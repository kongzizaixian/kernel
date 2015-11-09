/*
 * Copyright (C) 2013, 2014 ARM Limited, All Rights Reserved.
 * Author: Marc Zyngier <marc.zyngier@arm.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/cpu.h>
#include <linux/cpu_pm.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/acpi.h>
#include <linux/percpu.h>
#include <linux/slab.h>

#include <linux/irqchip/arm-gic-v3.h>
#include <linux/irqchip/arm-gic-acpi.h>

#include <asm/cputype.h>
#include <asm/exception.h>
#include <asm/smp_plat.h>

#include "irq-gic-common.h"
#include "irqchip.h"

struct gic_chip_data {
	struct list_head	entry;
	unsigned int		sid;
	void __iomem		*dist_base;
	unsigned int		irq_nr;
};

static LIST_HEAD(gic_nodes);
static DEFINE_SPINLOCK(gic_lock);
static struct irq_domain *gic_domain = NULL;
static struct rdists gic_rdists;

static u8 gic_support_lpis;
static bool gic_common_init = false;

#ifdef CONFIG_P660_2P
static DEFINE_SPINLOCK(g_gbl_lock);
static u64 g_irq_cnt[64][8];
static u32 g_irq_try[64][8];

static void gic_send_sgi(u64 cluster_id, u16 tlist, unsigned int irq);
extern int irq_do_set_affinity(struct irq_data *data,
				const struct cpumask *mask, bool force);
#endif

#define gic_data_rdist()		(this_cpu_ptr(gic_rdists.rdist))
#define gic_data_rdist_rd_base()	(gic_data_rdist()->rd_base)
#define gic_data_rdist_sgi_base()	(gic_data_rdist_rd_base() + SZ_64K)

/* Our default, arbitrary priority value. Linux only uses one anyway. */
#define DEFAULT_PMR_VALUE	0xf0

static inline unsigned int gic_irq(struct irq_data *d)
{
	return d->hwirq;
}

static inline int gic_irq_in_rdist(struct irq_data *d)
{
	return gic_irq(d) < 32;
}

struct gic_chip_data *gic_from_hwirq(unsigned long hwirq)
{
	struct gic_chip_data *gic = NULL, *tmp;

	spin_lock(&gic_lock);

	list_for_each_entry(tmp, &gic_nodes, entry) {
		if (tmp->sid == hwirq / tmp->irq_nr) {
			gic = tmp;
			break;
		}
	}

	spin_unlock(&gic_lock);

	return gic;
}

static inline void __iomem *gic_get_dist_base(unsigned long hwirq)
{
	struct gic_chip_data *gic = gic_from_hwirq(hwirq);

	return WARN_ON(!gic) ? NULL : gic->dist_base;
}

static inline void __iomem *gic_dist_base(struct irq_data *d)
{
	if (gic_irq_in_rdist(d))	/* SGI+PPI -> SGI_base for this CPU */
		return gic_data_rdist_sgi_base();

	if (d->hwirq <= 1023)		/* SPI -> dist_base */
		return gic_get_dist_base(gic_irq(d));

	return NULL;
}

static void gic_do_wait_for_rwp(void __iomem *base)
{
	u32 count = 1000000;	/* 1s! */

	while (readl_relaxed(base + GICD_CTLR) & GICD_CTLR_RWP) {
		count--;
		if (!count) {
			pr_err_ratelimited("RWP timeout, gone fishing\n");
			return;
		}
		cpu_relax();
		udelay(1);
	};
}

/* Low level accessors */
static u64 __maybe_unused gic_read_iar(void)
{
	u64 irqstat;

	asm volatile("mrs_s %0, " __stringify(ICC_IAR1_EL1) : "=r" (irqstat));
	return irqstat;
}

static void __maybe_unused gic_write_pmr(u64 val)
{
	asm volatile("msr_s " __stringify(ICC_PMR_EL1) ", %0" : : "r" (val));
}

static void __maybe_unused gic_write_ctlr(u64 val)
{
	asm volatile("msr_s " __stringify(ICC_CTLR_EL1) ", %0" : : "r" (val));
	isb();
}

static void __maybe_unused gic_write_grpen1(u64 val)
{
	asm volatile("msr_s " __stringify(ICC_GRPEN1_EL1) ", %0" : : "r" (val));
	isb();
}

#ifndef CONFIG_P660_2P
static void __maybe_unused gic_write_sgi1r(u64 val)
{
	asm volatile("msr_s " __stringify(ICC_SGI1R_EL1) ", %0" : : "r" (val));
}
#endif

static void gic_enable_sre(void)
{
	u64 val;

	asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
	val |= ICC_SRE_EL1_SRE;
	asm volatile("msr_s " __stringify(ICC_SRE_EL1) ", %0" : : "r" (val));
	isb();

	/*
	 * Need to check that the SRE bit has actually been set. If
	 * not, it means that SRE is disabled at EL2. We're going to
	 * die painfully, and there is nothing we can do about it.
	 *
	 * Kindly inform the luser.
	 */
	asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
	if (!(val & ICC_SRE_EL1_SRE))
		pr_err("GIC: unable to set SRE (disabled at EL2), panic ahead\n");
}

static void gic_enable_redist(bool enable)
{
	void __iomem *rbase;
	u32 count = 1000000;	/* 1s! */
	u32 val;

	rbase = gic_data_rdist_rd_base();

	val = readl_relaxed(rbase + GICR_WAKER);
	if (enable)
		/* Wake up this CPU redistributor */
		val &= ~GICR_WAKER_ProcessorSleep;
	else
		val |= GICR_WAKER_ProcessorSleep;
	writel_relaxed(val, rbase + GICR_WAKER);

	if (!enable) {		/* Check that GICR_WAKER is writeable */
		val = readl_relaxed(rbase + GICR_WAKER);
		if (!(val & GICR_WAKER_ProcessorSleep))
			return;	/* No PM support in this redistributor */
	}

	while (count--) {
		val = readl_relaxed(rbase + GICR_WAKER);
		if (enable ^ (val & GICR_WAKER_ChildrenAsleep))
			break;
		cpu_relax();
		udelay(1);
	};
	if (!count)
		pr_err_ratelimited("redistributor failed to %s...\n",
				   enable ? "wakeup" : "sleep");
}

/*
 * Routines to disable, enable, EOI and route interrupts
 */
static void gic_poke_irq(struct irq_data *d, u32 offset)
{
	u32 mask = 1 << (gic_irq(d) % 32);
	void __iomem *base;

	if (gic_irq_in_rdist(d))
		base = gic_data_rdist_sgi_base();
	else
		base = gic_dist_base(d);

	writel_relaxed(mask, base + offset + (gic_irq(d) / 32) * 4);
	gic_do_wait_for_rwp(base);
}

static void gic_mask_irq(struct irq_data *d)
{
	gic_poke_irq(d, GICD_ICENABLER);
}

static void gic_unmask_irq(struct irq_data *d)
{
	gic_poke_irq(d, GICD_ISENABLER);
}

static void gic_eoi_irq(struct irq_data *d)
{
	gic_write_eoir(gic_irq(d));
}

static int gic_set_type(struct irq_data *d, unsigned int type)
{
	unsigned int irq = gic_irq(d);
	void __iomem *base;

	/* Interrupt configuration for SGIs can't be changed */
	if (irq < 16)
		return -EINVAL;

	if (type != IRQ_TYPE_LEVEL_HIGH && type != IRQ_TYPE_EDGE_RISING)
		return -EINVAL;

	if (gic_irq_in_rdist(d))
		base = gic_data_rdist_sgi_base();
	else
		base = gic_dist_base(d);

	gic_configure_irq(irq, type, base, gic_do_wait_for_rwp);

	return 0;
}

static u64 gic_mpidr_to_affinity(u64 mpidr)
{
	u64 aff;

	aff = (MPIDR_AFFINITY_LEVEL(mpidr, 3) << 32 |
	       MPIDR_AFFINITY_LEVEL(mpidr, 2) << 16 |
	       MPIDR_AFFINITY_LEVEL(mpidr, 1) << 8  |
	       MPIDR_AFFINITY_LEVEL(mpidr, 0));

	return aff;
}

static asmlinkage void __exception_irq_entry gic_handle_irq(struct pt_regs *regs)
{
	u64 irqnr;

	do {
		irqnr = gic_read_iar();

		if (likely(irqnr > 15 && irqnr < 1020) || irqnr >= 8192) {
			int err;
			err = handle_domain_irq(gic_domain, irqnr, regs);
			if (likely(!err)) {
				/*
				 * Issue an explicit EOI for LPIs, since edge
				 * interrupt flow handler won't cover this.
				 */
				if (irqnr >= 8192)
					gic_write_eoir(irqnr);
			} else {
				WARN_ONCE(true, "Unexpected interrupt received!\n");
				gic_write_eoir(irqnr);
			}
			continue;
		}
		if (irqnr < 16) {
			gic_write_eoir(irqnr);
#ifdef CONFIG_SMP
			#ifdef CONFIG_P660_2P
			{
				unsigned long flags;
				u32 cpu = smp_processor_id();
				u64 i, need_try;

				spin_lock_irqsave(&g_gbl_lock, flags);
				g_irq_cnt[cpu][irqnr] = 0;
				g_irq_try[cpu][irqnr] = 0;
				spin_unlock_irqrestore(&g_gbl_lock, flags);

				handle_IPI(irqnr, regs);

				for (i = 0; i < 8; i++) {
					spin_lock_irqsave(&g_gbl_lock, flags);
					need_try = g_irq_try[cpu][i];
					g_irq_try[cpu][i] = 0;
					spin_unlock_irqrestore(&g_gbl_lock, flags);

					if (need_try) {
						u64 cluster_id = cpu_logical_map(cpu) & ~0xffUL;

						gic_send_sgi(cluster_id, (u16)(1 << (cpu & 0x3)), i);
						cpu_relax();
						break;
					}
				}
			}
			#else
			handle_IPI(irqnr, regs);
			#endif
#else
			WARN_ONCE(true, "Unexpected SGI received!\n");
#endif
			continue;
		}
	} while (irqnr != ICC_IAR1_EL1_SPURIOUS);
}

#ifdef CONFIG_P660_2P
static u32 irq_to_dieid(unsigned long irq)
{
	return (u32)(irq >> 7);
}

static u32 cpu_to_dieid(u32 cpu)
{
	u64 mpidr = cpu_logical_map(cpu);

	return (u32)(0xff & (mpidr >> 16));
}
#endif

static void __init gic_dist_init(struct gic_chip_data *gic_data)
{
	unsigned int i;
	u64 affinity;
	void __iomem *base = gic_data->dist_base;

	/* Disable the distributor */
	writel_relaxed(0, base + GICD_CTLR);
	gic_do_wait_for_rwp(base);

	gic_dist_config(base, gic_data->irq_nr, gic_do_wait_for_rwp);

	/* Enable distributor with ARE, Group1 */
	writel_relaxed(GICD_CTLR_ARE_NS | GICD_CTLR_ENABLE_G1A | GICD_CTLR_ENABLE_G1,
		       base + GICD_CTLR);

	/*
	 * Set all global interrupts to the boot CPU only. ARE must be
	 * enabled.
	 */
#ifdef CONFIG_P660_2P
{
	u32 cpu, die_id;

	die_id = gic_data->sid;
	for (cpu = 0; cpu < nr_cpu_ids; cpu++)
		if ((die_id == cpu_to_dieid(cpu)) && cpu_possible(cpu))
			break;

	if (cpu >= nr_cpu_ids)
		cpu = smp_processor_id();
	affinity = gic_mpidr_to_affinity(cpu_logical_map(cpu));
	for (i = (128 * die_id) + 32; i < (128 * (die_id + 1)); i++)
		writeq_relaxed(affinity, base + GICD_IROUTER + i * 8);
}
#else
	affinity = gic_mpidr_to_affinity(cpu_logical_map(smp_processor_id()));
	for (i = 32; i < gic_data->irq_nr; i++)
		writeq_relaxed(affinity, base + GICD_IROUTER + i * 8);
#endif
}

static int gic_populate_rdist(void)
{
	u64 mpidr = cpu_logical_map(smp_processor_id());
	u64 typer;
	u32 aff;
	int i;

	/*
	 * Convert affinity to a 32bit value that can be matched to
	 * GICR_TYPER bits [63:32].
	 */
	aff = (MPIDR_AFFINITY_LEVEL(mpidr, 3) << 24 |
	       MPIDR_AFFINITY_LEVEL(mpidr, 2) << 16 |
	       MPIDR_AFFINITY_LEVEL(mpidr, 1) << 8 |
	       MPIDR_AFFINITY_LEVEL(mpidr, 0));

	for (i = 0; i < gic_rdists.nr_regions; i++) {
		void __iomem *ptr = gic_rdists.regions[i].redist_base;
		u32 reg;

		reg = readl_relaxed(ptr + GICR_PIDR2) & GIC_PIDR2_ARCH_MASK;
		if (reg != GIC_PIDR2_ARCH_GICv3 &&
		    reg != GIC_PIDR2_ARCH_GICv4) { /* We're in trouble... */
			pr_warn("No redistributor present @%p\n", ptr);
			break;
		}

		do {
			typer = readq_relaxed(ptr + GICR_TYPER);
			if ((typer >> 32) == aff) {
				u64 offset = ptr - gic_rdists.regions[i].redist_base;
				gic_data_rdist_rd_base() = ptr;
				gic_data_rdist()->phys_base = gic_rdists.regions[i].phys_base + offset;
				pr_info("CPU%d: found redistributor %llx region %d:%pa\n",
					smp_processor_id(),
					(unsigned long long)mpidr,
					i, &gic_data_rdist()->phys_base);
				return 0;
			}

			if (gic_rdists.stride) {
				ptr += gic_rdists.stride;
			} else {
				ptr += SZ_64K * 2; /* Skip RD_base + SGI_base */
				if (typer & GICR_TYPER_VLPIS)
					ptr += SZ_64K * 2; /* Skip VLPI_base + reserved page */
			}
		} while (!(typer & GICR_TYPER_LAST));
	}

	/* We couldn't even deal with ourselves... */
	WARN(true, "CPU%d: mpidr %llx has no re-distributor!\n",
	     smp_processor_id(), (unsigned long long)mpidr);
	return -ENODEV;
}

static void gic_cpu_sys_reg_init(void)
{
	/* Enable system registers */
	gic_enable_sre();

	/* Set priority mask register */
	gic_write_pmr(DEFAULT_PMR_VALUE);

	/* EOI deactivates interrupt too (mode 0) */
	gic_write_ctlr(ICC_CTLR_EL1_EOImode_drop_dir);

	/* ... and let's hit the road... */
	gic_write_grpen1(1);
}

#ifdef CONFIG_ARM_GIC_V3_ITS
static int gic_dist_supports_lpis(u32 typer)
{
	return !!(typer & GICD_TYPER_LPIS);
}
#else
static int gic_dist_supports_lpis(u32 typer)
{
	return 0;
}
#endif

static void gic_cpu_init(void)
{
	void __iomem *rbase;

	/* Register ourselves with the rest of the world */
	if (gic_populate_rdist())
		return;

	gic_enable_redist(true);

	rbase = gic_data_rdist_sgi_base();

	gic_cpu_config(rbase, gic_do_wait_for_rwp);

	/* Give LPIs a spin */
	if (gic_support_lpis)
		its_cpu_init();

	/* initialise system registers */
	gic_cpu_sys_reg_init();
}

#ifdef CONFIG_SMP
static int gic_peek_irq(struct irq_data *d, u32 offset)
{
	u32 mask = 1 << (gic_irq(d) % 32);
	void __iomem *base;

	if (gic_irq_in_rdist(d))
		base = gic_data_rdist_sgi_base();
	else
		base = gic_dist_base(d);

	return !!(readl_relaxed(base + offset + (gic_irq(d) / 32) * 4) & mask);
}

static int gic_secondary_init(struct notifier_block *nfb,
			      unsigned long action, void *hcpu)
{
	if (action == CPU_STARTING || action == CPU_STARTING_FROZEN)
		gic_cpu_init();
	return NOTIFY_OK;
}

/*
 * Notifier for enabling the GIC CPU interface. Set an arbitrarily high
 * priority because the GIC needs to be up before the ARM generic timers.
 */
static struct notifier_block gic_cpu_notifier = {
	.notifier_call = gic_secondary_init,
	.priority = 100,
};

static u16 gic_compute_target_list(int *base_cpu, const struct cpumask *mask,
				   u64 cluster_id)
{
	int cpu = *base_cpu;
	u64 mpidr = cpu_logical_map(cpu);
	u16 tlist = 0;

	while (cpu < nr_cpu_ids) {
		/*
		 * If we ever get a cluster of more than 16 CPUs, just
		 * scream and skip that CPU.
		 */
		if (WARN_ON((mpidr & 0xff) >= 16))
			goto out;

		tlist |= 1 << (mpidr & 0xf);

		cpu = cpumask_next(cpu, mask);
		if (cpu == nr_cpu_ids)
			goto out;

		mpidr = cpu_logical_map(cpu);

		if (cluster_id != (mpidr & ~0xffUL)) {
			cpu--;
			goto out;
		}
	}
out:
	*base_cpu = cpu;
	return tlist;
}

static void gic_send_sgi(u64 cluster_id, u16 tlist, unsigned int irq)
{
	u64 val;
#ifdef CONFIG_P660_2P
	u64 aff2, aff1, aff0;
	void *gicd_base;
	u32 cpu, cpu_lo;
	u32 setr, i;
	unsigned long flags;
#endif

	val = (MPIDR_AFFINITY_LEVEL(cluster_id, 3) << 48	|
	       MPIDR_AFFINITY_LEVEL(cluster_id, 2) << 32	|
	       irq << 24			    		|
	       MPIDR_AFFINITY_LEVEL(cluster_id, 1) << 16	|
	       tlist);

	pr_debug("CPU%d: ICC_SGI1R_EL1 %llx\n", smp_processor_id(), val);
#ifndef CONFIG_P660_2P
	gic_write_sgi1r(val);
#else
	aff2 = MPIDR_AFFINITY_LEVEL(cluster_id, 2);
	aff1 = MPIDR_AFFINITY_LEVEL(cluster_id, 1);

	spin_lock_irqsave(&g_gbl_lock, flags);

	for (aff0 = 0; aff0 < 4; aff0++)
		if (tlist & (1 << aff0)) {
			cpu_lo = (aff1 * 4) + aff0;
			cpu = ((aff2 >> 1) * 16) + cpu_lo;

			gicd_base = gic_get_dist_base(128 * aff2);

			setr  = 0;
			setr |= (0x1 << 23);	/* nsecure=1 */
			setr |= (0x1 << 22);	/* grpmod=1 */
			setr |= (0x14 << 17);	/* priority=0xa0 */
			setr |= (irq << 7);	/* irq */
			setr |= (aff2 << 4);	/* dieid */
			setr |= (cpu_lo << 0);	/* aff1+aff0 */

			for (i = 0; i < 8; i++) {
				if (i == irq)
					continue;

				if (g_irq_cnt[cpu][i])
					g_irq_try[cpu][i] = 1;
			}

			g_irq_cnt[cpu][irq]++;

			writel_relaxed(setr, gicd_base + 0x2000 + (cpu_lo * 4));
			dsb(sy);
		}

	spin_unlock_irqrestore(&g_gbl_lock, flags);
#endif
}

static void gic_raise_softirq(const struct cpumask *mask, unsigned int irq)
{
	int cpu;

	if (WARN_ON(irq >= 16))
		return;

	/*
	 * Ensure that stores to Normal memory are visible to the
	 * other CPUs before issuing the IPI.
	 */
	smp_wmb();

	for_each_cpu_mask(cpu, *mask) {
		u64 cluster_id = cpu_logical_map(cpu) & ~0xffUL;
		u16 tlist;

		tlist = gic_compute_target_list(&cpu, mask, cluster_id);
		gic_send_sgi(cluster_id, tlist, irq);
	}

	/* Force the above writes to ICC_SGI1R_EL1 to be executed */
	isb();
}

static void gic_smp_init(void)
{
	set_smp_cross_call(gic_raise_softirq);
	register_cpu_notifier(&gic_cpu_notifier);
}

static int gic_set_affinity(struct irq_data *d, const struct cpumask *mask_val,
			    bool force)
{
	unsigned int cpu = cpumask_any_and(mask_val, cpu_online_mask);
	void __iomem *reg, *base = gic_dist_base(d);
	int enabled;
	u64 val;

	if (gic_irq_in_rdist(d))
		return -EINVAL;

#ifdef CONFIG_P660_2P
{
	u32 i, dieid, local_die_cpu = cpu;
	struct cpumask cpumask_allowed;

	dieid = irq_to_dieid(d->hwirq);
	cpumask_and(&cpumask_allowed, mask_val, cpu_online_mask);
	for (i = 0; i < nr_cpu_ids; i++) {
		if ((dieid != cpu_to_dieid(i)) || !cpu_online(i))
			continue;

		if (cpumask_test_cpu(i, &cpumask_allowed)) {
			cpu = i;
			break;
		}

		local_die_cpu = i;
	}

	if (i >= nr_cpu_ids) {
		#if 0
		pr_info("Try bind %lld to local die failed, cpumask=0x%llx, forced\n",
				(u64)d->hwirq, (u64)mask_val->bits[0]);
		dump_stack();
		#endif
		cpu = local_die_cpu;
	}
}
#endif

	/* If interrupt was enabled, disable it first */
	enabled = gic_peek_irq(d, GICD_ISENABLER);
	if (enabled)
		gic_mask_irq(d);

	reg = base + GICD_IROUTER + (gic_irq(d) * 8);
	val = gic_mpidr_to_affinity(cpu_logical_map(cpu));

	writeq_relaxed(val, reg);

	/*
	 * If the interrupt was enabled, enabled it again. Otherwise,
	 * just wait for the distributor to have digested our changes.
	 */
	if (enabled)
		gic_unmask_irq(d);
	else
		gic_do_wait_for_rwp(base);

#ifdef CONFIG_P660_2P
	return IRQ_SET_MASK_OK_NOCOPY;
#else
	return IRQ_SET_MASK_OK;
#endif
}

#ifdef CONFIG_P660_2P
static void bind_local_affinity(unsigned int irq, unsigned long hwirq)
{
	u32 cpu;
	unsigned long flags;
	struct irq_desc *desc;
	struct cpumask cpumask_allowed;

	desc = irq_to_desc(irq);
	if (!desc)
		return;

#ifdef CONFIG_COPYCAT_NUMA
{
	u64 boot_dieid;
	int to_node[] = {0, 1, 3, 2};

	boot_dieid = 0xff & (cpu_logical_map(0) >> 16);

	/* TC boot */
	if (boot_dieid == 2) {
		to_node[0] = 1;
		to_node[1] = 0;
	}

	desc->irq_data.node = to_node[hwirq >> 8];
}
#endif

	cpumask_clear(&cpumask_allowed);
	for (cpu = 0; cpu < nr_cpu_ids; cpu++)
		if (cpu_to_dieid(cpu) == irq_to_dieid(hwirq))
			cpumask_set_cpu(cpu, &cpumask_allowed);

	raw_spin_lock_irqsave(&desc->lock, flags);
	if (!desc->irq_data.affinity) {
		raw_spin_unlock_irqrestore(&desc->lock, flags);
		return;
	}

	cpumask_copy(desc->irq_data.affinity, &cpumask_allowed);
	irq_do_set_affinity(&desc->irq_data, &cpumask_allowed, 0);
	raw_spin_unlock_irqrestore(&desc->lock, flags);
}
#endif
#else
#define gic_set_affinity	NULL
#define gic_smp_init()		do { } while(0)
#endif

#ifdef CONFIG_CPU_PM
static int gic_cpu_pm_notifier(struct notifier_block *self,
			       unsigned long cmd, void *v)
{
	if (cmd == CPU_PM_EXIT) {
		gic_enable_redist(true);
		gic_cpu_sys_reg_init();
	} else if (cmd == CPU_PM_ENTER) {
		gic_write_grpen1(0);
		gic_enable_redist(false);
	}
	return NOTIFY_OK;
}

static struct notifier_block gic_cpu_pm_notifier_block = {
	.notifier_call = gic_cpu_pm_notifier,
};

static void gic_cpu_pm_init(void)
{
	cpu_pm_register_notifier(&gic_cpu_pm_notifier_block);
}

#else
static inline void gic_cpu_pm_init(void) { }
#endif /* CONFIG_CPU_PM */

static struct irq_chip gic_chip = {
	.name			= "GICv3",
	.irq_mask		= gic_mask_irq,
	.irq_unmask		= gic_unmask_irq,
	.irq_eoi		= gic_eoi_irq,
	.irq_set_type		= gic_set_type,
	.irq_set_affinity	= gic_set_affinity,
};

#define GIC_ID_NR		(1U << gic_rdists.id_bits)

static int gic_irq_domain_map(struct irq_domain *d, unsigned int irq,
			      irq_hw_number_t hw)
{
	/* SGIs are private to the core kernel */
	if (hw < 16)
		return -EPERM;
	/* Nothing here */
	if (hw >= 1020 && hw < 8192)
		return -EPERM;
	/* Off limits */
	if (hw >= GIC_ID_NR)
		return -EPERM;

	/* PPIs */
	if (hw < 32) {
		irq_set_percpu_devid(irq);
		irq_domain_set_info(d, irq, hw, &gic_chip, d->host_data,
				    handle_percpu_devid_irq, NULL, NULL);
		set_irq_flags(irq, IRQF_VALID | IRQF_NOAUTOEN);
	}
	/* SPIs */
	if (hw >= 32 && hw < 1020) {
		irq_domain_set_info(d, irq, hw, &gic_chip, d->host_data,
				    handle_fasteoi_irq, NULL, NULL);
		set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
		#ifdef CONFIG_P660_2P
		bind_local_affinity(irq, hw);
		#endif
	}
	/* LPIs */
	if (hw >= 8192 && hw < GIC_ID_NR) {
		if (!gic_support_lpis)
			return -EPERM;
		irq_domain_set_info(d, irq, hw, &gic_chip, d->host_data,
				    handle_fasteoi_irq, NULL, NULL);
		set_irq_flags(irq, IRQF_VALID);
	}

	return 0;
}

static int gic_irq_domain_xlate(struct irq_domain *d,
				struct device_node *controller,
				const u32 *intspec, unsigned int intsize,
				unsigned long *out_hwirq, unsigned int *out_type)
{
	if (d->of_node != controller)
		return -EINVAL;
	if (intsize < 3)
		return -EINVAL;

	switch(intspec[0]) {
	case 0:			/* SPI */
		*out_hwirq = intspec[1] + 32;
		break;
	case 1:			/* PPI */
		*out_hwirq = intspec[1] + 16;
		break;
	case GIC_IRQ_TYPE_LPI:	/* LPI */
		*out_hwirq = intspec[1];
		break;
	default:
		return -EINVAL;
	}

	*out_type = intspec[2] & IRQ_TYPE_SENSE_MASK;
	return 0;
}

static int gic_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
				unsigned int nr_irqs, void *arg)
{
	int i, ret;
	irq_hw_number_t hwirq;
	unsigned int type = IRQ_TYPE_NONE;
	struct of_phandle_args *irq_data = arg;

	ret = gic_irq_domain_xlate(domain, irq_data->np, irq_data->args,
				   irq_data->args_count, &hwirq, &type);
	if (ret)
		return ret;

	for (i = 0; i < nr_irqs; i++)
		gic_irq_domain_map(domain, virq + i, hwirq + i);

	return 0;
}

static void gic_irq_domain_free(struct irq_domain *domain, unsigned int virq,
				unsigned int nr_irqs)
{
	int i;

	for (i = 0; i < nr_irqs; i++) {
		struct irq_data *d = irq_domain_get_irq_data(domain, virq + i);
		irq_set_handler(virq + i, NULL);
		irq_domain_reset_irq_data(d);
	}
}

static const struct irq_domain_ops gic_irq_domain_ops = {
	.map = gic_irq_domain_map,
	.xlate = gic_irq_domain_xlate,
	.alloc = gic_irq_domain_alloc,
	.free = gic_irq_domain_free,
};

static void gic_rdist_free(void)
{
	struct redist_region *rdist_regs = gic_rdists.regions;
	int i;

	free_percpu(gic_rdists.rdist);
	for (i = 0; i < gic_rdists.nr_regions; i++)
		if (rdist_regs[i].redist_base)
			iounmap(rdist_regs[i].redist_base);
	kfree(rdist_regs);
}

static int gic_rdist_of_init(struct device_node *node, int id_bits)
{
	struct redist_region *rdist_regs;
	u64 redist_stride;
	u32 redist_regions;
	int err, i;

	if (of_property_read_u32(node, "#redistributor-regions", &redist_regions))
		return 0;

	if (of_property_read_u64(node, "redistributor-stride", &redist_stride))
		redist_stride = 0;

	rdist_regs = kzalloc(sizeof(*rdist_regs) * redist_regions, GFP_KERNEL);
	if (!rdist_regs)
		return -ENOMEM;

	for (i = 0; i < redist_regions; i++) {
		struct resource res;

		err = of_address_to_resource(node, 1 + i, &res);
		rdist_regs[i].redist_base = of_iomap(node, 1 + i);
		if (err || !rdist_regs[i].redist_base) {
			pr_err("%s: couldn't map region %d\n",
			       node->full_name, i);
			err = -ENODEV;
			goto out_unmap_rdist;
		}
		rdist_regs[i].phys_base = res.start;
	}

	gic_rdists.rdist = alloc_percpu(typeof(*gic_rdists.rdist));
	if (WARN_ON(!gic_rdists.rdist)) {
		err = -ENOMEM;
		goto out_free_rdist;
	}

	gic_rdists.id_bits = id_bits;
	gic_rdists.regions = rdist_regs;
	gic_rdists.nr_regions = redist_regions;
	gic_rdists.stride = redist_stride;

	return 0;

out_free_rdist:
	free_percpu(gic_rdists.rdist);
out_unmap_rdist:
	for (i = 0; i < redist_regions; i++)
		if (rdist_regs[i].redist_base)
			iounmap(rdist_regs[i].redist_base);
	kfree(rdist_regs);
	return err;
}

static int __init gic_of_init(struct device_node *node, struct device_node *parent)
{
	struct gic_chip_data *gic_data;
	u32 typer;
	u32 reg;
	int gic_irqs;
	int err;

	gic_data = kzalloc(sizeof(*gic_data), GFP_KERNEL);
	if (!gic_data)
		return -ENOMEM;

	gic_data->dist_base = of_iomap(node, 0);
	if (!gic_data->dist_base) {
		pr_err("%s: unable to map gic dist registers\n",
			node->full_name);
		err = -ENXIO;
		goto out_free_gic;
	}

	reg = readl_relaxed(gic_data->dist_base + GICD_PIDR2) & GIC_PIDR2_ARCH_MASK;
	if (reg != GIC_PIDR2_ARCH_GICv3 && reg != GIC_PIDR2_ARCH_GICv4) {
		pr_err("%s: no distributor detected, giving up\n",
			node->full_name);
		err = -ENODEV;
		goto out_unmap_dist;
	}

	reg = readl_relaxed(gic_data->dist_base + GICD_SIDR);
	gic_data->sid = reg & GIC_SID_MASK;

	/*
	 * Find out how many interrupts are supported.
	 * The GIC only supports up to 1020 interrupt sources (SGI+PPI+SPI)
	 */
	typer = readl_relaxed(gic_data->dist_base + GICD_TYPER);
	gic_irqs = GICD_TYPER_IRQS(typer);
	gic_data->irq_nr = min(gic_irqs, 1020);

	if (of_device_is_compatible(node, "hisilicon,gic-v3"))
		gic_data->irq_nr = 0x80;

	err = gic_rdist_of_init(node, GICD_TYPER_ID_BITS(typer));
	if (err)
		goto out_unmap_dist;

	gic_dist_init(gic_data);

	if (gic_common_init)
		goto end_probe;

	gic_domain = irq_domain_add_tree(node, &gic_irq_domain_ops, gic_data);
	if (WARN_ON(!gic_domain)) {
		err = -ENOMEM;
		goto out_unmap_rdist;
	}

	set_handle_irq(gic_handle_irq);

	gic_support_lpis = gic_dist_supports_lpis(typer);
	if (gic_support_lpis) {
		err = its_init(&gic_rdists, gic_domain);
		if (err)
			gic_support_lpis = 0;
	}

	gic_smp_init();
	gic_cpu_init();

	if (!of_device_is_compatible(node, "hisilicon,gic-v3"))
		gic_cpu_pm_init();

	gic_common_init = true;

end_probe:
	spin_lock(&gic_lock);
	list_add(&gic_data->entry, &gic_nodes);
	spin_unlock(&gic_lock);

	return 0;

out_unmap_rdist:
	gic_rdist_free();
out_unmap_dist:
	iounmap(gic_data->dist_base);
out_free_gic:
	kfree(gic_data);
	return err;
}

IRQCHIP_DECLARE(gic_v3, "arm,gic-v3", gic_of_init);
IRQCHIP_DECLARE(hic_v3, "hisilicon,gic-v3", gic_of_init);

#ifdef CONFIG_ACPI
static struct redist_region *redist_regs;
static u32 redist_regions;

static void __iomem * __init
gic_acpi_map_one_redist(u64 redist_base_address)
{
	void __iomem *redist_base;
	u64 typer;
	u32 reg;

	/* Map RD + SGI pages */
	redist_base = ioremap(redist_base_address, 2 * SZ_64K);
	if (!redist_base)
		return NULL;

	/*
	 * Map another two pages VLPI + reserved, if GIC support
	 * virtual LPI.
	 */
	reg = readl_relaxed(redist_base + GICR_PIDR2) & GIC_PIDR2_ARCH_MASK;
	if (reg != 0x30 && reg != 0x40) { /* We're in trouble... */
		pr_warn("ACPI: No redistributor present @%p\n", redist_base);
		iounmap(redist_base);
		return NULL;
	}

	typer = readq_relaxed(redist_base + GICR_TYPER);
	if (typer & GICR_TYPER_VLPIS) {
		iounmap(redist_base);
		redist_base = ioremap(redist_base_address, 4 * SZ_64K);
	}

	return redist_base;
}

static int __init
gic_acpi_register_redist(u64 redist_base_address, u32 size, int region)
{
	struct redist_region *redist_regs_new;
	void __iomem *redist_base;

	redist_regs_new = krealloc(redist_regs,
				   sizeof(*redist_regs) * (redist_regions + 1),
				   GFP_KERNEL);
	if (!redist_regs_new) {
		pr_err("ACPI: Couldn't allocate resource for GICR region\n");
		return -ENOMEM;
	}

	redist_regs = redist_regs_new;

	/*
	 * Region contains a distinct set of GIC redistributors. Region size
	 * gives us all info we need to map redistributors properly.
	 *
	 * If it is not region, we assume to deal with one redistributor.
	 * Redistributor size is probeable and depends on GIC version:
	 * GICv3: RD + SGI pages
	 * GICv4: RD + SGI + VLPI + reserved pages
	 */
	if (region)
		redist_base = ioremap(redist_base_address, size);
	else
		redist_base = gic_acpi_map_one_redist(redist_base_address);

	if (!redist_base) {
		pr_err("ACPI: Couldn't map GICR region @%lx\n",
		       (long int)redist_base_address);
		return -ENOMEM;
	}

	redist_regs[redist_regions].phys_base = redist_base_address;
	redist_regs[redist_regions++].redist_base = redist_base;
	return 0;
}

static int __init
gic_acpi_parse_madt_cpu(struct acpi_subtable_header *header,
			const unsigned long end)
{
	struct acpi_madt_generic_interrupt *processor;

	if (BAD_MADT_ENTRY(header, end))
		return -EINVAL;

	processor = (struct acpi_madt_generic_interrupt *)header;
	if (!processor->gicr_base_address)
		return -EINVAL;

	return gic_acpi_register_redist(processor->gicr_base_address, 0, 0);
}

static int __init
gic_acpi_parse_madt_redist(struct acpi_subtable_header *header,
			const unsigned long end)
{
	struct acpi_madt_generic_redistributor *redist;

	if (BAD_MADT_ENTRY(header, end))
		return -EINVAL;

	redist = (struct acpi_madt_generic_redistributor *)header;
	if (!redist->base_address)
		return -EINVAL;

	return gic_acpi_register_redist(redist->base_address,
					redist->length, 1);
}

static int __init
gic_acpi_parse_madt_distributor(struct acpi_subtable_header *header,
				const unsigned long end)
{
	struct acpi_madt_generic_distributor *dist;
	struct gic_chip_data *gic_data;
	u32 typer;
	u32 reg;
	int gic_irqs;
	int err;

	dist = (struct acpi_madt_generic_distributor *)header;

	if (BAD_MADT_ENTRY(dist, end))
		return -EINVAL;

	gic_data = kzalloc(sizeof(*gic_data), GFP_KERNEL);
	if (!gic_data)
		return -ENOMEM;

	gic_data->dist_base = ioremap(dist->base_address,
					ACPI_GICV3_DIST_MEM_SIZE);
	if (!gic_data->dist_base) {
		pr_err("ACPI: Unable to map GICD registers\n");
		err =  -ENOMEM;
		goto out_free_dist;
	}

	reg = readl_relaxed(gic_data->dist_base + GICD_PIDR2);
	reg &= GIC_PIDR2_ARCH_MASK;
	if (reg != GIC_PIDR2_ARCH_GICv3 && reg != GIC_PIDR2_ARCH_GICv4) {
		pr_err("ACPI: no distributor detected, giving up\n");
		err = -ENODEV;
		goto out_unmap_dist;
	}

	reg = readl_relaxed(gic_data->dist_base + GICD_SIDR);
	gic_data->sid = reg & GIC_SID_MASK;

	/*
	 * Find out how many interrupts are supported.
	 * The GIC only supports up to 1020 interrupt sources (SGI+PPI+SPI)
	 */
	typer = readl_relaxed(gic_data->dist_base + GICD_TYPER);
	gic_irqs = ((typer & 0x1f) + 1) * 32;
	gic_data->irq_nr = min(gic_irqs, 1020);

	if (IS_ENABLED(CONFIG_ARCH_P660))
		gic_data->irq_nr = 0x80;  /* Should be min(gic_irqs, 1020) */

	gic_dist_init(gic_data);

	if (!gic_common_init) {
		gic_rdists.rdist = alloc_percpu(typeof(*gic_rdists.rdist));
		if (WARN_ON(!gic_rdists.rdist)) {
			err = -ENOMEM;
			goto out_unmap_dist;
		}

		gic_rdists.regions = redist_regs;
		gic_rdists.nr_regions = redist_regions;
		gic_rdists.stride = 0;	/* standard 2 or 4 64k pages */

		/* P660 special, we got three 64k pages */
		if (IS_ENABLED(CONFIG_ARCH_P660))
			gic_rdists.stride = 0x30000;

		gic_rdists.id_bits = ((typer >> 19) & 0x1f) + 1;

		gic_domain = irq_domain_add_tree(NULL, &gic_irq_domain_ops, gic_data);
		if (WARN_ON(!gic_domain)) {
			gic_rdist_free();
			err = -ENOMEM;
			goto out_unmap_dist;
		}

		irq_set_default_host(gic_domain);
		set_handle_irq(gic_handle_irq);

		gic_support_lpis = gic_dist_supports_lpis(typer);
		if (gic_support_lpis)
			its_init(&gic_rdists, gic_domain);

		gic_smp_init();
		gic_cpu_init();
		if (!IS_ENABLED(CONFIG_ARCH_P660))
			gic_cpu_pm_init();
		gic_common_init = 1;
	}

	spin_lock(&gic_lock);
	list_add(&gic_data->entry, &gic_nodes);
	spin_unlock(&gic_lock);

	return 0;

out_unmap_dist:
	iounmap(gic_data->dist_base);
out_free_dist:
	kfree(gic_data);
	return err;
}

int __init
gic_v3_acpi_init(struct acpi_table_header *table)
{
	int count, err = 0;

	/* Collect redistributor base addresses */
	count = acpi_parse_entries(ACPI_SIG_MADT,
			sizeof(struct acpi_table_madt),
			gic_acpi_parse_madt_redist, table,
			ACPI_MADT_TYPE_GENERIC_REDISTRIBUTOR, 0);
	if (!count)
		pr_info("ACPI: No valid GICR entries exist\n");
	else if (count < 0) {
		pr_err("ACPI: Error during GICR entries parsing\n");
		err = -EINVAL;
		goto out_redist_unmap;
	} else
		goto madt_dist;

	/*
	 * There might be no GICR structure but we can still obtain
	 * redistributor collection from GICC subtables.
	 */
	count = acpi_parse_entries(ACPI_SIG_MADT,
			sizeof(struct acpi_table_madt),
			gic_acpi_parse_madt_cpu, table,
			ACPI_MADT_TYPE_GENERIC_INTERRUPT, 0);
	if (!count) {
		pr_info("ACPI: No valid GICC entries exist\n");
		return -EINVAL;
	} else if (count < 0) {
		pr_err("ACPI: Error during GICC entries parsing\n");
		err = -EINVAL;
		goto out_redist_unmap;
	}

madt_dist:
	count = acpi_parse_entries(ACPI_SIG_MADT,
				sizeof(struct acpi_table_madt),
				gic_acpi_parse_madt_distributor, table,
				ACPI_MADT_TYPE_GENERIC_DISTRIBUTOR, 0);
	if (count < 0) {
		pr_err("ACPI: Error during GICD entries parsing\n");
		err = -EINVAL;
		goto out_redist_unmap;
	} else if (!count) {
		pr_err("ACPI: No valid GICD entries exist\n");
		err = -EINVAL;
		goto out_redist_unmap;
	} else if (count >= 1) {
		pr_info("ACPI: %d GICD entry detected\n", count);
		return 0;
	}

out_redist_unmap:
	gic_rdist_free();
	return err;
}
#endif

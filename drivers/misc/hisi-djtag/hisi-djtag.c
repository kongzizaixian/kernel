/*
 * Driver for Hisilicon Djtag r/w via System Controller.
 *
 * Copyright (C) 2013-2014 Hisilicon Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/spinlock.h>

#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/regmap.h>
#include <linux/mfd/syscon.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/bitops.h>

#include <asm/cacheflush.h>
#include <asm/hisi-djtag.h>

/* for 660 and 1382 totem */
#define SC_DJTAG_MSTR_EN		0x6800
#define DJTAG_NOR_CFG			BIT(1)	/* accelerate R,W */
#define DJTAG_MSTR_EN			BIT(0)
#define SC_DJTAG_MSTR_START_EN		0x6804
#define DJTAG_MSTR_START_EN		0x1
#define SC_DJTAG_DEBUG_MODULE_SEL	0x680c
#define SC_DJTAG_MSTR_WR		0x6810
#define DJTAG_MSTR_W			0x1
#define DJTAG_MSTR_R			0x0
#define SC_DJTAG_CHAIN_UNIT_CFG_EN	0x6814
#define CHAIN_UNIT_CFG_EN		0xFFFF
#define SC_DJTAG_MSTR_ADDR		0x6818
#define SC_DJTAG_MSTR_DATA		0x681c
#define SC_DJTAG_RD_DATA_BASE		0xe800

/* for 1382 totem and io */
#define SC_DJTAG_SEC_ACC_EN_EX		0xd800
#define DJTAG_SEC_ACC_EN_EX		0x1
#define SC_DJTAG_MSTR_CFG_EX		0xd818
#define DJTAG_MSTR_RW_SHIFT_EX		29
#define DJTAG_MSTR_RD_EX		(0x0 << DJTAG_MSTR_RW_SHIFT_EX)
#define DJTAG_MSTR_WR_EX		(0x1 << DJTAG_MSTR_RW_SHIFT_EX)
#define DEBUG_MODULE_SEL_SHIFT_EX	16
#define CHAIN_UNIT_CFG_EN_EX		0xFFFF
#define SC_DJTAG_MSTR_ADDR_EX		0xd810
#define SC_DJTAG_MSTR_DATA_EX		0xd814
#define SC_DJTAG_MSTR_START_EN_EX	0xd81c
#define DJTAG_MSTR_START_EN_EX		0x1
#define SC_DJTAG_RD_DATA_BASE_EX	0xe800

static LIST_HEAD(djtag_list);

enum hisi_soc_type {
	HISI_HIP05,
	HISI_HIP06,
	HISI_HI1382,
};

struct djtag_of_data {
	struct list_head list;
	struct regmap *scl_map;
	struct device_node *node;
	enum hisi_soc_type type;
	void (*mod_cfg_by_djtag)(struct regmap *map, u32 offset,
				u32 mod_sel, u32 mod_mask, bool is_w,
				u32 wval, int chain_id, u32 *rval);
};

static DEFINE_SPINLOCK(djtag_lock);

/**
 * mod_cfg_by_djtag: cfg mode via djtag
 * @node:	djtag node
 * @offset:	register's offset
 * @mod_sel:	module selection
 * @mod_mask:	mask to select specific modules
 * @is_w:	write -> true, read -> false
 * @wval:	value to write to register
 * @chain_id:	read value of which module
 * @rval:	value which read from register
 *
 * Return NULL if error, else return pointer of regmap.
 */
static void hip05_mod_cfg_by_djtag(struct regmap *map,
				   u32 offset, u32 mod_sel,
				    u32 mod_mask, bool is_w,
				     u32 wval, int chain_id,
				      u32 *rval)
{
	u32 rd;

	BUG_ON(!map);

	if (!(mod_mask & CHAIN_UNIT_CFG_EN))
		mod_mask = CHAIN_UNIT_CFG_EN;

	/* djtag mster enable & accelerate R,W */
	regmap_write(map, SC_DJTAG_MSTR_EN,
			DJTAG_NOR_CFG | DJTAG_MSTR_EN);
	/* select module */
	regmap_write(map,
			SC_DJTAG_DEBUG_MODULE_SEL,
			mod_sel);

	regmap_write(map, SC_DJTAG_CHAIN_UNIT_CFG_EN,
			mod_mask & CHAIN_UNIT_CFG_EN);

	if (is_w) {
		regmap_write(map,
				SC_DJTAG_MSTR_WR,
				DJTAG_MSTR_W);
		regmap_write(map,
				SC_DJTAG_MSTR_DATA,
				wval);
	} else {
		regmap_write(map,
				SC_DJTAG_MSTR_WR,
				DJTAG_MSTR_R);
	}

	/* address offset */
	regmap_write(map, SC_DJTAG_MSTR_ADDR, offset);
	/* start to write to djtag register */
	regmap_write(map, SC_DJTAG_MSTR_START_EN,
			DJTAG_MSTR_START_EN);

	while (!regmap_read(map, SC_DJTAG_MSTR_START_EN,
				&rd) && (rd & DJTAG_MSTR_EN))
		cpu_relax();

	if (!is_w)
		regmap_read(map, SC_DJTAG_RD_DATA_BASE
				+ chain_id * 0x4, rval);
}

static void hi1382_mod_cfg_by_djtag(struct regmap *map,
				   u32 offset, u32 mod_sel,
				    u32 mod_mask, bool is_w,
				     u32 wval, int chain_id,
				      u32 *rval)
{
	u32 rd;

	BUG_ON(!map);

	if (!(mod_mask & CHAIN_UNIT_CFG_EN_EX))
		mod_mask = CHAIN_UNIT_CFG_EN_EX;

	/* djtag mster enable */
	regmap_write(map, SC_DJTAG_SEC_ACC_EN_EX,
			DJTAG_SEC_ACC_EN_EX);
	if (is_w) {
		regmap_write(map, SC_DJTAG_MSTR_CFG_EX,
				DJTAG_MSTR_WR_EX | (mod_sel
				<< DEBUG_MODULE_SEL_SHIFT_EX)
				| (mod_mask
				& CHAIN_UNIT_CFG_EN_EX));
		regmap_write(map, SC_DJTAG_MSTR_DATA_EX,
				wval);
	} else
		regmap_write(map, SC_DJTAG_MSTR_CFG_EX,
				DJTAG_MSTR_RD_EX | (mod_sel
				<< DEBUG_MODULE_SEL_SHIFT_EX)
				| (mod_mask
				& CHAIN_UNIT_CFG_EN_EX));

	/* address offset */
	regmap_write(map, SC_DJTAG_MSTR_ADDR_EX, offset);

	/* start to write to djtag register */
	regmap_write(map, SC_DJTAG_MSTR_START_EN_EX,
			DJTAG_MSTR_START_EN_EX);

	while (!regmap_read(map, SC_DJTAG_MSTR_START_EN_EX,
				&rd) && (rd
					& DJTAG_MSTR_START_EN_EX))
		cpu_relax();

	if (!is_w)
		regmap_read(map, SC_DJTAG_RD_DATA_BASE_EX
				+ chain_id * 0x4, rval);
}


/**
 * djtag_writel - write registers via djtag
 * @node:	djtag node
 * @offset:	register's offset
 * @mod_sel:	module selection
 * @mod_mask:	mask to select specific modules
 * @val:	value to write to register
 *
 * If error return errno, otherwise return 0.
 */
int djtag_writel(struct device_node *node, u32 offset,
			u32 mod_sel, u32 mod_mask, u32 val)
{
	struct regmap *map;
	unsigned long flags;
	struct djtag_of_data *tmp, *p;

	map = NULL;
	list_for_each_entry_safe(tmp, p, &djtag_list, list) {
		if (tmp->node == node) {
			map = tmp->scl_map;

			spin_lock_irqsave(&djtag_lock, flags);
			tmp->mod_cfg_by_djtag(map, offset, mod_sel,
						mod_mask, true,
						val, 0, NULL);
			spin_unlock_irqrestore(&djtag_lock, flags);
			break;
		}
	}

	if (!map)
		return -ENODEV;
	else
		return 0;
}
EXPORT_SYMBOL_GPL(djtag_writel);

/**
 * djtag_readl - read registers via djtag
 * @node:	djtag node
 * @offset:	register's offset
 * @mod_sel:	module type selection
 * @chain_id:	chain_id number, mostly is 0
 * @val:	register's value
 *
 * If error return errno, otherwise return 0.
 */
int djtag_readl(struct device_node *node, u32 offset,
				u32 mod_sel, int chain_id, u32 *val)
{
	struct regmap *map;
	unsigned long flags;
	struct djtag_of_data *tmp, *p;

	map = NULL;
	list_for_each_entry_safe(tmp, p, &djtag_list, list) {
		if (tmp->node == node) {
			map = tmp->scl_map;

			spin_lock_irqsave(&djtag_lock, flags);
			tmp->mod_cfg_by_djtag(map, offset, mod_sel,
						0, false,
						0, chain_id, val);
			spin_unlock_irqrestore(&djtag_lock, flags);
			break;
		}
	}

	if (!map)
		return -ENODEV;
	else
		return 0;
}
EXPORT_SYMBOL_GPL(djtag_readl);

static const struct of_device_id djtag_of_match[] = {
	/* for 660 and 1610 totem */
	{ .compatible = "hisilicon,hip05-djtag", .data = (void *)HISI_HIP05 },
	/* for 1382 totem and io */
	{ .compatible = "hisilicon,hi1382-djtag", .data = (void *)HISI_HI1382 },
	{},
};

MODULE_DEVICE_TABLE(of, djtag_of_match);

static int djtag_dev_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct djtag_of_data *dg_data;
	const struct of_device_id *of_id;
	struct device_node *scl_node;

	of_id = of_match_device(djtag_of_match, dev);
	if (!of_id)
		return -EINVAL;

	dg_data = kzalloc(sizeof(struct djtag_of_data), GFP_KERNEL);
	if (dg_data == NULL)
		return -ENOMEM;

	dg_data->node = dev->of_node;
	dg_data->type = (enum hisi_soc_type)of_id->data;
	if (dg_data->type == HISI_HI1382)
		dg_data->mod_cfg_by_djtag = hi1382_mod_cfg_by_djtag;
	else if (dg_data->type == HISI_HIP05)
		dg_data->mod_cfg_by_djtag = hip05_mod_cfg_by_djtag;
	else {
		dev_err(dev, "djtag configure error.\n");
		return -EINVAL;
	}

	INIT_LIST_HEAD(&dg_data->list);
	scl_node = of_parse_phandle(dev->of_node, "syscon", 0);
	if (!scl_node) {
		dev_warn(dev, "no hisilicon syscon.\n");
		return -EINVAL;
	}

	dg_data->scl_map = syscon_node_to_regmap(scl_node);
	if (IS_ERR(dg_data->scl_map)) {
		dev_warn(dev, "wrong syscon register address.\n");
		return -EINVAL;
	}

	list_add_tail(&dg_data->list, &djtag_list);
	dev_info(dev, "%s init successfully.\n",
					dg_data->node->name);
	return 0;
}

static int djtag_dev_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct djtag_of_data *tmp, *p;

	list_for_each_entry_safe(tmp, p, &djtag_list, list) {
		list_del(&tmp->list);
		dev_info(dev, "%s remove successfully.\n",
						tmp->node->name);
		kfree(tmp);
	}

	return 0;
}

static struct platform_driver djtag_dev_driver = {
	.driver = {
		.name = "hisi-djtag",
		.of_match_table = djtag_of_match,
	},
	.probe = djtag_dev_probe,
	.remove = djtag_dev_remove,
};

static int __init djtag_dev_init(void)
{
	return platform_driver_register(&djtag_dev_driver);
}

static void __exit djtag_dev_exit(void)
{
	platform_driver_unregister(&djtag_dev_driver);
}

arch_initcall_sync(djtag_dev_init);
module_exit(djtag_dev_exit);

MODULE_DESCRIPTION("Hisilicon djtag driver");
MODULE_AUTHOR("Xiaojun Tan");
MODULE_LICENSE("GPL");
MODULE_VERSION("V1R1");

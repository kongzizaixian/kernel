/******************************************************************************

                  ��Ȩ���� (C), 2011-2021, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : sre_sys_ctrl.h
  �� �� ��   : ����
  ��    ��   : g00220740
  ��������   : 2014��6��26��
  ����޸�   :
  ��������   : sysctrl/poe��ϵͳͷ�ļ�����
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __SYS_CTRL_REG_OFFSET_H__
#define __SYS_CTRL_REG_OFFSET_H__


#include "hrdCommon.h"
#include "hrdOs.h"
#include "osal_api.h"
#include "sre_crg_api.h"
#include "sre_sub_alg.h"
#include "HRD_hccs_hal.h"
#include "SRE_common.h"

#ifdef HRD_OS_LINUX
#include "iware_comm_kernel_api.h"
#endif

/*ϵͳ����ʱ��Ƶ�ʣ�Ĭ��50M*/
#define SYS_FREF  (50)
#define TOTEMC_PEOSUB_BASE (0x80000000)
#define TOTEMA_PEOSUB_BASE (0xE0000000)

/*����PLL����*/
#define SLICION_PLL (0x0)
#define TSMC_PLL    (0x1)
#define BIT_I(bitmap,i) ((bitmap>>(i))&(0x1))

typedef enum tagPllSel
{
    /*TOTEMC�ĸ���PLL*/
    SRE_TOTEMC_PLL0 = 0x0,
    SRE_TOTEMC_PLL1,
    SRE_TOTEMC_PLL2,
    SRE_TOTEMC_PLL3,
    SRE_TOTEMC_PLL4,

    /*TOTEMA�ĸ���PLL*/
    SRE_TOTEMA_PLL0,
    SRE_TOTEMA_PLL1,
    SRE_TOTEMA_PLL2,
    SRE_TOTEMA_PLL3,
    SRE_TOTEMA_PLL4,

    /*NIMBUS�ĸ���PLL*/
    SRE_NIMBUS_PLL0,
    SRE_NIMBUS_PLL1,
    SRE_NIMBUS_PLL2,
    SRE_NIMBUS_PLL3,
    SRE_NIMBUS_PLL4,
}SRE_PLL_SEL_E;

#define SYSCTRL_BASE                       (0x40010000)
#define POE_SUB_BASE                       (0x0)

/******************************************************************************/
/*                      XXX SYSCTRL Registers' Definitions                            */
/******************************************************************************/

#define SYSCTRL_SC_CPU_EDBGRQ_CTRL_REG          (SYSCTRL_BASE + 0x0)    /* ��Ӧcluster��Cortex-A57 CPU core debug���� */
#define SYSCTRL_SC_CPU_CP15SDIS_CRTL_REG        (SYSCTRL_BASE + 0x8)    /* ��Ӧcluster��Cortex-A57 CPU core ĳЩ��ȫ�Ĵ���CP15����ʹ�ܡ� */
#define SYSCTRL_SC_CPU_PMU_CTRL_REG             (SYSCTRL_BASE + 0xC)    /* ��Ӧcluster��PMU snapshot trigger request. */
#define SYSCTRL_SC_CLUS_L2_CLKEN_REG            (SYSCTRL_BASE + 0x10)   /* ��Ӧcluster��Cortex-A57 subsys��L2����ʱ��ʹ�� */
#define SYSCTRL_SC_CPU_GICDIS_CTRL_REG          (SYSCTRL_BASE + 0x14)   /* �رն�Ӧcluster��Cortex-A57 CPU core��GIC�ӿ��߼���ͬʱ��nIRQ��nFIQ��nVIRQ��nVFIQ�ź�ֱ��·������������ */
#define SYSCTRL_SC_CPU_CLKEN_REG                (SYSCTRL_BASE + 0x18)   /* ��Ӧcluster��Cortex-A57 CPU core��ȫ��ʱ��ʹ�ܡ� */
#define SYSCTRL_SC_CPU_L2FSHREQ_CTRL_REG        (SYSCTRL_BASE + 0x1C)   /* ��Ӧcluster��L2 hardware flush request�� */
#define SYSCTRL_SC_CPU_CLREXMONREQ_CTRL_REG     (SYSCTRL_BASE + 0x20)   /* ��Ӧcluster��clearing of the external global exclusive monitor request. */
#define SYSCTRL_SC_CPU_SYSBROADCAST_CTRL_REG    (SYSCTRL_BASE + 0x24)   /* SC_CPU_SYSBROADCAST_CTRLΪϵͳ�㲥���� */
#define SYSCTRL_SC_CPU_SINACT_CTRL_REG          (SYSCTRL_BASE + 0x28)   /* SC_CPU_SINACT_CTRLΪ��Ӧcluster��skyros�ӿ�ʹ�� */
#define SYSCTRL_SC_CLUS0_CTRL_RVBA0_REG         (SYSCTRL_BASE + 0x34)   /* SC_CLUS0_CTRL_RVBA��ʾAArch64��CPU0��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS0_CTRL_RVBA1_REG         (SYSCTRL_BASE + 0x3C)   /* SC_CLUS0_CTRL_RVBA��ʾAArch64��CPU1��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS0_CTRL_RVBA2_REG         (SYSCTRL_BASE + 0x44)   /* SC_CLUS0_CTRL_RVBA��ʾAArch64��CPU2��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS0_CTRL_RVBA3_REG         (SYSCTRL_BASE + 0x4C)   /* SC_CLUS0_CTRL_RVBA��ʾAArch64��CPU3��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ��� */
#define SYSCTRL_SC_CLUS1_CTRL_RVBA0_REG         (SYSCTRL_BASE + 0x54)   /* SC_CLUS1_CTRL_RVBA��ʾAArch64��CPU0��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS1_CTRL_RVBA1_REG         (SYSCTRL_BASE + 0x5C)   /* SC_CLUS1_CTRL_RVBA��ʾAArch64��CPU1��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS1_CTRL_RVBA2_REG         (SYSCTRL_BASE + 0x64)   /* SC_CLUS1_CTRL_RVBA��ʾAArch64��CPU2��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS1_CTRL_RVBA3_REG         (SYSCTRL_BASE + 0x6C)   /* SC_CLUS1_CTRL_RVBA��ʾAArch64��CPU3��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS2_CTRL_RVBA0_REG         (SYSCTRL_BASE + 0x74)   /* SC_CLUS2_CTRL_RVBA��ʾAArch64��CPU0��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS2_CTRL_RVBA1_REG         (SYSCTRL_BASE + 0x7C)   /* SC_CLUS2_CTRL_RVBA��ʾAArch64��CPU1��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS2_CTRL_RVBA2_REG         (SYSCTRL_BASE + 0x84)   /* SC_CLUS2_CTRL_RVBA��ʾAArch64��CPU2��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS2_CTRL_RVBA3_REG         (SYSCTRL_BASE + 0x8C)   /* SC_CLUS2_CTRL_RVBA��ʾAArch64��CPU3��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS3_CTRL_RVBA0_REG         (SYSCTRL_BASE + 0x94)   /* SC_CLUS3_CTRL_RVBA��ʾAArch64��CPU0��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS3_CTRL_RVBA1_REG         (SYSCTRL_BASE + 0x9C)   /* SC_CLUS3_CTRL_RVBA��ʾAArch64��CPU1��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS3_CTRL_RVBA2_REG         (SYSCTRL_BASE + 0xA4)   /* SC_CLUS3_CTRL_RVBA��ʾAArch64��CPU2��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_CLUS3_CTRL_RVBA3_REG         (SYSCTRL_BASE + 0xAC)   /* SC_CLUS3_CTRL_RVBA��ʾAArch64��CPU3��λ����ַ�����á��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU���� */
#define SYSCTRL_SC_PERIPHBASE_REG               (SYSCTRL_BASE + 0xB0)   /* SC_PERIPHBASE��ʾCPU�ڲ�GICC��ʼ��ַ */
#define SYSCTRL_SC_DBG_AUTH_CTRL_REG            (SYSCTRL_BASE + 0xB4)   /* ��ȫ�ȼ���Ȩ���ƼĴ�������ע�⣺1���˼Ĵ����ռ�����ǰ�ȫ���ʲ��ܳɹ���2��Ĭ�Ͼ��Ǵ򿪵���ģʽ����©��������������ʱ���ʼ���رյ��Թ��ܣ� */
#define SYSCTRL_SC_CLUS_CRYPTODISABLE_REG       (SYSCTRL_BASE + 0xB8)   /* SC_CLUS_CRYPTODISABLE��ʾIndividual processor Cryptography engine disable */
#define SYSCTRL_SC_CORE0_EVENT_EN_REG           (SYSCTRL_BASE + 0x930)  /* ��Core0��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE1_EVENT_EN_REG           (SYSCTRL_BASE + 0x934)  /* ��Core1��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE2_EVENT_EN_REG           (SYSCTRL_BASE + 0x938)  /* ��Core2��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE3_EVENT_EN_REG           (SYSCTRL_BASE + 0x93C)  /* ��Core3��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE4_EVENT_EN_REG           (SYSCTRL_BASE + 0x940)  /* ��Core4��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE5_EVENT_EN_REG           (SYSCTRL_BASE + 0x944)  /* ��Core5��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE6_EVENT_EN_REG           (SYSCTRL_BASE + 0x948)  /* ��Core6��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE7_EVENT_EN_REG           (SYSCTRL_BASE + 0x94C)  /* ��Core7��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE8_EVENT_EN_REG           (SYSCTRL_BASE + 0x950)  /* ��Core8��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE9_EVENT_EN_REG           (SYSCTRL_BASE + 0x954)  /* ��Core9��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE10_EVENT_EN_REG          (SYSCTRL_BASE + 0x958)  /* ��Core10��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE11_EVENT_EN_REG          (SYSCTRL_BASE + 0x95C)  /* ��Core11��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE12_EVENT_EN_REG          (SYSCTRL_BASE + 0x960)  /* ��Core12��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE13_EVENT_EN_REG          (SYSCTRL_BASE + 0x964)  /* ��Core13��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE14_EVENT_EN_REG          (SYSCTRL_BASE + 0x968)  /* ��Core14��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CORE15_EVENT_EN_REG          (SYSCTRL_BASE + 0x96C)  /* ��Core15��EventԴͷѡ��ʹ�� */
#define SYSCTRL_SC_CPU_DBGL1RSTDISABLE_CTRL_REG (SYSCTRL_BASE + 0x980)  /* ��Ӧcluster��Cortex-A57 CPU core debug���� */
#define SYSCTRL_SC_SYSMODE_CTRL_REG             (SYSCTRL_BASE + 0x3000) /* SC_SYSMODE_CTRLΪCDIE_CRGϵͳʱ�ӹ���ģʽ���ƼĴ��� */
#define SYSCTRL_SC_SYSSOFTRST_CTRL_REG          (SYSCTRL_BASE + 0x3004) /* SC_SYSSOFTRST_CTRLΪCDIE_CRGϵͳ��λ�Ĵ����� */
#define SYSCTRL_SC_PLLCTRL_REG                  (SYSCTRL_BASE + 0x3010) /* SC_PLLCTRLΪPLL���ƼĴ����� */
#define SYSCTRL_SC_PLLFCTRL4_REG                (SYSCTRL_BASE + 0x3024) /* SC_PLLFCTRL4ΪCIDE_CRG��PLL2���ƼĴ���0�� */
#define SYSCTRL_SC_PLLFCTRL5_REG                (SYSCTRL_BASE + 0x3028) /* SC_PLLFCTRL5ΪCIDE_CRG��PLL2���ƼĴ���1�� */
#define SYSCTRL_SC_PLLFCTRL6_REG                (SYSCTRL_BASE + 0x302C) /* SC_PLLFCTRL6ΪCIDE_CRG��PLL3���ƼĴ���0�� */
#define SYSCTRL_SC_PLLFCTRL7_REG                (SYSCTRL_BASE + 0x3030) /* SC_PLLFCTRL7ΪCIDE_CRG��PLL3���ƼĴ���1�� */
#define SYSCTRL_SC_PLL_CLK_BYPASS_DDR_REG       (SYSCTRL_BASE + 0x3044) /* SC_PLL_CLK_BYPASS_DDRΪCDIE_CRG��DDR PLL��ع���ʱ��ѡ�� */
#define SYSCTRL_SC_REF_CLK_EN_REG               (SYSCTRL_BASE + 0x3050) /* SC_REF_CLK_EN��clk_ref��ʱ��ʹ�ܼĴ����� */
#define SYSCTRL_SC_REF_CLK_DIS_REG              (SYSCTRL_BASE + 0x3054) /* SC_REF_CLK_DIS��clk_refʱ�ӽ�ֹ�Ĵ����� */
#define SYSCTRL_SC_GPIO_CLK_EN_REG              (SYSCTRL_BASE + 0x3058) /* SC_GPIO_CLK_EN��clk_gpio_db��ʱ��ʹ�ܼĴ����� */
#define SYSCTRL_SC_GPIO_CLK_DIS_REG             (SYSCTRL_BASE + 0x305C) /* SC_GPIO_CLK_DIS��clk_gpio_dbʱ�ӽ�ֹ�Ĵ����� */
#define SYSCTRL_SC_CLUS0_CRG_CLK_EN_REG         (SYSCTRL_BASE + 0x3060) /* SC_CLUS0_CRG_CLK_EN��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵ����á� */
#define SYSCTRL_SC_CLUS0_CRG_CLK_DIS_REG        (SYSCTRL_BASE + 0x3064) /* SC_CLUS0_CRG_CLK_DIS��ʾ�Ե�ǰCLUSTER��CRG��ʱ�ӽ�ֹʹ�����á� */
#define SYSCTRL_SC_CLUS0_CRG_RESET_REQ_REG      (SYSCTRL_BASE + 0x3068) /* SC_CLUS0_CRG_RESET_REQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ����á� */
#define SYSCTRL_SC_CLUS0_CRG_RESET_DREQ_REG     (SYSCTRL_BASE + 0x306C) /* SC_CLUS0_CRG_RESET_DEREQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ�ȥ��λ�� */
#define SYSCTRL_SC_CLUS1_CRG_CLK_EN_REG         (SYSCTRL_BASE + 0x3070) /* SC_CLUS1_CRG_CLK_EN��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵ����á� */
#define SYSCTRL_SC_CLUS1_CRG_CLK_DIS_REG        (SYSCTRL_BASE + 0x3074) /* SC_CLUS1_CRG_CLK_DIS��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵĹرա� */
#define SYSCTRL_SC_CLUS1_CRG_RESET_REQ_REG      (SYSCTRL_BASE + 0x3078) /* SC_CLUS1_CRG_RESET_REQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ����á� */
#define SYSCTRL_SC_CLUS1_CRG_RESET_DREQ_REG     (SYSCTRL_BASE + 0x307C) /* SC_CLUS1_CRG_RESET_DEREQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ�ȥ��λ�� */
#define SYSCTRL_SC_CLUS2_CRG_CLK_EN_REG         (SYSCTRL_BASE + 0x3080) /* SC_CLUS2_CRG_CLK_EN��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵ����á� */
#define SYSCTRL_SC_CLUS2_CRG_CLK_DIS_REG        (SYSCTRL_BASE + 0x3084) /* SC_CLUS2_CRG_CLK_DIS��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵĹرա� */
#define SYSCTRL_SC_CLUS2_CRG_RESET_REQ_REG      (SYSCTRL_BASE + 0x3088) /* SC_CLUS2_CRG_RESET_REQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ����á� */
#define SYSCTRL_SC_CLUS2_CRG_RESET_DREQ_REG     (SYSCTRL_BASE + 0x308C) /* SC_CLUS2_CRG_RESET_DEREQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ�ȥ��λ�� */
#define SYSCTRL_SC_CLUS3_CRG_CLK_EN_REG         (SYSCTRL_BASE + 0x3090) /* SC_CLUS3_CRG_CLK_EN��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵ����á� */
#define SYSCTRL_SC_CLUS3_CRG_CLK_DIS_REG        (SYSCTRL_BASE + 0x3094) /* SC_CLUS3_CRG_CLK_DIS��ʾ�Ե�ǰCLUSTER��CRG��CLKEN�źŵĹرա� */
#define SYSCTRL_SC_CLUS3_CRG_RESET_REQ_REG      (SYSCTRL_BASE + 0x3098) /* SC_CLUS3_CRG_RESET_REQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ����á� */
#define SYSCTRL_SC_CLUS3_CRG_RESET_DREQ_REG     (SYSCTRL_BASE + 0x309C) /* SC_CLUS3_CRG_RESET_DEREQ��ʾ�Ե�ǰCLUSTER��CRG��RST_REQ�źŵ�ȥ��λ�� */
#define SYSCTRL_SC_LLC_CLK_EN_REG               (SYSCTRL_BASE + 0x30A0) /* SC_LLC_CLK_ENΪLLC��ʱ��ʹ�ܼĴ��� */
#define SYSCTRL_SC_LLC_CLK_DIS_REG              (SYSCTRL_BASE + 0x30A4) /* SC_LLC_CLK_DISΪLLC��ʱ�ӽ�ֹ�Ĵ��� */
#define SYSCTRL_SC_LLC_RESET_REQ_REG            (SYSCTRL_BASE + 0x30A8) /* SC_LLC_RESET_REQΪCDIE��LLC��λ������ƼĴ��� */
#define SYSCTRL_SC_LLC_RESET_DREQ_REG           (SYSCTRL_BASE + 0x30AC) /* SC_LLC_RESET_DREQΪCDIE��LLC��λȥ������ƼĴ��� */
#define SYSCTRL_SC_DDRC_CLK_EN_REG              (SYSCTRL_BASE + 0x30B0) /* SC_DDRC_CLK_ENΪDDRC��ʱ��ʹ�ܼĴ��� */
#define SYSCTRL_SC_DDRC_CLK_DIS_REG             (SYSCTRL_BASE + 0x30B4) /* SC_DDRC_CLK_DISΪDDRC��ʱ�ӽ�ֹ�Ĵ��� */
#define SYSCTRL_SC_DDRC_RESET_REQ_REG           (SYSCTRL_BASE + 0x30B8) /* SC_DDRC_RESET_REQΪCDIE��DDRC��λ������ƼĴ��� */
#define SYSCTRL_SC_DDRC_RESET_DREQ_REG          (SYSCTRL_BASE + 0x30BC) /* SC_DDRC_RESET_DREQΪCDIE��DDRC��λȥ������ƼĴ��� */
#define SYSCTRL_SC_SLLC_CLK_EN_REG              (SYSCTRL_BASE + 0x30D0) /* SC_SLLC_CLK_EN��ʾSLLC�߼�ʱ��ʹ�����üĴ��� */
#define SYSCTRL_SC_SLLC_CLK_DIS_REG             (SYSCTRL_BASE + 0x30D4) /* SC_SLLC_CLK_DIS��ʾSLLC�߼�ʱ�ӽ�ֹ�Ĵ��� */
#define SYSCTRL_SC_SLLC_RESET_REQ_REG           (SYSCTRL_BASE + 0x30D8) /* SC_SLLC_RESET_REQ��ʾSLLC����λ������ƼĴ��� */
#define SYSCTRL_SC_SLLC_RESET_DREQ_REG          (SYSCTRL_BASE + 0x30DC) /* SC_SLLC_RESET_DREQ��ʾSLLC����λȥ������ƼĴ��� */
#define SYSCTRL_SC_SLLC_TSVRX_RESET_REQ_REG     (SYSCTRL_BASE + 0x30E0) /* SC_SLLC_TSVRX_RESET_REQΪSLLC TSVRXͨ����λ������ƼĴ��� */
#define SYSCTRL_SC_SLLC_TSVRX_RESET_DREQ_REG    (SYSCTRL_BASE + 0x30E4) /* SC_SLLC_TSVRX_RESET_DREQΪSLLC TSVRXͨ����λ������ƼĴ��� */
#define SYSCTRL_SC_HPM_CLK_EN_REG               (SYSCTRL_BASE + 0x30E8) /* SC_HPM_CLK_EN��ʾHPM�߼�ʱ��ʹ�����üĴ��� */
#define SYSCTRL_SC_HPM_CLK_DIS_REG              (SYSCTRL_BASE + 0x30EC) /* SC_HPM_CLK_DIS��ʾHPM�߼�ʱ�ӽ�ֹ���üĴ��� */
#define SYSCTRL_SC_HPM_RESET_REQ_REG            (SYSCTRL_BASE + 0x30F0) /* SC_HPM_RESET_REQΪCDIE��HPM��λ������ƼĴ��� */
#define SYSCTRL_SC_HPM_RESET_DREQ_REG           (SYSCTRL_BASE + 0x30F4) /* SC_HPM_RESET_DREQΪCDIE��HPM��λȥ������ƼĴ��� */
#define SYSCTRL_SC_DJTAG_CLK_EN_REG             (SYSCTRL_BASE + 0x3100) /* SC_DJTAG_CLKEN��ʾDJTAG�߼�ʱ��ʹ�����üĴ��� */
#define SYSCTRL_SC_DJTAG_CLK_DIS_REG            (SYSCTRL_BASE + 0x3104) /* SC_DJTAG_CLK_DIS��ʾDJTAG�߼�ʱ�ӽ�ֹ�Ĵ��� */
#define SYSCTRL_SC_DJTAG_SRST_REQ_REG           (SYSCTRL_BASE + 0x3108) /* SC_DJTAG_SRST_REQ��ʾDJTAG�߼���λ����Ĵ��� */
#define SYSCTRL_SC_DJTAG_SRST_DREQ_REG          (SYSCTRL_BASE + 0x310C) /* SC_DJTAG_SRST_DREQ��ʾDJTAG�߼���λȥ����Ĵ��� */
#define SYSCTRL_SC_HHA_MN_CLK_EN_REG            (SYSCTRL_BASE + 0x3110) /* SC_HHA_MN_CLK_EN��ʾHHA��MN�߼�ʱ��ʹ�����üĴ��� */
#define SYSCTRL_SC_HHA_MN_CLK_DIS_REG           (SYSCTRL_BASE + 0x3114) /* SC_HHA_MN_CLK_DIS��ʾHHA��MN�߼�ʱ�ӽ�ֹʹ�����üĴ��� */
#define SYSCTRL_SC_HHA_MN_RESET_REQ_REG         (SYSCTRL_BASE + 0x3118) /* SC_HHA_MN_RESET_REQΪHHA��MN��λ������ƼĴ��� */
#define SYSCTRL_SC_HHA_MN_RESET_DREQ_REG        (SYSCTRL_BASE + 0x311C) /* SC_HHA_MN_RESET_DREQΪHHA��MN��λȥ������ƼĴ��� */
#define SYSCTRL_SC_WDOG_RESET_CFG_REG           (SYSCTRL_BASE + 0x3180) /* ���Ź������λ��Χ���ƼĴ����� */
#define SYSCTRL_SC_TSMC_PLLCTRL2_REG            (SYSCTRL_BASE + 0x3208) /* SC_TSMC_PLLCTRL2ΪCIDE CRG��PLL2��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
#define SYSCTRL_SC_TSMC_PLLCTRL3_REG            (SYSCTRL_BASE + 0x320C) /* SC_TSMC_PLLCTRL3ΪCIDE CRG��PLL3��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
#define SYSCTRL_SC_PLL_SEL_DDR_REG              (SYSCTRL_BASE + 0x3214) /* SC_PLL_SELΪCIDE�ڵ�PLLѡ����ƼĴ����� */
#define SYSCTRL_SC_ALL_SCAN_CTRL_REG            (SYSCTRL_BASE + 0x3220) /* SC_ALL_SCAN_CTRLΪALL_SCANģʽOCCʱ�ӹضϿ��ƼĴ����� */
#define SYSCTRL_SC_TSENSOR_CTRL_REG             (SYSCTRL_BASE + 0x5000) /* Ƭ���¶ȴ����������������á� */
#define SYSCTRL_SC_TSENSOR_TEST_REG             (SYSCTRL_BASE + 0x5004) /* Tsensor����ʹ�ã��������û���Ҫ�����޸ġ� */
#define SYSCTRL_SC_TSENSOR_ALARM_REG            (SYSCTRL_BASE + 0x5008) /* Ƭ���¶ȴ������¶��������üĴ��� */
#define SYSCTRL_SC_DDRC_APB_CLK_EN_REG          (SYSCTRL_BASE + 0x5400) /* DDRC��APB����CLKEN���ƼĴ����� */
#define SYSCTRL_SC_MBIST_CPUI_ENABLE_REG        (SYSCTRL_BASE + 0x5C00) /* CPU����MBISTѡ���źţ�оƬ��·����ʹ�á� */
#define SYSCTRL_SC_MBIST_CPUI_RESET_N_REG       (SYSCTRL_BASE + 0x5C04) /* CPU����MBIST��λ�ź� */
#define SYSCTRL_SC_MBIST_CPUI_DATAIN_REG        (SYSCTRL_BASE + 0x5C08) /* CPU����MBIST��TMB��·���ݺ�ָ������ӿڼĴ��� */
#define SYSCTRL_SC_MBIST_CPUI_WRITE_EN_REG      (SYSCTRL_BASE + 0x5C0C) /* DFT MBISTģʽ��TMB��·CPU2TAP�ӿ����üĴ�����оƬ��·����ʹ�á� */
#define SYSCTRL_SC_SRC_INT_REG                  (SYSCTRL_BASE + 0x6000) /* ϵͳ�������ж�Դ�Ĵ��� */
#define SYSCTRL_SC_INT_MASK_REG                 (SYSCTRL_BASE + 0x6004) /* ϵͳ�������ж����μĴ��� */
#define SYSCTRL_SC_IM_CTRL_REG                  (SYSCTRL_BASE + 0x6008)
#define SYSCTRL_SC_IM_STAT_REG                  (SYSCTRL_BASE + 0x600C)
#define SYSCTRL_SC_XTAL_CTRL_REG                (SYSCTRL_BASE + 0x6010)
#define SYSCTRL_SC_ITCR_REG                     (SYSCTRL_BASE + 0x6014)
#define SYSCTRL_SC_ITIR0_REG                    (SYSCTRL_BASE + 0x6018)
#define SYSCTRL_SC_ITOR_REG                     (SYSCTRL_BASE + 0x601C)
#define SYSCTRL_SC_CNT_CTRL_REG                 (SYSCTRL_BASE + 0x6020)
#define SYSCTRL_SC_BOOT_CTRL_CFG_EN_REG         (SYSCTRL_BASE + 0x6030) /* SC_BOOT_CTRL_CFG_EN��ʾCPU BOOT�ܽſ����źŵ�����ʹ�ܣ��˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU�ɷ��� */
#define SYSCTRL_SC_BOOT_CTRL_CFG_REG            (SYSCTRL_BASE + 0x6034) /* SC_BOOT_CTRL_CFG��ʾCPU���������źŵ����üĴ������˼Ĵ���Ϊ��ȫ�Ĵ�����ֻ�а�ȫCPU�ɷ��� */
#define SYSCTRL_SC_SOCKET_INITIALED_REG         (SYSCTRL_BASE + 0x6040) /* SC_SOCKET_INITIALED��ʾsocket�ĳ�ʼ����ɱ�ǼĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_EN_REG           (SYSCTRL_BASE + 0x6100) /* SC_SYSCNT_SYNC_EN��ʾͬ��system counter������ʹ�ܼĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_DST_ADDR1_REG    (SYSCTRL_BASE + 0x6104) /* SC_SYSCNT_SYNC_DST_ADDR1��ʾͬ��system counter�ĵ�ַ�Ĵ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_DST_ADDR0_REG    (SYSCTRL_BASE + 0x6108) /* SC_SYSCNT_SYNC_DST_ADDR0��ʾͬ��system counter�ĵ�ַ�Ĵ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_SRC_ADDR1_REG    (SYSCTRL_BASE + 0x610C) /* SC_SYSCNT_SYNC_SRC_ADDR1��ʾͬ��system counter�ĵ�ַ�Ĵ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_SRC_ADDR0_REG    (SYSCTRL_BASE + 0x6110) /* SC_SYSCNT_SYNC_SRC_ADDR0��ʾͬ��system counter�ĵ�ַ�Ĵ��� */
#define SYSCTRL_SC_CORESIGHT_SYNC_DST_ADDR1_REG (SYSCTRL_BASE + 0x6114) /* SC_CORESIGHT_SYNC_DST_ADDR1��ʾͬ��system counter�ĵ�ַ�Ĵ��� */
#define SYSCTRL_SC_CORESIGHT_SYNC_DST_ADDR0_REG (SYSCTRL_BASE + 0x6118) /* SC_CORESIGHT_SYNC_DST_ADDR0��ʾͬ��system counter�ĵ�ַ�Ĵ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_AVE_EN_REG       (SYSCTRL_BASE + 0x6120) /* SC_SYSCNT_SYNC_AVE_EN��ʾsystem counterͬ������ʱƽ��ʹ�ܼĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_DST_DATA_EN_REG  (SYSCTRL_BASE + 0x6140) /* SC_SYSCNT_SYNC_DST_DATA_EN��ʾsystem counterͬ������ʹ�ܵļĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_DST_DATA0_REG    (SYSCTRL_BASE + 0x6148) /* SC_SYSCNT_SYNC_DST_DATA0��ʾsystem counterͬ�����ݵļĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_DST_DATA1_REG    (SYSCTRL_BASE + 0x614C) /* SC_SYSCNT_SYNC_DST_DATA1��ʾsystem counterͬ�����ݵļĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_SRC_DATA_EN_REG  (SYSCTRL_BASE + 0x6180) /* SC_SYSCNT_SYNC_SRC_DATA_EN��ʾsystem counterͬ������ʹ�ܵļĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_SRC_DATA0_REG    (SYSCTRL_BASE + 0x6188) /* SC_SYSCNT_SYNC_SRC_DATA0��ʾsystem counterͬ�����ݵļĴ��� */
#define SYSCTRL_SC_SYSCNT_SYNC_SRC_DATA1_REG    (SYSCTRL_BASE + 0x618C) /* SC_SYSCNT_SYNC_SRC_DATA1��ʾsystem counterͬ�����ݵļĴ��� */
#define SYSCTRL_SC_SYSCNT_VAL_CFG_EN_REG        (SYSCTRL_BASE + 0x6200) /* SC_SYSCNT_VAL_CFG_EN��ʾsystem counterͬ��ʱͳ���ӳٵ�����ʹ�ܼĴ��� */
#define SYSCTRL_SC_SYSCNT_VAL_CFG_DATA_REG      (SYSCTRL_BASE + 0x6204) /* SC_SYSCNT_VAL_CFG_DATA1��ʾsystem counterͬ��ʱͳ���ӳٸ�32bit�����üĴ��� */
#define SYSCTRL_SC_PROBE_SYSCNT_EN_REG          (SYSCTRL_BASE + 0x6210) /* SC_PROBE_SYSCNT_EN��ʾsystem counterͬ��ʱͳ���ӳٵ�probeʹ�ܼĴ��� */
#define SYSCTRL_SC_PROBE_SYSCNT_DATA_REG        (SYSCTRL_BASE + 0x6214) /* SC_PROBE_SYSCNT_DATA��ʾsystem counterͬ��ʱͳ���ӳٵ�probe���ݼĴ��� */
#define SYSCTRL_SC_BROADCAST_EN_REG             (SYSCTRL_BASE + 0x6220) /* SC_BROADCAST_EN��ʾCPU CORE EVENT_EN��broadcastʹ�� */
#define SYSCTRL_SC_BROADCAST_DIE1_ADDR0_REG     (SYSCTRL_BASE + 0x6230) /* SC_BROADCAST_DIE1_ADDR0��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE1��ַ */
#define SYSCTRL_SC_BROADCAST_DIE1_ADDR1_REG     (SYSCTRL_BASE + 0x6234) /* SC_BROADCAST_DIE1_ADDR1��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE1��ַ */
#define SYSCTRL_SC_BROADCAST_DIE2_ADDR0_REG     (SYSCTRL_BASE + 0x6238) /* SC_BROADCAST_DIE2_ADDR0��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE2��ַ */
#define SYSCTRL_SC_BROADCAST_DIE2_ADDR1_REG     (SYSCTRL_BASE + 0x623C) /* SC_BROADCAST_DIE2_ADDR1��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE2��ַ */
#define SYSCTRL_SC_BROADCAST_DIE3_ADDR0_REG     (SYSCTRL_BASE + 0x6240) /* SC_BROADCAST_DIE3_ADDR0��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE3��ַ */
#define SYSCTRL_SC_BROADCAST_DIE3_ADDR1_REG     (SYSCTRL_BASE + 0x6244) /* SC_BROADCAST_DIE3_ADDR1��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE3��ַ */
#define SYSCTRL_SC_BROADCAST_DIE4_ADDR0_REG     (SYSCTRL_BASE + 0x6248) /* SC_BROADCAST_DIE4_ADDR0��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE4��ַ */
#define SYSCTRL_SC_BROADCAST_DIE4_ADDR1_REG     (SYSCTRL_BASE + 0x624C) /* SC_BROADCAST_DIE4_ADDR1��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE4��ַ */
#define SYSCTRL_SC_BROADCAST_DIE5_ADDR0_REG     (SYSCTRL_BASE + 0x6250) /* SC_BROADCAST_DIE5_ADDR0��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE5��ַ */
#define SYSCTRL_SC_BROADCAST_DIE5_ADDR1_REG     (SYSCTRL_BASE + 0x6254) /* SC_BROADCAST_DIE5_ADDR1��ʾCPU CORE EVENT_EN�Ĺ㲥��DIE5��ַ */
#define SYSCTRL_SC_BROADCAST_CORE_EVENT_REG     (SYSCTRL_BASE + 0x6260) /* SC_BROADCAST_CORE_EVENT��ʾSYSCTRL������������CPU CORE�� EVENT_EN�㲥 */
#define SYSCTRL_SC_DJTAG_MSTR_EN_REG            (SYSCTRL_BASE + 0x6800) /* SC_DJTAG_MSTR_ENΪSYS_CTRL��DJTAG Masterʹ�ܿ��� */
#define SYSCTRL_SC_DJTAG_MSTR_START_EN_REG      (SYSCTRL_BASE + 0x6804) /* SC_DJTAG_MSTR_START_ENΪDJTAG Master����chain����startʹ�� */
#define SYSCTRL_SC_DJTAG_SEC_ACC_EN_REG         (SYSCTRL_BASE + 0x6808) /* DJTAG���ʸ�ģ���ڰ�ȫ����Ĵ����İ�ȫ���ʿ���ʹ�ܡ���ע�⣺1���˼Ĵ����ռ�����ǰ�ȫ���ʲ��ܳɹ����� */
#define SYSCTRL_SC_DJTAG_DEBUG_MODULE_SEL_REG   (SYSCTRL_BASE + 0x680C) /* SC_DJTAG_DEBUG_MODULE_SELΪSYS_CTRL��DJTAG Master���÷���ģ��Ĵ��� */
#define SYSCTRL_SC_DJTAG_MSTR_WR_REG            (SYSCTRL_BASE + 0x6810) /* SC_DJTAG_MSTR_WRΪSYS_CTRL��DJTAG Master�Ķ�д�����ź� */
#define SYSCTRL_SC_DJTAG_CHAIN_UNIT_CFG_EN_REG  (SYSCTRL_BASE + 0x6814) /* SC_DJTAG_CHAIN_UNIT_CFG_ENΪDJTAG Master��chain���ϵ�Ԫ�ķ���ʹ�� */
#define SYSCTRL_SC_DJTAG_MSTR_ADDR_REG          (SYSCTRL_BASE + 0x6818) /* SC_DJTAG_MSTR_ADDRΪSYS_CTRL��DJTAG Master���÷���ģ���ƫ�Ƶ�ַ�Ĵ��� */
#define SYSCTRL_SC_DJTAG_MSTR_DATA_REG          (SYSCTRL_BASE + 0x681C) /* SC_DJTAG_MSTR_DATAΪSYS_CTRL��DJTAG Master��д���� */
#define SYSCTRL_SC_DJTAG_TMOUT_REG              (SYSCTRL_BASE + 0x6820) /* SC_DJTAG_TMOUTΪSYS_CTRL��DJTAG Master��״̬����ʱ��ֵ */
#define SYSCTRL_SC_TDRE_OP_ADDR_REG             (SYSCTRL_BASE + 0x6824) /* SC_TDRE_OP_ADDRΪSYS_CTRL��DJTAG Master����TDREģ���ƫ�Ƶ�ַ�Ĵ����Ͳ������ͼĴ��� */
#define SYSCTRL_SC_TDRE_WDATA_REG               (SYSCTRL_BASE + 0x6828) /* SC_TDRE_DATAΪSYS_CTRL��DJTAG Master��дTDRE���� */
#define SYSCTRL_SC_TDRE_REPAIR_EN_REG           (SYSCTRL_BASE + 0x682C) /* SC_TDRE_REPAIR_ENΪSYS_CTRL��DJTAG Master��TDRE REPAIRʹ�� */
#define SYSCTRL_SC_AXI_MSTR_START_EN_REG        (SYSCTRL_BASE + 0x6830) /* SC_AXI_MSTR_START_EN��ʾSYS_CTRL��AXI Master��startʹ�� */
#define SYSCTRL_SC_AXI_MSTR_SEC_ACC_EN_REG      (SYSCTRL_BASE + 0x6834) /* sysctrl��AXI Master����DDR��ȫ��ַ�ռ�İ�ȫ���ʿ���ʹ�ܡ���ע�⣺1���˼Ĵ����ռ�����ǰ�ȫ���ʲ��ܳɹ����� */
#define SYSCTRL_SC_AXI_MSTR_WR_REG              (SYSCTRL_BASE + 0x6838) /* SC_AXI_MSTR_WRΪSYS_CTRL��AXI Master��дʹ�� */
#define SYSCTRL_SC_AXI_MSTR_USER_REG            (SYSCTRL_BASE + 0x683C) /* SC_AXI_MSTR_USER��ʾSYS_CTRL��AXI Master�������ID */
#define SYSCTRL_SC_AXI_MSTR_ADDR1_REG           (SYSCTRL_BASE + 0x6840) /* SC_AXI_MSTR_ADDR1ΪSYS_CTRL��AXI Master�ķ��ʵ�ַbit[63:32] */
#define SYSCTRL_SC_AXI_MSTR_ADDR0_REG           (SYSCTRL_BASE + 0x6844) /* SC_AXI_MSTR_ADDR0ΪSYS_CTRL��AXI Master�ķ��ʵ�ַbit[31:0] */
#define SYSCTRL_SC_AXI_MSTR_DATA3_REG           (SYSCTRL_BASE + 0x6848) /* SC_AXI_MSTR_DATA3ΪSYS_CTRL��AXI Master�ķ�������bit[127:96] */
#define SYSCTRL_SC_AXI_MSTR_DATA2_REG           (SYSCTRL_BASE + 0x684C) /* SC_AXI_MSTR_DATA2ΪSYS_CTRL��AXI Master�ķ�������bit[95:64] */
#define SYSCTRL_SC_AXI_MSTR_DATA1_REG           (SYSCTRL_BASE + 0x6850) /* SC_AXI_MSTR_DATA1ΪSYS_CTRL��AXI Master�ķ�������bit[63:32] */
#define SYSCTRL_SC_AXI_MSTR_DATA0_REG           (SYSCTRL_BASE + 0x6854) /* SC_AXI_MSTR_DATA0ΪSYS_CTRL��AXI Master�ķ�������bit[31:0] */
#define SYSCTRL_SC_CTRL_HC_HHA_REG              (SYSCTRL_BASE + 0x8400) /* HHA HC memory���ƼĴ��� */
#define SYSCTRL_SC_CTRL_RASHDE_HHA_REG          (SYSCTRL_BASE + 0x840C) /* HHA HDE RAS memory���ƼĴ��� */
#define SYSCTRL_SC_CTRL_HC_LLC_REG              (SYSCTRL_BASE + 0x8410) /* LLC HC memory���ƼĴ��� */
#define SYSCTRL_SC_CTRL_RASHDE_LLC_REG          (SYSCTRL_BASE + 0x8414) /* LLC HDE RAS memory���ƼĴ��� */
#define SYSCTRL_SC_HS_MEM_ADJUST_HC_REG         (SYSCTRL_BASE + 0x8418) /* CPU HC memory ���ƼĴ��� */
#define SYSCTRL_SC_HS_MEM_ADJUST_REG            (SYSCTRL_BASE + 0x841C) /* CPU RFS memory ���ƼĴ��� */
#define SYSCTRL_SC_CTRL_RASHDE_CSYS_REG         (SYSCTRL_BASE + 0x8420) /* Coresight HDE RAS memory���ƼĴ��� */
#define SYSCTRL_SC_ECO_RSV0_REG                 (SYSCTRL_BASE + 0x8800) /* ECO �Ĵ���0 */
#define SYSCTRL_SC_ECO_RSV1_REG                 (SYSCTRL_BASE + 0x8804) /* ECO �Ĵ���1 */
#define SYSCTRL_SC_ECO_RSV2_REG                 (SYSCTRL_BASE + 0x8810) /* ECO �Ĵ���2 */
#define SYSCTRL_SC_CPU_PMUSNAPSHOTACK_ST_REG    (SYSCTRL_BASE + 0xA000) /* ��Ӧcluster��PMU snapshot trigger acknowledge */
#define SYSCTRL_SC_CPU_SMPEN_ST_REG             (SYSCTRL_BASE + 0xA004) /* ��Ӧcluster��Cortex-A57 CPU core����smpģʽָʾ�� */
#define SYSCTRL_SC_CPU_STANDBYWFE_ST_REG        (SYSCTRL_BASE + 0xA008) /* ��Ӧcluster��Cortex-A57 CPU core����WFE����ģʽָʾ�� */
#define SYSCTRL_SC_CPU_STANDBYWFI_ST_REG        (SYSCTRL_BASE + 0xA00C) /* ��Ӧcluster��Cortex-A57 CPU core����WFI����ģʽָʾ�� */
#define SYSCTRL_SC_CPU_DBGACK_ST_REG            (SYSCTRL_BASE + 0xA010) /* ��Ӧcluster��Cortex-A57 CPU core debug������Ӧָʾ�� */
#define SYSCTRL_SC_CPU_CLREXMONACK_ST_REG       (SYSCTRL_BASE + 0xA014) /* ��Ӧcluster��clearing of the external global exclusive monitor acknowledge. */
#define SYSCTRL_SC_CPU_STANDBYWFIL2_ST_REG      (SYSCTRL_BASE + 0xA018) /* ��Ӧcluster��L2����WFI����ģʽָʾ�� */
#define SYSCTRL_SC_CPU_L2FSHDONE_ST_REG         (SYSCTRL_BASE + 0xA01C) /* ��Ӧcluster��L2 hardware flush requestָʾ�� */
#define SYSCTRL_SC_SYSMODE_STATUS_REG           (SYSCTRL_BASE + 0xC000) /* SC_CTRLΪϵͳʱ�ӹ���״̬�Ĵ��� */
#define SYSCTRL_SC_PLL_LOCK_STATUS_REG          (SYSCTRL_BASE + 0xC004) /* PLL����״̬�Ĵ����� */
#define SYSCTRL_SC_PLLCTRL_ST_REG               (SYSCTRL_BASE + 0xC008) /* SC_PLLCTRL_STΪPLL״̬�Ĵ����� */
#define SYSCTRL_SC_REF_CLK_ST_REG               (SYSCTRL_BASE + 0xC00C) /* SC_REF_CLK_ST��ʾCDIE_CRG��ref_clk��ʱ��״̬�� */
#define SYSCTRL_SC_GPIO_CLK_ST_REG              (SYSCTRL_BASE + 0xC010) /* SC_GPIO_CLK_ST��ʾCDIE_CRG��gpio_db_clk��ʱ��״̬�� */
#define SYSCTRL_SC_CLUS0_CRG_CLK_ST_REG         (SYSCTRL_BASE + 0xC014) /* SC_CLUS0_CRG_CLK_ST��ʾ��ǰCLUSTER��CRG��ʱ��״̬�� */
#define SYSCTRL_SC_CLUS0_CRG_RESET_ST_REG       (SYSCTRL_BASE + 0xC018) /* SC_CLUS0_CRG_RESET_ST��ʾ��ǰCLUSTER��RESET��״̬�� */
#define SYSCTRL_SC_CLUS1_CRG_CLK_ST_REG         (SYSCTRL_BASE + 0xC01C) /* SC_CLUS1_CRG_CLK_ST��ʾ��ǰCLUSTER��CRG��ʱ��״̬�� */
#define SYSCTRL_SC_CLUS1_CRG_RESET_ST_REG       (SYSCTRL_BASE + 0xC020) /* SC_CLUS1_CRG_RESET_ST��ʾ��ǰCLUSTER��RESET��״̬�� */
#define SYSCTRL_SC_CLUS2_CRG_CLK_ST_REG         (SYSCTRL_BASE + 0xC024) /* SC_CLUS2_CRG_CLK_ST��ʾ��ǰCLUSTER��CRG��ʱ��״̬�� */
#define SYSCTRL_SC_CLUS2_CRG_RESET_ST_REG       (SYSCTRL_BASE + 0xC028) /* SC_CLUS2_CRG_RESET_ST��ʾ��ǰCLUSTER��RESET��״̬�� */
#define SYSCTRL_SC_CLUS3_CRG_CLK_ST_REG         (SYSCTRL_BASE + 0xC02C) /* SC_CLUS3_CRG_CLK_ST��ʾ��ǰCLUSTER��CRG��ʱ��״̬�� */
#define SYSCTRL_SC_CLUS3_CRG_RESET_ST_REG       (SYSCTRL_BASE + 0xC030) /* SC_CLUS3_CRG_RESET_ST��ʾ��ǰCLUSTER��RESET��״̬�� */
#define SYSCTRL_SC_LLC_CLK_ST_REG               (SYSCTRL_BASE + 0xC034) /* SC_LLC_CLK_STΪLLC��ʱ��״̬�Ĵ��� */
#define SYSCTRL_SC_LLC_RESET_ST_REG             (SYSCTRL_BASE + 0xC038) /* SC_LLC_RESET_STΪCDIE��LLC��λ״̬�Ĵ��� */
#define SYSCTRL_SC_DDRC_CLK_ST_REG              (SYSCTRL_BASE + 0xC03C) /* SC_DDRC_CLK_STΪDDRC��ʱ��״̬�Ĵ��� */
#define SYSCTRL_SC_DDRC_RESET_ST_REG            (SYSCTRL_BASE + 0xC040) /* SC_DDRC_RESET_STΪCDIE��DDRC��λ״̬�Ĵ��� */
#define SYSCTRL_SC_SLLC_CLK_ST_REG              (SYSCTRL_BASE + 0xC100) /* SC_SLLC_CLK_ST��ʾSLLC�ĵ�ǰʱ��״̬ */
#define SYSCTRL_SC_SLLC_RESET_ST_REG            (SYSCTRL_BASE + 0xC104) /* SC_SLLC_RESET_STAT��ʾSLLC�ĵ�ǰ��λ״̬ */
#define SYSCTRL_SC_SLLC_TSVRX_RESET_ST_REG      (SYSCTRL_BASE + 0xC108) /* SC_SLLC_TSVRX_RESET_STATΪSLLC TSVRXͨ����λ״̬�Ĵ��� */
#define SYSCTRL_SC_HPM_CLK_ST_REG               (SYSCTRL_BASE + 0xC110) /* SC_HPM_CLK_ST��ʾHPM��ǰʱ��״̬ */
#define SYSCTRL_SC_HPM_SRST_ST_REG              (SYSCTRL_BASE + 0xC114) /* SC_HPM_SRST_ST��ʾHPM��ǰ��λ״̬״̬ */
#define SYSCTRL_SC_DJTAG_CLK_ST_REG             (SYSCTRL_BASE + 0xC120) /* SC_DJTAG_CLK_ST��ʾDJTAG����߼�ʱ��״̬ */
#define SYSCTRL_SC_DJTAG_SRST_ST_REG            (SYSCTRL_BASE + 0xC124) /* SC_DJTAG_SRST_ST��ʾDJTAG����߼���λ״̬ */
#define SYSCTRL_SC_HHA_MN_CLK_ST_REG            (SYSCTRL_BASE + 0xC128) /* SC_HHA_MN_CLK_ST��ʾHHA��MN�߼�ʱ��״̬ */
#define SYSCTRL_SC_HHA_MN_SRST_ST_REG           (SYSCTRL_BASE + 0xC12C) /* SC_HHA_MN_SRST_ST��ʾHHA��MN�߼���λ״̬ */
#define SYSCTRL_SC_DDRC_WARM_RST_ACKED_REG      (SYSCTRL_BASE + 0xC160) /* SC_DDRC_WARM_RST_ACKED��ʾCRG��⵽���ϵ��ϵͳ��λ��warn_rst_req�����DDRC�����ź� */
#define SYSCTRL_SC_TSENSOR_SYSSTAT_REG          (SYSCTRL_BASE + 0xD000) /* tsensorϵͳ״̬�Ĵ����� */
#define SYSCTRL_SC_TSENSOR_TEMP_SAMPLE_REG      (SYSCTRL_BASE + 0xD004) /* оƬ�¶Ȳ���ֵ */
#define SYSCTRL_SC_MDDRC0_AC_IOCTL_IOTEST0_REG  (SYSCTRL_BASE + 0xD400)
#define SYSCTRL_SC_MDDRC0_AC_IOCTL_IOTEST1_REG  (SYSCTRL_BASE + 0xD404)
#define SYSCTRL_SC_MDDRC1_AC_IOCTL_IOTEST0_REG  (SYSCTRL_BASE + 0xD408)
#define SYSCTRL_SC_MDDRC1_AC_IOCTL_IOTEST1_REG  (SYSCTRL_BASE + 0xD40C)
#define SYSCTRL_SC_MDDRC0_DX_IOCTL_IOTEST0_REG  (SYSCTRL_BASE + 0xD410)
#define SYSCTRL_SC_MDDRC0_DX_IOCTL_IOTEST1_REG  (SYSCTRL_BASE + 0xD414)
#define SYSCTRL_SC_MDDRC0_DX_IOCTL_IOTEST2_REG  (SYSCTRL_BASE + 0xD418)
#define SYSCTRL_SC_MDDRC0_DX_IOCTL_IOTEST3_REG  (SYSCTRL_BASE + 0xD41C)
#define SYSCTRL_SC_MDDRC1_DX_IOCTL_IOTEST0_REG  (SYSCTRL_BASE + 0xD420)
#define SYSCTRL_SC_MDDRC1_DX_IOCTL_IOTEST1_REG  (SYSCTRL_BASE + 0xD424)
#define SYSCTRL_SC_MDDRC1_DX_IOCTL_IOTEST2_REG  (SYSCTRL_BASE + 0xD428)
#define SYSCTRL_SC_MDDRC1_DX_IOCTL_IOTEST3_REG  (SYSCTRL_BASE + 0xD42C)
#define SYSCTRL_SC_MBIST_CPUI_DATAOUT_REG       (SYSCTRL_BASE + 0xDC00) /* DFT MBISTģʽ�¶����ݼĴ��� */
#define SYSCTRL_SC_INT_STATUS_REG               (SYSCTRL_BASE + 0xE000) /* ϵͳ�������ж�״̬�Ĵ��� */
#define SYSCTRL_SC_DIE_ID0_REG                  (SYSCTRL_BASE + 0xE004) /* DIE ID �Ĵ���bit[31:0]�� */
#define SYSCTRL_SC_DIE_ID1_REG                  (SYSCTRL_BASE + 0xE008) /* DIE ID �Ĵ���bit[63:32]�� */
#define SYSCTRL_SC_DIE_ID2_REG                  (SYSCTRL_BASE + 0xE00C) /* DIE ID �Ĵ���bit[95:64]�� */
#define SYSCTRL_SC_DIE_ID3_REG                  (SYSCTRL_BASE + 0xE010) /* DIE ID �Ĵ���bit[127:96]�� */
#define SYSCTRL_SC_DIE_ID4_REG                  (SYSCTRL_BASE + 0xE014) /* DIE ID �Ĵ���bit[159:128]�� */
#define SYSCTRL_SC_DIE_ID5_REG                  (SYSCTRL_BASE + 0xE018) /* DIE ID �Ĵ���bit[191:160]�� */
#define SYSCTRL_SC_DIE_ID6_REG                  (SYSCTRL_BASE + 0xE01C) /* DIE ID �Ĵ���bit[223:192]�� */
#define SYSCTRL_SC_DIE_ID7_REG                  (SYSCTRL_BASE + 0xE020) /* DIE ID �Ĵ���bit[255:224]�� */
#define SYSCTRL_SC_DIE_ID8_REG                  (SYSCTRL_BASE + 0xE024) /* DIE ID �Ĵ���bit[287:256]�� */
#define SYSCTRL_SC_DIE_ID9_REG                  (SYSCTRL_BASE + 0xE028) /* DIE ID �Ĵ���bit[319:288]�� */
#define SYSCTRL_SC_DIE_ID10_REG                 (SYSCTRL_BASE + 0xE02C) /* DIE ID �Ĵ���bit[351:320]�� */
#define SYSCTRL_SC_DIE_ID11_REG                 (SYSCTRL_BASE + 0xE030) /* DIE ID �Ĵ���bit[383:352]�� */
#define SYSCTRL_SC_DIE_ID12_REG                 (SYSCTRL_BASE + 0xE034) /* DIE ID �Ĵ���bit[415:384]�� */
#define SYSCTRL_SC_DIE_ID13_REG                 (SYSCTRL_BASE + 0xE038) /* DIE ID �Ĵ���bit[447:416]�� */
#define SYSCTRL_SC_DIE_ID14_REG                 (SYSCTRL_BASE + 0xE03C) /* DIE ID �Ĵ���bit[479:448]�� */
#define SYSCTRL_SC_DIE_ID15_REG                 (SYSCTRL_BASE + 0xE040) /* DIE ID �Ĵ���bit[511:480]�� */
#define SYSCTRL_SC_DIE_ID16_REG                 (SYSCTRL_BASE + 0xE044) /* DIE ID �Ĵ���bit[543:512]�� */
#define SYSCTRL_SC_DIE_ID17_REG                 (SYSCTRL_BASE + 0xE048) /* DIE ID �Ĵ���bit[575:544]�� */
#define SYSCTRL_SC_DIE_ID18_REG                 (SYSCTRL_BASE + 0xE04C) /* DIE ID �Ĵ���bit[607:576]�� */
#define SYSCTRL_SC_DIE_ID19_REG                 (SYSCTRL_BASE + 0xE050) /* DIE ID �Ĵ���bit[639:608]�� */
#define SYSCTRL_SC_SOCKET_ID_REG                (SYSCTRL_BASE + 0xE080) /* SC_SOCKET_ID��ʾsocket�Ĺܽ�ָʾ�ź� */
#define SYSCTRL_SC_BOOT_CTRL_ST_REG             (SYSCTRL_BASE + 0xE084) /* SC_BOOT_CTRL_ST��ʾCPU�������Ƶ�PAD��eFuse�ź�״̬ */
#define SYSCTRL_SC_BOOT_CTRL_CFG_ST_REG         (SYSCTRL_BASE + 0xE088) /* SC_BOOT_CTRL_CFG_ST��ʾCPU���������źž������ú�����״̬ */
#define SYSCTRL_SC_LAST_RST_STATUS_REG          (SYSCTRL_BASE + 0xE090) /* SC_LAST_RST_STATUS��ʾоƬ���һ�θ�λ�ĸ�λ״̬ */
#define SYSCTRL_SC_XTAL_ST_REG                  (SYSCTRL_BASE + 0xE100)
#define SYSCTRL_SC_CNT_ST_REG                   (SYSCTRL_BASE + 0xE104)
#define SYSCTRL_SC_ITIR0_TEST_REG               (SYSCTRL_BASE + 0xE108)
#define SYSCTRL_SC_ITOR_TEST_REG                (SYSCTRL_BASE + 0xE10C)
#define SYSCTRL_SC_CNT_DATA_REG                 (SYSCTRL_BASE + 0xE110)
#define SYSCTRL_SC_CNT_STEP_RSV_REG             (SYSCTRL_BASE + 0xE114)
#define SYSCTRL_SC_AXI_ACC_ST_REG               (SYSCTRL_BASE + 0xE200)
#define SYSCTRL_SC_SYSCNT_SYNC_OFFSET_REG       (SYSCTRL_BASE + 0xE204) /* System Counterͬ������ͳ�Ƶ�·���ӳټĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA0_REG           (SYSCTRL_BASE + 0xE800) /* DJTAGɨ�����ϵ�һ��ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA1_REG           (SYSCTRL_BASE + 0xE804) /* DJTAGɨ�����ϵڶ���ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA2_REG           (SYSCTRL_BASE + 0xE808) /* DJTAGɨ�����ϵ�����ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA3_REG           (SYSCTRL_BASE + 0xE80C) /* DJTAGɨ�����ϵ��ĸ�ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA4_REG           (SYSCTRL_BASE + 0xE810) /* DJTAGɨ�����ϵ����ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA5_REG           (SYSCTRL_BASE + 0xE814) /* DJTAGɨ�����ϵ�����ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA6_REG           (SYSCTRL_BASE + 0xE818) /* DJTAGɨ�����ϵ��߸�ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA7_REG           (SYSCTRL_BASE + 0xE81C) /* DJTAGɨ�����ϵڰ˸�ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA8_REG           (SYSCTRL_BASE + 0xE820) /* DJTAGɨ�����ϵھŸ�ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_RD_DATA9_REG           (SYSCTRL_BASE + 0xE824) /* DJTAGɨ�����ϵ�ʮ��ģ������ݼĴ��� */
#define SYSCTRL_SC_DJTAG_OP_ST_REG              (SYSCTRL_BASE + 0xE828) /* DJTAG����״̬�Ĵ��� */
#define SYSCTRL_SC_TDRE_RDATA1_REG              (SYSCTRL_BASE + 0xE82C) /* DJTAG����TDREģ��Ķ����ݸ�32bit */
#define SYSCTRL_SC_TDRE_RDATA0_REG              (SYSCTRL_BASE + 0xE830) /* DJTAG����TDREģ��Ķ����ݵ�32bit */
#define SYSCTRL_SC_AXI_RD_DATA3_REG             (SYSCTRL_BASE + 0xE840) /* AXI����DDR�Ķ����ݼĴ��� */
#define SYSCTRL_SC_AXI_RD_DATA2_REG             (SYSCTRL_BASE + 0xE844) /* AXI����DDR�Ķ����ݼĴ��� */
#define SYSCTRL_SC_AXI_RD_DATA1_REG             (SYSCTRL_BASE + 0xE848) /* AXI����DDR�Ķ����ݼĴ��� */
#define SYSCTRL_SC_AXI_RD_DATA0_REG             (SYSCTRL_BASE + 0xE84C) /* AXI����DDR�Ķ����ݼĴ��� */
#define SYSCTRL_SC_AXI_MSTR_ST_REG              (SYSCTRL_BASE + 0xE850) /* AXI����DDR����״̬�Ĵ��� */
#define SYSCTRL_SC_BOARD_CFG_INFO_REG           (SYSCTRL_BASE + 0xF000) /* ����������Ϣ״̬�Ĵ��� */


/******************************************************************************/
/*                      PHOSPHOR POE_SUB Registers' Definitions                            */
/******************************************************************************/

#define POE_SUB_SC_SRAM_CLK_EN_REG            (POE_SUB_BASE + 0x340)  /* SRAMʱ��ʹ�ܼĴ��� */
#define POE_SUB_SC_SRAM_CLK_DIS_REG           (POE_SUB_BASE + 0x344)  /* SRAMʱ�ӽ�ֹ�Ĵ��� */
#define POE_SUB_SC_POE_CLK_EN_REG             (POE_SUB_BASE + 0x500)  /* POEʱ��ʹ�ܼĴ��� */
#define POE_SUB_SC_POE_CLK_DIS_REG            (POE_SUB_BASE + 0x504)  /* POEʱ�ӽ�ֹ�Ĵ��� */
#define POE_SUB_SC_SRAM_RESET_REQ_REG         (POE_SUB_BASE + 0xA40)  /* SRAM��λ������ƼĴ��� */
#define POE_SUB_SC_SRAM_RESET_DREQ_REG        (POE_SUB_BASE + 0xA44)  /* SRAM��λȥ������ƼĴ��� */
#define POE_SUB_SC_POE_RESET_REQ_REG          (POE_SUB_BASE + 0xB18)  /* poe��λ������ƼĴ��� */
#define POE_SUB_SC_POE_RESET_DREQ_REG         (POE_SUB_BASE + 0xB1C)  /* poe��λȥ������ƼĴ��� */
#define POE_SUB_SC_DISPATCH_DAW_EN_REG        (POE_SUB_BASE + 0x1000) /* dispatch daw en���� */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY0_REG    (POE_SUB_BASE + 0x1004) /* dispatch daw��������0 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY1_REG    (POE_SUB_BASE + 0x1008) /* dispatch daw��������1 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY2_REG    (POE_SUB_BASE + 0x100C) /* dispatch daw��������2 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY3_REG    (POE_SUB_BASE + 0x1010) /* dispatch daw��������3 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY4_REG    (POE_SUB_BASE + 0x1014) /* dispatch daw��������4 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY5_REG    (POE_SUB_BASE + 0x1018) /* dispatch daw��������5 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY6_REG    (POE_SUB_BASE + 0x101C) /* dispatch daw��������6 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY7_REG    (POE_SUB_BASE + 0x1020) /* dispatch daw��������7 */
#define POE_SUB_SC_DISPATCH_RETRY_CONTROL_REG (POE_SUB_BASE + 0x1030) /* dispatch retry���ƼĴ��� */
#define POE_SUB_SC_DISPATCH_INTMASK_REG       (POE_SUB_BASE + 0x1100) /* dispatch���ж����μĴ��� */
#define POE_SUB_SC_DISPATCH_RAWINT_REG        (POE_SUB_BASE + 0x1104) /* dispatch��ԭʼ�ж�״̬�Ĵ��� */
#define POE_SUB_SC_DISPATCH_INTSTAT_REG       (POE_SUB_BASE + 0x1108) /* dispatch�����κ���ж�״̬�Ĵ��� */
#define POE_SUB_SC_DISPATCH_INTCLR_REG        (POE_SUB_BASE + 0x110C) /* dispatch���ж�����Ĵ��� */
#define POE_SUB_SC_DISPATCH_ERRSTAT_REG       (POE_SUB_BASE + 0x1110) /* dispatch��ERR״̬�Ĵ��� */
#define POE_SUB_SC_DISPATCH_REMAP_CTRL_REG    (POE_SUB_BASE + 0x1200) /* subsys������Remap�Ĵ��� */
#define POE_SUB_SC_SRAM_CTRL0_REG             (POE_SUB_BASE + 0x2030) /* sram���ƼĴ���0 */
#define POE_SUB_SC_SRAM_CTRL1_REG             (POE_SUB_BASE + 0x2034) /* sram���ƼĴ���1����ȫ�Ĵ����� */
#define POE_SUB_SC_SRAM_CTRL2_REG             (POE_SUB_BASE + 0x2038) /* sram���ƼĴ���2����ȫ�Ĵ����� */
#define POE_SUB_SC_SRAM_CTRL3_REG             (POE_SUB_BASE + 0x203C) /* sram���ƼĴ���3����ȫ�Ĵ����� */
#define POE_SUB_SC_SMMU_MEM_CTRL1_REG         (POE_SUB_BASE + 0x3004) /* smmu mem���ƼĴ���1 */
#define POE_SUB_SC_SMMU_MEM_CTRL2_REG         (POE_SUB_BASE + 0x3008) /* smmu mem���ƼĴ���2 */
#define POE_SUB_SC_SRAM_MEM_CTRL_REG          (POE_SUB_BASE + 0x3010) /* sram mem���ƼĴ��� */
#define POE_SUB_SC_PLLFCTRL0_REG              (POE_SUB_BASE + 0x3014) /* SC_PLLFCTRL0ΪCIDE_CRG��PLL0���ƼĴ���0�� */
#define POE_SUB_SC_PLLFCTRL1_REG              (POE_SUB_BASE + 0x3018) /* SC_PLLFCTRL1ΪCIDE_CRG��PLL0���ƼĴ���1�� */
#define POE_SUB_SC_PLLFCTRL8_REG              (POE_SUB_BASE + 0x3034) /* SC_PLLFCTRL8ΪCIDE_CRG��PLL4���ƼĴ���0�� */
#define POE_SUB_SC_PLLFCTRL9_REG              (POE_SUB_BASE + 0x3038) /* SC_PLLFCTRL9ΪCIDE_CRG��PLL4���ƼĴ���1�� */
#define POE_SUB_SC_PLL_CLK_BYPASS0_REG        (POE_SUB_BASE + 0x3040) /* SC_PLL_CLK_BYPASS0ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
#define POE_SUB_SC_PLL_CLK_BYPASS1_REG        (POE_SUB_BASE + 0x3044) /* SC_PLL_CLK_BYPASS1ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
#define POE_SUB_SC_CLK_SEL_REG                (POE_SUB_BASE + 0x3048) /* SC_CLK_SEL��CDIE_CRG�Ĵ�������ϵͳ����ʱ��Ƶ��ѡ��Ĵ����� */
#define POE_SUB_SC_TSMC_PLLCTRL1_REG          (POE_SUB_BASE + 0x3204) /* SC_TSMC_PLLCTRL1ΪCIDE��PLL1��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
#define POE_SUB_SC_TSMC_PLLCTRL4_REG          (POE_SUB_BASE + 0x3210) /* SC_TSMC_PLLCTRL4ΪCIDE CRG��PLL4��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
#define POE_SUB_SC_PLL_SEL_REG                (POE_SUB_BASE + 0x3214) /* SC_PLL_SELΪCIDE�ڵ�PLLѡ����ƼĴ����� */
#define POE_SUB_SC_SRAM_CLK_ST_REG            (POE_SUB_BASE + 0x5320) /* SRAMʱ��״̬�Ĵ��� */
#define POE_SUB_SC_POE_CLK_ST_REG             (POE_SUB_BASE + 0x5400) /* POEʱ��״̬�Ĵ��� */
#define POE_SUB_SC_SRAM_RESET_ST_REG          (POE_SUB_BASE + 0x5A20) /* SRAM��λ״̬�Ĵ��� */
#define POE_SUB_SC_POE_RESET_ST_REG           (POE_SUB_BASE + 0x5B00) /* poe��λ״̬�Ĵ��� */
#define POE_SUB_SC_SRAM_ST0_REG               (POE_SUB_BASE + 0x6000) /* sram״̬�Ĵ���0 */
#define POE_SUB_SC_SRAM_ST1_REG               (POE_SUB_BASE + 0x6004) /* sram״̬�Ĵ���1 */
#define POE_SUB_SC_SRAM_ST2_REG               (POE_SUB_BASE + 0x6008) /* sram״̬�Ĵ���2 */
#define POE_SUB_SC_SRAM_ST3_REG               (POE_SUB_BASE + 0x600C) /* sram״̬�Ĵ���3 */
#define POE_SUB_SC_SRAM_ST4_REG               (POE_SUB_BASE + 0x6010) /* sram״̬�Ĵ���4 */
#define POE_SUB_SC_SRAM_ST5_REG               (POE_SUB_BASE + 0x6014) /* sram״̬�Ĵ���5 */
#define POE_SUB_SC_ECO_RSV0_REG               (POE_SUB_BASE + 0x8000) /* ECO �Ĵ���0 */
#define POE_SUB_SC_ECO_RSV1_REG               (POE_SUB_BASE + 0x8004) /* ECO �Ĵ���1 */
#define POE_SUB_SC_ECO_RSV2_REG               (POE_SUB_BASE + 0x8008) /* ECO �Ĵ���2 */





/* Define the union U_SC_CPU_EDBGRQ_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    edbgrq_cluster0       : 4   ; /* [3..0]  */
        unsigned int    edbgrq_cluster1       : 4   ; /* [7..4]  */
        unsigned int    edbgrq_cluster2       : 4   ; /* [11..8]  */
        unsigned int    edbgrq_cluster3       : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_EDBGRQ_CTRL;

/* Define the union U_SC_CPU_CP15SDIS_CRTL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cp15sdisable_cluster0 : 4   ; /* [3..0]  */
        unsigned int    cp15sdisable_cluster1 : 4   ; /* [7..4]  */
        unsigned int    cp15sdisable_cluster2 : 4   ; /* [11..8]  */
        unsigned int    cp15sdisable_cluster3 : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_CP15SDIS_CRTL;

/* Define the union U_SC_CPU_PMU_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pmusnapshotreq_cluster0 : 4   ; /* [3..0]  */
        unsigned int    pmusnapshotreq_cluster1 : 4   ; /* [7..4]  */
        unsigned int    pmusnapshotreq_cluster2 : 4   ; /* [11..8]  */
        unsigned int    pmusnapshotreq_cluster3 : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_PMU_CTRL;

/* Define the union U_SC_CLUS_L2_CLKEN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_clken        : 1   ; /* [0]  */
        unsigned int    cluster1_clken        : 1   ; /* [1]  */
        unsigned int    cluster2_clken        : 1   ; /* [2]  */
        unsigned int    cluster3_clken        : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS_L2_CLKEN;

/* Define the union U_SC_CPU_GICDIS_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    giccdisable_cluster0  : 1   ; /* [0]  */
        unsigned int    giccdisable_cluster1  : 1   ; /* [1]  */
        unsigned int    giccdisable_cluster2  : 1   ; /* [2]  */
        unsigned int    giccdisable_cluster3  : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_GICDIS_CTRL;

/* Define the union U_SC_CPU_CLKEN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cpu0_cluster0_clken   : 1   ; /* [0]  */
        unsigned int    cpu1_cluster0_clken   : 1   ; /* [1]  */
        unsigned int    cpu2_cluster0_clken   : 1   ; /* [2]  */
        unsigned int    cpu3_cluster0_clken   : 1   ; /* [3]  */
        unsigned int    cpu0_cluster1_clken   : 1   ; /* [4]  */
        unsigned int    cpu1_cluster1_clken   : 1   ; /* [5]  */
        unsigned int    cpu2_cluster1_clken   : 1   ; /* [6]  */
        unsigned int    cpu3_cluster1_clken   : 1   ; /* [7]  */
        unsigned int    cpu0_cluster2_clken   : 1   ; /* [8]  */
        unsigned int    cpu1_cluster2_clken   : 1   ; /* [9]  */
        unsigned int    cpu2_cluster2_clken   : 1   ; /* [10]  */
        unsigned int    cpu3_cluster2_clken   : 1   ; /* [11]  */
        unsigned int    cpu0_cluster3_clken   : 1   ; /* [12]  */
        unsigned int    cpu1_cluster3_clken   : 1   ; /* [13]  */
        unsigned int    cpu2_cluster3_clken   : 1   ; /* [14]  */
        unsigned int    cpu3_cluster3_clken   : 1   ; /* [15]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_CLKEN;

/* Define the union U_SC_CPU_L2FSHREQ_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    l2flushreq_cluster0   : 1   ; /* [0]  */
        unsigned int    l2flushreq_cluster1   : 1   ; /* [1]  */
        unsigned int    l2flushreq_cluster2   : 1   ; /* [2]  */
        unsigned int    l2flushreq_cluster3   : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_L2FSHREQ_CTRL;

/* Define the union U_SC_CPU_CLREXMONREQ_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clrexmonreq_cluster0  : 1   ; /* [0]  */
        unsigned int    clrexmonreq_cluster1  : 1   ; /* [1]  */
        unsigned int    clrexmonreq_cluster2  : 1   ; /* [2]  */
        unsigned int    clrexmonreq_cluster3  : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_CLREXMONREQ_CTRL;

/* Define the union U_SC_CPU_SYSBROADCAST_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sysbardisable_cluster0 : 1   ; /* [0]  */
        unsigned int    broadcastinner_cluster0 : 1   ; /* [1]  */
        unsigned int    broadcastouter_cluster0 : 1   ; /* [2]  */
        unsigned int    broadcastcachemaint_cluster0 : 1   ; /* [3]  */
        unsigned int    sysbardisable_cluster1 : 1   ; /* [4]  */
        unsigned int    broadcastinner_cluster1 : 1   ; /* [5]  */
        unsigned int    broadcastouter_cluster1 : 1   ; /* [6]  */
        unsigned int    broadcastcachemaint_cluster1 : 1   ; /* [7]  */
        unsigned int    sysbardisable_cluster2 : 1   ; /* [8]  */
        unsigned int    broadcastinner_cluster2 : 1   ; /* [9]  */
        unsigned int    broadcastouter_cluster2 : 1   ; /* [10]  */
        unsigned int    broadcastcachemaint_cluster2 : 1   ; /* [11]  */
        unsigned int    sysbardisable_cluster3 : 1   ; /* [12]  */
        unsigned int    broadcastinner_cluster3 : 1   ; /* [13]  */
        unsigned int    broadcastouter_cluster3 : 1   ; /* [14]  */
        unsigned int    broadcastcachemaint_cluster3 : 1   ; /* [15]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_SYSBROADCAST_CTRL;

/* Define the union U_SC_CPU_SINACT_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sinact_cluster0       : 1   ; /* [0]  */
        unsigned int    sinact_cluster1       : 1   ; /* [1]  */
        unsigned int    sinact_cluster2       : 1   ; /* [2]  */
        unsigned int    sinact_cluster3       : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_SINACT_CTRL;

/* Define the union U_SC_CLUS0_CTRL_RVBA0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr0_cluster0   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CTRL_RVBA0;

/* Define the union U_SC_CLUS0_CTRL_RVBA1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr1_cluster0   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CTRL_RVBA1;

/* Define the union U_SC_CLUS0_CTRL_RVBA2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr2_cluster0   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CTRL_RVBA2;

/* Define the union U_SC_CLUS0_CTRL_RVBA3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr3_cluster0   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CTRL_RVBA3;

/* Define the union U_SC_CLUS1_CTRL_RVBA0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr0_cluster1   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CTRL_RVBA0;

/* Define the union U_SC_CLUS1_CTRL_RVBA1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr1_cluster1   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CTRL_RVBA1;

/* Define the union U_SC_CLUS1_CTRL_RVBA2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr2_cluster1   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CTRL_RVBA2;

/* Define the union U_SC_CLUS1_CTRL_RVBA3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr3_cluster1   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CTRL_RVBA3;

/* Define the union U_SC_CLUS2_CTRL_RVBA0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr0_cluster2   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CTRL_RVBA0;

/* Define the union U_SC_CLUS2_CTRL_RVBA1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr1_cluster2   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CTRL_RVBA1;

/* Define the union U_SC_CLUS2_CTRL_RVBA2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr2_cluster2   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CTRL_RVBA2;

/* Define the union U_SC_CLUS2_CTRL_RVBA3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr3_cluster2   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CTRL_RVBA3;

/* Define the union U_SC_CLUS3_CTRL_RVBA0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr0_cluster3   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CTRL_RVBA0;

/* Define the union U_SC_CLUS3_CTRL_RVBA1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr1_cluster3   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CTRL_RVBA1;

/* Define the union U_SC_CLUS3_CTRL_RVBA2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr2_cluster3   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CTRL_RVBA2;

/* Define the union U_SC_CLUS3_CTRL_RVBA3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rvbaraddr3_cluster3   : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CTRL_RVBA3;

/* Define the union U_SC_PERIPHBASE */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    periph_base           : 26  ; /* [25..0]  */
        unsigned int    reserved_0            : 6   ; /* [31..26]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PERIPHBASE;

/* Define the union U_SC_DBG_AUTH_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cpu_dbgen             : 1   ; /* [0]  */
        unsigned int    cpu_niden             : 1   ; /* [1]  */
        unsigned int    cpu_spiden            : 1   ; /* [2]  */
        unsigned int    cpu_spniden           : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DBG_AUTH_CTRL;

/* Define the union U_SC_CLUS_CRYPTODISABLE */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_cryptodisable : 4   ; /* [3..0]  */
        unsigned int    cluster1_cryptodisable : 4   ; /* [7..4]  */
        unsigned int    cluster2_cryptodisable : 4   ; /* [11..8]  */
        unsigned int    cluster3_cryptodisable : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS_CRYPTODISABLE;

/* Define the union U_SC_CORE0_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core0_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE0_EVENT_EN;

/* Define the union U_SC_CORE1_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core1_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE1_EVENT_EN;

/* Define the union U_SC_CORE2_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core2_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE2_EVENT_EN;

/* Define the union U_SC_CORE3_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core3_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE3_EVENT_EN;

/* Define the union U_SC_CORE4_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core4_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE4_EVENT_EN;

/* Define the union U_SC_CORE5_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core5_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE5_EVENT_EN;

/* Define the union U_SC_CORE6_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core6_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE6_EVENT_EN;

/* Define the union U_SC_CORE7_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core7_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE7_EVENT_EN;

/* Define the union U_SC_CORE8_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core8_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE8_EVENT_EN;

/* Define the union U_SC_CORE9_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core9_event_en        : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE9_EVENT_EN;

/* Define the union U_SC_CORE10_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core10_event_en       : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE10_EVENT_EN;

/* Define the union U_SC_CORE11_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core11_event_en       : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE11_EVENT_EN;

/* Define the union U_SC_CORE12_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core12_event_en       : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE12_EVENT_EN;

/* Define the union U_SC_CORE13_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core13_event_en       : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE13_EVENT_EN;

/* Define the union U_SC_CORE14_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core14_event_en       : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE14_EVENT_EN;

/* Define the union U_SC_CORE15_EVENT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    core15_event_en       : 17  ; /* [16..0]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CORE15_EVENT_EN;

/* Define the union U_SC_CPU_DBGL1RSTDISABLE_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    dbgl1rstdisable_cluster0 : 1   ; /* [0]  */
        unsigned int    dbgl1rstdisable_cluster1 : 1   ; /* [1]  */
        unsigned int    dbgl1rstdisable_cluster2 : 1   ; /* [2]  */
        unsigned int    dbgl1rstdisable_cluster3 : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_DBGL1RSTDISABLE_CTRL;

/* Define the union U_SC_SYSMODE_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    modectrl              : 3   ; /* [2..0]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSMODE_CTRL;

/* Define the union U_SC_PLLCTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll_over              : 1   ; /* [0]  */
        unsigned int    pll_en_sw             : 1   ; /* [1]  */
        unsigned int    reserved_0            : 1   ; /* [2]  */
        unsigned int    pll_time              : 25  ; /* [27..3]  */
        unsigned int    reserved_1            : 4   ; /* [31..28]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLCTRL;

/* Define the union U_SC_PLLFCTRL4 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll2_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll2_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll2_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll2_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll2_bypass           : 1   ; /* [24]  */
        unsigned int    pll2_pd               : 1   ; /* [25]  */
        unsigned int    pll2_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll2_dacpd            : 1   ; /* [27]  */
        unsigned int    pll2_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll2_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll2_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL4;

/* Define the union U_SC_PLLFCTRL5 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll2_frac             : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL5;

/* Define the union U_SC_PLLFCTRL6 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll3_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll3_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll3_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll3_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll3_bypass           : 1   ; /* [24]  */
        unsigned int    pll3_pd               : 1   ; /* [25]  */
        unsigned int    pll3_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll3_dacpd            : 1   ; /* [27]  */
        unsigned int    pll3_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll3_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll3_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL6;

/* Define the union U_SC_PLLFCTRL7 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll3_frac             : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL7;

/* Define the union U_SC_PLL_CLK_BYPASS_DDR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 1   ; /* [0]  */
        unsigned int    reserved_1            : 1   ; /* [1]  */
        unsigned int    pll2_bypass_external_n : 1   ; /* [2]  */
        unsigned int    pll3_bypass_external_n : 1   ; /* [3]  */
        unsigned int    reserved_2            : 13  ; /* [16..4]  */
        unsigned int    pll2_peri_mode        : 1   ; /* [17]  */
        unsigned int    pll3_peri_mode        : 1   ; /* [18]  */
        unsigned int    reserved_3            : 1   ; /* [19]  */
        unsigned int    reserved_4            : 12  ; /* [31..20]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS_DDR;

/* Define the union U_SC_REF_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ref_clken             : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_REF_CLK_EN;

/* Define the union U_SC_REF_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ref_clk_dis           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_REF_CLK_DIS;

/* Define the union U_SC_GPIO_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    gpio_db_clken         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_GPIO_CLK_EN;

/* Define the union U_SC_GPIO_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    gpio_db_clk_dis       : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_GPIO_CLK_DIS;

/* Define the union U_SC_CLUS0_CRG_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_dbg_clken    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CRG_CLK_EN;

/* Define the union U_SC_CLUS0_CRG_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_dbg_clk_dis  : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CRG_CLK_DIS;

/* Define the union U_SC_CLUS0_CRG_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_l2_srst_req  : 1   ; /* [0]  */
        unsigned int    cluster0_cpu0_por_srst_req : 1   ; /* [1]  */
        unsigned int    cluster0_cpu1_por_srst_req : 1   ; /* [2]  */
        unsigned int    cluster0_cpu2_por_srst_req : 1   ; /* [3]  */
        unsigned int    cluster0_cpu3_por_srst_req : 1   ; /* [4]  */
        unsigned int    cluster0_cpu0_srst_req : 1   ; /* [5]  */
        unsigned int    cluster0_cpu1_srst_req : 1   ; /* [6]  */
        unsigned int    cluster0_cpu2_srst_req : 1   ; /* [7]  */
        unsigned int    cluster0_cpu3_srst_req : 1   ; /* [8]  */
        unsigned int    cluster0_dbg_srst_req : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CRG_RESET_REQ;

/* Define the union U_SC_CLUS0_CRG_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_l2_srst_dreq : 1   ; /* [0]  */
        unsigned int    cluster0_cpu0_por_srst_dreq : 1   ; /* [1]  */
        unsigned int    cluster0_cpu1_por_srst_dreq : 1   ; /* [2]  */
        unsigned int    cluster0_cpu2_por_srst_dreq : 1   ; /* [3]  */
        unsigned int    cluster0_cpu3_por_srst_dreq : 1   ; /* [4]  */
        unsigned int    cluster0_cpu0_srst_dreq : 1   ; /* [5]  */
        unsigned int    cluster0_cpu1_srst_dreq : 1   ; /* [6]  */
        unsigned int    cluster0_cpu2_srst_dreq : 1   ; /* [7]  */
        unsigned int    cluster0_cpu3_srst_dreq : 1   ; /* [8]  */
        unsigned int    cluster0_dbg_srst_dreq : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CRG_RESET_DREQ;

/* Define the union U_SC_CLUS1_CRG_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster1_dbg_clken    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CRG_CLK_EN;

/* Define the union U_SC_CLUS1_CRG_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster1_dbg_clk_dis  : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CRG_CLK_DIS;

/* Define the union U_SC_CLUS1_CRG_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster1_l2_srst_req  : 1   ; /* [0]  */
        unsigned int    cluster1_cpu0_por_srst_req : 1   ; /* [1]  */
        unsigned int    cluster1_cpu1_por_srst_req : 1   ; /* [2]  */
        unsigned int    cluster1_cpu2_por_srst_req : 1   ; /* [3]  */
        unsigned int    cluster1_cpu3_por_srst_req : 1   ; /* [4]  */
        unsigned int    cluster1_cpu0_srst_req : 1   ; /* [5]  */
        unsigned int    cluster1_cpu1_srst_req : 1   ; /* [6]  */
        unsigned int    cluster1_cpu2_srst_req : 1   ; /* [7]  */
        unsigned int    cluster1_cpu3_srst_req : 1   ; /* [8]  */
        unsigned int    cluster1_dbg_srst_req : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CRG_RESET_REQ;

/* Define the union U_SC_CLUS1_CRG_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster1_l2_srst_dreq : 1   ; /* [0]  */
        unsigned int    cluster1_cpu0_por_srst_dreq : 1   ; /* [1]  */
        unsigned int    cluster1_cpu1_por_srst_dreq : 1   ; /* [2]  */
        unsigned int    cluster1_cpu2_por_srst_dreq : 1   ; /* [3]  */
        unsigned int    cluster1_cpu3_por_srst_dreq : 1   ; /* [4]  */
        unsigned int    cluster1_cpu0_srst_dreq : 1   ; /* [5]  */
        unsigned int    cluster1_cpu1_srst_dreq : 1   ; /* [6]  */
        unsigned int    cluster1_cpu2_srst_dreq : 1   ; /* [7]  */
        unsigned int    cluster1_cpu3_srst_dreq : 1   ; /* [8]  */
        unsigned int    cluster1_dbg_srst_dreq : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CRG_RESET_DREQ;

/* Define the union U_SC_CLUS2_CRG_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster2_dbg_clken    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CRG_CLK_EN;

/* Define the union U_SC_CLUS2_CRG_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster2_dbg_clk_dis  : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CRG_CLK_DIS;

/* Define the union U_SC_CLUS2_CRG_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster2_l2_srst_req  : 1   ; /* [0]  */
        unsigned int    cluster2_cpu0_por_srst_req : 1   ; /* [1]  */
        unsigned int    cluster2_cpu1_por_srst_req : 1   ; /* [2]  */
        unsigned int    cluster2_cpu2_por_srst_req : 1   ; /* [3]  */
        unsigned int    cluster2_cpu3_por_srst_req : 1   ; /* [4]  */
        unsigned int    cluster2_cpu0_srst_req : 1   ; /* [5]  */
        unsigned int    cluster2_cpu1_srst_req : 1   ; /* [6]  */
        unsigned int    cluster2_cpu2_srst_req : 1   ; /* [7]  */
        unsigned int    cluster2_cpu3_srst_req : 1   ; /* [8]  */
        unsigned int    cluster2_dbg_srst_req : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CRG_RESET_REQ;

/* Define the union U_SC_CLUS2_CRG_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster2_l2_srst_dreq : 1   ; /* [0]  */
        unsigned int    cluster2_cpu0_por_srst_dreq : 1   ; /* [1]  */
        unsigned int    cluster2_cpu1_por_srst_dreq : 1   ; /* [2]  */
        unsigned int    cluster2_cpu2_por_srst_dreq : 1   ; /* [3]  */
        unsigned int    cluster2_cpu3_por_srst_dreq : 1   ; /* [4]  */
        unsigned int    cluster2_cpu0_srst_dreq : 1   ; /* [5]  */
        unsigned int    cluster2_cpu1_srst_dreq : 1   ; /* [6]  */
        unsigned int    cluster2_cpu2_srst_dreq : 1   ; /* [7]  */
        unsigned int    cluster2_cpu3_srst_dreq : 1   ; /* [8]  */
        unsigned int    cluster2_dbg_srst_dreq : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CRG_RESET_DREQ;

/* Define the union U_SC_CLUS3_CRG_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster3_dbg_clken    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CRG_CLK_EN;

/* Define the union U_SC_CLUS3_CRG_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster3_dbg_clk_dis  : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CRG_CLK_DIS;

/* Define the union U_SC_CLUS3_CRG_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster3_l2_srst_req  : 1   ; /* [0]  */
        unsigned int    cluster3_cpu0_por_srst_req : 1   ; /* [1]  */
        unsigned int    cluster3_cpu1_por_srst_req : 1   ; /* [2]  */
        unsigned int    cluster3_cpu2_por_srst_req : 1   ; /* [3]  */
        unsigned int    cluster3_cpu3_por_srst_req : 1   ; /* [4]  */
        unsigned int    cluster3_cpu0_srst_req : 1   ; /* [5]  */
        unsigned int    cluster3_cpu1_srst_req : 1   ; /* [6]  */
        unsigned int    cluster3_cpu2_srst_req : 1   ; /* [7]  */
        unsigned int    cluster3_cpu3_srst_req : 1   ; /* [8]  */
        unsigned int    cluster3_dbg_srst_req : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CRG_RESET_REQ;

/* Define the union U_SC_CLUS3_CRG_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster3_l2_srst_dreq : 1   ; /* [0]  */
        unsigned int    cluster3_cpu0_por_srst_dreq : 1   ; /* [1]  */
        unsigned int    cluster3_cpu1_por_srst_dreq : 1   ; /* [2]  */
        unsigned int    cluster3_cpu2_por_srst_dreq : 1   ; /* [3]  */
        unsigned int    cluster3_cpu3_por_srst_dreq : 1   ; /* [4]  */
        unsigned int    cluster3_cpu0_srst_dreq : 1   ; /* [5]  */
        unsigned int    cluster3_cpu1_srst_dreq : 1   ; /* [6]  */
        unsigned int    cluster3_cpu2_srst_dreq : 1   ; /* [7]  */
        unsigned int    cluster3_cpu3_srst_dreq : 1   ; /* [8]  */
        unsigned int    cluster3_dbg_srst_dreq : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CRG_RESET_DREQ;

/* Define the union U_SC_LLC_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    llc0_clken            : 1   ; /* [0]  */
        unsigned int    llc1_clken            : 1   ; /* [1]  */
        unsigned int    llc2_clken            : 1   ; /* [2]  */
        unsigned int    llc3_clken            : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LLC_CLK_EN;

/* Define the union U_SC_LLC_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    llc0_clk_dis          : 1   ; /* [0]  */
        unsigned int    llc1_clk_dis          : 1   ; /* [1]  */
        unsigned int    llc2_clk_dis          : 1   ; /* [2]  */
        unsigned int    llc3_clk_dis          : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LLC_CLK_DIS;

/* Define the union U_SC_LLC_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    llc0_srst_req         : 1   ; /* [0]  */
        unsigned int    llc1_srst_req         : 1   ; /* [1]  */
        unsigned int    llc2_srst_req         : 1   ; /* [2]  */
        unsigned int    llc3_srst_req         : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LLC_RESET_REQ;

/* Define the union U_SC_LLC_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    llc0_srst_dreq        : 1   ; /* [0]  */
        unsigned int    llc1_srst_dreq        : 1   ; /* [1]  */
        unsigned int    llc2_srst_dreq        : 1   ; /* [2]  */
        unsigned int    llc3_srst_dreq        : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LLC_RESET_DREQ;

/* Define the union U_SC_DDRC_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_clken           : 1   ; /* [0]  */
        unsigned int    ddrc1_clken           : 1   ; /* [1]  */
        unsigned int    ddrphy0_bypass_clken  : 1   ; /* [2]  */
        unsigned int    ddrphy1_bypass_clken  : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_CLK_EN;

/* Define the union U_SC_DDRC_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_clk_dis         : 1   ; /* [0]  */
        unsigned int    ddrc1_clk_dis         : 1   ; /* [1]  */
        unsigned int    ddrphy0_bypass_clk_dis : 1   ; /* [2]  */
        unsigned int    ddrphy1_bypass_clk_dis : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_CLK_DIS;

/* Define the union U_SC_DDRC_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_srst_req        : 1   ; /* [0]  */
        unsigned int    ddrc1_srst_req        : 1   ; /* [1]  */
        unsigned int    ddrphy0_srst_req      : 1   ; /* [2]  */
        unsigned int    ddrphy1_srst_req      : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_RESET_REQ;

/* Define the union U_SC_DDRC_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_srst_dreq       : 1   ; /* [0]  */
        unsigned int    ddrc1_srst_dreq       : 1   ; /* [1]  */
        unsigned int    ddrphy0_srst_dreq     : 1   ; /* [2]  */
        unsigned int    ddrphy1_srst_dreq     : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_RESET_DREQ;

/* Define the union U_SC_SLLC_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_clken           : 1   ; /* [0]  */
        unsigned int    sllc1_clken           : 1   ; /* [1]  */
        unsigned int    sllc2_clken           : 1   ; /* [2]  */
        unsigned int    sllc3_clken           : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_CLK_EN;

/* Define the union U_SC_SLLC_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_clk_dis         : 1   ; /* [0]  */
        unsigned int    sllc1_clk_dis         : 1   ; /* [1]  */
        unsigned int    sllc2_clk_dis         : 1   ; /* [2]  */
        unsigned int    sllc3_clk_dis         : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_CLK_DIS;

/* Define the union U_SC_SLLC_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_srst_req        : 1   ; /* [0]  */
        unsigned int    sllc1_srst_req        : 1   ; /* [1]  */
        unsigned int    sllc2_srst_req        : 1   ; /* [2]  */
        unsigned int    sllc3_srst_req        : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_RESET_REQ;

/* Define the union U_SC_SLLC_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_srst_dreq       : 1   ; /* [0]  */
        unsigned int    sllc1_srst_dreq       : 1   ; /* [1]  */
        unsigned int    sllc2_srst_dreq       : 1   ; /* [2]  */
        unsigned int    sllc3_srst_dreq       : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_RESET_DREQ;

/* Define the union U_SC_SLLC_TSVRX_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_tsvrx0_srst_req : 1   ; /* [0]  */
        unsigned int    sllc0_tsvrx1_srst_req : 1   ; /* [1]  */
        unsigned int    sllc0_tsvrx2_srst_req : 1   ; /* [2]  */
        unsigned int    sllc0_tsvrx3_srst_req : 1   ; /* [3]  */
        unsigned int    sllc1_tsvrx0_srst_req : 1   ; /* [4]  */
        unsigned int    sllc1_tsvrx1_srst_req : 1   ; /* [5]  */
        unsigned int    sllc1_tsvrx2_srst_req : 1   ; /* [6]  */
        unsigned int    sllc1_tsvrx3_srst_req : 1   ; /* [7]  */
        unsigned int    sllc2_tsvrx0_srst_req : 1   ; /* [8]  */
        unsigned int    sllc2_tsvrx1_srst_req : 1   ; /* [9]  */
        unsigned int    sllc2_tsvrx2_srst_req : 1   ; /* [10]  */
        unsigned int    sllc2_tsvrx3_srst_req : 1   ; /* [11]  */
        unsigned int    sllc3_tsvrx0_srst_req : 1   ; /* [12]  */
        unsigned int    sllc3_tsvrx1_srst_req : 1   ; /* [13]  */
        unsigned int    sllc3_tsvrx2_srst_req : 1   ; /* [14]  */
        unsigned int    sllc3_tsvrx3_srst_req : 1   ; /* [15]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_TSVRX_RESET_REQ;

/* Define the union U_SC_SLLC_TSVRX_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_tsvrx0_srst_dreq : 1   ; /* [0]  */
        unsigned int    sllc0_tsvrx1_srst_dreq : 1   ; /* [1]  */
        unsigned int    sllc0_tsvrx2_srst_dreq : 1   ; /* [2]  */
        unsigned int    sllc0_tsvrx3_srst_dreq : 1   ; /* [3]  */
        unsigned int    sllc1_tsvrx0_srst_dreq : 1   ; /* [4]  */
        unsigned int    sllc1_tsvrx1_srst_dreq : 1   ; /* [5]  */
        unsigned int    sllc1_tsvrx2_srst_dreq : 1   ; /* [6]  */
        unsigned int    sllc1_tsvrx3_srst_dreq : 1   ; /* [7]  */
        unsigned int    sllc2_tsvrx0_srst_dreq : 1   ; /* [8]  */
        unsigned int    sllc2_tsvrx1_srst_dreq : 1   ; /* [9]  */
        unsigned int    sllc2_tsvrx2_srst_dreq : 1   ; /* [10]  */
        unsigned int    sllc2_tsvrx3_srst_dreq : 1   ; /* [11]  */
        unsigned int    sllc3_tsvrx0_srst_dreq : 1   ; /* [12]  */
        unsigned int    sllc3_tsvrx1_srst_dreq : 1   ; /* [13]  */
        unsigned int    sllc3_tsvrx2_srst_dreq : 1   ; /* [14]  */
        unsigned int    sllc3_tsvrx3_srst_dreq : 1   ; /* [15]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_TSVRX_RESET_DREQ;

/* Define the union U_SC_HPM_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hpm_clken             : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HPM_CLK_EN;

/* Define the union U_SC_HPM_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hpm_clk_dis           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HPM_CLK_DIS;

/* Define the union U_SC_HPM_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hpm_srst_req          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HPM_RESET_REQ;

/* Define the union U_SC_HPM_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hpm_srst_dreq         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HPM_RESET_DREQ;

/* Define the union U_SC_DJTAG_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_clken           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_CLK_EN;

/* Define the union U_SC_DJTAG_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_clk_dis         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_CLK_DIS;

/* Define the union U_SC_DJTAG_SRST_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_srst_req        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_SRST_REQ;

/* Define the union U_SC_DJTAG_SRST_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_srst_dreq       : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_SRST_DREQ;

/* Define the union U_SC_HHA_MN_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hha0_clken            : 1   ; /* [0]  */
        unsigned int    hha1_clken            : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HHA_MN_CLK_EN;

/* Define the union U_SC_HHA_MN_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hha0_clk_dis          : 1   ; /* [0]  */
        unsigned int    hha1_clk_dis          : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HHA_MN_CLK_DIS;

/* Define the union U_SC_HHA_MN_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hha0_srst_req         : 1   ; /* [0]  */
        unsigned int    hha1_srst_req         : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HHA_MN_RESET_REQ;

/* Define the union U_SC_HHA_MN_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hha0_srst_dreq        : 1   ; /* [0]  */
        unsigned int    hha1_srst_dreq        : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HHA_MN_RESET_DREQ;

/* Define the union U_SC_WDOG_RESET_CFG */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    wdog0_reset_cfg       : 1   ; /* [0]  */
        unsigned int    wdog1_reset_cfg       : 1   ; /* [1]  */
        unsigned int    wdog2_reset_cfg       : 1   ; /* [2]  */
        unsigned int    wdog3_reset_cfg       : 1   ; /* [3]  */
        unsigned int    wdog4_reset_cfg       : 1   ; /* [4]  */
        unsigned int    wdog5_reset_cfg       : 1   ; /* [5]  */
        unsigned int    wdog6_reset_cfg       : 1   ; /* [6]  */
        unsigned int    wdog7_reset_cfg       : 1   ; /* [7]  */
        unsigned int    wdog8_reset_cfg       : 1   ; /* [8]  */
        unsigned int    wdog9_reset_cfg       : 1   ; /* [9]  */
        unsigned int    wdog10_reset_cfg      : 1   ; /* [10]  */
        unsigned int    wdog11_reset_cfg      : 1   ; /* [11]  */
        unsigned int    wdog12_reset_cfg      : 1   ; /* [12]  */
        unsigned int    wdog13_reset_cfg      : 1   ; /* [13]  */
        unsigned int    wdog14_reset_cfg      : 1   ; /* [14]  */
        unsigned int    wdog15_reset_cfg      : 1   ; /* [15]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_WDOG_RESET_CFG;

/* Define the union U_SC_TSMC_PLLCTRL2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll2_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll2_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll2_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll2_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll2_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL2;

/* Define the union U_SC_TSMC_PLLCTRL3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll3_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll3_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll3_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll3_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll3_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL3;

/* Define the union U_SC_PLL_SEL_DDR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll_sel_ddr           : 2   ; /* [1..0]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_SEL_DDR;

/* Define the union U_SC_ALL_SCAN_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    all_scan_sys_int      : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_ALL_SCAN_CTRL;

/* Define the union U_SC_TSENSOR_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_temp_en       : 1   ; /* [0]  */
        unsigned int    tsensor_calib         : 1   ; /* [1]  */
        unsigned int    reserved_0            : 2   ; /* [3..2]  */
        unsigned int    tsensor_temp_trim     : 8   ; /* [11..4]  */
        unsigned int    tsensor_ct_sel        : 2   ; /* [13..12]  */
        unsigned int    reserved_1            : 18  ; /* [31..14]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSENSOR_CTRL;

/* Define the union U_SC_TSENSOR_TEST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_test          : 10  ; /* [9..0]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSENSOR_TEST;

/* Define the union U_SC_TSENSOR_ALARM */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_low           : 10  ; /* [9..0]  */
        unsigned int    tsensor_high          : 10  ; /* [19..10]  */
        unsigned int    reserved_0            : 12  ; /* [31..20]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSENSOR_ALARM;

/* Define the union U_SC_DDRC_APB_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_apb_gt_en       : 1   ; /* [0]  */
        unsigned int    ddrc1_apb_gt_en       : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_APB_CLK_EN;

/* Define the union U_SC_MBIST_CPUI_ENABLE */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mbist_cpui_enable     : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MBIST_CPUI_ENABLE;

/* Define the union U_SC_MBIST_CPUI_RESET_N */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mbist_cpui_reset_n    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MBIST_CPUI_RESET_N;

/* Define the union U_SC_MBIST_CPUI_WRITE_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mbist_cpui_write_en   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MBIST_CPUI_WRITE_EN;

/* Define the union U_SC_SRC_INT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_under         : 1   ; /* [0]  */
        unsigned int    tsensor_over          : 1   ; /* [1]  */
        unsigned int    pll0_unlock           : 1   ; /* [2]  */
        unsigned int    pll1_unlock           : 1   ; /* [3]  */
        unsigned int    pll2_unlock           : 1   ; /* [4]  */
        unsigned int    pll3_unlock           : 1   ; /* [5]  */
        unsigned int    pll4_unlock           : 1   ; /* [6]  */
        unsigned int    djtag_sta_timeout     : 1   ; /* [7]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRC_INT;

/* Define the union U_SC_INT_MASK */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_under_int_mask : 1   ; /* [0]  */
        unsigned int    tsensor_over_int_mask : 1   ; /* [1]  */
        unsigned int    pll_unlock_int_mask   : 1   ; /* [2]  */
        unsigned int    djtag_sta_timeout_int_mask : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_INT_MASK;

/* Define the union U_SC_IM_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    it_md_en              : 1   ; /* [0]  */
        unsigned int    it_md_ctrl            : 3   ; /* [3..1]  */
        unsigned int    it_md_clk             : 3   ; /* [6..4]  */
        unsigned int    in_md_type            : 1   ; /* [7]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_IM_CTRL;

/* Define the union U_SC_IM_STAT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    it_md_stat            : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_IM_STAT;

/* Define the union U_SC_XTAL_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    xtal_over             : 1   ; /* [0]  */
        unsigned int    xtal_en_sw            : 1   ; /* [1]  */
        unsigned int    reserved_0            : 1   ; /* [2]  */
        unsigned int    xtal_time             : 16  ; /* [18..3]  */
        unsigned int    reserved_1            : 13  ; /* [31..19]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_XTAL_CTRL;

/* Define the union U_SC_ITCR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sc_itcr               : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_ITCR;

/* Define the union U_SC_ITIR0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sc_itir0              : 13  ; /* [12..0]  */
        unsigned int    reserved_0            : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_ITIR0;

/* Define the union U_SC_ITOR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sc_itor               : 11  ; /* [10..0]  */
        unsigned int    reserved_0            : 21  ; /* [31..11]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_ITOR;

/* Define the union U_SC_CNT_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    test_mode_en          : 1   ; /* [0]  */
        unsigned int    test_pll_en           : 1   ; /* [1]  */
        unsigned int    test_load_time        : 1   ; /* [2]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CNT_CTRL;

/* Define the union U_SC_BOOT_CTRL_CFG_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    boot_ctrl_cfg_en      : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BOOT_CTRL_CFG_EN;

/* Define the union U_SC_BOOT_CTRL_CFG */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    boot_sel_cfg          : 2   ; /* [1..0]  */
        unsigned int    reserved_0            : 14  ; /* [15..2]  */
        unsigned int    boot_64b_cfg          : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BOOT_CTRL_CFG;

/* Define the union U_SC_SOCKET_INITIALED */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    socket_initialed      : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SOCKET_INITIALED;

/* Define the union U_SC_SYSCNT_SYNC_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    syscnt_sync_en        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSCNT_SYNC_EN;

/* Define the union U_SC_SYSCNT_SYNC_AVE_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    syscnt_sync_ave_en    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSCNT_SYNC_AVE_EN;

/* Define the union U_SC_SYSCNT_SYNC_DST_DATA_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    syscnt_sync_dst_data_en : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSCNT_SYNC_DST_DATA_EN;

/* Define the union U_SC_SYSCNT_SYNC_SRC_DATA_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    syscnt_sync_src_data_en : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSCNT_SYNC_SRC_DATA_EN;

/* Define the union U_SC_SYSCNT_VAL_CFG_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    syscnt_val_cfg_en     : 2   ; /* [1..0]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSCNT_VAL_CFG_EN;

/* Define the union U_SC_PROBE_SYSCNT_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    probe_syscnt_en       : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PROBE_SYSCNT_EN;

/* Define the union U_SC_PROBE_SYSCNT_DATA */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    probe_syscnt_data     : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PROBE_SYSCNT_DATA;

/* Define the union U_SC_BROADCAST_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    broadcast_en          : 5   ; /* [4..0]  */
        unsigned int    reserved_0            : 27  ; /* [31..5]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BROADCAST_EN;

/* Define the union U_SC_BROADCAST_CORE_EVENT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    broadcast_core_event  : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BROADCAST_CORE_EVENT;

/* Define the union U_SC_DJTAG_MSTR_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_mstr_en         : 1   ; /* [0]  */
        unsigned int    djtag_nor_cfg_en      : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_MSTR_EN;

/* Define the union U_SC_DJTAG_MSTR_START_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_mstr_start_en   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_MSTR_START_EN;

/* Define the union U_SC_DJTAG_SEC_ACC_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_sec_acc_en      : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_SEC_ACC_EN;

/* Define the union U_SC_DJTAG_DEBUG_MODULE_SEL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    debug_module_sel      : 6   ; /* [5..0]  */
        unsigned int    reserved_0            : 26  ; /* [31..6]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_DEBUG_MODULE_SEL;

/* Define the union U_SC_DJTAG_MSTR_WR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_mstr_wr         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_MSTR_WR;

/* Define the union U_SC_DJTAG_CHAIN_UNIT_CFG_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    chain_unit_cfg_en     : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_CHAIN_UNIT_CFG_EN;

/* Define the union U_SC_DJTAG_MSTR_ADDR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_mstr_addr       : 31  ; /* [30..0]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_MSTR_ADDR;

/* Define the union U_SC_TDRE_OP_ADDR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tdre_op_addr          : 18  ; /* [17..0]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TDRE_OP_ADDR;

/* Define the union U_SC_TDRE_REPAIR_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tdre_repair_en        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TDRE_REPAIR_EN;

/* Define the union U_SC_AXI_MSTR_START_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    axi_mstr_start_en     : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_AXI_MSTR_START_EN;

/* Define the union U_SC_AXI_MSTR_SEC_ACC_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    axi_mstr_sec_acc_en   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_AXI_MSTR_SEC_ACC_EN;

/* Define the union U_SC_AXI_MSTR_WR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    axi_mstr_wr           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_AXI_MSTR_WR;

/* Define the union U_SC_AXI_MSTR_USER */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    axi_mstr_vmid         : 8   ; /* [7..0]  */
        unsigned int    axi_mstr_asid         : 8   ; /* [15..8]  */
        unsigned int    axi_mstr_user21_16    : 6   ; /* [21..16]  */
        unsigned int    reserved_0            : 10  ; /* [31..22]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_AXI_MSTR_USER;

/* Define the union U_SC_CTRL_HC_HHA */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsel_hc_hha           : 3   ; /* [2..0]  */
        unsigned int    test_hc_hha           : 2   ; /* [4..3]  */
        unsigned int    reserved_0            : 27  ; /* [31..5]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CTRL_HC_HHA;

/* Define the union U_SC_CTRL_RASHDE_HHA */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ctrl_rashde_hha       : 8   ; /* [7..0]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CTRL_RASHDE_HHA;

/* Define the union U_SC_CTRL_HC_LLC */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsel_hc_llc           : 3   ; /* [2..0]  */
        unsigned int    test_hc_llc           : 2   ; /* [4..3]  */
        unsigned int    reserved_0            : 27  ; /* [31..5]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CTRL_HC_LLC;

/* Define the union U_SC_CTRL_RASHDE_LLC */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ctrl_rashde_llc       : 4   ; /* [3..0]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CTRL_RASHDE_LLC;

/* Define the union U_SC_HS_MEM_ADJUST_HC */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hs_mem_adjust_hc      : 8   ; /* [7..0]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HS_MEM_ADJUST_HC;

/* Define the union U_SC_HS_MEM_ADJUST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hs_mem_adjust         : 8   ; /* [7..0]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HS_MEM_ADJUST;

/* Define the union U_SC_CTRL_RASHDE_CSYS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ctrl_rashde_csys      : 8   ; /* [7..0]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CTRL_RASHDE_CSYS;

/* Define the union U_SC_CPU_PMUSNAPSHOTACK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pmusnapshotack_cluster0 : 4   ; /* [3..0]  */
        unsigned int    pmusnapshotack_cluster1 : 4   ; /* [7..4]  */
        unsigned int    pmusnapshotack_cluster2 : 4   ; /* [11..8]  */
        unsigned int    pmusnapshotack_cluster3 : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_PMUSNAPSHOTACK_ST;

/* Define the union U_SC_CPU_SMPEN_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    smpen_cluster0        : 4   ; /* [3..0]  */
        unsigned int    smpen_cluster1        : 4   ; /* [7..4]  */
        unsigned int    smpen_cluster2        : 4   ; /* [11..8]  */
        unsigned int    smpen_cluster3        : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_SMPEN_ST;

/* Define the union U_SC_CPU_STANDBYWFE_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    standbywfe_cluster0   : 4   ; /* [3..0]  */
        unsigned int    standbywfe_cluster1   : 4   ; /* [7..4]  */
        unsigned int    standbywfe_cluster2   : 4   ; /* [11..8]  */
        unsigned int    standbywfe_cluster3   : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_STANDBYWFE_ST;

/* Define the union U_SC_CPU_STANDBYWFI_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    standbywfi_cluster0   : 4   ; /* [3..0]  */
        unsigned int    standbywfi_cluster1   : 4   ; /* [7..4]  */
        unsigned int    standbywfi_cluster2   : 4   ; /* [11..8]  */
        unsigned int    standbywfi_cluster3   : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_STANDBYWFI_ST;

/* Define the union U_SC_CPU_DBGACK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    dbgack_cluster0       : 4   ; /* [3..0]  */
        unsigned int    dbgack_cluster1       : 4   ; /* [7..4]  */
        unsigned int    dbgack_cluster2       : 4   ; /* [11..8]  */
        unsigned int    dbgack_cluster3       : 4   ; /* [15..12]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_DBGACK_ST;

/* Define the union U_SC_CPU_CLREXMONACK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clrexmonack_cluster0  : 1   ; /* [0]  */
        unsigned int    clrexmonack_cluster1  : 1   ; /* [1]  */
        unsigned int    clrexmonack_cluster2  : 1   ; /* [2]  */
        unsigned int    clrexmonack_cluster3  : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_CLREXMONACK_ST;

/* Define the union U_SC_CPU_STANDBYWFIL2_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    standbywfil2_cluster0 : 1   ; /* [0]  */
        unsigned int    standbywfil2_cluster1 : 1   ; /* [1]  */
        unsigned int    standbywfil2_cluster2 : 1   ; /* [2]  */
        unsigned int    standbywfil2_cluster3 : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_STANDBYWFIL2_ST;

/* Define the union U_SC_CPU_L2FSHDONE_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    l2flushdone_cluster0  : 1   ; /* [0]  */
        unsigned int    l2flushdone_cluster1  : 1   ; /* [1]  */
        unsigned int    l2flushdone_cluster2  : 1   ; /* [2]  */
        unsigned int    l2flushdone_cluster3  : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CPU_L2FSHDONE_ST;

/* Define the union U_SC_SYSMODE_STATUS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sys_mode              : 4   ; /* [3..0]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SYSMODE_STATUS;

/* Define the union U_SC_PLL_LOCK_STATUS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_lock             : 1   ; /* [0]  */
        unsigned int    pll1_lock             : 1   ; /* [1]  */
        unsigned int    pll2_lock             : 1   ; /* [2]  */
        unsigned int    pll3_lock             : 1   ; /* [3]  */
        unsigned int    pll4_lock             : 1   ; /* [4]  */
        unsigned int    reserved_0            : 27  ; /* [31..5]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_LOCK_STATUS;

/* Define the union U_SC_PLLCTRL_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll_on                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLCTRL_ST;

/* Define the union U_SC_REF_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ref_clk_st            : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_REF_CLK_ST;

/* Define the union U_SC_GPIO_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    gpio_db_clk_st        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_GPIO_CLK_ST;

/* Define the union U_SC_CLUS0_CRG_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_dbg_clk_st   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CRG_CLK_ST;

/* Define the union U_SC_CLUS0_CRG_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster0_l2_srst_st   : 1   ; /* [0]  */
        unsigned int    cluster0_cpu0_por_srst_st : 1   ; /* [1]  */
        unsigned int    cluster0_cpu1_por_srst_st : 1   ; /* [2]  */
        unsigned int    cluster0_cpu2_por_srst_st : 1   ; /* [3]  */
        unsigned int    cluster0_cpu3_por_srst_st : 1   ; /* [4]  */
        unsigned int    cluster0_cpu0_srst_st : 1   ; /* [5]  */
        unsigned int    cluster0_cpu1_srst_st : 1   ; /* [6]  */
        unsigned int    cluster0_cpu2_srst_st : 1   ; /* [7]  */
        unsigned int    cluster0_cpu3_srst_st : 1   ; /* [8]  */
        unsigned int    cluster0_dbg_srst_st  : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS0_CRG_RESET_ST;

/* Define the union U_SC_CLUS1_CRG_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster1_dbg_clk_st   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CRG_CLK_ST;

/* Define the union U_SC_CLUS1_CRG_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster1_l2_srst_st   : 1   ; /* [0]  */
        unsigned int    cluster1_cpu0_por_srst_st : 1   ; /* [1]  */
        unsigned int    cluster1_cpu1_por_srst_st : 1   ; /* [2]  */
        unsigned int    cluster1_cpu2_por_srst_st : 1   ; /* [3]  */
        unsigned int    cluster1_cpu3_por_srst_st : 1   ; /* [4]  */
        unsigned int    cluster1_cpu0_srst_st : 1   ; /* [5]  */
        unsigned int    cluster1_cpu1_srst_st : 1   ; /* [6]  */
        unsigned int    cluster1_cpu2_srst_st : 1   ; /* [7]  */
        unsigned int    cluster1_cpu3_srst_st : 1   ; /* [8]  */
        unsigned int    cluster1_dbg_srst_st  : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS1_CRG_RESET_ST;

/* Define the union U_SC_CLUS2_CRG_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster2_dbg_clk_st   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CRG_CLK_ST;

/* Define the union U_SC_CLUS2_CRG_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster2_l2_srst_st   : 1   ; /* [0]  */
        unsigned int    cluster2_cpu0_por_srst_st : 1   ; /* [1]  */
        unsigned int    cluster2_cpu1_por_srst_st : 1   ; /* [2]  */
        unsigned int    cluster2_cpu2_por_srst_st : 1   ; /* [3]  */
        unsigned int    cluster2_cpu3_por_srst_st : 1   ; /* [4]  */
        unsigned int    cluster2_cpu0_srst_st : 1   ; /* [5]  */
        unsigned int    cluster2_cpu1_srst_st : 1   ; /* [6]  */
        unsigned int    cluster2_cpu2_srst_st : 1   ; /* [7]  */
        unsigned int    cluster2_cpu3_srst_st : 1   ; /* [8]  */
        unsigned int    cluster2_dbg_srst_st  : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS2_CRG_RESET_ST;

/* Define the union U_SC_CLUS3_CRG_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster3_dbg_clk_st   : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CRG_CLK_ST;

/* Define the union U_SC_CLUS3_CRG_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cluster3_l2_srst_st   : 1   ; /* [0]  */
        unsigned int    cluster3_cpu0_por_srst_st : 1   ; /* [1]  */
        unsigned int    cluster3_cpu1_por_srst_st : 1   ; /* [2]  */
        unsigned int    cluster3_cpu2_por_srst_st : 1   ; /* [3]  */
        unsigned int    cluster3_cpu3_por_srst_st : 1   ; /* [4]  */
        unsigned int    cluster3_cpu0_srst_st : 1   ; /* [5]  */
        unsigned int    cluster3_cpu1_srst_st : 1   ; /* [6]  */
        unsigned int    cluster3_cpu2_srst_st : 1   ; /* [7]  */
        unsigned int    cluster3_cpu3_srst_st : 1   ; /* [8]  */
        unsigned int    cluster3_dbg_srst_st  : 1   ; /* [9]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLUS3_CRG_RESET_ST;

/* Define the union U_SC_LLC_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    llc0_clk_st           : 1   ; /* [0]  */
        unsigned int    llc1_clk_st           : 1   ; /* [1]  */
        unsigned int    llc2_clk_st           : 1   ; /* [2]  */
        unsigned int    llc3_clk_st           : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LLC_CLK_ST;

/* Define the union U_SC_LLC_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    llc0_srst_st          : 1   ; /* [0]  */
        unsigned int    llc1_srst_st          : 1   ; /* [1]  */
        unsigned int    llc2_srst_st          : 1   ; /* [2]  */
        unsigned int    llc3_srst_st          : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LLC_RESET_ST;

/* Define the union U_SC_DDRC_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_clk_st          : 1   ; /* [0]  */
        unsigned int    ddrc1_clk_st          : 1   ; /* [1]  */
        unsigned int    ddrphy0_bypass_clk_st : 1   ; /* [2]  */
        unsigned int    ddrphy1_bypass_clk_st : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_CLK_ST;

/* Define the union U_SC_DDRC_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ddrc0_srst_st         : 1   ; /* [0]  */
        unsigned int    ddrc1_srst_st         : 1   ; /* [1]  */
        unsigned int    ddrphy0_srst_st       : 1   ; /* [2]  */
        unsigned int    ddrphy1_srst_st       : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_RESET_ST;

/* Define the union U_SC_SLLC_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_clk_st          : 1   ; /* [0]  */
        unsigned int    sllc1_clk_st          : 1   ; /* [1]  */
        unsigned int    sllc2_clk_st          : 1   ; /* [2]  */
        unsigned int    sllc3_clk_st          : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_CLK_ST;

/* Define the union U_SC_SLLC_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_srst_st         : 1   ; /* [0]  */
        unsigned int    sllc1_srst_st         : 1   ; /* [1]  */
        unsigned int    sllc2_srst_st         : 1   ; /* [2]  */
        unsigned int    sllc3_srst_st         : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_RESET_ST;

/* Define the union U_SC_SLLC_TSVRX_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sllc0_tsvrx0_srst_st  : 1   ; /* [0]  */
        unsigned int    sllc0_tsvrx1_srst_st  : 1   ; /* [1]  */
        unsigned int    sllc0_tsvrx2_srst_st  : 1   ; /* [2]  */
        unsigned int    sllc0_tsvrx3_srst_st  : 1   ; /* [3]  */
        unsigned int    sllc1_tsvrx0_srst_st  : 1   ; /* [4]  */
        unsigned int    sllc1_tsvrx1_srst_st  : 1   ; /* [5]  */
        unsigned int    sllc1_tsvrx2_srst_st  : 1   ; /* [6]  */
        unsigned int    sllc1_tsvrx3_srst_st  : 1   ; /* [7]  */
        unsigned int    sllc2_tsvrx0_srst_st  : 1   ; /* [8]  */
        unsigned int    sllc2_tsvrx1_srst_st  : 1   ; /* [9]  */
        unsigned int    sllc2_tsvrx2_srst_st  : 1   ; /* [10]  */
        unsigned int    sllc2_tsvrx3_srst_st  : 1   ; /* [11]  */
        unsigned int    sllc3_tsvrx0_srst_st  : 1   ; /* [12]  */
        unsigned int    sllc3_tsvrx1_srst_st  : 1   ; /* [13]  */
        unsigned int    sllc3_tsvrx2_srst_st  : 1   ; /* [14]  */
        unsigned int    sllc3_tsvrx3_srst_st  : 1   ; /* [15]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SLLC_TSVRX_RESET_ST;

/* Define the union U_SC_HPM_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hpm_clk_st            : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HPM_CLK_ST;

/* Define the union U_SC_HPM_SRST_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hpm_srst_st           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HPM_SRST_ST;

/* Define the union U_SC_DJTAG_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_clk_st          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_CLK_ST;

/* Define the union U_SC_DJTAG_SRST_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    djtag_srst_st         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_SRST_ST;

/* Define the union U_SC_HHA_MN_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hha0_clk_st           : 1   ; /* [0]  */
        unsigned int    hha1_clk_st           : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HHA_MN_CLK_ST;

/* Define the union U_SC_HHA_MN_SRST_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    hha0_srst_st          : 1   ; /* [0]  */
        unsigned int    hha1_srst_st          : 1   ; /* [1]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_HHA_MN_SRST_ST;

/* Define the union U_SC_DDRC_WARM_RST_ACKED */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    warm_rst_acked        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DDRC_WARM_RST_ACKED;

/* Define the union U_SC_TSENSOR_SYSSTAT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    temp_out_tsensor      : 10  ; /* [9..0]  */
        unsigned int    reserved_0            : 2   ; /* [11..10]  */
        unsigned int    data_ready_tsensor    : 1   ; /* [12]  */
        unsigned int    efuse_parameter_trim  : 8   ; /* [20..13]  */
        unsigned int    reserved_1            : 11  ; /* [31..21]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSENSOR_SYSSTAT;

/* Define the union U_SC_TSENSOR_TEMP_SAMPLE */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_sample        : 10  ; /* [9..0]  */
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSENSOR_TEMP_SAMPLE;

/* Define the union U_SC_MDDRC0_AC_IOCTL_IOTEST1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mddrc0_ac_ioctl_iotest37_32 : 6   ; /* [5..0]  */
        unsigned int    reserved_0            : 26  ; /* [31..6]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MDDRC0_AC_IOCTL_IOTEST1;

/* Define the union U_SC_MDDRC1_AC_IOCTL_IOTEST1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mddrc1_ac_ioctl_iotest37_32 : 6   ; /* [5..0]  */
        unsigned int    reserved_0            : 26  ; /* [31..6]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MDDRC1_AC_IOCTL_IOTEST1;

/* Define the union U_SC_MDDRC0_DX_IOCTL_IOTEST3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mddrc0_dx_ioctl_iotest98_96 : 3   ; /* [2..0]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MDDRC0_DX_IOCTL_IOTEST3;

/* Define the union U_SC_MDDRC1_DX_IOCTL_IOTEST3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    mddrc1_dx_ioctl_iotest98_96 : 3   ; /* [2..0]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_MDDRC1_DX_IOCTL_IOTEST3;

/* Define the union U_SC_INT_STATUS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsensor_under_int_status : 1   ; /* [0]  */
        unsigned int    tsensor_over_int_status : 1   ; /* [1]  */
        unsigned int    pll_unlock_int_status : 1   ; /* [2]  */
        unsigned int    djtag_timeout_int_status : 1   ; /* [3]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_INT_STATUS;

/* Define the union U_SC_SOCKET_ID */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    socket_id             : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SOCKET_ID;

/* Define the union U_SC_BOOT_CTRL_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pad_die_mode          : 2   ; /* [1..0]  */
        unsigned int    efuse_ns_forbid       : 1   ; /* [2]  */
        unsigned int    pad_boot_sel          : 2   ; /* [4..3]  */
        unsigned int    pad_boot_64b          : 1   ; /* [5]  */
        unsigned int    pad_rst_mode          : 1   ; /* [6]  */
        unsigned int    reserved_0            : 25  ; /* [31..7]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BOOT_CTRL_ST;

/* Define the union U_SC_BOOT_CTRL_CFG_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    boot_sel_muxed        : 2   ; /* [1..0]  */
        unsigned int    reserved_0            : 14  ; /* [15..2]  */
        unsigned int    boot_64b_muxed        : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BOOT_CTRL_CFG_ST;

/* Define the union U_SC_LAST_RST_STATUS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    last_rst_status       : 4   ; /* [3..0]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_LAST_RST_STATUS;

/* Define the union U_SC_XTAL_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    xtal_on               : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_XTAL_ST;

/* Define the union U_SC_CNT_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    xtal_pll_timeout      : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CNT_ST;

/* Define the union U_SC_ITIR0_TEST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sc_itir0_tst          : 13  ; /* [12..0]  */
        unsigned int    reserved_0            : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_ITIR0_TEST;

/* Define the union U_SC_ITOR_TEST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sc_itor_tst           : 11  ; /* [10..0]  */
        unsigned int    reserved_0            : 21  ; /* [31..11]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_ITOR_TEST;

/* Define the union U_SC_CNT_DATA */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sc_cnt_data           : 25  ; /* [24..0]  */
        unsigned int    reserved_0            : 7   ; /* [31..25]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CNT_DATA;

/* Define the union U_SC_AXI_ACC_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    axi_syscnt_wr_err     : 1   ; /* [0]  */
        unsigned int    reserved_0            : 3   ; /* [3..1]  */
        unsigned int    syscnt_curr_stat      : 4   ; /* [7..4]  */
        unsigned int    broadcast_berror      : 1   ; /* [8]  */
        unsigned int    reserved_1            : 23  ; /* [31..9]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_AXI_ACC_ST;

/* Define the union U_SC_DJTAG_OP_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    unit_conflict         : 8   ; /* [7..0]  */
        unsigned int    djtag_op_done         : 1   ; /* [8]  */
        unsigned int    debug_bus_en          : 1   ; /* [9]  */
        unsigned int    reserved_0            : 6   ; /* [15..10]  */
        unsigned int    rdata_changed         : 10  ; /* [25..16]  */
        unsigned int    reserved_1            : 6   ; /* [31..26]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DJTAG_OP_ST;

/* Define the union U_SC_AXI_MSTR_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    axi_op_done           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 3   ; /* [3..1]  */
        unsigned int    axi_rd_error          : 1   ; /* [4]  */
        unsigned int    axi_wr_error          : 1   ; /* [5]  */
        unsigned int    axi_op_conflict       : 1   ; /* [6]  */
        unsigned int    reserved_1            : 25  ; /* [31..7]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_AXI_MSTR_ST;

/* Define the union U_SC_BOARD_CFG_INFO */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    board_cfg_info        : 28  ; /* [27..0]  */
        unsigned int    reserved_0            : 4   ; /* [31..28]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_BOARD_CFG_INFO;


/*������POE�Ĵ����ṹ����*/

/* Define the union U_SC_SRAM_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_sram_enb          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_EN;

/* Define the union U_SC_SRAM_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_sram_dsb          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_DIS;

/* Define the union U_SC_POE_CLK_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_poe_enb           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_EN;

/* Define the union U_SC_POE_CLK_DIS */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_poe_dsb           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_DIS;

/* Define the union U_SC_SRAM_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_srst_req         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_REQ;

/* Define the union U_SC_SRAM_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_srst_dreq        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_DREQ;

/* Define the union U_SC_POE_RESET_REQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    poe_srst_req          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_REQ;

/* Define the union U_SC_POE_RESET_DREQ */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    poe_srst_dreq         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_DREQ;

/* Define the union U_SC_DISPATCH_DAW_EN */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    dispatch_daw_en       : 8   ; /* [7..0]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_EN;

/* Define the union U_SC_DISPATCH_DAW_ARRAY0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array0_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array0_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array0_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array0_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY0;

/* Define the union U_SC_DISPATCH_DAW_ARRAY1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array1_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array1_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array1_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array1_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY1;

/* Define the union U_SC_DISPATCH_DAW_ARRAY2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array2_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array2_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array2_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array2_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY2;

/* Define the union U_SC_DISPATCH_DAW_ARRAY3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array3_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array3_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array3_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array3_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY3;

/* Define the union U_SC_DISPATCH_DAW_ARRAY4 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array4_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array4_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array4_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array4_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY4;

/* Define the union U_SC_DISPATCH_DAW_ARRAY5 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array5_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array5_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array5_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array5_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY5;

/* Define the union U_SC_DISPATCH_DAW_ARRAY6 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array6_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array6_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array6_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array6_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY6;

/* Define the union U_SC_DISPATCH_DAW_ARRAY7 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array7_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array7_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array7_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array7_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY7;

/* Define the union U_SC_DISPATCH_RETRY_CONTROL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    retry_num_limit       : 16  ; /* [15..0]  */
        unsigned int    retry_en              : 1   ; /* [16]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_RETRY_CONTROL;

/* Define the union U_SC_DISPATCH_INTMASK */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    intmask               : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTMASK;

/* Define the union U_SC_DISPATCH_RAWINT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rawint                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_RAWINT;

/* Define the union U_SC_DISPATCH_INTSTAT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    intsts                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTSTAT;

/* Define the union U_SC_DISPATCH_INTCLR */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    intclr                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTCLR;

/* Define the union U_SC_DISPATCH_ERRSTAT */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    err_opcode            : 5   ; /* [4..0]  */
        unsigned int    err_addr              : 17  ; /* [21..5]  */
        unsigned int    reserved_0            : 10  ; /* [31..22]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_ERRSTAT;

/* Define the union U_SC_DISPATCH_REMAP_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sys_remap_vld         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_REMAP_CTRL;

/* Define the union U_SC_SRAM_CTRL0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_ecc_en           : 1   ; /* [0]  */
        unsigned int    sram_ecc_err_trans    : 1   ; /* [1]  */
        unsigned int    sram_err_clr          : 1   ; /* [2]  */
        unsigned int    sram_err_cnt_clr      : 1   ; /* [3]  */
        unsigned int    sram_sglerr_addr_clr  : 1   ; /* [4]  */
        unsigned int    sram_mulerr_addr_clr  : 1   ; /* [5]  */
        unsigned int    sram_swap_en          : 1   ; /* [6]  */
        unsigned int    reserved_0            : 25  ; /* [31..7]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CTRL0;

/* Define the union U_SC_SRAM_CTRL1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_prot_ctrl_en     : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CTRL1;

/* Define the union U_SC_SMMU_MEM_CTRL1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsel_hc_smmu          : 3   ; /* [2..0]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SMMU_MEM_CTRL1;

/* Define the union U_SC_SMMU_MEM_CTRL2 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    test_hc_smmu          : 2   ; /* [1..0]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SMMU_MEM_CTRL2;

/* Define the union U_SC_SRAM_MEM_CTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ctrl_rashde_sram      : 4   ; /* [3..0]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_MEM_CTRL;

/* Define the union U_SC_PLLFCTRL0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll0_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll0_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll0_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll0_bypass           : 1   ; /* [24]  */
        unsigned int    pll0_pd               : 1   ; /* [25]  */
        unsigned int    pll0_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll0_dacpd            : 1   ; /* [27]  */
        unsigned int    pll0_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll0_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll0_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL0;

/*Silicon Creation PLL���üĴ���*/
/* Define the union U_SC_PLLFCTRL0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll_bypass           : 1   ; /* [24]  */
        unsigned int    pll_pd               : 1   ; /* [25]  */
        unsigned int    pll_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll_dacpd            : 1   ; /* [27]  */
        unsigned int    pll_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved             : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SlicionCrePLLTRL;

/* Define the union U_SC_PLLFCTRL1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_frac             : 26  ; /* [25..0]  */
        unsigned int    reserved_0            : 6   ; /* [31..26]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL1;

/* Define the union U_SC_PLLFCTRL8 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll4_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll4_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll4_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll4_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll4_bypass           : 1   ; /* [24]  */
        unsigned int    pll4_pd               : 1   ; /* [25]  */
        unsigned int    pll4_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll4_dacpd            : 1   ; /* [27]  */
        unsigned int    pll4_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll4_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll4_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL8;

/* Define the union U_SC_PLLFCTRL9 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll4_frac             : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL9;

/* Define the union U_SC_PLL_CLK_BYPASS0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll4_peri_mode        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS0;

/* Define the union U_SC_PLL_CLK_BYPASS1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_bypass_external_n : 1   ; /* [0]  */
        unsigned int    pll1_bypass_external_n : 1   ; /* [1]  */
        unsigned int    reserved_0            : 2   ; /* [3..2]  */
        unsigned int    pll4_bypass_external_n : 1   ; /* [4]  */
        unsigned int    reserved_1            : 27  ; /* [31..5]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS1;

/* Define the union U_SC_CLK_SEL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cpu_clk_source_sel    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 7   ; /* [7..1]  */
        unsigned int    gpio_db_clk_sel       : 1   ; /* [8]  */
        unsigned int    clk_div_sel           : 1   ; /* [9]  */
        unsigned int    reserved_1            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLK_SEL;

/* Define the union U_SC_TSMC_PLLCTRL1 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll1_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll1_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll1_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll1_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll1_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL1;

/*TSMC����PLL���ýӿ�*/
/* Define the union U_SC_TSMC_PLLCTRL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved             : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL;

/* Define the union U_SC_TSMC_PLLCTRL4 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll4_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll4_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll4_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll4_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll4_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL4;

/* Define the union U_SC_PLL_SEL */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 2   ; /* [1..0]  */
        unsigned int    pll_sel               : 1   ; /* [2]  */
        unsigned int    reserved_1            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_SEL;

/* Define the union U_SC_SRAM_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_sram_st           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_ST;

/* Define the union U_SC_POE_CLK_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_poe_st            : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_ST;

/* Define the union U_SC_SRAM_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_srst_st          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_ST;

/* Define the union U_SC_POE_RESET_ST */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    poe_srst_st           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_ST;

/* Define the union U_SC_SRAM_ST0 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_single_err       : 1   ; /* [0]  */
        unsigned int    sram_double_err       : 1   ; /* [1]  */
        unsigned int    sram_multi_err        : 1   ; /* [2]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST0;

/* Define the union U_SC_SRAM_ST3 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_count_ecc_sglerr : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST3;

/* Define the union U_SC_SRAM_ST4 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_count_ecc_mulerr : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST4;

/* Define the union U_SC_SRAM_ST5 */
typedef union
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_dfx_dbg          : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST5;

#endif


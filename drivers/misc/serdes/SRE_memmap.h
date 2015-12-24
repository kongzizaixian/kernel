/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : mc_iomap_hisilicon.h
  �� �� ��   : ����
  ��    ��   : c00111586
  ��������   : 2009��4��21��
  ����޸�   :
  ��������   : ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2009��4��21��
    ��    ��   : c00111586
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef _SRE_MEMMAP_H
#define _SRE_MEMMAP_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* ͷ�ļ����� ----------------------------------*/

/* �궨�� --------------------------------------*/
/*��ȡ��Ƶ�ļĴ�����ַ  */
#if 0  /*h64632*/
#define MC_CLK_REG_ADDR         0xA0000018UL
#else
#define MC_CLK_REG_ADDR         0x13e00100
#endif /*h64632*/

/*SYSTEM CONTROL REGISTER  1380��ַ��650����*/
#define SRE_SYSCTL_REG_BASE_ADDR    (0x20000000 + 0x80000000)

/*poe gmac and so on buffer & cacheable control*/
#define SRE_SC_PERCTRL49_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x0F0)

/*ar_shaping*/
#define SRE_SC_PERCTRL74_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x154)

/*SYSTEM CPU VERSION REGISTER*/
#define SRE_SYSCTL_REG_CPU_VER0          (SRE_SYSCTL_REG_BASE_ADDR + 0xEE0)
#define SRE_SYSCTL_REG_CPU_VER1          (SRE_SYSCTL_REG_BASE_ADDR + 0xEE4)
#define SRE_SYSCTL_REG_CPU_VER2          (SRE_SYSCTL_REG_BASE_ADDR + 0xEE8)
#define SRE_SYSCTL_REG_CPU_VER3         (SRE_SYSCTL_REG_BASE_ADDR + 0xEEC)

/*SEC Request*/
#define MC_SEC1_REQ_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x048)
#define MC_SEC0_REQ_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x04C)

/* ��������ģ�鸴λ�Ĵ��� */
#define SRE_SC_PERCTRL6_REG           (SRE_SYSCTL_REG_BASE_ADDR + 0x044)
#define SRE_SC_PERCTRL7_REG           (SRE_SYSCTL_REG_BASE_ADDR + 0x048)
#define SRE_SC_PERCTRL8_REG           (SRE_SYSCTL_REG_BASE_ADDR + 0x04C)

/*HDCP Request*/
#define SRE_HDCP_REQ_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x04C)

/*HDCP Clock*/
#define SRE_HDCP_CLK_ENABLE_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x400)
#define SRE_HDCP_CLK_DISABLE_REG             (SRE_SYSCTL_REG_BASE_ADDR + 0x404)
#define SRE_HDCP_CLK_STATUS_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x408)
/*7x3 Master port base*/
/*hi1380 asic*/
#define MC_7x3MASTER_REG_BASE_ADDR     (0x18040000 + 0x80000000)

//******************************************************************************

/* BMU_REG ģ��Ĵ�������ַ */
#if 0     /* z00202052 */
#define SRE_BMU_REG_BASE_ADDR            (0x11400000UL)            /*BMU�Ĵ�������ַ*/
#else
#define SRE_BMU_REG_BASE_ADDR            (0xe1400000UL)            /*BMU�Ĵ�������ַ*/
#endif    /* z00202052 */


/******************************************************************************/
/*                      BMU BMU_REG �Ĵ�������                                */
/******************************************************************************/
#define SRE_BMU_ADDR_P_0_REG                       (SRE_BMU_REG_BASE_ADDR + 0x0)                 /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_1_REG                       (SRE_BMU_REG_BASE_ADDR + 0x4)                 /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_2_REG                       (SRE_BMU_REG_BASE_ADDR + 0x8)                 /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_3_REG                       (SRE_BMU_REG_BASE_ADDR + 0xC)                 /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_4_REG                       (SRE_BMU_REG_BASE_ADDR + 0x10)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_5_REG                       (SRE_BMU_REG_BASE_ADDR + 0x14)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_6_REG                       (SRE_BMU_REG_BASE_ADDR + 0x18)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_7_REG                       (SRE_BMU_REG_BASE_ADDR + 0x1C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_8_REG                       (SRE_BMU_REG_BASE_ADDR + 0x20)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_9_REG                       (SRE_BMU_REG_BASE_ADDR + 0x24)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_10_REG                      (SRE_BMU_REG_BASE_ADDR + 0x28)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_11_REG                      (SRE_BMU_REG_BASE_ADDR + 0x2C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_12_REG                      (SRE_BMU_REG_BASE_ADDR + 0x30)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_13_REG                      (SRE_BMU_REG_BASE_ADDR + 0x34)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_14_REG                      (SRE_BMU_REG_BASE_ADDR + 0x38)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_15_REG                      (SRE_BMU_REG_BASE_ADDR + 0x3C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_16_REG                      (SRE_BMU_REG_BASE_ADDR + 0x40)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_17_REG                      (SRE_BMU_REG_BASE_ADDR + 0x44)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_18_REG                      (SRE_BMU_REG_BASE_ADDR + 0x48)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_19_REG                      (SRE_BMU_REG_BASE_ADDR + 0x4C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_20_REG                      (SRE_BMU_REG_BASE_ADDR + 0x50)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_21_REG                      (SRE_BMU_REG_BASE_ADDR + 0x54)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_22_REG                      (SRE_BMU_REG_BASE_ADDR + 0x58)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_23_REG                      (SRE_BMU_REG_BASE_ADDR + 0x5C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_24_REG                      (SRE_BMU_REG_BASE_ADDR + 0x60)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_25_REG                      (SRE_BMU_REG_BASE_ADDR + 0x64)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_26_REG                      (SRE_BMU_REG_BASE_ADDR + 0x68)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_27_REG                      (SRE_BMU_REG_BASE_ADDR + 0x6C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_28_REG                      (SRE_BMU_REG_BASE_ADDR + 0x70)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_29_REG                      (SRE_BMU_REG_BASE_ADDR + 0x74)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_30_REG                      (SRE_BMU_REG_BASE_ADDR + 0x78)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_ADDR_P_31_REG                      (SRE_BMU_REG_BASE_ADDR + 0x7C)                /* BMUģ���pool�Ķ�д�ӿڵ�ַ�� */
#define SRE_BMU_SIZE_P_0_REG                       (SRE_BMU_REG_BASE_ADDR + 0x80)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_1_REG                       (SRE_BMU_REG_BASE_ADDR + 0x84)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_2_REG                       (SRE_BMU_REG_BASE_ADDR + 0x88)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_3_REG                       (SRE_BMU_REG_BASE_ADDR + 0x8C)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_4_REG                       (SRE_BMU_REG_BASE_ADDR + 0x90)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_5_REG                       (SRE_BMU_REG_BASE_ADDR + 0x94)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_6_REG                       (SRE_BMU_REG_BASE_ADDR + 0x98)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_7_REG                       (SRE_BMU_REG_BASE_ADDR + 0x9C)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_8_REG                       (SRE_BMU_REG_BASE_ADDR + 0xA0)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_9_REG                       (SRE_BMU_REG_BASE_ADDR + 0xA4)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_10_REG                      (SRE_BMU_REG_BASE_ADDR + 0xA8)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_11_REG                      (SRE_BMU_REG_BASE_ADDR + 0xAC)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_12_REG                      (SRE_BMU_REG_BASE_ADDR + 0xB0)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_13_REG                      (SRE_BMU_REG_BASE_ADDR + 0xB4)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_14_REG                      (SRE_BMU_REG_BASE_ADDR + 0xB8)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_15_REG                      (SRE_BMU_REG_BASE_ADDR + 0xBC)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_16_REG                      (SRE_BMU_REG_BASE_ADDR + 0xC0)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_17_REG                      (SRE_BMU_REG_BASE_ADDR + 0xC4)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_18_REG                      (SRE_BMU_REG_BASE_ADDR + 0xC8)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_19_REG                      (SRE_BMU_REG_BASE_ADDR + 0xCC)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_20_REG                      (SRE_BMU_REG_BASE_ADDR + 0xD0)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_21_REG                      (SRE_BMU_REG_BASE_ADDR + 0xD4)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_22_REG                      (SRE_BMU_REG_BASE_ADDR + 0xD8)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_23_REG                      (SRE_BMU_REG_BASE_ADDR + 0xDC)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_24_REG                      (SRE_BMU_REG_BASE_ADDR + 0xE0)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_25_REG                      (SRE_BMU_REG_BASE_ADDR + 0xE4)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_26_REG                      (SRE_BMU_REG_BASE_ADDR + 0xE8)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_27_REG                      (SRE_BMU_REG_BASE_ADDR + 0xEC)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_28_REG                      (SRE_BMU_REG_BASE_ADDR + 0xF0)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_29_REG                      (SRE_BMU_REG_BASE_ADDR + 0xF4)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_30_REG                      (SRE_BMU_REG_BASE_ADDR + 0xF8)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_SIZE_P_31_REG                      (SRE_BMU_REG_BASE_ADDR + 0xFC)                /* BMU pool���ڲ�SRAM ��С�� */
#define SRE_BMU_WL_P_0_REG                         (SRE_BMU_REG_BASE_ADDR + 0x100)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_1_REG                         (SRE_BMU_REG_BASE_ADDR + 0x104)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_2_REG                         (SRE_BMU_REG_BASE_ADDR + 0x108)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_3_REG                         (SRE_BMU_REG_BASE_ADDR + 0x10C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_4_REG                         (SRE_BMU_REG_BASE_ADDR + 0x110)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_5_REG                         (SRE_BMU_REG_BASE_ADDR + 0x114)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_6_REG                         (SRE_BMU_REG_BASE_ADDR + 0x118)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_7_REG                         (SRE_BMU_REG_BASE_ADDR + 0x11C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_8_REG                         (SRE_BMU_REG_BASE_ADDR + 0x120)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_9_REG                         (SRE_BMU_REG_BASE_ADDR + 0x124)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_10_REG                        (SRE_BMU_REG_BASE_ADDR + 0x128)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_11_REG                        (SRE_BMU_REG_BASE_ADDR + 0x12C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_12_REG                        (SRE_BMU_REG_BASE_ADDR + 0x130)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_13_REG                        (SRE_BMU_REG_BASE_ADDR + 0x134)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_14_REG                        (SRE_BMU_REG_BASE_ADDR + 0x138)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_15_REG                        (SRE_BMU_REG_BASE_ADDR + 0x13C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_16_REG                        (SRE_BMU_REG_BASE_ADDR + 0x140)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_17_REG                        (SRE_BMU_REG_BASE_ADDR + 0x144)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_18_REG                        (SRE_BMU_REG_BASE_ADDR + 0x148)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_19_REG                        (SRE_BMU_REG_BASE_ADDR + 0x14C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_20_REG                        (SRE_BMU_REG_BASE_ADDR + 0x150)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_21_REG                        (SRE_BMU_REG_BASE_ADDR + 0x154)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_22_REG                        (SRE_BMU_REG_BASE_ADDR + 0x158)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_23_REG                        (SRE_BMU_REG_BASE_ADDR + 0x15C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_24_REG                        (SRE_BMU_REG_BASE_ADDR + 0x160)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_25_REG                        (SRE_BMU_REG_BASE_ADDR + 0x164)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_26_REG                        (SRE_BMU_REG_BASE_ADDR + 0x168)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_27_REG                        (SRE_BMU_REG_BASE_ADDR + 0x16C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_28_REG                        (SRE_BMU_REG_BASE_ADDR + 0x170)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_29_REG                        (SRE_BMU_REG_BASE_ADDR + 0x174)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_30_REG                        (SRE_BMU_REG_BASE_ADDR + 0x178)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_WL_P_31_REG                        (SRE_BMU_REG_BASE_ADDR + 0x17C)               /* BMU pool���ڲ�SRAM ���ⲿL2/DRAM �����/�ض�ˮ�ߡ� */
#define SRE_BMU_CTRL_REG                           (SRE_BMU_REG_BASE_ADDR + 0x180)               /* BMU ȫ�ֿ��ƼĴ����� */
#define SRE_BMU_POOL_RDEN_REG                      (SRE_BMU_REG_BASE_ADDR + 0x184)               /* BMUģ��pool ��дʹ�ܱ���λ�� */
#define SRE_BMU_INT_STS_REG                        (SRE_BMU_REG_BASE_ADDR + 0x188)               /* BMU �ж�״̬�Ĵ����� */
#define SRE_BMU_INT_EN_REG                         (SRE_BMU_REG_BASE_ADDR + 0x18C)               /* BMU �ж�ʹ�ܼĴ����� */
#define SRE_BMU_UNALIGN_ERR_PID_REG                (SRE_BMU_REG_BASE_ADDR + 0x190)               /* BMU �Ƕ������Poo ID �Ĵ����� */
#define SRE_BMU_ECC_1B_CNT_REG                     (SRE_BMU_REG_BASE_ADDR + 0x194)               /* BMU SRAM ecc 1bit����ͳ�Ƽ����� */
#define SRE_BMU_CPU_ADD_STATUS_L_REG               (SRE_BMU_REG_BASE_ADDR + 0x198)               /* CPU ADD BMU״̬�Ĵ���0~31 ����CPU */
#define SRE_BMU_CPU_ADD_STATUS_H_REG               (SRE_BMU_REG_BASE_ADDR + 0x19C)               /* CPU ADD BMU״̬�Ĵ���32~63 ����CPU */
#define SRE_BMU_CPU_ADD_ERROR_DATA0_REG            (SRE_BMU_REG_BASE_ADDR + 0x1A0)               /* CPU ADD ��������ݼĴ�����λ */
#define SRE_BMU_CPU_ADD_ERROR_DATA1_REG            (SRE_BMU_REG_BASE_ADDR + 0x1A4)               /* CPU ADD ��������ݼĴ�����λ */
#define SRE_BMU_BITMAP_ECC_1B_CNT_REG              (SRE_BMU_REG_BASE_ADDR + 0x1A8)               /* BMU bitmap SRAM ecc 1bit����ͳ�Ƽ����� */
#define SRE_BMU_PTRNUM_P_0_REG                     (SRE_BMU_REG_BASE_ADDR + 0x200)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_1_REG                     (SRE_BMU_REG_BASE_ADDR + 0x204)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_2_REG                     (SRE_BMU_REG_BASE_ADDR + 0x208)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_3_REG                     (SRE_BMU_REG_BASE_ADDR + 0x20C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_4_REG                     (SRE_BMU_REG_BASE_ADDR + 0x210)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_5_REG                     (SRE_BMU_REG_BASE_ADDR + 0x214)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_6_REG                     (SRE_BMU_REG_BASE_ADDR + 0x218)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_7_REG                     (SRE_BMU_REG_BASE_ADDR + 0x21C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_8_REG                     (SRE_BMU_REG_BASE_ADDR + 0x220)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_9_REG                     (SRE_BMU_REG_BASE_ADDR + 0x224)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_10_REG                    (SRE_BMU_REG_BASE_ADDR + 0x228)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_11_REG                    (SRE_BMU_REG_BASE_ADDR + 0x22C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_12_REG                    (SRE_BMU_REG_BASE_ADDR + 0x230)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_13_REG                    (SRE_BMU_REG_BASE_ADDR + 0x234)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_14_REG                    (SRE_BMU_REG_BASE_ADDR + 0x238)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_15_REG                    (SRE_BMU_REG_BASE_ADDR + 0x23C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_16_REG                    (SRE_BMU_REG_BASE_ADDR + 0x240)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_17_REG                    (SRE_BMU_REG_BASE_ADDR + 0x244)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_18_REG                    (SRE_BMU_REG_BASE_ADDR + 0x248)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_19_REG                    (SRE_BMU_REG_BASE_ADDR + 0x24C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_20_REG                    (SRE_BMU_REG_BASE_ADDR + 0x250)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_21_REG                    (SRE_BMU_REG_BASE_ADDR + 0x254)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_22_REG                    (SRE_BMU_REG_BASE_ADDR + 0x258)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_23_REG                    (SRE_BMU_REG_BASE_ADDR + 0x25C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_24_REG                    (SRE_BMU_REG_BASE_ADDR + 0x260)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_25_REG                    (SRE_BMU_REG_BASE_ADDR + 0x264)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_26_REG                    (SRE_BMU_REG_BASE_ADDR + 0x268)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_27_REG                    (SRE_BMU_REG_BASE_ADDR + 0x26C)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_28_REG                    (SRE_BMU_REG_BASE_ADDR + 0x270)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_29_REG                    (SRE_BMU_REG_BASE_ADDR + 0x274)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_30_REG                    (SRE_BMU_REG_BASE_ADDR + 0x278)               /* BMU pool�ĵ�ַָ������� */
#define SRE_BMU_PTRNUM_P_31_REG                    (SRE_BMU_REG_BASE_ADDR + 0x27C)               /* BMU pool�ĵ�ַָ������� */

#define SRE_BMU_P0_OUT_ADDR_REG                    (SRE_BMU_REG_BASE_ADDR + 0x280)
#define SRE_BMU_P0_OUT_CUR_ADDR_REG                (SRE_BMU_REG_BASE_ADDR + 0x300)
#define SRE_BMU_P0_OUT_LEN_REG                     (SRE_BMU_REG_BASE_ADDR + 0x380)
#define SRE_BMU_BOUND_ERR_ADDR_REG                 (SRE_BMU_REG_BASE_ADDR + 0x400)
#define SRE_BMU_IN_EMTPY_STA_ADDR_REG              (SRE_BMU_REG_BASE_ADDR + 0x404)
#define SRE_BMU_IN_FULL_STA_ADDR_REG               (SRE_BMU_REG_BASE_ADDR + 0x408)
#define SRE_BMU_ALL_EMTPY_STA_ADDR_REG             (SRE_BMU_REG_BASE_ADDR + 0x40c)
#define SRE_BMU_ALL_FULL_STA_ADDR_REG              (SRE_BMU_REG_BASE_ADDR + 0x410)
#define SRE_BMU_ALMST_FULL_STA_ADDR_REG            (SRE_BMU_REG_BASE_ADDR + 0x414)


#define SRE_BMU_BUS_ERR_PID_REG                    (SRE_BMU_REG_BASE_ADDR + 0x418)               /* ��ǰ���߳��ִ����pool ID */
#define SRE_BMU_PERR_SRAM_ADDR_REG                 (SRE_BMU_REG_BASE_ADDR + 0x41C)               /* ��ǰSRAMECCУ��2bit����ָ�� */
#define SRE_BMU_PERR_LDST_ADDR_REG                 (SRE_BMU_REG_BASE_ADDR + 0x420)

#define SRE_BMU_ECC_PID_REG                        (SRE_BMU_REG_BASE_ADDR + 0x424)               /* Peri����pool ID */
#define SRE_BMU_TEST_REG                           (SRE_BMU_REG_BASE_ADDR + 0x428)               /* BMU�ڲ�״̬�Ĵ��� */
#define SRE_BMU_CFG_DLY_REG                        (SRE_BMU_REG_BASE_ADDR + 0x42C)               /* BMU�������/д�ӳټĴ��� */
#define SRE_BMU_VMID_CFG_REG                       (SRE_BMU_REG_BASE_ADDR + 0x430)               /* BMU Master����MDDRC��VMID������ */
#define SRE_BMU_BOUND_ERR_STS_REG                  (SRE_BMU_REG_BASE_ADDR + 0x434)               /* BMU �ͷŻ����ַ�߽����״̬�Ĵ��� */
#define SRE_BMU_BOUND_P_0_REG                      (SRE_BMU_REG_BASE_ADDR + 0x438)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_1_REG                      (SRE_BMU_REG_BASE_ADDR + 0x43C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_2_REG                      (SRE_BMU_REG_BASE_ADDR + 0x440)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_3_REG                      (SRE_BMU_REG_BASE_ADDR + 0x444)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_4_REG                      (SRE_BMU_REG_BASE_ADDR + 0x448)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_5_REG                      (SRE_BMU_REG_BASE_ADDR + 0x44C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_6_REG                      (SRE_BMU_REG_BASE_ADDR + 0x450)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_7_REG                      (SRE_BMU_REG_BASE_ADDR + 0x454)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_8_REG                      (SRE_BMU_REG_BASE_ADDR + 0x458)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_9_REG                      (SRE_BMU_REG_BASE_ADDR + 0x45C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_10_REG                     (SRE_BMU_REG_BASE_ADDR + 0x460)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_11_REG                     (SRE_BMU_REG_BASE_ADDR + 0x464)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_12_REG                     (SRE_BMU_REG_BASE_ADDR + 0x468)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_13_REG                     (SRE_BMU_REG_BASE_ADDR + 0x46C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_14_REG                     (SRE_BMU_REG_BASE_ADDR + 0x470)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_15_REG                     (SRE_BMU_REG_BASE_ADDR + 0x474)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_16_REG                     (SRE_BMU_REG_BASE_ADDR + 0x478)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_17_REG                     (SRE_BMU_REG_BASE_ADDR + 0x47C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_18_REG                     (SRE_BMU_REG_BASE_ADDR + 0x480)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_19_REG                     (SRE_BMU_REG_BASE_ADDR + 0x484)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_20_REG                     (SRE_BMU_REG_BASE_ADDR + 0x488)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_21_REG                     (SRE_BMU_REG_BASE_ADDR + 0x48C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_22_REG                     (SRE_BMU_REG_BASE_ADDR + 0x490)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_23_REG                     (SRE_BMU_REG_BASE_ADDR + 0x494)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_24_REG                     (SRE_BMU_REG_BASE_ADDR + 0x498)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_25_REG                     (SRE_BMU_REG_BASE_ADDR + 0x49C)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_26_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4A0)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_27_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4A4)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_28_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4A8)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_29_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4AC)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_30_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4B0)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BOUND_P_31_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4B4)               /* BMU Pool�ͷŻ����ַ�߽�Ĵ��� */
#define SRE_BMU_BITMAP_BADDR_P0_REG                (SRE_BMU_REG_BASE_ADDR + 0x500)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P1_REG                (SRE_BMU_REG_BASE_ADDR + 0x504)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P2_REG                (SRE_BMU_REG_BASE_ADDR + 0x508)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P3_REG                (SRE_BMU_REG_BASE_ADDR + 0x50C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P4_REG                (SRE_BMU_REG_BASE_ADDR + 0x510)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P5_REG                (SRE_BMU_REG_BASE_ADDR + 0x514)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P6_REG                (SRE_BMU_REG_BASE_ADDR + 0x518)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P7_REG                (SRE_BMU_REG_BASE_ADDR + 0x51C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P8_REG                (SRE_BMU_REG_BASE_ADDR + 0x520)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P9_REG                (SRE_BMU_REG_BASE_ADDR + 0x524)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P10_REG               (SRE_BMU_REG_BASE_ADDR + 0x528)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P11_REG               (SRE_BMU_REG_BASE_ADDR + 0x52C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P12_REG               (SRE_BMU_REG_BASE_ADDR + 0x530)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P13_REG               (SRE_BMU_REG_BASE_ADDR + 0x534)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P14_REG               (SRE_BMU_REG_BASE_ADDR + 0x538)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P15_REG               (SRE_BMU_REG_BASE_ADDR + 0x53C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P16_REG               (SRE_BMU_REG_BASE_ADDR + 0x540)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P17_REG               (SRE_BMU_REG_BASE_ADDR + 0x544)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P18_REG               (SRE_BMU_REG_BASE_ADDR + 0x548)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P19_REG               (SRE_BMU_REG_BASE_ADDR + 0x54C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P20_REG               (SRE_BMU_REG_BASE_ADDR + 0x550)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P21_REG               (SRE_BMU_REG_BASE_ADDR + 0x554)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P22_REG               (SRE_BMU_REG_BASE_ADDR + 0x558)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P23_REG               (SRE_BMU_REG_BASE_ADDR + 0x55C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P24_REG               (SRE_BMU_REG_BASE_ADDR + 0x560)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P25_REG               (SRE_BMU_REG_BASE_ADDR + 0x564)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P26_REG               (SRE_BMU_REG_BASE_ADDR + 0x568)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P27_REG               (SRE_BMU_REG_BASE_ADDR + 0x56C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P28_REG               (SRE_BMU_REG_BASE_ADDR + 0x570)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P29_REG               (SRE_BMU_REG_BASE_ADDR + 0x574)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P30_REG               (SRE_BMU_REG_BASE_ADDR + 0x578)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_BADDR_P31_REG               (SRE_BMU_REG_BASE_ADDR + 0x57C)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_WIDTH_REG                   (SRE_BMU_REG_BASE_ADDR + 0x580)               /* BMU bitmap��SRAM�и���Pool����ʼ��ַ */
#define SRE_BMU_BITMAP_ST_ERR_INFO_REG             (SRE_BMU_REG_BASE_ADDR + 0x584)               /* BMU bitmap�ظ��ͷŴ���״̬�Ĵ��� */
#define SRE_BMU_BITMAP_LD_ERR_INFO_REG             (SRE_BMU_REG_BASE_ADDR + 0x588)               /* BMU bitmap�ظ��������״̬�Ĵ��� */
#define SRE_BMU_BITMAP_ERR_STS_REG                 (SRE_BMU_REG_BASE_ADDR + 0x58C)               /* BMU bitmap�ظ��������״̬�Ĵ��� */
#define SRE_BMU_PPE_QOS_EN_REG                     (SRE_BMU_REG_BASE_ADDR + 0x590)               /* �͸�PPE��QOSˮ�߲����߼�ʹ�ܼĴ��� */
#define SRE_BMU_CPU_ID_H12_REG                     (SRE_BMU_REG_BASE_ADDR + 0x594)               /* CPU��Master ID ��12λ */
#define SRE_BMU_PPE_QOS_WL_0_REG                   (SRE_BMU_REG_BASE_ADDR + 0x800)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_1_REG                   (SRE_BMU_REG_BASE_ADDR + 0x804)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_2_REG                   (SRE_BMU_REG_BASE_ADDR + 0x808)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_3_REG                   (SRE_BMU_REG_BASE_ADDR + 0x80C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_4_REG                   (SRE_BMU_REG_BASE_ADDR + 0x810)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_5_REG                   (SRE_BMU_REG_BASE_ADDR + 0x814)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_6_REG                   (SRE_BMU_REG_BASE_ADDR + 0x818)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_7_REG                   (SRE_BMU_REG_BASE_ADDR + 0x81C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_8_REG                   (SRE_BMU_REG_BASE_ADDR + 0x820)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_9_REG                   (SRE_BMU_REG_BASE_ADDR + 0x824)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_10_REG                  (SRE_BMU_REG_BASE_ADDR + 0x828)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_11_REG                  (SRE_BMU_REG_BASE_ADDR + 0x82C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_12_REG                  (SRE_BMU_REG_BASE_ADDR + 0x830)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_13_REG                  (SRE_BMU_REG_BASE_ADDR + 0x834)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_14_REG                  (SRE_BMU_REG_BASE_ADDR + 0x838)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_15_REG                  (SRE_BMU_REG_BASE_ADDR + 0x83C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_16_REG                  (SRE_BMU_REG_BASE_ADDR + 0x840)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_17_REG                  (SRE_BMU_REG_BASE_ADDR + 0x844)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_18_REG                  (SRE_BMU_REG_BASE_ADDR + 0x848)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_19_REG                  (SRE_BMU_REG_BASE_ADDR + 0x84C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_20_REG                  (SRE_BMU_REG_BASE_ADDR + 0x850)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_21_REG                  (SRE_BMU_REG_BASE_ADDR + 0x854)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_22_REG                  (SRE_BMU_REG_BASE_ADDR + 0x858)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_23_REG                  (SRE_BMU_REG_BASE_ADDR + 0x85C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_24_REG                  (SRE_BMU_REG_BASE_ADDR + 0x860)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_25_REG                  (SRE_BMU_REG_BASE_ADDR + 0x864)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_26_REG                  (SRE_BMU_REG_BASE_ADDR + 0x868)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_27_REG                  (SRE_BMU_REG_BASE_ADDR + 0x86C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_28_REG                  (SRE_BMU_REG_BASE_ADDR + 0x870)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_29_REG                  (SRE_BMU_REG_BASE_ADDR + 0x874)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_30_REG                  (SRE_BMU_REG_BASE_ADDR + 0x878)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_31_REG                  (SRE_BMU_REG_BASE_ADDR + 0x87C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_32_REG                  (SRE_BMU_REG_BASE_ADDR + 0x880)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_33_REG                  (SRE_BMU_REG_BASE_ADDR + 0x884)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_34_REG                  (SRE_BMU_REG_BASE_ADDR + 0x888)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_35_REG                  (SRE_BMU_REG_BASE_ADDR + 0x88C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_36_REG                  (SRE_BMU_REG_BASE_ADDR + 0x890)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_37_REG                  (SRE_BMU_REG_BASE_ADDR + 0x894)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_38_REG                  (SRE_BMU_REG_BASE_ADDR + 0x898)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_39_REG                  (SRE_BMU_REG_BASE_ADDR + 0x89C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_40_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8A0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_41_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8A4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_42_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8A8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_43_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8AC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_44_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8B0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_45_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8B4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_46_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8B8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_47_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8BC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_48_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8C0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_49_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8C4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_50_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8C8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_51_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8CC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_52_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8D0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_53_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8D4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_54_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8D8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_55_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8DC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_56_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8E0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_57_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8E4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_58_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8E8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_59_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8EC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_60_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8F0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_61_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8F4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_62_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8F8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_63_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8FC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_64_REG                  (SRE_BMU_REG_BASE_ADDR + 0x900)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_65_REG                  (SRE_BMU_REG_BASE_ADDR + 0x904)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_66_REG                  (SRE_BMU_REG_BASE_ADDR + 0x908)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_67_REG                  (SRE_BMU_REG_BASE_ADDR + 0x90C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_68_REG                  (SRE_BMU_REG_BASE_ADDR + 0x910)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_69_REG                  (SRE_BMU_REG_BASE_ADDR + 0x914)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_70_REG                  (SRE_BMU_REG_BASE_ADDR + 0x918)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_71_REG                  (SRE_BMU_REG_BASE_ADDR + 0x91C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_72_REG                  (SRE_BMU_REG_BASE_ADDR + 0x920)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_73_REG                  (SRE_BMU_REG_BASE_ADDR + 0x924)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_74_REG                  (SRE_BMU_REG_BASE_ADDR + 0x928)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_75_REG                  (SRE_BMU_REG_BASE_ADDR + 0x92C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_76_REG                  (SRE_BMU_REG_BASE_ADDR + 0x930)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_77_REG                  (SRE_BMU_REG_BASE_ADDR + 0x934)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_78_REG                  (SRE_BMU_REG_BASE_ADDR + 0x938)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_79_REG                  (SRE_BMU_REG_BASE_ADDR + 0x93C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_80_REG                  (SRE_BMU_REG_BASE_ADDR + 0x940)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_81_REG                  (SRE_BMU_REG_BASE_ADDR + 0x944)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_82_REG                  (SRE_BMU_REG_BASE_ADDR + 0x948)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_83_REG                  (SRE_BMU_REG_BASE_ADDR + 0x94C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_84_REG                  (SRE_BMU_REG_BASE_ADDR + 0x950)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_85_REG                  (SRE_BMU_REG_BASE_ADDR + 0x954)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_86_REG                  (SRE_BMU_REG_BASE_ADDR + 0x958)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_87_REG                  (SRE_BMU_REG_BASE_ADDR + 0x95C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_88_REG                  (SRE_BMU_REG_BASE_ADDR + 0x960)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_89_REG                  (SRE_BMU_REG_BASE_ADDR + 0x964)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_90_REG                  (SRE_BMU_REG_BASE_ADDR + 0x968)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_91_REG                  (SRE_BMU_REG_BASE_ADDR + 0x96C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_92_REG                  (SRE_BMU_REG_BASE_ADDR + 0x970)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_93_REG                  (SRE_BMU_REG_BASE_ADDR + 0x974)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_94_REG                  (SRE_BMU_REG_BASE_ADDR + 0x978)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_95_REG                  (SRE_BMU_REG_BASE_ADDR + 0x97C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_96_REG                  (SRE_BMU_REG_BASE_ADDR + 0x980)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_97_REG                  (SRE_BMU_REG_BASE_ADDR + 0x984)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_98_REG                  (SRE_BMU_REG_BASE_ADDR + 0x988)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_99_REG                  (SRE_BMU_REG_BASE_ADDR + 0x98C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_100_REG                 (SRE_BMU_REG_BASE_ADDR + 0x990)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_101_REG                 (SRE_BMU_REG_BASE_ADDR + 0x994)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_102_REG                 (SRE_BMU_REG_BASE_ADDR + 0x998)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_103_REG                 (SRE_BMU_REG_BASE_ADDR + 0x99C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_104_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9A0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_105_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9A4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_106_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9A8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_107_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9AC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_108_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9B0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_109_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9B4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_110_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9B8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_111_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9BC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_112_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9C0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_113_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9C4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_114_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9C8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_115_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9CC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_116_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9D0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_117_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9D4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_118_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9D8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_119_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9DC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_120_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9E0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_121_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9E4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_122_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9E8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_123_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9EC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_124_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9F0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_125_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9F4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_126_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9F8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_127_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9FC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_128_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA00)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_129_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA04)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_130_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA08)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_131_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA0C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_132_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA10)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_133_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA14)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_134_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA18)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_135_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA1C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_136_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA20)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_137_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA24)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_138_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA28)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_139_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA2C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_140_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA30)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_141_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA34)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_142_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA38)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_143_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA3C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_144_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA40)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_145_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA44)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_146_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA48)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_147_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA4C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_148_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA50)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_149_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA54)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_150_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA58)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_151_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA5C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_152_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA60)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_153_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA64)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_154_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA68)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_155_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA6C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_156_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA70)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_157_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA74)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_158_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA78)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_159_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA7C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_160_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA80)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_161_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA84)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_162_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA88)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_163_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA8C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_164_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA90)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_165_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA94)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_166_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA98)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_167_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA9C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_168_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAA0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_169_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAA4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_170_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAA8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_171_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAAC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_172_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAB0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_173_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAB4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_174_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAB8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_175_REG                 (SRE_BMU_REG_BASE_ADDR + 0xABC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_176_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAC0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_177_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAC4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_178_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAC8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_179_REG                 (SRE_BMU_REG_BASE_ADDR + 0xACC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_180_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAD0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_181_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAD4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_182_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAD8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_183_REG                 (SRE_BMU_REG_BASE_ADDR + 0xADC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_184_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAE0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_185_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAE4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_186_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAE8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_187_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAEC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_188_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAF0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_189_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAF4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_190_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAF8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_191_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAFC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_192_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB00)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_193_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB04)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_194_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB08)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_195_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB0C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_196_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB10)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_197_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB14)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_198_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB18)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_199_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB1C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_200_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB20)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_201_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB24)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_202_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB28)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_203_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB2C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_204_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB30)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_205_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB34)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_206_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB38)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_207_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB3C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_208_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB40)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_209_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB44)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_210_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB48)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_211_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB4C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_212_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB50)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_213_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB54)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_214_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB58)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_215_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB5C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_216_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB60)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_217_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB64)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_218_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB68)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_219_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB6C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_220_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB70)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_221_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB74)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_222_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB78)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_223_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB7C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_224_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB80)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_225_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB84)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_226_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB88)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_227_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB8C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_228_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB90)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_229_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB94)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_230_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB98)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_231_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB9C)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_232_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBA0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_233_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBA4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_234_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBA8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_235_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBAC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_236_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBB0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_237_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBB4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_238_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBB8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_239_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBBC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_240_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBC0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_241_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBC4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_242_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBC8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_243_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBCC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_244_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBD0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_245_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBD4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_246_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBD8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_247_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBDC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_248_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBE0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_249_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBE4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_250_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBE8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_251_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBEC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_252_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBF0)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_253_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBF4)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_254_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBF8)               /* �͸�PPE��QOSˮ�߼Ĵ����� */
#define SRE_BMU_PPE_QOS_WL_255_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBFC)               /* �͸�PPE��QOSˮ�߼Ĵ����� */


/* Tring��ص�IO��ַ�궨�� */
#define SRE_TRING_REG_BASE_ADDR           (0x10840000)

#define SRE_TIM_CTR_ADDR                   SRE_TRING_REG_BASE_ADDR
#define SRE_TIM_ERR_INT_ADDR              (SRE_TRING_REG_BASE_ADDR +0x4)
#define SRE_TIM_ERR_MASK_ADDR             (SRE_TRING_REG_BASE_ADDR +0x8)
#define SRE_TIM_RING0_BASE_ADDR           (SRE_TRING_REG_BASE_ADDR +0x10)
#define SRE_TIM_RING0_BSIZE_ADDR          (SRE_TRING_REG_BASE_ADDR +0x14)
#define SRE_TIM_RING0_INTERVAL_ADDR       (SRE_TRING_REG_BASE_ADDR +0x18)
#define SRE_TIM_RING0_CSIZE_ADDR          (SRE_TRING_REG_BASE_ADDR +0x1c)
#define SRE_TIM_RING0_POE_ADDR            (SRE_TRING_REG_BASE_ADDR +0x20)
#define SRE_TIM_RING0_POOL_ADDR           (SRE_TRING_REG_BASE_ADDR +0x24)
#define SRE_TIM_RING0_COUNT_ADDR          (SRE_TRING_REG_BASE_ADDR +0x28)
#define SRE_TIM_RING0_BUCKET_ADDR         (SRE_TRING_REG_BASE_ADDR +0x2c)
#define SRE_TIM_RING0_WR_POE_TIMEOUT      (SRE_TRING_REG_BASE_ADDR +0x30)
#define SRE_TIM_RING0_WR_BMU_TIMEOUT      (SRE_TRING_REG_BASE_ADDR +0x34)
#define SRE_TIM_RING0_WR_TIMEOUT_ST       (SRE_TRING_REG_BASE_ADDR +0x38)
#define SRE_TIM_RING0_REL_CHUNK_NUM       (SRE_TRING_REG_BASE_ADDR +0x3C)
#define SRE_TIMEBASE0_INIT_L_ADDR         (SRE_TRING_REG_BASE_ADDR + 0x190)
#define SRE_TIMEBASE0_INIT_H_ADDR         (SRE_TRING_REG_BASE_ADDR + 0x194)
#define SRE_TIMEBASE0_CNT_L_ADDR          (SRE_TRING_REG_BASE_ADDR + 0x198)
#define SRE_TIMEBASE0_CNT_H_ADDR          (SRE_TRING_REG_BASE_ADDR + 0x19C)

#define SRE_MDIO_BASE_ADDR          (0x18000000 + 0x80000000)

/******************************************************************************/
/*                      PhosphorV600 MAC_CORE �Ĵ�������                      */
/******************************************************************************/
#if 0     /* z00202052 */
#define SRE_GMAC_BASE_ADDR                                 (0x12800000)
#else
#define SRE_GMAC_BASE_ADDR                                 (0xe2800000)
#endif    /* z00202052 */


#define SRE_GMAC_DUPLEX_TYPE_REG                           (0x0008UL)                          /*ȫ˫����˫��ģʽ�Ĵ��� */
#define SRE_GMAC_FD_FC_TYPE_REG                            (0x000CUL)                          /*FD_FC_TYPEΪ����֡������Ĵ�����*/
#define SRE_GMAC_FC_TX_TIMER_REG                           (0x001CUL)                          /*FC_TX_TIMERΪ����ʱ������Ĵ�����*/
#define SRE_GMAC_FD_FC_ADDR_LOW_REG                        (0x0020UL)                          /*FD_FC_ADDR_LOWΪ����֡Ŀ�ĵ�ַ�Ĵ���1��*/
#define SRE_GMAC_FD_FC_ADDR_HIGH_REG                       (0x0024UL)                          /*FD_FC_ADDR_HIGHΪ����֡Ŀ�ĵ�ַ�Ĵ���2�� */
#define SRE_GMAC_IPG_TX_TIMER_REG                          (0x0030UL)                          /*IPG_TX_TIMERΪ����֡��϶�Ĵ�����             */
#define SRE_GMAC_PAUSE_THR_REG                             (0x0038UL)                          /*PAUSE_THRΪ��������֡��϶�Ĵ�����         */
#define SRE_GMAC_MAX_FRM_SIZE_REG                          (0x003CUL)                          /*MAX_FRM_SIZEΪ���֡���Ĵ�����                    */
#define SRE_GMAC_PORT_MODE_REG                             (0x0040UL)                          /*PORT_MODEΪ�˿�״̬�Ĵ�����                          */
#define SRE_GMAC_PORT_EN_REG                               (0x0044UL)                          /*PORT_ENΪͨ��ʹ�ܼĴ�����                                   */
#define SRE_GMAC_PAUSE_EN_REG                              (0x0048UL)                          /*PAUSE_ENΪ����ʹ�ܼĴ�����                                */
#define SRE_GMAC_SHORT_RUNTS_THR_REG                       (0x0050UL)                          /*SHORT_RUNTS_THRΪ����֡���޼Ĵ����� */
#define SRE_GMAC_AN_NEG_STATE_REG                          (0x0058UL)                          /*SGMII��Э��״̬�Ĵ���                                    */
#define SRE_GMAC_TX_LOCAL_PAGE_REG                         (0x005CUL)                          /*��Э�̱������üĴ���                                  */
#define SRE_GMAC_TRANSMIT_CONTROL_REG                      (0x0060UL)                          /*TRANSMIT_CONTROLΪ�������üĴ�����     */
#define SRE_GMAC_REC_FILT_CONTROL_REG                      (0x0064UL)                          /*REC_FILT_CONTROLΪ����֡���˿��ƼĴ����� */
#define SRE_GMAC_PTP_CONFIG_REG                            (0x0074UL)                          /*���ͷ���IPV6��1588����CHCECKSUMʹ�ܺ�1588�����������λ��0ʹ�� */
#define SRE_GMAC_RX_OCTETS_TOTAL_OK_REG                    (0x0080UL)                          /*RX_OCTETS_TOTAL_OKΪ������Ч֡���ֽ�ͳ�ƼĴ�����*/
#define SRE_GMAC_RX_OCTETS_BAD_REG                         (0x0084UL)                          /*RX_OCTETS_BADΪ���մ���֡�ֽ�ͳ�ƼĴ�����                     */
#define SRE_GMAC_RX_UC_PKTS_REG                            (0x0088UL)                          /*RX_UC_PKTSΪMAC���յ���֡��ͳ�ƼĴ�����                              */
#define SRE_GMAC_RX_MC_PKTS_REG                            (0x008CUL)                          /*RX_MC_PKTSΪ���նಥ֡��ͳ�ƼĴ�����                                     */
#define SRE_GMAC_RX_BC_PKTS_REG                            (0x0090UL)                          /*RX_BC_PKTSΪ���յĹ㲥֡��ͳ�ƼĴ�����                                 */
#define SRE_GMAC_RX_PKTS_64OCTETS_REG                      (0x0094UL)                          /*RX_PKTS_64OCTETSΪ���յ�֡��Ϊ64byte��֡��ͳ�ƼĴ�����*/
#define SRE_GMAC_RX_PKTS_65TO127OCTETS_REG                 (0x0098UL)                          /*RX_PKTS_65TO127OCTETSΪ���յ�֡��Ϊ65��127byte��֡��ͳ�ƼĴ����� */
#define SRE_GMAC_RX_PKTS_128TO255OCTETS_REG                (0x009CUL)                          /*RX_PKTS_128TO255OCTETSΪ���յ�֡��Ϊ128��255byte��֡��ͳ�ƼĴ����� */
#define SRE_GMAC_RX_PKTS_255TO511OCTETS_REG                (0x00A0UL)                          /*RX_PKTS_255TO511OCTETSΪ���յ�֡��Ϊ256��511byte��֡��ͳ�ƼĴ�����  */
#define SRE_GMAC_RX_PKTS_512TO1023OCTETS_REG               (0x00A4UL)                          /*RX_PKTS_512TO1023OCTETSΪ���յ�֡��Ϊ512��1023byte��֡��ͳ�ƼĴ����� */
#define SRE_GMAC_RX_PKTS_1024TO1518OCTETS_REG              (0x00A8UL)                          /*RX_PKTS_1024TO1518OCTETSΪ����֡��Ϊ1024��1518byte��֡��ͳ�ƼĴ�����  */
#define SRE_GMAC_RX_PKTS_1519TOMAXOCTETS_REG               (0x00ACUL)                          /*RX_PKTS_1519TOMAXOCTETSΪ���յ�֡��Ϊ1519�����byte��֡��ͳ�ƼĴ����� */
#define SRE_GMAC_RX_FCS_ERRORS_REG                         (0x00B0UL)                          /*RX_FCS_ERRORSΪ����CRC��������֡��ͳ�ƼĴ�����                                        */
#define SRE_GMAC_RX_TAGGED_REG                             (0x00B4UL)                          /*RX_TAGGEDΪ���մ�TAG��֡ͳ�ƼĴ�����                                                    */
#define SRE_GMAC_RX_DATA_ERR_REG                           (0x00B8UL)                          /*RX_DATA_ERRΪ�������ݴ���֡ͳ�ƼĴ�����                                                 */
#define SRE_GMAC_RX_ALIGN_ERRORS_REG                       (0x00BCUL)                          /*RX_ALIGN_ERRORSΪ�������ݷ��ֽڶ������֡ͳ�ƼĴ�����                                  */
#define SRE_GMAC_RX_LONG_ERRORS_REG                        (0x00C0UL)                          /*RX_LONG_ERRORSΪ����֡�������������󳤶ȵ�֡��ͳ�ƼĴ���1��                        */
#define SRE_GMAC_RX_JABBER_ERRORS_REG                      (0x00C4UL)                          /*RX_JABBER_ERRORSΪ����֡�������������󳤶ȵ�֡��ͳ�ƼĴ���2��                      */
#define SRE_GMAC_RX_PAUSE_MACCONTROL_FRAMCOUNTER_REG       (0x00C8UL)                          /*RX_PAUSE_MACCONTROL_FRAMCOUNTERΪ���յ�������֡��ͳ�ƼĴ�����                          */
#define SRE_GMAC_RX_UNKNOWN_MACCONTROL_FRAMCOUNTER_REG     (0x00CCUL)                          /*RX_UNKNOWN_MACCONTROL_FRAMCOUNTERΪMAC���յ��ķ����ؿ���֡��ͳ�ƼĴ���                */
#define SRE_GMAC_RX_VERY_LONG_ERR_CNT_REG                  (0x00D0UL)                          /*RX_VERY_LONG_ERR_CNTΪ���յ�����֡ͳ�ƼĴ�����                                          */
#define SRE_GMAC_RX_RUNT_ERR_CNT_REG                       (0x00D4UL)                          /*RX_RUNT_ERR_CNTΪ���յ�֡��С��64byte���ڵ���short_runts_thr �ֽڵ�֡���Ĵ�����        */
#define SRE_GMAC_RX_SHORT_ERR_CNT_REG                      (0x00D8UL)                          /*RX_SHORT_ERR_CNTΪ����֡��С��short_runts_thr�ֽڵ�֡��ͳ�ƼĴ�����                    */
#define SRE_GMAC_RX_FILT_PKT_CNT_REG                       (0x00E8UL)                          /*���շ�����˵��İ�ͳ��                                                                */
#define SRE_GMAC_RX_OCTETS_TOTAL_FILT_REG                  (0x00ECUL)                          /*���շ�����˵����ֽ�ͳ��                                                              */
#define SRE_GMAC_OCTETS_TRANSMITTED_OK_REG                 (0x0100UL)                          /*OCTETS_TRANSMITTED_OKΪ���ͳɹ��ĺð��ֽ���ͳ�ƼĴ�����                              */
#define SRE_GMAC_OCTETS_TRANSMITTED_BAD_REG                (0x0104UL)                          /*OCTETS_TRANSMITTED_BADΪ���ͳɹ��Ļ����ֽ���ͳ�ƼĴ�����                             */
#define SRE_GMAC_TX_UC_PKTS_REG                            (0x0108UL)                          /*TX_UC_PKTSΪ���͵ĵ���֡��ͳ�ƼĴ�����                                                 */
#define SRE_GMAC_TX_MC_PKTS_REG                            (0x010CUL)                          /*TX_MC_PKTSΪ���͵Ķಥ֡��ͳ�ƼĴ�����                                                 */
#define SRE_GMAC_TX_BC_PKTS_REG                            (0x0110UL)                          /*TX_BC_PKTSΪ���͵Ĺ㲥֡��ͳ�ƼĴ�����                                                 */
#define SRE_GMAC_TX_PKTS_64OCTETS_REG                      (0x0114UL)                          /*TX_PKTS_64OCTETSΪ����֡��Ϊ64byte��֡��ͳ�ƼĴ�����                                    */
#define SRE_GMAC_TX_PKTS_65TO127OCTETS_REG                 (0x0118UL)                          /*TX_PKTS_65TO127OCTETSΪ����֡��Ϊ65��127byte��֡��ͳ�ƼĴ�����                          */
#define SRE_GMAC_TX_PKTS_128TO255OCTETS_REG                (0x011CUL)                          /*TX_PKTS_128TO255OCTETSΪ����֡��Ϊ128��255byte��֡��ͳ�ƼĴ�����                        */
#define SRE_GMAC_TX_PKTS_255TO511OCTETS_REG                (0x0120UL)                          /*TX_PKTS_255TO511OCTETSΪ����֡��Ϊ256��511byte��֡��ͳ�ƼĴ�����                        */
#define SRE_GMAC_TX_PKTS_512TO1023OCTETS_REG               (0x0124UL)                          /*TX_PKTS_512TO1023OCTETSΪ����֡��Ϊ512��1023byte�ڵ�֡��ͳ�ƼĴ�����                    */
#define SRE_GMAC_TX_PKTS_1024TO1518OCTETS_REG              (0x0128UL)                          /*TX_PKTS_1024TO1518OCTETSΪ����֡��Ϊ1024��1518byte��֡��ͳ�ƼĴ�����                    */
#define SRE_GMAC_TX_PKTS_1519TOMAXOCTETS_REG               (0x012CUL)                          /*TX_PKTS_1519TOMAXOCTETSΪ����֡������1519byte��֡��ͳ�ƼĴ�����                         */
#define SRE_GMAC_TX_EXCESSIVE_LENGTH_DROP_REG              (0x014CUL)                          /*TX_EXCESSIVE_LENGTH_DROPΪ�����趨�����֡�����·���ʧ�ܴ���ͳ�ƼĴ���     ��       */
#define SRE_GMAC_TX_UNDERRUN_REG                           (0x0150UL)                          /*TX_UNDERRUNΪ֡���͹����з����ڲ���������·���ʧ�ܵĴ���ͳ�ơ�                     */
#define SRE_GMAC_TX_TAGGED_REG                             (0x0154UL)                          /*TX_TAGGEDΪ���͵�VLAN֡��ͳ�ƼĴ�����                                                  */
#define SRE_GMAC_TX_CRC_ERROR_REG                          (0x0158UL)                          /*TX_CRC_ERRORΪ����֡����ȷCRC�����֡��ͳ�ƼĴ�����                                   */
#define SRE_GMAC_TX_PAUSE_FRAMES_REG                       (0x015CUL)                          /*TX_PAUSE_FRAMESΪ����PAUSE֡��ͳ�ƼĴ�����                                             */
#define SRE_GMAC_LED_MOD_REG                               (0x016CUL)                          /*LED_MODΪ���ģʽ���ƼĴ�����                                                         */
#define SRE_GMAC_TS_DLY_ESTI_REG                           (0x0170UL)                          /*����������ʱֵ                                                                         */
#define SRE_GMAC_CF_ASYM_CRT_HIGH_REG                      (0x0174UL)                          /*�ǶԳ���ʱ��32����                                                                     */
#define SRE_GMAC_CF_ASYM_CRT_LOW_REG                       (0x0178UL)                          /*�ǶԳ���ʱ��32����                                                                     */
#define SRE_GMAC_TIMSTP_INGRESS_REG                        (0x017CUL)                          /*����������ʱֵ                                                                         */
#define SRE_GMAC_LINE_LOOP_BACK_REG                        (0x01A8UL)                          /*LINE_LOOP_BACKΪMAC��·�໷�ؼĴ�����                                                  */
#define SRE_GMAC_CF_CRC_STRIP_REG                          (0x01B0UL)                          /*CF_CRC_STRIPΪCRC����ʹ�ܼĴ�����                                                      */
#define SRE_GMAC_MODE_CHANGE_EN_REG                        (0x01B4UL)                          /*MODE_CHANGE_ENΪ�˿�ģʽ�ı�ʹ�ܼĴ�����                                              */
#define SRE_GMAC_SIXTEEN_BIT_CNTR_REG                      (0x01CCUL)                          /*��Э������ʱ��Ĵ���                                                                   */
#define SRE_GMAC_LD_LINK_COUNTER_REG                       (0x01D0UL)                          /*��Э������ʱ����¼Ĵ���                                                              */
#define SRE_GMAC_LOOP_REG                                  (0x01DCUL)                          /*LOOP_REGΪ���ز���Ĵ�����                                                             */
#define SRE_GMAC_RECV_CONTROL_REG                          (0x01E0UL)                          /*RECV_CONTROLΪ���տ��ƼĴ�����                                                        */
#define SRE_GMAC_VLAN_CODE_REG                             (0x01E8UL)                          /*VLAN_CODEΪVLAN Code�Ĵ�����                                                            */
#define SRE_GMAC_RX_OVERRUN_CNT_REG                        (0x01ECUL)                          /*RX_OVERRUN_CNTΪFIFO���ͳ�ƼĴ�����                                                   */
#define SRE_GMAC_RX_LENGTHFIELD_ERR_CNT_REG                (0x01F4UL)                          /*RX_LENGTHFIELD_ERR_CNTΪ��PAD֡ͳ�ƼĴ�����                                             */
#define SRE_GMAC_RX_FAIL_COMMA_CNT_REG                     (0x01F8UL)                          /*RX_FAIL_COMMA_CNTΪ�ֽڶ���COMMAͳ�ƼĴ�����                                           */
#define SRE_GMAC_STATION_ADDR_LOW_0_REG                    (0x0200UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ0�Ĵ���1��                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_0_REG                   (0x0204UL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ0�Ĵ���2��                                              */
#define SRE_GMAC_STATION_ADDR_LOW_1_REG                    (0x0208UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ1�Ĵ���1��                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_1_REG                   (0x020CUL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ1�Ĵ���2��                                              */
#define SRE_GMAC_STATION_ADDR_LOW_2_REG                    (0x0210UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ2�Ĵ���1��                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_2_REG                   (0x0214UL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ2�Ĵ���2��                                              */
#define SRE_GMAC_STATION_ADDR_LOW_3_REG                    (0x0218UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ3�Ĵ���1��                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_3_REG                   (0x021CUL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ3�Ĵ���2��                                              */
#define SRE_GMAC_STATION_ADDR_LOW_4_REG                    (0x0220UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ4�Ĵ���1��                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_4_REG                   (0x0224UL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ4�Ĵ���2��                                              */
#define SRE_GMAC_STATION_ADDR_LOW_5_REG                    (0x0228UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ5�Ĵ���1��                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_5_REG                   (0x022CUL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ5�Ĵ���2��                                              */
#define SRE_GMAC_STATION_ADDR_LOW_MSK_0_REG                (0x0230UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ0�Ĵ���1�����롣                                        */
#define SRE_GMAC_STATION_ADDR_HIGH_MSK_0_REG               (0x0234UL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ0�Ĵ���2�����롣                                       */
#define SRE_GMAC_STATION_ADDR_LOW_MSK_1_REG                (0x0238UL)                          /*STATION_ADDR_LOWΪ����MAC��ַ1�Ĵ���1�����롣                                        */
#define SRE_GMAC_STATION_ADDR_HIGH_MSK_1_REG               (0x023CUL)                          /*STATION_ADDR_HIGHΪ����MAC��ַ1�Ĵ���2�����롣                                       */
#define SRE_GMAC_MAC_SKIP_LEN_REG                          (0x0240UL)                          /*SKIP_LENΪ����ͷ�������ֶγ��ȡ�                                                      */
#define SRE_GMAC_DEBUG_RD_DATA_REG                         (0x0244UL)                          /*1588���ͷ���debugʱ��ץ���������� +mac_num*0x4                                                   */
#define SRE_GMAC_DEBUG_PKT_PTR_REG                         (0x0344UL)                          /*����ָ��Ĵ���                                                                        */
#define SRE_GMAC_DEBUG_EN_REG                              (0x0348UL)                          /*����ʹ��                                                                               */
#define SRE_GMAC_INTR_STATE_REG                            (0x034CUL)                          /*�ж�״̬                                                                               */
#define SRE_GMAC_INTR_CLR_REG                              (0x0350UL)                          /*�ж�����Ĵ���                                                                        */
#define SRE_GMAC_INTR_MSK_REG                              (0x0354UL)                          /*�ж����μĴ���                                                                        */
#define SRE_GMAC_SEQ_ID_REG                                (0x0358UL)                          /*�����sequence ID��ʱ�����[79:64]                                                     */
#define SRE_GMAC_STP_63_TO_32_REG                          (0x035CUL)                          /*�ϱ�ʱ�����[63:32]                                                                     */
#define SRE_GMAC_STP_31_TO_0_REG                           (0x0360UL)                          /*�ϱ�ʱ�����[31:0]                                                                      */
#define SRE_GMAC_DBG_GRP0_VLD_WORDS_REG                    (0x0364UL)                          /*��һ��RAM�в������Ч����                                                             */
#define SRE_GMAC_DBG_GRP1_VLD_WORDS_REG                    (0x0368UL)                          /*�ڶ���RAM�в������Ч����                                                             */
#define SRE_GMAC_DMAC_EN_REG                               (0x0370UL)                          /*DMACΪ���õ�32����������ı���MAC��ַʹ�ܡ�                                          */
#define SRE_GMAC_DMAC_WITH_MSK_EN_REG                      (0x0374UL)                          /*DMACΪ���õ�32��������ı���MAC��ַʹ�ܡ���                                           */
#define SRE_GMAC_TX_LOOP_PKT_PRI_REG                       (0x0378UL)                          /*ָ�����ر������ȼ����á�                                                              */

/******************************************************************************/
/*                      P650 PPE_COMMON �Ĵ�������                            */
/******************************************************************************/

#if 0         /* z00202052 */
#define SRE_PPE_COMMON_BASE                                   (0x128c0000)
#else
#define SRE_PPE_COMMON_BASE                                   (0xe28c0000)
#endif        /* z00202052 */

#define SRE_PPE_CFG_WE_ADDR_REG      (SRE_PPE_COMMON_BASE + 0x0)   /* PPE_CFG_WE_ADDRΪPOE��д��ַ�� */
#define SRE_PPE_CFG_BMU_ADDR_REG     (SRE_PPE_COMMON_BASE + 0x4)   /* PPE_CFG_BMU_ADDRΪBMU������ͷŻ���Ļ���ַ�� */
#define SRE_PPE_CFG_RX_BUFF_REQ_TIMER_REG  (SRE_PPE_COMMON_BASE + 0x8)   /* PPE_CFG_RX_BUFFREQ_TIMERΪ���ջ������볬ʱ�Ĵ����� */
#define SRE_PPE_CFG_VMID_REG         (SRE_PPE_COMMON_BASE + 0xC)   /* PPE_CFG_VMIDΪ����BMU��POE��VMID�� */
#define SRE_PPE_CFG_QOS_DROP_EN_REG  (SRE_PPE_COMMON_BASE + 0x10)  /* PPE_CFG_QOS_DROP_EN��32��POOL�İ�QoS����ʹ�� */
#define SRE_PPE_CFG_TM_ADDR_REG      (SRE_PPE_COMMON_BASE + 0x14)  /* PPE_CFG_TM_ADDRΪTM�Ķ����Ĵ�����ַ����õ�ַ�ư���TM��ɶ����� */
#define SRE_PPE_CFG_REQ_BMU_OUT_DEPTH_REG  (SRE_PPE_COMMON_BASE + 0x18)  /* PPE_CFG_REQ_BMU_OUT_DEPTHΪ��BMU���뻺��ʱ��outstanding��ȡ� */
#define SRE_PPE_CFG_CMM_TO_BE_RST_REG  (SRE_PPE_COMMON_BASE + 0x1C)  /* PPE_CFG_CMM_TO_BE_RSTΪ��ͨ���Ƿ�Ҫ��λ�� */
#define SRE_PPE_CFG_MEM_TIMING_REG   (SRE_PPE_COMMON_BASE + 0x20)  /* PPE_CFG_MEM_TIMINGΪPPE��MEMʱ�����á� */
#define SRE_PPE_CFG_BP_BUS_TIME_REG  (SRE_PPE_COMMON_BASE + 0x24)  /* PPE_CFG_BP_BUS_TIMEΪPPE�ķ�ѹ���ߵĳ�ʱ�Ĵ������á� */
#define SRE_PPE_CFG_RX_CFF_ADDR_0_REG  (SRE_PPE_COMMON_BASE + 0x100)  /* PPE_CFG_RX_CFF_ADD��32��POOL�Ķ�ӦFIFO��������BUF�ĵ�ַ��0x0100~0x017C������POOL0~POOL31�Ķ�ӦFIFO��������BUF�ĵ�ַ */
#define SRE_PPE_CFG_RX_CFF_ADDR_1_REG  (SRE_PPE_COMMON_BASE + 0x104)  /* PPE_CFG_RX_CFF_ADD��32��POOL�Ķ�ӦFIFO��������BUF�ĵ�ַ��0x0100~0x017C������POOL0~POOL31�Ķ�ӦFIFO��������BUF�ĵ�ַ */
#define SRE_PPE_CFG_RX_BUFF_FIFO_0_THRSLD_0_REG  (SRE_PPE_COMMON_BASE + 0x200)  /* PPE_CFG_RX_BUFF_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ�����
0x0200~0x027C�����ǻ���FIFO_0~FIFO_31��ˮ�����üĴ��� */
#define SRE_PPE_CFG_RX_BUFF_FIFO_0_THRSLD_1_REG  (SRE_PPE_COMMON_BASE + 0x204)  /* PPE_CFG_RX_BUFF_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ�����
0x0200~0x027C�����ǻ���FIFO_0~FIFO_31��ˮ�����üĴ��� */
#define SRE_PPE_CFG_POOL_GRP_0_REG   (SRE_PPE_COMMON_BASE + 0x300)  /* PPE_CFG_POOL_GRP��32��POOL���Է������ЩGRPʹ�ã�0x0300~0x037C������POOL0~POOL31������ */
#define SRE_PPE_CFG_POOL_GRP_1_REG   (SRE_PPE_COMMON_BASE + 0x304)  /* PPE_CFG_POOL_GRP��32��POOL���Է������ЩGRPʹ�ã�0x0300~0x037C������POOL0~POOL31������ */
#define SRE_PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZE_0_REG  (SRE_PPE_COMMON_BASE + 0x400)  /* PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZEΪ����FIFO�Ļ����С���üĴ�����
0x0400~0x047C�����ǻ���FIFO_0~FIFO_31�Ļ����С���üĴ��� */
#define SRE_PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZE_1_REG  (SRE_PPE_COMMON_BASE + 0x404)  /* PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZEΪ����FIFO�Ļ����С���üĴ�����
0x0400~0x047C�����ǻ���FIFO_0~FIFO_31�Ļ����С���üĴ��� */
#define SRE_PPE_CFG_RX_BUFF_FIFO_SIZE_0_REG  (SRE_PPE_COMMON_BASE + 0x500)  /* PPE_CFG_RX_BUFF_FIFO_SIZE����FIFO�Ĵ�С���üĴ�����
0x0500~0x057C�����ǻ���FIFO_0~FIFO_31�Ĵ�С���üĴ��� */
#define SRE_PPE_CFG_RX_BUFF_FIFO_SIZE_1_REG  (SRE_PPE_COMMON_BASE + 0x504)  /* PPE_CFG_RX_BUFF_FIFO_SIZE����FIFO�Ĵ�С���üĴ�����
0x0500~0x057C�����ǻ���FIFO_0~FIFO_31�Ĵ�С���üĴ��� */
#define SRE_PPE_CFG_TYPE_ITEM_0_REG  (SRE_PPE_COMMON_BASE + 0x2000)  /* PPE_CFG_TYPE_ITEMΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ������á�
0x2000~0x24FC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_1_REG  (SRE_PPE_COMMON_BASE + 0x2004)  /* PPE_CFG_TYPE_ITEMΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ������á�
0x2000~0x24FC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x2400)  /* PPE_CFG_TYPE_ITEM0_MSKΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ��ĵ��������á�
0x2400~0x27FC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_MSK_1_REG  (SRE_PPE_COMMON_BASE + 0x2404)  /* PPE_CFG_TYPE_ITEM0_MSKΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ��ĵ��������á�
0x2400~0x27FC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_MODE_0_REG  (SRE_PPE_COMMON_BASE + 0x2800)  /* PPE_CFG_TYPE_ITEM_QOS_MODEΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ������ɷ�ʽ����1��
0x2800~0x2BFC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_MODE_1_REG  (SRE_PPE_COMMON_BASE + 0x2804)  /* PPE_CFG_TYPE_ITEM_QOS_MODEΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ������ɷ�ʽ����1��
0x2800~0x2BFC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_OFFSET_0_REG  (SRE_PPE_COMMON_BASE + 0x2C00)  /* PPE_CFG_TYPE_ITEM_QOS_OFFSETΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ������ɷ�ʽ����2��0x2C00~0x2CFC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_OFFSET_1_REG  (SRE_PPE_COMMON_BASE + 0x2C04)  /* PPE_CFG_TYPE_ITEM_QOS_OFFSETΪ��Ҫ����������QOS/GRP/VMID�ĸ��ֱ������ɷ�ʽ����2��0x2C00~0x2CFC�����ǵ�0��~��255�ֱ��ĵ����� */
#define SRE_PPE_CFG_QOS_TBL0_0_REG   (SRE_PPE_COMMON_BASE + 0x4000)  /* PPE_CFG_QOS_TBL0������QOS�ĵ�0�ű� */
#define SRE_PPE_CFG_QOS_TBL0_1_REG   (SRE_PPE_COMMON_BASE + 0x4004)  /* PPE_CFG_QOS_TBL0������QOS�ĵ�0�ű� */
#define SRE_PPE_CFG_QOS_TBL1_0_REG   (SRE_PPE_COMMON_BASE + 0x4020)  /* PPE_CFG_QOS_TBL1������QOS�ĵ�1�ű� */
#define SRE_PPE_CFG_QOS_TBL1_1_REG   (SRE_PPE_COMMON_BASE + 0x4024)  /* PPE_CFG_QOS_TBL1������QOS�ĵ�1�ű� */
#define SRE_PPE_CFG_QOS_TBL2_0_REG   (SRE_PPE_COMMON_BASE + 0x4040)  /* PPE_CFG_QOS_TBL2������QOS�ĵ�2�ű� */
#define SRE_PPE_CFG_QOS_TBL2_1_REG   (SRE_PPE_COMMON_BASE + 0x4044)  /* PPE_CFG_QOS_TBL2������QOS�ĵ�2�ű� */
#define SRE_PPE_CFG_QOS_TBL3_0_REG   (SRE_PPE_COMMON_BASE + 0x4060)  /* PPE_CFG_QOS_TBL3������QOS�ĵ�3�ű� */
#define SRE_PPE_CFG_QOS_TBL3_1_REG   (SRE_PPE_COMMON_BASE + 0x4064)  /* PPE_CFG_QOS_TBL3������QOS�ĵ�3�ű� */
#define SRE_PPE_CFG_QOS_TBL4_0_REG   (SRE_PPE_COMMON_BASE + 0x4080)  /* PPE_CFG_QOS_TBL4������QOS�ĵ�4�ű� */
#define SRE_PPE_CFG_QOS_TBL4_1_REG   (SRE_PPE_COMMON_BASE + 0x4084)  /* PPE_CFG_QOS_TBL4������QOS�ĵ�4�ű� */
#define SRE_PPE_CFG_QOS_TBL5_0_REG   (SRE_PPE_COMMON_BASE + 0x40A0)  /* PPE_CFG_QOS_TBL5������QOS�ĵ�5�ű� */
#define SRE_PPE_CFG_QOS_TBL5_1_REG   (SRE_PPE_COMMON_BASE + 0x40A4)  /* PPE_CFG_QOS_TBL5������QOS�ĵ�5�ű� */
#define SRE_PPE_CFG_QOS_TBL6_0_REG   (SRE_PPE_COMMON_BASE + 0x40C0)  /* PPE_CFG_QOS_TBL6������QOS�ĵ�6�ű� */
#define SRE_PPE_CFG_QOS_TBL6_1_REG   (SRE_PPE_COMMON_BASE + 0x40C4)  /* PPE_CFG_QOS_TBL6������QOS�ĵ�6�ű� */
#define SRE_PPE_CFG_QOS_TBL7_0_REG   (SRE_PPE_COMMON_BASE + 0x40E0)  /* PPE_CFG_QOS_TBL7������QOS�ĵ�7�ű� */
#define SRE_PPE_CFG_QOS_TBL7_1_REG   (SRE_PPE_COMMON_BASE + 0x40E4)  /* PPE_CFG_QOS_TBL7������QOS�ĵ�7�ű� */
#define SRE_PPE_CFG_QOS_TBL_KEY_EN_0_REG  (SRE_PPE_COMMON_BASE + 0x4104)  /* PPE_CFG_QOS_TBL0_KEY_EN������QOS�ı�ļ�ֵ�������üĴ���1��0x4104~0x413C�����Ǳ�0~��7������ */
#define SRE_PPE_CFG_QOS_TBL_KEY_EN_1_REG  (SRE_PPE_COMMON_BASE + 0x410C)  /* PPE_CFG_QOS_TBL0_KEY_EN������QOS�ı�ļ�ֵ�������üĴ���1��0x4104~0x413C�����Ǳ�0~��7������ */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0_0_REG  (SRE_PPE_COMMON_BASE + 0x5D00)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���0��0x5D00~0x5D50�����Ǳ�0~��10������ */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0_1_REG  (SRE_PPE_COMMON_BASE + 0x5D08)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���0��0x5D00~0x5D50�����Ǳ�0~��10������ */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET1_0_REG  (SRE_PPE_COMMON_BASE + 0x5D04)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���1��0x5D04~0x5D54�����Ǳ�0~��10������ */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET1_1_REG  (SRE_PPE_COMMON_BASE + 0x5D0C)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���1��0x5D04~0x5D54�����Ǳ�0~��10������ */
#define SRE_PPE_CFG_GRP_TBL0_0_REG   (SRE_PPE_COMMON_BASE + 0x5000)  /* PPE_CFG_GRP_TBL0�ǲ������GRP�ĵ�0�ű� */
#define SRE_PPE_CFG_GRP_TBL0_1_REG   (SRE_PPE_COMMON_BASE + 0x5004)  /* PPE_CFG_GRP_TBL0�ǲ������GRP�ĵ�0�ű� */
#define SRE_PPE_CFG_GRP_TBL1_0_REG   (SRE_PPE_COMMON_BASE + 0x5100)  /* PPE_CFG_GRP_TBL1�ǲ������GRP�ĵ�1�ű� */
#define SRE_PPE_CFG_GRP_TBL1_1_REG   (SRE_PPE_COMMON_BASE + 0x5104)  /* PPE_CFG_GRP_TBL1�ǲ������GRP�ĵ�1�ű� */
#define SRE_PPE_CFG_GRP_TBL2_0_REG   (SRE_PPE_COMMON_BASE + 0x5200)  /* PPE_CFG_GRP_TBL2�ǲ������GRP�ĵ�2�ű� */
#define SRE_PPE_CFG_GRP_TBL2_1_REG   (SRE_PPE_COMMON_BASE + 0x5204)  /* PPE_CFG_GRP_TBL2�ǲ������GRP�ĵ�2�ű� */
#define SRE_PPE_CFG_GRP_TBL3_0_REG   (SRE_PPE_COMMON_BASE + 0x5300)  /* PPE_CFG_GRP_TBL3�ǲ������GRP�ĵ�3�ű� */
#define SRE_PPE_CFG_GRP_TBL3_1_REG   (SRE_PPE_COMMON_BASE + 0x5304)  /* PPE_CFG_GRP_TBL3�ǲ������GRP�ĵ�3�ű� */
#define SRE_PPE_CFG_GRP_TBL4_0_REG   (SRE_PPE_COMMON_BASE + 0x5400)  /* PPE_CFG_GRP_TBL4�ǲ������GRP�ĵ�4�ű� */
#define SRE_PPE_CFG_GRP_TBL4_1_REG   (SRE_PPE_COMMON_BASE + 0x5404)  /* PPE_CFG_GRP_TBL4�ǲ������GRP�ĵ�4�ű� */
#define SRE_PPE_CFG_GRP_TBL5_0_REG   (SRE_PPE_COMMON_BASE + 0x5500)  /* PPE_CFG_GRP_TBL5�ǲ������GRP�ĵ�5�ű� */
#define SRE_PPE_CFG_GRP_TBL5_1_REG   (SRE_PPE_COMMON_BASE + 0x5504)  /* PPE_CFG_GRP_TBL5�ǲ������GRP�ĵ�5�ű� */
#define SRE_PPE_CFG_GRP_TBL6_0_REG   (SRE_PPE_COMMON_BASE + 0x5600)  /* PPE_CFG_GRP_TBL6�ǲ������GRP�ĵ�6�ű� */
#define SRE_PPE_CFG_GRP_TBL6_1_REG   (SRE_PPE_COMMON_BASE + 0x5604)  /* PPE_CFG_GRP_TBL6�ǲ������GRP�ĵ�6�ű� */
#define SRE_PPE_CFG_GRP_TBL7_0_REG   (SRE_PPE_COMMON_BASE + 0x5700)  /* PPE_CFG_GRP_TBL7�ǲ������GRP�ĵ�7�ű� */
#define SRE_PPE_CFG_GRP_TBL7_1_REG   (SRE_PPE_COMMON_BASE + 0x5704)  /* PPE_CFG_GRP_TBL7�ǲ������GRP�ĵ�7�ű� */
#define SRE_PPE_CFG_GRP_TBL8_0_REG   (SRE_PPE_COMMON_BASE + 0x5800)  /* PPE_CFG_GRP_TBL8�ǲ������GRP�ĵ�8�ű� */
#define SRE_PPE_CFG_GRP_TBL8_1_REG   (SRE_PPE_COMMON_BASE + 0x5804)  /* PPE_CFG_GRP_TBL8�ǲ������GRP�ĵ�8�ű� */
#define SRE_PPE_CFG_GRP_TBL9_0_REG   (SRE_PPE_COMMON_BASE + 0x5900)  /* PPE_CFG_GRP_TBL9�ǲ������GRP�ĵ�9�ű� */
#define SRE_PPE_CFG_GRP_TBL9_1_REG   (SRE_PPE_COMMON_BASE + 0x5904)  /* PPE_CFG_GRP_TBL9�ǲ������GRP�ĵ�9�ű� */
#define SRE_PPE_CFG_GRP_TBL10_0_REG  (SRE_PPE_COMMON_BASE + 0x5A00)  /* PPE_CFG_GRP_TBL10�ǲ������GRP�ĵ�10�ű� */
#define SRE_PPE_CFG_GRP_TBL10_1_REG  (SRE_PPE_COMMON_BASE + 0x5A04)  /* PPE_CFG_GRP_TBL10�ǲ������GRP�ĵ�10�ű� */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_0_REG  (SRE_PPE_COMMON_BASE + 0x5B00)  /* PPE_CFG_GRP_CMP_TBL_VALUE�ǱȽϷ�ʽ����GRP��GRP������ֵ */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_1_REG  (SRE_PPE_COMMON_BASE + 0x5B04)  /* PPE_CFG_GRP_CMP_TBL_VALUE�ǱȽϷ�ʽ����GRP��GRP������ֵ */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_2_REG  (SRE_PPE_COMMON_BASE + 0x5B20)  /* PPE_CFG_GRP_CMP_TBL_VALUE�ǱȽϷ�ʽ����GRP��GRP������ֵ */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_3_REG  (SRE_PPE_COMMON_BASE + 0x5B24)  /* PPE_CFG_GRP_CMP_TBL_VALUE�ǱȽϷ�ʽ����GRP��GRP������ֵ */
#define SRE_PPE_CFG_VMID_TBL0_0_REG  (SRE_PPE_COMMON_BASE + 0x6000)  /* PPE_CFG_VMID_TBL0������vmid�ĵ�0�ű� */
#define SRE_PPE_CFG_VMID_TBL0_1_REG  (SRE_PPE_COMMON_BASE + 0x6004)  /* PPE_CFG_VMID_TBL0������vmid�ĵ�0�ű� */
#define SRE_PPE_CFG_VMID_TBL1_0_REG  (SRE_PPE_COMMON_BASE + 0x6080)  /* PPE_CFG_VMID_TBL1������vmid�ĵ�1�ű� */
#define SRE_PPE_CFG_VMID_TBL1_1_REG  (SRE_PPE_COMMON_BASE + 0x6084)  /* PPE_CFG_VMID_TBL1������vmid�ĵ�1�ű� */
#define SRE_PPE_CFG_VMID_TBL2_0_REG  (SRE_PPE_COMMON_BASE + 0x6100)  /* PPE_CFG_VMID_TBL2������vmid�ĵ�2�ű� */
#define SRE_PPE_CFG_VMID_TBL2_1_REG  (SRE_PPE_COMMON_BASE + 0x6104)  /* PPE_CFG_VMID_TBL2������vmid�ĵ�2�ű� */
#define SRE_PPE_CFG_VMID_TBL3_0_REG  (SRE_PPE_COMMON_BASE + 0x6180)  /* PPE_CFG_VMID_TBL3������vmid�ĵ�3�ű� */
#define SRE_PPE_CFG_VMID_TBL3_1_REG  (SRE_PPE_COMMON_BASE + 0x6184)  /* PPE_CFG_VMID_TBL3������vmid�ĵ�3�ű� */
#define SRE_PPE_CFG_VMID_TBL4_0_REG  (SRE_PPE_COMMON_BASE + 0x6200)  /* PPE_CFG_VMID_TBL4������vmid�ĵ�4�ű� */
#define SRE_PPE_CFG_VMID_TBL4_1_REG  (SRE_PPE_COMMON_BASE + 0x6204)  /* PPE_CFG_VMID_TBL4������vmid�ĵ�4�ű� */
#define SRE_PPE_CFG_VMID_TBL5_0_REG  (SRE_PPE_COMMON_BASE + 0x6280)  /* PPE_CFG_VMID_TBL5������vmid�ĵ�5�ű� */
#define SRE_PPE_CFG_VMID_TBL5_1_REG  (SRE_PPE_COMMON_BASE + 0x6284)  /* PPE_CFG_VMID_TBL5������vmid�ĵ�5�ű� */
#define SRE_PPE_CFG_VMID_TBL6_0_REG  (SRE_PPE_COMMON_BASE + 0x6300)  /* PPE_CFG_VMID_TBL6������vmid�ĵ�6�ű� */
#define SRE_PPE_CFG_VMID_TBL6_1_REG  (SRE_PPE_COMMON_BASE + 0x6304)  /* PPE_CFG_VMID_TBL6������vmid�ĵ�6�ű� */
#define SRE_PPE_CFG_VMID_TBL7_0_REG  (SRE_PPE_COMMON_BASE + 0x6380)  /* PPE_CFG_VMID_TBL7������vmid�ĵ�7�ű� */
#define SRE_PPE_CFG_VMID_TBL7_1_REG  (SRE_PPE_COMMON_BASE + 0x6384)  /* PPE_CFG_VMID_TBL7������vmid�ĵ�7�ű� */
#define SRE_PPE_CFG_VMID_TBL8_0_REG  (SRE_PPE_COMMON_BASE + 0x6400)  /* PPE_CFG_VMID_TBL8������vmid�ĵ�8�ű� */
#define SRE_PPE_CFG_VMID_TBL8_1_REG  (SRE_PPE_COMMON_BASE + 0x6404)  /* PPE_CFG_VMID_TBL8������vmid�ĵ�8�ű� */
#define SRE_PPE_CFG_VMID_TBL9_0_REG  (SRE_PPE_COMMON_BASE + 0x6480)  /* PPE_CFG_VMID_TBL9������vmid�ĵ�9�ű� */
#define SRE_PPE_CFG_VMID_TBL9_1_REG  (SRE_PPE_COMMON_BASE + 0x6484)  /* PPE_CFG_VMID_TBL9������vmid�ĵ�9�ű� */
#define SRE_PPE_CFG_VMID_TBL10_0_REG  (SRE_PPE_COMMON_BASE + 0x6500)  /* PPE_CFG_VMID_TBL0������vmid�ĵ�10�ű� */
#define SRE_PPE_CFG_VMID_TBL10_1_REG  (SRE_PPE_COMMON_BASE + 0x6504)  /* PPE_CFG_VMID_TBL0������vmid�ĵ�10�ű� */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_0_REG  (SRE_PPE_COMMON_BASE + 0x6580)  /* PPE_CFG_VMID_CMP_TBL_VALUE�ǱȽϷ�ʽ����VMID��VMID������ֵ */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_1_REG  (SRE_PPE_COMMON_BASE + 0x6584)  /* PPE_CFG_VMID_CMP_TBL_VALUE�ǱȽϷ�ʽ����VMID��VMID������ֵ */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_2_REG  (SRE_PPE_COMMON_BASE + 0x6590)  /* PPE_CFG_VMID_CMP_TBL_VALUE�ǱȽϷ�ʽ����VMID��VMID������ֵ */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_3_REG  (SRE_PPE_COMMON_BASE + 0x6594)  /* PPE_CFG_VMID_CMP_TBL_VALUE�ǱȽϷ�ʽ����VMID��VMID������ֵ */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL0_0_REG  (SRE_PPE_COMMON_BASE + 0x7000)  /* PPE_CFG_GRP_VMID_CMP_TBL0�ǱȽϷ�ʽ����GRP_VMID�ĵ�0�ű� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL1_0_REG  (SRE_PPE_COMMON_BASE + 0x7100)  /* PPE_CFG_GRP_VMID_CMP_TBL1�ǱȽϷ�ʽ����GRP_VMID�ĵ�1�ű� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL2_0_REG  (SRE_PPE_COMMON_BASE + 0x7200)  /* PPE_CFG_GRP_VMID_CMP_TBL2�ǱȽϷ�ʽ����GRP_VMID�ĵ�2�ű� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL3_0_REG  (SRE_PPE_COMMON_BASE + 0x7300)  /* PPE_CFG_GRP_VMID_CMP_TBL3�ǱȽϷ�ʽ����GRP_VMID�ĵ�3�ű� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL0_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B00)  /* PPE_CFG_GRP_VMID_CMP_TBL0_MSK�ǱȽϷ�ʽ����GRP_VMID�ĵ�0�ű������ֵ�� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL1_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B08)  /* PPE_CFG_GRP_VMID_CMP_TBL1_MSK�ǱȽϷ�ʽ����GRP_VMID�ĵ�1�ű������ֵ�� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL2_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B10)  /* PPE_CFG_GRP_VMID_CMP_TBL2_MSK�ǱȽϷ�ʽ����GRP_VMID�ĵ�2�ű������ֵ�� */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL3_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B18)  /* PPE_CFG_GRP_VMID_CMP_TBL3_MSK�ǱȽϷ�ʽ����GRP_VMID�ĵ�3�ű������ֵ�� */
#define SRE_PPE_INTEN_0_REG          (SRE_PPE_COMMON_BASE + 0x8000)  /* PPE_INTEN_0��ʹ���жϼĴ���0�� */
#define SRE_PPE_RINT_0_REG           (SRE_PPE_COMMON_BASE + 0x8004)  /* PPE_RINT_0��ԭʼ�жϼĴ���0�� */
#define SRE_PPE_INTSTS_0_REG         (SRE_PPE_COMMON_BASE + 0x8008)  /* PPE_INTSTS_0���ж�״̬�Ĵ���0�� */
#define SRE_PPE_INTEN_1_REG          (SRE_PPE_COMMON_BASE + 0x8010)  /* PPE_INTEN_1��ʹ���жϼĴ���1�� */
#define SRE_PPE_RINT_1_REG           (SRE_PPE_COMMON_BASE + 0x8014)  /* PPE_RINT_1��ԭʼ�жϼĴ���1�� */
#define SRE_PPE_INTSTS_1_REG         (SRE_PPE_COMMON_BASE + 0x8018)  /* PPE_INTSTS_1���ж�״̬�Ĵ���1�� */
#define SRE_PPE_INTEN_2_REG          (SRE_PPE_COMMON_BASE + 0x8020)  /* PPE_RINT_2��ʹ���жϼĴ���2�� */
#define SRE_PPE_RINT_2_REG           (SRE_PPE_COMMON_BASE + 0x8024)  /* PPE_RINT_2��ԭʼ�жϼĴ���2�� */
#define SRE_PPE_INTSTS_2_REG         (SRE_PPE_COMMON_BASE + 0x8028)  /* PPE_INTSTS_2���ж�״̬�Ĵ���2�� */
#define SRE_PPE_CFG_STS_MODE_0_REG   (SRE_PPE_COMMON_BASE + 0xA000)  /* PPE_CFG_STS_MODE_0�ǼĴ�������ΪΪCNT_CYC����ʹ�ܼĴ���0�� */
#define SRE_PPE_CFG_STS_MODE_1_REG   (SRE_PPE_COMMON_BASE + 0xA004)  /* PPE_CFG_STS_MODE_1�ǼĴ�������ΪΪCNT_CYC����ʹ�ܼĴ���1�� */
#define SRE_PPE_HIS_PKT_GRP_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA100)  /* PPE_HIS_PKT_GRP_CN�ǽ��ձ��İ�GRP��ͳ�ơ� */
#define SRE_PPE_HIS_PKT_GRP_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA104)  /* PPE_HIS_PKT_GRP_CN�ǽ��ձ��İ�GRP��ͳ�ơ� */
#define SRE_PPE_HIS_PKT_QOS_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA180)  /* PPE_HIS_PKT_QOS_CN�ǽ��ձ��İ�QOS��ͳ�ơ� */
#define SRE_PPE_HIS_PKT_QOS_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA184)  /* PPE_HIS_PKT_QOS_CN�ǽ��ձ��İ�QOS��ͳ�ơ� */
#define SRE_PPE_HIS_DROP_PKT_QOS_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA1A0)  /* PPE_HIS_DROP_PKT_QOS_CNT�Ƕ������İ�QOS��ͳ�ơ� */
#define SRE_PPE_HIS_DROP_PKT_QOS_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA1A4)  /* PPE_HIS_DROP_PKT_QOS_CNT�Ƕ������İ�QOS��ͳ�ơ� */
#define SRE_PPE_HIS_MST_WR_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA1C0)  /* PPE_HIS_MST_WR_CNT��MASTERд������ͳ�ơ� */
#define SRE_PPE_HIS_MST_WR_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA1C4)  /* PPE_HIS_MST_WR_CNT��MASTERд������ͳ�ơ� */
#define SRE_PPE_HIS_MST_RD_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA1D8)  /* PPE_HIS_MST_RD_CNT��MASTERд������ͳ�ơ� */
#define SRE_PPE_HIS_MST_RD_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA1DC)  /* PPE_HIS_MST_RD_CNT��MASTERд������ͳ�ơ� */
#define SRE_PPE_HIS_REQ_BMU_FAIL_CNT_REG  (SRE_PPE_COMMON_BASE + 0xA1F0)  /* PPE_HIS_REQ_BMU_FAIL_CNT������BMUʧ�ܵ�ͳ�ơ� */
#define SRE_PPE_HIS_REQ_BMU_OK_CNT_REG  (SRE_PPE_COMMON_BASE + 0xA1F4)  /* PPE_HIS_REQ_BMU_OK_CNT������BMU�ɹ���ͳ�ơ� */
#define SRE_PPE_CURR_BUF_CNT_0_REG   (SRE_PPE_COMMON_BASE + 0xA200)  /* PPE_CURR_BUF_CNT��
0xA200~0xA27C�����ǻ���pool_0~pool_31�Ļ���ָ����� */
#define SRE_PPE_CURR_BUF_CNT_1_REG   (SRE_PPE_COMMON_BASE + 0xA204)  /* PPE_CURR_BUF_CNT��
0xA200~0xA27C�����ǻ���pool_0~pool_31�Ļ���ָ����� */
#define SRE_PPE_CURR_CMM_CAN_RST_REG  (SRE_PPE_COMMON_BASE + 0xA300)  /* PPE_CURR_CAN_RSTΪ��ͨ���Ƿ���Ը�λ�� */
#define SRE_PPE_HIS_FIFO_ERR_REG     (SRE_PPE_COMMON_BASE + 0xA304)  /* PPE_HIS_FIFO_ERR���ڲ�FIFO����� */
#define SRE_PPE_CURR_FIFO_0_REG      (SRE_PPE_COMMON_BASE + 0xA308)  /* PPE_CURR_FIFO_0ΪBMU��������FIFO��״̬�� */
#define SRE_PPE_CURR_FIFO_1_REG      (SRE_PPE_COMMON_BASE + 0xA30C)  /* PPE_CURR_FIFO_0ΪBMU��������FIFO��״̬�� */
#define SRE_PPE_HIS_MST_RD_LAT_0_REG  (SRE_PPE_COMMON_BASE + 0xA310)  /* PPE_HIS_MST_RD_LAT��MASTER����������ʱͳ�ơ� */
#define SRE_PPE_HIS_MST_RD_LAT_1_REG  (SRE_PPE_COMMON_BASE + 0xA314)  /* PPE_HIS_MST_RD_LAT��MASTER����������ʱͳ�ơ� */
#define SRE_PPE_HIS_MST_WR_LAT_0_REG  (SRE_PPE_COMMON_BASE + 0xA328)  /* PPE_HIS_MST_WR_LAT��MASTERд��������ʱͳ�ơ� */
#define SRE_PPE_HIS_MST_WR_LAT_1_REG  (SRE_PPE_COMMON_BASE + 0xA32C)  /* PPE_HIS_MST_WR_LAT��MASTERд��������ʱͳ�ơ� */
#define SRE_PPE_HIS_MST_RD_STS_1_0_REG  (SRE_PPE_COMMON_BASE + 0xA340)  /* PPE_HIS_MST_RD_STS_1��MASTER��������״̬1�� */
#define SRE_PPE_HIS_MST_RD_STS_1_1_REG  (SRE_PPE_COMMON_BASE + 0xA344)  /* PPE_HIS_MST_RD_STS_1��MASTER��������״̬1�� */
#define SRE_PPE_HIS_MST_RD_STS_2_0_REG  (SRE_PPE_COMMON_BASE + 0xA358)  /* PPE_HIS_MST_RD_STS_2��MASTER��������״̬2�� */
#define SRE_PPE_HIS_MST_RD_STS_2_1_REG  (SRE_PPE_COMMON_BASE + 0xA35C)  /* PPE_HIS_MST_RD_STS_2��MASTER��������״̬2�� */
#define SRE_PPE_HIS_MST_WR_STS_1_0_REG  (SRE_PPE_COMMON_BASE + 0xA370)  /* PPE_HIS_MST_RD_STS_1��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_WR_STS_1_1_REG  (SRE_PPE_COMMON_BASE + 0xA374)  /* PPE_HIS_MST_RD_STS_1��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_WR_STS_2_0_REG  (SRE_PPE_COMMON_BASE + 0xA388)  /* PPE_HIS_MST_RD_STS_2��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_WR_STS_2_1_REG  (SRE_PPE_COMMON_BASE + 0xA38C)  /* PPE_HIS_MST_RD_STS_2��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_WR_STS_3_0_REG  (SRE_PPE_COMMON_BASE + 0xA3A0)  /* PPE_HIS_MST_RD_STS_3��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_WR_STS_3_1_REG  (SRE_PPE_COMMON_BASE + 0xA3A4)  /* PPE_HIS_MST_RD_STS_3��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_RD_STS_3_0_REG  (SRE_PPE_COMMON_BASE + 0xA3B8)  /* PPE_HIS_MST_RD_STS_3��MASTERд������״̬�� */
#define SRE_PPE_HIS_MST_RD_STS_3_1_REG  (SRE_PPE_COMMON_BASE + 0xA3BC)  /* PPE_HIS_MST_RD_STS_3��MASTERд������״̬�� */
#define SRE_PPE_CFG_MST_STS_CLR_0_REG  (SRE_PPE_COMMON_BASE + 0xA3D0)  /* PPE_CFG_MST_STS_CLR��MASTERͳ������Ĵ����� */
#define SRE_PPE_CFG_MST_STS_CLR_1_REG  (SRE_PPE_COMMON_BASE + 0xA3D4)  /* PPE_CFG_MST_STS_CLR��MASTERͳ������Ĵ����� */
#define SRE_PPE_CFG_OAM_TX_ITEM_STS_0_REG  (SRE_PPE_COMMON_BASE + 0xB000)  /* PPE_CFG_OAM_TX_TIEM��Y.1731���ͷ������ƥ��ͳ�ơ� */
#define SRE_PPE_CFG_OAM_TX_ITEM_STS_1_REG  (SRE_PPE_COMMON_BASE + 0xB004)  /* PPE_CFG_OAM_TX_TIEM��Y.1731���ͷ������ƥ��ͳ�ơ� */
#define SRE_PPE_CFG_TIME_SYNC_H_REG  (SRE_PPE_COMMON_BASE + 0xC000)  /* ʱ��ͬ����ʱ���λ���üĴ����� */
#define SRE_PPE_CFG_TIME_SYNC_M_REG  (SRE_PPE_COMMON_BASE + 0xC004)  /* ʱ��ͬ����ʱ���λ���üĴ����� */
#define SRE_PPE_CFG_TIME_SYNC_L_REG  (SRE_PPE_COMMON_BASE + 0xC008)  /* ʱ��ͬ������ʱ�����üĴ����� */
#define SRE_PPE_CFG_TIME_SYNC_RDY_REG  (SRE_PPE_COMMON_BASE + 0xC00C)  /* ʱ��ͬ��ʹ�����üĴ����� */
#define SRE_PPE_CFG_PTP_OFFSET_ADD_RDY_REG  (SRE_PPE_COMMON_BASE + 0xC010)  /* ʱ��ͬ��ƫ��ʹ�����üĴ����� */
#define SRE_PPE_CFG_TIME_CYC_NS_REG  (SRE_PPE_COMMON_BASE + 0xC014)  /* RTC��ʱʱ������ʱ����������ֵ���üĴ����� */
#define SRE_PPE_CFG_TIME_CYC_NS_DEC_REG  (SRE_PPE_COMMON_BASE + 0xC018)  /* RTC��ʱʱ������ʱ������С��ֵ���üĴ����� */
#define SRE_PPE_CFG_SYS_CYC_REG      (SRE_PPE_COMMON_BASE + 0xC01C)  /* ϵͳʱ������ʱ�����üĴ����� */
#define SRE_PPE_CFG_INT_1PPS_EN_REG  (SRE_PPE_COMMON_BASE + 0xC020)  /* 1PPS�ж�ʹ�ܼĴ����� */
#define SRE_PPE_CFG_INTS_1PPS_CLR_REG  (SRE_PPE_COMMON_BASE + 0xC024)  /* 1PPS�ж�����Ĵ����� */
#define SRE_PPE_CFG_INTS_1PPS_REG    (SRE_PPE_COMMON_BASE + 0xC028)  /* 1PPS�ж�״̬�Ĵ����� */
#define SRE_PPE_CURR_TIME_OUT_H_REG  (SRE_PPE_COMMON_BASE + 0xC02C)  /* ����ʱ�����λ����Ĵ����� */
#define SRE_PPE_CURR_TIME_OUT_L_REG  (SRE_PPE_COMMON_BASE + 0xC030)  /* ����ʱ�����λ����Ĵ����� */
#define SRE_PPE_CURR_TIME_OUT_NS_REG  (SRE_PPE_COMMON_BASE + 0xC034)  /* ����ʱ����������Ĵ����� */
#define SRE_PPE_CFG_TS_CLK_SEL_REG   (SRE_PPE_COMMON_BASE + 0xC038)  /* ���ؼ�ʱʱ��ѡ��Ĵ��� */
#define SRE_PPE_CFG_SYS_TIME_OFFSET_REG  (SRE_PPE_COMMON_BASE + 0xC03C)  /* ϵͳʱ�Ӳ���ʱ�䲹��ƫ��ֵ���üĴ����� */


/******************************************************************************/
/*                      P650 PPE_TNL �Ĵ�������                               */
/******************************************************************************/

#if 0         /* z00202052 */
#define SRE_PPE_TNL_BASE                                   (0x12800000)
#else
#define SRE_PPE_TNL_BASE                                   (0xe2800000)
#endif        /* z00202052 */

#define SRE_PPE_TNL_CFG_TX_FIFO_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x400)  /* PPE_CFG_TX_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ����� */
#define SRE_PPE_TNL_CFG_RX_FIFO_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x404)  /* PPE_CFG_RX_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ����� */
#define SRE_PPE_TNL_CFG_MAX_FRAME_LEN_REG  (SRE_PPE_TNL_BASE + 0x408)  /* MAX_FRAME_LENΪ���ճ���֡���޼Ĵ����� */
#define SRE_PPE_TNL_CFG_TX_PAUSE_REG   (SRE_PPE_TNL_BASE + 0x40C)  /* PPE_CFG_TX_PAUSEΪ�������ؿ��ƼĴ����� */
#define SRE_PPE_TNL_CFG_RX_FIFO_PAUSE_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x410)  /* PPE_CFG_RX_FIFO_PAUSE_THRSLDΪ����FIFO��������ˮ�߼Ĵ����� */
#define SRE_PPE_TNL_CFG_RX_FIFO_BUS_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x414)  /* PPE_CFG_RX_FIFO_BUS_THRSLDΪ����FIFO�ķ�ѹ���ߵ�ˮ�߼Ĵ����� */
#define SRE_PPE_TNL_CFG_TX_BD_ADDR_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x418)  /* PPE_CFG_TX_BD_ADDR_THRSLDΪ������������ַ��FIFOˮ�߼Ĵ����� */
#define SRE_PPE_TNL_CFG_XGE_MODE_REG   (SRE_PPE_TNL_BASE + 0x41C)  /* PPE_CFG_XGE_MODE���ø�ͨ���Խӵ���GE����XGE */
#define SRE_PPE_TNL_CFG_TX_PKT_BD_ADDR_REG  (SRE_PPE_TNL_BASE + 0x420)  /* PPE_CFG_TX_PKT_BUF_ADDRΪ�����������ĵ�ַ�� */
#define SRE_PPE_TNL_CFG_BUS_CTRL_REG   (SRE_PPE_TNL_BASE + 0x424)  /* PPE_CFG_BUS_CTRLΪ���߿��ƼĴ��� */
#define SRE_PPE_TNL_CFG_RX_CTRL_REG    (SRE_PPE_TNL_BASE + 0x428)  /* PPE_CFG_RX_CTRLΪ���տ��ƼĴ����� */
#define SRE_PPE_TNL_CFG_RX_WE_TIMER_REG  (SRE_PPE_TNL_BASE + 0x42C)  /* PPE_CFG_RX_PD_TIMERΪ����дwork entryʧ�ܺ�ĳ�ʱ�Ĵ����� */
#define SRE_PPE_TNL_CFG_REL_BMU_TIMER_REG  (SRE_PPE_TNL_BASE + 0x430)  /* PPE_CFG_REL_BMU_TIMERΪ�ͷ�BMU���üĴ����� */
#define SRE_PPE_TNL_CFG_PAUSE_IDLE_CNT_REG  (SRE_PPE_TNL_BASE + 0x434)  /* PPE_CFG_PAUSE_IDLE_CNT�Ƿ���PAUSE֡���ƼĴ��� */
#define SRE_PPE_TNL_CFG_RX_PKT_MODE_REG  (SRE_PPE_TNL_BASE + 0x438)  /* PPE_CFG_RX_PKT_MODEΪ���ձ�������ģʽ�� */
#define SRE_PPE_TNL_CFG_RX_VLAN_TAG_REG  (SRE_PPE_TNL_BASE + 0x43C)  /* PPE_CFG_RX_VLAN_TAG�ǽ��ձ��ĵ�2��VLAN�����tagֵ */
#define SRE_PPE_TNL_CFG_TX_DECT_EN_REG  (SRE_PPE_TNL_BASE + 0x440)  /* PPE_CFG_TX_DECT_EN�Ƿ���1588DECTʹ�� */
#define SRE_PPE_TNL_CFG_TX_VLAN_TAG_REG  (SRE_PPE_TNL_BASE + 0x444)  /* ����DECT����VLAN��TAG���üĴ����� */
#define SRE_PPE_TNL_CFG_TX_PTP_DPN_REG  (SRE_PPE_TNL_BASE + 0x448)  /* ����DECT����PTP����UDP��Ŀ�Ķ˿ں����üĴ����� */
#define SRE_PPE_TNL_CFG_QOS_GRP_VMID_GEN_REG  (SRE_PPE_TNL_BASE + 0x500)  /* PPE_CFG_QOS_GRP_VMID_GENΪQOS��GRP��VMID�����ɷ�ʽ�Ĵ����� */
#define SRE_PPE_TNL_CFG_TAG_TT_GEN_REG  (SRE_PPE_TNL_BASE + 0x504)  /* PPE_CFG_TAG_TT_GENΪTAG��TT�����ɷ�ʽ�Ĵ��� */
#define SRE_PPE_TNL_CFG_PARSE_TAG_REG  (SRE_PPE_TNL_BASE + 0x508)  /* PPE_CFG_PARSE_TAGΪ����ģʽ�¸�Ԫ���������üĴ��� */
#define SRE_PPE_TNL_CFG_TAG_OFFSET_REG  (SRE_PPE_TNL_BASE + 0x50C)  /* PPE_CFG_TAG_OFFSET������ģʽ����tagʱѡ128�ֽڱ��ĵ�ƫ�ƼĴ������� */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK1_REG  (SRE_PPE_TNL_BASE + 0x510)  /* PPE_CFG_TAG_BIT_MASK1������ģʽ����tagʱѡ128�ֽڱ��ĵĵ�0~31�ֽ��������üĴ����� */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK2_REG  (SRE_PPE_TNL_BASE + 0x514)  /* PPE_CFG_TAG_BIT_MASK2������ģʽ����tagʱѡ128�ֽڱ��ĵĵ�32~63�ֽ��ֽ��������üĴ����� */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK3_REG  (SRE_PPE_TNL_BASE + 0x518)  /* PPE_CFG_TAG_BIT_MASK3������ģʽ����tagʱѡ128�ֽڱ��ĵĵ�64~95�ֽ��������üĴ����� */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK4_REG  (SRE_PPE_TNL_BASE + 0x51C)  /* PPE_CFG_TAG_BIT_MASK3������ģʽ����tagʱѡ128�ֽڱ��ĵĵ�96~127�ֽ��������üĴ����� */
#define SRE_PPE_TNL_CFG_TAG_OTHER_TYPE_REG  (SRE_PPE_TNL_BASE + 0x520)  /* PPE_CFG_TAG_BIT_MASK�ǽ���ģʽ��4�ַ�IP����ID���üĴ��� */
#define SRE_PPE_TNL_CFG_TAG_BIT_MASK_REG  (SRE_PPE_TNL_BASE + 0x524)  /* PPE_CFG_TAG_BIT_MASK������ģʽ����tagʱѡ128�ֽڱ����е�2����λ�����ֽڵ����üĴ����� */
#define SRE_PPE_TNL_CFG_AR_TAG1_CFG_REG  (SRE_PPE_TNL_BASE + 0x528)  /* PPE_CFG_AR_TAG1_CFG��AR������VLAN_ID����ָ��TAG�����á� */
#define SRE_PPE_TNL_CFG_AR_TAG2_CFG_REG  (SRE_PPE_TNL_BASE + 0x52C)  /* PPE_CFG_AR_TAG1_CFG��AR��ָ�����ͱ�������ָ��TAG�����á� */
#define SRE_PPE_TNL_CFG_AR_SPE_CFG_REG  (SRE_PPE_TNL_BASE + 0x530)  /* PPE_CFG_AR_SPE_CFG��AR��2��ָ��TAG�� */
#define SRE_PPE_TNL_CFG_PRO_CHECK_EN_REG  (SRE_PPE_TNL_BASE + 0x534)  /* PPE_CFG_PRO_CHECK_EN��Э�����ʹ�ܡ� */
#define SRE_PPE_TNL_CFG_RX_PKT_INT_REG  (SRE_PPE_TNL_BASE + 0x538)  /* PPE_CFG_RX_PKT_INT�ǽ��յ�ָ����Ŀ���Ļ���ձ��ĳ�ʱ�ϱ��жϵ����á� */
#define SRE_PPE_TNL_CFG_HEAT_DECT_TIME0_REG  (SRE_PPE_TNL_BASE + 0x53C)  /* *704* */
#define SRE_PPE_TNL_CFG_HEAT_DECT_TIME1_REG  (SRE_PPE_TNL_BASE + 0x540)  /* PPE_CFG_HEAT_DECT_TIME1��״̬��������ⳬʱ�Ĵ������üĴ���1 */
#define SRE_PPE_TNL_CFG_TNL_TO_BE_RST_REG  (SRE_PPE_TNL_BASE + 0x544)  /* PPE_CFG_TNL_TO_BE_RSTΪ��ͨ���Ƿ�Ҫ��λ�� */
#define SRE_PPE_TNL_CFG_DELAY_CLR_REG  (SRE_PPE_TNL_BASE + 0x548)  /* PPE_CFG_DELAY_CLR�Ƕ�дDDR�������ʱ�� */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_0_REG  (SRE_PPE_TNL_BASE + 0x580)  /* PPE_CFG_CPU_ADD_ADDR��16��CPU���ͷ����������ĵ�ַ��0x0580~0x05BC������CPU0~CPU15�����͵�ַ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_1_REG  (SRE_PPE_TNL_BASE + 0x584)  /* PPE_CFG_CPU_ADD_ADDR��16��CPU���ͷ����������ĵ�ַ��0x0580~0x05BC������CPU0~CPU15�����͵�ַ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL0_REG  (SRE_PPE_TNL_BASE + 0x5C0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL0��CPU0���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL1_REG  (SRE_PPE_TNL_BASE + 0x5C4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL1��CPU1���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL2_REG  (SRE_PPE_TNL_BASE + 0x5C8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL2��CPU2���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL3_REG  (SRE_PPE_TNL_BASE + 0x5CC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL3��CPU3���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL4_REG  (SRE_PPE_TNL_BASE + 0x5D0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL4��CPU4���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL5_REG  (SRE_PPE_TNL_BASE + 0x5D4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL5��CPU5���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL6_REG  (SRE_PPE_TNL_BASE + 0x5D8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL6��CPU6���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL7_REG  (SRE_PPE_TNL_BASE + 0x5DC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL7��CPU7���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL8_REG  (SRE_PPE_TNL_BASE + 0x5E0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL8��CPU8���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL9_REG  (SRE_PPE_TNL_BASE + 0x5E4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL9��CPU9���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL10_REG  (SRE_PPE_TNL_BASE + 0x5E8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL10��CPU10���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL11_REG  (SRE_PPE_TNL_BASE + 0x5EC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL11��CPU11���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL12_REG  (SRE_PPE_TNL_BASE + 0x5F0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL12��CPU12���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL13_REG  (SRE_PPE_TNL_BASE + 0x5F4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL13��CPU13���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL14_REG  (SRE_PPE_TNL_BASE + 0x5F8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL14��CPU14���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL15_REG  (SRE_PPE_TNL_BASE + 0x5FC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL15��CPU15���ͷ���������ʧ��ָʾ */
#define SRE_PPE_TNL_INTEN_REG          (SRE_PPE_TNL_BASE + 0x600)  /* PPE_INTEN��ʹ���жϼĴ����� */
#define SRE_PPE_TNL_RINT_REG           (SRE_PPE_TNL_BASE + 0x604)  /* PPE_RINT��ԭʼ�жϼĴ����� */
#define SRE_PPE_TNL_INTSTS_REG         (SRE_PPE_TNL_BASE + 0x608)  /* PPE_INTSTS���ж�״̬�Ĵ����� */
#define SRE_PPE_TNL_INT_VMID_REG       (SRE_PPE_TNL_BASE + 0x60C)  /* PPE_INT_VMID���ж�VMID�Ĵ����� */
#define SRE_PPE_TNL_CFG_AXI_DBG_REG    (SRE_PPE_TNL_BASE + 0x610)  /* PPE_CFG_AXI_DBG��AXI DEBUG�Ĵ����� */
#define SRE_PPE_TNL_CFG_STS_MODE_REG   (SRE_PPE_TNL_BASE + 0x700)  /* PPE_CFG_STS_MODE�ǼĴ�������ΪΪCNT_CYC����ʹ�ܼĴ���1�� */
#define SRE_PPE_TNL_HIS_RX_PKT_OK_CNT_REG  (SRE_PPE_TNL_BASE + 0x704)  /* PPE_HIS_RX_PKT_OK_CNT�ǳɹ����������POE�ɹ��ı���ͳ�ơ� */
#define SRE_PPE_TNL_HIS_RX_PKT_DROP_FUL_CNT_REG  (SRE_PPE_TNL_BASE + 0x708)  /* PPE_HIS_RX_PKT_DROP_FUL_CNT����FIFO������������ͳ�ơ� */
#define SRE_PPE_TNL_HIS_RX_PKT_DROP_PRT_CNT_REG  (SRE_PPE_TNL_BASE + 0x70C)  /* PPE_HIS_RX_PKT_DROP_PRT_CNT����FIFO�����Ľضϵ�ͳ�ơ� */
#define SRE_PPE_TNL_HIS_RX_PKT_LOW_QOS_CNT_REG  (SRE_PPE_TNL_BASE + 0x710)  /* PPE_HIS_RX_PKT_LOW_QOS_CNT����QOS���㶪���ı���ͳ�ơ� */
#define SRE_PPE_TNL_HIS_RX_PKT_NO_BUF_CNT_REG  (SRE_PPE_TNL_BASE + 0x714)  /* PPE_HIS_RX_PKT_NO_BUF_CNT����û�ж�ӦBUF�ҽ���FIFO�������ĵ�ͳ�ơ� */
#define SRE_PPE_TNL_HIS_TX_PKT_OK_CNT_REG  (SRE_PPE_TNL_BASE + 0x718)  /* PPE_HIS_TX_PKT_OK_CNT�ǳɹ����͵ı���ͳ�ơ� */
#define SRE_PPE_TNL_HIS_TX_PKT_EPT_CNT_REG  (SRE_PPE_TNL_BASE + 0x71C)  /* PPE_HIS_TX_PKT_EPT_CNT�Ƿ���FIFO�ձ��Ľض�ͳ�ơ� */
#define SRE_PPE_TNL_HIS_TX_PKT_CS_FAIL_CNT_REG  (SRE_PPE_TNL_BASE + 0x720)  /* PPE_HIS_TX_PKT_CS_FAIL_CNT�Ƿ��ͼ���checksumʧ�ܵı���ͳ�ơ� */
#define SRE_PPE_TNL_HIS_REL_BUF_FAIL_CNT_REG  (SRE_PPE_TNL_BASE + 0x724)  /* PPE_HIS_REL_BUF_FAIL_CNT�Ƿ����ͷŻ���ʧ�ܵ�ͳ�ơ� */
#define SRE_PPE_TNL_HIS_RX_ADD_POE_TM_BMU_FAIL_CNT_REG  (SRE_PPE_TNL_BASE + 0x728)  /* PPE_HIS_RX_ADD_POE_TM_BMU_FAIL_CNT�ǽ���дPOE/TM/BMUʧ�ܵ�ͳ�ơ� */
#define SRE_PPE_TNL_HIS_RX_ADD_TM_BMU_OK_CNT_REG  (SRE_PPE_TNL_BASE + 0x72C)  /* PPE_HIS_RX_ADD_TM_BMU_OK_CNTT�ǽ���дTM/BMU�ĳɹ�ͳ��ͳ�ơ� */
#define SRE_PPE_TNL_CURR_CFF_DATA_NUM_REG  (SRE_PPE_TNL_BASE + 0x730)  /* PPE_CURR_DATA_NUMΪ����FIFO���ݸ����Ĵ����� */
#define SRE_PPE_TNL_CURR_TNL_CAN_RST_REG  (SRE_PPE_TNL_BASE + 0x734)  /* PPE_CURR_TNL_CAN_RSTΪ��ͨ���Ƿ���Ը�λ�� */
#define SRE_PPE_TNL_HIS_PRO_ERR_REG    (SRE_PPE_TNL_BASE + 0x738)  /* PPE_HIS_PRO_ERR��Э����������鵽�Ĵ��� */
#define SRE_PPE_TNL_HIS_TNL_FIFO_ERR_REG  (SRE_PPE_TNL_BASE + 0x73C)  /* PPE_HIS_TNL_FIFO_ERR���ڲ�FIFO����� */
#define SRE_PPE_TNL_CURR_RX_ST_REG     (SRE_PPE_TNL_BASE + 0x740)  /* PPE_CURR_RX_ST�ǽ���״̬����ǰ״̬�� */
#define SRE_PPE_TNL_CURR_TX_ST_REG     (SRE_PPE_TNL_BASE + 0x744)  /* PPE_CURR_TX_ST�ǽ���״̬����ǰ״̬�� */
#define SRE_PPE_TNL_CURR_RX_FIFO0_REG  (SRE_PPE_TNL_BASE + 0x748)  /* PPE_CURR_RX_FIFO0�ǽ���FIFO״̬0�� */
#define SRE_PPE_TNL_CURR_RX_FIFO1_REG  (SRE_PPE_TNL_BASE + 0x74C)  /* PPE_CURR_RX_FIFO1�ǽ���FIFO״̬1�� */
#define SRE_PPE_TNL_CURR_TX_FIFO0_REG  (SRE_PPE_TNL_BASE + 0x750)  /* PPE_CURR_TX_FIFO0�Ƿ���FIFO״̬0�� */
#define SRE_PPE_TNL_CURR_TX_FIFO1_REG  (SRE_PPE_TNL_BASE + 0x754)  /* PPE_CURR_TX_FIFO1�Ƿ���FIFO״̬1�� */
#define SRE_PPE_TNL_CURR_DDR_DELAY_REG  (SRE_PPE_TNL_BASE + 0x758)  /* PPE_CURR_DDR_DELAYΪ��дDDR�������ʱ�� */
#define SRE_PPE_TNL_ECO0_REG           (SRE_PPE_TNL_BASE + 0x75C)  /* PPE_ECO0��eco�Ĵ���0�� */
#define SRE_PPE_TNL_ECO1_REG           (SRE_PPE_TNL_BASE + 0x760)  /* PPE_ECO1��eco�Ĵ���1�� */
#define SRE_PPE_TNL_ECO2_REG           (SRE_PPE_TNL_BASE + 0x764)  /* PPE_ECO2��eco�Ĵ���2�� */
#define SRE_PPE_TNL_HIS_RX_MAC_PKT_CNT_REG  (SRE_PPE_TNL_BASE + 0x800)  /* PPE_HIS_RX_MAC_PKT_CNT�ǽ��յ�MAC��ı��ĸ����� */
#define SRE_PPE_TNL_HIS_RX_WR_BD_OK_PKT_CNT_REG  (SRE_PPE_TNL_BASE + 0x804)  /* PPE_HIS_RX_WR_BD_OK_PKT_CNT�ǳɹ�д������������ı��ĸ����� */
#define SRE_PPE_TNL_HIS_TX_BD_ADDR_WR_CNT_REG  (SRE_PPE_TNL_BASE + 0x808)  /* PPE_HIS_TX_BD_ADDR_WR_CNT�Ǳ�д�뷢����������ַ������ */
#define SRE_PPE_TNL_HIS_RX_REL_BUF_CNT_REG  (SRE_PPE_TNL_BASE + 0x80C)  /* PPE_HIS_RX_REL_BUF_CNT�ǽ����ͷŻ���ĸ����� */
#define SRE_PPE_TNL_HIS_TX_REL_BUF_CNT_REG  (SRE_PPE_TNL_BASE + 0x810)  /* PPE_HIS_TX_REL_BUF_CNT�Ƿ����ͷŻ���ĸ����� */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_0_REG  (SRE_PPE_TNL_BASE + 0x1000)  /* PPE_CFG_L3_TYPE_VALUE_0Ϊ��0��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_0_REG  (SRE_PPE_TNL_BASE + 0x1004)  /* PPE_CFG_L3_TYPE_VALUEΪ��0��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_0_REG  (SRE_PPE_TNL_BASE + 0x1008)  /* PPE_CFG_L3_TYPE_VALUEΪ��0��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_1_REG  (SRE_PPE_TNL_BASE + 0x1010)  /* PPE_CFG_L3_TYPE_VALUE_1Ϊ��1��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_1_REG  (SRE_PPE_TNL_BASE + 0x1014)  /* PPE_CFG_L3_TYPE_VALUEΪ��1��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_1_REG  (SRE_PPE_TNL_BASE + 0x1018)  /* PPE_CFG_L3_TYPE_VALUEΪ��1��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_2_REG  (SRE_PPE_TNL_BASE + 0x1020)  /* PPE_CFG_L3_TYPE_VALUE_2Ϊ��2��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_2_REG  (SRE_PPE_TNL_BASE + 0x1024)  /* PPE_CFG_L3_TYPE_VALUEΪ��2��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_2_REG  (SRE_PPE_TNL_BASE + 0x1028)  /* PPE_CFG_L3_TYPE_VALUEΪ��2��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_3_REG  (SRE_PPE_TNL_BASE + 0x1030)  /* PPE_CFG_L3_TYPE_VALUE_3Ϊ��3��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_3_REG  (SRE_PPE_TNL_BASE + 0x1034)  /* PPE_CFG_L3_TYPE_VALUEΪ��3��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_3_REG  (SRE_PPE_TNL_BASE + 0x1038)  /* PPE_CFG_L3_TYPE_VALUEΪ��3��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_4_REG  (SRE_PPE_TNL_BASE + 0x1040)  /* PPE_CFG_L3_TYPE_VALUE_4Ϊ��4��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_4_REG  (SRE_PPE_TNL_BASE + 0x1044)  /* PPE_CFG_L3_TYPE_VALUEΪ��4��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_4_REG  (SRE_PPE_TNL_BASE + 0x1048)  /* PPE_CFG_L3_TYPE_VALUEΪ��4��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_5_REG  (SRE_PPE_TNL_BASE + 0x1050)  /* PPE_CFG_L3_TYPE_VALUE_5Ϊ��5��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_5_REG  (SRE_PPE_TNL_BASE + 0x1054)  /* PPE_CFG_L3_TYPE_VALUEΪ��5��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_5_REG  (SRE_PPE_TNL_BASE + 0x1058)  /* PPE_CFG_L3_TYPE_VALUEΪ��5��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_6_REG  (SRE_PPE_TNL_BASE + 0x1060)  /* PPE_CFG_L3_TYPE_VALUE_6Ϊ��6��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_6_REG  (SRE_PPE_TNL_BASE + 0x1064)  /* PPE_CFG_L3_TYPE_VALUEΪ��6��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_6_REG  (SRE_PPE_TNL_BASE + 0x1068)  /* PPE_CFG_L3_TYPE_VALUEΪ��7��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_7_REG  (SRE_PPE_TNL_BASE + 0x1070)  /* PPE_CFG_L3_TYPE_VALUE_7Ϊ��7��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_7_REG  (SRE_PPE_TNL_BASE + 0x1074)  /* PPE_CFG_L3_TYPE_VALUEΪ��7��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_7_REG  (SRE_PPE_TNL_BASE + 0x1078)  /* PPE_CFG_L3_TYPE_VALUEΪ��8��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_8_REG  (SRE_PPE_TNL_BASE + 0x1080)  /* PPE_CFG_L3_TYPE_VALUE_8Ϊ��8��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_8_REG  (SRE_PPE_TNL_BASE + 0x1084)  /* PPE_CFG_L3_TYPE_VALUEΪ��8��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_8_REG  (SRE_PPE_TNL_BASE + 0x1088)  /* PPE_CFG_L3_TYPE_VALUEΪ��9��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_9_REG  (SRE_PPE_TNL_BASE + 0x1090)  /* PPE_CFG_L3_TYPE_VALUE_9Ϊ��9��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_9_REG  (SRE_PPE_TNL_BASE + 0x1094)  /* PPE_CFG_L3_TYPE_VALUEΪ��9��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_9_REG  (SRE_PPE_TNL_BASE + 0x1098)  /* PPE_CFG_L3_TYPE_VALUEΪ��9��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_10_REG  (SRE_PPE_TNL_BASE + 0x10A0)  /* PPE_CFG_L3_TYPE_VALUE_10Ϊ��10��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_10_REG  (SRE_PPE_TNL_BASE + 0x10A4)  /* PPE_CFG_L3_TYPE_VALUEΪ��10��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_10_REG  (SRE_PPE_TNL_BASE + 0x10A8)  /* PPE_CFG_L3_TYPE_VALUEΪ��10��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_11_REG  (SRE_PPE_TNL_BASE + 0x10B0)  /* PPE_CFG_L3_TYPE_VALUE_11Ϊ��1��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_11_REG  (SRE_PPE_TNL_BASE + 0x10B4)  /* PPE_CFG_L3_TYPE_VALUEΪ��11��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_11_REG  (SRE_PPE_TNL_BASE + 0x10B8)  /* PPE_CFG_L3_TYPE_VALUEΪ��11��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_12_REG  (SRE_PPE_TNL_BASE + 0x10C0)  /* PPE_CFG_L3_TYPE_VALUE_12Ϊ��12��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_12_REG  (SRE_PPE_TNL_BASE + 0x10C4)  /* PPE_CFG_L3_TYPE_VALUEΪ��12��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_12_REG  (SRE_PPE_TNL_BASE + 0x10C8)  /* PPE_CFG_L3_TYPE_VALUEΪ��12��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_13_REG  (SRE_PPE_TNL_BASE + 0x10D0)  /* PPE_CFG_L3_TYPE_VALUE_13Ϊ��13��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_13_REG  (SRE_PPE_TNL_BASE + 0x10D4)  /* PPE_CFG_L3_TYPE_VALUEΪ��13��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_13_REG  (SRE_PPE_TNL_BASE + 0x10D8)  /* PPE_CFG_L3_TYPE_VALUEΪ��13��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_14_REG  (SRE_PPE_TNL_BASE + 0x10E0)  /* PPE_CFG_L3_TYPE_VALUE_14Ϊ��14��3����������ֵ */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_14_REG  (SRE_PPE_TNL_BASE + 0x10E4)  /* PPE_CFG_L3_TYPE_VALUEΪ��14��3����������ֵ��MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_14_REG  (SRE_PPE_TNL_BASE + 0x10E8)  /* PPE_CFG_L3_TYPE_VALUEΪ��14��3�����͵�ͷ��Э����ƫ��ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_0_REG  (SRE_PPE_TNL_BASE + 0x1100)  /* PPE_CFG_L4_TYPE_VALUE_0Ϊ��0��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_0_REG  (SRE_PPE_TNL_BASE + 0x1104)  /* PPE_CFG_L4_TYPE_VALUE_0Ϊ��0��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_0_REG  (SRE_PPE_TNL_BASE + 0x1108)  /* PPE_CFG_L4_SUB_ID_0Ϊ��0��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_1_REG  (SRE_PPE_TNL_BASE + 0x1110)  /* PPE_CFG_L4_TYPE_VALUE_1Ϊ��1��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_1_REG  (SRE_PPE_TNL_BASE + 0x1114)  /* PPE_CFG_L4_TYPE_VALUE_1Ϊ��1��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_1_REG  (SRE_PPE_TNL_BASE + 0x1118)  /* PPE_CFG_L4_SUB_ID_1Ϊ��1��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_2_REG  (SRE_PPE_TNL_BASE + 0x1120)  /* PPE_CFG_L4_TYPE_VALUE_2Ϊ��2��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_2_REG  (SRE_PPE_TNL_BASE + 0x1124)  /* PPE_CFG_L4_TYPE_VALUE_2Ϊ��2��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_2_REG  (SRE_PPE_TNL_BASE + 0x1128)  /* PPE_CFG_L4_SUB_ID_2Ϊ��2��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_3_REG  (SRE_PPE_TNL_BASE + 0x1130)  /* PPE_CFG_L4_TYPE_VALUE_3Ϊ��3��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_3_REG  (SRE_PPE_TNL_BASE + 0x1134)  /* PPE_CFG_L4_TYPE_VALUE_3Ϊ��3��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_3_REG  (SRE_PPE_TNL_BASE + 0x1138)  /* PPE_CFG_L4_SUB_ID_3Ϊ��3��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_4_REG  (SRE_PPE_TNL_BASE + 0x1140)  /* PPE_CFG_L4_TYPE_VALUE_4Ϊ��4��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_4_REG  (SRE_PPE_TNL_BASE + 0x1144)  /* PPE_CFG_L4_TYPE_VALUE_4Ϊ��4��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_4_REG  (SRE_PPE_TNL_BASE + 0x1148)  /* PPE_CFG_L4_SUB_ID_4Ϊ��4��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_5_REG  (SRE_PPE_TNL_BASE + 0x1150)  /* PPE_CFG_L4_TYPE_VALUE_5Ϊ��5��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_5_REG  (SRE_PPE_TNL_BASE + 0x1154)  /* PPE_CFG_L4_TYPE_VALUE_5Ϊ��5��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_5_REG  (SRE_PPE_TNL_BASE + 0x1158)  /* PPE_CFG_L4_SUB_ID_5Ϊ��5��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_6_REG  (SRE_PPE_TNL_BASE + 0x1160)  /* PPE_CFG_L4_TYPE_VALUE_6Ϊ��6��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_6_REG  (SRE_PPE_TNL_BASE + 0x1164)  /* PPE_CFG_L4_TYPE_VALUE_6Ϊ��6��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_6_REG  (SRE_PPE_TNL_BASE + 0x1168)  /* PPE_CFG_L4_SUB_ID_6Ϊ��6��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_7_REG  (SRE_PPE_TNL_BASE + 0x1170)  /* PPE_CFG_L4_TYPE_VALUE_7Ϊ��7��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_7_REG  (SRE_PPE_TNL_BASE + 0x1174)  /* PPE_CFG_L4_TYPE_VALUE_7Ϊ��7��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_7_REG  (SRE_PPE_TNL_BASE + 0x1178)  /* PPE_CFG_L4_SUB_ID_7Ϊ��7��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_8_REG  (SRE_PPE_TNL_BASE + 0x1180)  /* PPE_CFG_L4_TYPE_VALUE_8Ϊ��8��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_8_REG  (SRE_PPE_TNL_BASE + 0x1184)  /* PPE_CFG_L4_TYPE_VALUE_8Ϊ��8��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_8_REG  (SRE_PPE_TNL_BASE + 0x1188)  /* PPE_CFG_L4_SUB_ID_8Ϊ��8��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_9_REG  (SRE_PPE_TNL_BASE + 0x1190)  /* PPE_CFG_L4_TYPE_VALUE_9Ϊ��9��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_9_REG  (SRE_PPE_TNL_BASE + 0x1194)  /* PPE_CFG_L4_TYPE_VALUE_9Ϊ��9��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_9_REG  (SRE_PPE_TNL_BASE + 0x1198)  /* PPE_CFG_L4_SUB_ID_9Ϊ��9��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_10_REG  (SRE_PPE_TNL_BASE + 0x11A0)  /* PPE_CFG_L4_TYPE_VALUE_10Ϊ��10��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_10_REG  (SRE_PPE_TNL_BASE + 0x11A4)  /* PPE_CFG_L4_TYPE_VALUE_10Ϊ��10��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_10_REG  (SRE_PPE_TNL_BASE + 0x11A8)  /* PPE_CFG_L4_SUB_ID_10Ϊ��10��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_11_REG  (SRE_PPE_TNL_BASE + 0x11B0)  /* PPE_CFG_L4_TYPE_VALUE_11Ϊ��11��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_11_REG  (SRE_PPE_TNL_BASE + 0x11B4)  /* PPE_CFG_L4_TYPE_VALUE_11Ϊ��11��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_11_REG  (SRE_PPE_TNL_BASE + 0x11B8)  /* PPE_CFG_L4_SUB_ID_11Ϊ��11��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_12_REG  (SRE_PPE_TNL_BASE + 0x11C0)  /* PPE_CFG_L4_TYPE_VALUE_12Ϊ��12��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_12_REG  (SRE_PPE_TNL_BASE + 0x11C4)  /* PPE_CFG_L4_TYPE_VALUE_12Ϊ��12��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_12_REG  (SRE_PPE_TNL_BASE + 0x11C8)  /* PPE_CFG_L4_SUB_ID_12Ϊ��12��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_13_REG  (SRE_PPE_TNL_BASE + 0x11D0)  /* PPE_CFG_L4_TYPE_VALUE_13Ϊ��13��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_13_REG  (SRE_PPE_TNL_BASE + 0x11D4)  /* PPE_CFG_L4_TYPE_VALUE_13Ϊ��13��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_13_REG  (SRE_PPE_TNL_BASE + 0x11D8)  /* PPE_CFG_L4_SUB_ID_13Ϊ��13��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_14_REG  (SRE_PPE_TNL_BASE + 0x11E0)  /* PPE_CFG_L4_TYPE_VALUE_14Ϊ��14��4����������ֵ
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_14_REG  (SRE_PPE_TNL_BASE + 0x11E4)  /* PPE_CFG_L4_TYPE_VALUE_14Ϊ��14��4������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_14_REG  (SRE_PPE_TNL_BASE + 0x11E8)  /* PPE_CFG_L4_SUB_ID_14Ϊ��14��4��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_0_REG  (SRE_PPE_TNL_BASE + 0x1200)  /* PPE_CFG_L5_TYPE_VALUE_0Ϊ��0��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_0_REG  (SRE_PPE_TNL_BASE + 0x1204)  /* PPE_CFG_L5_TYPE_VALUE_0Ϊ��0��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_0_REG  (SRE_PPE_TNL_BASE + 0x1208)  /* PPE_CFG_L5_SUB_ID_0Ϊ��0��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_1_REG  (SRE_PPE_TNL_BASE + 0x1210)  /* PPE_CFG_L5_TYPE_VALUE_1Ϊ��1��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_1_REG  (SRE_PPE_TNL_BASE + 0x1214)  /* PPE_CFG_L5_TYPE_VALUE_1Ϊ��1��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_1_REG  (SRE_PPE_TNL_BASE + 0x1218)  /* PPE_CFG_L5_SUB_ID_1Ϊ��1��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_2_REG  (SRE_PPE_TNL_BASE + 0x1220)  /* PPE_CFG_L5_TYPE_VALUE_2Ϊ��2��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_2_REG  (SRE_PPE_TNL_BASE + 0x1224)  /* PPE_CFG_L5_TYPE_VALUE_2Ϊ��2��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_2_REG  (SRE_PPE_TNL_BASE + 0x1228)  /* PPE_CFG_L5_SUB_ID_2Ϊ��2��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_3_REG  (SRE_PPE_TNL_BASE + 0x1230)  /* PPE_CFG_L5_TYPE_VALUE_3Ϊ��3��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_3_REG  (SRE_PPE_TNL_BASE + 0x1234)  /* PPE_CFG_L5_TYPE_VALUE_3Ϊ��3��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_3_REG  (SRE_PPE_TNL_BASE + 0x1238)  /* PPE_CFG_L5_SUB_ID_3Ϊ��3��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_4_REG  (SRE_PPE_TNL_BASE + 0x1240)  /* PPE_CFG_L5_TYPE_VALUE_4Ϊ��4��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_4_REG  (SRE_PPE_TNL_BASE + 0x1244)  /* PPE_CFG_L5_TYPE_VALUE_4Ϊ��4��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_4_REG  (SRE_PPE_TNL_BASE + 0x1248)  /* PPE_CFG_L5_SUB_ID_4Ϊ��4��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_5_REG  (SRE_PPE_TNL_BASE + 0x1250)  /* PPE_CFG_L5_TYPE_VALUE_5Ϊ��5��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_5_REG  (SRE_PPE_TNL_BASE + 0x1254)  /* PPE_CFG_L5_TYPE_VALUE_5Ϊ��5��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_5_REG  (SRE_PPE_TNL_BASE + 0x1258)  /* PPE_CFG_L5_SUB_ID_5Ϊ��5��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_6_REG  (SRE_PPE_TNL_BASE + 0x1260)  /* PPE_CFG_L5_TYPE_VALUE_6Ϊ��6��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_6_REG  (SRE_PPE_TNL_BASE + 0x1264)  /* PPE_CFG_L5_TYPE_VALUE_6Ϊ��6��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_6_REG  (SRE_PPE_TNL_BASE + 0x1268)  /* PPE_CFG_L5_SUB_ID_6Ϊ��6��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_7_REG  (SRE_PPE_TNL_BASE + 0x1270)  /* PPE_CFG_L5_TYPE_VALUE_7Ϊ��7��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_7_REG  (SRE_PPE_TNL_BASE + 0x1274)  /* PPE_CFG_L5_TYPE_VALUE_7Ϊ��7��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_7_REG  (SRE_PPE_TNL_BASE + 0x1278)  /* PPE_CFG_L5_SUB_ID_7Ϊ��7��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_8_REG  (SRE_PPE_TNL_BASE + 0x1280)  /* PPE_CFG_L5_TYPE_VALUE_8Ϊ��8��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_8_REG  (SRE_PPE_TNL_BASE + 0x1284)  /* PPE_CFG_L5_TYPE_VALUE_8Ϊ��8��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_8_REG  (SRE_PPE_TNL_BASE + 0x1288)  /* PPE_CFG_L5_SUB_ID_8Ϊ��8��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_9_REG  (SRE_PPE_TNL_BASE + 0x1290)  /* PPE_CFG_L5_TYPE_VALUE_9Ϊ��9��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_9_REG  (SRE_PPE_TNL_BASE + 0x1294)  /* PPE_CFG_L5_TYPE_VALUE_9Ϊ��9��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_9_REG  (SRE_PPE_TNL_BASE + 0x1298)  /* PPE_CFG_L5_SUB_ID_9Ϊ��9��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_10_REG  (SRE_PPE_TNL_BASE + 0x12A0)  /* PPE_CFG_L5_TYPE_VALUE_10Ϊ��10��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_10_REG  (SRE_PPE_TNL_BASE + 0x12A4)  /* PPE_CFG_L5_TYPE_VALUE_10Ϊ��10��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_10_REG  (SRE_PPE_TNL_BASE + 0x12A8)  /* PPE_CFG_L5_SUB_ID_10Ϊ��10��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_11_REG  (SRE_PPE_TNL_BASE + 0x12B0)  /* PPE_CFG_L5_TYPE_VALUE_11Ϊ��11��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_11_REG  (SRE_PPE_TNL_BASE + 0x12B4)  /* PPE_CFG_L5_TYPE_VALUE_11Ϊ��11��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_11_REG  (SRE_PPE_TNL_BASE + 0x12B8)  /* PPE_CFG_L5_SUB_ID_11Ϊ��11��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_12_REG  (SRE_PPE_TNL_BASE + 0x12C0)  /* PPE_CFG_L5_TYPE_VALUE_12Ϊ��12��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_12_REG  (SRE_PPE_TNL_BASE + 0x12C4)  /* PPE_CFG_L5_TYPE_VALUE_12Ϊ��12��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_12_REG  (SRE_PPE_TNL_BASE + 0x12C8)  /* PPE_CFG_L5_SUB_ID_12Ϊ��12��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_13_REG  (SRE_PPE_TNL_BASE + 0x12D0)  /* PPE_CFG_L5_TYPE_VALUE_13Ϊ��13��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_13_REG  (SRE_PPE_TNL_BASE + 0x12D4)  /* PPE_CFG_L5_TYPE_VALUE_13Ϊ��13��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_13_REG  (SRE_PPE_TNL_BASE + 0x12D8)  /* PPE_CFG_L5_SUB_ID_13Ϊ��13��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_14_REG  (SRE_PPE_TNL_BASE + 0x12E0)  /* PPE_CFG_L5_TYPE_VALUE_14Ϊ��14��5����������ֵ
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_14_REG  (SRE_PPE_TNL_BASE + 0x12E4)  /* PPE_CFG_L5_TYPE_VALUE_14Ϊ��14��5������ֵ��MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_14_REG  (SRE_PPE_TNL_BASE + 0x12E8)  /* PPE_CFG_L5_SUB_ID_14Ϊ��14��5��Ĵ�����������
 */
#define SRE_PPE_TNL_CFG_QOS_TBL_KEY_OFFSET_0_REG  (SRE_PPE_TNL_BASE + 0x4100)  /* PPE_CFG_QOS_TBL0_KEY_OFFSET������QOS�ı�ļ�ֵ�������üĴ���0��0x4100~0x4138�����Ǳ�0~��7������ */
#define SRE_PPE_TNL_CFG_QOS_TBL_KEY_OFFSET_1_REG  (SRE_PPE_TNL_BASE + 0x4108)  /* PPE_CFG_QOS_TBL0_KEY_OFFSET������QOS�ı�ļ�ֵ�������üĴ���0��0x4100~0x4138�����Ǳ�0~��7������ */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET0_0_REG  (SRE_PPE_TNL_BASE + 0x5D00)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���0��0x5D00~0x5D50�����Ǳ�0~��10������ */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET0_1_REG  (SRE_PPE_TNL_BASE + 0x5D08)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���0��0x5D00~0x5D50�����Ǳ�0~��10������ */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET1_0_REG  (SRE_PPE_TNL_BASE + 0x5D04)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���1��0x5D04~0x5D54�����Ǳ�0~��10������ */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET1_1_REG  (SRE_PPE_TNL_BASE + 0x5D0C)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0������GRP��VMID�ı�ļ�ֵ�������üĴ���1��0x5D04~0x5D54�����Ǳ�0~��10������ */



/******************************************************************************/
/*                      PhosphorV600 PCU �Ĵ�������                           */
/******************************************************************************/
#define SRE_GMAC_CF_TX_FIFO_THRSLD_REG   (0x420)  /* CF_TX_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ����� */
#define SRE_GMAC_CF_RX_FIFO_THRSLD_REG   (0x424)  /* CF_RX_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ����� */
#define SRE_GMAC_CF_CFG_FIFO_THRSLD_REG  (0x428)  /* CF_CFG_FIFO_THRSLDΪ����FIFOˮ�߼Ĵ����� */
#define SRE_GMAC_CF_INTRPT_MSK_REG       (0x42C)  /* CF_INTRPT_MSKΪ�ж����μĴ����� */
#define SRE_GMAC_CF_FIFO_CLR_REG         (0x430)  /* CF_FIFO_CLRΪFIFO����Ĵ����� */
#define SRE_GMAC_CF_INTRPT_STAT_REG      (0x434)  /* CF_INTRPT_STATΪ�ж�״̬�Ĵ����� */
#define SRE_GMAC_CF_INTRPT_CLR_REG       (0x438)  /* CF_INTRPT_CLRΪ�ж�����Ĵ����� */
#define SRE_GMAC_BUS_ERR_ADDR_REG        (0x43C)  /* BUS_ERR_ADDRΪ�������ߵ�ַ�� */
#define SRE_GMAC_PCU_MAXFRAME_SIZE_REG   (0x444) /*�������֡�����üĴ���*/
#define SRE_GMAC_TX_DROP_CNT_REG         (0x448)  /* TX_DROP_CNTΪ���ͷ�����FIFO�ն������İ���ͳ�Ƽ������� */
#define SRE_GMAC_RX_OVER_FLOW_CNT_REG    (0x44C)  /* OVER_FLOW_CNTΪ�����FIFO���������İ���ͳ�Ƽ������� */
#define SRE_GMAC_DEBUG_ST_MCH_REG        (0x450)  /* DEBUG_ST_MCH״̬���ϱ��Ĵ����� */
#define SRE_GMAC_FIFO_CURR_STATUS_REG    (0x454)  /* FIFO_CURR_STATUSΪFIFO��ǰ״̬�Ĵ����� */
#define SRE_GMAC_FIFO_HIS_STATUS_REG     (0x458)  /* FIFO_HIS_STATUSΪFIFO��ʷ״̬�Ĵ����� */
#define SRE_GMAC_CF_CFF_DATA_NUM_REG     (0x45C)  /* CF_CFF_DATA_NUMΪ����FIFO���ݸ����Ĵ����� */
#define SRE_GMAC_TX_CS_FAIL_CNT_REG      (0x460)  /* TX_CS_FAIL_CNTΪ�������У���ʧ�ܼ������� */
#define SRE_GMAC_RX_TRANS_PKG_CNT_REG    (0x464)  /* RX_TRANS_PKG_CNTΪ���а��˳ɹ��İ��������� */
#define SRE_GMAC_TX_TRANS_PKG_CNT_REG    (0x468)  /* TX_TRANS_PKG_CNTΪ���а��˳ɹ��İ��������� */
#define SRE_GMAC_RX_ADDR_OVERFLOW_REG    (0x46C)  /* RX_ADDR_OVERFLOWΪд��������FIFO����������� */
#define SRE_GMAC_CF_TX_PAUSE_REG         (0x470)  /* CF_TX_PAUSEΪ�������ؿ��ƼĴ����� */
#define SRE_GMAC_TX_CFF_ADDR_0_REG       (0x488)  /* TX_CFF_ADDR_0Ϊ����������FIFO��ַ�Ĵ���0�� */
#define SRE_GMAC_TX_CFF_ADDR_1_REG       (0x48C)  /* TX_CFF_ADDR_1Ϊ����������FIFO��ַ�Ĵ���1�� */
#define SRE_GMAC_TX_CFF_ADDR_2_REG       (0x490)  /* TX_CFF_ADDR_2Ϊ����������FIFO��ַ�Ĵ���2�� */
#define SRE_GMAC_TX_CFF_ADDR_3_REG       (0x494)  /* TX_CFF_ADDR_3Ϊ����������FIFO��ַ�Ĵ���3�� */
#define SRE_GMAC_RX_CFF_ADDR_REG         (0x4A0)  /* RX_CFF_ADDRΪ��������FIFO��ַ�Ĵ����� */
#define SRE_GMAC_WE_ADDR_REG             (0x4E0)  /* WE_ADDRΪ������������д��ַ�� */
#define SRE_GMAC_RX_BUF_SIZE_REG         (0x4E4)  /* RX_BUF_SIZEΪ���ջ����С�� */
#define SRE_GMAC_BUS_CTRL_REG            (0x4E8)  /* BUS_CTRLΪ���߿��ƼĴ����� */
#define SRE_GMAC_RX_BUF_REQ_ADDR_REG     (0x4EC)  /* RX_BUF_REQ_ADDRΪ���ջ���������ַ�� */
#define SRE_GMAC_RX_CTRL_REG             (0x4F0)  /* RX_CTRLΪ���տ��ƼĴ����� */
#define SRE_GMAC_RX_PKT_MODE_REG         (0x4F4)  /* RX_PKT_MODEΪ���ձ�������ģʽ�� */
#define SRE_GMAC_QOS_MODE_REG            (0x4F8)  /* QOS_MODEΪQOS��Ϣ������ģʽ�� */
#define SRE_GMAC_VLAN_QOS_REG            (0x4FC)  /* VLAN_QOSΪvlan֡�����ȼ���qos�Ĳ��ұ� */
#define SRE_GMAC_IP_QOS_0_REG            (0x500)  /* IP_QOS_0ΪIP֡�����ȼ���qos�Ĳ��ұ�0�� */
#define SRE_GMAC_IP_QOS_1_REG            (0x504)  /* IP_QOS_1ΪIP֡�����ȼ���qos�Ĳ��ұ�11�� */
#define SRE_GMAC_IP_QOS_2_REG            (0x508)  /* IP_QOS_2ΪIP֡�����ȼ���qos�Ĳ��ұ�22�� */
#define SRE_GMAC_IP_QOS_3_REG            (0x50C)  /* IP_QOS_3ΪIP֡�����ȼ���qos�Ĳ��ұ�3�� */
#define SRE_GMAC_IP_QOS_4_REG            (0x510)  /* IP_QOS_4ΪIP֡�����ȼ���qos�Ĳ��ұ�4�� */
#define SRE_GMAC_IP_QOS_5_REG            (0x514)  /* IP_QOS_5ΪIP֡�����ȼ���qos�Ĳ��ұ�55�� */
#define SRE_GMAC_IP_QOS_6_REG            (0x518)  /* IP_QOS_6ΪIP֡�����ȼ���qos�Ĳ��ұ�66�� */
#define SRE_GMAC_IP_QOS_7_REG            (0x51C)  /* IP_QOS_6ΪIP֡�����ȼ���qos�Ĳ��ұ�7�� */
#define SRE_GMAC_GRP_MODE_0_REG          (0x520)  /* GRP_MODEΪgroup��Ϣ������ģʽ�Ĵ���0�� */
#define SRE_GMAC_GRP_MODE_1_REG          (0x524)  /* GRP_MODEΪgroup��Ϣ������ģʽ�Ĵ���1�� */
#define SRE_GMAC_TT_MODE_REG             (0x528)  /* TT_MODEΪtype��Ϣ������ģʽ�� */
#define SRE_GMAC_TAG_MODE_REG            (0x52C)  /* TAG_MODEΪtag��Ϣ������ģʽ�� */
#define SRE_GMAC_TAG_MASK_0_REG          (0x530)  /* TAG_MASK_0Ϊ����tag����ı���ͷ���ֽ������0�� */
#define SRE_GMAC_TAG_MASK_1_REG          (0x534)  /* TAG_MASK_0Ϊ����tag����ı���ͷ���ֽ������1�� */
#define SRE_GMAC_MATCH_MASK_0_REG        (0x538)  /* MATCH_MASK_0Ϊ����ƥ��ı���ͷ���ֽ������0�� */
#define SRE_GMAC_MATCH_TBL_0_REG         (0x540)  /* MATCH_TBL_0Ϊ���б�ͷƥ����ֽڱ�0�� */
#define SRE_GMAC_MATCH_TBL_1_REG         (0x544)  /* MATCH_TBL_1Ϊ���б�ͷƥ����ֽڱ�1�� */
#define SRE_GMAC_MATCH_TBL_2_REG         (0x548)  /* MATCH_TBL_2Ϊ���б�ͷƥ����ֽڱ�2�� */
#define SRE_GMAC_MATCH_TBL_3_REG         (0x54C)  /* MATCH_TBL_3Ϊ���б�ͷƥ����ֽڱ�3�� */
#define SRE_GMAC_MATCH_TBL_4_REG         (0x550)  /* MATCH_TBL_4Ϊ���б�ͷƥ����ֽڱ�4�� */
#define SRE_GMAC_MATCH_TBL_5_REG         (0x554)  /* MATCH_TBL_5Ϊ���б�ͷƥ����ֽڱ�5�� */
#define SRE_GMAC_MATCH_TBL_6_REG         (0x558)  /* MATCH_TBL_6Ϊ���б�ͷƥ����ֽڱ�6�� */
#define SRE_GMAC_MATCH_TBL_7_REG         (0x55C)  /* MATCH_TBL_7Ϊ���б�ͷƥ����ֽڱ�7�� */
#define SRE_GMAC_RXBUF_REQ_TIMER_REG     (0x580)  /* RXBUF_REQ_TIMERΪ���ջ������볬ʱ�Ĵ����� */
#define SRE_GMAC_RX_WE_TIMER_REG         (0x584)  /* RX_PD_TIMERΪ����дwork entryʧ�ܺ�ĳ�ʱ�Ĵ����� */
#define SRE_GMAC_TX_REL_TIMER_REG        (0x588)  /* TX_REL_TIMERΪ��������ͷŻ���ʧ�ܺ�ĳ�ʱ�Ĵ����� */
#define SRE_GMAC_RX_BUFRQ_ERR_CNT_REG    (0x58C)  /* RX_BUFRQ_ERR_CNTΪ���շ������뻺������������ */
#define SRE_GMAC_TX_BUFRL_ERR_CNT_REG    (0x590)  /* RX_BUFRQ_ERR_CNTΪ���ͷ����ͷŻ������������� */
#define SRE_GMAC_TX_WE_ERR_CNT_REG       (0x594)  /* TX_WE_ERR_CNTΪ���ͷ���д��������������������� */
#define SRE_GMAC_RX_GRP_TBL_0_REG        (0x598)  /* RX_GRP_TBL_0Ϊgroupƥ�����0 */
#define SRE_GMAC_RX_GRP_TBL_1_REG        (0x59C)  /* RX_GRP_TBL_1Ϊgroupƥ�����1 */
#define SRE_GMAC_RX_GRP_TBL_2_REG        (0x5A0)  /* RX_GRP_TBL_2Ϊgroupƥ�����2 */
#define SRE_GMAC_RX_GRP_TBL_3_REG        (0x5A4)  /* RX_GRP_TBL_3Ϊgroupƥ�����3 */
#define SRE_GMAC_RX_GRP_TBL_4_REG        (0x5A8)  /* RX_GRP_TBL_4Ϊgroupƥ�����4 */
#define SRE_GMAC_RX_GRP_TBL_5_REG        (0x5AC)  /* RX_GRP_TBL_5Ϊgroupƥ�����5 */
#define SRE_GMAC_RX_GRP_TBL_6_REG        (0x5B0)  /* RX_GRP_TBL_6Ϊgroupƥ�����6 */
#define SRE_GMAC_RX_GRP_TBL_7_REG        (0x5B4)  /* RX_GRP_TBL_7Ϊgroupƥ�����7 */
#define SRE_GMAC_RX_GRP_RES_REG          (0x5B8)  /* RX_GRP_RESΪƥ�������üĴ��� */
#define SRE_GMAC_RX_GRP_MSK_REG          (0x5BC)  /* RX_GRP_MSKΪ�ֽ�ƥ��ģʽ��groupƥ������Ĵ��� */
#define SRE_GMAC_ADDR_FILT_S0_REG        (0x5C0)  /* ADDR_FILT_S0Ϊ��ַ���˷�Χ0����ʼ��ַ */
#define SRE_GMAC_ADDR_FILT_E0_REG        (0x5C4)  /* ADDR_FILT_S0Ϊ��ַ���˷�Χ0�Ľ�����ַ */
#define SRE_GMAC_ADDR_FILT_S1_REG        (0x5C8)  /* ADDR_FILT_S1Ϊ��ַ���˷�Χ1����ʼ��ַ */
#define SRE_GMAC_ADDR_FILT_E1_REG        (0x5CC)  /* ADDR_FILT_S1Ϊ��ַ���˷�Χ1�Ľ�����ַ */
#define SRE_GMAC_ADDR_FILT_S2_REG        (0x5D0)  /* ADDR_FILT_S0Ϊ��ַ���˷�Χ2����ʼ��ַ */
#define SRE_GMAC_ADDR_FILT_E2_REG        (0x5D4)  /* ADDR_FILT_S0Ϊ��ַ���˷�Χ2�Ľ�����ַ */
#define SRE_GMAC_ADDR_FILT_S3_REG        (0x5D8)  /* ADDR_FILT_S1Ϊ��ַ���˷�Χ3����ʼ��ַ */
#define SRE_GMAC_ADDR_FILT_E3_REG        (0x5DC)  /* ADDR_FILT_S1Ϊ��ַ���˷�Χ3�Ľ�����ַ */
#define SRE_GMAC_IDLE_CNT_REG            (0x5E0)  /* ����pause֡���ƼĴ��� */



/******************************************************************************/
/*                      MC XGEM �Ĵ�������                                    */
/******************************************************************************/

#if 0         /* z00202052 */
#define SRE_XGE_BASE                                   (0x128d0000)
#else
#define SRE_XGE_BASE                                   (0xe28d0000)
#endif        /* z00202052 */

#define SRE_XGE_RCI_MODE_CFG_REG                   (0x0)                 /* RCI�Ĵ���ģʽ���üĴ����� */
#define SRE_XGE_MAC_MODE_CONTRL_REG                (0x4)                 /* ����ģʽ���ƼĴ����� */
#define SRE_XGE_TX_TEST_PATTERN_REG                (0x8)                 /* ���Ͳ����ģʽ���üĴ����� */
#define SRE_XGE_MAC_TX_CONTROL_REG                 (0xC)                 /* XGE���Ϳ��ƼĴ����� */
#define SRE_XGE_MAC_TX_PRBS31_INSERT_ONCE_REG      (0x10)                /* ����PRBS31����һ��������ƼĴ��� */
#define SRE_XGE_STP_TX_CONTROL_REG                 (0x18)                /* XGE���Ϳ��ƼĴ���2�� */
#define SRE_XGE_MAC_LONG_FRAME_REG                 (0x24)                /* �����������üĴ����� */
#define SRE_XGE_MAC_GAP_REG                        (0x28)                /* ����϶���üĴ����� */
#define SRE_XGE_MAC_TX_VLAN_TAG_REG                (0x2C)                /* VLAN TAG���üĴ����� */
#define SRE_XGE_MAC_PAUSE_TIME_REG                 (0x34)                /* ����ʱ�����üĴ����� */
#define SRE_XGE_MAC_PAUSE_CONTRL_REG               (0x3C)                /* ����ָʾ���üĴ����� */
#define SRE_XGE_MIB_CONTRL_REG                     (0x40)                /* MIB�������üĴ��� */
#define SRE_XGE_MIB_WR_DATA_REG                    (0x44)                /* MIBд���ݼĴ��� */
#define SRE_XGE_MIB_WR_DATA1_REG                   (0x48)                /* MIBд���ݼĴ���1 */
#define SRE_XGE_MIB_RD_DATA_REG                    (0x4C)                /* MIB�����ݼĴ��� */
#define SRE_XGE_MIB_RD_DATA1_REG                   (0x50)                /* MIB�����ݼĴ���1 */
#define SRE_XGE_MIB_ADDR_REG                       (0x54)                /* MIB��ַ���üĴ��� */
#define SRE_XGE_MAC_SOURCE_ADDR0_REG               (0x58)                /* MACԴ��ַ���üĴ����� */
#define SRE_XGE_MAC_SOURCE_ADDR1_REG               (0x5C)                /* MACԴ��ַ���üĴ����� */
#define SRE_XGE_MAC_INT_REG                        (0x60)                /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define SRE_XGE_MAC_INTMASK_REG                    (0x64)                /* XGE MAC �ж����μĴ��� */
#define SRE_XGE_MAC_STATE_REG                      (0x68)                /* XGE MAC״̬�Ĵ����� */
#define SRE_XGE_MAC_TX_STATE_REG                   (0x6C)                /* XGE MAC״̬�Ĵ����� */
#define SRE_XGE_PCS_PRBS31_INSER_PATTERN_0_REG     (0x94)                /* 10GE PCS PRBS31���β�����������Ĵ���0�� */
#define SRE_XGE_PCS_PRBS31_INSER_PATTERN_1_REG     (0x98)                /* 10GE PCS PRBS31���β�����������Ĵ���1�� */
#define SRE_XGE_PCS_PRBS31_INSER_CYCLE_REG         (0x9C)                /* 10GE PCS PRBS31��β����������üĴ�������������Ŀ���� */
#define SRE_XGE_TEST_PATTERN_SEED_A_0_REG          (0xA4)                /* 10GE PCSα�������ģʽ�������A�Ĵ���0�� */
#define SRE_XGE_TEST_PATTERN_SEED_A_1_REG          (0xA8)                /* 10GE PCSα�������ģʽ�������A�Ĵ���1�� */
#define SRE_XGE_TEST_PATTERN_SEED_B_0_REG          (0xAC)                /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define SRE_XGE_TEST_PATTERN_SEED_B_1_REG          (0xB0)                /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define SRE_XGE_TX_FAULT_REG                       (0xB4)                /* 10GE PCS����ͨ������澯�Ĵ����� */
#define SRE_XGE_TX_STAT_REG                        (0xB8)                /* 10GE PCS����ͨ��״̬�Ĵ����� */
#define SRE_XGE_MAC_SHORT_FRAME_REG                (0xBC)                /* ��̰������üĴ����� */
#define SRE_XGE_DTE_XGXS_TX_CURR_STA_REG           (0xC0)                /* 10GE XGXS����״̬����ǰ״̬�Ĵ����� */
#define SRE_XGE_TIMESTAMP_ESTI_REG                 (0xC4)                /* ����ʱ���ӳٹ��� */
#define SRE_XGE_ASYM_CRT_HIGH_REG                  (0xC8)                /* �ǶԳ�У��ֵ��32λ */
#define SRE_XGE_ASYM_CRT_LOW_REG                   (0xCC)                /* �ǶԳ�У��ֵ��32λ */
#define SRE_XGE_SEQID_REG                          (0xD0)                /* ��ID����ֵ */
#define SRE_XGE_CF_MSB_REG                         (0xD4)                /* ��ID����ֵ */
#define SRE_XGE_TIMESTP_HIGH_REG                   (0xD8)                /* ����ʱ����32��63λ */
#define SRE_XGE_TIMESTP_LOW_REG                    (0xDC)                /* ����ʱ����0��31λ */
#define SRE_XGE_MEM_ADAPT_REG                      (0xE0)                /* memoryʱ�������Ϣ */
#define SRE_XGE_RCI_RX_MODE_CFG_REG                (0x2000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define SRE_XGE_RX_TEST_PATTERN_REG                (0x2004)              /* ���ղ����ģʽ���üĴ����� */
#define SRE_XGE_MAC_RX_CONTROL_REG                 (0x2008)              /* XGE���տ��ƼĴ��� */
#define SRE_XGE_STP_RX_CONTROL_REG                 (0x200C)              /* XGE���տ��ƼĴ���2 */
#define SRE_XGE_MAC_RX_FIFO_REG                    (0x2010)              /* XGE���ղ�FIFON���üĴ��� */
#define SRE_XGE_MAC_RX_VLAN_REG                    (0x2014)              /* XGE���ղ�VLAN���üĴ��� */
#define SRE_XGE_MAC_INT2_REG                       (0x2018)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define SRE_XGE_MAC_INTMASK2_REG                   (0x201C)              /* XGE MAC �ж����μĴ��� */
#define SRE_XGE_MAC_STATE1_REG                     (0x202C)              /* XGE MAC״̬�Ĵ����� */
#define SRE_XGE_MAC_TX_STATE1_REG                  (0x2030)              /* XGE MAC״̬�Ĵ����� */
#define SRE_XGE_PCS_PRBS31_THLD_A_REG              (0x2034)              /* PCS PRBS31������������ֵ���üĴ����� */
#define SRE_XGE_PCS_PRBS31_TB_REG                  (0x2038)              /* PCS PRBS31ʱ�䴰�����üĴ����� */
#define SRE_XGE_PCS_SYNC_LK_CNT_REG                (0x203C)              /* PCS����SYNC�����üĴ����� */
#define SRE_XGE_PCS_CONTROL1_REG                   (0x2040)              /* PCS��PRBS31����ģʽ���ƼĴ���1�� */
#define SRE_XGE_PCS_SYNC_ERR_REG                   (0x2048)              /* ͬ��ͷ����ͳ�ƼĴ����� */
#define SRE_XGE_PCS_TYPE_STA_2_REG                 (0x2050)              /* 10GE PCS 10GBASE_R_PCS״̬�Ĵ����Ĵ���2�� */
#define SRE_XGE_TEST_PATTERN_ERR_CNT_REG           (0x2058)              /* 10GE PCS����ģʽ����������� */
#define SRE_XGE_PCS_ALARM_REG                      (0x205C)              /* PCS�澯�Ĵ����� */
#define SRE_XGE_PCS_STATE_REG                      (0x2060)              /* XGE PCS״̬�Ĵ����� */
#define SRE_XGE_RX_LANE_1_SYNC_CURR_STA_REG        (0x20B8)              /* 10GE XGXSͨ��0/1ͬ��״̬����ǰ״̬�Ĵ����� */
#define SRE_XGE_RX_LANE_2_SYNC_CURR_STA_REG        (0x20BC)              /* 10GE XGXSͨ��2/3ͬ��״̬����ǰ״̬�Ĵ����� */
#define SRE_XGE_RX_DESKEW_CURR_STA_REG             (0x20C0)              /* 10GE XGXSͨ����DESKEW״̬����ǰ״̬�Ĵ����� */
#define SRE_XGE_DTE_XGXS_STA_1_REG                 (0x20C4)              /* 10GE XGXS״̬�Ĵ���1�� */
#define SRE_XGE_DTE_XGXS_RX_LANE0_10B_ERROR_REG    (0x20C8)              /* 10GE XGXS����LANE0/1����������� */
#define SRE_XGE_DTE_XGXS_RX_LANE2_10B_ERROR_REG    (0x20CC)              /* 10GE XGXS����LANE2/3����������� */
#define SRE_XGE_DTE_XGXS_RX_PRJ_ERROR_REG          (0x20D0)              /* 10GE XGXS���շ��򹤳����� */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_REG            (0x20E0)              /* ����ͨ�������źŲ��� */
#define SRE_XGE_UNICAST_ADDR_EN_REG                (0x2290)              /* XGE0���յ�����ַ����ʹ�ܼĴ����� */
#define SRE_XGE_UNICAST_ADDR_EN_HIGH_REG           (0x2294)              /* XGE0���յ������ಥ���㲥��ַ����ʹ�ܼĴ����� */
#define SRE_XGE_TIMESTAMP_INGRESS_REG              (0x2298)              /* XGE0����ʱ���ӳٹ��ơ� */
#define SRE_XGE_NLST_REG                           (0x229C)              /* XGE0���𻷻�FIFO */
#define SRE_XGE_BIT_ERR_REG                        (0x22A0)              /* ��·�쳣ͳ�ƼĴ��� */
#define MC_XGE1_RCI_MODE_CFG_REG                  (0x4000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define MC_XGE1_MAC_MODE_CONTRL_REG               (0x4004)              /* ����ģʽ���ƼĴ����� */
#define MC_XGE1_TX_TEST_PATTERN_REG               (0x4008)              /* ���Ͳ����ģʽ���üĴ����� */
#define MC_XGE1_MAC_TX_CONTROL_REG                (0x400C)              /* XGE���Ϳ��ƼĴ����� */
#define MC_XGE1_MAC_TX_PRBS31_INSERT_ONCE_REG     (0x4010)
#define MC_XGE1_STP_TX_CONTROL_REG                (0x4018)              /* XGE���Ϳ��ƼĴ���2�� */
#define MC_XGE1_MAC_LONG_FRAME_REG                (0x4024)              /* �����������üĴ����� */
#define MC_XGE1_MAC_GAP_REG                       (0x4028)              /* ����϶���üĴ����� */
#define MC_XGE1_MAC_TX_VLAN_TAG_REG               (0x402C)              /* VLAN TAG���üĴ����� */
#define MC_XGE1_MAC_PAUSE_TIME_REG                (0x4034)              /* ����ʱ�����üĴ����� */
#define MC_XGE1_MAC_PAUSE_CONTRL_REG              (0x403C)              /* ����ָʾ���üĴ����� */
#define MC_XGE1_MIB_CONTRL_REG                    (0x4040)              /* MIB�������üĴ��� */
#define MC_XGE1_MIB_WR_DATA_REG                   (0x4044)              /* MIBд���ݼĴ��� */
#define MC_XGE1_MIB_WR_DATA1_REG                  (0x4048)              /* MIBд���ݼĴ���1 */
#define MC_XGE1_MIB_RD_DATA_REG                   (0x404C)              /* MIB�����ݼĴ��� */
#define MC_XGE1_MIB_RD_DATA1_REG                  (0x4050)              /* MIB�����ݼĴ���1 */
#define MC_XGE1_MIB_ADDR_REG                      (0x4054)              /* MIB��ַ���üĴ��� */
#define MC_XGE1_MAC_SOURCE_ADDR0_REG              (0x4058)              /* MACԴ��ַ���üĴ����� */
#define MC_XGE1_MAC_SOURCE_ADDR1_REG              (0x405C)              /* MACԴ��ַ���üĴ����� */
#define MC_XGE1_MAC_INT_REG                       (0x4060)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define MC_XGE1_MAC_INTMASK_REG                   (0x4064)              /* XGE MAC �ж����μĴ��� */
#define MC_XGE1_MAC_STATE_REG                     (0x4068)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE1_MAC_TX_STATE_REG                  (0x406C)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE1_PCS_PRBS31_INSER_PATTERN_0_REG    (0x4094)              /* 10GE PCS PRBS31���β�����������Ĵ���0�� */
#define MC_XGE1_PCS_PRBS31_INSER_PATTERN_1_REG    (0x4098)              /* 10GE PCS PRBS31���β�����������Ĵ���1�� */
#define MC_XGE1_PCS_PRBS31_INSER_CYCLE_REG        (0x409C)              /* 10GE PCS PRBS31��β����������üĴ�������������Ŀ���� */
#define MC_XGE1_TEST_PATTERN_SEED_A_0_REG         (0x40A4)              /* 10GE PCSα�������ģʽ�������A�Ĵ���0�� */
#define MC_XGE1_TEST_PATTERN_SEED_A_1_REG         (0x40A8)              /* 10GE PCSα�������ģʽ�������A�Ĵ���1�� */
#define MC_XGE1_TEST_PATTERN_SEED_B_0_REG         (0x40AC)              /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define MC_XGE1_TEST_PATTERN_SEED_B_1_REG         (0x40B0)              /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define MC_XGE1_TX_FAULT_REG                      (0x40B4)              /* 10GE PCS����ͨ������澯�Ĵ����� */
#define MC_XGE1_TX_STAT_REG                       (0x40B8)              /* 10GE PCS����ͨ��״̬�Ĵ����� */
#define MC_XGE1_MAC_SHORT_FRAME_REG               (0x40BC)              /* ��̰������üĴ����� */
#define MC_XGE1_DTE_XGXS_TX_CURR_STA_REG          (0x40C0)              /* 10GE XGXS����״̬����ǰ״̬�Ĵ����� */
#define MC_XGE1_TIMESTAMP_ESTI_REG                (0x40C4)              /* ����ʱ���ӳٹ��� */
#define MC_XGE1_ASYM_CRT_HIGH_REG                 (0x40C8)              /* �ǶԳ�У��ֵ��32λ */
#define MC_XGE1_ASYM_CRT_LOW_REG                  (0x40CC)              /* �ǶԳ�У��ֵ��32λ */
#define MC_XGE1_SEQID_REG                         (0x40D0)              /* ��ID����ֵ */
#define MC_XGE1_CF_MSB_REG                        (0x40D4)              /* ��ID����ֵ */
#define MC_XGE1_TIMESTP_HIGH_REG                  (0x40D8)              /* ����ʱ����32��63λ */
#define MC_XGE1_TIMESTP_LOW_REG                   (0x40DC)              /* ����ʱ����0��31λ */
#define MC_XGE1_RCI_RX_MODE_CFG_REG               (0x6000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define MC_XGE1_RX_TEST_PATTERN_REG               (0x6004)              /* ���ղ����ģʽ���üĴ����� */
#define MC_XGE1_MAC_RX_CONTROL_REG                (0x6008)              /* XGE���տ��ƼĴ��� */
#define MC_XGE1_STP_RX_CONTROL_REG                (0x600C)              /* XGE���տ��ƼĴ���2 */
#define MC_XGE1_MAC_RX_FIFO_REG                   (0x6010)              /* XGE���ղ�FIFON���üĴ��� */
#define MC_XGE1_MAC_RX_VLAN_REG                   (0x6014)              /* XGE���ղ�VLAN���üĴ��� */
#define MC_XGE1_MAC_INT2_REG                      (0x6018)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define MC_XGE1_MAC_INTMASK2_REG                  (0x601C)              /* XGE MAC �ж����μĴ��� */
#define MC_XGE1_MAC_STATE1_REG                    (0x602C)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE1_MAC_TX_STATE1_REG                 (0x6030)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE1_PCS_PRBS31_THLD_A_REG             (0x6034)              /* PCS PRBS31������������ֵ���üĴ����� */
#define MC_XGE1_PCS_PRBS31_TB_REG                 (0x6038)              /* PCS PRBS31ʱ�䴰�����üĴ����� */
#define MC_XGE1_PCS_SYNC_LK_CNT_REG               (0x603C)              /* PCS����SYNC�����üĴ����� */
#define MC_XGE1_PCS_CONTROL1_REG                  (0x6040)              /* PCS��PRBS31����ģʽ���ƼĴ���1�� */
#define MC_XGE1_PCS_SYNC_ERR_REG                  (0x6048)              /* ͬ��ͷ����ͳ�ƼĴ����� */
#define MC_XGE1_PCS_TYPE_STA_2_REG                (0x6050)              /* 10GE PCS 10GBASE_R_PCS״̬�Ĵ����Ĵ���2�� */
#define MC_XGE1_TEST_PATTERN_ERR_CNT_REG          (0x6058)              /* 10GE PCS����ģʽ����������� */
#define MC_XGE1_PCS_ALARM_REG                     (0x605C)              /* PCS�澯�Ĵ����� */
#define MC_XGE1_PCS_STATE_REG                     (0x6060)              /* XGE PCS״̬�Ĵ����� */
#define MC_XGE1_RX_LANE_1_SYNC_CURR_STA_REG       (0x60B8)              /* 10GE XGXSͨ��0/1ͬ��״̬����ǰ״̬�Ĵ����� */
#define MC_XGE1_RX_LANE_2_SYNC_CURR_STA_REG       (0x60BC)              /* 10GE XGXSͨ��2/3ͬ��״̬����ǰ״̬�Ĵ����� */
#define MC_XGE1_RX_DESKEW_CURR_STA_REG            (0x60C0)              /* 10GE XGXSͨ����DESKEW״̬����ǰ״̬�Ĵ����� */
#define MC_XGE1_DTE_XGXS_STA_1_REG                (0x60C4)              /* 10GE XGXS״̬�Ĵ���1�� */
#define MC_XGE1_DTE_XGXS_RX_LANE0_10B_ERROR_REG   (0x60C8)              /* 10GE XGXS����LANE0/1����������� */
#define MC_XGE1_DTE_XGXS_RX_LANE2_10B_ERROR_REG   (0x60CC)              /* 10GE XGXS����LANE2/3����������� */
#define MC_XGE1_DTE_XGXS_RX_PRJ_ERROR_REG         (0x60D0)              /* 10GE XGXS���շ��򹤳����� */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_1_REG          (0x60E0)              /* ����ͨ�������źŲ��� */
#define MC_XGE1_UNICAST_ADDR_EN_REG               (0x60E4)              /* XGE1���յ�����ַ����ʹ�ܼĴ����� */
#define MC_XGE1_UNICAST_ADDR_EN_HIGH_REG          (0x60E8)              /* XGE1���յ������ಥ���㲥��ַ����ʹ�ܼĴ����� */
#define MC_XGE1_TIMESTAMP_INGRESS_REG             (0x60EC)              /* XGE1����ʱ���ӳٹ��ơ� */
#define MC_XGE1_NLST_REG                          (0x60F0)              /* XGE0���𻷻�FIFO */
#define MC_XGE1_BIT_ERR_REG                       (0x60F4)              /* ��·�쳣ͳ�ƼĴ��� */
#define MC_XGE2_RCI_MODE_CFG_REG                  (0x8000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define MC_XGE2_MAC_MODE_CONTRL_REG               (0x8004)              /* ����ģʽ���ƼĴ����� */
#define MC_XGE2_TX_TEST_PATTERN_REG               (0x8008)              /* ���Ͳ����ģʽ���üĴ����� */
#define MC_XGE2_MAC_TX_CONTROL_REG                (0x800C)              /* XGE���Ϳ��ƼĴ����� */
#define MC_XGE2_MAC_TX_PRBS31_INSERT_ONCE_REG     (0x8010)
#define MC_XGE2_STP_TX_CONTROL_REG                (0x8018)              /* XGE���Ϳ��ƼĴ���2�� */
#define MC_XGE2_MAC_LONG_FRAME_REG                (0x8024)              /* �����������üĴ����� */
#define MC_XGE2_MAC_GAP_REG                       (0x8028)              /* ����϶���üĴ����� */
#define MC_XGE2_MAC_TX_VLAN_TAG_REG               (0x802C)              /* VLAN TAG���üĴ����� */
#define MC_XGE2_MAC_PAUSE_TIME_REG                (0x8034)              /* ����ʱ�����üĴ����� */
#define MC_XGE2_MAC_PAUSE_CONTRL_REG              (0x803C)              /* ����ָʾ���üĴ����� */
#define MC_XGE2_MIB_CONTRL_REG                    (0x8040)              /* MIB�������üĴ��� */
#define MC_XGE2_MIB_WR_DATA_REG                   (0x8044)              /* MIBд���ݼĴ��� */
#define MC_XGE2_MIB_WR_DATA1_REG                  (0x8048)              /* MIBд���ݼĴ���1 */
#define MC_XGE2_MIB_RD_DATA_REG                   (0x804C)              /* MIB�����ݼĴ��� */
#define MC_XGE2_MIB_RD_DATA1_REG                  (0x8050)              /* MIB�����ݼĴ���1 */
#define MC_XGE2_MIB_ADDR_REG                      (0x8054)              /* MIB��ַ���üĴ��� */
#define MC_XGE2_MAC_SOURCE_ADDR0_REG              (0x8058)              /* MACԴ��ַ���üĴ����� */
#define MC_XGE2_MAC_SOURCE_ADDR1_REG              (0x805C)              /* MACԴ��ַ���üĴ����� */
#define MC_XGE2_MAC_INT_REG                       (0x8060)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define MC_XGE2_MAC_INTMASK_REG                   (0x8064)              /* XGE MAC �ж����μĴ��� */
#define MC_XGE2_MAC_STATE_REG                     (0x8068)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE2_MAC_TX_STATE_REG                  (0x806C)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE2_PCS_PRBS31_INSER_PATTERN_0_REG    (0x8094)              /* 10GE PCS PRBS31���β�����������Ĵ���0�� */
#define MC_XGE2_PCS_PRBS31_INSER_PATTERN_1_REG    (0x8098)              /* 10GE PCS PRBS31���β�����������Ĵ���1�� */
#define MC_XGE2_PCS_PRBS31_INSER_CYCLE_REG        (0x809C)              /* 10GE PCS PRBS31��β����������üĴ�������������Ŀ���� */
#define MC_XGE2_TEST_PATTERN_SEED_A_0_REG         (0x80A4)              /* 10GE PCSα�������ģʽ�������A�Ĵ���0�� */
#define MC_XGE2_TEST_PATTERN_SEED_A_1_REG         (0x80A8)              /* 10GE PCSα�������ģʽ�������A�Ĵ���1�� */
#define MC_XGE2_TEST_PATTERN_SEED_B_0_REG         (0x80AC)              /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define MC_XGE2_TEST_PATTERN_SEED_B_1_REG         (0x80B0)              /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define MC_XGE2_TX_FAULT_REG                      (0x80B4)              /* 10GE PCS����ͨ������澯�Ĵ����� */
#define MC_XGE2_TX_STAT_REG                       (0x80B8)              /* 10GE PCS����ͨ��״̬�Ĵ����� */
#define MC_XGE2_MAC_SHORT_FRAME_REG               (0x80BC)              /* ��̰������üĴ����� */
#define MC_XGE2_TIMESTAMP_ESTI_REG                (0x80C4)              /* ����ʱ���ӳٹ��� */
#define MC_XGE2_ASYM_CRT_HIGH_REG                 (0x80C8)              /* �ǶԳ�У��ֵ��32λ */
#define MC_XGE2_ASYM_CRT_LOW_REG                  (0x80CC)              /* �ǶԳ�У��ֵ��32λ */
#define MC_XGE2_SEQID_REG                         (0x80D0)              /* ��ID����ֵ */
#define MC_XGE2_CF_MSB_REG                        (0x80D4)              /* ��ID����ֵ */
#define MC_XGE2_TIMESTP_HIGH_REG                  (0x80D8)              /* ����ʱ����32��63λ */
#define MC_XGE2_TIMESTP_LOW_REG                   (0x80DC)              /* ����ʱ����0��31λ */
#define MC_XGE2_RCI_RX_MODE_CFG_REG               (0xA000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define MC_XGE2_RX_TEST_PATTERN_REG               (0xA004)              /* ���ղ����ģʽ���üĴ����� */
#define MC_XGE2_MAC_RX_CONTROL_REG                (0xA008)              /* XGE���տ��ƼĴ��� */
#define MC_XGE2_STP_RX_CONTROL_REG                (0xA00C)              /* XGE���տ��ƼĴ���2 */
#define MC_XGE2_MAC_RX_FIFO_REG                   (0xA010)              /* XGE���ղ�FIFON���üĴ��� */
#define MC_XGE2_MAC_RX_VLAN_REG                   (0xA014)              /* XGE���ղ�VLAN���üĴ��� */
#define MC_XGE2_MAC_INT2_REG                      (0xA018)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define MC_XGE2_MAC_INTMASK2_REG                  (0xA01C)              /* XGE MAC �ж����μĴ��� */
#define MC_XGE2_MAC_STATE1_REG                    (0xA02C)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE2_MAC_TX_STATE1_REG                 (0xA030)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE2_PCS_PRBS31_THLD_A_REG             (0xA034)              /* PCS PRBS31������������ֵ���üĴ����� */
#define MC_XGE2_PCS_PRBS31_TB_REG                 (0xA038)              /* PCS PRBS31ʱ�䴰�����üĴ����� */
#define MC_XGE2_PCS_SYNC_LK_CNT_REG               (0xA03C)              /* PCS����SYNC�����üĴ����� */
#define MC_XGE2_PCS_CONTROL1_REG                  (0xA040)              /* PCS��PRBS31����ģʽ���ƼĴ���1�� */
#define MC_XGE2_PCS_SYNC_ERR_REG                  (0xA048)              /* ͬ��ͷ����ͳ�ƼĴ����� */
#define MC_XGE2_PCS_TYPE_STA_2_REG                (0xA050)              /* 10GE PCS 10GBASE_R_PCS״̬�Ĵ����Ĵ���2�� */
#define MC_XGE2_TEST_PATTERN_ERR_CNT_REG          (0xA058)              /* 10GE PCS����ģʽ����������� */
#define MC_XGE2_PCS_ALARM_REG                     (0xA05C)              /* PCS�澯�Ĵ����� */
#define MC_XGE2_PCS_STATE_REG                     (0xA060)              /* XGE PCS״̬�Ĵ����� */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_2_REG          (0xA0E0)              /* ����ͨ�������źŲ��� */
#define MC_XGE2_UNICAST_ADDR_EN_REG               (0xA0E4)              /* XGE2���յ�����ַ����ʹ�ܼĴ����� */
#define MC_XGE2_UNICAST_ADDR_EN_HIGH_REG          (0xA0E8)              /* XGE2���յ������ಥ���㲥��ַ����ʹ�ܼĴ����� */
#define MC_XGE2_TIMESTAMP_INGRESS_REG             (0xA0EC)              /* XGE2����ʱ���ӳٹ��ơ� */
#define MC_XGE2_NLST_REG                          (0xA0F0)              /* XGE0���𻷻�FIFO */
#define MC_XGE2_BIT_ERR_REG                       (0xA0F4)              /* ��·�쳣ͳ�ƼĴ��� */
#define MC_XGE3_RCI_MODE_CFG_REG                  (0xC000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define MC_XGE3_MAC_MODE_CONTRL_REG               (0xC004)              /* ����ģʽ���ƼĴ����� */
#define MC_XGE3_TX_TEST_PATTERN_REG               (0xC008)              /* ���Ͳ����ģʽ���üĴ����� */
#define MC_XGE3_MAC_TX_CONTROL_REG                (0xC00C)              /* XGE���Ϳ��ƼĴ����� */
#define MC_XGE3_MAC_TX_PRBS31_INSERT_ONCE_REG     (0xC010)
#define MC_XGE3_STP_TX_CONTROL_REG                (0xC018)              /* XGE���Ϳ��ƼĴ���2�� */
#define MC_XGE3_MAC_LONG_FRAME_REG                (0xC024)              /* �����������üĴ����� */
#define MC_XGE3_MAC_GAP_REG                       (0xC028)              /* ����϶���üĴ����� */
#define MC_XGE3_MAC_TX_VLAN_TAG_REG               (0xC02C)              /* VLAN TAG���üĴ����� */
#define MC_XGE3_MAC_PAUSE_TIME_REG                (0xC034)              /* ����ʱ�����üĴ����� */
#define MC_XGE3_MAC_PAUSE_CONTRL_REG              (0xC03C)              /* ����ָʾ���üĴ����� */
#define MC_XGE3_MIB_CONTRL_REG                    (0xC040)              /* MIB�������üĴ��� */
#define MC_XGE3_MIB_WR_DATA_REG                   (0xC044)              /* MIBд���ݼĴ��� */
#define MC_XGE3_MIB_WR_DATA1_REG                  (0xC048)              /* MIBд���ݼĴ���1 */
#define MC_XGE3_MIB_RD_DATA_REG                   (0xC04C)              /* MIB�����ݼĴ��� */
#define MC_XGE3_MIB_RD_DATA1_REG                  (0xC050)              /* MIB�����ݼĴ���1 */
#define MC_XGE3_MIB_ADDR_REG                      (0xC054)              /* MIB��ַ���üĴ��� */
#define MC_XGE3_MAC_SOURCE_ADDR0_REG              (0xC058)              /* MACԴ��ַ���üĴ����� */
#define MC_XGE3_MAC_SOURCE_ADDR1_REG              (0xC05C)              /* MACԴ��ַ���üĴ����� */
#define MC_XGE3_MAC_INT_REG                       (0xC060)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define MC_XGE3_MAC_INTMASK_REG                   (0xC064)              /* XGE MAC �ж����μĴ��� */
#define MC_XGE3_MAC_STATE_REG                     (0xC068)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE3_MAC_TX_STATE_REG                  (0xC06C)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE3_PCS_PRBS31_INSER_PATTERN_0_REG    (0xC094)              /* 10GE PCS PRBS31���β�����������Ĵ���0�� */
#define MC_XGE3_PCS_PRBS31_INSER_PATTERN_1_REG    (0xC098)              /* 10GE PCS PRBS31���β�����������Ĵ���1�� */
#define MC_XGE3_PCS_PRBS31_INSER_CYCLE_REG        (0xC09C)              /* 10GE PCS PRBS31��β����������üĴ�������������Ŀ���� */
#define MC_XGE3_TEST_PATTERN_SEED_A_0_REG         (0xC0A4)              /* 10GE PCSα�������ģʽ�������A�Ĵ���0�� */
#define MC_XGE3_TEST_PATTERN_SEED_A_1_REG         (0xC0A8)              /* 10GE PCSα�������ģʽ�������A�Ĵ���1�� */
#define MC_XGE3_TEST_PATTERN_SEED_B_0_REG         (0xC0AC)              /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define MC_XGE3_TEST_PATTERN_SEED_B_1_REG         (0xC0B0)              /* 10GE PCSα�������ģʽ�������B�Ĵ���0�� */
#define MC_XGE3_TX_FAULT_REG                      (0xC0B4)              /* 10GE PCS����ͨ������澯�Ĵ����� */
#define MC_XGE3_TX_STAT_REG                       (0xC0B8)              /* 10GE PCS����ͨ��״̬�Ĵ����� */
#define MC_XGE3_MAC_SHORT_FRAME_REG               (0xC0BC)              /* ��̰������üĴ����� */
#define MC_XGE3_TIMESTAMP_ESTI_REG                (0xC0C4)              /* ����ʱ���ӳٹ��� */
#define MC_XGE3_ASYM_CRT_HIGH_REG                 (0xC0C8)              /* �ǶԳ�У��ֵ��32λ */
#define MC_XGE3_ASYM_CRT_LOW_REG                  (0xC0CC)              /* �ǶԳ�У��ֵ��32λ */
#define MC_XGE3_SEQID_REG                         (0xC0D0)              /* ��ID����ֵ */
#define MC_XGE3_CF_MSB_REG                        (0xC0D4)              /* ��ID����ֵ */
#define MC_XGE3_TIMESTP_HIGH_REG                  (0xC0D8)              /* ����ʱ����32��63λ */
#define MC_XGE3_TIMESTP_LOW_REG                   (0xC0DC)              /* ����ʱ����0��31λ */
#define MC_XGE3_RCI_RX_MODE_CFG_REG               (0xE000)              /* RCI�Ĵ���ģʽ���üĴ����� */
#define MC_XGE3_RX_TEST_PATTERN_REG               (0xE004)              /* ���ղ����ģʽ���üĴ����� */
#define MC_XGE3_MAC_RX_CONTROL_REG                (0xE008)              /* XGE���տ��ƼĴ��� */
#define MC_XGE3_STP_RX_CONTROL_REG                (0xE00C)              /* XGE���տ��ƼĴ���2 */
#define MC_XGE3_MAC_RX_FIFO_REG                   (0xE010)              /* XGE���ղ�FIFON���üĴ��� */
#define MC_XGE3_MAC_RX_VLAN_REG                   (0xE014)              /* XGE���ղ�VLAN���üĴ��� */
#define MC_XGE3_MAC_INT2_REG                      (0xE018)              /* XGE MAC�ӿ��жϱ�־�Ĵ��� */
#define MC_XGE3_MAC_INTMASK2_REG                  (0xE01C)              /* XGE MAC �ж����μĴ��� */
#define MC_XGE3_MAC_STATE1_REG                    (0xE02C)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE3_MAC_TX_STATE1_REG                 (0xE030)              /* XGE MAC״̬�Ĵ����� */
#define MC_XGE3_PCS_PRBS31_THLD_A_REG             (0xE034)              /* PCS PRBS31������������ֵ���üĴ����� */
#define MC_XGE3_PCS_PRBS31_TB_REG                 (0xE038)              /* PCS PRBS31ʱ�䴰�����üĴ����� */
#define MC_XGE3_PCS_SYNC_LK_CNT_REG               (0xE03C)              /* PCS����SYNC�����üĴ����� */
#define MC_XGE3_PCS_CONTROL1_REG                  (0xE040)              /* PCS��PRBS31����ģʽ���ƼĴ���1�� */
#define MC_XGE3_PCS_SYNC_ERR_REG                  (0xE048)              /* ͬ��ͷ����ͳ�ƼĴ����� */
#define MC_XGE3_PCS_TYPE_STA_2_REG                (0xE050)              /* 10GE PCS 10GBASE_R_PCS״̬�Ĵ����Ĵ���2�� */
#define MC_XGE3_TEST_PATTERN_ERR_CNT_REG          (0xE058)              /* 10GE PCS����ģʽ����������� */
#define MC_XGE3_PCS_ALARM_REG                     (0xE05C)              /* PCS�澯�Ĵ����� */
#define MC_XGE3_PCS_STATE_REG                     (0xE060)              /* XGE PCS״̬�Ĵ����� */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_3_REG          (0xE0E0)              /* ����ͨ�������źŲ��� */
#define MC_XGE3_UNICAST_ADDR_EN_REG               (0xE0E4)              /* XGE3���յ�����ַ����ʹ�ܼĴ����� */
#define MC_XGE3_UNICAST_ADDR_EN_HIGH_REG          (0xE0E8)              /* XGE3���յ������ಥ���㲥��ַ����ʹ�ܼĴ����� */
#define MC_XGE3_TIMESTAMP_INGRESS_REG             (0xE0EC)              /* XGE3����ʱ���ӳٹ��ơ� */
#define MC_XGE3_NLST_REG                          (0xE0F0)              /* XGE0���𻷻�FIFO */
#define MC_XGE3_BIT_ERR_REG                       (0xE0F4)              /* ��·�쳣ͳ�ƼĴ��� */

/******************************************************************************/
/*                      MC XGEM_ADDR �Ĵ�������                               */
/******************************************************************************/

#define SRE_XGE_UNICAST_ADDR_EN_0_REG              (0x20E4)              /* ���յ�����ַ����ʹ�ܼĴ����� */
#define SRE_XGE_UNICAST_ADDR_EN_1_REG              (0x20E8)              /* ���յ�����ַ����ʹ�ܼĴ����� */
#define SRE_XGE_MULTICAST_ADDR_EN_0_REG            (0x20EC)              /* ���ն��ַ����ʹ�ܼĴ����� */
#define SRE_XGE_UNICAST_ADDR0_REG                  (0x20F0)              /* ���յ�����ַ0�� */
#define SRE_XGE_UNICAST_ADDR0_HIGH_REG             (0x20F4)              /* ���յ�����ַ0�� */
#define SRE_XGE_UNICAST_ADDR1_REG                  (0x20F8)              /* ���յ�����ַ1�� */
#define SRE_XGE_UNICAST_ADDR1_HIGH_REG             (0x20FC)              /* ���յ�����ַ1�� */
#define SRE_XGE_UNICAST_ADDR2_REG                  (0x2100)              /* ���յ�����ַ2�� */
#define SRE_XGE_UNICAST_ADDR2_HIGH_REG             (0x2104)              /* ���յ�����ַ2�� */
#define SRE_XGE_UNICAST_ADDR3_REG                  (0x2108)              /* ���յ�����ַ3�� */
#define SRE_XGE_UNICAST_ADDR3_HIGH_REG             (0x210C)              /* ���յ�����ַ3�� */
#define SRE_XGE_UNICAST_ADDR4_REG                  (0x2110)              /* ���յ�����ַ4�� */
#define SRE_XGE_UNICAST_ADDR4_HIGH_REG             (0x2114)              /* ���յ�����ַ4�� */
#define SRE_XGE_UNICAST_ADDR5_REG                  (0x2118)              /* ���յ�����ַ5�� */
#define SRE_XGE_UNICAST_ADDR5_HIGH_REG             (0x211C)              /* ���յ�����ַ5�� */
#define SRE_XGE_UNICAST_ADDR6_REG                  (0x2120)              /* ���յ�����ַ6�� */
#define SRE_XGE_UNICAST_ADDR6_HIGH_REG             (0x2124)              /* ���յ�����ַ6�� */
#define SRE_XGE_UNICAST_ADDR7_REG                  (0x2128)              /* ���յ�����ַ7�� */
#define SRE_XGE_UNICAST_ADDR7_HIGH_REG             (0x212C)              /* ���յ�����ַ7�� */
#define SRE_XGE_UNICAST_ADDR8_REG                  (0x2130)              /* ���յ�����ַ8�� */
#define SRE_XGE_UNICAST_ADDR8_HIGH_REG             (0x2134)              /* ���յ�����ַ8�� */
#define SRE_XGE_UNICAST_ADDR9_REG                  (0x2138)              /* ���յ�����ַ9�� */
#define SRE_XGE_UNICAST_ADDR9_HIGH_REG             (0x213C)              /* ���յ�����ַ9�� */
#define SRE_XGE_UNICAST_ADDR10_REG                 (0x2140)              /* ���յ�����ַ10�� */
#define SRE_XGE_UNICAST_ADDR10_HIGH_REG            (0x2144)              /* ���յ�����ַ10�� */
#define SRE_XGE_UNICAST_ADDR11_REG                 (0x2148)              /* ���յ�����ַ11�� */
#define SRE_XGE_UNICAST_ADDR11_HIGH_REG            (0x214C)              /* ���յ�����ַ11�� */
#define SRE_XGE_UNICAST_ADDR12_REG                 (0x2150)              /* ���յ�����ַ12�� */
#define SRE_XGE_UNICAST_ADDR12_HIGH_REG            (0x2154)              /* ���յ�����ַ12�� */
#define SRE_XGE_UNICAST_ADDR13_REG                 (0x2158)              /* ���յ�����ַ13�� */
#define SRE_XGE_UNICAST_ADDR13_HIGH_REG            (0x215C)              /* ���յ�����ַ13�� */
#define SRE_XGE_UNICAST_ADDR14_REG                 (0x2160)              /* ���յ�����ַ14�� */
#define SRE_XGE_UNICAST_ADDR14_HIGH_REG            (0x2164)              /* ���յ�����ַ14�� */
#define SRE_XGE_UNICAST_ADDR15_REG                 (0x2168)              /* ���յ�����ַ15�� */
#define SRE_XGE_UNICAST_ADDR15_HIGH_REG            (0x216C)              /* ���յ�����ַ15�� */
#define SRE_XGE_UNICAST_ADDR16_REG                 (0x2170)              /* ���յ�����ַ16�� */
#define SRE_XGE_UNICAST_ADDR16_HIGH_REG            (0x2174)              /* ���յ�����ַ16�� */
#define SRE_XGE_UNICAST_ADDR17_REG                 (0x2178)              /* ���յ�����ַ17�� */
#define SRE_XGE_UNICAST_ADDR17_HIGH_REG            (0x217C)              /* ���յ�����ַ17�� */
#define SRE_XGE_UNICAST_ADDR18_REG                 (0x2180)              /* ���յ�����ַ18�� */
#define SRE_XGE_UNICAST_ADDR18_HIGH_REG            (0x2184)              /* ���յ�����ַ18�� */
#define SRE_XGE_UNICAST_ADDR19_REG                 (0x2188)              /* ���յ�����ַ19�� */
#define SRE_XGE_UNICAST_ADDR19_HIGH_REG            (0x218C)              /* ���յ�����ַ19�� */
#define SRE_XGE_UNICAST_ADDR20_REG                 (0x2190)              /* ���յ�����ַ20�� */
#define SRE_XGE_UNICAST_ADDR20_HIGH_REG            (0x2194)              /* ���յ�����ַ20�� */
#define SRE_XGE_UNICAST_ADDR21_REG                 (0x2198)              /* ���յ�����ַ21�� */
#define SRE_XGE_UNICAST_ADDR21_HIGH_REG            (0x219C)              /* ���յ�����ַ21�� */
#define SRE_XGE_UNICAST_ADDR22_REG                 (0x21A0)              /* ���յ�����ַ22�� */
#define SRE_XGE_UNICAST_ADDR22_HIGH_REG            (0x21A4)              /* ���յ�����ַ22�� */
#define SRE_XGE_UNICAST_ADDR23_REG                 (0x21A8)              /* ���յ�����ַ23�� */
#define SRE_XGE_UNICAST_ADDR23_HIGH_REG            (0x21AC)              /* ���յ�����ַ23�� */
#define SRE_XGE_UNICAST_ADDR24_REG                 (0x21B0)              /* ���յ�����ַ24�� */
#define SRE_XGE_UNICAST_ADDR24_HIGH_REG            (0x21B4)              /* ���յ�����ַ24�� */
#define SRE_XGE_UNICAST_ADDR25_REG                 (0x21B8)              /* ���յ�����ַ25�� */
#define SRE_XGE_UNICAST_ADDR25_HIGH_REG            (0x21BC)              /* ���յ�����ַ25�� */
#define SRE_XGE_UNICAST_ADDR26_REG                 (0x21C0)              /* ���յ�����ַ26�� */
#define SRE_XGE_UNICAST_ADDR26_HIGH_REG            (0x21C4)              /* ���յ�����ַ26�� */
#define SRE_XGE_UNICAST_ADDR27_REG                 (0x21C8)              /* ���յ�����ַ27�� */
#define SRE_XGE_UNICAST_ADDR27_HIGH_REG            (0x21CC)              /* ���յ�����ַ27�� */
#define SRE_XGE_UNICAST_ADDR28_REG                 (0x21D0)              /* ���յ�����ַ28�� */
#define SRE_XGE_UNICAST_ADDR28_HIGH_REG            (0x21D4)              /* ���յ�����ַ28�� */
#define SRE_XGE_UNICAST_ADDR29_REG                 (0x21D8)              /* ���յ�����ַ29�� */
#define SRE_XGE_UNICAST_ADDR29_HIGH_REG            (0x21DC)              /* ���յ�����ַ29�� */
#define SRE_XGE_UNICAST_ADDR30_REG                 (0x21E0)              /* ���յ�����ַ30�� */
#define SRE_XGE_UNICAST_ADDR30_HIGH_REG            (0x21E4)              /* ���յ�����ַ30�� */
#define SRE_XGE_UNICAST_ADDR31_REG                 (0x21E8)              /* ���յ�����ַ31�� */
#define SRE_XGE_UNICAST_ADDR31_HIGH_REG            (0x21EC)              /* ���յ�����ַ31�� */
#define SRE_XGE_UNICAST_ADDR32_REG                 (0x21F0)              /* ���յ�����ַ32�� */
#define SRE_XGE_UNICAST_ADDR32_HIGH_REG            (0x21F4)              /* ���յ�����ַ32�� */
#define SRE_XGE_UNICAST_ADDR33_REG                 (0x21F8)              /* ���յ�����ַ33�� */
#define SRE_XGE_UNICAST_ADDR33_HIGH_REG            (0x21FC)              /* ���յ�����ַ33�� */
#define SRE_XGE_UNICAST_ADDR34_REG                 (0x2200)              /* ���յ�����ַ34�� */
#define SRE_XGE_UNICAST_ADDR34_HIGH_REG            (0x2204)              /* ���յ�����ַ34�� */
#define SRE_XGE_UNICAST_ADDR35_REG                 (0x2208)              /* ���յ�����ַ35�� */
#define SRE_XGE_UNICAST_ADDR35_HIGH_REG            (0x220C)              /* ���յ�����ַ35�� */
#define SRE_XGE_MULTICAST_ADDR0_REG                (0x2210)              /* ���նಥ��ַ0�� */
#define SRE_XGE_MULTICAST_ADDR0_HIGH_REG           (0x2214)              /* ���նಥ��ַ0�� */
#define SRE_XGE_MULTICAST_ADDR1_REG                (0x2218)              /* ���նಥ��ַ1�� */
#define SRE_XGE_MULTICAST_ADDR1_HIGH_REG           (0x221C)              /* ���նಥ��ַ1�� */
#define SRE_XGE_MULTICAST_ADDR2_REG                (0x2220)              /* ���նಥ��ַ2�� */
#define SRE_XGE_MULTICAST_ADDR2_HIGH_REG           (0x2224)              /* ���նಥ��ַ2�� */
#define SRE_XGE_MULTICAST_ADDR3_REG                (0x2228)              /* ���նಥ��ַ3�� */
#define SRE_XGE_MULTICAST_ADDR3_HIGH_REG           (0x222C)              /* ���նಥ��ַ3�� */
#define SRE_XGE_MULTICAST_ADDR4_REG                (0x2230)              /* ���նಥ��ַ4�� */
#define SRE_XGE_MULTICAST_ADDR4_HIGH_REG           (0x2234)              /* ���նಥ��ַ4�� */
#define SRE_XGE_MULTICAST_ADDR5_REG                (0x2238)              /* ���նಥ��ַ5�� */
#define SRE_XGE_MULTICAST_ADDR5_HIGH_REG           (0x223C)              /* ���նಥ��ַ5�� */
#define SRE_XGE_MULTICAST_ADDR6_REG                (0x2240)              /* ���նಥ��ַ6�� */
#define SRE_XGE_MULTICAST_ADDR6_HIGH_REG           (0x2244)              /* ���նಥ��ַ6�� */
#define SRE_XGE_MULTICAST_ADDR7_REG                (0x2248)              /* ���նಥ��ַ7�� */
#define SRE_XGE_MULTICAST_ADDR7_HIGH_REG           (0x224C)              /* ���նಥ��ַ7�� */
#define SRE_XGE_MULTICAST_MSK0_REG                 (0x2250)              /* ���նಥ����0�� */
#define SRE_XGE_MULTICAST_MSK0_HIGH_REG            (0x2254)              /* ���նಥ����0�� */
#define SRE_XGE_MULTICAST_MSK1_REG                 (0x2258)              /* ���նಥ����1�� */
#define SRE_XGE_MULTICAST_MSK1_HIGH_REG            (0x225C)              /* ���նಥ����1�� */
#define SRE_XGE_MULTICAST_MSK2_REG                 (0x2260)              /* ���նಥ����2�� */
#define SRE_XGE_MULTICAST_MSK2_HIGH_REG            (0x2264)              /* ���նಥ����2�� */
#define SRE_XGE_MULTICAST_MSK3_REG                 (0x2268)              /* ���նಥ����3�� */
#define SRE_XGE_MULTICAST_MSK3_HIGH_REG            (0x226C)              /* ���նಥ����3�� */
#define SRE_XGE_MULTICAST_MSK4_REG                 (0x2270)              /* ���նಥ����4�� */
#define SRE_XGE_MULTICAST_MSK4_HIGH_REG            (0x2274)              /* ���նಥ����4�� */
#define SRE_XGE_MULTICAST_MSK5_REG                 (0x2278)              /* ���նಥ����5�� */
#define SRE_XGE_MULTICAST_MSK5_HIGH_REG            (0x227C)              /* ���նಥ����5�� */
#define SRE_XGE_MULTICAST_MSK6_REG                 (0x2280)              /* ���նಥ����6�� */
#define SRE_XGE_MULTICAST_MSK6_HIGH_REG            (0x2284)              /* ���նಥ����6�� */
#define SRE_XGE_MULTICAST_MSK7_REG                 (0x2288)              /* ���նಥ����7�� */
#define SRE_XGE_MULTICAST_MSK7_HIGH_REG            (0x228C)              /* ���նಥ����7�� */

/*                      SERDES1 �Ĵ�������              z00202052            */
/******************************************************************************/
#define SERDES1_BASE_ADDR            (0xe28e0000)

/*                      MDIO �Ĵ���ƫ�Ƶ�ַ����                          */
/******************************************************************************/
#if 0         /* z00202052 */
#define MDIO_BASE_ADDR               (0x128f0000)
#else
#define MDIO_BASE_ADDR               (0xe28f0000)
#endif        /* z00202052 */

#define MDIO_COMMAND_REG            (0x0)          /* MDIO���ƼĴ��� */
#define MDIO_ADDR_REG               (0x4)          /* MDIO��ӵ�ַ�Ĵ��� */
#define MDIO_WDATA_REG              (0x8)          /* MDIOд���ݼĴ��� */
#define MDIO_RDATA_REG              (0xc)          /* MDIO�����ݼĴ��� */
#define MDIO_STA_REG                (0x10)         /* MDIO����״̬�Ĵ��� */


/******************************************************************************/
/*                      PhosphorV600 MDIO PCU �Ĵ�������                      */
/******************************************************************************/
#define SRE_MDIO_CMD_REG                 (0x0)
#define SRE_MDIO_RD_WR_DATA_REG          (0x4)
#define SRE_MDIO_AUTOSCAN_PHY_ADDR_REG   (0x8)
#define SRE_MDIO_CTROL_REG               (0xC)
#define SRE_MDIO_STAT_REG                (0x10)
#define SRE_MDIO_SOFT_RST_MDIO_REG       (0x14)
#define SRE_MDIO_PHY0_ADDR_REG           (0x18)
#define SRE_MDIO_PHY1_ADDR_REG           (0x1C)
#define SRE_MDIO_PHY2_ADDR_REG           (0x20)
#define SRE_MDIO_PHY3_ADDR_REG           (0x24)
#define SRE_MDIO_PHY4_ADDR_REG           (0x28)
#define SRE_MDIO_PHY_TYPE_REG            (0x2C)
#define SRE_MDIO_PHY0_CONTROL_REG        (0x600)
#define SRE_MDIO_PHY0_STATUS_REG         (0x610)
#define SRE_MDIO_PHY0_ID1_REG            (0x620)
#define SRE_MDIO_PHY0_ID2_REG            (0x630)
#define SRE_MDIO_AN0_ADVERTISEMENT_REG   (0x640)
#define SRE_MDIO_LINK0_BASE_PAGE_REG     (0x650)
#define SRE_MDIO_AN0_EXPANSION_REG       (0x660)
#define SRE_MDIO_AN0_NP_TX_REG           (0x670)
#define SRE_MDIO_PHY1_CONTROL_REG        (0x700)
#define SRE_MDIO_PHY1_STATUS_REG         (0x710)
#define SRE_MDIO_PHY1_ID1_REG            (0x720)
#define SRE_MDIO_PHY1_ID2_REG            (0x730)
#define SRE_MDIO_AN1_ADVERTISEMENT_REG   (0x740)
#define SRE_MDIO_LINK1_BASE_PAGE_REG     (0x750)
#define SRE_MDIO_AN1_EXPANSION_REG       (0x760)
#define SRE_MDIO_AN1_NP_TX_REG           (0x770)
#define SRE_MDIO_PHY2_CONTROL_REG        (0x800)
#define SRE_MDIO_PHY2_STATUS_REG         (0x810)
#define SRE_MDIO_PHY2_ID1_REG            (0x820)
#define SRE_MDIO_PHY2_ID2_REG            (0x830)
#define SRE_MDIO_AN2_ADVERTISEMENT_REG   (0x840)
#define SRE_MDIO_LINK2_BASE_PAGE_REG     (0x850)
#define SRE_MDIO_AN2_EXPANSION_REG       (0x860)
#define SRE_MDIO_AN2_NP_TX_REG           (0x870)
#define SRE_MDIO_PHY3_CONTROL_REG        (0x900)
#define SRE_MDIO_PHY3_STATUS_REG         (0x910)
#define SRE_MDIO_PHY3_ID1_REG            (0x920)
#define SRE_MDIO_PHY3_ID2_REG            (0x930)
#define SRE_MDIO_AN3_ADVERTISEMENT_REG   (0x940)
#define SRE_MDIO_LINK3_BASE_PAGE_REG     (0x950)
#define SRE_MDIO_AN3_EXPANSION_REG       (0x960)
#define SRE_MDIO_AN3_NP_TX_REG           (0x970)
#define SRE_MDIO_PHY4_CONTROL_REG        (0xA00)
#define SRE_MDIO_PHY4_STATUS_REG         (0xA10)
#define SRE_MDIO_PHY4_ID1_REG            (0xA20)
#define SRE_MDIO_PHY4_ID2_REG            (0xA30)
#define SRE_MDIO_AN4_ADVERTISEMENT_REG   (0xA40)
#define SRE_MDIO_LINK4_BASE_PAGE_REG     (0xA50)
#define SRE_MDIO_AN4_EXPANSION_REG       (0xA60)
#define SRE_MDIO_AN4_NP_TX_REG           (0xA70)

/*                      SERDES0_L �Ĵ�������            z00202052            */
/******************************************************************************/
#define SERDES0_LOW_BASE_ADDR        (0xe28f2000)

/*                      SERDES0_H �Ĵ�������            z00202052            */
/******************************************************************************/
#define SERDES0_HIGHT_BASE_ADDR      (0xe28f3000)

/*                      IOCTRL0 �Ĵ�������              z00202052            */
/******************************************************************************/
#define IOCTRL0_BASE_ADDR                 (0xe28f4000)

/* PDM ģ��Ĵ������� */
#define SRE_PDM_BASE_ADDR                       (0x10820000)
#define SRE_PDM_ENA                             (SRE_PDM_BASE_ADDR + 0x00 )
#define SRE_PDM_GETPOE_STOP                     (SRE_PDM_BASE_ADDR + 0x04 )
#define SRE_PDM_NODE_CODE                       (SRE_PDM_BASE_ADDR + 0x08 )
#define SRE_PDM_CFG_ENDIAN                      (SRE_PDM_BASE_ADDR + 0x0c )
#define SRE_PDM_CACHE_CFG                       (SRE_PDM_BASE_ADDR + 0x10 )
#define SRE_PDM_CFG_BUS_CTRL                    (SRE_PDM_BASE_ADDR + 0x14 )
#define SRE_PDM_CFG_BUS_TIMEOUT_THRSHLD         (SRE_PDM_BASE_ADDR + 0x18 )
#define SRE_PDM_CFG_STS_TIMEOUT_THRSHLD         (SRE_PDM_BASE_ADDR + 0x1c )
#define SRE_PDM_REFCNT_CTRL                     (SRE_PDM_BASE_ADDR + 0x20 )
#define SRE_PDM_ERR_GROUP                       (SRE_PDM_BASE_ADDR + 0x24 )
#define SRE_PDM_ERR_QOS                         (SRE_PDM_BASE_ADDR + 0x28 )
#define SRE_PDM_ERR_TT                          (SRE_PDM_BASE_ADDR + 0x2c )
#define SRE_PDM_ERR_TAG                         (SRE_PDM_BASE_ADDR + 0x30 )
#define SRE_PDM_NULL_GROUP                      (SRE_PDM_BASE_ADDR + 0x34 )
#define SRE_PDM_NULL_QOS                        (SRE_PDM_BASE_ADDR + 0x38 )
#define SRE_PDM_NULL_TT                         (SRE_PDM_BASE_ADDR + 0x3c )
#define SRE_PDM_NULL_TAG                        (SRE_PDM_BASE_ADDR + 0x40 )
#define SRE_PDM_BYP_GROUP                       (SRE_PDM_BASE_ADDR + 0x44 )
#define SRE_PDM_BYP_QOS                         (SRE_PDM_BASE_ADDR + 0x48 )
#define SRE_PDM_GETPKT_ADDR                     (SRE_PDM_BASE_ADDR + 0x4c )
#define SRE_PDM_ADDPKT_ADDR                     (SRE_PDM_BASE_ADDR + 0x50 )
#define SRE_PDM_ADDSPE_BASE_ADDR                (SRE_PDM_BASE_ADDR + 0x54 )
#define SRE_PDM_BYP_SPACE_TIME                  (SRE_PDM_BASE_ADDR + 0x58 )
#define SRE_PDM_MACSDU_PROC_TIMEOUT_THRSHLD     (SRE_PDM_BASE_ADDR + 0x5c )
#define SRE_PDM_BYP_WATERLINE                   (SRE_PDM_BASE_ADDR + 0x60 )
#define SRE_PDM_GETPOE_CONTFAIL                 (SRE_PDM_BASE_ADDR + 0x64 )
#define SRE_PDM_ADDPOE_CONTFAIL                 (SRE_PDM_BASE_ADDR + 0x68 )
#define SRE_PDM_POE_FAIL_WAIT_TIME              (SRE_PDM_BASE_ADDR + 0x6c )
#define SRE_PDM_POE_OK_WAIT_TIME                (SRE_PDM_BASE_ADDR + 0x70 )
#define SRE_PDM_BMU_BASE_ADDR                   (SRE_PDM_BASE_ADDR + 0x74 )
#define SRE_PDM_GETBMU_POOL_VMID                (SRE_PDM_BASE_ADDR + 0x78 )
#define SRE_PDM_GETBMU_CONTFAIL                 (SRE_PDM_BASE_ADDR + 0x7c )
#define SRE_PDM_BMU_GETFAIL_WAIT_TIME           (SRE_PDM_BASE_ADDR + 0x80 )
#define SRE_PDM_MACETT_ADDR                     (SRE_PDM_BASE_ADDR + 0x84 )
#define SRE_PDM_MACETT_SIZE                     (SRE_PDM_BASE_ADDR + 0x88 )
#define SRE_PDM_MACETT_ITEM_SIZE                (SRE_PDM_BASE_ADDR + 0x8c )
#define SRE_PDM_MACETT_OFFSET                   (SRE_PDM_BASE_ADDR + 0x90 )
#define SRE_PDM_RLCETT_ADDR                     (SRE_PDM_BASE_ADDR + 0x94 )
#define SRE_PDM_RLCETT_SIZE                     (SRE_PDM_BASE_ADDR + 0x98 )
#define SRE_PDM_RLCETT_ITEM_SIZE                (SRE_PDM_BASE_ADDR + 0x9c )
#define SRE_PDM_RLCETT_OFFSET                   (SRE_PDM_BASE_ADDR + 0xa0 )
#define SRE_PDM_VBD_SKIP_SIZE                   (SRE_PDM_BASE_ADDR + 0xa4 )
#define SRE_PDM_MAX_MAC_HEAD_SIZE               (SRE_PDM_BASE_ADDR + 0xa8 )
#define SRE_PDM_MAX_SDU_NUM                     (SRE_PDM_BASE_ADDR + 0xac )
#define SRE_PDM_LCID_BEGIN_END                  (SRE_PDM_BASE_ADDR + 0xb0 )
#define SRE_PDM_ACC_VMID                        (SRE_PDM_BASE_ADDR + 0xb4 )
#define SRE_PDM_HIS_CLR_EN                      (SRE_PDM_BASE_ADDR + 0xb8 )
#define SRE_PDM_AXI_TRACE_ENA                   (SRE_PDM_BASE_ADDR + 0xbc )
#define SRE_PDM_AXI_STAT_CLR                    (SRE_PDM_BASE_ADDR + 0xc0 )
#define SRE_PDM_INTMSK_ERR                      (SRE_PDM_BASE_ADDR + 0xc4 )
#define SRE_PDM_RINT_ERR                        (SRE_PDM_BASE_ADDR + 0xc8 )
#define SRE_PDM_INTSTS_ERR                      (SRE_PDM_BASE_ADDR + 0xcc )
#define SRE_PDM_GET_PKT_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xd0 )
#define SRE_PDM_GET_PKT_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xd4 )
#define SRE_PDM_ADD_PKT_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xd8 )
#define SRE_PDM_ADD_PKT_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xdc )
#define SRE_PDM_ADD_MCE_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xe0 )
#define SRE_PDM_ADD_MCE_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xe4 )
#define SRE_PDM_ADD_BYP_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xe8 )
#define SRE_PDM_ADD_BYP_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xec )
#define SRE_PDM_GET_BUFFOK_CNT                  (SRE_PDM_BASE_ADDR + 0xf0 )
#define SRE_PDM_GET_BUFFFAIL_CNT                (SRE_PDM_BASE_ADDR + 0xf4 )
#define SRE_PDM_RDBD_FAIL_CNT                   (SRE_PDM_BASE_ADDR + 0xf8 )
#define SRE_PDM_MACETT_FAIL_CNT                 (SRE_PDM_BASE_ADDR + 0xfc )
#define SRE_PDM_RLCETT_FAIL_CNT                 (SRE_PDM_BASE_ADDR + 0x100)
#define SRE_PDM_MAC_PDU_OK_CNT                  (SRE_PDM_BASE_ADDR + 0x104)
#define SRE_PDM_MAC_PDU_ERROR_CNT               (SRE_PDM_BASE_ADDR + 0x108)
#define SRE_PDM_BYP_MACSDU_CNT                  (SRE_PDM_BASE_ADDR + 0x10c)
#define SRE_PDM_RLC_PDU_ERROR_CNT               (SRE_PDM_BASE_ADDR + 0x110)
#define SRE_PDM_TM_RLCPDU_CNT                   (SRE_PDM_BASE_ADDR + 0x114)
#define SRE_PDM_AM_UM_RLCPDU_CNT                (SRE_PDM_BASE_ADDR + 0x118)
#define SRE_PDM_CTRL_RLCPDU_CNT                 (SRE_PDM_BASE_ADDR + 0x11c)
#define SRE_PDM_AXI_WR_LATENCY_AVG_STAT         (SRE_PDM_BASE_ADDR + 0x120)
#define SRE_PDM_AXI_RD_LATENCY_AVG_STAT         (SRE_PDM_BASE_ADDR + 0x124)
#define SRE_PDM_AXI_WR_LATENCY_MAX_STAT         (SRE_PDM_BASE_ADDR + 0x128)
#define SRE_PDM_AXI_RD_LATENCY_MAX_STAT         (SRE_PDM_BASE_ADDR + 0x12c)
#define SRE_PDM_AXI_WR_ACC_STAT                 (SRE_PDM_BASE_ADDR + 0x130)
#define SRE_PDM_AXI_RD_ACC_STAT                 (SRE_PDM_BASE_ADDR + 0x134)
#define SRE_PDM_AXI_WCHN0_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x138)
#define SRE_PDM_AXI_WCHN1_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x13c)
#define SRE_PDM_AXI_WCHN2_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x140)
#define SRE_PDM_AXI_WCHN3_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x144)
#define SRE_PDM_AXI_RCHN0_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x148)
#define SRE_PDM_AXI_RCHN1_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x14c)
#define SRE_PDM_AXI_RCHN2_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x150)
#define SRE_PDM_AXI_RCHN3_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x154)
#define SRE_PDM_AXI_RCHN4_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x158)
#define SRE_PDM_AXI_RCHN5_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x15c)
#define SRE_PDM_PKT_PRERD_STATE                 (SRE_PDM_BASE_ADDR + 0x160)
#define SRE_PDM_MAC_PARSE_STATE                 (SRE_PDM_BASE_ADDR + 0x164)
#define SRE_PDM_RLC_PARSE_STATE                 (SRE_PDM_BASE_ADDR + 0x168)
#define SRE_PDM_BUS_BUSY                        (SRE_PDM_BASE_ADDR + 0x16c)
#define SRE_PDM_PKT_FINISH                      (SRE_PDM_BASE_ADDR + 0x170)


/* POE ģ��Ĵ�������ַ */
#if 0         /* z00202052 */
#define SRE_POE_BASE                               (0x12000000)
#define SRE_POE_NORMAL_BASE                        (0x1E000000)
#else
#define SRE_POE_BASE                               (0xe2000000)
#define SRE_POE_NORMAL_BASE                        (0xee000000)
#endif        /* z00202052 */

/******************************************************************************/
/*                      MC POE �Ĵ�������                                     */
/******************************************************************************/
#define SRE_POE_PDM_WORD0_SPE_ADD_0_REG            (SRE_POE_BASE + 0x0)             /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD0_SPE_ADD_1_REG            (SRE_POE_BASE + 0x20)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD1_SPE_ADD_0_REG            (SRE_POE_BASE + 0x4)             /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD1_SPE_ADD_1_REG            (SRE_POE_BASE + 0x24)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD2_SPE_ADD_0_REG            (SRE_POE_BASE + 0x8)             /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD2_SPE_ADD_1_REG            (SRE_POE_BASE + 0x28)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD3_SPE_ADD_0_REG            (SRE_POE_BASE + 0xC)             /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD3_SPE_ADD_1_REG            (SRE_POE_BASE + 0x2C)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD4_SPE_ADD_0_REG            (SRE_POE_BASE + 0x10)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD4_SPE_ADD_1_REG            (SRE_POE_BASE + 0x30)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD5_SPE_ADD_0_REG            (SRE_POE_BASE + 0x14)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD5_SPE_ADD_1_REG            (SRE_POE_BASE + 0x34)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD6_SPE_ADD_0_REG            (SRE_POE_BASE + 0x18)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD6_SPE_ADD_1_REG            (SRE_POE_BASE + 0x38)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_PDM_WORD7_SPE_ADD_0_REG            (SRE_POE_BASE + 0x1C)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
 */
#define SRE_POE_PDM_WORD7_SPE_ADD_1_REG            (SRE_POE_BASE + 0x3C)            /* ������PDMָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
 */

#define POE_PROFILE_DEVICE 1      //POE CPU��д����Ĵ��� 1:0? DEVICE, NORMAL?

#ifdef POE_PROFILE_DEVICE
#define SRE_POE_VCPU_WORD0_WR_CMD_0_REG            (SRE_POE_BASE + 0x2000)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD0_WR_CMD_1_REG            (SRE_POE_BASE + 0x2020)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD1_WR_CMD_0_REG            (SRE_POE_BASE + 0x2004)          /* �߼�CPU��POEģ����д����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD1_WR_CMD_1_REG            (SRE_POE_BASE + 0x2024)          /* �߼�CPU��POEģ����д����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD2_WR_CMD_0_REG            (SRE_POE_BASE + 0x2008)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD2_WR_CMD_1_REG            (SRE_POE_BASE + 0x2028)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD3_WR_CMD_0_REG            (SRE_POE_BASE + 0x200C)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD3_WR_CMD_1_REG            (SRE_POE_BASE + 0x202C)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD4_WR_CMD_0_REG            (SRE_POE_BASE + 0x2010)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD4_WR_CMD_1_REG            (SRE_POE_BASE + 0x2030)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD5_WR_CMD_0_REG            (SRE_POE_BASE + 0x2014)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD5_WR_CMD_1_REG            (SRE_POE_BASE + 0x2034)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD6_WR_CMD_0_REG            (SRE_POE_BASE + 0x2018)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD6_WR_CMD_1_REG            (SRE_POE_BASE + 0x2038)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD7_WR_CMD_0_REG            (SRE_POE_BASE + 0x201C)          /* �߼�CPU��POEģ����д����Ĵ����� */
#define SRE_POE_VCPU_WORD7_WR_CMD_1_REG            (SRE_POE_BASE + 0x203C)          /* �߼�CPU��POEģ����д����Ĵ����� */
#else
#define SRE_POE_VCPU_WORD0_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2000)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD0_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2020)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD1_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2004)          /* �߼�CPU��POEģ����д����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD1_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2024)          /* �߼�CPU��POEģ����д����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD2_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2008)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD2_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2028)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD3_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x200C)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD3_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x202C)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD4_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2010)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD4_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2030)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD5_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2014)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD5_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2034)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD6_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2018)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD6_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2038)          /* �߼�CPU��POEģ����д����Ĵ��� */
#define SRE_POE_VCPU_WORD7_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x201C)          /* �߼�CPU��POEģ����д����Ĵ����� */
#define SRE_POE_VCPU_WORD7_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x203C)          /* �߼�CPU��POEģ����д����Ĵ����� */
#endif

#define SRE_POE_ACC_WORD0_ADD_REG                  (SRE_POE_BASE + 0x2800)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�������������ȫ�����ݽṹΪ׼��ROHC,SEC,PDM,Tring��AQM��ULHDCP,DLHDCP,IMA��������Ӱ�����ר�á� */
#define SRE_POE_ACC_WORD1_ADD_REG                  (SRE_POE_BASE + 0x2804)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����ROHC,SEC,PDM,Tring��AQM��ULHDCP,DLHDCP,IMA��������Ӱ�����ר�á� */
#define SRE_POE_ACC_WORD2_ADD_REG                  (SRE_POE_BASE + 0x2808)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����ROHC,SEC,PDM,Tring��AQM��ULHDCP,DLHDCP,IMA��������Ӱ�����ר�á� */
#define SRE_POE_ACC_WORD3_ADD_REG                  (SRE_POE_BASE + 0x280C)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����ROHC,SEC,PDM,Tring��AQM��ULHDCP,DLHDCP,IMA��������Ӱ�����ר�á� */
#define SRE_POE_TM_SPPE_WORD0_ADD_REG              (SRE_POE_BASE + 0x2820)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�������������ȫ�����ݽṹΪ׼��SPPE��TM��POE,MPE��������Ӱ�����ר�á� */
#define SRE_POE_TM_SPPE_WORD1_ADD_REG              (SRE_POE_BASE + 0x2824)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����SPPE��TM��POE,MPE��������Ӱ�����ר�á� */
#define SRE_POE_TM_SPPE_WORD2_ADD_REG              (SRE_POE_BASE + 0x2828)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����SPPE��TM��POE,MPE��������Ӱ�����ר�á� */
#define SRE_POE_TM_SPPE_WORD3_ADD_REG              (SRE_POE_BASE + 0x282C)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����SPPE��TM��POE,MPE��������Ӱ�����ר�á� */
#define SRE_POE_PPE_WORD0_ADD_REG                  (SRE_POE_BASE + 0x2840)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�������������ȫ�����ݽṹΪ׼��PPE��������Ӱ�����ר�á� */
#define SRE_POE_PPE_WORD1_ADD_REG                  (SRE_POE_BASE + 0x2844)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����PPE��������Ӱ�����ר�á� */
#define SRE_POE_PPE_WORD2_ADD_REG                  (SRE_POE_BASE + 0x2848)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����PPE��������Ӱ�����ר�á� */
#define SRE_POE_PPE_WORD3_ADD_REG                  (SRE_POE_BASE + 0x284C)          /* ��������POEģ������Ӱ������ADD_PACKET����Ĵ�����PPE��������Ӱ�����ר�á�
�����2860~3FFC��ַ���� */

#ifdef POE_PROFILE_DEVICE
#define SRE_POE_VCPU_WORD0_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4000)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD0_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4020)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD0_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6000)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD0_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6020)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4004)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4024)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6004)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6024)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4008)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4028)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6008)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6028)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_0_REG           (SRE_POE_BASE + 0x400C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_1_REG           (SRE_POE_BASE + 0x402C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_2_REG           (SRE_POE_BASE + 0x600C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_3_REG           (SRE_POE_BASE + 0x602C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4010)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4030)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6010)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6030)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4014)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4034)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6014)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6034)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4018)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4038)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6018)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6038)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_0_REG           (SRE_POE_BASE + 0x401C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_1_REG           (SRE_POE_BASE + 0x403C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_2_REG           (SRE_POE_BASE + 0x601C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_3_REG           (SRE_POE_BASE + 0x603C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#else
#define SRE_POE_VCPU_WORD0_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4000)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD0_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4020)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD0_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6000)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD0_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6020)          /* �߼�CPU_0ָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ�����CPU��������Ƿ�ɹ������ȡVCPU_ADD_ST�Ĵ�������ȷ�ϡ� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4004)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4024)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6004)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD1_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6024)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4008)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4028)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6008)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD2_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6028)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x400C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x402C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x600C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD3_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x602C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4010)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4030)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6010)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD4_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6030)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4014)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4034)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6014)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD5_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6034)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4018)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4038)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6018)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD6_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6038)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ��� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x401C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x403C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x601C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#define SRE_POE_VCPU_WORD7_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x603C)          /* �߼�CPUָ��������Ӻ˼���Ϣ��ADD_SPE_WORK����Ĵ���
����0x84000~0x84ffc��ַ���� */
#endif

#define SRE_POE_SEC_WORD0_GET_REG                  (SRE_POE_BASE + 0x85000)         /* POEģ����SEC��GET_POE����Ĵ����� */
#define SRE_POE_SEC_WORD1_GET_REG                  (SRE_POE_BASE + 0x85004)         /* POEģ����SEC��GET_POE����Ĵ����� */
#define SRE_POE_SEC_WORD2_GET_REG                  (SRE_POE_BASE + 0x85008)         /* POEģ����SEC��GET_POE����Ĵ����� */
#define SRE_POE_SEC_WORD3_GET_REG                  (SRE_POE_BASE + 0x8500C)         /* POEģ����SEC��GET_POE����Ĵ����� */
#define SRE_POE_SPPE_WORD0_GET_REG                 (SRE_POE_BASE + 0x85020)         /* POEģ����SPPE��GET_POE����Ĵ����� */
#define SRE_POE_SPPE_WORD1_GET_REG                 (SRE_POE_BASE + 0x85024)         /* POEģ����SPPE��GET_POE����Ĵ����� */
#define SRE_POE_SPPE_WORD2_GET_REG                 (SRE_POE_BASE + 0x85028)         /* POEģ����SPPE��GET_POE����Ĵ����� */
#define SRE_POE_SPPE_WORD3_GET_REG                 (SRE_POE_BASE + 0x8502C)         /* POEģ����SPPE��GET_POE����Ĵ����� */
#define SRE_POE_ROHC_ZIP_WORD0_GET_REG             (SRE_POE_BASE + 0x85040)         /* POEģ����ROHCѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_ZIP_WORD1_GET_REG             (SRE_POE_BASE + 0x85044)         /* POEģ����ROHCѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_ZIP_WORD2_GET_REG             (SRE_POE_BASE + 0x85048)         /* POEģ����ROHCѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_ZIP_WORD3_GET_REG             (SRE_POE_BASE + 0x8504C)         /* POEģ����ROHCѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_UZIP_WORD0_GET_REG            (SRE_POE_BASE + 0x85060)         /* POEģ����ROHC��ѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_UZIP_WORD1_GET_REG            (SRE_POE_BASE + 0x85064)         /* POEģ����ROHC��ѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_UZIP_WORD2_GET_REG            (SRE_POE_BASE + 0x85068)         /* POEģ����ROHC��ѹ����GET_POE����Ĵ����� */
#define SRE_POE_ROHC_UZIP_WORD3_GET_REG            (SRE_POE_BASE + 0x8506C)         /* POEģ����ROHC��ѹ����GET_POE����Ĵ����� */
#define SRE_POE_PDM_WORD0_GET_REG                  (SRE_POE_BASE + 0x85080)         /* POEģ����PDM��GET_POE����Ĵ����� */
#define SRE_POE_PDM_WORD1_GET_REG                  (SRE_POE_BASE + 0x85084)         /* POEģ����PDM��GET_POE����Ĵ����� */
#define SRE_POE_PDM_WORD2_GET_REG                  (SRE_POE_BASE + 0x85088)         /* POEģ����PDM��GET_POE����Ĵ����� */
#define SRE_POE_PDM_WORD3_GET_REG                  (SRE_POE_BASE + 0x8508C)         /* POEģ����PDM��GET_POE����Ĵ����� */
#define SRE_POE_ULHDCP_WORD0_GET_REG               (SRE_POE_BASE + 0x850A0)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_ULHDCP_WORD1_GET_REG               (SRE_POE_BASE + 0x850A4)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_ULHDCP_WORD2_GET_REG               (SRE_POE_BASE + 0x850A8)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_ULHDCP_WORD3_GET_REG               (SRE_POE_BASE + 0x850AC)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_DLHDCP_WORD0_GET_REG               (SRE_POE_BASE + 0x850C0)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_DLHDCP_WORD1_GET_REG               (SRE_POE_BASE + 0x850C4)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_DLHDCP_WORD2_GET_REG               (SRE_POE_BASE + 0x850C8)         /* POEģ����HDCP��GET_POE����Ĵ����� */
#define SRE_POE_DLHDCP_WORD3_GET_REG               (SRE_POE_BASE + 0x850CC)         /* POEģ����HDCP��GET_POE����Ĵ�����
 */
#define SRE_POE_ACC_WORD0_GET_0_REG                (SRE_POE_BASE + 0x850E0)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ�����0x0FC~0x10BC */
#define SRE_POE_ACC_WORD0_GET_1_REG                (SRE_POE_BASE + 0x85100)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ�����0x0FC~0x10BC */
#define SRE_POE_ACC_WORD1_GET_0_REG                (SRE_POE_BASE + 0x850E4)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ����� */
#define SRE_POE_ACC_WORD1_GET_1_REG                (SRE_POE_BASE + 0x85104)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ����� */
#define SRE_POE_ACC_WORD2_GET_0_REG                (SRE_POE_BASE + 0x850E8)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ����� */
#define SRE_POE_ACC_WORD2_GET_1_REG                (SRE_POE_BASE + 0x85108)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ����� */
#define SRE_POE_ACC_WORD3_GET_0_REG                (SRE_POE_BASE + 0x850EC)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ�����
����0x851a0~0x857fc���� */
#define SRE_POE_ACC_WORD3_GET_1_REG                (SRE_POE_BASE + 0x8510C)         /* POEģ����Ԥ��������ACC_{0~5}��GET_POE����Ĵ�����
����0x851a0~0x857fc���� */
#define SRE_POE_VCPU_WORD0_GET_0_REG               (SRE_POE_BASE + 0x85800)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD0_GET_1_REG               (SRE_POE_BASE + 0x85820)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD1_GET_0_REG               (SRE_POE_BASE + 0x85804)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD1_GET_1_REG               (SRE_POE_BASE + 0x85824)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD2_GET_0_REG               (SRE_POE_BASE + 0x85808)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD2_GET_1_REG               (SRE_POE_BASE + 0x85828)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD3_GET_0_REG               (SRE_POE_BASE + 0x8580C)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD3_GET_1_REG               (SRE_POE_BASE + 0x8582C)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD4_GET_0_REG               (SRE_POE_BASE + 0x85810)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD4_GET_1_REG               (SRE_POE_BASE + 0x85830)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD5_GET_0_REG               (SRE_POE_BASE + 0x85814)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD5_GET_1_REG               (SRE_POE_BASE + 0x85834)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD6_GET_0_REG               (SRE_POE_BASE + 0x85818)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD6_GET_1_REG               (SRE_POE_BASE + 0x85838)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD7_GET_0_REG               (SRE_POE_BASE + 0x8581C)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_WORD7_GET_1_REG               (SRE_POE_BASE + 0x8583C)         /* POEģ�����߼�CPU_{0~63}��GET_POE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD0_GET_0_REG             (SRE_POE_BASE + 0x86000)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD0_GET_1_REG             (SRE_POE_BASE + 0x86020)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD0_GET_2_REG             (SRE_POE_BASE + 0x88000)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD0_GET_3_REG             (SRE_POE_BASE + 0x88020)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD1_GET_0_REG             (SRE_POE_BASE + 0x86004)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD1_GET_1_REG             (SRE_POE_BASE + 0x86024)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD1_GET_2_REG             (SRE_POE_BASE + 0x88004)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD1_GET_3_REG             (SRE_POE_BASE + 0x88024)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD2_GET_0_REG             (SRE_POE_BASE + 0x86008)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD2_GET_1_REG             (SRE_POE_BASE + 0x86028)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD2_GET_2_REG             (SRE_POE_BASE + 0x88008)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD2_GET_3_REG             (SRE_POE_BASE + 0x88028)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD3_GET_0_REG             (SRE_POE_BASE + 0x8600C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD3_GET_1_REG             (SRE_POE_BASE + 0x8602C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD3_GET_2_REG             (SRE_POE_BASE + 0x8800C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD3_GET_3_REG             (SRE_POE_BASE + 0x8802C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD4_GET_0_REG             (SRE_POE_BASE + 0x86010)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD4_GET_1_REG             (SRE_POE_BASE + 0x86030)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD4_GET_2_REG             (SRE_POE_BASE + 0x88010)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD4_GET_3_REG             (SRE_POE_BASE + 0x88030)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD5_GET_0_REG             (SRE_POE_BASE + 0x86014)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD5_GET_1_REG             (SRE_POE_BASE + 0x86034)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD5_GET_2_REG             (SRE_POE_BASE + 0x88014)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD5_GET_3_REG             (SRE_POE_BASE + 0x88034)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD6_GET_0_REG             (SRE_POE_BASE + 0x86018)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD6_GET_1_REG             (SRE_POE_BASE + 0x86038)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD6_GET_2_REG             (SRE_POE_BASE + 0x88018)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD6_GET_3_REG             (SRE_POE_BASE + 0x88038)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD7_GET_0_REG             (SRE_POE_BASE + 0x8601C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD7_GET_1_REG             (SRE_POE_BASE + 0x8603C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD7_GET_2_REG             (SRE_POE_BASE + 0x8801C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_Q_WORD7_GET_3_REG             (SRE_POE_BASE + 0x8803C)         /* POEģ���У�CPUָ�����ж�ȡ�����GET_QUEUE����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD0_GET_0_REG           (SRE_POE_BASE + 0x106000)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD0_GET_1_REG           (SRE_POE_BASE + 0x106020)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD0_GET_2_REG           (SRE_POE_BASE + 0x106400)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD0_GET_3_REG           (SRE_POE_BASE + 0x106420)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD1_GET_0_REG           (SRE_POE_BASE + 0x106004)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD1_GET_1_REG           (SRE_POE_BASE + 0x106024)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD1_GET_2_REG           (SRE_POE_BASE + 0x106404)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD1_GET_3_REG           (SRE_POE_BASE + 0x106424)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD2_GET_0_REG           (SRE_POE_BASE + 0x106008)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD2_GET_1_REG           (SRE_POE_BASE + 0x106028)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD2_GET_2_REG           (SRE_POE_BASE + 0x106408)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD2_GET_3_REG           (SRE_POE_BASE + 0x106428)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD3_GET_0_REG           (SRE_POE_BASE + 0x10600C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD3_GET_1_REG           (SRE_POE_BASE + 0x10602C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD3_GET_2_REG           (SRE_POE_BASE + 0x10640C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD3_GET_3_REG           (SRE_POE_BASE + 0x10642C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD4_GET_0_REG           (SRE_POE_BASE + 0x106010)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD4_GET_1_REG           (SRE_POE_BASE + 0x106030)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD4_GET_2_REG           (SRE_POE_BASE + 0x106410)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD4_GET_3_REG           (SRE_POE_BASE + 0x106430)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD5_GET_0_REG           (SRE_POE_BASE + 0x106014)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD5_GET_1_REG           (SRE_POE_BASE + 0x106034)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD5_GET_2_REG           (SRE_POE_BASE + 0x106414)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD5_GET_3_REG           (SRE_POE_BASE + 0x106434)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD6_GET_0_REG           (SRE_POE_BASE + 0x106018)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD6_GET_1_REG           (SRE_POE_BASE + 0x106038)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD6_GET_2_REG           (SRE_POE_BASE + 0x106418)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD6_GET_3_REG           (SRE_POE_BASE + 0x106438)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ����� */
#define SRE_POE_VCPU_GRP_WORD7_GET_0_REG           (SRE_POE_BASE + 0x10601C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ�����
����0x116000~0x3ffffc��ַ���������������üĴ��� */
#define SRE_POE_VCPU_GRP_WORD7_GET_1_REG           (SRE_POE_BASE + 0x10603C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ�����
����0x116000~0x3ffffc��ַ���������������üĴ��� */
#define SRE_POE_VCPU_GRP_WORD7_GET_2_REG           (SRE_POE_BASE + 0x10641C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ�����
����0x116000~0x3ffffc��ַ���������������üĴ��� */
#define SRE_POE_VCPU_GRP_WORD7_GET_3_REG           (SRE_POE_BASE + 0x10643C)        /* POEģ���У�CPUָ��Group��ȡ�����GET_GROUP����Ĵ�����
����0x116000~0x3ffffc��ַ���������������üĴ��� */
#define SRE_POE_GRP_VCPU_MASK_0_REG                (SRE_POE_BASE + 0x400000)        /* POEģ���߼�CPU��Group����Ĵ����� */
#define SRE_POE_GRP_VCPU_MASK_1_REG                (SRE_POE_BASE + 0x400004)        /* POEģ���߼�CPU��Group����Ĵ����� */
#define SRE_POE_GRP_SEC_MASK_REG                   (SRE_POE_BASE + 0x400100)        /* POEģ��SEC��Group����Ĵ����� */
#define SRE_POE_GRP_ROHCZ_MASK_REG                 (SRE_POE_BASE + 0x400104)        /* POEģ��"ROHC��ѹ������"��Group����Ĵ����� */
#define SRE_POE_GRP_ROHCUZ_MASK_REG                (SRE_POE_BASE + 0x400108)        /* POEģ��"ROHC�н�ѹ����"��Group����Ĵ����� */
#define SRE_POE_GRP_SPPE_MASK_REG                  (SRE_POE_BASE + 0x40010C)        /* POEģ��SPPE��Group����Ĵ����� */
#define SRE_POE_GRP_PDM_MASK_REG                   (SRE_POE_BASE + 0x400110)        /* POEģ��PDM��Group����Ĵ����� */
#define SRE_POE_GRP_ULHDCP_MASK_REG                (SRE_POE_BASE + 0x40011C)        /* POEģ��ULHDCP��Group����Ĵ����� */
#define SRE_POE_GRP_DLHDCP_MASK_REG                (SRE_POE_BASE + 0x400120)        /* POEģ��DLHDCP��Group����Ĵ����� */
#define SRE_POE_GRP_ACC_MASK_0_REG                 (SRE_POE_BASE + 0x400124)        /* POEģ��Ԥ��6��������ACC��Group����Ĵ�����
����0x40013C���� */
#define SRE_POE_GRP_ACC_MASK_1_REG                 (SRE_POE_BASE + 0x400128)        /* POEģ��Ԥ��6��������ACC��Group����Ĵ�����
����0x40013C���� */
#define SRE_POE_GRP_BP_TH_0_REG                    (SRE_POE_BASE + 0x400140)        /* POEģ����Group_{0~31}��ѹˮ�����üĴ�����Group�İ��ﵽ������õ�ˮ��ֵʱ��ѹ����ģ�飬Group�в��ٽ���������ӡ� */
#define SRE_POE_GRP_BP_TH_1_REG                    (SRE_POE_BASE + 0x400144)        /* POEģ����Group_{0~31}��ѹˮ�����üĴ�����Group�İ��ﵽ������õ�ˮ��ֵʱ��ѹ����ģ�飬Group�в��ٽ���������ӡ� */
#define SRE_POE_SCH_SEL_CFG_REG                    (SRE_POE_BASE + 0x4001C0)        /* POEģ������㷨ѡ�����üĴ����� */
#define SRE_POE_GRP_SCH_CFG_0_REG                  (SRE_POE_BASE + 0x4001C4)        /* ���������㷨����Group��QoS��ʱ��ÿ��Groupѡ��ĵ����㷨���üĴ���0�� */
#define SRE_POE_GRP_SCH_CFG_1_REG                  (SRE_POE_BASE + 0x4001C8)        /* ���������㷨����Group��QoS��ʱ��ÿ��Groupѡ��ĵ����㷨���üĴ���1�� */
#define SRE_POE_WRR_CFG_0_REG                      (SRE_POE_BASE + 0x4001CC)        /* ���������㷨����Group��QoS��ʱ��POEģ���Group{0~31}����PQ+WRR�㷨���üĴ�����
���ص����㷨ʱ��POE����PQ+WRR�㷨�����üĴ�����
Ȩ��ֵ����Ϊ0ʱ����������ȣ�������������ȳ�����
ע�⣺���ص����㷨����QoS��Group��ʱ��QoS0�ڵ���ʱ������ѡ��PQ����WRR����Ӧ��Ȩ�ر�������Ϊ���㣨WRR_CFG{0}�Ĵ�����q0_weight������Ϊ���㣩��QoS0�е�������ܵ��ȳ�����ȻQoS0�е������޷����ȳ�����
���µ�ַ0x4002CC���� */
#define SRE_POE_WRR_CFG_1_REG                      (SRE_POE_BASE + 0x4001D0)        /* ���������㷨����Group��QoS��ʱ��POEģ���Group{0~31}����PQ+WRR�㷨���üĴ�����
���ص����㷨ʱ��POE����PQ+WRR�㷨�����üĴ�����
Ȩ��ֵ����Ϊ0ʱ����������ȣ�������������ȳ�����
ע�⣺���ص����㷨����QoS��Group��ʱ��QoS0�ڵ���ʱ������ѡ��PQ����WRR����Ӧ��Ȩ�ر�������Ϊ���㣨WRR_CFG{0}�Ĵ�����q0_weight������Ϊ���㣩��QoS0�е�������ܵ��ȳ�����ȻQoS0�е������޷����ȳ�����
���µ�ַ0x4002CC���� */
#define SRE_POE_DDR_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002D0)        /* POE������������Ǹ�VM�����üĴ���
 */
#define SRE_POE_TM_VMID_CFG_REG                    (SRE_POE_BASE + 0x4002D4)        /* POE��������TM��VM�����üĴ�����TM���ĸ�VM�Ŀռ�
 */
#define SRE_POE_TM_ADDR_CFG_REG                    (SRE_POE_BASE + 0x4002D8)        /* POE��������TM�ĵ�ַ���üĴ�������ӵ�TM�ĵ�ַ
 */
#define SRE_POE_AQM_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002DC)        /* POE��������AQM��VM�����üĴ�����AQM���ĸ�VM�Ŀռ�
 */
#define SRE_POE_AQM_ADDR_CFG_REG                   (SRE_POE_BASE + 0x4002E0)        /* POE��������AQM�ĵ�ַ���üĴ�������ӵ�AQM�ĵ�ַ
 */
#define SRE_POE_MPE_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002E4)        /* POE��������MPE��VM�����üĴ�����MPE���ĸ�VM�Ŀռ�
 */
#define SRE_POE_MPE_ADDR_CFG_REG                   (SRE_POE_BASE + 0x4002E8)        /* POE��������MPE�ĵ�ַ���üĴ�������ӵ�MPE�ĵ�ַ
 */
#define SRE_POE_POE_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002EC)        /* POE��������POE��VM�����üĴ�����POE���ĸ�VM�Ŀռ�
 */
#define SRE_POE_POE_ADDR_CFG_REG                   (SRE_POE_BASE + 0x4002F0)        /* POE��������POE�ĵ�ַ���üĴ�������ӵ�POE�ĵ�ַ
 */
#define SRE_POE_SEND_TRY_CNT_REG                   (SRE_POE_BASE + 0x4002F4)        /* POEģ����������TM/AQM/MPE/POE�ϱ��жϵ�������Դ��� */
#define SRE_POE_SEND_TRY_INTER_REG                 (SRE_POE_BASE + 0x4002F8)        /* POEģ���������TM/AQM/MPE/POEʱ�����ʧ�ܣ��ٴ�������ӵļ��ʱ�䣬��POE��ʱ������Ϊ��λ����ʱ������750M�� */
#define SRE_POE_CPU_EVENT_MODE_CFG_REG             (SRE_POE_BASE + 0x4002FC)        /* POEģ�齫CPU��˯��״̬���ѵķ�ʽѡ�� */
#define SRE_POE_CPU_CORE_EVENT_CFG_0_REG           (SRE_POE_BASE + 0x400300)        /* POEģ�����CPU���÷��ʹ����ź�event��CPU��˯��״̬���ѡ�
 */
#define SRE_POE_CPU_CORE_EVENT_CFG_1_REG           (SRE_POE_BASE + 0x400304)        /* POEģ�����CPU���÷��ʹ����ź�event��CPU��˯��״̬���ѡ�
 */
#define SRE_POE_SEND_TM_OUT_CNT_CFG_REG            (SRE_POE_BASE + 0x400340)        /* POEģ�齫��������TM��outstanding�������üĴ������������Ϊ4 */
#define SRE_POE_SEND_MPE_OUT_CNT_CFG_REG           (SRE_POE_BASE + 0x400344)        /* POEģ�齫��������MPE��outstanding�������üĴ������������Ϊ4 */
#define SRE_POE_SEND_POE_OUT_CNT_CFG_REG           (SRE_POE_BASE + 0x400348)        /* POEģ�齫��������POE��outstanding�������üĴ������������Ϊ4
����0x40034C��0x4003D0���� */
#define SRE_POE_GRP_INT_CNT_CFG_0_REG              (SRE_POE_BASE + 0x4003D4)        /* POEģ��Input-queue�ж�ˮ�����üĴ�������group{0~31}�е���������ﵽ����趨ֵ��ʱ���Ǽ����������Group������Ч�߼��ߡ���CPU�����Group���ϱ��жϡ� */
#define SRE_POE_GRP_INT_CNT_CFG_1_REG              (SRE_POE_BASE + 0x4003D8)        /* POEģ��Input-queue�ж�ˮ�����üĴ�������group{0~31}�е���������ﵽ����趨ֵ��ʱ���Ǽ����������Group������Ч�߼��ߡ���CPU�����Group���ϱ��жϡ� */
#define SRE_POE_INPUT_TMOUT_CFG_REG                (SRE_POE_BASE + 0x400454)        /* POEģ�����񻺴���У�input_queue���У���ʱ���üĴ�������ʱ�ϱ��жϡ� */
#define SRE_POE_INFLIGHT_TMOUT_CFG_REG             (SRE_POE_BASE + 0x400458)        /* POEģ��in-flight������г�ʱ���üĴ�������ʱ�ϱ��жϡ� */
#define SRE_POE_DESCH_TMOUT_CFG_REG                (SRE_POE_BASE + 0x40045C)        /* POEģ�������񻺴���г�ʱ���üĴ�������ʱ�ϱ��жϡ� */
#define SRE_POE_INIT_RAM_START_REG                 (SRE_POE_BASE + 0x400460)        /* POEģ��ĳ�ʼ���Ĵ�������POE�ڲ�RAM���г�ʼ�� */
#define SRE_POE_INIT_RAM_DONE_REG                  (SRE_POE_BASE + 0x400464)        /* POEģ��ĳ�ʼ������״̬�Ĵ����� */
#define SRE_POE_GRP_ORDER_EN_0_REG                 (SRE_POE_BASE + 0x400468)        /* POEģ��Group�Ƿ������üĴ���������0x4004E8~0x400570���� */
#define SRE_POE_GRP_ORDER_EN_1_REG                 (SRE_POE_BASE + 0x40046C)        /* POEģ��Group�Ƿ������üĴ���������0x4004E8~0x400570���� */
#define SRE_POE_Q_BP_TH_ST_0_REG                   (SRE_POE_BASE + 0x400574)        /* POEģ����queue�ߵ�ˮ���ж�״̬�Ĵ�����
 */
#define SRE_POE_Q_BP_TH_ST_1_REG                   (SRE_POE_BASE + 0x400578)        /* POEģ����queue�ߵ�ˮ���ж�״̬�Ĵ�����
 */
#define SRE_POE_Q_BP_PARI_ERR_Q_REG                (SRE_POE_BASE + 0x400594)        /* POEģ����Q_BP_TH��ѹˮ�ߵ�RAM������żУ�����ʱ����¼������кżĴ�����
����0x400598~0x4006f8���� */
#define SRE_POE_CORE_MSG_BIT_REG                   (SRE_POE_BASE + 0x4006FC)        /* CPU����POE��λ�����üĴ�������128bit������256bit���������ܻ�ϲ�����
 */
#define SRE_POE_OVER_BASE_ADDR_GRP_0_REG           (SRE_POE_BASE + 0x400700)        /* POEģ����group�������ַ���üĴ����� */
#define SRE_POE_OVER_BASE_ADDR_GRP_1_REG           (SRE_POE_BASE + 0x400704)        /* POEģ����group�������ַ���üĴ����� */
#define SRE_POE_OVER_LEN_GRP_0_REG                 (SRE_POE_BASE + 0x400780)        /* POEģ����group����ռ��С���üĴ����� */
#define SRE_POE_OVER_LEN_GRP_1_REG                 (SRE_POE_BASE + 0x400784)        /* POEģ����group����ռ��С���üĴ����� */
#define SRE_POE_OVER_DDR_INIT_START_REG            (SRE_POE_BASE + 0x400800)        /* POEģ����group�������ַ�ĳ�ʼ�����üĴ����� */
#define SRE_POE_OVER_DDR_INIT_DONE_REG             (SRE_POE_BASE + 0x400804)        /* POEģ����group�������ַ���üĴ�����
����0x400808~4008F4���� */
#define SRE_POE_INIT_BP_TH_START_REG               (SRE_POE_BASE + 0x4008F8)        /* POEģ��ĳ�ʼ���Ĵ�������POE�ڲ�Q_BP_TH��RAM���г�ʼ�� */
#define SRE_POE_INIT_BP_TH_DONE_REG                (SRE_POE_BASE + 0x4008FC)        /* POEģ��ĳ�ʼ������״̬�Ĵ������鿴Q_BP_TH��RAM�Ƿ��ʼ����� */
#define SRE_POE_Q_BP_TH_H_0_REG                    (SRE_POE_BASE + 0x400900)        /* POEģ����queue�жϸ�ˮ�ߡ�Memoryʵ�֡�
�˼Ĵ�������ǰ����������INIT_RAM_START��ʼ���ڲ�RAM������ͬʱ��д�˼Ĵ������������ͬʱ��д��д���ȣ������ݷ���ȫ�㡣 */
#define SRE_POE_Q_BP_TH_H_1_REG                    (SRE_POE_BASE + 0x400904)        /* POEģ����queue�жϸ�ˮ�ߡ�Memoryʵ�֡�
�˼Ĵ�������ǰ����������INIT_RAM_START��ʼ���ڲ�RAM������ͬʱ��д�˼Ĵ������������ͬʱ��д��д���ȣ������ݷ���ȫ�㡣 */
#define SRE_POE_Q_BP_TH_L_0_REG                    (SRE_POE_BASE + 0x400D00)        /* POEģ����queue�жϵ�ˮ�ߡ�Memoryʵ�֡�
�˼Ĵ�������ǰ����������INIT_RAM_START��ʼ���ڲ�RAM������ͬʱ��д�˼Ĵ������������ͬʱ��д��д���ȣ������ݷ���ȫ�㡣
 */
#define SRE_POE_Q_BP_TH_L_1_REG                    (SRE_POE_BASE + 0x400D04)        /* POEģ����queue�жϵ�ˮ�ߡ�Memoryʵ�֡�
�˼Ĵ�������ǰ����������INIT_RAM_START��ʼ���ڲ�RAM������ͬʱ��д�˼Ĵ������������ͬʱ��д��д���ȣ������ݷ���ȫ�㡣
 */
#define SRE_POE_MEM_TIMING_CFG_REG                 (SRE_POE_BASE + 0x401100)        /* POEģ����Memoryʱ��������üĴ�����
 */
#define SRE_POE_CORE_INT_ENABLE_0_REG              (SRE_POE_BASE + 0x401104)        /* POEģ��Core{0~15}�ж�ʹ�ܼĴ������ж�ʹ�ܺ��ж�״̬�����ϱ���CPU�� */
#define SRE_POE_CORE_INT_ENABLE_1_REG              (SRE_POE_BASE + 0x401108)        /* POEģ��Core{0~15}�ж�ʹ�ܼĴ������ж�ʹ�ܺ��ж�״̬�����ϱ���CPU�� */
#define SRE_POE_CORE_INTS_0_REG                    (SRE_POE_BASE + 0x401204)        /* POEģ��Core{0~15}�ж�״̬�Ĵ������ж�״̬�ϱ���Core */
#define SRE_POE_CORE_INTS_1_REG                    (SRE_POE_BASE + 0x401208)        /* POEģ��Core{0~15}�ж�״̬�Ĵ������ж�״̬�ϱ���Core */
#define SRE_POE_COMMON_INT_ENABLE_REG              (SRE_POE_BASE + 0x401304)        /* POEģ��Ĺ����ж�ʹ�ܼĴ������ж�ʹ�ܺ��ж�״̬�����ϱ�CPU�� */
#define SRE_POE_COMMON_INTS_REG                    (SRE_POE_BASE + 0x401308)        /* POEģ��Ĺ����ж�״̬�Ĵ�����
 */
#define SRE_POE_CORE_INTS_INFO_0_REG               (SRE_POE_BASE + 0x40130C)        /* POEģ��Core{0~15}�ж�״̬��Ϣ�Ĵ�������¼�ж϶�Ӧ��״̬��Ϣ */
#define SRE_POE_CORE_INTS_INFO_1_REG               (SRE_POE_BASE + 0x401310)        /* POEģ��Core{0~15}�ж�״̬��Ϣ�Ĵ�������¼�ж϶�Ӧ��״̬��Ϣ */
#define SRE_POE_COMMON_INTS_INFO_1_REG             (SRE_POE_BASE + 0x40140C)        /* POEģ�鹫���ж�״̬��Ϣ�Ĵ�������¼�ж϶�Ӧ��״̬��Ϣ������bufferָ�롣
 */
#define SRE_POE_COMMON_INTS_INFO_2_REG             (SRE_POE_BASE + 0x401410)        /* POEģ�鹫���ж�״̬��Ϣ�Ĵ�������¼�ж϶�Ӧ��״̬��Ϣ�������ڱ�������е���Ϣ��
����0x401414~41FFFC������������ģ��״̬�Ĵ��� */
#define SRE_POE_VCPU_INF0_0_REG                    (SRE_POE_BASE + 0x420000)        /* POEģ�����߼�CPU_{0~63}�ĵ�ǰ����Ϣ�Ĵ���0�� */
#define SRE_POE_VCPU_INF0_1_REG                    (SRE_POE_BASE + 0x420008)        /* POEģ�����߼�CPU_{0~63}�ĵ�ǰ����Ϣ�Ĵ���0�� */
#define SRE_POE_VCPU_INF1_0_REG                    (SRE_POE_BASE + 0x420004)        /* POEģ�����߼�CPU_{0~63}�ĵ�ǰ����Ϣ�Ĵ���1�� */
#define SRE_POE_VCPU_INF1_1_REG                    (SRE_POE_BASE + 0x42000C)        /* POEģ�����߼�CPU_{0~63}�ĵ�ǰ����Ϣ�Ĵ���1�� */
#define SRE_POE_GROUP_CNT_0_REG                    (SRE_POE_BASE + 0x420200)        /* GROUP_{0~31}�е��������������8��QoS���У��Ĵ��� */
#define SRE_POE_GROUP_CNT_1_REG                    (SRE_POE_BASE + 0x420204)        /* GROUP_{0~31}�е��������������8��QoS���У��Ĵ��� */
#define SRE_POE_RC_EN_CFG_REG                      (SRE_POE_BASE + 0x420280)        /* POEģ���ж���Ĵ�����ʹ�����üĴ�������ʹ��ʱ����������Ĵ�����ʱ�����㡣 */
#define SRE_POE_ADD_FAIL_CNT_REG                   (SRE_POE_BASE + 0x420284)        /* POEģ������ADD�������ʧ��ͳ�ƼĴ����� */
#define SRE_POE_ADD_OK_CNT_REG                     (SRE_POE_BASE + 0x420288)        /* POEģ������ADD������ӳɹ�ͳ�ƼĴ����� */
#define SRE_POE_INFLIGHT_FREE_ST_REG               (SRE_POE_BASE + 0x42028C)        /* POEģ����in-flight�е�״̬�Ĵ�����512��Entry���ж��ٸ�ûʹ�ã�512��������л��ж��ٸ�ûʹ�á� */
#define SRE_POE_VCPU_ADD_ST_0_REG                  (SRE_POE_BASE + 0x420290)        /* 64���߼�CPU��POE�������ĳɹ�/ʧ��״̬�Ĵ���
 */
#define SRE_POE_VCPU_ADD_ST_1_REG                  (SRE_POE_BASE + 0x420294)        /* 64���߼�CPU��POE�������ĳɹ�/ʧ��״̬�Ĵ���
 */
#define SRE_POE_INPUT_Q_GRP_EMP_REG                (SRE_POE_BASE + 0x420390)        /* POEģ����INPUT_Qģ����group�Ŀ��źš� */
#define SRE_POE_DES_FIFO_GRP_EMP_REG               (SRE_POE_BASE + 0x420394)        /* POEģ����DESCHEDULE FIFOģ����group�Ŀ��źš� */
#define SRE_POE_OV_Q_GRP_EMP_REG                   (SRE_POE_BASE + 0x420398)        /* POEģ����OV_Qbuffer��group�Ŀ��źš� */
#define SRE_POE_DDR_GRP_EMP_REG                    (SRE_POE_BASE + 0x42039C)        /* POEģ����DDR����ռ�ģ����group�Ŀ��źš� */
#define SRE_POE_VCPU_INF2_0_REG                    (SRE_POE_BASE + 0x4203A0)        /* POEģ�����߼�CPU_{0~63}�ĵ�ǰ����Ϣ�Ĵ���2��buffer��ַ��Ϣ��
����0x4204A0~0x440000���� */
#define SRE_POE_VCPU_INF2_1_REG                    (SRE_POE_BASE + 0x4203A4)        /* POEģ�����߼�CPU_{0~63}�ĵ�ǰ����Ϣ�Ĵ���2��buffer��ַ��Ϣ��
����0x4204A0~0x440000���� */
#define SRE_POE_DEBUG_CMD_FIFO_CNT_REG             (SRE_POE_BASE + 0x440000)        /* POEģ���CMD_FIFO���л��ж��ٸ���������δִ�С� */
#define SRE_POE_DEBUG_SEND_TM_REG                  (SRE_POE_BASE + 0x440004)        /* POEģ�����������TM��debug�Ĵ����� */
#define SRE_POE_DEBUG_SEND_AQM_REG                 (SRE_POE_BASE + 0x440008)        /* POEģ�����������AQM��debug�Ĵ����� */
#define SRE_POE_DEBUG_SEND_MPE_REG                 (SRE_POE_BASE + 0x44000C)        /* POEģ�����������MPE��debug�Ĵ����� */
#define SRE_POE_DEBUG_SEND_POE_REG                 (SRE_POE_BASE + 0x440010)        /* POEģ�����������POE��debug�Ĵ����� */
#define SRE_POE_DEBUG_SLAVE_ERR_EN_REG             (SRE_POE_BASE + 0x440014)        /* POEģ���slave֧�ּ�����дoutstanding�������Ƶ�ʹ���źš� */
#define SRE_POE_DEBUG_SLAVE_ERR_SIG_REG            (SRE_POE_BASE + 0x440018)        /* POEģ���slave֧�ּ�����дoutstanding�������ƵĹ۲��ź��źš� */
#define SRE_POE_DEBUG_MST_RD_EN_REG                (SRE_POE_BASE + 0x44001C)        /* POEģ���master��ͨ��ͳ����ʱ��������ʹ�ܼĴ�������8��ͨ������ͨ������ʹ�ܡ� */
#define SRE_POE_DEBUG_MST_RD_LAY_AVG_REG           (SRE_POE_BASE + 0x440020)        /* POEģ���master��ͨ����ƽ����ʱ�Ĵ��� */
#define SRE_POE_DEBUG_MST_RD_LAY_MAX_REG           (SRE_POE_BASE + 0x440024)        /* POEģ���master��ͨ���������ʱͳ�ƼĴ��� */
#define SRE_POE_DEBUG_MST_RD_LAY_CLR_REG           (SRE_POE_BASE + 0x440028)        /* POEģ���master��ͨ����ʱ����Ĵ��������DEBUG_MST_WR_LAY_AVG��DEBUG_MST_WR_LAY_MAX�Ĵ���ֵ */
#define SRE_POE_DEBUG_MST_RD_ACC_CNT_REG           (SRE_POE_BASE + 0x44002C)        /* POEģ���master��ͨ��������ͳ�ƼĴ��� */
#define SRE_POE_DEBUG_MST_RD_ACC_CLR_REG           (SRE_POE_BASE + 0x440030)        /* POEģ���master��ͨ����������Ĵ��������DEBUG_MST_WR_ACC_CNT�Ĵ��� */
#define SRE_POE_DEBUG_MST_RD_OTD_1_REG             (SRE_POE_BASE + 0x440034)        /* POEģ���master��ͨ����ǰ����ȥ��outstanding����ͳ�ƼĴ�������32bit */
#define SRE_POE_DEBUG_MST_RD_OTD_2_REG             (SRE_POE_BASE + 0x440038)        /* POEģ���master��ͨ����ǰ����ȥ��outstanding����ͳ�ƼĴ�������32bit */
#define SRE_POE_DEBUG_MST_WR_EN_REG                (SRE_POE_BASE + 0x44003C)        /* POEģ���masterдͨ��ͳ����ʱ��������ʹ�ܼĴ�������8��ͨ������ͨ������ʹ�ܡ� */
#define SRE_POE_DEBUG_MST_WR_LAY_AVG_REG           (SRE_POE_BASE + 0x440040)        /* POEģ���masterдͨ����ƽ����ʱ�Ĵ��� */
#define SRE_POE_DEBUG_MST_WR_LAY_MAX_REG           (SRE_POE_BASE + 0x440044)        /* POEģ���masterдͨ���������ʱͳ�ƼĴ��� */
#define SRE_POE_DEBUG_MST_WR_LAY_CLR_REG           (SRE_POE_BASE + 0x440048)        /* POEģ���masterдͨ����ʱ����Ĵ��������DEBUG_MST_WR_LAY_AVG��DEBUG_MST_WR_LAY_MAX�Ĵ���ֵ */
#define SRE_POE_DEBUG_MST_WR_ACC_CNT_REG           (SRE_POE_BASE + 0x44004C)        /* POEģ���masterдͨ��д����ͳ�ƼĴ��� */
#define SRE_POE_DEBUG_MST_WR_ACC_CLR_REG           (SRE_POE_BASE + 0x440050)        /* POEģ���masterдͨ����������Ĵ��������DEBUG_MST_WR_ACC_CNT�Ĵ��� */
#define SRE_POE_DEBUG_MST_WR_OTD_1_REG             (SRE_POE_BASE + 0x440054)        /* POEģ���masterдͨ����ǰ����ȥ��outstanding����ͳ�ƼĴ�������32bit */
#define SRE_POE_DEBUG_MST_WR_OTD_2_REG             (SRE_POE_BASE + 0x440058)        /* POEģ���masterдͨ����ǰ����ȥ��outstanding����ͳ�ƼĴ�������32bit */
#define SRE_POE_DEBUG_INFLI_ST_REG                 (SRE_POE_BASE + 0x44005C)        /* POEģ��ı���ģ�鴦��״̬����ʾ����ģ�����������ʱ�䳬��20��POE���� */
#define SRE_POE_DEBUG_INFLI_ST_CNT_REG             (SRE_POE_BASE + 0x440060)        /* POEģ��ı���ģ�鴦��״̬����ʾ����ģ���д���ʱ�䳬��20��POE���ڵı���������� */
#define SRE_POE_DEBUG_ADD_CNT_REG                  (SRE_POE_BASE + 0x440064)        /* �������POE�ĸ��� */
#define SRE_POE_DEBUG_GET_CNT_REG                  (SRE_POE_BASE + 0x440068)        /* ��POEģ���ȡ����ĸ��� */
#define SRE_POE_DEBUG_OVFL_OUT_CNT_REG             (SRE_POE_BASE + 0x44006C)        /* �����DDR��outstanding������һ������128bit��burst4��ֻ������2/3/4 */
#define SRE_POE_DEBUG_RDBK_OUT_CNT_REG             (SRE_POE_BASE + 0x440070)        /* ��DDR��OV_FIFO�ض���outstanding������һ������128bit��burst4��ֻ������2/3/4 */
#define SRE_POE_SUHAI_RSV_1_REG                    (SRE_POE_BASE + 0x440074)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_2_REG                    (SRE_POE_BASE + 0x440078)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_3_REG                    (SRE_POE_BASE + 0x44007C)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_4_REG                    (SRE_POE_BASE + 0x440080)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_5_REG                    (SRE_POE_BASE + 0x440084)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_6_REG                    (SRE_POE_BASE + 0x440088)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_7_REG                    (SRE_POE_BASE + 0x44008C)        /* Ԥ���Ĵ��� */
#define SRE_POE_SUHAI_RSV_8_REG                    (SRE_POE_BASE + 0x440090)        /* Ԥ���Ĵ��� */

/* pou ģ��Ĵ�������ַ */
#define MC_POU_BASE                     (0x100d0000 + 0x80000000)

/******************************************************************************/
/*                      PhosphorV600 pou �Ĵ�������                           */
/******************************************************************************/
#define MC_POU_GLOBAL_REG           (MC_POU_BASE + 0x0)   /* POUȫ����ؼĴ����� */
#define MC_POU_INT_STATUS_REG       (MC_POU_BASE + 0x8)   /* POU�ж�״̬�Ĵ����� */
#define MC_POU_INT_ENA_REG          (MC_POU_BASE + 0xC)   /* POU�ж�ʹ�ܼĴ����� */
#define MC_POU_INT_MASK_REG         (MC_POU_BASE + 0x10)  /* POU�ж�����Ĵ����� */
#define MC_POU_QOV_ID_REG           (MC_POU_BASE + 0x20)  /* POU����������ID�� */
#define MC_POU_QERR_ID_REG          (MC_POU_BASE + 0x24)  /* POU�������ݷ��ʴ���������мĴ����� */
#define MC_POU_ATOMIC_REG           (MC_POU_BASE + 0x30)  /* POUԭ�Ӳ����Ĵ����� */
#define MC_POU_OQ_EN0_REG           (MC_POU_BASE + 0x40)  /* POU�������ʹ�ܼĴ���0�� */
#define MC_POU_OQ_EN1_REG           (MC_POU_BASE + 0x44)  /* POU�������ʹ�ܼĴ���1�� */
#define MC_POU_TP_DIS_STAT_REG      (MC_POU_BASE + 0x48)  /* POU �˿ڽ�ֹ״̬�Ĵ���*/
#define MC_POU_TP_DIS_STAT_CLR_REG  (MC_POU_BASE + 0x4C)  /* POU �˿ڽ�ֹ״����Ĵ���*/
#define MC_POU_GMAC0_ADDR_REG       (MC_POU_BASE + 0x50)  /* POU��GMAC0д��ַ�Ĵ����� */
#define MC_POU_GMAC1_ADDR_REG       (MC_POU_BASE + 0x54)  /* POU��GMAC1д��ַ�Ĵ����� */
#define MC_POU_GMAC2_ADDR_REG       (MC_POU_BASE + 0x58)  /* POU��GMAC2д��ַ�Ĵ����� */
#define MC_POU_GMAC3_ADDR_REG       (MC_POU_BASE + 0x5C)  /* POU��GMAC3д��ַ�Ĵ����� */
#define MC_POU_GMAC4_ADDR_REG       (MC_POU_BASE + 0x60)  /* POU��GMAC4д��ַ�Ĵ����� */
#define MC_POU_GMAC5_ADDR_REG       (MC_POU_BASE + 0x64)  /* POU��GMAC5д��ַ�Ĵ����� */
#define MC_POU_GMAC6_ADDR_REG       (MC_POU_BASE + 0x68)  /* POU��GMAC6д��ַ�Ĵ����� */
#define MC_POU_GMAC7_ADDR_REG       (MC_POU_BASE + 0x6C)  /* POU��GMAC7д��ַ�Ĵ����� */
#define MC_POU_TP_SHAPING_EN_REG    (MC_POU_BASE + 0x80)  /* POU����˿���������ʹ�ܼĴ����� */
#define MC_POU_DEBUG0_REG           (MC_POU_BASE + 0x90)  /* POU���ԼĴ���0�� */
#define MC_POU_DEBUG1_REG           (MC_POU_BASE + 0x94)  /* POU���ԼĴ���1�� */
#define MC_POU_DEBUG2_REG           (MC_POU_BASE + 0x98)  /* POU���ԼĴ���2�� */
#define MC_POU_DEBUG3_REG           (MC_POU_BASE + 0x9C)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_ST_REG            (MC_POU_BASE + 0xA0)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_0_REG        (MC_POU_BASE + 0xB0)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_1_REG        (MC_POU_BASE + 0xB8)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_2_REG        (MC_POU_BASE + 0xC0)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_3_REG        (MC_POU_BASE + 0xC8)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_4_REG        (MC_POU_BASE + 0xD0)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_5_REG        (MC_POU_BASE + 0xD8)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_6_REG        (MC_POU_BASE + 0xE0)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_DEEP_7_REG        (MC_POU_BASE + 0xE8)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_0_REG         (MC_POU_BASE + 0xB4)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_1_REG         (MC_POU_BASE + 0xBC)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_2_REG         (MC_POU_BASE + 0xC4)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_3_REG         (MC_POU_BASE + 0xCC)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_4_REG         (MC_POU_BASE + 0xD4)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_5_REG         (MC_POU_BASE + 0xDC)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_6_REG         (MC_POU_BASE + 0xE4)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_CNT_7_REG         (MC_POU_BASE + 0xEC)  /* POU���ԼĴ���3�� */
#define MC_POU_TP_RATE0_0_REG  (MC_POU_BASE + 0x100)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_1_REG  (MC_POU_BASE + 0x110)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_2_REG  (MC_POU_BASE + 0x120)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_3_REG  (MC_POU_BASE + 0x130)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_4_REG  (MC_POU_BASE + 0x140)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_5_REG  (MC_POU_BASE + 0x150)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_6_REG  (MC_POU_BASE + 0x160)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE0_7_REG  (MC_POU_BASE + 0x170)  /* POU����˿ڵ��ٶ����üĴ���0�� */
#define MC_POU_TP_RATE1_0_REG  (MC_POU_BASE + 0x104)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_1_REG  (MC_POU_BASE + 0x114)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_2_REG  (MC_POU_BASE + 0x124)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_3_REG  (MC_POU_BASE + 0x134)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_4_REG  (MC_POU_BASE + 0x144)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_5_REG  (MC_POU_BASE + 0x154)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_6_REG  (MC_POU_BASE + 0x164)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_RATE1_7_REG  (MC_POU_BASE + 0x174)  /* POU����˿ڵ��ٶ����üĴ���1�� */
#define MC_POU_TP_LIMIT_0_REG  (MC_POU_BASE + 0x108)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_1_REG  (MC_POU_BASE + 0x118)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_2_REG  (MC_POU_BASE + 0x128)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_3_REG  (MC_POU_BASE + 0x138)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_4_REG  (MC_POU_BASE + 0x148)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_5_REG  (MC_POU_BASE + 0x158)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_6_REG  (MC_POU_BASE + 0x168)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_TP_LIMIT_7_REG  (MC_POU_BASE + 0x178)  /* POU����˿ڵ��ٶ����ƼĴ���1�� */
#define MC_POU_OQ_SET_0_REG  (MC_POU_BASE + 0x200)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_1_REG  (MC_POU_BASE + 0x204)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_2_REG  (MC_POU_BASE + 0x208)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_3_REG  (MC_POU_BASE + 0x20C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_4_REG  (MC_POU_BASE + 0x210)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_5_REG  (MC_POU_BASE + 0x214)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_6_REG  (MC_POU_BASE + 0x218)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_7_REG  (MC_POU_BASE + 0x21C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_8_REG  (MC_POU_BASE + 0x220)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_9_REG  (MC_POU_BASE + 0x224)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_10_REG  (MC_POU_BASE + 0x228)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_11_REG  (MC_POU_BASE + 0x22C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_12_REG  (MC_POU_BASE + 0x230)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_13_REG  (MC_POU_BASE + 0x234)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_14_REG  (MC_POU_BASE + 0x238)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_15_REG  (MC_POU_BASE + 0x23C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_16_REG  (MC_POU_BASE + 0x240)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_17_REG  (MC_POU_BASE + 0x244)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_18_REG  (MC_POU_BASE + 0x248)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_19_REG  (MC_POU_BASE + 0x24C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_20_REG  (MC_POU_BASE + 0x250)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_21_REG  (MC_POU_BASE + 0x254)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_22_REG  (MC_POU_BASE + 0x258)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_23_REG  (MC_POU_BASE + 0x25C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_24_REG  (MC_POU_BASE + 0x260)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_25_REG  (MC_POU_BASE + 0x264)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_26_REG  (MC_POU_BASE + 0x268)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_27_REG  (MC_POU_BASE + 0x26C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_28_REG  (MC_POU_BASE + 0x270)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_29_REG  (MC_POU_BASE + 0x274)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_30_REG  (MC_POU_BASE + 0x278)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_31_REG  (MC_POU_BASE + 0x27C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_32_REG  (MC_POU_BASE + 0x280)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_33_REG  (MC_POU_BASE + 0x284)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_34_REG  (MC_POU_BASE + 0x288)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_35_REG  (MC_POU_BASE + 0x28C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_36_REG  (MC_POU_BASE + 0x290)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_37_REG  (MC_POU_BASE + 0x294)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_38_REG  (MC_POU_BASE + 0x298)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_39_REG  (MC_POU_BASE + 0x29C)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_40_REG  (MC_POU_BASE + 0x2A0)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_41_REG  (MC_POU_BASE + 0x2A4)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_42_REG  (MC_POU_BASE + 0x2A8)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_43_REG  (MC_POU_BASE + 0x2AC)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_44_REG  (MC_POU_BASE + 0x2B0)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_45_REG  (MC_POU_BASE + 0x2B4)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_46_REG  (MC_POU_BASE + 0x2B8)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_47_REG  (MC_POU_BASE + 0x2BC)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_48_REG  (MC_POU_BASE + 0x2C0)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_49_REG  (MC_POU_BASE + 0x2C4)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_50_REG  (MC_POU_BASE + 0x2C8)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_51_REG  (MC_POU_BASE + 0x2CC)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_52_REG  (MC_POU_BASE + 0x2D0)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_53_REG  (MC_POU_BASE + 0x2D4)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_54_REG  (MC_POU_BASE + 0x2D8)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_55_REG  (MC_POU_BASE + 0x2DC)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_56_REG  (MC_POU_BASE + 0x2E0)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_57_REG  (MC_POU_BASE + 0x2E4)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_58_REG  (MC_POU_BASE + 0x2E8)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_59_REG  (MC_POU_BASE + 0x2EC)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_60_REG  (MC_POU_BASE + 0x2F0)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_61_REG  (MC_POU_BASE + 0x2F4)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_62_REG  (MC_POU_BASE + 0x2F8)  /* POU������л������üĴ����� */
#define MC_POU_OQ_SET_63_REG  (MC_POU_BASE + 0x2FC)  /* POU������л������üĴ����� */
#define MC_POU_OQ_BASE_0_REG  (MC_POU_BASE + 0x300)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_1_REG  (MC_POU_BASE + 0x304)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_2_REG  (MC_POU_BASE + 0x308)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_3_REG  (MC_POU_BASE + 0x30C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_4_REG  (MC_POU_BASE + 0x310)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_5_REG  (MC_POU_BASE + 0x314)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_6_REG  (MC_POU_BASE + 0x318)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_7_REG  (MC_POU_BASE + 0x31C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_8_REG  (MC_POU_BASE + 0x320)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_9_REG  (MC_POU_BASE + 0x324)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_10_REG  (MC_POU_BASE + 0x328)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_11_REG  (MC_POU_BASE + 0x32C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_12_REG  (MC_POU_BASE + 0x330)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_13_REG  (MC_POU_BASE + 0x334)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_14_REG  (MC_POU_BASE + 0x338)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_15_REG  (MC_POU_BASE + 0x33C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_16_REG  (MC_POU_BASE + 0x340)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_17_REG  (MC_POU_BASE + 0x344)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_18_REG  (MC_POU_BASE + 0x348)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_19_REG  (MC_POU_BASE + 0x34C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_20_REG  (MC_POU_BASE + 0x350)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_21_REG  (MC_POU_BASE + 0x354)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_22_REG  (MC_POU_BASE + 0x358)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_23_REG  (MC_POU_BASE + 0x35C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_24_REG  (MC_POU_BASE + 0x360)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_25_REG  (MC_POU_BASE + 0x364)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_26_REG  (MC_POU_BASE + 0x368)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_27_REG  (MC_POU_BASE + 0x36C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_28_REG  (MC_POU_BASE + 0x370)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_29_REG  (MC_POU_BASE + 0x374)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_30_REG  (MC_POU_BASE + 0x378)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_31_REG  (MC_POU_BASE + 0x37C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_32_REG  (MC_POU_BASE + 0x380)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_33_REG  (MC_POU_BASE + 0x384)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_34_REG  (MC_POU_BASE + 0x388)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_35_REG  (MC_POU_BASE + 0x38C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_36_REG  (MC_POU_BASE + 0x390)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_37_REG  (MC_POU_BASE + 0x394)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_38_REG  (MC_POU_BASE + 0x398)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_39_REG  (MC_POU_BASE + 0x39C)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_40_REG  (MC_POU_BASE + 0x3A0)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_41_REG  (MC_POU_BASE + 0x3A4)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_42_REG  (MC_POU_BASE + 0x3A8)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_43_REG  (MC_POU_BASE + 0x3AC)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_44_REG  (MC_POU_BASE + 0x3B0)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_45_REG  (MC_POU_BASE + 0x3B4)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_46_REG  (MC_POU_BASE + 0x3B8)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_47_REG  (MC_POU_BASE + 0x3BC)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_48_REG  (MC_POU_BASE + 0x3C0)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_49_REG  (MC_POU_BASE + 0x3C4)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_50_REG  (MC_POU_BASE + 0x3C8)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_51_REG  (MC_POU_BASE + 0x3CC)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_52_REG  (MC_POU_BASE + 0x3D0)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_53_REG  (MC_POU_BASE + 0x3D4)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_54_REG  (MC_POU_BASE + 0x3D8)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_55_REG  (MC_POU_BASE + 0x3DC)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_56_REG  (MC_POU_BASE + 0x3E0)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_57_REG  (MC_POU_BASE + 0x3E4)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_58_REG  (MC_POU_BASE + 0x3E8)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_59_REG  (MC_POU_BASE + 0x3EC)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_60_REG  (MC_POU_BASE + 0x3F0)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_61_REG  (MC_POU_BASE + 0x3F4)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_62_REG  (MC_POU_BASE + 0x3F8)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_BASE_63_REG  (MC_POU_BASE + 0x3FC)  /* POU������е�ַ�Ĵ����� */
#define MC_POU_OQ_DEEP_0_REG  (MC_POU_BASE + 0x400)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_1_REG  (MC_POU_BASE + 0x404)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_2_REG  (MC_POU_BASE + 0x408)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_3_REG  (MC_POU_BASE + 0x40C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_4_REG  (MC_POU_BASE + 0x410)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_5_REG  (MC_POU_BASE + 0x414)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_6_REG  (MC_POU_BASE + 0x418)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_7_REG  (MC_POU_BASE + 0x41C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_8_REG  (MC_POU_BASE + 0x420)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_9_REG  (MC_POU_BASE + 0x424)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_10_REG  (MC_POU_BASE + 0x428)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_11_REG  (MC_POU_BASE + 0x42C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_12_REG  (MC_POU_BASE + 0x430)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_13_REG  (MC_POU_BASE + 0x434)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_14_REG  (MC_POU_BASE + 0x438)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_15_REG  (MC_POU_BASE + 0x43C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_16_REG  (MC_POU_BASE + 0x440)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_17_REG  (MC_POU_BASE + 0x444)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_18_REG  (MC_POU_BASE + 0x448)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_19_REG  (MC_POU_BASE + 0x44C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_20_REG  (MC_POU_BASE + 0x450)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_21_REG  (MC_POU_BASE + 0x454)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_22_REG  (MC_POU_BASE + 0x458)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_23_REG  (MC_POU_BASE + 0x45C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_24_REG  (MC_POU_BASE + 0x460)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_25_REG  (MC_POU_BASE + 0x464)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_26_REG  (MC_POU_BASE + 0x468)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_27_REG  (MC_POU_BASE + 0x46C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_28_REG  (MC_POU_BASE + 0x470)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_29_REG  (MC_POU_BASE + 0x474)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_30_REG  (MC_POU_BASE + 0x478)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_31_REG  (MC_POU_BASE + 0x47C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_32_REG  (MC_POU_BASE + 0x480)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_33_REG  (MC_POU_BASE + 0x484)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_34_REG  (MC_POU_BASE + 0x488)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_35_REG  (MC_POU_BASE + 0x48C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_36_REG  (MC_POU_BASE + 0x490)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_37_REG  (MC_POU_BASE + 0x494)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_38_REG  (MC_POU_BASE + 0x498)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_39_REG  (MC_POU_BASE + 0x49C)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_40_REG  (MC_POU_BASE + 0x4A0)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_41_REG  (MC_POU_BASE + 0x4A4)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_42_REG  (MC_POU_BASE + 0x4A8)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_43_REG  (MC_POU_BASE + 0x4AC)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_44_REG  (MC_POU_BASE + 0x4B0)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_45_REG  (MC_POU_BASE + 0x4B4)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_46_REG  (MC_POU_BASE + 0x4B8)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_47_REG  (MC_POU_BASE + 0x4BC)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_48_REG  (MC_POU_BASE + 0x4C0)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_49_REG  (MC_POU_BASE + 0x4C4)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_50_REG  (MC_POU_BASE + 0x4C8)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_51_REG  (MC_POU_BASE + 0x4CC)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_52_REG  (MC_POU_BASE + 0x4D0)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_53_REG  (MC_POU_BASE + 0x4D4)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_54_REG  (MC_POU_BASE + 0x4D8)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_55_REG  (MC_POU_BASE + 0x4DC)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_56_REG  (MC_POU_BASE + 0x4E0)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_57_REG  (MC_POU_BASE + 0x4E4)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_58_REG  (MC_POU_BASE + 0x4E8)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_59_REG  (MC_POU_BASE + 0x4EC)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_60_REG  (MC_POU_BASE + 0x4F0)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_61_REG  (MC_POU_BASE + 0x4F4)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_62_REG  (MC_POU_BASE + 0x4F8)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_DEEP_63_REG  (MC_POU_BASE + 0x4FC)  /* POU�������DEEP���üĴ����� */
#define MC_POU_OQ_CNT_0_REG  (MC_POU_BASE + 0x500)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_1_REG  (MC_POU_BASE + 0x510)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_2_REG  (MC_POU_BASE + 0x520)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_3_REG  (MC_POU_BASE + 0x530)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_4_REG  (MC_POU_BASE + 0x540)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_5_REG  (MC_POU_BASE + 0x550)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_6_REG  (MC_POU_BASE + 0x560)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_7_REG  (MC_POU_BASE + 0x570)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_8_REG  (MC_POU_BASE + 0x580)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_9_REG  (MC_POU_BASE + 0x590)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_10_REG  (MC_POU_BASE + 0x5A0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_11_REG  (MC_POU_BASE + 0x5B0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_12_REG  (MC_POU_BASE + 0x5C0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_13_REG  (MC_POU_BASE + 0x5D0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_14_REG  (MC_POU_BASE + 0x5E0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_15_REG  (MC_POU_BASE + 0x5F0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_16_REG  (MC_POU_BASE + 0x600)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_17_REG  (MC_POU_BASE + 0x610)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_18_REG  (MC_POU_BASE + 0x620)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_19_REG  (MC_POU_BASE + 0x630)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_20_REG  (MC_POU_BASE + 0x640)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_21_REG  (MC_POU_BASE + 0x650)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_22_REG  (MC_POU_BASE + 0x660)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_23_REG  (MC_POU_BASE + 0x670)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_24_REG  (MC_POU_BASE + 0x680)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_25_REG  (MC_POU_BASE + 0x690)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_26_REG  (MC_POU_BASE + 0x6A0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_27_REG  (MC_POU_BASE + 0x6B0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_28_REG  (MC_POU_BASE + 0x6C0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_29_REG  (MC_POU_BASE + 0x6D0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_30_REG  (MC_POU_BASE + 0x6E0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_31_REG  (MC_POU_BASE + 0x6F0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_32_REG  (MC_POU_BASE + 0x700)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_33_REG  (MC_POU_BASE + 0x710)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_34_REG  (MC_POU_BASE + 0x720)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_35_REG  (MC_POU_BASE + 0x730)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_36_REG  (MC_POU_BASE + 0x740)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_37_REG  (MC_POU_BASE + 0x750)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_38_REG  (MC_POU_BASE + 0x760)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_39_REG  (MC_POU_BASE + 0x770)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_40_REG  (MC_POU_BASE + 0x780)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_41_REG  (MC_POU_BASE + 0x790)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_42_REG  (MC_POU_BASE + 0x7A0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_43_REG  (MC_POU_BASE + 0x7B0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_44_REG  (MC_POU_BASE + 0x7C0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_45_REG  (MC_POU_BASE + 0x7D0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_46_REG  (MC_POU_BASE + 0x7E0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_47_REG  (MC_POU_BASE + 0x7F0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_48_REG  (MC_POU_BASE + 0x800)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_49_REG  (MC_POU_BASE + 0x810)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_50_REG  (MC_POU_BASE + 0x820)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_51_REG  (MC_POU_BASE + 0x830)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_52_REG  (MC_POU_BASE + 0x840)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_53_REG  (MC_POU_BASE + 0x850)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_54_REG  (MC_POU_BASE + 0x860)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_55_REG  (MC_POU_BASE + 0x870)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_56_REG  (MC_POU_BASE + 0x880)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_57_REG  (MC_POU_BASE + 0x890)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_58_REG  (MC_POU_BASE + 0x8A0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_59_REG  (MC_POU_BASE + 0x8B0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_60_REG  (MC_POU_BASE + 0x8C0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_61_REG  (MC_POU_BASE + 0x8D0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_62_REG  (MC_POU_BASE + 0x8E0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT_63_REG  (MC_POU_BASE + 0x8F0)  /* POU�������COUNTER���üĴ����� */
#define MC_POU_OQ_CNT0_0_REG  (MC_POU_BASE + 0x504)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_1_REG  (MC_POU_BASE + 0x514)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_2_REG  (MC_POU_BASE + 0x524)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_3_REG  (MC_POU_BASE + 0x534)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_4_REG  (MC_POU_BASE + 0x544)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_5_REG  (MC_POU_BASE + 0x554)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_6_REG  (MC_POU_BASE + 0x564)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_7_REG  (MC_POU_BASE + 0x574)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_8_REG  (MC_POU_BASE + 0x584)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_9_REG  (MC_POU_BASE + 0x594)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_10_REG  (MC_POU_BASE + 0x5A4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_11_REG  (MC_POU_BASE + 0x5B4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_12_REG  (MC_POU_BASE + 0x5C4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_13_REG  (MC_POU_BASE + 0x5D4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_14_REG  (MC_POU_BASE + 0x5E4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_15_REG  (MC_POU_BASE + 0x5F4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_16_REG  (MC_POU_BASE + 0x604)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_17_REG  (MC_POU_BASE + 0x614)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_18_REG  (MC_POU_BASE + 0x624)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_19_REG  (MC_POU_BASE + 0x634)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_20_REG  (MC_POU_BASE + 0x644)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_21_REG  (MC_POU_BASE + 0x654)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_22_REG  (MC_POU_BASE + 0x664)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_23_REG  (MC_POU_BASE + 0x674)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_24_REG  (MC_POU_BASE + 0x684)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_25_REG  (MC_POU_BASE + 0x694)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_26_REG  (MC_POU_BASE + 0x6A4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_27_REG  (MC_POU_BASE + 0x6B4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_28_REG  (MC_POU_BASE + 0x6C4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_29_REG  (MC_POU_BASE + 0x6D4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_30_REG  (MC_POU_BASE + 0x6E4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_31_REG  (MC_POU_BASE + 0x6F4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_32_REG  (MC_POU_BASE + 0x704)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_33_REG  (MC_POU_BASE + 0x714)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_34_REG  (MC_POU_BASE + 0x724)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_35_REG  (MC_POU_BASE + 0x734)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_36_REG  (MC_POU_BASE + 0x744)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_37_REG  (MC_POU_BASE + 0x754)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_38_REG  (MC_POU_BASE + 0x764)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_39_REG  (MC_POU_BASE + 0x774)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_40_REG  (MC_POU_BASE + 0x784)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_41_REG  (MC_POU_BASE + 0x794)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_42_REG  (MC_POU_BASE + 0x7A4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_43_REG  (MC_POU_BASE + 0x7B4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_44_REG  (MC_POU_BASE + 0x7C4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_45_REG  (MC_POU_BASE + 0x7D4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_46_REG  (MC_POU_BASE + 0x7E4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_47_REG  (MC_POU_BASE + 0x7F4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_48_REG  (MC_POU_BASE + 0x804)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_49_REG  (MC_POU_BASE + 0x814)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_50_REG  (MC_POU_BASE + 0x824)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_51_REG  (MC_POU_BASE + 0x834)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_52_REG  (MC_POU_BASE + 0x844)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_53_REG  (MC_POU_BASE + 0x854)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_54_REG  (MC_POU_BASE + 0x864)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_55_REG  (MC_POU_BASE + 0x874)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_56_REG  (MC_POU_BASE + 0x884)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_57_REG  (MC_POU_BASE + 0x894)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_58_REG  (MC_POU_BASE + 0x8A4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_59_REG  (MC_POU_BASE + 0x8B4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_60_REG  (MC_POU_BASE + 0x8C4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_61_REG  (MC_POU_BASE + 0x8D4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_62_REG  (MC_POU_BASE + 0x8E4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT0_63_REG  (MC_POU_BASE + 0x8F4)  /* POU������еķ������ݰ������Ĵ���0�� */
#define MC_POU_OQ_CNT1_0_REG  (MC_POU_BASE + 0x508)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_1_REG  (MC_POU_BASE + 0x518)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_2_REG  (MC_POU_BASE + 0x528)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_3_REG  (MC_POU_BASE + 0x538)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_4_REG  (MC_POU_BASE + 0x548)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_5_REG  (MC_POU_BASE + 0x558)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_6_REG  (MC_POU_BASE + 0x568)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_7_REG  (MC_POU_BASE + 0x578)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_8_REG  (MC_POU_BASE + 0x588)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_9_REG  (MC_POU_BASE + 0x598)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_10_REG  (MC_POU_BASE + 0x5A8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_11_REG  (MC_POU_BASE + 0x5B8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_12_REG  (MC_POU_BASE + 0x5C8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_13_REG  (MC_POU_BASE + 0x5D8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_14_REG  (MC_POU_BASE + 0x5E8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_15_REG  (MC_POU_BASE + 0x5F8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_16_REG  (MC_POU_BASE + 0x608)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_17_REG  (MC_POU_BASE + 0x618)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_18_REG  (MC_POU_BASE + 0x628)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_19_REG  (MC_POU_BASE + 0x638)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_20_REG  (MC_POU_BASE + 0x648)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_21_REG  (MC_POU_BASE + 0x658)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_22_REG  (MC_POU_BASE + 0x668)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_23_REG  (MC_POU_BASE + 0x678)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_24_REG  (MC_POU_BASE + 0x688)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_25_REG  (MC_POU_BASE + 0x698)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_26_REG  (MC_POU_BASE + 0x6A8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_27_REG  (MC_POU_BASE + 0x6B8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_28_REG  (MC_POU_BASE + 0x6C8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_29_REG  (MC_POU_BASE + 0x6D8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_30_REG  (MC_POU_BASE + 0x6E8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_31_REG  (MC_POU_BASE + 0x6F8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_32_REG  (MC_POU_BASE + 0x708)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_33_REG  (MC_POU_BASE + 0x718)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_34_REG  (MC_POU_BASE + 0x728)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_35_REG  (MC_POU_BASE + 0x738)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_36_REG  (MC_POU_BASE + 0x748)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_37_REG  (MC_POU_BASE + 0x758)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_38_REG  (MC_POU_BASE + 0x768)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_39_REG  (MC_POU_BASE + 0x778)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_40_REG  (MC_POU_BASE + 0x788)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_41_REG  (MC_POU_BASE + 0x798)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_42_REG  (MC_POU_BASE + 0x7A8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_43_REG  (MC_POU_BASE + 0x7B8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_44_REG  (MC_POU_BASE + 0x7C8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_45_REG  (MC_POU_BASE + 0x7D8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_46_REG  (MC_POU_BASE + 0x7E8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_47_REG  (MC_POU_BASE + 0x7F8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_48_REG  (MC_POU_BASE + 0x808)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_49_REG  (MC_POU_BASE + 0x818)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_50_REG  (MC_POU_BASE + 0x828)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_51_REG  (MC_POU_BASE + 0x838)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_52_REG  (MC_POU_BASE + 0x848)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_53_REG  (MC_POU_BASE + 0x858)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_54_REG  (MC_POU_BASE + 0x868)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_55_REG  (MC_POU_BASE + 0x878)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_56_REG  (MC_POU_BASE + 0x888)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_57_REG  (MC_POU_BASE + 0x898)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_58_REG  (MC_POU_BASE + 0x8A8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_59_REG  (MC_POU_BASE + 0x8B8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_60_REG  (MC_POU_BASE + 0x8C8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_61_REG  (MC_POU_BASE + 0x8D8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_62_REG  (MC_POU_BASE + 0x8E8)  /* POU������еķ������ݰ������Ĵ���1�� */
#define MC_POU_OQ_CNT1_63_REG  (MC_POU_BASE + 0x8F8)  /* POU������еķ������ݰ������Ĵ���1�� */

/* CRC ģ��Ĵ�������ַ */
#define SRE_CRC_BASE          				(SRE_SEC_REG_BASE + 0x50000)

/******************************************************************************/
/*                      P650 CRC �Ĵ�������                                 */
/******************************************************************************/
#define SRE_CRC_VERSION_REG                (0x0)         /* CRC �汾�Ĵ����� */
#define SRE_CRC_CFG_REG                    (0x4)         /* CRCȫ�����üĴ����� */
#define SRE_CRC_INT_EN_REG                 (0x8)         /* �ж�ʹ�ܼĴ��� */
#define SRE_CRC_INT_STS_REG                (0xC)         /* �ж�״̬�Ĵ��� */
#define SRE_CRC_PATTERN0_REG               (0x10)        /* CRC����ʽ��������0 */
#define SRE_CRC_PATTERN1_REG               (0x14)        /* CRC����ʽ��������1 */
#define SRE_CRC_PATTERN2_REG               (0x18)        /* CRC����ʽ��������2 */
#define SRE_CRC_PATTERN3_REG               (0x1C)        /* CRC����ʽ��������3 */
#define SRE_CRC_PATTERN4_REG               (0x20)        /* CRC����ʽ��������4 */
#define SRE_CRC_PATTERN5_REG               (0x24)        /* CRC����ʽ��������5 */
#define SRE_CRC_PATTERN6_REG               (0x28)        /* CRC����ʽ��������6 */
#define SRE_CRC_PATTERN7_REG               (0x2C)        /* CRC����ʽ��������7 */
#define SRE_CRC_INIT_VAL0_REG              (0x30)        /* CRC����ĳ�ʼֵ���üĴ���0 */
#define SRE_CRC_INIT_VAL1_REG              (0x34)        /* CRC����ĳ�ʼֵ���üĴ���1 */
#define SRE_CRC_INIT_VAL2_REG              (0x38)        /* CRC����ĳ�ʼֵ���üĴ���2 */
#define SRE_CRC_INIT_VAL3_REG              (0x3C)        /* CRC����ĳ�ʼֵ���üĴ���3 */
#define SRE_CRC_INIT_VAL4_REG              (0x40)        /* CRC����ĳ�ʼֵ���üĴ���4 */
#define SRE_CRC_INIT_VAL5_REG              (0x44)        /* CRC����ĳ�ʼֵ���üĴ���5 */
#define SRE_CRC_INIT_VAL6_REG              (0x48)        /* CRC����ĳ�ʼֵ���üĴ���6 */
#define SRE_CRC_INIT_VAL7_REG              (0x4C)        /* CRC����ĳ�ʼֵ���üĴ���7 */
#define SRE_CRC_START_ADDR0_REG            (0x50)        /* CRC�����������ʼ��ַ�Ĵ���0 */
#define SRE_CRC_START_ADDR1_REG            (0x54)        /* CRC�����������ʼ��ַ�Ĵ���1 */
#define SRE_CRC_START_ADDR2_REG            (0x58)        /* CRC�����������ʼ��ַ�Ĵ���2 */
#define SRE_CRC_START_ADDR3_REG            (0x5C)        /* CRC�����������ʼ��ַ�Ĵ���3 */
#define SRE_CRC_START_ADDR4_REG            (0x60)        /* CRC�����������ʼ��ַ�Ĵ���4 */
#define SRE_CRC_START_ADDR5_REG            (0x64)        /* CRC�����������ʼ��ַ�Ĵ���5 */
#define SRE_CRC_START_ADDR6_REG            (0x68)        /* CRC�����������ʼ��ַ�Ĵ���6 */
#define SRE_CRC_START_ADDR7_REG            (0x6C)        /* CRC�����������ʼ��ַ�Ĵ���7 */
#define SRE_CRC_START_LEN0_REG             (0x70)        /* CRC��������ݳ��ȼĴ���0 */
#define SRE_CRC_START_LEN1_REG             (0x74)        /* CRC��������ݳ��ȼĴ���1 */
#define SRE_CRC_START_LEN2_REG             (0x78)        /* CRC��������ݳ��ȼĴ���2 */
#define SRE_CRC_START_LEN3_REG             (0x7C)        /* CRC��������ݳ��ȼĴ���3 */
#define SRE_CRC_START_LEN4_REG             (0x80)        /* CRC��������ݳ��ȼĴ���4 */
#define SRE_CRC_START_LEN5_REG             (0x84)        /* CRC��������ݳ��ȼĴ���5 */
#define SRE_CRC_START_LEN6_REG             (0x88)        /* CRC��������ݳ��ȼĴ���6 */
#define SRE_CRC_START_LEN7_REG             (0x8C)        /* CRC��������ݳ��ȼĴ���7 */
#define SRE_CRC_RESULT0_REG                (0x90)        /* CRC�������Ĵ���0 */
#define SRE_CRC_RESULT1_REG                (0x94)        /* CRC�������Ĵ���1 */
#define SRE_CRC_RESULT2_REG                (0x98)        /* CRC�������Ĵ���2 */
#define SRE_CRC_RESULT3_REG                (0x9C)        /* CRC�������Ĵ���3 */
#define SRE_CRC_RESULT4_REG                (0xA0)        /* CRC�������Ĵ���4 */
#define SRE_CRC_RESULT5_REG                (0xA4)        /* CRC�������Ĵ���5 */
#define SRE_CRC_RESULT6_REG                (0xA8)        /* CRC�������Ĵ���6 */
#define SRE_CRC_RESULT7_REG                (0xAC)        /* CRC�������Ĵ���7 */
#define SRE_CRC_RES_LEN0_REG               (0xB0)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���0 */
#define SRE_CRC_RES_LEN1_REG               (0xB4)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���1 */
#define SRE_CRC_RES_LEN2_REG               (0xB8)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���2 */
#define SRE_CRC_RES_LEN3_REG               (0xBC)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���3 */
#define SRE_CRC_RES_LEN4_REG               (0xC0)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���4 */
#define SRE_CRC_RES_LEN5_REG               (0xC4)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���5 */
#define SRE_CRC_RES_LEN6_REG               (0xC8)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���6 */
#define SRE_CRC_RES_LEN7_REG               (0xCC)        /* CRC�ôμ����ܹ����㳤��ͳ�ƼĴ���7 */
#define SRE_CRC_START_REG                  (0xD0)        /* CRC�����Ĵ��� */
#define SRE_CRC_STS_REG                    (0xD4)        /* CRC״̬�Ĵ��� */
#define SRE_CRC_DATA_MODE0_REG             (0xD8)        /* CRC���ݽӿ�ģʽ�Ĵ���0 */
#define SRE_CRC_DATA_MODE1_REG             (0xDC)        /* CRC���ݽӿ�ģʽ�Ĵ���1 */
#define SRE_CRC_DATA_MODE2_REG             (0xE0)        /* CRC���ݽӿ�ģʽ�Ĵ���2 */
#define SRE_CRC_DATA_MODE3_REG             (0xE4)        /* CRC���ݽӿ�ģʽ�Ĵ���3 */
#define SRE_CRC_DATA_MODE4_REG             (0xE8)        /* CRC���ݽӿ�ģʽ�Ĵ���4 */
#define SRE_CRC_DATA_MODE5_REG             (0xEC)        /* CRC���ݽӿ�ģʽ�Ĵ���5 */
#define SRE_CRC_DATA_MODE6_REG             (0xF0)        /* CRC���ݽӿ�ģʽ�Ĵ���6 */
#define SRE_CRC_DATA_MODE7_REG             (0xF4)        /* CRC���ݽӿ�ģʽ�Ĵ���7 */
#define SRE_CRC_AHBM_ADDRH_CH0_REG         (0x100)       /* CRC AHB Master�ӿ�channel0��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH1_REG         (0x104)       /* CRC AHB Master�ӿ�channel1��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH2_REG         (0x108)       /* CRC AHB Master�ӿ�channel2��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH3_REG         (0x10C)       /* CRC AHB Master�ӿ�channel3��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH4_REG         (0x110)       /* CRC AHB Master�ӿ�channel4��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH5_REG         (0x114)       /* CRC AHB Master�ӿ�channel5��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH6_REG         (0x118)       /* CRC AHB Master�ӿ�channel6��2λ��ַ */
#define SRE_CRC_AHBM_ADDRH_CH7_REG         (0x11C)       /* CRC AHB Master�ӿ�channel7��2λ��ַ */
#define SRE_CRC_WR_ADDR0_REG               (0x2000)      /* CRC Slaveģʽ���ݽӿڼĴ���0 */
#define SRE_CRC_WR_ADDR1_REG               (0x2400)      /* CRC Slaveģʽ���ݽӿڼĴ���1 */
#define SRE_CRC_WR_ADDR2_REG               (0x2800)      /* CRC Slaveģʽ���ݽӿڼĴ���2 */
#define SRE_CRC_WR_ADDR3_REG               (0x2C00)      /* CRC Slaveģʽ���ݽӿڼĴ���3 */
#define SRE_CRC_WR_ADDR4_REG               (0x3000)      /* CRC Slaveģʽ���ݽӿڼĴ���4 */
#define SRE_CRC_WR_ADDR5_REG               (0x3400)      /* CRC Slaveģʽ���ݽӿڼĴ���5 */
#define SRE_CRC_WR_ADDR6_REG               (0x3800)      /* CRC Slaveģʽ���ݽӿڼĴ���6 */
#define SRE_CRC_WR_ADDR7_REG               (0x3C00)      /* CRC Slaveģʽ���ݽӿڼĴ���7 */


/* DMAC ģ��Ĵ�������ַ */
#define SRE_DMAC_BASE_ADDR          (0xf00d2000)

/******************************************************************************/
/*                      Phosphor DMAC �Ĵ�������                              */
/******************************************************************************/
#define SRE_DMAC_INT_1_REG                   (0x0)      	/* DMAC_INT_1ΪDMAC���κ���ж�״̬�Ĵ���1�� */
#define SRE_DMAC_ITC_MASK_INT_1_REG          (0x4)      	/* DMAC_ITC_MASK_INT_1ΪDMAC��������ж����μĴ���1�� */
#define SRE_DMAC_IE_MASK_INT_1_REG           (0x8)      	/* DMAC_IE_MASK_INT_1ΪDMAC��������ж����μĴ���1�� */
#define SRE_DMAC_INT_TC_1_REG                (0xC)      	/* DMAC_INT_TC_1ΪDMAC��������ж�״̬�Ĵ���1�� */
#define SRE_DMAC_INT_ERR_1_REG               (0x10)     	/* DMAC_INT_ERR_1ΪDMAC��������ж�״̬�Ĵ���1�� */
#define SRE_DMAC_INT_2_REG                   (0x14)     	/* DMAC_INT_2ΪDMAC���κ���ж�״̬�Ĵ���2�� */
#define SRE_DMAC_ITC_MASK_INT_2_REG          (0x18)     	/* DMAC_ITC_MASK_INT_2ΪDMAC��������ж����μĴ���2�� */
#define SRE_DMAC_IE_MASK_INT_2_REG           (0x1C)     	/* DMAC_IE_MASK_INT_2ΪDMAC��������ж����μĴ���2�� */
#define SRE_DMAC_INT_TC_2_REG                (0x20)     	/* DMAC_INT_TC_2ΪDMAC��������ж�״̬�Ĵ���2�� */
#define SRE_DMAC_INT_ERR_2_REG               (0x24)     	/* DMAC_INT_ERR_2ΪDMAC��������ж�״̬�Ĵ���2�� */
#define SRE_DMAC_INT_3_REG                   (0x28)     	/* DMAC_INT_3ΪDMAC���κ���ж�״̬�Ĵ���3�� */
#define SRE_DMAC_ITC_MASK_INT_3_REG          (0x2C)     	/* DMAC_ITC_MASK_INT_3ΪDMAC��������ж����μĴ���3�� */
#define SRE_DMAC_IE_MASK_INT_3_REG           (0x30)     	/* DMAC_IE_MASK_INT_3ΪDMAC��������ж����μĴ���3�� */
#define SRE_DMAC_INT_TC_3_REG                (0x34)     	/* DMAC_INT_TCΪDMAC��������ж�״̬�Ĵ���3�� */
#define SRE_DMAC_INT_ERR_3_REG               (0x38)     	/* DMAC_INT_ERRΪDMAC��������ж�״̬�Ĵ���3�� */
#define SRE_DMAC_INT_TC_CLR_REG              (0x3C)     	/* DMAC_INT_TC_CLRΪDMAC��������ж�����Ĵ����� */
#define SRE_DMAC_INT_ERR_CLR_REG             (0x40)     	/* DMAC_INT_ERR_CLRΪDMAC��������ж�����Ĵ����� */
#define SRE_DMAC_INT_TC_RAW_REG              (0x44)     	/* DMAC_INT_TC_RAWΪDMAC�������ԭʼ�ж�״̬�Ĵ����� */
#define SRE_DMAC_INT_ERR_RAW_REG             (0x48)     	/* DMAC_INT_ERR_RAWΪDMAC�������ԭʼ�ж�״̬�Ĵ����� */
#define SRE_DMAC_EN_CH_STATUS_REG            (0x4C)     	/* DMAC_EN_CH_STATUSΪDMACͨ��ʹ��״̬�Ĵ����� */
#define SRE_DMAC_BREQ_1_REG                  (0x50)     	/* DMAC_BREQ_1ΪDMACͨ��ͻ����������Ĵ���1�� */
#define SRE_DMAC_BREQ_2_REG                  (0x54)    	/* DMAC_BREQ_2ΪDMACͨ��ͻ����������Ĵ���2�� */
#define SRE_DMAC_SREQ_1_REG                  (0x58)     	/* DMAC_SREQ_1ΪDMACͨ�����δ�������Ĵ���1�� */
#define SRE_DMAC_SREQ_2_REG                  (0x5C)     	/* DMAC_SREQ_2ΪDMACͨ�����δ�������Ĵ���2�� */
#define SRE_DMAC_LBREQ_1_REG                 (0x60)     	/* DMAC_LBREQ_1ΪDMACͨ��ĩ��ͻ����������Ĵ���1�� */
#define SRE_DMAC_LBREQ_2_REG                 (0x64)     	/* DMAC_LBREQ_2ΪDMACͨ��ĩ��ͻ����������Ĵ���2�� */
#define SRE_DMAC_LSREQ_1_REG                 (0x68)     	/* DMAC_LSREQ_1ΪDMACͨ��ĩ�ε��δ�������Ĵ���1�� */
#define SRE_DMAC_LSREQ_2_REG                 (0x6C)     	/* DMAC_LSREQ_2ΪDMACͨ��ĩ�ε��δ�������Ĵ���2�� */
#define SRE_DMAC_SECURIRY_READ_REG           (0x70)     	/* DMAC_SECURIRY_READΪDMACͨ����ȫ�����ʿ��ƼĴ����� */
#define SRE_SECURIRY_WRITE_REG               (0x74)     	/* SECURIRY_WRITEΪDMACͨ����ȫд���ʿ��ƼĴ����� */
#define SRE_DMAC_G_EN_REG                    (0x78)     	/* DMAC_G_ENΪDMAC���ƼĴ����� */
#define SRE_DMAC_AUDIO_JP_SIZE_REG      		(0x7C)     	/* DMAC_AUDIO_JP_SIZEΪ��Ƶ��Ծ���ƼĴ����� */
#define SRE_DMAC_STRID_CH_SIZE_REG      		(0x80)     	/* DMAC_STRID_CH_SIZEΪ������ͨ���Ĳ������üĴ�������16λ����ĳ����ͨ������16λ����ĳ��дͨ���� */
#define SRE_DMAC_VIDEO_LN_SIZE_REG      		(0x84)     	/* ������ͨ����Դ����Ŀ�����ݿ��С���üĴ�������������ÿ���ƶ������ݿ�֮��Դ����Ŀ�ĵ�ַ����һ�������� */
#define SRE_DMAC_CMSRCADDR_0_REG        		(0x100)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_1_REG        		(0x110)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_2_REG        		(0x120)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_3_REG        		(0x130)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_4_REG        		(0x140)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_5_REG        		(0x150) 	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_6_REG        		(0x160)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_7_REG        		(0x170)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_8_REG        		(0x180)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_9_REG        		(0x190) 	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_10_REG       		(0x1A0)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_11_REG       		(0x1B0)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_12_REG       		(0x1C0)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_13_REG       		(0x1D0)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_14_REG       		(0x1E0)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMSRCADDR_15_REG       		(0x1F0)  	/* ͨ��m��Դ��ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_0_REG       		(0x104)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_1_REG       		(0x114)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_2_REG       		(0x124)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_3_REG       		(0x134)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_4_REG       		(0x144)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_5_REG       		(0x154)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_6_REG       		(0x164)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_7_REG       		(0x174)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_8_REG       		(0x184)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_9_REG       		(0x194)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_10_REG      		(0x1A4)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_11_REG      		(0x1B4)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_12_REG      		(0x1C4)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_13_REG      		(0x1D4)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_14_REG      		(0x1E4)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMDESTADDR_15_REG      		(0x1F4)  	/* ͨ��m��Ŀ���ַ�Ĵ����� */
#define SRE_DMAC_CMLLI_0_REG            		(0x108)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_1_REG            		(0x118)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_2_REG            		(0x128)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_3_REG            		(0x138)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_4_REG            		(0x148)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_5_REG            		(0x158)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_6_REG            		(0x168)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_7_REG            		(0x178)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_8_REG            		(0x188)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_9_REG           		(0x198)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_10_REG           		(0x1A8)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_11_REG           		(0x1B8)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_12_REG           		(0x1C8)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_13_REG           		(0x1D8)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_14_REG           		(0x1E8)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMLLI_15_REG           		(0x1F8)  	/* ͨ��m��������Ĵ����� */
#define SRE_DMAC_CMCONTROL_0_REG        		(0x10C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_1_REG        		(0x11C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_2_REG        		(0x12C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_3_REG        		(0x13C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_4_REG        		(0x14C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_5_REG        		(0x15C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_6_REG        		(0x16C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_7_REG        		(0x17C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_8_REG        		(0x18C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_9_REG        		(0x19C)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_10_REG       		(0x1AC)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_11_REG       		(0x1BC)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_12_REG       		(0x1CC)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_13_REG       		(0x1DC)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_14_REG       		(0x1EC)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONTROL_15_REG       		(0x1FC)  	/* ͨ��m�Ŀ��ƼĴ����� */
#define SRE_DMAC_CMCONFIG_0_REG         		(0x300)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_1_REG         		(0x304)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_2_REG         		(0x308)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_3_REG         		(0x30C)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_4_REG         		(0x310)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_5_REG         		(0x314)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_6_REG         		(0x318)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_7_REG         		(0x31C)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_8_REG         		(0x320)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_9_REG         		(0x324)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_10_REG        		(0x328)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_11_REG        		(0x32C)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_12_REG        		(0x330)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_13_REG        		(0x334)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_14_REG        		(0x338)  	/* ͨ��m�����üĴ����� */
#define SRE_DMAC_CMCONFIG_15_REG        		(0x33C)  	/* ͨ��m�����üĴ����� */

/******************************************************************************/
/*                      PhosphorV650 SEC_COMMON �Ĵ�������                    */
/******************************************************************************/
#define SRE_SEC_REG_BASE                               (0xe0800000)
#define SRE_SEC_COM_SEC_CLK_EN_REG                     (SRE_SEC_REG_BASE + 0x0)             /* SECʱ��ʹ�ܿ��� */
#define SRE_SEC_COM_SEC_GET_POE_ADDR_REG               (SRE_SEC_REG_BASE + 0x4)             /* GET POE��ַ�Ĵ����� */
#define SRE_SEC_COM_SEC_ADD_POE_ADDR_REG               (SRE_SEC_REG_BASE + 0x8)             /* ADD POE��ַ�Ĵ��� */
#define SRE_SEC_COM_SEC_BD_OFFSET_REG                  (SRE_SEC_REG_BASE + 0xC)             /* SEC BDƫ�Ƶ�ַ���üĴ��� */
#define SRE_SEC_COM_POE_FAIL_WAIT_TIME_REG             (SRE_SEC_REG_BASE + 0x10)            /* ADD��GET POEʧ�ܵȴ�ʱ��Ĵ��� */
#define SRE_SEC_COM_POE_SUC_WAIT_TIME_REG              (SRE_SEC_REG_BASE + 0x14)            /* ADD��GET POE�ɹ��ȴ�ʱ��Ĵ��� */
#define SRE_SEC_COM_SEC_CONTROL_REG                    (SRE_SEC_REG_BASE + 0x18)            /* SECȫ�����üĴ��� */
#define SRE_SEC_COM_POE_ADD_FAIL_CNT_REG               (SRE_SEC_REG_BASE + 0x1C)            /* ADD POE PACKET ʧ�ܴ�����ͳ��״̬�Ĵ��� */
#define SRE_SEC_COM_POE_ADD_SUC_CNT_REG                (SRE_SEC_REG_BASE + 0x20)            /* ADD POE PACKET �ɹ�������ͳ��״̬�Ĵ��� */
#define SRE_SEC_COM_POE_GET_FAIL_CNT_REG               (SRE_SEC_REG_BASE + 0x24)            /* GET POE PACKET ʧ�ܴ�����ͳ��״̬�Ĵ��� */
#define SRE_SEC_COM_POE_GET_SUC_CNT_REG                (SRE_SEC_REG_BASE + 0x28)            /* GET POE PACKET �ɹ�������ͳ��״̬�Ĵ��� */
#define SRE_SEC_COM_SEC_BUS_TIMEOUT_THLD_REG           (SRE_SEC_REG_BASE + 0x2C)            /* SEC���߳�ʱ���޼Ĵ��� */
#define SRE_SEC_COM_COMMON_RC_EN_CTRL_REG              (SRE_SEC_REG_BASE + 0x30)            /* ����Ĵ��������ʹ�� */
#define SRE_SEC_COM_SEC_GET_FAIL_THLD_REG              (SRE_SEC_REG_BASE + 0x34)            /* SEC GET POEʧ�ܴ������޼Ĵ��� */
#define SRE_SEC_COM_SEC_ADD_FAIL_THLD_REG              (SRE_SEC_REG_BASE + 0x38)            /* SEC ADD POEʧ�ܴ������޼Ĵ��� */
#define SRE_SEC_COM_SEC_BD_FIFO_DATA_REG               (SRE_SEC_REG_BASE + 0x3C)            /* BD FIFOģʽ������ӼĴ��� */
#define SRE_SEC_COM_SEC_TASKIN_FIFO_STATUS_REG         (SRE_SEC_REG_BASE + 0x40)            /* TASK IN FIFO״̬�Ĵ��� */
#define SRE_SEC_COM_SEC_ST_SRC_INT_REG                 (SRE_SEC_REG_BASE + 0x44)            /* SECȫ��Դ�жϼĴ��� */
#define SRE_SEC_COM_SEC_ST_INT_MASK_REG                (SRE_SEC_REG_BASE + 0x48)            /* SECȫ���ж����μĴ��� */
#define SRE_SEC_COM_SEC_ST_INT_STATUS_REG              (SRE_SEC_REG_BASE + 0x4C)            /* SECȫ���ж�״̬�Ĵ��� */
#define SRE_SEC_COM_SEC_BD_SRC_INT_REG                 (SRE_SEC_REG_BASE + 0x50)            /* SEC BD����Դ�жϼĴ��� */
#define SRE_SEC_COM_SEC_BD_INT_MASK_REG                (SRE_SEC_REG_BASE + 0x54)            /* SEC BD�����ж����μĴ��� */
#define SRE_SEC_COM_SEC_BD_INT_STATUS_REG              (SRE_SEC_REG_BASE + 0x58)            /* SEC BD�����ж�״̬�Ĵ��� */
#define SRE_SEC_COM_IPV4_MASK_TABLE_REG                (SRE_SEC_REG_BASE + 0x60)            /* IPV4 MASK�����üĴ��� */
#define SRE_SEC_COM_IPV6_MASK_TABLE_LSB_REG            (SRE_SEC_REG_BASE + 0x64)            /* IPV6 MASK���32λ���üĴ��� */
#define SRE_SEC_COM_IPV6_MASK_TABLE_MSB_REG            (SRE_SEC_REG_BASE + 0x68)            /* IPV6 MASK���8λ���üĴ��� */
#define SRE_SEC_COM_SEC_STOP_REQUST_AND_STATUS_REG     (SRE_SEC_REG_BASE + 0x6C)            /* SEC ֹͣ�����ֹͣ״̬�Ĵ��� */
#define SRE_SEC_COM_SEC_STOP_TIMEOUT_THLD_REG          (SRE_SEC_REG_BASE + 0x70)            /* SECֹͣ��ʱ�Ĵ��� */
#define SRE_SEC_COM_SEC_CONTROL_2_REG                  (SRE_SEC_REG_BASE + 0x74)            /* SECȫ�����üĴ��� */
#define SRE_SEC_COM_SEC_SECURE_CONTROL_REG             (SRE_SEC_REG_BASE + 0x80)            /* ϵͳ��ȫ���ƼĴ��� */
#define SRE_SEC_COM_SEC_SECURE_SRAM_START_ADDR_REG     (SRE_SEC_REG_BASE + 0x84)            /* ��ȫSRAM��ʼ��ַ */
#define SRE_SEC_COM_SEC_SECURE_SRAM_MEM_LEN_REG        (SRE_SEC_REG_BASE + 0x8C)            /* ��ȫSRAM���� */
#define SRE_SEC_COM_BD_NUM_CNT_IN_FIFO_REG             (SRE_SEC_REG_BASE + 0x400)           /* ����ģ����FIFO�������ܸ���״̬�Ĵ��� */
#define SRE_SEC_COM_BD_NUM_CNT_IN_SEC_REG              (SRE_SEC_REG_BASE + 0x404)           /* SECģ���ڲ�BD�ܸ���״̬�Ĵ��� */
#define SRE_SEC_COM_SEC_ORDER_FSM_STATUS_REG           (SRE_SEC_REG_BASE + 0x408)           /* ����ģ����״̬��״̬�Ĵ��� */
#define SRE_SEC_COM_SEC_BD_AXI_DFX_CTRL_REG            (SRE_SEC_REG_BASE + 0x40C)           /* BD AXI�˿�DFX���ƼĴ��� */
#define SRE_SEC_COM_SEC_BD_AXI_DFX_LAT_AVG_REG         (SRE_SEC_REG_BASE + 0x410)           /* BD AXI�˿ڶ�дƽ���ӳ� */
#define SRE_SEC_COM_SEC_BD_AXI_DFX_LAT_MAX_REG         (SRE_SEC_REG_BASE + 0x414)           /* BD AXI�˿ڶ�д����ӳ� */
#define SRE_SEC_COM_SEC_BD_AXI_WR_ACC_REG              (SRE_SEC_REG_BASE + 0x418)           /* BD AXI�˿�д�ۼƼ����� */
#define SRE_SEC_COM_SEC_BD_AXI_RD_ACC_REG              (SRE_SEC_REG_BASE + 0x41C)           /* BD AXI�˿ڶ��ۼƼ����� */
#define SRE_SEC_COM_SEC_BD_AXI_WR_OTD_1_REG            (SRE_SEC_REG_BASE + 0x420)           /* BD AXI�˿�дoutstanding������1 */
#define SRE_SEC_COM_SEC_BD_AXI_WR_OTD_2_REG            (SRE_SEC_REG_BASE + 0x424)           /* BD AXI�˿�дoutstanding������2 */
#define SRE_SEC_COM_SEC_BD_AXI_WR_OTD_3_REG            (SRE_SEC_REG_BASE + 0x428)           /* BD AXI�˿�дoutstanding������3 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_OTD_1_REG            (SRE_SEC_REG_BASE + 0x42C)           /* BD AXI�˿ڶ�outstanding������1 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_OTD_2_REG            (SRE_SEC_REG_BASE + 0x430)           /* BD AXI�˿ڶ�outstanding������2 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_OTD_3_REG            (SRE_SEC_REG_BASE + 0x434)           /* BD AXI�˿ڶ�outstanding������3 */
#define SRE_SEC_COM_SEC_DATA_AXI1_DFX_CTRL_REG         (SRE_SEC_REG_BASE + 0x438)           /* DATA AXI�˿�1 DFX���ƼĴ��� */
#define SRE_SEC_COM_SEC_DATA_AXI1_DFX_LAT_AVG_REG      (SRE_SEC_REG_BASE + 0x43C)           /* DATA AXI�˿�1��дƽ���ӳ� */
#define SRE_SEC_COM_SEC_DATA_AXI1_DFX_LAT_MAX_REG      (SRE_SEC_REG_BASE + 0x440)           /* DATA AXI�˿�1��д����ӳ� */
#define SRE_SEC_COM_SEC_DATA_AXI1_WR_ACC_REG           (SRE_SEC_REG_BASE + 0x444)           /* DATA AXI�˿�1д�ۼƼ����� */
#define SRE_SEC_COM_SEC_DATA_AXI1_RD_ACC_REG           (SRE_SEC_REG_BASE + 0x448)           /* DATA AXI�˿�1���ۼƼ����� */
#define SRE_SEC_COM_SEC_DATA_AXI1_WR_OTD_1_REG         (SRE_SEC_REG_BASE + 0x44C)           /* DATA AXI�˿�1дoutstanding������1 */
#define SRE_SEC_COM_SEC_DATA_AXI1_WR_OTD_2_REG         (SRE_SEC_REG_BASE + 0x450)           /* DATA AXI�˿�1дoutstanding������2 */
#define SRE_SEC_COM_SEC_DATA_AXI1_RD_OTD_1_REG         (SRE_SEC_REG_BASE + 0x454)           /* DATA AXI�˿�1��outstanding������1 */
#define SRE_SEC_COM_SEC_DATA_AXI1_RD_OTD_2_REG         (SRE_SEC_REG_BASE + 0x458)           /* DATA AXI�˿�1��outstanding������2 */
#define SRE_SEC_COM_SEC_DATA_AXI2_DFX_CTRL_REG         (SRE_SEC_REG_BASE + 0x45C)           /* DATA AXI�˿�2 DFX���ƼĴ��� */
#define SRE_SEC_COM_SEC_DATA_AXI2_DFX_LAT_AVG_REG      (SRE_SEC_REG_BASE + 0x460)           /* DATA AXI�˿�2��дƽ���ӳ� */
#define SRE_SEC_COM_SEC_DATA_AXI2_DFX_LAT_MAX_REG      (SRE_SEC_REG_BASE + 0x464)           /* DATA AXI�˿�2��д����ӳ� */
#define SRE_SEC_COM_SEC_DATA_AXI2_WR_ACC_REG           (SRE_SEC_REG_BASE + 0x468)           /* DATA AXI�˿�2д�ۼƼ����� */
#define SRE_SEC_COM_SEC_DATA_AXI2_RD_ACC_REG           (SRE_SEC_REG_BASE + 0x46C)           /* DATA AXI�˿�2���ۼƼ����� */
#define SRE_SEC_COM_SEC_DATA_AXI2_WR_OTD_1_REG         (SRE_SEC_REG_BASE + 0x470)           /* DATA AXI�˿�2дoutstanding������1 */
#define SRE_SEC_COM_SEC_DATA_AXI2_WR_OTD_2_REG         (SRE_SEC_REG_BASE + 0x474)           /* DATA AXI�˿�2дoutstanding������2 */
#define SRE_SEC_COM_SEC_DATA_AXI2_RD_OTD_1_REG         (SRE_SEC_REG_BASE + 0x478)           /* DATA AXI�˿�2��outstanding������1 */
#define SRE_SEC_COM_SEC_DATA_AXI2_RD_OTD_2_REG         (SRE_SEC_REG_BASE + 0x47C)           /* DATA AXI�˿�2��outstanding������2 */
#define SRE_SEC_COM_SEC_BD_AXI_TIMEOUT_1_REG           (SRE_SEC_REG_BASE + 0x480)           /* BD AXI�˿ڳ�ʱ��־�Ĵ���1 */
#define SRE_SEC_COM_SEC_BD_AXI_TIMEOUT_2_REG           (SRE_SEC_REG_BASE + 0x484)           /* BD AXI�˿ڳ�ʱ��־�Ĵ���2 */
#define SRE_SEC_COM_SEC_DATA_AXI_TIMEOUT_REG           (SRE_SEC_REG_BASE + 0x488)           /* DATA AXI�˿ڳ�ʱ��־�Ĵ��� */
#define SRE_SEC_COM_SEC_STAT_CLR_REG                   (SRE_SEC_REG_BASE + 0x48C)           /* SECͳ�ƼĴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA0_ACC_REG                   (SRE_SEC_REG_BASE + 0x490)           /* SAA0�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA1_ACC_REG                   (SRE_SEC_REG_BASE + 0x494)           /* SAA1�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA2_ACC_REG                   (SRE_SEC_REG_BASE + 0x498)           /* SAA2�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA3_ACC_REG                   (SRE_SEC_REG_BASE + 0x49C)           /* SAA3�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA4_ACC_REG                   (SRE_SEC_REG_BASE + 0x4A0)           /* SAA4�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA5_ACC_REG                   (SRE_SEC_REG_BASE + 0x4A4)           /* SAA5�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA6_ACC_REG                   (SRE_SEC_REG_BASE + 0x4A8)           /* SAA6�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_SAA7_ACC_REG                   (SRE_SEC_REG_BASE + 0x4AC)           /* SAA7�ۼƴ�������Ĵ��� */
#define SRE_SEC_COM_SEC_PKT_LATENCY_REG                (SRE_SEC_REG_BASE + 0x4B0)           /* �����ӳ�ͳ�ƼĴ��� */
#define SRE_SEC_COM_RSV_DFX_CONFIG_1_REG               (SRE_SEC_REG_BASE + 0x500)           /* ����DFX���üĴ��� */
#define SRE_SEC_COM_RSV_DFX_CONFIG_2_REG               (SRE_SEC_REG_BASE + 0x504)           /* ����DFX���üĴ��� */
#define SRE_SEC_COM_RSV_DFX_CONFIG_3_REG               (SRE_SEC_REG_BASE + 0x508)           /* ����DFX���üĴ��� */
#define SRE_SEC_COM_RSV_DFX_STATUS_1_REG               (SRE_SEC_REG_BASE + 0x50C)           /* ����DFX״̬�Ĵ��� */
#define SRE_SEC_COM_RSV_DFX_STATUS_2_REG               (SRE_SEC_REG_BASE + 0x510)           /* ����DFX״̬�Ĵ��� */
#define SRE_SEC_COM_RSV_DFX_STATUS_3_REG               (SRE_SEC_REG_BASE + 0x514)           /* ����DFX״̬�Ĵ��� */


#define SRE_SEC_SAA_REG_BASE                        (SRE_SEC_REG_BASE + 0x1000)
#define SRE_SEC_CHANNEL_CURR_BD_REG  	       		(SRE_SEC_SAA_REG_BASE + 0x0)  /* CHANNEL_CURR_BDΪSAA��Channel��ǰʹ�õ�BD��Ϣ�Ĵ����� */
#define SRE_SEC_SHADOW_CURR_BD_REG  	            (SRE_SEC_SAA_REG_BASE + 0x200)  /* SHADOW_CURR_BDΪSAA��SHADOW״̬����ǰʹ�õ�BD��Ϣ�Ĵ����� */
#define SRE_SEC_CIPHER_IVIN_REG    	                (SRE_SEC_SAA_REG_BASE + 0x400)  /* SAA SHADOW״̬����ǰʹ�õ�CIPHER IVINֵ��Ϣ�Ĵ����� */
#define SRE_SEC_CIPHER_KEY_REG     	                (SRE_SEC_SAA_REG_BASE + 0x500)  /* SAA SHADOW״̬����ǰʹ�õ�CIPHER KEYֵ��Ϣ�Ĵ����� */
#define SRE_SEC_HASH_IVIN_REG      	                (SRE_SEC_SAA_REG_BASE + 0x600)  /* SAA SHADOW״̬����ǰʹ�õ�HASH IVINֵ��Ϣ�Ĵ����� */
#define SRE_SEC_HASH_KEY_REG       	                (SRE_SEC_SAA_REG_BASE + 0x700)  /* SAA SHADOW״̬����ǰʹ�õ�HMAC KEYֵ��Ϣ�Ĵ����� */
#define SRE_SEC_HASH_IVOUT_REG     	                (SRE_SEC_SAA_REG_BASE + 0x800)  /* SAA��ǰ�����HASH IV OUTֵ��Ϣ�Ĵ����� */
#define SRE_SEC_CHANNEL_STATUS_REG   	            (SRE_SEC_SAA_REG_BASE + 0x908)  /* CHANNEL_STATUSΪChannel״̬�Ĵ����� */
#define SRE_SEC_CHANNEL_TIME_OUT_CNT_REG       		(SRE_SEC_SAA_REG_BASE + 0x90C)  /* CHANNEL״̬��������������ֵ�Ĵ��� */
#define SRE_SEC_CHANNEL_MAX_CNT_REG  	        	(SRE_SEC_SAA_REG_BASE + 0x910)  /* CHANNEL״̬������������������ֵ���üĴ��� */
#define SRE_SEC_SHADOW_TIME_OUT_CNT_REG        		(SRE_SEC_SAA_REG_BASE + 0x914)  /* SHADOW״̬��������������ֵ�Ĵ��� */
#define SRE_SEC_SHADOW_MAX_CNT_REG   	        	(SRE_SEC_SAA_REG_BASE + 0x918)  /* SHADOW״̬������������������ֵ���üĴ��� */
#define SRE_SEC_SEC_BD_ERR_ADDR_REG  	            (SRE_SEC_SAA_REG_BASE + 0x91C)  /* ���һ�δ���BD��ַ��ѯ�Ĵ��� */
#define SRE_SEC_SEC_BD_ERR_CNT_REG   	            (SRE_SEC_SAA_REG_BASE + 0x920)  /* SEC BD����ͳ�ƼĴ��� */
#define SRE_SEC_SAA_GET2ADD_WAIT_TIME_REG    		(SRE_SEC_SAA_REG_BASE + 0x924)  /* �ڿ���ADD BDʱ����ȡBD����ȴ�ʱ�����üĴ����� */
#define SRE_SEC_SAA_RC_EN_CTRL_REG   	            (SRE_SEC_SAA_REG_BASE + 0x928)  /* ����Ĵ��������ʹ�� */
#define SRE_SEC_SAA_ADD_DATA_1_REG                  (SRE_SEC_SAA_REG_BASE + 0xD00)  /* ��ǰSAA ADD DATA�������� */
#define SRE_SEC_SAA_ADD_DATA_2_REG                  (SRE_SEC_SAA_REG_BASE + 0xD04)  /* ��ǰSAA ADD DATA�������� */
#define SRE_SEC_SAA_ADD_DATA_3_REG                  (SRE_SEC_SAA_REG_BASE + 0xD08)  /* ��ǰSAA ADD DATA�������� */
#define SRE_SEC_DFX_CONFIG_SEL_REG                  (SRE_SEC_SAA_REG_BASE + 0xD0C)  /* DFX���üĴ��� */
#define SRE_SEC_RSV_DFX_CONFIG_1_REG                (SRE_SEC_SAA_REG_BASE + 0xE00)  /* ����DFX���üĴ��� */
#define SRE_SEC_RSV_DFX_CONFIG_2_REG                (SRE_SEC_SAA_REG_BASE + 0xE04)  /* ����DFX���üĴ��� */
#define SRE_SEC_RSV_DFX_CONFIG_3_REG                (SRE_SEC_SAA_REG_BASE + 0xE08)  /* ����DFX���üĴ��� */
#define SRE_SEC_RSV_DFX_STATUS_1_REG                (SRE_SEC_SAA_REG_BASE + 0xE0C)  /* ����DFX״̬�Ĵ��� */
#define SRE_SEC_RSV_DFX_STATUS_2_REG                (SRE_SEC_SAA_REG_BASE + 0xE10)  /* ����DFX״̬�Ĵ��� */
#define SRE_SEC_RSV_DFX_STATUS_3_REG                (SRE_SEC_SAA_REG_BASE + 0xE14)  /* ����DFX״̬�Ĵ��� */


/******************************************************************************/
/*                      PhosphorV650 rohc Engine �Ĵ�������               */
/******************************************************************************/
/* rohc_config ģ��Ĵ�������ַ */
#define SRE_ROHC_CONFIG_BASE                     (0x10810000)

/******************************************************************************/
/*                      MC rohc_config �Ĵ�������                   */
/******************************************************************************/
#define SRE_ROHC_CONFIG_ROHC_ENABLE_REG                              (SRE_ROHC_CONFIG_BASE + 0x0)  /* ROHCȫ��ʹ�ܿ��ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_CONTROL_REG                          (SRE_ROHC_CONFIG_BASE + 0x4)  /* ROHCȫ�����üĴ����� */
#define SRE_ROHC_CONFIG_ROHC_COMP_GET_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0x8)  /* ѹ����GET POE��ַ�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_COMP_ADD_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0xC)  /* ѹ����ADD POE��ַ�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_DECOMP_GET_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0x10)  /* ��ѹ��GET POE��ַ�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_DECOMP_ADD_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0x14)  /* ��ѹ��ADD POE��ַ�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_PDCP_ADDR_REG                           (SRE_ROHC_CONFIG_BASE + 0x18)  /* PDCPʵ���ַ�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_CRCOPT_PKT_NUM_REG        (SRE_ROHC_CONFIG_BASE + 0x24)  /* �жϱ����������üĴ����� */
#define SRE_ROHC_CONFIG_ROHC_FDBACK_PKT_NUM_REG         (SRE_ROHC_CONFIG_BASE + 0x28)  /* �������������üĴ����� */
#define SRE_ROHC_CONFIG_ROHC_POE_FAIL_WAIT_TIME_REG  (SRE_ROHC_CONFIG_BASE + 0x2C)  /* POE GET��ADD����ʧ�ܵȴ��Ĵ��� */
#define SRE_ROHC_CONFIG_ROHC_POE_OK_WAIT_TIME_REG     (SRE_ROHC_CONFIG_BASE + 0x30)  /* POE GET��ADD����ɹ��ȴ��Ĵ��� */
#define SRE_ROHC_CONFIG_ROHC_BACK2IRFO_TIME_REG  (SRE_ROHC_CONFIG_BASE + 0x34)  /* ��ʱ��Ǩ�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_IPID_MAX_DELTA_REG  (SRE_ROHC_CONFIG_BASE + 0x38)  /* IPID�仯��Χ�Ĵ����� */
#define SRE_ROHC_CONFIG_PRF0_STATE_THLD_REG            (SRE_ROHC_CONFIG_BASE + 0x3c)  /* profile0ԾǨ����Ǩ���� */
#define SRE_ROHC_CONFIG_ROHC_FC2SC_N1_REG                (SRE_ROHC_CONFIG_BASE + 0x40)  /* ��ѹ��״̬��ת������ѹ���ܰ������üĴ����� */
#define SRE_ROHC_CONFIG_ROHC_CTXLIST_ADDR_REG      (SRE_ROHC_CONFIG_BASE + 0x44)  /* ROHC�����ı���ʼ��ַ���üĴ�����(ѹ������ѹ�����üĴ����ϲ��� */
#define SRE_ROHC_CONFIG_ROHC_CTX_ADDR_REG              (SRE_ROHC_CONFIG_BASE + 0x48)  /* �����Ŀռ���ʼ��ַ���üĴ�����(ѹ������ѹ�����üĴ����ϲ��� */
#define SRE_ROHC_CONFIG_ROHC_PDCP_ID_OFST_REG      (SRE_ROHC_CONFIG_BASE + 0x4C)  /* PDCPʵ��IDƫ�����üĴ����� */
#define SRE_ROHC_CONFIG_ROHC_SEC_BD_OFST_REG        (SRE_ROHC_CONFIG_BASE + 0x50)  /* SEC BD�ڱ��Ļ�������ƫ�ơ� */
#define SRE_ROHC_CONFIG_SN_WRAP_AROUND_THLD_REG     (SRE_ROHC_CONFIG_BASE + 0x54)  /* �ж�SN�������� */
#define SRE_ROHC_CONFIG_BMU_RELEASE_BASE_ADDR_REG   (SRE_ROHC_CONFIG_BASE + 0x58)  /* дBMU�ͷŻ������ַ�Ĵ��� */
#define SRE_ROHC_CONFIG_BMU_REQ_ADDR_REG                       (SRE_ROHC_CONFIG_BASE + 0x5C)  /* ��BMU���뻺���ַ�Ĵ��� */
#define SRE_ROHC_CONFIG_BMU_WR_FAIL_WATI_TIME_REG   (SRE_ROHC_CONFIG_BASE + 0x60)  /* дBUM�ͷŻ���ʧ���ӳټĴ��� */
#define SRE_ROHC_CONFIG_BMU_RD_FAIL_WAIT_TIME_REG    (SRE_ROHC_CONFIG_BASE + 0x64)  /* ��BUM���뻺��ʧ���ӳټĴ��� */
#define SRE_ROHC_CONFIG_BMU_BUF_ADDR0_REG                      (SRE_ROHC_CONFIG_BASE + 0x68)  /* ROHC�ڲ�ӵ�е�BMU�����ַ0 */
#define SRE_ROHC_CONFIG_BMU_BUF_ADDR1_REG                      (SRE_ROHC_CONFIG_BASE + 0x6C)  /* ROHC�ڲ�ӵ�е�BMU�����ַ1 */
#define SRE_ROHC_CONFIG_BMU_REQ_BUF_CNT_REG                 (SRE_ROHC_CONFIG_BASE + 0x70)  /* ������BMU�������ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_BMU_RELEASE_BUF_CNT_REG         (SRE_ROHC_CONFIG_BASE + 0x74)  /* д�ͷ�BMU�������ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_BMU_REQ_BUF_FAIL_CNT_REG       (SRE_ROHC_CONFIG_BASE + 0x78)  /* ��BMU���뻺������ʧ�ܸ���ͳ�Ƽ����� */
#define SRE_ROHC_CONFIG_BMU_RELEASE_BUF_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x7C)  /* дBMU�ͷŻ�������ʧ�ܸ���ͳ�Ƽ����� */
#define SRE_ROHC_CONFIG_BMU_REQ_BUFFER_REG                       (SRE_ROHC_CONFIG_BASE + 0x80)  /* ��������� */
#define SRE_ROHC_CONFIG_FBK_GROUP_TT_QOS_REG                  (SRE_ROHC_CONFIG_BASE + 0x84)  /* ���������*/
#define SRE_ROHC_CONFIG_HBEAT_THLD_REG                                 (SRE_ROHC_CONFIG_BASE + 0x88)  /* ֻ��������ֵ*/
#define SRE_ROHC_CONFIG_BMU_INT_THLD_REG                            (SRE_ROHC_CONFIG_BASE + 0x8C)  /* BMU����ʧ���ж���ֵ�Ĵ��� */
#define SRE_ROHC_CONFIG_BUT_MAX_TIMEOUT_THLD_REG         (SRE_ROHC_CONFIG_BASE + 0x90)  /* ���������ʱ��ʱ���� */
#define SRE_ROHC_CONFIG_POE_INT_THLD_REG                             (SRE_ROHC_CONFIG_BASE + 0x94)  /* POE����ʧ���ж���ֵ�Ĵ��� */
#define SRE_ROHC_CONFIG_ROHC_SRC_INT_REG                            (SRE_ROHC_CONFIG_BASE + 0x98)  /* ROHCԴ�жϼĴ��� */
#define SRE_ROHC_CONFIG_ROHC_INT_MASK_REG                         (SRE_ROHC_CONFIG_BASE + 0x9C)  /* ROHC�ж����μĴ��� */
#define SRE_ROHC_CONFIG_ROHC_INTSTS_REG                               (SRE_ROHC_CONFIG_BASE + 0x100)  /* ��ʱ�ж�״̬�Ĵ����� */
#define SRE_ROHC_CONFIG_ROHC_C_GET_POE_SUC_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x110)  /* ѹ����GET POE�ɹ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_C_ADD_POE_SUC_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x114)  /* ѹ����ADD POE�ɹ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_C_GET_POE_FAIL_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x118)  /* ѹ����GET POEʧ�ܴ���ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_C_ADD_POE_FAIL_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x11C)  /* ѹ����ADD POEʧ�ܴ���ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_D_GET_POE_SUC_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x120)  /* ��ѹ��GET POE�ɹ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_D_ADD_POE_SUC_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x124)  /* ��ѹ��ADD POE�ɹ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_D_GET_POE_FAIL_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x128)  /* ��ѹ��GET POEʧ�ܴ���ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_D_ADD_POE_FAIL_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x12C)  /* ��ѹ��ADD POEʧ�ܴ���ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_C_GET_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x130)  /* ѹ����GET POE����ʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_ROHC_C_ADD_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x134)  /* ѹ����ADD POE����ʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_ROHC_D_GET_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x138)  /* ��ѹ��GET POE����ʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_ROHC_D_ADD_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x13C)  /* ��ѹ��ADD POE����ʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_RD_LATENCY_AVG_REG                         (SRE_ROHC_CONFIG_BASE + 0x140)  /* ���߶�����ƽ����ʱͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_WR_LATENCY_AVG_REG                        (SRE_ROHC_CONFIG_BASE + 0x144)  /* ���߶�����ƽ����ʱͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_RD_LATENCY_MAX_REG                        (SRE_ROHC_CONFIG_BASE + 0x148)  /* ���߶����������ʱͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_WR_LATENCY_MAX_REG                       (SRE_ROHC_CONFIG_BASE + 0x14C)  /* ���߶����������ʱͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_RD_ACC_REG                      (SRE_ROHC_CONFIG_BASE + 0x150)  /* ���߶����ʴ���ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_WR_ACC_REG                     (SRE_ROHC_CONFIG_BASE + 0x154)  /* ����д���ʴ���ͳ�ƼĴ��� */
#define SRE_ROHC_CONFIG_CNT_RD_OTD_MSB_REG            (SRE_ROHC_CONFIG_BASE + 0x158)  /* ���߶�outstanding����ͳ�Ƹ�32bit */
#define SRE_ROHC_CONFIG_CNT_RD_OTD_LSB_REG             (SRE_ROHC_CONFIG_BASE + 0x15C)  /* ���߶�outstanding����ͳ�Ƶ�32bit */
#define SRE_ROHC_CONFIG_CNT_WR_OTD_MSB_REG           (SRE_ROHC_CONFIG_BASE + 0x160)  /* ����дoutstanding����ͳ�Ƹ�32bit */
#define SRE_ROHC_CONFIG_CNT_WR_OTD_LSB_REG            (SRE_ROHC_CONFIG_BASE + 0x164)  /* ����дoutstanding����ͳ�Ƶ�32bit */
#define SRE_ROHC_CONFIG_ROHC_HOLD_PKT_NUM_REG    (SRE_ROHC_CONFIG_BASE + 0x168)  /* rohc��ǰholdס��buffer*/
#define SRE_ROHC_CONFIG_ROHC_UL_DECOMP_PKT_CNT_REG   (SRE_ROHC_CONFIG_BASE + 0x200)  /* �����յ�ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_DECOMP_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x204)  /* ���н�ѹʧ��ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_DECOMP_OK_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x208)  /* ���н�ѹ�ɹ�ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_CRC_ERR_CNT_REG           (SRE_ROHC_CONFIG_BASE + 0x20C)  /* ���н�ѹ��CRCУ�����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_CRC_OK_CNT_REG             (SRE_ROHC_CONFIG_BASE + 0x210)  /* ���н�ѹ��CRCУ��ɹ���������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PKTTYP_ERR_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x214)  /* ���н�ѹ��ѹ�������ʹ�������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_COMP_PKT_CNT_REG        (SRE_ROHC_CONFIG_BASE + 0x218)  /* ����ѹ��ʹ�ܱ�������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_COMP_ERR_CNT_REG        (SRE_ROHC_CONFIG_BASE + 0x21C)  /* ����ѹ��ʧ�ܱ�������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_COMP_OK_CNT_REG          (SRE_ROHC_CONFIG_BASE + 0x220)  /* ����ѹ���ɹ���������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF0_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x234)  /* ����ѡ��Profile0ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF1_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x238)  /* ����ѡ��Profile1ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF2_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x23C)  /* ����ѡ��Profile2ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF3_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x240)  /* ����ѡ��Profile3ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF4_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x244)  /* ����ѡ��Profile4ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF6_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x248)  /* ����ѡ��Profile6ѹ����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF0_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x24C)  /* ����ѡ��Profile0��ѹ��������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF1_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x250)  /* ����ѡ��Profile1��ѹ��������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF2_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x254)  /* ����ѡ��Profile2��ѹ��������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF3_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x258)  /* ����ѡ��Profile3��ѹ��������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF4_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x25C)  /* ����ѡ��Profile4��ѹ��������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF6_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x260)  /* ����ѡ��Profile6��ѹ��������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_IR_CNT_REG          (SRE_ROHC_CONFIG_BASE + 0x264)  /* ����ѹ������IR������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_IRDYN_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x268)  /* ����ѹ������IRDYN������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_EX3_CNT_REG        (SRE_ROHC_CONFIG_BASE + 0x278)  /* ����ѹ��������չ3���Ͱ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_IR_CNT_REG           (SRE_ROHC_CONFIG_BASE + 0x27C)  /* ���н�ѹ�յ�IR������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_IRDYN_CNT_REG   (SRE_ROHC_CONFIG_BASE + 0x280)  /* ���н�ѹ�յ�IRDYN������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_TYP0_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x284)  /* ���н�ѹ�յ�0�Ͱ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_TYP1_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x288)  /* ���н�ѹ�յ�1�Ͱ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_TYP2_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x28C)  /* ���н�ѹ�յ�2�Ͱ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_EX3_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x290)  /* ���н�ѹ�յ���չ3���Ͱ�����ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_DL_FBK_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x294)  /* ����ѹ�����յ�����������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_ROHC_UL_FBK_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x298)  /* ���н�ѹ����������������ͳ�ƼĴ����� */
#define SRE_ROHC_CONFIG_CNT_CLR_EN_REG0_REG  (SRE_ROHC_CONFIG_BASE + 0x300)  /* ͳ�Ƽ�������0ʹ�ܼĴ���0�� */
#define SRE_ROHC_CONFIG_CNT_CLR_EN_REG1_REG  (SRE_ROHC_CONFIG_BASE + 0x304)  /* ͳ�Ƽ�������0ʹ�ܼĴ���1�� */
#define SRE_ROHC_CONFIG_READ_CLR_EN_REG           (SRE_ROHC_CONFIG_BASE + 0x308)  /* ����ʹ�ܿ��ƼĴ��� */
#define SRE_ROHC_CONFIG_C_CTX_RD_CTRL_REG      (SRE_ROHC_CONFIG_BASE + 0x400)  /* ѹ���������Ķ�ȡ���ƼĴ��� */
#define SRE_ROHC_CONFIG_C_CTX_WORD0_REG  (SRE_ROHC_CONFIG_BASE + 0x404)  /* ѹ�������������ݼĴ���0 */
#define SRE_ROHC_CONFIG_C_CTX_WORD1_REG  (SRE_ROHC_CONFIG_BASE + 0x408)  /* ѹ�������������ݼĴ���1 */
#define SRE_ROHC_CONFIG_C_CTX_WORD2_REG  (SRE_ROHC_CONFIG_BASE + 0x40C)  /* ѹ�������������ݼĴ���2 */
#define SRE_ROHC_CONFIG_C_CTX_WORD3_REG  (SRE_ROHC_CONFIG_BASE + 0x410)  /* ѹ�������������ݼĴ���3 */
#define SRE_ROHC_CONFIG_D_CTX_WORD0_REG  (SRE_ROHC_CONFIG_BASE + 0x414)  /* ��ѹ�����������ݼĴ���0 */
#define SRE_ROHC_CONFIG_D_CTX_WORD1_REG  (SRE_ROHC_CONFIG_BASE + 0x418)  /* ��ѹ�����������ݼĴ���1 */
#define SRE_ROHC_CONFIG_D_CTX_WORD2_REG  (SRE_ROHC_CONFIG_BASE + 0x41C)  /* ��ѹ�����������ݼĴ���2 */
#define SRE_ROHC_CONFIG_D_CTX_WORD3_REG  (SRE_ROHC_CONFIG_BASE + 0x420)  /* ��ѹ�����������ݼĴ���3 */
#define SRE_ROHC_CONFIG_PE_INDEX_REG                (SRE_ROHC_CONFIG_BASE + 0x424)  /* ��ˮ��ָ��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE1_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x500)  /* ѹ������һ����״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE1_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x504)  /* ѹ������һ��PDCP��ȡ״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE1_CID_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x508)  /* ѹ������һ��CID״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE1_CTX_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x50C)  /* ѹ������һ�������Ķ�ȡ״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE2_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x510)  /* ѹ�����ڶ�����״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE2_PPS_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x514)  /* ѹ�����ڶ���������״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE2_CRC_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x518)  /* ѹ�����ڶ���CRC״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE2_ASM_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x51C)  /* ѹ�����ڶ������״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE3_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x520)  /* ѹ������������״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE3_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x524)  /* ѹ����������PDCP��д״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_C_PE3_CTX_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x528)  /* ѹ���������������Ļ�д״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE1_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x530)  /* ��ѹ����һ����״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE1_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x534)  /* ��ѹ����һ��PDCP��ȡ״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE1_FBK_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x538)  /* ��ѹ����һ������״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE1_CTX_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x53C)  /* ��ѹ����һ�������Ķ�ȡ״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE2_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x540)  /* ��ѹ���ڶ�����״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE2_EX3_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x544)  /* ��ѹ���ڶ���EX3״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE2_CRC_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x548)  /* ��ѹ���ڶ���CRC״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE2_STA_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x54C)  /* ��ѹ���ڶ���STA״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE2_DYN_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x550)  /* ��ѹ���ڶ���DYN״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE3_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x554)  /* ��ѹ����������״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE3_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x558)  /* ��ѹ��������PDCP��д״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_D_PE3_CTX_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x55C)  /* ��ѹ�������������Ļ�д״̬��״̬�Ĵ��� */
#define SRE_ROHC_CONFIG_DFX_CONFIG_REG0		(SRE_ROHC_CONFIG_BASE + 0x0600)	/* DFX���üĴ���0                    */
#define SRE_ROHC_CONFIG_DFX_CONFIG_REG1		(SRE_ROHC_CONFIG_BASE + 0x0604)	/* DFX���üĴ���1                    */
#define SRE_ROHC_CONFIG_DFX_CONFIG_REG2		(SRE_ROHC_CONFIG_BASE + 0x0608)	/* DFX���üĴ���2                    */
#define SRE_ROHC_CONFIG_DFX_STATUE_REG0		(SRE_ROHC_CONFIG_BASE + 0x060C)	/* DFX״̬�Ĵ���0                    */
#define SRE_ROHC_CONFIG_DFX_STATUE_REG1		(SRE_ROHC_CONFIG_BASE + 0x0610)	/* DFX״̬�Ĵ���1                    */
#define SRE_ROHC_CONFIG_DFX_STATUE_REG2		(SRE_ROHC_CONFIG_BASE + 0x0614)	/* DFX״̬�Ĵ���2                    */
#define SRE_ROHC_CONFIG_C_POE_DATA_31_0		(SRE_ROHC_CONFIG_BASE + 0x0620)	/* ѹ������ȡPOE��������Word0�Ĵ���  */
#define SRE_ROHC_CONFIG_C_POE_DATA_63_32	(SRE_ROHC_CONFIG_BASE + 0x0624)	/* ѹ������ȡPOE��������Word1�Ĵ���  */
#define SRE_ROHC_CONFIG_C_POE_DATA_95_64	(SRE_ROHC_CONFIG_BASE + 0x0628)	/* ѹ������ȡPOE��������Word2�Ĵ���  */
#define SRE_ROHC_CONFIG_C_POE_DATA_127_96	(SRE_ROHC_CONFIG_BASE + 0x062C)	/* ѹ������ȡPOE��������Word3�Ĵ���  */
#define SRE_ROHC_CONFIG_D_POE_DATA_31_0		(SRE_ROHC_CONFIG_BASE + 0x0630)	/* ��ѹ����ȡPOE��������Word0�Ĵ���  */
#define SRE_ROHC_CONFIG_D_POE_DATA_63_32	(SRE_ROHC_CONFIG_BASE + 0x0634)	/* ��ѹ����ȡPOE��������Word1�Ĵ���  */
#define SRE_ROHC_CONFIG_D_POE_DATA_95_64	(SRE_ROHC_CONFIG_BASE + 0x0638)	/* ��ѹ����ȡPOE��������Word2�Ĵ���  */
#define SRE_ROHC_CONFIG_D_POE_DATA_127_96	(SRE_ROHC_CONFIG_BASE + 0x063C)	/* ��ѹ����ȡPOE��������Word3�Ĵ���  */
#define SRE_ROHC_CONFIG_C_BD_WORD_12		(SRE_ROHC_CONFIG_BASE + 0x0640)	/* ѹ������ȡBD Word12�Ĵ���	     */
#define SRE_ROHC_CONFIG_C_BD_WORD_13		(SRE_ROHC_CONFIG_BASE + 0x0644)	/* ѹ������ȡBD Word12�Ĵ���	     */
#define SRE_ROHC_CONFIG_C_BD_WORD_14		(SRE_ROHC_CONFIG_BASE + 0x0648)	/* ѹ������ȡBD Word14�Ĵ���	     */
#define SRE_ROHC_CONFIG_C_DFX_PAYLOAD		(SRE_ROHC_CONFIG_BASE + 0x064C)	/* ѹ�����ؼ���־λ״̬�Ĵ���        */
#define SRE_ROHC_CONFIG_D_BD_WORD_12		(SRE_ROHC_CONFIG_BASE + 0x0650)	/* ��ѹ����ȡBD Word12�Ĵ���	     */
#define SRE_ROHC_CONFIG_D_BD_WORD_13		(SRE_ROHC_CONFIG_BASE + 0x0654)	/* ��ѹ����ȡBD Word12�Ĵ���	     */
#define SRE_ROHC_CONFIG_D_BD_WORD_14		(SRE_ROHC_CONFIG_BASE + 0x0658)	/* ��ѹ����ȡBD Word14�Ĵ���	     */
#define SRE_ROHC_CONFIG_D_DFX_PAYLOAD		(SRE_ROHC_CONFIG_BASE + 0x065C)	/* ��ѹ���ؼ���־λ״̬�Ĵ���        */
#define SRE_ROHC_CONFIG_CTX_LOCK_DFX_REG	(SRE_ROHC_CONFIG_BASE + 0x0660)	/* ��������״̬�Ĵ���		     */
#define SRE_ROHC_CONFIG_C_BD_EEROR_ADDR		(SRE_ROHC_CONFIG_BASE + 0x0664)	/* ѹ����BD���󻺴��ַ�Ĵ���	     */
#define SRE_ROHC_CONFIG_D_BD_EEROR_ADDR		(SRE_ROHC_CONFIG_BASE + 0x0668)	/* ��ѹ��BD���󻺴��ַ�Ĵ���	     */
#define SRE_ROHC_CONFIG_C_PDCP_EEROR_ID		(SRE_ROHC_CONFIG_BASE + 0x066C)	/* ѹ����PDCP����ID�Ĵ���*/
#define SRE_ROHC_CONFIG_D_PDCP_EEROR_ID		(SRE_ROHC_CONFIG_BASE + 0x0670)	/* ��ѹ��PDCP����ID�Ĵ���*/
#define SRE_ROHC_CONFIG_C_DFX_CTRL_REG		(SRE_ROHC_CONFIG_BASE + 0x0700)	/* ѹ����DFX���ƼĴ���		     */
#define SRE_ROHC_CONFIG_D_DFX_CTRL_REG		(SRE_ROHC_CONFIG_BASE + 0x0704)	/* ��ѹ��DFX���ƼĴ���		     */

/* SCH ģ��Ĵ�������ַ */
#define SRE_SCH_BASE                                 (0xe1000000UL)
/******************************************************************************/
/*                      MC SCH �Ĵ�������                                     */
/******************************************************************************/
#define SRE_SCH_VMIMO0_CTRL_STOP_REG         (SRE_SCH_BASE + 0x0)       /* cell0 VMIMO������ֹ���ƼĴ����� */
#define SRE_SCH_VMIMO0_CTRL_START_REG        (SRE_SCH_BASE + 0x4)       /* cell0 VMIMO�����������ƼĴ����� */
#define SRE_SCH_VMIMO0_ANT_NUM_REG           (SRE_SCH_BASE + 0x8)       /* cell0 VMIMO�ŵ���Ӧ������������Ĵ����� */
#define SRE_SCH_VMIMO0_USRU_NUM_REG          (SRE_SCH_BASE + 0xC)       /* cell0 VMIMO����ʵ��U�û����Ĵ����� */
#define SRE_SCH_VMIMO0_USRV_NUM_REG          (SRE_SCH_BASE + 0x10)      /* cell0 VMIMO����ʵ��V�û����Ĵ����� */
#define SRE_SCH_VMIMO0_NPWR_NUM_REG          (SRE_SCH_BASE + 0x14)      /* cell0 VMIMO�����������ʸ����Ĵ����� */
#define SRE_SCH_VMIMO0_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x18)      /* cell0 VMIMO��������������DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO0_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x1C)      /* cell0 VMIMO�û���Ϣ��DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO0_SINR_ADDR_REG         (SRE_SCH_BASE + 0x24)      /* cell0 VMIMO��SINR����ֵд��DDR���׵�ַ�� */
#define SRE_SCH_VMIMO0_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x28)      /* cell0 VMIMO UV�û����� */
#define SRE_SCH_VMIMO0_RND_MD_REG            (SRE_SCH_BASE + 0x2C)      /* cell0 VMIMO����������ģʽѡ������� */
#define SRE_SCH_VMIMO0_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x30)      /* cell0 VMIMO SINR�������Ŵ����ĸ����� */
#define SRE_SCH_VMIMO0_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x34)      /* cell0 VMIMO SINR��������������С�����ĵ����ĸ����� */
#define SRE_SCH_VMIMO0_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x38)      /* cell0 VMIMO����DDR��С��ģʽ���ƼĴ��� */
#define SRE_SCH_VMIMO0_STAT_EN_REG           (SRE_SCH_BASE + 0x3C)      /* cell0 VMIMO���������ڲ�״̬ͳ��ʹ�ܿ��� */
#define SRE_SCH_VMIMO1_CTRL_STOP_REG         (SRE_SCH_BASE + 0x50)      /* cell1 VMIMO������ֹ���ƼĴ����� */
#define SRE_SCH_VMIMO1_CTRL_START_REG        (SRE_SCH_BASE + 0x54)      /* cell1 VMIMO�����������ƼĴ����� */
#define SRE_SCH_VMIMO1_ANT_NUM_REG           (SRE_SCH_BASE + 0x58)      /* cell1 VMIMO�ŵ���Ӧ������������Ĵ����� */
#define SRE_SCH_VMIMO1_USRU_NUM_REG          (SRE_SCH_BASE + 0x5C)      /* cell1 VMIMO����ʵ��U�û����Ĵ����� */
#define SRE_SCH_VMIMO1_USRV_NUM_REG          (SRE_SCH_BASE + 0x60)      /* cell1 VMIMO����ʵ��V�û����Ĵ����� */
#define SRE_SCH_VMIMO1_NPWR_NUM_REG          (SRE_SCH_BASE + 0x64)      /* cell1 VMIMO�����������ʸ����Ĵ����� */
#define SRE_SCH_VMIMO1_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x68)      /* cell1 VMIMO��������������DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO1_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x6C)      /* cell1 VMIMO�û���Ϣ��DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO1_SINR_ADDR_REG         (SRE_SCH_BASE + 0x74)      /* cell1 VMIMO��SINR����ֵд��DDR���׵�ַ�� */
#define SRE_SCH_VMIMO1_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x78)      /* cell1 VMIMO UV�û����� */
#define SRE_SCH_VMIMO1_RND_MD_REG            (SRE_SCH_BASE + 0x7C)      /* cell1 VMIMO����������ģʽѡ������� */
#define SRE_SCH_VMIMO1_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x80)      /* cell1 VMIMO SINR�������Ŵ����ĸ����� */
#define SRE_SCH_VMIMO1_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x84)      /* cell1 VMIMO SINR��������������С�����ĵ����ĸ����� */
#define SRE_SCH_VMIMO1_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x88)      /* cell1 VMIMO����DDR��С��ģʽ���ƼĴ��� */
#define SRE_SCH_VMIMO1_STAT_EN_REG           (SRE_SCH_BASE + 0x8C)      /* cell1 VMIM���������ڲ�״̬ͳ��ʹ�ܿ��� */
#define SRE_SCH_VMIMO2_CTRL_STOP_REG         (SRE_SCH_BASE + 0xA0)      /* cell2 VMIMO������ֹ���ƼĴ����� */
#define SRE_SCH_VMIMO2_CTRL_START_REG        (SRE_SCH_BASE + 0xA4)      /* cell2 VMIMO�����������ƼĴ����� */
#define SRE_SCH_VMIMO2_ANT_NUM_REG           (SRE_SCH_BASE + 0xA8)      /* cell2 VMIMO�ŵ���Ӧ������������Ĵ����� */
#define SRE_SCH_VMIMO2_USRU_NUM_REG          (SRE_SCH_BASE + 0xAC)      /* cell2 VMIMO����ʵ��U�û����Ĵ����� */
#define SRE_SCH_VMIMO2_USRV_NUM_REG          (SRE_SCH_BASE + 0xB0)      /* cell2 VMIMO����ʵ��V�û����Ĵ����� */
#define SRE_SCH_VMIMO2_NPWR_NUM_REG          (SRE_SCH_BASE + 0xB4)      /* cell2 VMIMO�����������ʸ����Ĵ����� */
#define SRE_SCH_VMIMO2_NPWR_ADDR_REG         (SRE_SCH_BASE + 0xB8)      /* cell2 VMIMO��������������DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO2_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0xBC)      /* cell2 VMIMO�û���Ϣ��DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO2_SINR_ADDR_REG         (SRE_SCH_BASE + 0xC4)      /* cell2 VMIMO��SINR����ֵд��DDR���׵�ַ�� */
#define SRE_SCH_VMIMO2_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0xC8)      /* cell2 VMIMO UV�û����� */
#define SRE_SCH_VMIMO2_RND_MD_REG            (SRE_SCH_BASE + 0xCC)      /* cell2 VMIMO����������ģʽѡ������� */
#define SRE_SCH_VMIMO2_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0xD0)      /* cell2 VMIMO SINR�������Ŵ����ĸ����� */
#define SRE_SCH_VMIMO2_SINR_MINIFY_REG       (SRE_SCH_BASE + 0xD4)      /* cell2 VMIMO SINR��������������С�����ĵ����ĸ����� */
#define SRE_SCH_VMIMO2_ENDIAN_MD_REG         (SRE_SCH_BASE + 0xD8)      /* cell2 VMIMO����DDR��С��ģʽ���ƼĴ��� */
#define SRE_SCH_VMIMO2_STAT_EN_REG           (SRE_SCH_BASE + 0xDC)      /* cell2 VMIM���������ڲ�״̬ͳ��ʹ�ܿ��� */
#define SRE_SCH_VMIMO3_CTRL_STOP_REG         (SRE_SCH_BASE + 0xF0)      /* cell3 VMIMO������ֹ���ƼĴ����� */
#define SRE_SCH_VMIMO3_CTRL_START_REG        (SRE_SCH_BASE + 0xF4)      /* cell3 VMIMO�����������ƼĴ����� */
#define SRE_SCH_VMIMO3_ANT_NUM_REG           (SRE_SCH_BASE + 0xF8)      /* cell3 VMIMO�ŵ���Ӧ������������Ĵ����� */
#define SRE_SCH_VMIMO3_USRU_NUM_REG          (SRE_SCH_BASE + 0xFC)      /* cell3 VMIMO����ʵ��U�û����Ĵ����� */
#define SRE_SCH_VMIMO3_USRV_NUM_REG          (SRE_SCH_BASE + 0x100)     /* cell3 VMIMO����ʵ��V�û����Ĵ����� */
#define SRE_SCH_VMIMO3_NPWR_NUM_REG          (SRE_SCH_BASE + 0x104)     /* cell3 VMIMO�����������ʸ����Ĵ����� */
#define SRE_SCH_VMIMO3_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x108)     /* cell3 VMIMO��������������DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO3_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x10C)     /* cell3 VMIMO�û���Ϣ��DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO3_SINR_ADDR_REG         (SRE_SCH_BASE + 0x114)     /* cell3 VMIMO��SINR����ֵд��DDR���׵�ַ�� */
#define SRE_SCH_VMIMO3_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x118)     /* cell3 VMIMO UV�û����� */
#define SRE_SCH_VMIMO3_RND_MD_REG            (SRE_SCH_BASE + 0x11C)     /* cell3 VMIMO����������ģʽѡ������� */
#define SRE_SCH_VMIMO3_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x120)     /* cell3 VMIMO SINR�������Ŵ����ĸ����� */
#define SRE_SCH_VMIMO3_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x124)     /* cell3 VMIMO SINR��������������С�����ĵ����ĸ����� */
#define SRE_SCH_VMIMO3_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x128)     /* cell3 VMIMO����DDR��С��ģʽ���ƼĴ��� */
#define SRE_SCH_VMIMO3_STAT_EN_REG           (SRE_SCH_BASE + 0x12C)     /* cell3 VMIMO���������ڲ�״̬ͳ��ʹ�ܿ��� */
#define SRE_SCH_VMIMO4_CTRL_STOP_REG         (SRE_SCH_BASE + 0x140)     /* cell4 VMIMO������ֹ���ƼĴ����� */
#define SRE_SCH_VMIMO4_CTRL_START_REG        (SRE_SCH_BASE + 0x144)     /* cell4 VMIMO�����������ƼĴ����� */
#define SRE_SCH_VMIMO4_ANT_NUM_REG           (SRE_SCH_BASE + 0x148)     /* cell4 VMIMO�ŵ���Ӧ������������Ĵ����� */
#define SRE_SCH_VMIMO4_USRU_NUM_REG          (SRE_SCH_BASE + 0x14C)     /* cell4 VMIMO����ʵ��U�û����Ĵ����� */
#define SRE_SCH_VMIMO4_USRV_NUM_REG          (SRE_SCH_BASE + 0x150)     /* cell4 VMIMO����ʵ��V�û����Ĵ����� */
#define SRE_SCH_VMIMO4_NPWR_NUM_REG          (SRE_SCH_BASE + 0x154)     /* cell4 VMIMO�����������ʸ����Ĵ����� */
#define SRE_SCH_VMIMO4_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x158)     /* cell4 VMIMO��������������DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO4_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x15C)     /* cell4 VMIMO�û���Ϣ��DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO4_SINR_ADDR_REG         (SRE_SCH_BASE + 0x164)     /* cell4 VMIMO��SINR����ֵд��DDR���׵�ַ�� */
#define SRE_SCH_VMIMO4_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x168)     /* cell4 VMIMO UV�û����� */
#define SRE_SCH_VMIMO4_RND_MD_REG            (SRE_SCH_BASE + 0x16C)     /* cell4 VMIMO����������ģʽѡ������� */
#define SRE_SCH_VMIMO4_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x170)     /* cell4 VMIMO SINR�������Ŵ����ĸ����� */
#define SRE_SCH_VMIMO4_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x174)     /* cell4 VMIMO SINR��������������С�����ĵ����ĸ����� */
#define SRE_SCH_VMIMO4_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x178)     /* cell4 VMIMO����DDR��С��ģʽ���ƼĴ��� */
#define SRE_SCH_VMIMO4_STAT_EN_REG           (SRE_SCH_BASE + 0x17C)     /* cell4 VMIMO���������ڲ�״̬ͳ��ʹ�ܿ��� */
#define SRE_SCH_VMIMO5_CTRL_STOP_REG         (SRE_SCH_BASE + 0x190)     /* cell5 VMIMO������ֹ���ƼĴ����� */
#define SRE_SCH_VMIMO5_CTRL_START_REG        (SRE_SCH_BASE + 0x194)     /* cell5 VMIMO�����������ƼĴ����� */
#define SRE_SCH_VMIMO5_ANT_NUM_REG           (SRE_SCH_BASE + 0x198)     /* cell5 VMIMO�ŵ���Ӧ������������Ĵ����� */
#define SRE_SCH_VMIMO5_USRU_NUM_REG          (SRE_SCH_BASE + 0x19C)     /* cell5 VMIMO����ʵ��U�û����Ĵ����� */
#define SRE_SCH_VMIMO5_USRV_NUM_REG          (SRE_SCH_BASE + 0x1A0)     /* cell5 VMIMO����ʵ��V�û����Ĵ����� */
#define SRE_SCH_VMIMO5_NPWR_NUM_REG          (SRE_SCH_BASE + 0x1A4)     /* cell5 VMIMO�����������ʸ����Ĵ����� */
#define SRE_SCH_VMIMO5_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x1A8)     /* cell5 VMIMO��������������DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO5_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x1AC)     /* cell5 VMIMO�û���Ϣ��DDR�е��׵�ַ�Ĵ����� */
#define SRE_SCH_VMIMO5_SINR_ADDR_REG         (SRE_SCH_BASE + 0x1B4)     /* cell5 VMIMO��SINR����ֵд��DDR���׵�ַ�� */
#define SRE_SCH_VMIMO5_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x1B8)     /* cell5 VMIMO UV�û����� */
#define SRE_SCH_VMIMO5_RND_MD_REG            (SRE_SCH_BASE + 0x1BC)     /* cell5 VMIMO����������ģʽѡ������� */
#define SRE_SCH_VMIMO5_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x1C0)     /* cell5 VMIMO SINR�������Ŵ����ĸ����� */
#define SRE_SCH_VMIMO5_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x1C4)     /* cell5 VMIMO SINR��������������С�����ĵ����ĸ����� */
#define SRE_SCH_VMIMO5_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x1C8)     /* cell5 VMIMO����DDR��С��ģʽ���ƼĴ��� */
#define SRE_SCH_VMIMO5_STAT_EN_REG           (SRE_SCH_BASE + 0x1CC)     /* cell5 VMIMO���������ڲ�״̬ͳ��ʹ�ܿ��� */
#define SRE_SCH_SCH_AXI_TRACE_ENA_REG        (SRE_SCH_BASE + 0x1E0)     /* SCH AXI����ͳ��ʹ�ܿ��� */
#define SRE_SCH_SCH_VMID_REG                 (SRE_SCH_BASE + 0x1E4)     /* SCH VMID���üĴ��� */
#define SRE_SCH_SCH_ARUSR_M_CTRL_REG         (SRE_SCH_BASE + 0x1E8)     /* SCH AXI���ӿ�USER��Ϣ���üĴ��� */
#define SRE_SCH_SCH_AWUSR_M_CTRL_REG         (SRE_SCH_BASE + 0x1EC)     /* SCH AXIд�ӿ�USER��Ϣ���üĴ��� */
#define SRE_SCH_SCH_DYN_CLK_GT_MSK_REG       (SRE_SCH_BASE + 0x1F0)     /* SCH��̬ʱ���ſ����μĴ��� */
#define SRE_SCH_SCH_AXI_STAT_CLR_REG         (SRE_SCH_BASE + 0x1F4)     /* SCH AXI����ͳ��������ƼĴ��� */
#define SRE_SCH_SCH_RFS_SP_CFG_REG           (SRE_SCH_BASE + 0x1F8)     /* SCH�ڲ�Artisan Memoryʱ��������ƼĴ��� */
#define SRE_SCH_VMIMO0_INTMSK_REG            (SRE_SCH_BASE + 0x200)     /* cell0 VMIMO �ж�����̬�Ĵ����� */
#define SRE_SCH_VMIMO0_RINT_REG              (SRE_SCH_BASE + 0x204)     /* cell0 VMIMO ԭʼ�жϼĴ����� */
#define SRE_SCH_VMIMO0_INTSTS_REG            (SRE_SCH_BASE + 0x208)     /* cell0 VMIMO �ж�״̬�Ĵ����� */
#define SRE_SCH_VMIMO1_INTMSK_REG            (SRE_SCH_BASE + 0x210)     /* cell1 VMIMO �ж����μĴ����� */
#define SRE_SCH_VMIMO1_RINT_REG              (SRE_SCH_BASE + 0x214)     /* cell1 VMIMO ԭʼ�жϼĴ����� */
#define SRE_SCH_VMIMO1_INTSTS_REG            (SRE_SCH_BASE + 0x218)     /* cell1 VMIMO �ж�״̬�Ĵ����� */
#define SRE_SCH_VMIMO2_INTMSK_REG            (SRE_SCH_BASE + 0x220)     /* cell2 VMIMO ������̬�Ĵ����� */
#define SRE_SCH_VMIMO2_RINT_REG              (SRE_SCH_BASE + 0x224)     /* cell2 VMIMO ԭʼ�жϼĴ����� */
#define SRE_SCH_VMIMO2_INTSTS_REG            (SRE_SCH_BASE + 0x228)     /* cell2 VMIMO �ж�״̬�Ĵ����� */
#define SRE_SCH_VMIMO3_INTMSK_REG            (SRE_SCH_BASE + 0x230)     /* cell3 VMIMO �ж�����̬�Ĵ����� */
#define SRE_SCH_VMIMO3_RINT_REG              (SRE_SCH_BASE + 0x234)     /* cell3 VMIMO ԭʼ�жϼĴ����� */
#define SRE_SCH_VMIMO3_INTSTS_REG            (SRE_SCH_BASE + 0x238)     /* cell3 VMIMO �ж�״̬�Ĵ����� */
#define SRE_SCH_VMIMO4_INTMSK_REG            (SRE_SCH_BASE + 0x240)     /* cell4 VMIMO �ж�����̬�Ĵ����� */
#define SRE_SCH_VMIMO4_RINT_REG              (SRE_SCH_BASE + 0x244)     /* cell4 VMIMO ԭʼ�жϼĴ����� */
#define SRE_SCH_VMIMO4_INTSTS_REG            (SRE_SCH_BASE + 0x248)     /* cell4 VMIMO �ж�״̬�Ĵ����� */
#define SRE_SCH_VMIMO5_INTMSK_REG            (SRE_SCH_BASE + 0x250)     /* cell5 VMIMO �ж�����̬�Ĵ����� */
#define SRE_SCH_VMIMO5_RINT_REG              (SRE_SCH_BASE + 0x254)     /* cell5 VMIMO ԭʼ�жϼĴ����� */
#define SRE_SCH_VMIMO5_INTSTS_REG            (SRE_SCH_BASE + 0x258)     /* cell5 VMIMO �ж�״̬�Ĵ����� */
#define SRE_SCH_VMIMO0_STS_REG               (SRE_SCH_BASE + 0x300)     /* cell0 VMIMO�����״̬�Ĵ����� */
#define SRE_SCH_VMIMO0_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x304)     /* cell0 VMIMO����ʱ��ͳ�� */
#define SRE_SCH_VMIMO0_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x308)     /* cell0 VMIMO������Ч�����ʱ��ͳ�� */
#define SRE_SCH_VMIMO0_ARFSM_STS_REG         (SRE_SCH_BASE + 0x30C)     /* cell0 VMIMO������DDR��AR��״̬����״̬��� */
#define SRE_SCH_VMIMO0_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x310)     /* cell0 VMIMO������DDR��AR��״̬����ת�����ʱͳ�� */
#define SRE_SCH_VMIMO0_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x314)     /* cell0 VMIMO������ɵ�RB��Ŀͳ�� */
#define SRE_SCH_VMIMO0_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x318)     /* cell0 VMIMO������ɵ��û�����Ŀͳ�� */
#define SRE_SCH_VMIMO0_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x31C)     /* cell0 VMIMO������ɵ�U�û���Ŀͳ�� */
#define SRE_SCH_VMIMO0_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x320)     /* cell0 VMIMO������ɵ�V�û���Ŀͳ�� */
#define SRE_SCH_VMIMO0_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x32C)     /* cell0 VMIMO����ERROR��Ӧ�Ķ���ַ�����ж���ַ */
#define SRE_SCH_VMIMO0_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x330)     /* cell0 VMIMO����ERROR��Ӧ��д��ַ������д��ַ */
#define SRE_SCH_VMIMO0_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x334)     /* cell0 VMIMO��ǰ���е�U�û�ID */
#define SRE_SCH_VMIMO0_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x338)     /* cell0 VMIMO��ǰ���е�V�û�ID */
#define SRE_SCH_VMIMO0_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x33C)     /* cell0 VMIMO��ǰ���еķ���RB���ô����U�û���RB��Ϣ */
#define SRE_SCH_VMIMO0_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x340)     /* cell0 VMIMO���ŵ���Ӧ�����DDR�׵�ַ��cacheline����ĸ���ͳ�� */
#define SRE_SCH_VMIMO0_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x344)     /* cell0 VMIMO��U_INFO_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO0_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x348)     /* cell0 VMIMO��NPWR_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO0_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x34C)     /* cell0 VMIMO��V_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO0_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x350)     /* cell0 VMIMO��U_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO0_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x354)     /* cell0 VMIMO��ǰ���еķ���RB���ô����U�û�ID */
#define SRE_SCH_VMIMO0_CAL_FAIL_REG          (SRE_SCH_BASE + 0x358)     /* cell0 VMIMO����ʧ��ָʾ */
#define SRE_SCH_VMIMO0_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x35C)     /* cell0 VMIMO��U_INFO_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO0_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x360)     /* cell0 VMIMO��NPWR_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO0_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x364)     /* cell0 VMIMO��V_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO0_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x368)     /* cell0 VMIMO��U_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO1_STS_REG               (SRE_SCH_BASE + 0x380)     /* cell1 VMIMO�����״̬�Ĵ����� */
#define SRE_SCH_VMIMO1_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x384)     /* cell1 VMIMO����ʱ��ͳ�� */
#define SRE_SCH_VMIMO1_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x388)     /* cell1 VMIMO������Ч�����ʱ��ͳ�� */
#define SRE_SCH_VMIMO1_ARFSM_STS_REG         (SRE_SCH_BASE + 0x38C)     /* cell1 VMIMO������DDR��AR��״̬����״̬��� */
#define SRE_SCH_VMIMO1_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x390)     /* cell1 VMIMO������DDR��AR��״̬����ת�����ʱͳ�� */
#define SRE_SCH_VMIMO1_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x394)     /* cell1 VMIMO������ɵ�RB��Ŀͳ�� */
#define SRE_SCH_VMIMO1_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x398)     /* cell1 VMIMO������ɵ��û�����Ŀͳ�� */
#define SRE_SCH_VMIMO1_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x39C)     /* cell1 VMIMO������ɵ�U�û���Ŀͳ�� */
#define SRE_SCH_VMIMO1_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x3A0)     /* cell1 VMIMO������ɵ�V�û���Ŀͳ�� */
#define SRE_SCH_VMIMO1_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x3AC)     /* cell1 VMIMO����ERROR��Ӧ�Ķ���ַ�����ж���ַ */
#define SRE_SCH_VMIMO1_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x3B0)     /* cell1 VMIMO����ERROR��Ӧ��д��ַ������д��ַ */
#define SRE_SCH_VMIMO1_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x3B4)     /* cell1 VMIMO��ǰ���е�U�û�ID */
#define SRE_SCH_VMIMO1_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x3B8)     /* cell1 VMIMO��ǰ���е�V�û�ID */
#define SRE_SCH_VMIMO1_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x3BC)     /* cell1 VMIMO��ǰ���еķ���RB���ô����U�û���RB��Ϣ */
#define SRE_SCH_VMIMO1_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x3C0)     /* cell1 VMIMO���ŵ���Ӧ�����DDR�׵�ַ��cacheline����ĸ���ͳ�� */
#define SRE_SCH_VMIMO1_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3C4)     /* cell1 VMIMO��U_INFO_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO1_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3C8)     /* cell1 VMIMO��NPWR_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO1_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3CC)     /* cell1 VMIMO��V_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO1_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3D0)     /* cell1 VMIMO��U_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO1_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x3D4)     /* cell1 VMIMO��ǰ���еķ���RB���ô����U�û�ID */
#define SRE_SCH_VMIMO1_CAL_FAIL_REG          (SRE_SCH_BASE + 0x3D8)     /* cell1 VMIMO����ʧ��ָʾ */
#define SRE_SCH_VMIMO1_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3DC)     /* cell1 VMIMO��U_INFO_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO1_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3E0)     /* cell1 VMIMO��NPWR_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO1_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3E4)     /* cell1 VMIMO��V_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO1_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3E8)     /* cell1 VMIMO��U_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO2_STS_REG               (SRE_SCH_BASE + 0x400)     /* cell2 VMIMO�����״̬�Ĵ����� */
#define SRE_SCH_VMIMO2_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x404)     /* cell2 VMIMO����ʱ��ͳ�� */
#define SRE_SCH_VMIMO2_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x408)     /* cell2 VMIMO������Ч�����ʱ��ͳ�� */
#define SRE_SCH_VMIMO2_ARFSM_STS_REG         (SRE_SCH_BASE + 0x40C)     /* cell2 VMIMO������DDR��AR��״̬����״̬��� */
#define SRE_SCH_VMIMO2_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x410)     /* cell2 VMIMO������DDR��AR��״̬����ת�����ʱͳ�� */
#define SRE_SCH_VMIMO2_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x414)     /* cell2 VMIMO������ɵ�RB��Ŀͳ�� */
#define SRE_SCH_VMIMO2_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x418)     /* cell2 VMIMO������ɵ��û�����Ŀͳ�� */
#define SRE_SCH_VMIMO2_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x41C)     /* cell2 VMIMO������ɵ�U�û���Ŀͳ�� */
#define SRE_SCH_VMIMO2_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x420)     /* cell2 VMIMO������ɵ�V�û���Ŀͳ�� */
#define SRE_SCH_VMIMO2_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x42C)     /* cell2 VMIMO����ERROR��Ӧ�Ķ���ַ�����ж���ַ */
#define SRE_SCH_VMIMO2_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x430)     /* cell2 VMIMO����ERROR��Ӧ��д��ַ������д��ַ */
#define SRE_SCH_VMIMO2_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x434)     /* cell2 VMIMO��ǰ���е�U�û�ID */
#define SRE_SCH_VMIMO2_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x438)     /* cell2 VMIMO��ǰ���е�V�û�ID */
#define SRE_SCH_VMIMO2_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x43C)     /* cell2 VMIMO��ǰ���еķ���RB���ô����U�û���RB��Ϣ */
#define SRE_SCH_VMIMO2_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x440)     /* cell2 VMIMO���ŵ���Ӧ�����DDR�׵�ַ��cacheline����ĸ���ͳ�� */
#define SRE_SCH_VMIMO2_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x444)     /* cell2 VMIMO��U_INFO_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO2_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x448)     /* cell2 VMIMO��NPWR_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO2_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x44C)     /* cell2 VMIMO��V_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO2_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x450)     /* cell2 VMIMO��U_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO2_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x454)     /* cell2 VMIMO��ǰ���еķ���RB���ô����U�û�ID */
#define SRE_SCH_VMIMO2_CAL_FAIL_REG          (SRE_SCH_BASE + 0x458)     /* cell2 VMIMO����ʧ��ָʾ */
#define SRE_SCH_VMIMO2_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x45C)     /* cell2 VMIMO��U_INFO_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO2_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x460)     /* cell2 VMIMO��NPWR_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO2_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x464)     /* cell2 VMIMO��V_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO2_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x468)     /* cell2 VMIMO��U_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO3_STS_REG               (SRE_SCH_BASE + 0x480)     /* cell3 VMIMO�����״̬�Ĵ����� */
#define SRE_SCH_VMIMO3_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x484)     /* cell3 VMIMO����ʱ��ͳ�� */
#define SRE_SCH_VMIMO3_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x488)     /* cell3 VMIMO������Ч�����ʱ��ͳ�� */
#define SRE_SCH_VMIMO3_ARFSM_STS_REG         (SRE_SCH_BASE + 0x48C)     /* cell3 VMIMO������DDR��AR��״̬����״̬��� */
#define SRE_SCH_VMIMO3_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x490)     /* cell3 VMIMO������DDR��AR��״̬����ת�����ʱͳ�� */
#define SRE_SCH_VMIMO3_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x494)     /* cell3 VMIMO������ɵ�RB��Ŀͳ�� */
#define SRE_SCH_VMIMO3_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x498)     /* cell3 VMIMO������ɵ��û�����Ŀͳ�� */
#define SRE_SCH_VMIMO3_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x49C)     /* cell3 VMIMO������ɵ�U�û���Ŀͳ�� */
#define SRE_SCH_VMIMO3_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x4A0)     /* cell3 VMIMO������ɵ�V�û���Ŀͳ�� */
#define SRE_SCH_VMIMO3_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x4AC)     /* cell3 VMIMO����ERROR��Ӧ�Ķ���ַ�����ж���ַ */
#define SRE_SCH_VMIMO3_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x4B0)     /* cell3 VMIMO����ERROR��Ӧ��д��ַ������д��ַ */
#define SRE_SCH_VMIMO3_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x4B4)     /* cell3 VMIMO��ǰ���е�U�û�ID */
#define SRE_SCH_VMIMO3_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x4B8)     /* cell3 VMIMO��ǰ���е�V�û�ID */
#define SRE_SCH_VMIMO3_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x4BC)     /* cell3 VMIMO��ǰ���еķ���RB���ô����U�û���RB��Ϣ */
#define SRE_SCH_VMIMO3_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x4C0)     /* cell3 VMIMO���ŵ���Ӧ�����DDR�׵�ַ��cacheline����ĸ���ͳ�� */
#define SRE_SCH_VMIMO3_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4C4)     /* cell3 VMIMO��U_INFO_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO3_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4C8)     /* cell3 VMIMO��NPWR_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO3_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4CC)     /* cell3 VMIMO��V_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO3_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4D0)     /* cell3 VMIMO��U_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO3_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x4D4)     /* cell3 VMIMO��ǰ���еķ���RB���ô����U�û�ID */
#define SRE_SCH_VMIMO3_CAL_FAIL_REG          (SRE_SCH_BASE + 0x4D8)     /* cell3 VMIMO����ʧ��ָʾ */
#define SRE_SCH_VMIMO3_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4DC)     /* cell3 VMIMO��U_INFO_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO3_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4E0)     /* cell3 VMIMO��NPWR_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO3_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4E4)     /* cell3 VMIMO��V_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO3_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4E8)     /* cell3 VMIMO��U_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO4_STS_REG               (SRE_SCH_BASE + 0x500)     /* cell4 VMIMO�����״̬�Ĵ����� */
#define SRE_SCH_VMIMO4_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x504)     /* cell4 VMIMO����ʱ��ͳ�� */
#define SRE_SCH_VMIMO4_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x508)     /* cell4 VMIMO������Ч�����ʱ��ͳ�� */
#define SRE_SCH_VMIMO4_ARFSM_STS_REG         (SRE_SCH_BASE + 0x50C)     /* cell4 VMIMO������DDR��AR��״̬����״̬��� */
#define SRE_SCH_VMIMO4_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x510)     /* cell4 VMIMO������DDR��AR��״̬����ת�����ʱͳ�� */
#define SRE_SCH_VMIMO4_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x514)     /* cell4 VMIMO������ɵ�RB��Ŀͳ�� */
#define SRE_SCH_VMIMO4_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x518)     /* cell4 VMIMO������ɵ��û�����Ŀͳ�� */
#define SRE_SCH_VMIMO4_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x51C)     /* cell4 VMIMO������ɵ�U�û���Ŀͳ�� */
#define SRE_SCH_VMIMO4_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x520)     /* cell4 VMIMO������ɵ�V�û���Ŀͳ�� */
#define SRE_SCH_VMIMO4_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x52C)     /* cell4 VMIMO����ERROR��Ӧ�Ķ���ַ�����ж���ַ */
#define SRE_SCH_VMIMO4_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x530)     /* cell4 VMIMO����ERROR��Ӧ��д��ַ������д��ַ */
#define SRE_SCH_VMIMO4_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x534)     /* cell4 VMIMO��ǰ���е�U�û�ID */
#define SRE_SCH_VMIMO4_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x538)     /* cell4 VMIMO��ǰ���е�V�û�ID */
#define SRE_SCH_VMIMO4_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x53C)     /* cell4 VMIMO��ǰ���еķ���RB���ô����U�û���RB��Ϣ */
#define SRE_SCH_VMIMO4_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x540)     /* cell4 VMIMO���ŵ���Ӧ�����DDR�׵�ַ��cacheline����ĸ���ͳ�� */
#define SRE_SCH_VMIMO4_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x544)     /* cell4 VMIMO��U_INFO_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO4_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x548)     /* cell4 VMIMO��NPWR_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO4_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x54C)     /* cell4 VMIMO��V_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO4_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x550)     /* cell4 VMIMO��U_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO4_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x554)     /* cell4 VMIMO��ǰ���еķ���RB���ô����U�û�ID */
#define SRE_SCH_VMIMO4_CAL_FAIL_REG          (SRE_SCH_BASE + 0x558)     /* cell4 VMIMO����ʧ��ָʾ */
#define SRE_SCH_VMIMO4_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x55C)     /* cell4 VMIMO��U_INFO_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO4_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x560)     /* cell4 VMIMO��NPWR_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO4_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x564)     /* cell4 VMIMO��V_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO4_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x568)     /* cell4 VMIMO��U_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO5_STS_REG               (SRE_SCH_BASE + 0x580)     /* cell5 VMIMO�����״̬�Ĵ����� */
#define SRE_SCH_VMIMO5_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x584)     /* cell5 VMIMO����ʱ��ͳ�� */
#define SRE_SCH_VMIMO5_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x588)     /* cell5 VMIMO������Ч�����ʱ��ͳ�� */
#define SRE_SCH_VMIMO5_ARFSM_STS_REG         (SRE_SCH_BASE + 0x58C)     /* cell5 VMIMO������DDR��AR��״̬����״̬��� */
#define SRE_SCH_VMIMO5_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x590)     /* cell5 VMIMO������DDR��AR��״̬����ת�����ʱͳ�� */
#define SRE_SCH_VMIMO5_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x594)     /* cell5 VMIMO������ɵ�RB��Ŀͳ�� */
#define SRE_SCH_VMIMO5_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x598)     /* cell5 VMIMO������ɵ��û�����Ŀͳ�� */
#define SRE_SCH_VMIMO5_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x59C)     /* cell5 VMIMO������ɵ�U�û���Ŀͳ�� */
#define SRE_SCH_VMIMO5_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x5A0)     /* cell5 VMIMO������ɵ�V�û���Ŀͳ�� */
#define SRE_SCH_VMIMO5_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x5AC)     /* cell5 VMIMO����ERROR��Ӧ�Ķ���ַ�����ж���ַ */
#define SRE_SCH_VMIMO5_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x5B0)     /* cell5 VMIMO����ERROR��Ӧ��д��ַ������д��ַ */
#define SRE_SCH_VMIMO5_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x5B4)     /* cell5 VMIMO��ǰ���е�U�û�ID */
#define SRE_SCH_VMIMO5_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x5B8)     /* cell5 VMIMO��ǰ���е�V�û�ID */
#define SRE_SCH_VMIMO5_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x5BC)     /* cell5 VMIMO��ǰ���еķ���RB���ô����U�û���RB��Ϣ */
#define SRE_SCH_VMIMO5_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x5C0)     /* cell5 VMIMO���ŵ���Ӧ�����DDR�׵�ַ��cacheline����ĸ���ͳ�� */
#define SRE_SCH_VMIMO5_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5C4)     /* cell5 VMIMO��U_INFO_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO5_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5C8)     /* cell5 VMIMO��NPWR_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO5_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5CC)     /* cell5 VMIMO��V_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO5_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5D0)     /* cell5 VMIMO��U_CHDT_SRAM��żУ��������ͳ�� */
#define SRE_SCH_VMIMO5_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x5D4)     /* cell5 VMIMO��ǰ���еķ���RB���ô����U�û�ID */
#define SRE_SCH_VMIMO5_CAL_FAIL_REG          (SRE_SCH_BASE + 0x5D8)     /* cell5 VMIMO����ʧ��ָʾ */
#define SRE_SCH_VMIMO5_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5DC)     /* cell5 VMIMO��U_INFO_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO5_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5E0)     /* cell5 VMIMO��NPWR_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO5_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5E4)     /* cell5 VMIMO��V_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_VMIMO5_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5E8)     /* cell5 VMIMO��U_CHDT_SRAM��һ����żУ�����ĵ�ַ */
#define SRE_SCH_SCH_AXI_WR_LATENCY_AVG_STAT_REG  (SRE_SCH_BASE + 0x600)     /* SCH AXI����дͨ��ƽ��ʱ��ͳ�� */
#define SRE_SCH_SCH_AXI_RD_LATENCY_AVG_STAT_REG  (SRE_SCH_BASE + 0x604)     /* SCH AXI���߶�ͨ��ƽ��ʱ��ͳ�� */
#define SRE_SCH_SCH_AXI_WR_LATENCY_MAX_STAT_REG  (SRE_SCH_BASE + 0x608)     /* SCH AXI����дͨ�����ʱ��ͳ�� */
#define SRE_SCH_SCH_AXI_RD_LATENCY_MAX_STAT_REG  (SRE_SCH_BASE + 0x60C)     /* SCH AXI���߶�ͨ�����ʱ��ͳ�� */
#define SRE_SCH_SCH_AXI_WR_ACC_STAT_REG      (SRE_SCH_BASE + 0x610)     /* SCH AXI����дͨ��������д�������ͳ�� */
#define SRE_SCH_SCH_AXI_RD_ACC_STAT_REG      (SRE_SCH_BASE + 0x614)     /* SCH AXI���߶�ͨ�������Ķ��������ͳ�� */
#define SRE_SCH_SCH_AXI_RCHN0_OTSD_CNT_REG   (SRE_SCH_BASE + 0x618)     /* SCH AXI ��ͨ��0 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_RCHN1_OTSD_CNT_REG   (SRE_SCH_BASE + 0x61C)     /* SCH AXI ��ͨ��1 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_RCHN2_OTSD_CNT_REG   (SRE_SCH_BASE + 0x620)     /* SCH AXI ��ͨ��2 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_RCHN3_OTSD_CNT_REG   (SRE_SCH_BASE + 0x624)     /* SCH AXI ��ͨ��3 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_RCHN4_OTSD_CNT_REG   (SRE_SCH_BASE + 0x628)     /* SCH AXI ��ͨ��4 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_RCHN5_OTSD_CNT_REG   (SRE_SCH_BASE + 0x62C)     /* SCH AXI ��ͨ��5 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_WCHN0_OTSD_CNT_REG   (SRE_SCH_BASE + 0x630)     /* SCH AXI дͨ��0 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_WCHN1_OTSD_CNT_REG   (SRE_SCH_BASE + 0x634)     /* SCH AXI дͨ��1 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_WCHN2_OTSD_CNT_REG   (SRE_SCH_BASE + 0x638)     /* SCH AXI дͨ��2 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_WCHN3_OTSD_CNT_REG   (SRE_SCH_BASE + 0x63C)     /* SCH AXI дͨ��3 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_WCHN4_OTSD_CNT_REG   (SRE_SCH_BASE + 0x640)     /* SCH AXI дͨ��4 outstandingͳ�� */
#define SRE_SCH_SCH_AXI_WCHN5_OTSD_CNT_REG   (SRE_SCH_BASE + 0x644)     /* SCH AXI дͨ��5 outstandingͳ�� */
#define SRE_SCH_SCH_CFG_RSV0_REG             (SRE_SCH_BASE + 0x700)     /* SCH ���ñ����Ĵ���0 */
#define SRE_SCH_SCH_CFG_RSV1_REG             (SRE_SCH_BASE + 0x704)     /* SCH ���ñ����Ĵ���1 */
#define SRE_SCH_SCH_CFG_RSV2_REG             (SRE_SCH_BASE + 0x708)     /* SCH ���ñ����Ĵ���2 */
#define SRE_SCH_SCH_STS_RSV0_REG             (SRE_SCH_BASE + 0x720)     /* SCH ״̬�����Ĵ���0 */
#define SRE_SCH_SCH_STS_RSV1_REG             (SRE_SCH_BASE + 0x724)     /* SCH ״̬�����Ĵ���1 */
#define SRE_SCH_SCH_STS_RSV2_REG             (SRE_SCH_BASE + 0x728)     /* SCH ״̬�����Ĵ���2 */



/******************************************************************************/
/*                      PhosphorV600 SYSCTRL nManager �Ĵ�������              */
/******************************************************************************/
#if 0         /* z00202052 */
#define SRE_SYS_REG_BASEADDR         (0x13e00000) /* SYSCTRL nManager�ļĴ�������ַ */
#else
#define SRE_SYS_REG_BASEADDR         (0xe3e00000) /* SYSCTRL nManager�ļĴ�������ַ */
#endif        /* z00202052 */
#define SRE_SYS_REG_A9_0_1_INT       (SRE_SYS_REG_BASEADDR + 0x0500) /* A9_0���͵�A9_1���жϵ�ַ */

#define SRE_SYS_PERCTRL6_REG         (SRE_SYS_REG_BASEADDR + 0x44)   /*������ƼĴ���6*/
#define SRE_SYS_PERCTRL7_REG         (SRE_SYS_REG_BASEADDR + 0x48)   /*������ƼĴ���7*/
#define SRE_SYS_PERCTRL8_REG         (SRE_SYS_REG_BASEADDR + 0x4C)   /*������ƼĴ���8*/
#define SRE_SYS_PERCTRL9_REG         (SRE_SYS_REG_BASEADDR + 0x50)   /*������ƼĴ���9*/
#define SRE_SYS_PERCTRL10_REG        (SRE_SYS_REG_BASEADDR + 0x54)   /*������ƼĴ���10*/
#define SRE_SYS_PERCTRL15_REG        (SRE_SYS_REG_BASEADDR + 0x68)   /*������ƼĴ���10*/

#define SRE_SYS_PERCTRL33_REG        (SRE_SYS_REG_BASEADDR + 0xB0)   /* ������ƼĴ��� 33 */
#define SRE_SYS_PERCTRL34_REG        (SRE_SYS_REG_BASEADDR + 0xB4)   /* ������ƼĴ��� 34 */
#define SRE_SYS_PERCTRL37_REG        (SRE_SYS_REG_BASEADDR + 0xC0)   /* ������ƼĴ��� 37 */
#define SRE_SYS_PERCTRL38_REG        (SRE_SYS_REG_BASEADDR + 0xC4)   /* ������ƼĴ��� 38 */
#define SRE_SYS_PERCTRL41_REG        (SRE_SYS_REG_BASEADDR + 0xD0)   /* ������ƼĴ��� 41 */
#define SRE_SYS_PERCTRL42_REG        (SRE_SYS_REG_BASEADDR + 0xD4)   /* ������ƼĴ��� 42 */
#define SRE_SYS_PERCTRL45_REG        (SRE_SYS_REG_BASEADDR + 0xE0)   /* ������ƼĴ��� 45 */
#define SRE_SYS_PERCTRL46_REG        (SRE_SYS_REG_BASEADDR + 0xE4)   /* ������ƼĴ��� 46 */

#define SRE_SYS_PERCTRL50_REG        (SRE_SYS_REG_BASEADDR + 0xF4)   /* ������ƼĴ��� 50 */
#define SRE_SYS_PERCTRL51_REG        (SRE_SYS_REG_BASEADDR + 0xF8)   /* ������ƼĴ��� 51 */
#define SRE_SYS_PERCTRL52_REG        (SRE_SYS_REG_BASEADDR + 0xFC)   /* ������ƼĴ��� 52 */
#define SRE_SYS_PERCTRL69_REG        (SRE_SYS_REG_BASEADDR + 0x140)   /* ������ƼĴ��� 69 */
#define SRE_SYS_EXTSTATUS1_REG       (SRE_SYS_REG_BASEADDR + 0x40C)   /* ��չ״̬�Ĵ���1 */
#define SRE_SYS_EXTSTATUS2_REG       (SRE_SYS_REG_BASEADDR + 0x410)   /* ��չ״̬�Ĵ���2 */
#define SRE_SYS_EXTSTATUS3_REG       (SRE_SYS_REG_BASEADDR + 0x414)   /* ��չ״̬�Ĵ���3 */

#define SRE_SYSSTAT6_REG             (SRE_SYS_REG_BASEADDR + 0x420)   /* ��չϵͳ״̬�Ĵ���6��SerDes 0 bist״̬ */
#define SRE_SYSSTAT7_REG             (SRE_SYS_REG_BASEADDR + 0x424)   /* ��չϵͳ״̬�Ĵ���6��SerDes 1 bist״̬ */

#define SRE_SYS_EXTSTATUS17_REG      (SRE_SYS_REG_BASEADDR + 0x44C)   /* ��չ״̬�Ĵ���17 */
#define SRE_SYS_DBGREQ_REG           (SRE_SYS_REG_BASEADDR + 0x5E0)   /* A0 DBG�Ĵ��� */

#define SRE_SYS_SEC_RESET_REQ_REG    (SRE_SYS_REG_BASEADDR + 0x0708)  /* SEC��λ������ƼĴ���  */
#define SRE_SYS_SEC_RESET_DREQ_REG   (SRE_SYS_REG_BASEADDR + 0x070C)  /* SEC��λȥ������ƼĴ��� */

#define SRE_SYS_HDCP_RESET_REQ_REG   (SRE_SYS_REG_BASEADDR + 0x0748)  /* hdcp��λ������ƼĴ���  */
#define SRE_SYS_HDCP_RESET_DREQ_REG  (SRE_SYS_REG_BASEADDR + 0x074C)  /* hdcp��λȥ������ƼĴ��� */


/* BEGIN: Added by h00176630, 2012/6/9 */
#define SRE_SC_CTRL_REG                  (SRE_SYS_REG_BASEADDR + 0x0)       /* SC_CTRLΪϵͳ���ƼĴ����� */
#define SRE_SC_SYSRST_REG                (SRE_SYS_REG_BASEADDR + 0x4)       /* SC_SYSSTATΪϵͳ��λ�Ĵ����� */
#define SRE_SC_IMCTRL_REG                (SRE_SYS_REG_BASEADDR + 0x8)       /* SC_IMCTRLΪ�ж�ģʽ���ƼĴ������������� */
#define SRE_SC_IMSTAT_REG                (SRE_SYS_REG_BASEADDR + 0xC)       /* SC_IMSTATΪ�ж�ģʽ״̬�Ĵ������������� */
#define SRE_SC_XTALCTRL_REG              (SRE_SYS_REG_BASEADDR + 0x10)      /* SC_XTALCTRLΪ������ƼĴ����� */
#define SRE_SC_PLLCTRL_REG               (SRE_SYS_REG_BASEADDR + 0x14)      /* SC_PLLCTRLΪPLL���ƼĴ����� */
#define SRE_SC_DBG_AUTH_CTRL_REG         (SRE_SYS_REG_BASEADDR + 0x20)      /* ����ģʽ��ȫ�ȼ���Ȩ���ơ���ע�⣺1���˼Ĵ����ռ�����ǰ�ȫ���ʲ��ܳɹ���2��Ĭ�Ͼ��Ǵ򿪵���ģʽ����©��������������ʱ���ʼ���رյ��Թ��ܣ� */
#define SRE_SC_PLLFCTRL0_REG             (SRE_SYS_REG_BASEADDR + 0x100)     /* SC_PLLFCTRL0ΪPLL0���ƼĴ���0�� */
#define SRE_SC_PLLFCTRL1_REG             (SRE_SYS_REG_BASEADDR + 0x104)     /* SC_PLLFCTRL1ΪPLL0���ƼĴ���1�� */
#define SRE_SC_PLLFCTRL2_REG             (SRE_SYS_REG_BASEADDR + 0x108)     /* SC_PLLFCTRL2ΪPLL1���ƼĴ���0�� */
#define SRE_SC_PLLFCTRL3_REG             (SRE_SYS_REG_BASEADDR + 0x10C)     /* SC_PLLFCTRL3ΪPLL1���ƼĴ���1�� */
#define SRE_SC_PLLFCTRL4_REG             (SRE_SYS_REG_BASEADDR + 0x110)     /* SC_PLLFCTRL4ΪPLL2���ƼĴ���0�� */
#define SRE_SC_PLLFCTRL5_REG             (SRE_SYS_REG_BASEADDR + 0x114)     /* SC_PLLFCTRL5ΪPLL2���ƼĴ���1�� */
#define SRE_SC_PLLFCTRL6_REG             (SRE_SYS_REG_BASEADDR + 0x118)     /* SC_PLLFCTRL6ΪPLL3���ƼĴ���0�� */
#define SRE_SC_PLLFCTRL7_REG             (SRE_SYS_REG_BASEADDR + 0x11C)     /* SC_PLLFCTRL7ΪPLL3���ƼĴ���1�� */
#define SRE_SC_PLLFCTRL8_REG             (SRE_SYS_REG_BASEADDR + 0x120)     /* SC_PLLFCTRL8ΪPLL4���ƼĴ���0�� */
#define SRE_SC_PLLFCTRL9_REG             (SRE_SYS_REG_BASEADDR + 0x124)     /* SC_PLLFCTRL9ΪPLL4���ƼĴ���1�� */
#define SRE_SC_PLL_CLK_BYPASS_REG        (SRE_SYS_REG_BASEADDR + 0x180)     /* PLL��ع���ʱ��ѡ�� */
#define SRE_SC_CLK_SEL0_REG              (SRE_SYS_REG_BASEADDR + 0x188)     /* ��������ϵͳ����ʱ��Ƶ��ѡ�� */
#define SRE_SC_CLK_SEL1_REG              (SRE_SYS_REG_BASEADDR + 0x18C)     /* ����MACʱ��Ƶ��ѡ�� */
#define SRE_SC_CLK_SEL2_REG              (SRE_SYS_REG_BASEADDR + 0x190)     /* Ӳ������������ʱ��Ƶ��ѡ�� */
#define SRE_SC_CLK_SEL3_REG              (SRE_SYS_REG_BASEADDR + 0x194)     /* ��������ӿڹ���ʱ��ѡ�� */
#define SRE_SC_TOP_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x200)     /* ����ȫ��ʱ��ʹ�ܿ��� */
#define SRE_SC_TOP_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x204)     /* ����ȫ��ʱ�ӹرտ��� */
#define SRE_SC_CPU_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x220)     /* ���� */
#define SRE_SC_CPU_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x224)     /* ���� */
#define SRE_SC_SERDES_CLK_EN_REG         (SRE_SYS_REG_BASEADDR + 0x280)     /* ���� */
#define SRE_SC_SERDES_CLK_DIS_REG        (SRE_SYS_REG_BASEADDR + 0x284)     /* ���� */
#define SRE_SC_GE_CLK_EN_REG             (SRE_SYS_REG_BASEADDR + 0x2A0)     /* GEʱ��ʹ�ܼĴ��� */
#define SRE_SC_GE_CLK_DIS_REG            (SRE_SYS_REG_BASEADDR + 0x2A4)     /* GEʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_XGE_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x2B0)     /* XGEʱ��ʹ�ܼĴ��� */
#define SRE_SC_XGE_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x2B4)     /* XGEʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_PCIE_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x2E0)     /* PCIEʱ��ʹ�ܼĴ��� */
#define SRE_SC_PCIE_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x2E4)     /* PCIEʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_SRIO_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x2F0)     /* SRIOʱ��ʹ�ܼĴ��� */
#define SRE_SC_SRIO_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x2F4)     /* SRIOʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_USB_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x300)     /* USBʱ��ʹ�ܼĴ��� */
#define SRE_SC_USB_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x304)     /* USBʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_SATA_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x310)     /* SATAʱ��ʹ�ܼĴ��� */
#define SRE_SC_SATA_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x314)     /* SATAʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_DDR_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x320)     /* DDRʱ��ʹ�ܼĴ��� */
#define SRE_SC_DDR_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x324)     /* DDRʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_MMC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x330)     /* MMCʱ��ʹ�ܼĴ��� */
#define SRE_SC_MMC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x334)     /* MMCʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_SFC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x338)     /* SFCʱ��ʹ�ܼĴ��� */
#define SRE_SC_SFC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x33C)     /* SFCʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_NANDC_CLK_EN_REG          (SRE_SYS_REG_BASEADDR + 0x340)     /* NANDCʱ��ʹ�ܼĴ��� */
#define SRE_SC_NANDC_CLK_DIS_REG         (SRE_SYS_REG_BASEADDR + 0x344)     /* NANDCʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_LOCALBUS_CLK_EN_REG       (SRE_SYS_REG_BASEADDR + 0x350)     /* LOCALBUSʱ��ʹ�ܼĴ��� */
#define SRE_SC_LOCALBUS_CLK_DIS_REG      (SRE_SYS_REG_BASEADDR + 0x354)     /* LOCALBUSʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_UART_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x380)     /* UARTʱ��ʹ�ܼĴ��� */
#define SRE_SC_UART_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x384)     /* UARTʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_I2C_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x388)     /* I2Cʱ��ʹ�ܼĴ��� */
#define SRE_SC_I2C_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x38C)     /* I2Cʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_MDIO_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x390)     /* MDIOʱ��ʹ�ܼĴ��� */
#define SRE_SC_MDIO_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x394)     /* MDIOʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_SPI_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x398)     /* SPIʱ��ʹ�ܼĴ��� */
#define SRE_SC_SPI_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x39C)     /* SPIʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_GPIO_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x3A0)     /* GPIOʱ��ʹ�ܼĴ��� */
#define SRE_SC_GPIO_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x3A4)     /* GPIOʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_TDM_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x3C0)     /* TDMʱ��ʹ�ܼĴ��� */
#define SRE_SC_TDM_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x3C4)     /* TDMʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_HDLC_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x3C8)     /* HDLCʱ��ʹ�ܼĴ��� */
#define SRE_SC_HDLC_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x3CC)     /* HDLCʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_BOOTROM_CLK_EN_REG        (SRE_SYS_REG_BASEADDR + 0x400)     /* BOOTROMʱ��ʹ�ܼĴ��� */
#define SRE_SC_BOOTROM_CLK_DIS_REG       (SRE_SYS_REG_BASEADDR + 0x404)     /* BOOTROMʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_SEC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x408)     /* SECʱ��ʹ�ܼĴ��� */
#define SRE_SC_SEC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x40C)     /* SECʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_POE_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x410)     /* POEʱ��ʹ�ܼĴ��� */
#define SRE_SC_POE_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x414)     /* POEʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_BMU_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x418)     /* BMUʱ��ʹ�ܼĴ��� */
#define SRE_SC_BMU_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x41C)     /* BMUʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_PPE_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x420)     /* PPEʱ��ʹ�ܼĴ��� */
#define SRE_SC_PPE_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x424)     /* PPEʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_NP_CLK_EN_REG             (SRE_SYS_REG_BASEADDR + 0x428)     /* SPPEʱ��ʹ�ܼĴ��� */
#define SRE_SC_NP_CLK_DIS_REG            (SRE_SYS_REG_BASEADDR + 0x42C)     /* SPPEʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_CRC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x430)     /* CRCʱ��ʹ�ܼĴ��� */
#define SRE_SC_CRC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x434)     /* CRCʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_DMAC_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x438)     /* DMACʱ��ʹ�ܼĴ��� */
#define SRE_SC_DMAC_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x43C)     /* DMACʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_ROHC_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x440)     /* ROHCʱ��ʹ�ܼĴ��� */
#define SRE_SC_ROHC_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x444)     /* ROHCʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_HDCP_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x448)     /* HDCPʱ��ʹ�ܼĴ��� */
#define SRE_SC_HDCP_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x44C)     /* HDCPʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_PDM_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x450)     /* PDMʱ��ʹ�ܼĴ��� */
#define SRE_SC_PDM_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x454)     /* PDMʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_TRING_CLK_EN_REG          (SRE_SYS_REG_BASEADDR + 0x458)     /* TRINGʱ��ʹ�ܼĴ��� */
#define SRE_SC_TRING_CLK_DIS_REG         (SRE_SYS_REG_BASEADDR + 0x45C)     /* TRINGʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_RNG_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x460)     /* RNGʱ��ʹ�ܼĴ��� */
#define SRE_SC_RNG_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x464)     /* RNGʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_IMA_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x468)     /* IMAʱ��ʹ�ܼĴ��� */
#define SRE_SC_IMA_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x46C)     /* IMAʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_SCH_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x470)     /* SCHʱ��ʹ�ܼĴ��� */
#define SRE_SC_SCH_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x474)     /* SCHʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_TM_CLK_EN_REG             (SRE_SYS_REG_BASEADDR + 0x478)     /* TMʱ��ʹ�ܼĴ��� */
#define SRE_SC_TM_CLK_DIS_REG            (SRE_SYS_REG_BASEADDR + 0x47C)     /* TMʱ�ӽ�ֹ�Ĵ��� */
#define SRE_SC_IO_H2X_BRG_WFQCFG_REG     (SRE_SYS_REG_BASEADDR + 0x4A0)
#define SRE_SC_IO_H2X_BRG_CTRL_REG       (SRE_SYS_REG_BASEADDR + 0x4A4)
#define SRE_SC_IO_H2X_BRG_STATCFG_REG    (SRE_SYS_REG_BASEADDR + 0x4A8)
#define SRE_SC_ALG_H2X_BRG_WFQCFG_REG    (SRE_SYS_REG_BASEADDR + 0x4B0)
#define SRE_SC_ALG_H2X_BRG_CTRL_REG      (SRE_SYS_REG_BASEADDR + 0x4B4)
#define SRE_SC_ALG_H2X_BRG_STATCFG_REG   (SRE_SYS_REG_BASEADDR + 0x4B8)
#define SRE_SC_TOP_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x500)     /* ����CRG��λ������ƼĴ��� */
#define SRE_SC_TOP_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x504)     /* ����CRG��λȥ������ƼĴ��� */
#define SRE_SC_CPU_RESET_REQ0_REG        (SRE_SYS_REG_BASEADDR + 0x520)     /* Cluster0�ڲ���λ������ƼĴ����� */
#define SRE_SC_CPU_RESET_DREQ0_REG       (SRE_SYS_REG_BASEADDR + 0x524)     /* Cluster0�ڲ���λȥ������ƼĴ����� */
#define SRE_SC_CPU_RESET_REQ1_REG        (SRE_SYS_REG_BASEADDR + 0x528)     /* Cluster1�ڲ���λ������ƼĴ����� */
#define SRE_SC_CPU_RESET_DREQ1_REG       (SRE_SYS_REG_BASEADDR + 0x52C)     /* Cluster1�ڲ���λȥ������ƼĴ����� */
#define SRE_SC_CPU_RESET_REQ2_REG        (SRE_SYS_REG_BASEADDR + 0x530)     /* Cluster2�ڲ���λ������ƼĴ����� */
#define SRE_SC_CPU_RESET_DREQ2_REG       (SRE_SYS_REG_BASEADDR + 0x534)     /* Cluster2�ڲ���λȥ������ƼĴ����� */
#define SRE_SC_CPU_RESET_REQ3_REG        (SRE_SYS_REG_BASEADDR + 0x538)     /* Cluster3�ڲ���λ������ƼĴ����� */
#define SRE_SC_CPU_RESET_DREQ3_REG       (SRE_SYS_REG_BASEADDR + 0x53C)     /* Cluster3�ڲ���λȥ������ƼĴ����� */
#define SRE_SC_CACHE_RESET_REQ_REG       (SRE_SYS_REG_BASEADDR + 0x560)     /* l3cache��λ������ƼĴ��� */
#define SRE_SC_CACHE_RESET_DREQ_REG      (SRE_SYS_REG_BASEADDR + 0x564)     /* l3cache��λȥ������ƼĴ��� */
#define SRE_SC_SERDES_RESET_REQ0_REG     (SRE_SYS_REG_BASEADDR + 0x580)     /* Serdes��λ������ƼĴ���1 */
#define SRE_SC_SERDES_RESET_DREQ0_REG    (SRE_SYS_REG_BASEADDR + 0x584)     /* Serdes��λȥ������ƼĴ���1 */
#define SRE_SC_SERDES_RESET_REQ1_REG     (SRE_SYS_REG_BASEADDR + 0x588)     /* Serdes��λ������ƼĴ���2 */
#define SRE_SC_SERDES_RESET_DREQ1_REG    (SRE_SYS_REG_BASEADDR + 0x58C)     /* Serdes��λȥ������ƼĴ���2 */
#define SRE_SC_SERDES_RESET_REQ2_REG     (SRE_SYS_REG_BASEADDR + 0x590)     /* Serdes��λ������ƼĴ���3 */
#define SRE_SC_SERDES_RESET_DREQ2_REG    (SRE_SYS_REG_BASEADDR + 0x594)     /* Serdes��λȥ������ƼĴ���3 */
#define SRE_SC_GE_RESET_REQ_REG          (SRE_SYS_REG_BASEADDR + 0x5A0)     /* GE��λ������ƼĴ��� */
#define SRE_SC_GE_RESET_DREQ_REG         (SRE_SYS_REG_BASEADDR + 0x5A4)     /* GE��λȥ������ƼĴ��� */
#define SRE_SC_XGE_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x5B0)     /* XGE��λ������ƼĴ��� */
#define SRE_SC_XGE_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x5B4)     /* XGE��λȥ������ƼĴ��� */
#define SRE_SC_MAC_CFG_RESET_REQ_REG     (SRE_SYS_REG_BASEADDR + 0x5C0)     /* MAC������λ������ƼĴ��� */
#define SRE_SC_MAC_CFG_RESET_DREQ_REG    (SRE_SYS_REG_BASEADDR + 0x5C4)     /* MAC������λȥ������ƼĴ��� */
#define SRE_SC_MAC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x5C8)     /* MAC��λ������ƼĴ��� */
#define SRE_SC_MAC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x5CC)     /* MAC��λȥ������ƼĴ��� */
#define SRE_SC_PCIE_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x5E0)     /* PCIE��λ������ƼĴ��� */
#define SRE_SC_PCIE_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x5E4)     /* PCIE��λȥ������ƼĴ��� */
#define SRE_SC_SRIO_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x5F0)     /* SRIO��λ������ƼĴ��� */
#define SRE_SC_SRIO_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x5F4)     /* SRIO��λȥ������ƼĴ��� */
#define SRE_SC_USB_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x600)     /* USB��λ������ƼĴ��� */
#define SRE_SC_USB_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x604)     /* USB��λȥ������ƼĴ��� */
#define SRE_SC_DDR_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x620)     /* DDR��λ������ƼĴ��� */
#define SRE_SC_DDR_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x624)     /* DDR��λȥ������ƼĴ��� */
#define SRE_SC_MMC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x630)     /* MMC��λ������ƼĴ��� */
#define SRE_SC_MMC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x634)     /* MMC��λȥ������ƼĴ��� */
#define SRE_SC_SFC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x638)     /* SFC��λ������ƼĴ��� */
#define SRE_SC_SFC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x63C)     /* SFC��λȥ������ƼĴ��� */
#define SRE_SC_NANDC_RESET_REQ_REG       (SRE_SYS_REG_BASEADDR + 0x640)     /* NANDC��λ������ƼĴ��� */
#define SRE_SC_NANDC_RESET_DREQ_REG      (SRE_SYS_REG_BASEADDR + 0x644)     /* NANDC��λȥ������ƼĴ��� */
#define SRE_SC_LOCALBUS_RESET_REQ_REG    (SRE_SYS_REG_BASEADDR + 0x650)     /* LOCALBUS��λ������ƼĴ��� */
#define SRE_SC_LOCALBUS_RESET_DREQ_REG   (SRE_SYS_REG_BASEADDR + 0x654)     /* LOCALBUS��λȥ������ƼĴ��� */
#define SRE_SC_UART_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x680)     /* UART��λ������ƼĴ��� */
#define SRE_SC_UART_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x684)     /* UART��λȥ������ƼĴ��� */
#define SRE_SC_I2C_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x688)     /* I2C��λ������ƼĴ��� */
#define SRE_SC_I2C_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x68C)     /* I2C��λȥ������ƼĴ��� */
#define SRE_SC_MDIO_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x690)     /* MDIO��λ������ƼĴ��� */
#define SRE_SC_MDIO_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x694)     /* MDIO��λȥ������ƼĴ��� */
#define SRE_SC_SPI_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x698)     /* SPI��λ������ƼĴ��� */
#define SRE_SC_SPI_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x69C)     /* SPI��λȥ������ƼĴ��� */
#define SRE_SC_GPIO_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x6A0)     /* GPIO��λ������ƼĴ��� */
#define SRE_SC_GPIO_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x6A4)     /* GPIO��λȥ������ƼĴ��� */
#define SRE_SC_TDM_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x6C0)     /* TDM��λ������ƼĴ��� */
#define SRE_SC_TDM_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x6C4)     /* TDM��λȥ������ƼĴ��� */
#define SRE_SC_HDLC_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x6C8)     /* HDLC��λ������ƼĴ��� */
#define SRE_SC_HDLC_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x6CC)     /* HDLC��λȥ������ƼĴ��� */
#define SRE_SC_BOOTROM_RESET_REQ_REG     (SRE_SYS_REG_BASEADDR + 0x700)     /* BOOTROM��λ������ƼĴ��� */
#define SRE_SC_BOOTROM_RESET_DREQ_REG    (SRE_SYS_REG_BASEADDR + 0x704)     /* BOOTROM��λȥ������ƼĴ��� */
#define SRE_SC_SEC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x708)     /* SEC��λ������ƼĴ��� */
#define SRE_SC_SEC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x70C)     /* SEC��λȥ������ƼĴ��� */
#define SRE_SC_POE_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x710)     /* POE��λ������ƼĴ��� */
#define SRE_SC_POE_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x714)     /* POE��λȥ������ƼĴ��� */
#define SRE_SC_BMU_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x718)     /* BMU��λ������ƼĴ��� */
#define SRE_SC_BMU_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x71C)     /* BMU��λȥ������ƼĴ��� */
#define SRE_SC_PPE_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x720)     /* PPE��λ������ƼĴ��� */
#define SRE_SC_PPE_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x724)     /* PPE��λȥ������ƼĴ��� */
#define SRE_SC_NP_RESET_REQ_REG          (SRE_SYS_REG_BASEADDR + 0x728)     /* SPPE��λ������ƼĴ��� */
#define SRE_SC_NP_RESET_DREQ_REG         (SRE_SYS_REG_BASEADDR + 0x72C)     /* SPPE��λȥ������ƼĴ��� */
#define SRE_SC_CRC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x730)     /* CRC��λ������ƼĴ��� */
#define SRE_SC_CRC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x734)     /* CRC��λȥ������ƼĴ��� */
#define SRE_SC_DMAC_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x738)     /* DMAC��λ������ƼĴ��� */
#define SRE_SC_DMAC_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x73C)     /* DMAC��λȥ������ƼĴ��� */
#define SRE_SC_ROHC_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x740)     /* ROHC��λ������ƼĴ��� */
#define SRE_SC_ROHC_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x744)     /* ROHC��λȥ������ƼĴ��� */
#define SRE_SC_HDCP_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x748)     /* HDCP��λ������ƼĴ��� */
#define SRE_SC_HDCP_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x74C)     /* HDCP��λȥ������ƼĴ��� */
#define SRE_SC_PDM_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x750)     /* PDM��λ������ƼĴ��� */
#define SRE_SC_PDM_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x754)     /* PDM��λȥ������ƼĴ��� */
#define SRE_SC_TRING_RESET_REQ_REG       (SRE_SYS_REG_BASEADDR + 0x758)     /* TRING��λ������ƼĴ��� */
#define SRE_SC_TRING_RESET_DREQ_REG      (SRE_SYS_REG_BASEADDR + 0x75C)     /* TRING��λȥ������ƼĴ��� */
#define SRE_SC_RNG_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x760)     /* RNG��λ������ƼĴ��� */
#define SRE_SC_RNG_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x764)     /* RNG��λȥ������ƼĴ��� */
#define SRE_SC_IMA_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x768)     /* IMA��λ������ƼĴ��� */
#define SRE_SC_IMA_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x76C)     /* IMA��λȥ������ƼĴ��� */
#define SRE_SC_SCH_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x770)     /* SCH��λ������ƼĴ��� */
#define SRE_SC_SCH_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x774)     /* SCH��λȥ������ƼĴ��� */
#define SRE_SC_TM_RESET_REQ_REG          (SRE_SYS_REG_BASEADDR + 0x778)     /* TM��λ������ƼĴ��� */
#define SRE_SC_TM_RESET_DREQ_REG         (SRE_SYS_REG_BASEADDR + 0x77c)     /* TM��λȥ������ƼĴ��� */
#define SRE_SC_FUNC_MBIST_MODE_CFG_REG   (SRE_SYS_REG_BASEADDR + 0x800)
#define SRE_SC_FUNC_MBIST_CTRL_CFG_REG   (SRE_SYS_REG_BASEADDR + 0x804)
#define SRE_SC_FUNC_MBIST_MEM_CFG_REG    (SRE_SYS_REG_BASEADDR + 0x808)
#define SRE_SC_FUNC_MBIST_EN0_REG        (SRE_SYS_REG_BASEADDR + 0x810)
#define SRE_SC_FUNC_MBIST_EN1_REG        (SRE_SYS_REG_BASEADDR + 0x814)
#define SRE_SC_TCAM_MBIST_EN_REG         (SRE_SYS_REG_BASEADDR + 0x820)
#define SRE_SC_CPU_CTRL0_REG             (SRE_SYS_REG_BASEADDR + 0x900)
#define SRE_SC_CPU_CTRL1_REG             (SRE_SYS_REG_BASEADDR + 0x904)
#define SRE_SC_CPU_CTRL2_REG             (SRE_SYS_REG_BASEADDR + 0x908)
#define SRE_SC_CPU_CTRL3_REG             (SRE_SYS_REG_BASEADDR + 0x90C)
#define SRE_SC_CPU_CTRL4_REG             (SRE_SYS_REG_BASEADDR + 0x910)
#define SRE_SC_CPU_CTRL5_REG             (SRE_SYS_REG_BASEADDR + 0x914)
#define SRE_SC_CORE0_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x930)     /* ��Core0��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE1_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x934)     /* ��Core1��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE2_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x938)     /* ��Core2��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE3_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x93C)     /* ��Core3��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE4_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x940)     /* ��Core4��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE5_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x944)     /* ��Core5��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE6_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x948)     /* ��Core6��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE7_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x94C)     /* ��Core7��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE8_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x950)     /* ��Core8��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE9_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x954)     /* ��Core9��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE10_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x958)     /* ��Core10��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE11_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x95C)     /* ��Core11��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE12_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x960)     /* ��Core12��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE13_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x964)     /* ��Core13��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE14_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x968)     /* ��Core14��EventԴͷѡ��ʹ�� */
#define SRE_SC_CORE15_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x96C)     /* ��Core15��EventԴͷѡ��ʹ�� */
#define SRE_SC_CACHE_CTRL_REG            (SRE_SYS_REG_BASEADDR + 0x9F0)     /* Cache����ģʽ���� */
#define SRE_SC_GIC_CTRL_REG              (SRE_SYS_REG_BASEADDR + 0xA00)     /* GIC���ƼĴ��� */
#define SRE_SC_CS_CTRL_REG               (SRE_SYS_REG_BASEADDR + 0xA40)
#define SRE_SC_DDR_CTRL0_REG             (SRE_SYS_REG_BASEADDR + 0xA80)
#define SRE_SC_DDR_CTRL1_REG             (SRE_SYS_REG_BASEADDR + 0xA84)
#define SRE_SC_EBI_CTRL_REG              (SRE_SYS_REG_BASEADDR + 0xAC0)
#define SRE_SC_USB_CTRL0_REG             (SRE_SYS_REG_BASEADDR + 0xB80)
#define SRE_SC_USB_CTRL1_REG             (SRE_SYS_REG_BASEADDR + 0xB84)
#define SRE_SC_BOOTROM_CTRL_REG          (SRE_SYS_REG_BASEADDR + 0xC00)
#define SRE_SC_TSENSOR_CTRL_REG          (SRE_SYS_REG_BASEADDR + 0xC10)
#define SRE_SC_TSENSOR_TEST_CTRL_REG     (SRE_SYS_REG_BASEADDR + 0xC18)     /* Tsensor����ʹ�ã��������û���Ҫ�����޸ġ� */
#define SRE_SC_EMMC_CTRL_REG             (SRE_SYS_REG_BASEADDR + 0xC20)
#define SRE_SC_MDIO_CTRL0_REG            (SRE_SYS_REG_BASEADDR + 0xC30)
#define SRE_SC_MDIO_CTRL1_REG            (SRE_SYS_REG_BASEADDR + 0xC34)
#define SRE_SC_SYNC_ETH0_CTRL_REG        (SRE_SYS_REG_BASEADDR + 0xC40)     /* ͬ����̫��ʱ��ѡ����ƼĴ���0 */
#define SRE_SC_SYNC_ETH1_CTRL_REG        (SRE_SYS_REG_BASEADDR + 0xC44)     /* ͬ����̫��ʱ��ѡ�������1 */
#define SRE_SC_MAC_MODE_REG              (SRE_SYS_REG_BASEADDR + 0xC48)     /* ������MAC����ģʽָʾ��ͬ����̫��ʱ�����͹���ģ����ݴ��ź�ȷ��ԭʼʱ�ӵ�����ʱ����Ҫ���еķ�Ƶϵ�� */
#define SRE_SC_MISC_CTRL_REG             (SRE_SYS_REG_BASEADDR + 0xC80)
#define SRE_SC_IO_DRIVE_CTRL0_REG        (SRE_SYS_REG_BASEADDR + 0xC90)     /* ��ͨIO�ܽ������������ÿ���0 */
#define SRE_SC_IO_DRIVE_CTRL1_REG        (SRE_SYS_REG_BASEADDR + 0xC94)     /* ��ͨIO�ܽ������������ÿ���1 */
#define MC_SCITCR_REG                    (SRE_SYS_REG_BASEADDR + 0xF00)
#define MC_SCITIR0_REG                   (SRE_SYS_REG_BASEADDR + 0xF04)
#define MC_SCITIR1_REG                   (SRE_SYS_REG_BASEADDR + 0xF08)
#define MC_SCITOR_REG                    (SRE_SYS_REG_BASEADDR + 0xF0C)
#define MC_SCCNTCTRL_REG                 (SRE_SYS_REG_BASEADDR + 0xF10)
#define MC_SCCNTDATA_REG                 (SRE_SYS_REG_BASEADDR + 0xF14)
#define MC_SCCNTSTEP_REG                 (SRE_SYS_REG_BASEADDR + 0xF18)
#define SRE_SC_TSENSOR_REG               (SRE_SYS_REG_BASEADDR + 0x1080)
#define SRE_SC_BOOT_CFG_REG              (SRE_SYS_REG_BASEADDR + 0x1090)
#define SRE_SC_BOOT_SEL_REG              (SRE_SYS_REG_BASEADDR + 0x1094)
#define SRE_SC_PLL_LOCK_STATUS_REG       (SRE_SYS_REG_BASEADDR + 0x1110)
#define SRE_SC_TOP_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1200)    /* ����CRGʱ��״̬�Ĵ��� */
#define SRE_SC_GE_CLK_ST_REG             (SRE_SYS_REG_BASEADDR + 0x12A0)    /* GEʱ��״̬�Ĵ��� */
#define SRE_SC_XGE_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x12B0)    /* XGEʱ��״̬�Ĵ��� */
#define SRE_SC_PCIE_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x12E0)    /* PCIEʱ��״̬�Ĵ��� */
#define SRE_SC_SRIO_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x12F0)    /* SRIOʱ��״̬�Ĵ��� */
#define SRE_SC_USB_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1300)    /* USBʱ��״̬�Ĵ��� */
#define SRE_SC_SATA_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1310)    /* SATAʱ��״̬�Ĵ��� */
#define SRE_SC_DDR_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1320)    /* DDRʱ��״̬�Ĵ��� */
#define SRE_SC_MMC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1330)    /* MMCʱ��״̬�Ĵ��� */
#define SRE_SC_SFC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1338)    /* SFCʱ��״̬�Ĵ��� */
#define SRE_SC_NANDC_CLK_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1340)    /* NANDCʱ��״̬�Ĵ��� */
#define SRE_SC_LOCALBUS_CLK_ST_REG       (SRE_SYS_REG_BASEADDR + 0x1350)    /* LOCALBUSʱ��״̬�Ĵ��� */
#define SRE_SC_UART_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1380)    /* UARTʱ��״̬�Ĵ��� */
#define SRE_SC_I2C_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1388)    /* I2Cʱ��״̬�Ĵ��� */
#define SRE_SC_MDIO_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1390)    /* MDIOʱ��״̬�Ĵ��� */
#define SRE_SC_SPI_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1398)    /* SPIʱ��״̬�Ĵ��� */
#define SRE_SC_GPIO_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x13A0)    /* GPIOʱ��״̬�Ĵ��� */
#define SRE_SC_TDM_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x13C0)    /* TDMʱ��״̬�Ĵ��� */
#define SRE_SC_HDLC_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x13C8)    /* HDLCʱ��״̬�Ĵ��� */
#define SRE_SC_BOOTROM_CLK_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1400)    /* BOOTROMʱ��״̬�Ĵ��� */
#define SRE_SC_SEC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1408)    /* SECʱ��״̬�Ĵ��� */
#define SRE_SC_POE_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1410)    /* POEʱ��״̬�Ĵ��� */
#define SRE_SC_BMU_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1418)    /* BMUʱ��״̬�Ĵ��� */
#define SRE_SC_PPE_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1420)    /* PPEʱ��״̬�Ĵ��� */
#define SRE_SC_NP_CLK_ST_REG             (SRE_SYS_REG_BASEADDR + 0x1428)    /* SPPEʱ��״̬�Ĵ��� */
#define SRE_SC_CRC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1430)    /* CRCʱ��״̬�Ĵ��� */
#define SRE_SC_DMAC_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1438)    /* DMACʱ��״̬�Ĵ��� */
#define SRE_SC_ROHC_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1440)    /* ROHCʱ��״̬�Ĵ��� */
#define SRE_SC_HDCP_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1448)    /* HDCPʱ��״̬�Ĵ��� */
#define SRE_SC_PDM_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1450)    /* PDMʱ��״̬�Ĵ��� */
#define SRE_SC_TRING_CLK_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1458)    /* TRINGʱ��״̬�Ĵ��� */
#define SRE_SC_RNG_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1460)    /* RNGʱ��״̬�Ĵ��� */
#define SRE_SC_IMA_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1468)    /* IMAʱ��״̬�Ĵ��� */
#define SRE_SC_SCH_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1470)    /* SCHʱ��״̬�Ĵ��� */
#define SRE_SC_TM_CLK_ST_REG             (SRE_SYS_REG_BASEADDR + 0x1478)    /* TMʱ��״̬�Ĵ��� */
#define SRE_SC_TOP_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1500)    /* ����CRG��λ״̬�Ĵ��� */
#define SRE_SC_CPU_RESET_ST0_REG         (SRE_SYS_REG_BASEADDR + 0x1520)    /* Cluster0�ڲ���λ״̬���ƼĴ����� */
#define SRE_SC_CPU_RESET_ST1_REG         (SRE_SYS_REG_BASEADDR + 0x1528)    /* Cluster1�ڲ���λ״̬���ƼĴ����� */
#define SRE_SC_CPU_RESET_ST2_REG         (SRE_SYS_REG_BASEADDR + 0x1530)    /* Cluster2�ڲ���λ״̬���ƼĴ����� */
#define SRE_SC_CPU_RESET_ST3_REG         (SRE_SYS_REG_BASEADDR + 0x1538)    /* Cluster3�ڲ���λ״̬���ƼĴ����� */
#define SRE_SC_CACHE_RESET_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1560)    /* l3cache��λ״̬���ƼĴ��� */
#define SRE_SC_SERDES_RESET_ST0_REG      (SRE_SYS_REG_BASEADDR + 0x1580)    /* Serdes��λ״̬�Ĵ���1 */
#define SRE_SC_SERDES_RESET_ST1_REG      (SRE_SYS_REG_BASEADDR + 0x1588)    /* Serdes��λ״̬�Ĵ���2 */
#define SRE_SC_SERDES_RESET_ST2_REG      (SRE_SYS_REG_BASEADDR + 0x1590)    /* Serdes��λ״̬�Ĵ���3 */
#define SRE_SC_GE_RESET_ST_REG           (SRE_SYS_REG_BASEADDR + 0x15A0)    /* GE��λ״̬�Ĵ��� */
#define SRE_SC_XGE_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x15B0)    /* XGE��λ״̬�Ĵ��� */
#define SRE_SC_MAC_CFG_RESET_ST_REG      (SRE_SYS_REG_BASEADDR + 0x15C0)    /* MAC������λ״̬�Ĵ��� */
#define SRE_SC_MAC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x15C8)    /* MAC��λ״̬�Ĵ��� */
#define SRE_SC_PCIE_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x15E0)    /* PCIE��λ״̬�Ĵ��� */
#define SRE_SC_SRIO_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x15F0)    /* SRIO��λ״̬�Ĵ��� */
#define SRE_SC_USB_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1604)    /* USB��λ״̬�Ĵ��� */
#define SRE_SC_DDR_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1620)    /* DDR��λ״̬���ƼĴ��� */
#define SRE_SC_MMC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1630)    /* MMC��λ״̬�Ĵ��� */
#define SRE_SC_SFC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1638)    /* SFC��λ״̬�Ĵ��� */
#define SRE_SC_NANDC_RESET_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1640)    /* NANDC��λ״̬�Ĵ��� */
#define SRE_SC_LOCALBUS_RESET_ST_REG     (SRE_SYS_REG_BASEADDR + 0x1650)    /* LOCALBUS��λ״̬�Ĵ��� */
#define SRE_SC_UART_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1680)    /* UART��λ״̬�Ĵ��� */
#define SRE_SC_I2C_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1688)    /* I2C��λ״̬�Ĵ��� */
#define SRE_SC_MDIO_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1690)    /* MDIO��λ״̬�Ĵ��� */
#define SRE_SC_SPI_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1698)    /* SPI��λ״̬�Ĵ��� */
#define SRE_SC_GPIO_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x16A0)    /* GPIO��λ״̬�Ĵ��� */
#define SRE_SC_TDM_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x16C0)    /* TDM��λ״̬�Ĵ��� */
#define SRE_SC_HDLC_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x16C8)    /* HDLC��λ״̬�Ĵ��� */
#define SRE_SC_BOOTROM_RESET_ST_REG      (SRE_SYS_REG_BASEADDR + 0x1700)    /* BOOTROM��λ״̬�Ĵ��� */
#define SRE_SC_SEC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1708)    /* SEC��λ״̬�Ĵ��� */
#define SRE_SC_POE_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1710)    /* POE��λ״̬�Ĵ��� */
#define SRE_SC_BMU_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1718)    /* BMU��λ״̬�Ĵ��� */
#define SRE_SC_PPE_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1720)    /* PPE��λ״̬�Ĵ��� */
#define SRE_SC_NP_RESET_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1728)    /* SPPE��λ״̬�Ĵ��� */
#define SRE_SC_CRC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1730)    /* CRC��λ״̬�Ĵ��� */
#define SRE_SC_DMAC_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1738)    /* DMAC��λ״̬�Ĵ��� */
#define SRE_SC_ROHC_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1740)    /* ROHC��λ״̬�Ĵ��� */
#define SRE_SC_HDCP_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1748)    /* HDCP��λ״̬�Ĵ��� */
#define SRE_SC_PDM_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1750)    /* PDM��λ״̬�Ĵ��� */
#define SRE_SC_TRING_RESET_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1758)    /* TRING��λ״̬�Ĵ��� */
#define SRE_SC_RNG_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1760)    /* RNG��λ״̬�Ĵ��� */
#define SRE_SC_IMA_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1768)    /* IMA��λ״̬�Ĵ��� */
#define SRE_SC_SCH_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1770)    /* SCH��λ״̬�Ĵ��� */
#define SRE_SC_TM_RESET_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1778)    /* TM��λ״̬�Ĵ��� */
#define SRE_SC_FUNC_MBIST_DONE0_REG      (SRE_SYS_REG_BASEADDR + 0x1810)
#define SRE_SC_FUNC_MBIST_DONE1_REG      (SRE_SYS_REG_BASEADDR + 0x1814)
#define SRE_SC_FUNC_MBIST_RESULT0_REG    (SRE_SYS_REG_BASEADDR + 0x1820)
#define SRE_SC_FUNC_MBIST_RESULT1_REG    (SRE_SYS_REG_BASEADDR + 0x1824)
#define SRE_SC_CLUSTER0_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1830)    /* Cluster0 MBIST����״̬�ͽ�� */
#define SRE_SC_CLUSTER0_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x1834)    /* Cluster0 L1 MBIST���Խ��״̬ */
#define SRE_SC_CLUSTER1_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1838)    /* Cluster1 MBIST����״̬�ͽ�� */
#define SRE_SC_CLUSTER1_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x183C)    /* Cluster1 L1 MBIST���Խ��״̬ */
#define SRE_SC_CLUSTER2_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1840)    /* Cluster2 MBIST����״̬�ͽ�� */
#define SRE_SC_CLUSTER2_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x1844)    /* Cluster2 L1 MBIST���Խ��״̬ */
#define SRE_SC_CLUSTER3_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1848)    /* Cluster0 MBIST����״̬�ͽ�� */
#define SRE_SC_CLUSTER3_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x184C)    /* Cluster0 L1 MBIST���Խ��״̬ */
#define SRE_SC_TCAM_MBIST_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1860)    /* TCAM MBIST���Խ��״̬ */
#define SRE_SC_SYNC_ETH_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1900)    /* ͬ����̫������״̬ */
#define SRE_SC_DDR_ST_REG                (SRE_SYS_REG_BASEADDR + 0x1A80)
#define SRE_SC_LOGIC_FREEZE_EN_REG       (SRE_SYS_REG_BASEADDR + 0x1E00)    /* ͨ���˼Ĵ����������������߼�����ͬʱ��ȡоƬ״̬�� */
#define SRE_SC_LOGIC_FREEZE_SRC_EN_REG   (SRE_SYS_REG_BASEADDR + 0x1E04)    /* ʱ��ֹͣԴͷѡ�� */
#define SRE_SC_LOGIC_FREEZE_REQ_REG      (SRE_SYS_REG_BASEADDR + 0x1E08)    /* �ڲ��������ֹͣҵ��ͨ·����ʱ�� */
#define SRE_SC_IO_H2X_STAT_REG           (SRE_SYS_REG_BASEADDR + 0x1E40)
#define SRE_SC_ALG_H2X_STAT_REG          (SRE_SYS_REG_BASEADDR + 0x1E44)
#define SRE_SC_NORESET_REC0_REG          (SRE_SYS_REG_BASEADDR + 0x1E80)    /* �޸�λ�Ĵ���0�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC1_REG          (SRE_SYS_REG_BASEADDR + 0x1E84)    /* �޸�λ�Ĵ���1�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC2_REG          (SRE_SYS_REG_BASEADDR + 0x1E88)    /* �޸�λ�Ĵ���2�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC3_REG          (SRE_SYS_REG_BASEADDR + 0x1E8C)    /* �޸�λ�Ĵ���3�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC4_REG          (SRE_SYS_REG_BASEADDR + 0x1E90)    /* �޸�λ�Ĵ���4�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC5_REG          (SRE_SYS_REG_BASEADDR + 0x1E94)    /* �޸�λ�Ĵ���5�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC6_REG          (SRE_SYS_REG_BASEADDR + 0x1E98)    /* �޸�λ�Ĵ���6�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC7_REG          (SRE_SYS_REG_BASEADDR + 0x1E9C)    /* �޸�λ�Ĵ���7�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC8_REG          (SRE_SYS_REG_BASEADDR + 0x1EA0)    /* �޸�λ�Ĵ���8�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC9_REG          (SRE_SYS_REG_BASEADDR + 0x1EA4)    /* �޸�λ�Ĵ���9�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC10_REG         (SRE_SYS_REG_BASEADDR + 0x1EA8)    /* �޸�λ�Ĵ���10�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC11_REG         (SRE_SYS_REG_BASEADDR + 0x1EAC)    /* �޸�λ�Ĵ���11�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC12_REG         (SRE_SYS_REG_BASEADDR + 0x1EB0)    /* �޸�λ�Ĵ���12�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC13_REG         (SRE_SYS_REG_BASEADDR + 0x1EB4)    /* �޸�λ�Ĵ���13�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC14_REG         (SRE_SYS_REG_BASEADDR + 0x1EB8)    /* �޸�λ�Ĵ���14�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SC_NORESET_REC15_REG         (SRE_SYS_REG_BASEADDR + 0x1EBC)    /* �޸�λ�Ĵ���15�����������ڷǵ��縴λʱ��������λǰ��״̬�� */
#define SRE_SYS_SYSID_0_REG                  (SRE_SYS_REG_BASEADDR + 0x1EE0)    /* SYS ID 31~0���� */
#define SRE_SYS_SYSID_1_REG                  (SRE_SYS_REG_BASEADDR + 0x1EE4)    /* SYS ID 63~32���� */
#define SRE_SYS_SYSID_2_REG                  (SRE_SYS_REG_BASEADDR + 0x1EE8)    /* SYS ID 95~64���� */
#define SRE_SYS_SYSID_3_REG                  (SRE_SYS_REG_BASEADDR + 0x1EEC)    /* SYS ID 127~96���� */
#define SRE_SYS_SYSID_4_REG                  (SRE_SYS_REG_BASEADDR + 0x1EF0)    /* SYS ID 159~128���� */
#define SRE_SYS_SYSID_5_REG                  (SRE_SYS_REG_BASEADDR + 0x1EF4)    /* SYS ID 191~160���� */
#define SRE_SYS_SYSID_6_REG                  (SRE_SYS_REG_BASEADDR + 0x1EF8)    /* SYS ID 223~192���� */
#define SRE_SYS_SYSID_7_REG                  (SRE_SYS_REG_BASEADDR + 0x1EFC)    /* SYS ID 255~224���� */
/* END:   Added by h00176630, 2012/6/9 */

/******************************************************************************/
/*                      PhosphorV600 GIC �Ĵ�������                           */
/******************************************************************************/
#define MC_GIC0_REG_BASEADDR     (0x1A000100 + 0x80000000)   /* GIC0�ļĴ�������ַ */
#define MC_GIC1_REG_BASEADDR     (0x1B000100 + 0x80000000)   /* GIC1�ļĴ�������ַ */

/******************************************************************************/
/*                      PhosphorV600 UART0 �Ĵ�������                         */
/******************************************************************************/
#define MC_URAT0_REG_BASEADDR           0xe4007000   /* URAT0�ļĴ�������ַ */
#define MC_UART0_REG_DR_DLL          (MC_URAT0_REG_BASEADDR + 0x00 )  /* GIC0�ļĴ�������ַ */
#define MC_UART0_REG_USR             (MC_URAT0_REG_BASEADDR + 0x7c )  /* GIC0�ļĴ�������ַ */

/* ���Ź���ʱ����IO��ʼ��ַ */
#define MC_WATCHDOG_IO_BASE        (0x600)
#define MC_WATCHDOG_LOAD_GER       (MC_WATCHDOG_IO_BASE + 0x20)
#define MC_WATCHDOG_COUNT_GER      (MC_WATCHDOG_IO_BASE + 0x24)
#define MC_WATCHDOG_CONTRL_GER     (MC_WATCHDOG_IO_BASE + 0x28)
#define MC_WATCHDOG_INT_STAU_GER   (MC_WATCHDOG_IO_BASE + 0x2C)

/******************************************************************************/
/*                                    GPIO�Ĵ���                              */
/******************************************************************************/
#define MC_GPIO0_REG_BASE           (0x2000a000 + 0x80000000)
#define MC_GPIO0_SWPORT_DR_REG      (MC_GPIO0_REG_BASE + 0x00)
#define MC_GPIO0_SWPORT_DDR_REG     (MC_GPIO0_REG_BASE + 0x04)

/******************************************************************************/
/*                                    IO_CONFIG�Ĵ���                              */
/******************************************************************************/
#define MC_IOCONFIG_REG_BASE        (0x2000d000 + 0x80000000)
#define MC_IOMG012_REG              (MC_IOCONFIG_REG_BASE + 0x30)

/* BEGIN: Added by c00111586, 2010/9/24   ���ⵥ��:DTS2010091901574 */
#define MC_PADMG00_REG              (MC_IOCONFIG_REG_BASE + 0x800)
/* END:   Added by c00111586, 2010/9/24 */

/********QMUģ��ʹ�õļĴ�����ַ����************/
#define MC_QMU_REG_BASE            (0x10020000 + 0x80000000)
#define MC_QMU_INT_STATUS_REG      (MC_QMU_REG_BASE + 0x00)
#define MC_QMU_INT_ENA_REG         (MC_QMU_REG_BASE + 0x04)
#define MC_QMU_INT_CLR_REG         (MC_QMU_REG_BASE + 0x08)

#define MC_QMU_CNT_SEL_REG         (MC_QMU_REG_BASE + 0x00E8)
#define MC_QMU_RD_EXPT_RET_REG0    (MC_QMU_REG_BASE + 0x00FC)
#define MC_QMU_RD_EXPT_RET_REG1    (MC_QMU_REG_BASE + 0x0100)
#define MC_QMU_DEBUG_CTR_REG       (MC_QMU_REG_BASE + 0x0104)
#define MC_QMU_DEBUG_STAT_REG      (MC_QMU_REG_BASE + 0x0108)

#define MC_QMU_PQ_BASE_REG         (MC_QMU_REG_BASE + 0x2000)
#define MC_QMU_PQ_CNT_REG          (MC_QMU_REG_BASE + 0x2004)
#define MC_QMU_PQ_RWP_REG          (MC_QMU_REG_BASE + 0x2008)

#define MC_QMU_RQ_BASE_REG         (MC_QMU_REG_BASE + 0x2300)
#define MC_QMU_RQ_CNT_REG          (MC_QMU_REG_BASE + 0x2304)
#define MC_QMU_RQ_RWP_REG          (MC_QMU_REG_BASE + 0x2308)

#define MC_QMU_PQ_CORE0_LDST_REG   (MC_QMU_REG_BASE + 0x4000)
#define MC_QMU_PQ_CORE0_ST_STA_REG (MC_QMU_REG_BASE + 0x6000)

#define MC_QMU_RQ_CORE0_LDST_REG   (MC_QMU_REG_BASE + 0x8000)
#define MC_QMU_RQ_CORE0_ST_STA_REG (MC_QMU_REG_BASE + 0x9000)


/********HDCP ģ��ʹ�õļĴ�����ַ����************/
#define MC_HDCP_REG_BASE            (0x100e0000 + 0x80000000)
#define SRE_HDCP_ENABLE_REG         (MC_HDCP_REG_BASE + 0x0000)
#define HDCP_BMU_CFG_ADDR          (MC_HDCP_REG_BASE + 0x0004)
#define HDCP_POE_CFG_ADDR          (MC_HDCP_REG_BASE + 0x0008)          /**POE ADD �Ĵ���**/
#define HDCP_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x000c)
#define HDCP_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0010)

#define HDCP_INT_MASK_REG          (MC_HDCP_REG_BASE + 0x0014)
#define HDCP_INT_STATUS_REG        (MC_HDCP_REG_BASE + 0x0018)
#define HDCP_RAWINT_STATUS_REG     (MC_HDCP_REG_BASE + 0x001C)
#define HDCP_INT_CLR_REG           (MC_HDCP_REG_BASE + 0x0020)

#define HDCP_MEMREQ_FAIL_REG       (MC_HDCP_REG_BASE + 0x0024)
#define HDCP_BMURLS_FAIL_REG       (MC_HDCP_REG_BASE + 0x0028)
#define HDCP_ADDPOE_FAIL_REG       (MC_HDCP_REG_BASE + 0x002C)
#define HDCP_DATA_FAIL_REG         (MC_HDCP_REG_BASE + 0x0030)

#define HDCP_TRANS_CNT_REG         (MC_HDCP_REG_BASE + 0x0034)
#define HDCP_DATA_TIMECNT_REG      (MC_HDCP_REG_BASE + 0x0038)
#define HDCP_MEMRES_CMPL_CNT_REG   (MC_HDCP_REG_BASE + 0x003C)
#define HDCP_MEMREQ_CMPL_CNT_REG   (MC_HDCP_REG_BASE + 0x0040)
#define HDCP_ADDPOE_CMPL_CNT_REG   (MC_HDCP_REG_BASE + 0x0044)


#define HDCP_CH0_ENABLE_REG        (MC_HDCP_REG_BASE + 0x0100)
#define HDCP_CH0_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0104)
#define HDCP_CH0_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0108)
#define HDCP_CH0_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x010C)
#define HDCP_CH0_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0110)
#define HDCP_CH0_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0114)
#define HDCP_CH0_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0118)

#define HDCP_CH1_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0120)
#define HDCP_CH1_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0124)
#define HDCP_CH1_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0128)
#define HDCP_CH1_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x012C)
#define HDCP_CH1_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0130)
#define HDCP_CH1_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0134)
#define HDCP_CH1_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0138)

#define HDCP_CH2_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0140)
#define HDCP_CH2_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0144)
#define HDCP_CH2_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0148)
#define HDCP_CH2_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x014C)
#define HDCP_CH2_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0150)
#define HDCP_CH2_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0154)
#define HDCP_CH2_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0158)

#define HDCP_CH3_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0160)
#define HDCP_CH3_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0164)
#define HDCP_CH3_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0168)
#define HDCP_CH3_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x016C)
#define HDCP_CH3_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0170)
#define HDCP_CH3_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0174)
#define HDCP_CH3_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0178)

#define HDCP_CH4_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0180)
#define HDCP_CH4_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0184)
#define HDCP_CH4_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0188)
#define HDCP_CH4_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x018C)
#define HDCP_CH4_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0190)
#define HDCP_CH4_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0194)
#define HDCP_CH4_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0198)

#define HDCP_CH5_ENABLE_REG            (MC_HDCP_REG_BASE + 0x01A0)
#define HDCP_CH5_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x01A4)
#define HDCP_CH5_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x01A8)
#define HDCP_CH5_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x01AC)
#define HDCP_CH5_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x01B0)
#define HDCP_CH5_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x01B4)
#define HDCP_CH5_DEBUG_REG             (MC_HDCP_REG_BASE + 0x01B8)

#define HDCP_CH6_ENABLE_REG            (MC_HDCP_REG_BASE + 0x01C0)
#define HDCP_CH6_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x01C4)
#define HDCP_CH6_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x01C8)
#define HDCP_CH6_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x01CC)
#define HDCP_CH6_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x01D0)
#define HDCP_CH6_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x01D4)
#define HDCP_CH6_DEBUG_REG             (MC_HDCP_REG_BASE + 0x01D8)

#define HDCP_CH7_ENABLE_REG            (MC_HDCP_REG_BASE + 0x01E0)
#define HDCP_CH7_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x01E4)
#define HDCP_CH7_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x01E8)
#define HDCP_CH7_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x01EC)
#define HDCP_CH7_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x01F0)
#define HDCP_CH7_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x01F4)
#define HDCP_CH7_DEBUG_REG             (MC_HDCP_REG_BASE + 0x01F8)

/******************************************************************************/
/*                                    ����TIMER�Ĵ���                         */
/******************************************************************************/
#define MC_GLOBAL_TIMER_BASE      (0x20009000UL + 0x80000000UL)
#define MC_GLOBAL_TIMER0_LOAD     (MC_GLOBAL_TIMER_BASE + 0x00)
#define MC_GLOBAL_TIMER0_VALUE    (MC_GLOBAL_TIMER_BASE + 0x04)
#define MC_GLOBAL_TIMER0_CONTRL   (MC_GLOBAL_TIMER_BASE + 0x08)
#define MC_GLOBAL_TIMER0_INCLR    (MC_GLOBAL_TIMER_BASE + 0x0C)
#define MC_GLOBAL_TIMER0_RIS      (MC_GLOBAL_TIMER_BASE + 0x10)
#define MC_GLOBAL_TIMER0_MIS      (MC_GLOBAL_TIMER_BASE + 0x14)
#define MC_GLOBAL_TIMER0_BGLOAD   (MC_GLOBAL_TIMER_BASE + 0x18)
#define MC_GLOBAL_TIMER1_LOAD     (MC_GLOBAL_TIMER_BASE + 0x20)
#define MC_GLOBAL_TIMER1_VALUE    (MC_GLOBAL_TIMER_BASE + 0x24)
#define MC_GLOBAL_TIMER1_CONTRL   (MC_GLOBAL_TIMER_BASE + 0x28)
#define MC_GLOBAL_TIMER1_INCLR    (MC_GLOBAL_TIMER_BASE + 0x2C)
#define MC_GLOBAL_TIMER1_RIS      (MC_GLOBAL_TIMER_BASE + 0x30)
#define MC_GLOBAL_TIMER1_MIS      (MC_GLOBAL_TIMER_BASE + 0x34)
#define MC_GLOBAL_TIMER1_BGLOAD   (MC_GLOBAL_TIMER_BASE + 0x38)

/* GIC ģ��Ĵ�������ַ */
#if 0
#define SRE_GIC_BASE                               (0x10c00000)
#else
#define SRE_GIC_BASE                               (0xe0c00000)
#endif
/******************************************************************************/
/*                      PhosphorV650 GIC �Ĵ�������                           */
/******************************************************************************/
#define OS_GIC_GICD_CTLR_REG                      (SRE_GIC_BASE + 0x1000)          /* Distributor��ʹ�ܿ��� */
#define OS_GIC_GICD_TYPER_REG                     (SRE_GIC_BASE + 0x1004)          /* GIC��������Ϣ�������Ƿ�ʹ�ð�ȫ��չ�����������SPI�������֧�ֵ��ж�������Ϣ */
#define OS_GIC_GICD_IIDR_REG                      (SRE_GIC_BASE + 0x1008)          /* GIC��ݼĴ��� */
#define OS_GIC_GICD_IGROUPR0_REG                  (SRE_GIC_BASE + 0x1080)          /* ��ʶ�жϷ�����Group0��Group1 */
#define OS_GIC_GICD_ISENABLER0_REG                (SRE_GIC_BASE + 0x1100)          /* �����жϵ�ʹ�ܼĴ����������Ƿ񷢸�Cpu Interface�� */
#define OS_GIC_GICD_ICENABLER0_REG                (SRE_GIC_BASE + 0x1180)          /* �����жϵ����ʹ�ܵļĴ�����ȷ���Ƿ񷢸�CPU Interface��n��ֵ��GICD_TYPER.ITLinesNumber����,n=0 */
#define OS_GIC_GICD_ISPENDR0_REG                  (SRE_GIC_BASE + 0x1200)          /* �����ж�����pending״̬�Ŀ����źżĴ����� */
#define OS_GIC_GICD_ICPENDR0_REG                  (SRE_GIC_BASE + 0x1280)          /* �����ж����pending״̬�Ŀ����źżĴ����� */
#define OS_GIC_GICD_ISACTIVER0_REG                (SRE_GIC_BASE + 0x1300)          /* �����ж�����active״̬�Ŀ����źżĴ����� */
#define OS_GIC_GICD_ICACTIVER0_REG                (SRE_GIC_BASE + 0x1380)          /* �����ж����active״̬�Ŀ����źżĴ�������Щ�Ĵ�������Ҫ����ͻظ�GIC��״̬ʱʹ�á� */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_0_REG       (SRE_GIC_BASE + 0x1400)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_1_REG       (SRE_GIC_BASE + 0x1404)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_2_REG       (SRE_GIC_BASE + 0x1408)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_3_REG       (SRE_GIC_BASE + 0x140C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define OS_GIC_GICD_IPRIORITYR0TO3_S_0_REG        (SRE_GIC_BASE + 0x1400)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_S_1_REG        (SRE_GIC_BASE + 0x1404)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_S_2_REG        (SRE_GIC_BASE + 0x1408)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_S_3_REG        (SRE_GIC_BASE + 0x140C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR6_NS_REG            (SRE_GIC_BASE + 0x1418)          /* ÿ8bit��Ӧһ���жϵ����ȼ��� */
#define SRE_GIC_GICD_IPRIORITYR6_S_REG             (SRE_GIC_BASE + 0x1418)          /* ÿ8bit��Ӧһ���жϵ����ȼ��� */
#define SRE_GIC_GICD_IPRIORITYR7_NS_REG            (SRE_GIC_BASE + 0x141C)          /* ÿ8bit��Ӧһ���жϵ����ȼ��� */
#define SRE_GIC_GICD_IPRIORITYR7_S_REG             (SRE_GIC_BASE + 0x141C)          /* ÿ8bit��Ӧһ���жϵ����ȼ��� */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_0_REG     (SRE_GIC_BASE + 0x1420)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_1_REG     (SRE_GIC_BASE + 0x1424)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_2_REG     (SRE_GIC_BASE + 0x1428)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_3_REG     (SRE_GIC_BASE + 0x142C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_4_REG     (SRE_GIC_BASE + 0x1430)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_5_REG     (SRE_GIC_BASE + 0x1434)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_6_REG     (SRE_GIC_BASE + 0x1438)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_7_REG     (SRE_GIC_BASE + 0x143C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_8_REG     (SRE_GIC_BASE + 0x1440)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_9_REG     (SRE_GIC_BASE + 0x1444)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_10_REG    (SRE_GIC_BASE + 0x1448)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_11_REG    (SRE_GIC_BASE + 0x144C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_12_REG    (SRE_GIC_BASE + 0x1450)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_13_REG    (SRE_GIC_BASE + 0x1454)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_14_REG    (SRE_GIC_BASE + 0x1458)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_15_REG    (SRE_GIC_BASE + 0x145C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_16_REG    (SRE_GIC_BASE + 0x1460)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_17_REG    (SRE_GIC_BASE + 0x1464)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_18_REG    (SRE_GIC_BASE + 0x1468)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_19_REG    (SRE_GIC_BASE + 0x146C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_20_REG    (SRE_GIC_BASE + 0x1470)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_21_REG    (SRE_GIC_BASE + 0x1474)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_22_REG    (SRE_GIC_BASE + 0x1478)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_23_REG    (SRE_GIC_BASE + 0x147C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_24_REG    (SRE_GIC_BASE + 0x1480)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_25_REG    (SRE_GIC_BASE + 0x1484)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_26_REG    (SRE_GIC_BASE + 0x1488)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_27_REG    (SRE_GIC_BASE + 0x148C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_28_REG    (SRE_GIC_BASE + 0x1490)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_29_REG    (SRE_GIC_BASE + 0x1494)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_30_REG    (SRE_GIC_BASE + 0x1498)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_31_REG    (SRE_GIC_BASE + 0x149C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_32_REG    (SRE_GIC_BASE + 0x14A0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_33_REG    (SRE_GIC_BASE + 0x14A4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_34_REG    (SRE_GIC_BASE + 0x14A8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_35_REG    (SRE_GIC_BASE + 0x14AC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_36_REG    (SRE_GIC_BASE + 0x14B0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_37_REG    (SRE_GIC_BASE + 0x14B4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_38_REG    (SRE_GIC_BASE + 0x14B8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_39_REG    (SRE_GIC_BASE + 0x14BC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_40_REG    (SRE_GIC_BASE + 0x14C0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_41_REG    (SRE_GIC_BASE + 0x14C4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_42_REG    (SRE_GIC_BASE + 0x14C8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_43_REG    (SRE_GIC_BASE + 0x14CC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_44_REG    (SRE_GIC_BASE + 0x14D0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_45_REG    (SRE_GIC_BASE + 0x14D4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_46_REG    (SRE_GIC_BASE + 0x14D8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_47_REG    (SRE_GIC_BASE + 0x14DC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_48_REG    (SRE_GIC_BASE + 0x14E0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_49_REG    (SRE_GIC_BASE + 0x14E4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_50_REG    (SRE_GIC_BASE + 0x14E8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_51_REG    (SRE_GIC_BASE + 0x14EC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_52_REG    (SRE_GIC_BASE + 0x14F0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_53_REG    (SRE_GIC_BASE + 0x14F4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_54_REG    (SRE_GIC_BASE + 0x14F8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_55_REG    (SRE_GIC_BASE + 0x14FC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_56_REG    (SRE_GIC_BASE + 0x1500)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_57_REG    (SRE_GIC_BASE + 0x1504)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_58_REG    (SRE_GIC_BASE + 0x1508)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_59_REG    (SRE_GIC_BASE + 0x150C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_60_REG    (SRE_GIC_BASE + 0x1510)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_61_REG    (SRE_GIC_BASE + 0x1514)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_62_REG    (SRE_GIC_BASE + 0x1518)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_63_REG    (SRE_GIC_BASE + 0x151C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_64_REG    (SRE_GIC_BASE + 0x1520)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_65_REG    (SRE_GIC_BASE + 0x1524)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_66_REG    (SRE_GIC_BASE + 0x1528)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_67_REG    (SRE_GIC_BASE + 0x152C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_68_REG    (SRE_GIC_BASE + 0x1530)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_69_REG    (SRE_GIC_BASE + 0x1534)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_70_REG    (SRE_GIC_BASE + 0x1538)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_71_REG    (SRE_GIC_BASE + 0x153C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_72_REG    (SRE_GIC_BASE + 0x1540)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_73_REG    (SRE_GIC_BASE + 0x1544)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_74_REG    (SRE_GIC_BASE + 0x1548)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_75_REG    (SRE_GIC_BASE + 0x154C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_76_REG    (SRE_GIC_BASE + 0x1550)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_77_REG    (SRE_GIC_BASE + 0x1554)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_78_REG    (SRE_GIC_BASE + 0x1558)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_79_REG    (SRE_GIC_BASE + 0x155C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_80_REG    (SRE_GIC_BASE + 0x1560)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_81_REG    (SRE_GIC_BASE + 0x1564)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_82_REG    (SRE_GIC_BASE + 0x1568)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_83_REG    (SRE_GIC_BASE + 0x156C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_84_REG    (SRE_GIC_BASE + 0x1570)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_85_REG    (SRE_GIC_BASE + 0x1574)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_86_REG    (SRE_GIC_BASE + 0x1578)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_87_REG    (SRE_GIC_BASE + 0x157C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_88_REG    (SRE_GIC_BASE + 0x1580)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_89_REG    (SRE_GIC_BASE + 0x1584)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_90_REG    (SRE_GIC_BASE + 0x1588)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_91_REG    (SRE_GIC_BASE + 0x158C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_92_REG    (SRE_GIC_BASE + 0x1590)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_93_REG    (SRE_GIC_BASE + 0x1594)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_94_REG    (SRE_GIC_BASE + 0x1598)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_95_REG    (SRE_GIC_BASE + 0x159C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_96_REG    (SRE_GIC_BASE + 0x15A0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_97_REG    (SRE_GIC_BASE + 0x15A4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_98_REG    (SRE_GIC_BASE + 0x15A8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_99_REG    (SRE_GIC_BASE + 0x15AC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_100_REG   (SRE_GIC_BASE + 0x15B0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_101_REG   (SRE_GIC_BASE + 0x15B4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_102_REG   (SRE_GIC_BASE + 0x15B8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_103_REG   (SRE_GIC_BASE + 0x15BC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_104_REG   (SRE_GIC_BASE + 0x15C0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_105_REG   (SRE_GIC_BASE + 0x15C4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_106_REG   (SRE_GIC_BASE + 0x15C8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_107_REG   (SRE_GIC_BASE + 0x15CC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_108_REG   (SRE_GIC_BASE + 0x15D0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_109_REG   (SRE_GIC_BASE + 0x15D4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_110_REG   (SRE_GIC_BASE + 0x15D8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_111_REG   (SRE_GIC_BASE + 0x15DC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_0_REG      (SRE_GIC_BASE + 0x1420)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_1_REG      (SRE_GIC_BASE + 0x1424)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_2_REG      (SRE_GIC_BASE + 0x1428)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_3_REG      (SRE_GIC_BASE + 0x142C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_4_REG      (SRE_GIC_BASE + 0x1430)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_5_REG      (SRE_GIC_BASE + 0x1434)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_6_REG      (SRE_GIC_BASE + 0x1438)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_7_REG      (SRE_GIC_BASE + 0x143C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_8_REG      (SRE_GIC_BASE + 0x1440)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_9_REG      (SRE_GIC_BASE + 0x1444)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_10_REG     (SRE_GIC_BASE + 0x1448)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_11_REG     (SRE_GIC_BASE + 0x144C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_12_REG     (SRE_GIC_BASE + 0x1450)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_13_REG     (SRE_GIC_BASE + 0x1454)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_14_REG     (SRE_GIC_BASE + 0x1458)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_15_REG     (SRE_GIC_BASE + 0x145C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_16_REG     (SRE_GIC_BASE + 0x1460)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_17_REG     (SRE_GIC_BASE + 0x1464)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_18_REG     (SRE_GIC_BASE + 0x1468)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_19_REG     (SRE_GIC_BASE + 0x146C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_20_REG     (SRE_GIC_BASE + 0x1470)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_21_REG     (SRE_GIC_BASE + 0x1474)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_22_REG     (SRE_GIC_BASE + 0x1478)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_23_REG     (SRE_GIC_BASE + 0x147C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_24_REG     (SRE_GIC_BASE + 0x1480)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_25_REG     (SRE_GIC_BASE + 0x1484)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_26_REG     (SRE_GIC_BASE + 0x1488)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_27_REG     (SRE_GIC_BASE + 0x148C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_28_REG     (SRE_GIC_BASE + 0x1490)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_29_REG     (SRE_GIC_BASE + 0x1494)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_30_REG     (SRE_GIC_BASE + 0x1498)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_31_REG     (SRE_GIC_BASE + 0x149C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_32_REG     (SRE_GIC_BASE + 0x14A0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_33_REG     (SRE_GIC_BASE + 0x14A4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_34_REG     (SRE_GIC_BASE + 0x14A8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_35_REG     (SRE_GIC_BASE + 0x14AC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_36_REG     (SRE_GIC_BASE + 0x14B0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_37_REG     (SRE_GIC_BASE + 0x14B4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_38_REG     (SRE_GIC_BASE + 0x14B8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_39_REG     (SRE_GIC_BASE + 0x14BC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_40_REG     (SRE_GIC_BASE + 0x14C0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_41_REG     (SRE_GIC_BASE + 0x14C4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_42_REG     (SRE_GIC_BASE + 0x14C8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_43_REG     (SRE_GIC_BASE + 0x14CC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_44_REG     (SRE_GIC_BASE + 0x14D0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_45_REG     (SRE_GIC_BASE + 0x14D4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_46_REG     (SRE_GIC_BASE + 0x14D8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_47_REG     (SRE_GIC_BASE + 0x14DC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_48_REG     (SRE_GIC_BASE + 0x14E0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_49_REG     (SRE_GIC_BASE + 0x14E4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_50_REG     (SRE_GIC_BASE + 0x14E8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_51_REG     (SRE_GIC_BASE + 0x14EC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_52_REG     (SRE_GIC_BASE + 0x14F0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_53_REG     (SRE_GIC_BASE + 0x14F4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_54_REG     (SRE_GIC_BASE + 0x14F8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_55_REG     (SRE_GIC_BASE + 0x14FC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_56_REG     (SRE_GIC_BASE + 0x1500)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_57_REG     (SRE_GIC_BASE + 0x1504)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_58_REG     (SRE_GIC_BASE + 0x1508)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_59_REG     (SRE_GIC_BASE + 0x150C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_60_REG     (SRE_GIC_BASE + 0x1510)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_61_REG     (SRE_GIC_BASE + 0x1514)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_62_REG     (SRE_GIC_BASE + 0x1518)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_63_REG     (SRE_GIC_BASE + 0x151C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_64_REG     (SRE_GIC_BASE + 0x1520)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_65_REG     (SRE_GIC_BASE + 0x1524)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_66_REG     (SRE_GIC_BASE + 0x1528)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_67_REG     (SRE_GIC_BASE + 0x152C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_68_REG     (SRE_GIC_BASE + 0x1530)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_69_REG     (SRE_GIC_BASE + 0x1534)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_70_REG     (SRE_GIC_BASE + 0x1538)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_71_REG     (SRE_GIC_BASE + 0x153C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_72_REG     (SRE_GIC_BASE + 0x1540)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_73_REG     (SRE_GIC_BASE + 0x1544)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_74_REG     (SRE_GIC_BASE + 0x1548)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_75_REG     (SRE_GIC_BASE + 0x154C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_76_REG     (SRE_GIC_BASE + 0x1550)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_77_REG     (SRE_GIC_BASE + 0x1554)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_78_REG     (SRE_GIC_BASE + 0x1558)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_79_REG     (SRE_GIC_BASE + 0x155C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_80_REG     (SRE_GIC_BASE + 0x1560)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_81_REG     (SRE_GIC_BASE + 0x1564)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_82_REG     (SRE_GIC_BASE + 0x1568)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_83_REG     (SRE_GIC_BASE + 0x156C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_84_REG     (SRE_GIC_BASE + 0x1570)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_85_REG     (SRE_GIC_BASE + 0x1574)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_86_REG     (SRE_GIC_BASE + 0x1578)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_87_REG     (SRE_GIC_BASE + 0x157C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_88_REG     (SRE_GIC_BASE + 0x1580)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_89_REG     (SRE_GIC_BASE + 0x1584)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_90_REG     (SRE_GIC_BASE + 0x1588)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_91_REG     (SRE_GIC_BASE + 0x158C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_92_REG     (SRE_GIC_BASE + 0x1590)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_93_REG     (SRE_GIC_BASE + 0x1594)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_94_REG     (SRE_GIC_BASE + 0x1598)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_95_REG     (SRE_GIC_BASE + 0x159C)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_96_REG     (SRE_GIC_BASE + 0x15A0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_97_REG     (SRE_GIC_BASE + 0x15A4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_98_REG     (SRE_GIC_BASE + 0x15A8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_99_REG     (SRE_GIC_BASE + 0x15AC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_100_REG    (SRE_GIC_BASE + 0x15B0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_101_REG    (SRE_GIC_BASE + 0x15B4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_102_REG    (SRE_GIC_BASE + 0x15B8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_103_REG    (SRE_GIC_BASE + 0x15BC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_104_REG    (SRE_GIC_BASE + 0x15C0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_105_REG    (SRE_GIC_BASE + 0x15C4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_106_REG    (SRE_GIC_BASE + 0x15C8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_107_REG    (SRE_GIC_BASE + 0x15CC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_108_REG    (SRE_GIC_BASE + 0x15D0)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_109_REG    (SRE_GIC_BASE + 0x15D4)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_110_REG    (SRE_GIC_BASE + 0x15D8)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_111_REG    (SRE_GIC_BASE + 0x15DC)          /* ÿ8bit��Ӧһ���жϵ����ȼ���n{0,111} */
#define OS_GIC_GICD_ITARGETSRZ_0_REG              (SRE_GIC_BASE + 0x1800)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_1_REG              (SRE_GIC_BASE + 0x1804)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_2_REG              (SRE_GIC_BASE + 0x1808)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_3_REG              (SRE_GIC_BASE + 0x180C)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_4_REG              (SRE_GIC_BASE + 0x1810)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_5_REG              (SRE_GIC_BASE + 0x1814)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_6_REG              (SRE_GIC_BASE + 0x1818)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSRZ_7_REG              (SRE_GIC_BASE + 0x181C)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���z��ΧΪ0��7������Ӧ���ж���SGIs��z{0,7}�� */
#define SRE_GIC_GICD_ITARGETSR12_REG               (SRE_GIC_BASE + 0x1830)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���� */
#define SRE_GIC_GICD_ITARGETSRH_0_REG              (SRE_GIC_BASE + 0x1834)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���h��ΧΪ13��15������Ӧ���ж���PPIs��h{0,2} */
#define SRE_GIC_GICD_ITARGETSRH_1_REG              (SRE_GIC_BASE + 0x1838)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���h��ΧΪ13��15������Ӧ���ж���PPIs��h{0,2} */
#define SRE_GIC_GICD_ITARGETSRH_2_REG              (SRE_GIC_BASE + 0x183C)          /* ÿ16bit��Ӧһ���жϵ�������Ӧ��CPU Interface���˴���h��ΧΪ13��15������Ӧ���ж���PPIs��h{0,2} */
#define SRE_GIC_GICD_ITARGETSRY_0_REG              (SRE_GIC_BASE + 0x1840)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_1_REG              (SRE_GIC_BASE + 0x1844)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_2_REG              (SRE_GIC_BASE + 0x1848)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_3_REG              (SRE_GIC_BASE + 0x184C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_4_REG              (SRE_GIC_BASE + 0x1850)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_5_REG              (SRE_GIC_BASE + 0x1854)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_6_REG              (SRE_GIC_BASE + 0x1858)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_7_REG              (SRE_GIC_BASE + 0x185C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_8_REG              (SRE_GIC_BASE + 0x1860)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_9_REG              (SRE_GIC_BASE + 0x1864)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_10_REG             (SRE_GIC_BASE + 0x1868)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_11_REG             (SRE_GIC_BASE + 0x186C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_12_REG             (SRE_GIC_BASE + 0x1870)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_13_REG             (SRE_GIC_BASE + 0x1874)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_14_REG             (SRE_GIC_BASE + 0x1878)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_15_REG             (SRE_GIC_BASE + 0x187C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_16_REG             (SRE_GIC_BASE + 0x1880)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_17_REG             (SRE_GIC_BASE + 0x1884)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_18_REG             (SRE_GIC_BASE + 0x1888)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_19_REG             (SRE_GIC_BASE + 0x188C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_20_REG             (SRE_GIC_BASE + 0x1890)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_21_REG             (SRE_GIC_BASE + 0x1894)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_22_REG             (SRE_GIC_BASE + 0x1898)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_23_REG             (SRE_GIC_BASE + 0x189C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_24_REG             (SRE_GIC_BASE + 0x18A0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_25_REG             (SRE_GIC_BASE + 0x18A4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_26_REG             (SRE_GIC_BASE + 0x18A8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_27_REG             (SRE_GIC_BASE + 0x18AC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_28_REG             (SRE_GIC_BASE + 0x18B0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_29_REG             (SRE_GIC_BASE + 0x18B4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_30_REG             (SRE_GIC_BASE + 0x18B8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_31_REG             (SRE_GIC_BASE + 0x18BC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_32_REG             (SRE_GIC_BASE + 0x18C0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_33_REG             (SRE_GIC_BASE + 0x18C4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_34_REG             (SRE_GIC_BASE + 0x18C8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_35_REG             (SRE_GIC_BASE + 0x18CC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_36_REG             (SRE_GIC_BASE + 0x18D0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_37_REG             (SRE_GIC_BASE + 0x18D4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_38_REG             (SRE_GIC_BASE + 0x18D8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_39_REG             (SRE_GIC_BASE + 0x18DC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_40_REG             (SRE_GIC_BASE + 0x18E0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_41_REG             (SRE_GIC_BASE + 0x18E4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_42_REG             (SRE_GIC_BASE + 0x18E8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_43_REG             (SRE_GIC_BASE + 0x18EC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_44_REG             (SRE_GIC_BASE + 0x18F0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_45_REG             (SRE_GIC_BASE + 0x18F4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_46_REG             (SRE_GIC_BASE + 0x18F8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_47_REG             (SRE_GIC_BASE + 0x18FC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_48_REG             (SRE_GIC_BASE + 0x1900)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_49_REG             (SRE_GIC_BASE + 0x1904)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_50_REG             (SRE_GIC_BASE + 0x1908)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_51_REG             (SRE_GIC_BASE + 0x190C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_52_REG             (SRE_GIC_BASE + 0x1910)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_53_REG             (SRE_GIC_BASE + 0x1914)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_54_REG             (SRE_GIC_BASE + 0x1918)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_55_REG             (SRE_GIC_BASE + 0x191C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_56_REG             (SRE_GIC_BASE + 0x1920)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_57_REG             (SRE_GIC_BASE + 0x1924)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_58_REG             (SRE_GIC_BASE + 0x1928)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_59_REG             (SRE_GIC_BASE + 0x192C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_60_REG             (SRE_GIC_BASE + 0x1930)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_61_REG             (SRE_GIC_BASE + 0x1934)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_62_REG             (SRE_GIC_BASE + 0x1938)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_63_REG             (SRE_GIC_BASE + 0x193C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_64_REG             (SRE_GIC_BASE + 0x1940)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_65_REG             (SRE_GIC_BASE + 0x1944)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_66_REG             (SRE_GIC_BASE + 0x1948)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_67_REG             (SRE_GIC_BASE + 0x194C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_68_REG             (SRE_GIC_BASE + 0x1950)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_69_REG             (SRE_GIC_BASE + 0x1954)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_70_REG             (SRE_GIC_BASE + 0x1958)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_71_REG             (SRE_GIC_BASE + 0x195C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_72_REG             (SRE_GIC_BASE + 0x1960)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_73_REG             (SRE_GIC_BASE + 0x1964)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_74_REG             (SRE_GIC_BASE + 0x1968)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_75_REG             (SRE_GIC_BASE + 0x196C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_76_REG             (SRE_GIC_BASE + 0x1970)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_77_REG             (SRE_GIC_BASE + 0x1974)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_78_REG             (SRE_GIC_BASE + 0x1978)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_79_REG             (SRE_GIC_BASE + 0x197C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_80_REG             (SRE_GIC_BASE + 0x1980)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_81_REG             (SRE_GIC_BASE + 0x1984)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_82_REG             (SRE_GIC_BASE + 0x1988)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_83_REG             (SRE_GIC_BASE + 0x198C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_84_REG             (SRE_GIC_BASE + 0x1990)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_85_REG             (SRE_GIC_BASE + 0x1994)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_86_REG             (SRE_GIC_BASE + 0x1998)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_87_REG             (SRE_GIC_BASE + 0x199C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_88_REG             (SRE_GIC_BASE + 0x19A0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_89_REG             (SRE_GIC_BASE + 0x19A4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_90_REG             (SRE_GIC_BASE + 0x19A8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_91_REG             (SRE_GIC_BASE + 0x19AC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_92_REG             (SRE_GIC_BASE + 0x19B0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_93_REG             (SRE_GIC_BASE + 0x19B4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_94_REG             (SRE_GIC_BASE + 0x19B8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_95_REG             (SRE_GIC_BASE + 0x19BC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_96_REG             (SRE_GIC_BASE + 0x19C0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_97_REG             (SRE_GIC_BASE + 0x19C4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_98_REG             (SRE_GIC_BASE + 0x19C8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_99_REG             (SRE_GIC_BASE + 0x19CC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_100_REG            (SRE_GIC_BASE + 0x19D0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_101_REG            (SRE_GIC_BASE + 0x19D4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_102_REG            (SRE_GIC_BASE + 0x19D8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_103_REG            (SRE_GIC_BASE + 0x19DC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_104_REG            (SRE_GIC_BASE + 0x19E0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_105_REG            (SRE_GIC_BASE + 0x19E4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_106_REG            (SRE_GIC_BASE + 0x19E8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_107_REG            (SRE_GIC_BASE + 0x19EC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_108_REG            (SRE_GIC_BASE + 0x19F0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_109_REG            (SRE_GIC_BASE + 0x19F4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_110_REG            (SRE_GIC_BASE + 0x19F8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_111_REG            (SRE_GIC_BASE + 0x19FC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_112_REG            (SRE_GIC_BASE + 0x1A00)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_113_REG            (SRE_GIC_BASE + 0x1A04)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_114_REG            (SRE_GIC_BASE + 0x1A08)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_115_REG            (SRE_GIC_BASE + 0x1A0C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_116_REG            (SRE_GIC_BASE + 0x1A10)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_117_REG            (SRE_GIC_BASE + 0x1A14)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_118_REG            (SRE_GIC_BASE + 0x1A18)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_119_REG            (SRE_GIC_BASE + 0x1A1C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_120_REG            (SRE_GIC_BASE + 0x1A20)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_121_REG            (SRE_GIC_BASE + 0x1A24)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_122_REG            (SRE_GIC_BASE + 0x1A28)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_123_REG            (SRE_GIC_BASE + 0x1A2C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_124_REG            (SRE_GIC_BASE + 0x1A30)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_125_REG            (SRE_GIC_BASE + 0x1A34)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_126_REG            (SRE_GIC_BASE + 0x1A38)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_127_REG            (SRE_GIC_BASE + 0x1A3C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_128_REG            (SRE_GIC_BASE + 0x1A40)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_129_REG            (SRE_GIC_BASE + 0x1A44)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_130_REG            (SRE_GIC_BASE + 0x1A48)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_131_REG            (SRE_GIC_BASE + 0x1A4C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_132_REG            (SRE_GIC_BASE + 0x1A50)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_133_REG            (SRE_GIC_BASE + 0x1A54)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_134_REG            (SRE_GIC_BASE + 0x1A58)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_135_REG            (SRE_GIC_BASE + 0x1A5C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_136_REG            (SRE_GIC_BASE + 0x1A60)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_137_REG            (SRE_GIC_BASE + 0x1A64)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_138_REG            (SRE_GIC_BASE + 0x1A68)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_139_REG            (SRE_GIC_BASE + 0x1A6C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_140_REG            (SRE_GIC_BASE + 0x1A70)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_141_REG            (SRE_GIC_BASE + 0x1A74)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_142_REG            (SRE_GIC_BASE + 0x1A78)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_143_REG            (SRE_GIC_BASE + 0x1A7C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_144_REG            (SRE_GIC_BASE + 0x1A80)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_145_REG            (SRE_GIC_BASE + 0x1A84)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_146_REG            (SRE_GIC_BASE + 0x1A88)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_147_REG            (SRE_GIC_BASE + 0x1A8C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_148_REG            (SRE_GIC_BASE + 0x1A90)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_149_REG            (SRE_GIC_BASE + 0x1A94)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_150_REG            (SRE_GIC_BASE + 0x1A98)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_151_REG            (SRE_GIC_BASE + 0x1A9C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_152_REG            (SRE_GIC_BASE + 0x1AA0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_153_REG            (SRE_GIC_BASE + 0x1AA4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_154_REG            (SRE_GIC_BASE + 0x1AA8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_155_REG            (SRE_GIC_BASE + 0x1AAC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_156_REG            (SRE_GIC_BASE + 0x1AB0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_157_REG            (SRE_GIC_BASE + 0x1AB4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_158_REG            (SRE_GIC_BASE + 0x1AB8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_159_REG            (SRE_GIC_BASE + 0x1ABC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_160_REG            (SRE_GIC_BASE + 0x1AC0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_161_REG            (SRE_GIC_BASE + 0x1AC4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_162_REG            (SRE_GIC_BASE + 0x1AC8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_163_REG            (SRE_GIC_BASE + 0x1ACC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_164_REG            (SRE_GIC_BASE + 0x1AD0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_165_REG            (SRE_GIC_BASE + 0x1AD4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_166_REG            (SRE_GIC_BASE + 0x1AD8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_167_REG            (SRE_GIC_BASE + 0x1ADC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_168_REG            (SRE_GIC_BASE + 0x1AE0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_169_REG            (SRE_GIC_BASE + 0x1AE4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_170_REG            (SRE_GIC_BASE + 0x1AE8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_171_REG            (SRE_GIC_BASE + 0x1AEC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_172_REG            (SRE_GIC_BASE + 0x1AF0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_173_REG            (SRE_GIC_BASE + 0x1AF4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_174_REG            (SRE_GIC_BASE + 0x1AF8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_175_REG            (SRE_GIC_BASE + 0x1AFC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_176_REG            (SRE_GIC_BASE + 0x1B00)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_177_REG            (SRE_GIC_BASE + 0x1B04)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_178_REG            (SRE_GIC_BASE + 0x1B08)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_179_REG            (SRE_GIC_BASE + 0x1B0C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_180_REG            (SRE_GIC_BASE + 0x1B10)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_181_REG            (SRE_GIC_BASE + 0x1B14)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_182_REG            (SRE_GIC_BASE + 0x1B18)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_183_REG            (SRE_GIC_BASE + 0x1B1C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_184_REG            (SRE_GIC_BASE + 0x1B20)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_185_REG            (SRE_GIC_BASE + 0x1B24)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_186_REG            (SRE_GIC_BASE + 0x1B28)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_187_REG            (SRE_GIC_BASE + 0x1B2C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_188_REG            (SRE_GIC_BASE + 0x1B30)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_189_REG            (SRE_GIC_BASE + 0x1B34)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_190_REG            (SRE_GIC_BASE + 0x1B38)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_191_REG            (SRE_GIC_BASE + 0x1B3C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_192_REG            (SRE_GIC_BASE + 0x1B40)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_193_REG            (SRE_GIC_BASE + 0x1B44)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_194_REG            (SRE_GIC_BASE + 0x1B48)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_195_REG            (SRE_GIC_BASE + 0x1B4C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_196_REG            (SRE_GIC_BASE + 0x1B50)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_197_REG            (SRE_GIC_BASE + 0x1B54)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_198_REG            (SRE_GIC_BASE + 0x1B58)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_199_REG            (SRE_GIC_BASE + 0x1B5C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_200_REG            (SRE_GIC_BASE + 0x1B60)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_201_REG            (SRE_GIC_BASE + 0x1B64)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_202_REG            (SRE_GIC_BASE + 0x1B68)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_203_REG            (SRE_GIC_BASE + 0x1B6C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_204_REG            (SRE_GIC_BASE + 0x1B70)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_205_REG            (SRE_GIC_BASE + 0x1B74)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_206_REG            (SRE_GIC_BASE + 0x1B78)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_207_REG            (SRE_GIC_BASE + 0x1B7C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_208_REG            (SRE_GIC_BASE + 0x1B80)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_209_REG            (SRE_GIC_BASE + 0x1B84)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_210_REG            (SRE_GIC_BASE + 0x1B88)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_211_REG            (SRE_GIC_BASE + 0x1B8C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_212_REG            (SRE_GIC_BASE + 0x1B90)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_213_REG            (SRE_GIC_BASE + 0x1B94)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_214_REG            (SRE_GIC_BASE + 0x1B98)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_215_REG            (SRE_GIC_BASE + 0x1B9C)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_216_REG            (SRE_GIC_BASE + 0x1BA0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_217_REG            (SRE_GIC_BASE + 0x1BA4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_218_REG            (SRE_GIC_BASE + 0x1BA8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_219_REG            (SRE_GIC_BASE + 0x1BAC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_220_REG            (SRE_GIC_BASE + 0x1BB0)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_221_REG            (SRE_GIC_BASE + 0x1BB4)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_222_REG            (SRE_GIC_BASE + 0x1BB8)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ITARGETSRY_223_REG            (SRE_GIC_BASE + 0x1BBC)          /* �üĴ���ÿ16bit��ʾһ���жϵ�������Ӧ��CPU Interface���˴���y>15������Ӧ���ж���SPIs��y�ķ�Χ��y{0��223} */
#define SRE_GIC_GICD_ICFGR0_REG                    (SRE_GIC_BASE + 0x1C00)          /* �üĴ���ÿ2bit��ʾһ��SGI�ж��ǵ�ƽ���л��Ǳ��ش��� */
#define SRE_GIC_GICD_ICFGR1_REG                    (SRE_GIC_BASE + 0x1C04)          /* �üĴ���ÿ2bit��ʾһ��PPI�ж��ǵ�ƽ���л��Ǳ��ش��� */
#define SRE_GIC_GICD_ICFGR_0_REG                   (SRE_GIC_BASE + 0x1C08)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_1_REG                   (SRE_GIC_BASE + 0x1C0C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_2_REG                   (SRE_GIC_BASE + 0x1C10)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_3_REG                   (SRE_GIC_BASE + 0x1C14)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_4_REG                   (SRE_GIC_BASE + 0x1C18)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_5_REG                   (SRE_GIC_BASE + 0x1C1C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_6_REG                   (SRE_GIC_BASE + 0x1C20)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_7_REG                   (SRE_GIC_BASE + 0x1C24)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_8_REG                   (SRE_GIC_BASE + 0x1C28)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_9_REG                   (SRE_GIC_BASE + 0x1C2C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_10_REG                  (SRE_GIC_BASE + 0x1C30)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_11_REG                  (SRE_GIC_BASE + 0x1C34)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_12_REG                  (SRE_GIC_BASE + 0x1C38)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_13_REG                  (SRE_GIC_BASE + 0x1C3C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_14_REG                  (SRE_GIC_BASE + 0x1C40)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_15_REG                  (SRE_GIC_BASE + 0x1C44)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_16_REG                  (SRE_GIC_BASE + 0x1C48)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_17_REG                  (SRE_GIC_BASE + 0x1C4C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_18_REG                  (SRE_GIC_BASE + 0x1C50)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_19_REG                  (SRE_GIC_BASE + 0x1C54)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_20_REG                  (SRE_GIC_BASE + 0x1C58)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_21_REG                  (SRE_GIC_BASE + 0x1C5C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_22_REG                  (SRE_GIC_BASE + 0x1C60)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_23_REG                  (SRE_GIC_BASE + 0x1C64)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_24_REG                  (SRE_GIC_BASE + 0x1C68)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_25_REG                  (SRE_GIC_BASE + 0x1C6C)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_26_REG                  (SRE_GIC_BASE + 0x1C70)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_ICFGR_27_REG                  (SRE_GIC_BASE + 0x1C74)          /* �üĴ���ÿ2bit��ʾһ��SPI�ж��ǵ�ƽ���л��Ǳ��ش�����e�����ֵΪ2*GICD_TYPER.ITLinesNumber��e{0,27} */
#define SRE_GIC_GICD_PPISR_REG                     (SRE_GIC_BASE + 0x1D00)          /* PPI�ж�������Distributor��״̬ */
#define SRE_GIC_GICD_SPISR_0_REG                   (SRE_GIC_BASE + 0x1D04)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_1_REG                   (SRE_GIC_BASE + 0x1D08)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_2_REG                   (SRE_GIC_BASE + 0x1D0C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_3_REG                   (SRE_GIC_BASE + 0x1D10)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_4_REG                   (SRE_GIC_BASE + 0x1D14)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_5_REG                   (SRE_GIC_BASE + 0x1D18)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_6_REG                   (SRE_GIC_BASE + 0x1D1C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_7_REG                   (SRE_GIC_BASE + 0x1D20)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_8_REG                   (SRE_GIC_BASE + 0x1D24)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_9_REG                   (SRE_GIC_BASE + 0x1D28)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_10_REG                  (SRE_GIC_BASE + 0x1D2C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_11_REG                  (SRE_GIC_BASE + 0x1D30)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_12_REG                  (SRE_GIC_BASE + 0x1D34)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_13_REG                  (SRE_GIC_BASE + 0x1D38)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_14_REG                  (SRE_GIC_BASE + 0x1D3C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_15_REG                  (SRE_GIC_BASE + 0x1D40)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_16_REG                  (SRE_GIC_BASE + 0x1D44)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_17_REG                  (SRE_GIC_BASE + 0x1D48)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_18_REG                  (SRE_GIC_BASE + 0x1D4C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_19_REG                  (SRE_GIC_BASE + 0x1D50)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_20_REG                  (SRE_GIC_BASE + 0x1D54)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_21_REG                  (SRE_GIC_BASE + 0x1D58)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_22_REG                  (SRE_GIC_BASE + 0x1D5C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_23_REG                  (SRE_GIC_BASE + 0x1D60)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_24_REG                  (SRE_GIC_BASE + 0x1D64)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_25_REG                  (SRE_GIC_BASE + 0x1D68)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_26_REG                  (SRE_GIC_BASE + 0x1D6C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_27_REG                  (SRE_GIC_BASE + 0x1D70)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_28_REG                  (SRE_GIC_BASE + 0x1D74)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_29_REG                  (SRE_GIC_BASE + 0x1D78)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_30_REG                  (SRE_GIC_BASE + 0x1D7C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_31_REG                  (SRE_GIC_BASE + 0x1D80)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_32_REG                  (SRE_GIC_BASE + 0x1D84)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_33_REG                  (SRE_GIC_BASE + 0x1D88)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_34_REG                  (SRE_GIC_BASE + 0x1D8C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_35_REG                  (SRE_GIC_BASE + 0x1D90)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_36_REG                  (SRE_GIC_BASE + 0x1D94)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_37_REG                  (SRE_GIC_BASE + 0x1D98)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_38_REG                  (SRE_GIC_BASE + 0x1D9C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_39_REG                  (SRE_GIC_BASE + 0x1DA0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_40_REG                  (SRE_GIC_BASE + 0x1DA4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_41_REG                  (SRE_GIC_BASE + 0x1DA8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_42_REG                  (SRE_GIC_BASE + 0x1DAC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_43_REG                  (SRE_GIC_BASE + 0x1DB0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_44_REG                  (SRE_GIC_BASE + 0x1DB4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_45_REG                  (SRE_GIC_BASE + 0x1DB8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_46_REG                  (SRE_GIC_BASE + 0x1DBC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_47_REG                  (SRE_GIC_BASE + 0x1DC0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_48_REG                  (SRE_GIC_BASE + 0x1DC4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_49_REG                  (SRE_GIC_BASE + 0x1DC8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_50_REG                  (SRE_GIC_BASE + 0x1DCC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_51_REG                  (SRE_GIC_BASE + 0x1DD0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_52_REG                  (SRE_GIC_BASE + 0x1DD4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_53_REG                  (SRE_GIC_BASE + 0x1DD8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_54_REG                  (SRE_GIC_BASE + 0x1DDC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_55_REG                  (SRE_GIC_BASE + 0x1DE0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_56_REG                  (SRE_GIC_BASE + 0x1DE4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_57_REG                  (SRE_GIC_BASE + 0x1DE8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_58_REG                  (SRE_GIC_BASE + 0x1DEC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_59_REG                  (SRE_GIC_BASE + 0x1DF0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_60_REG                  (SRE_GIC_BASE + 0x1DF4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_61_REG                  (SRE_GIC_BASE + 0x1DF8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_62_REG                  (SRE_GIC_BASE + 0x1DFC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_63_REG                  (SRE_GIC_BASE + 0x1E00)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_64_REG                  (SRE_GIC_BASE + 0x1E04)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_65_REG                  (SRE_GIC_BASE + 0x1E08)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_66_REG                  (SRE_GIC_BASE + 0x1E0C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_67_REG                  (SRE_GIC_BASE + 0x1E10)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_68_REG                  (SRE_GIC_BASE + 0x1E14)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_69_REG                  (SRE_GIC_BASE + 0x1E18)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_70_REG                  (SRE_GIC_BASE + 0x1E1C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_71_REG                  (SRE_GIC_BASE + 0x1E20)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_72_REG                  (SRE_GIC_BASE + 0x1E24)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_73_REG                  (SRE_GIC_BASE + 0x1E28)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_74_REG                  (SRE_GIC_BASE + 0x1E2C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_75_REG                  (SRE_GIC_BASE + 0x1E30)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_76_REG                  (SRE_GIC_BASE + 0x1E34)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_77_REG                  (SRE_GIC_BASE + 0x1E38)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_78_REG                  (SRE_GIC_BASE + 0x1E3C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_79_REG                  (SRE_GIC_BASE + 0x1E40)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_80_REG                  (SRE_GIC_BASE + 0x1E44)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_81_REG                  (SRE_GIC_BASE + 0x1E48)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_82_REG                  (SRE_GIC_BASE + 0x1E4C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_83_REG                  (SRE_GIC_BASE + 0x1E50)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_84_REG                  (SRE_GIC_BASE + 0x1E54)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_85_REG                  (SRE_GIC_BASE + 0x1E58)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_86_REG                  (SRE_GIC_BASE + 0x1E5C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_87_REG                  (SRE_GIC_BASE + 0x1E60)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_88_REG                  (SRE_GIC_BASE + 0x1E64)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_89_REG                  (SRE_GIC_BASE + 0x1E68)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_90_REG                  (SRE_GIC_BASE + 0x1E6C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_91_REG                  (SRE_GIC_BASE + 0x1E70)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_92_REG                  (SRE_GIC_BASE + 0x1E74)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_93_REG                  (SRE_GIC_BASE + 0x1E78)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_94_REG                  (SRE_GIC_BASE + 0x1E7C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_95_REG                  (SRE_GIC_BASE + 0x1E80)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_96_REG                  (SRE_GIC_BASE + 0x1E84)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_97_REG                  (SRE_GIC_BASE + 0x1E88)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_98_REG                  (SRE_GIC_BASE + 0x1E8C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_99_REG                  (SRE_GIC_BASE + 0x1E90)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_100_REG                 (SRE_GIC_BASE + 0x1E94)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_101_REG                 (SRE_GIC_BASE + 0x1E98)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_102_REG                 (SRE_GIC_BASE + 0x1E9C)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_103_REG                 (SRE_GIC_BASE + 0x1EA0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_104_REG                 (SRE_GIC_BASE + 0x1EA4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_105_REG                 (SRE_GIC_BASE + 0x1EA8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_106_REG                 (SRE_GIC_BASE + 0x1EAC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_107_REG                 (SRE_GIC_BASE + 0x1EB0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_108_REG                 (SRE_GIC_BASE + 0x1EB4)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_109_REG                 (SRE_GIC_BASE + 0x1EB8)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_110_REG                 (SRE_GIC_BASE + 0x1EBC)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define SRE_GIC_GICD_SPISR_111_REG                 (SRE_GIC_BASE + 0x1EC0)          /* SPI�ж�����IRQS��GIC��״̬��n��ֵ��ʵ�ʵ��ⲿ�ж���Ŀ������n{0,14} */
#define OS_GIC_GICD_SGIR_REG                      (SRE_GIC_BASE + 0x1F00)          /* ����SGI�Ĳ��� */
#define SRE_GIC_GICD_CPENDSGIR_0_REG               (SRE_GIC_BASE + 0x1F40)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_1_REG               (SRE_GIC_BASE + 0x1F44)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_2_REG               (SRE_GIC_BASE + 0x1F48)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_3_REG               (SRE_GIC_BASE + 0x1F4C)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_4_REG               (SRE_GIC_BASE + 0x1F50)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_5_REG               (SRE_GIC_BASE + 0x1F54)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_6_REG               (SRE_GIC_BASE + 0x1F58)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_7_REG               (SRE_GIC_BASE + 0x1F5C)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface���pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_0_REG               (SRE_GIC_BASE + 0x1F80)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_1_REG               (SRE_GIC_BASE + 0x1F84)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_2_REG               (SRE_GIC_BASE + 0x1F88)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_3_REG               (SRE_GIC_BASE + 0x1F8C)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_4_REG               (SRE_GIC_BASE + 0x1F90)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_5_REG               (SRE_GIC_BASE + 0x1F94)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_6_REG               (SRE_GIC_BASE + 0x1F98)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_7_REG               (SRE_GIC_BASE + 0x1F9C)          /* ÿ16bit��ʾ����SGI�ж϶�Ӧ��16��CPU Interface����pending״̬��f{0,7} */
#define SRE_GIC_GICD_PIDR4_REG                     (SRE_GIC_BASE + 0x1FD0)          /* Peripheral ID4���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR5_REG                     (SRE_GIC_BASE + 0x1FD4)          /* Peripheral ID5���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR6_REG                     (SRE_GIC_BASE + 0x1FD8)          /* Peripheral ID6���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR7_REG                     (SRE_GIC_BASE + 0x1FDC)          /* Peripheral ID7���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR0_REG                     (SRE_GIC_BASE + 0x1FE0)          /* Peripheral ID0���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR1_REG                     (SRE_GIC_BASE + 0x1FE4)          /* Peripheral ID1���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR2_REG                     (SRE_GIC_BASE + 0x1FE8)          /* Peripheral ID2���ʶ��Ĵ��� */
#define SRE_GIC_GICD_PIDR3_REG                     (SRE_GIC_BASE + 0x1FEC)          /* Peripheral ID3���ʶ��Ĵ��� */
#define SRE_GIC_GICD_CIDR0_REG                     (SRE_GIC_BASE + 0x1FF0)          /* Component ID0�Ĵ��� */
#define SRE_GIC_GICD_CIDR1_REG                     (SRE_GIC_BASE + 0x1FF4)          /* Component ID1�Ĵ��� */
#define SRE_GIC_GICD_CIDR2_REG                     (SRE_GIC_BASE + 0x1FF8)          /* Component ID2�Ĵ��� */
#define SRE_GIC_GICD_CIDR3_REG                     (SRE_GIC_BASE + 0x1FFC)          /* Component ID3�Ĵ��� */
#define SRE_GIC_GICC_CTLR_NS_REG                   (SRE_GIC_BASE + 0x2000)          /* CPU Interfaceʹ���Լ�������ƼĴ��������ر�ע�⣺GICC_CTLR��banked���˼Ĵ�������secure access�µı��ݡ�����non_secure �ı��ݵ�λ���䲻һ������ */
#define OS_GIC_GICC_CTLR_S_REG                    (SRE_GIC_BASE + 0x2000)          /* CPU Interfaceʹ���Լ�������ƼĴ��������ر�ע�⣺�˼Ĵ�������non_secure access�µı��ݡ�����secure �ı��ݵ�λ���䲻һ������ */
#define OS_GIC_GICC_PMR_S_REG                     (SRE_GIC_BASE + 0x2004)          /* �ж����ȼ����μĴ��� */
#define SRE_GIC_GICC_PMR_NS_REG                    (SRE_GIC_BASE + 0x2004)          /* �ж����ȼ����μĴ��� */
#define SRE_GIC_GICC_BPR_NS_REG                    (SRE_GIC_BASE + 0x2008)          /* Group ���ȼ����üĴ��� */
#define OS_GIC_GICC_BPR_S_REG                     (SRE_GIC_BASE + 0x2008)          /* Group ���ȼ����üĴ��� */
#define OS_GIC_GICC_IAR_REG                       (SRE_GIC_BASE + 0x200C)          /* �ж�ȷ�ϼĴ��� */
#define OS_GIC_GICC_EOIR_REG                      (SRE_GIC_BASE + 0x2010)          /* �жϽ����Ĵ��� */
#define SRE_GIC_GICC_RPR_REG                       (SRE_GIC_BASE + 0x2014)          /* ָʾrunning priority�ļĴ��� */
#define SRE_GIC_GICC_HPPIR_REG                     (SRE_GIC_BASE + 0x2018)          /* ����������ȼ�pending״̬���жϼĴ��� */
#define OS_GIC_GICC_ABPR_REG                      (SRE_GIC_BASE + 0x201C)          /* Group���ȼ����üĴ��� */
#define OS_GIC_GICC_AIAR_REG                      (SRE_GIC_BASE + 0x2020)          /* Group1�ж�ȷ�ϼĴ��� */
#define SRE_GIC_GICC_AEOIR_REG                     (SRE_GIC_BASE + 0x2024)          /* Group1�жϽ����Ĵ��� */
#define SRE_GIC_GICC_AHPPIR_REG                    (SRE_GIC_BASE + 0x2028)          /* ����������ȼ�pending״̬��Group1�жϼĴ��� */
#define SRE_GIC_GICC_APR0_REG                      (SRE_GIC_BASE + 0x20D0)          /* active״̬�İ�ȫ�ж����ȼ��Ĵ��� */
#define SRE_GIC_GICC_NSAPR0_REG                    (SRE_GIC_BASE + 0x20E0)          /* active״̬�ķǰ�ȫ�ж����ȼ��Ĵ��� */
#define SRE_GIC_GICC_IIDR_REG                      (SRE_GIC_BASE + 0x20FC)          /* CPU interface��ݼĴ��� */
#define SRE_GIC_GICC_DIR_REG                       (SRE_GIC_BASE + 0x3000)          /* deactive�жϼĴ��� */
#define SRE_GIC_GICH_HCR_REG                       (SRE_GIC_BASE + 0x4000)          /* Hypervisor���ƼĴ��� */
#define SRE_GIC_GICH_VTR_REG                       (SRE_GIC_BASE + 0x4004)          /* ��¼GIC���⻯��չ�Ĳ����Ĵ��� */
#define SRE_GIC_GICH_VMCR_REG                      (SRE_GIC_BASE + 0x4008)          /* VM���ƼĴ�������VM�л�ʱ��ʹ��hypervisor�����ͻָ�GIC��״̬�� */
#define SRE_GIC_GICH_MISR_REG                      (SRE_GIC_BASE + 0x4010)          /* Maintenance�ж�״̬�Ĵ�������ʶ����maintenance interrupt����Ч�� */
#define SRE_GIC_GICH_EISR0_REG                     (SRE_GIC_BASE + 0x4020)          /* List register0��31 EOI״̬�Ĵ��� */
#define SRE_GIC_GICH_ELSR0_REG                     (SRE_GIC_BASE + 0x4030)          /* List register0��31 ��״̬�Ĵ��� */
#define SRE_GIC_GICH_APR0_REG                      (SRE_GIC_BASE + 0x4070)          /* active ���ȼ��Ĵ�������n=0�� */
#define SRE_GIC_GICH_LR_0_REG                      (SRE_GIC_BASE + 0x4080)          /* List register��һ��List register��¼һ���жϵ���Ϣ��n��ֵ��GICH_VTR.ListRegs���塣g{0,3} */
#define SRE_GIC_GICH_LR_1_REG                      (SRE_GIC_BASE + 0x4084)          /* List register��һ��List register��¼һ���жϵ���Ϣ��n��ֵ��GICH_VTR.ListRegs���塣g{0,3} */
#define SRE_GIC_GICH_LR_2_REG                      (SRE_GIC_BASE + 0x4088)          /* List register��һ��List register��¼һ���жϵ���Ϣ��n��ֵ��GICH_VTR.ListRegs���塣g{0,3} */
#define SRE_GIC_GICH_LR_3_REG                      (SRE_GIC_BASE + 0x408C)          /* List register��һ��List register��¼һ���жϵ���Ϣ��n��ֵ��GICH_VTR.ListRegs���塣g{0,3} */
#define SRE_GIC_GICV_CTLR_REG                      (SRE_GIC_BASE + 0x6000)          /* Virtual CPU Interfaceʹ���Լ�������ƼĴ��� */
#define SRE_GIC_GICV_PMR_REG                       (SRE_GIC_BASE + 0x6004)          /* �����ж����ȼ����μĴ��� */
#define SRE_GIC_GICV_BPR_REG                       (SRE_GIC_BASE + 0x6008)          /* �����ж�Group���ȼ����üĴ��� */
#define SRE_GIC_GICV_IAR_REG                       (SRE_GIC_BASE + 0x600C)          /* �����ж�ȷ�ϼĴ��� */
#define SRE_GIC_GICV_EOIR_REG                      (SRE_GIC_BASE + 0x6010)          /* �����жϽ����Ĵ��� */
#define SRE_GIC_GICV_RPR_REG                       (SRE_GIC_BASE + 0x6014)          /* ָʾVM��running priority�ļĴ��� */
#define SRE_GIC_GICV_HPPIR_REG                     (SRE_GIC_BASE + 0x6018)          /* ����������ȼ�pending״̬�������жϼĴ��� */
#define SRE_GIC_GICV_ABPR_REG                      (SRE_GIC_BASE + 0x601C)          /* �����ж�Group���ȼ����üĴ��� */
#define SRE_GIC_GICV_AIAR_REG                      (SRE_GIC_BASE + 0x6020)          /* �����ж�ȷ�ϼĴ��� */
#define SRE_GIC_GICV_AEOIR_REG                     (SRE_GIC_BASE + 0x6024)          /* �����жϽ����Ĵ��� */
#define SRE_GIC_GICV_AHPPIR_REG                    (SRE_GIC_BASE + 0x6028)          /* ����������ȼ�pending״̬�������жϼĴ��� */
#define SRE_GIC_GICV_APR0_REG                      (SRE_GIC_BASE + 0x60D0)          /* active״̬��group0�����ж����ȼ��Ĵ�����(n=0) */
#define SRE_GIC_GICV_IIDR_REG                      (SRE_GIC_BASE + 0x60FC)          /* Virtual CPU Interface��ݼĴ��� */
#define SRE_GIC_GICV_DIR_REG                       (SRE_GIC_BASE + 0x7000)          /* deactive�����жϼĴ��� */

/* TMR ģ��Ĵ�������ַ */
#define MC_TMR_BASE                               (0xe3000000)

/******************************************************************************/
/*                      MC TMR �Ĵ�������                                     */
/******************************************************************************/
#define MC_TMR_TIMER0_LOAD_REG                    (MC_TMR_BASE + 0x0)             /* TIMER0_LOADΪTimer0������ֵ�Ĵ����� */
#define MC_TMR_TIMER0_VALUE_REG                   (MC_TMR_BASE + 0x4)             /* TIMER0_VALUEΪTimer0��ǰ����ֵ�Ĵ����� */
#define MC_TMR_TIMER0_CONTROL_REG                 (MC_TMR_BASE + 0x8)             /* TIMER0_CONTROLΪTimer0���ƼĴ����� */
#define MC_TMR_TIMER0_INTCLR_REG                  (MC_TMR_BASE + 0xC)             /* TIMER0_INTCLRΪTimer0�ж�����Ĵ����� */
#define MC_TMR_TIMER0_RIS_REG                     (MC_TMR_BASE + 0x10)            /* TIMER0_RISΪTimer0�ж�״̬�Ĵ����� */
#define MC_TMR_TIMER0_MIS_REG                     (MC_TMR_BASE + 0x14)            /* TIMER0_MISΪTimer0���κ��ж�״̬�Ĵ����� */
#define MC_TMR_TIMER0_BGLOAD_REG                  (MC_TMR_BASE + 0x18)            /* TIMER0_BGLOADΪTimer0ѭ��ģʽ������ֵ�Ĵ����� */
#define MC_TMR_TIMER1_LOAD_REG                    (MC_TMR_BASE + 0x20)            /* TIMER1_LOADΪTimer1������ֵ�Ĵ����� */
#define MC_TMR_TIMER1_VALUE_REG                   (MC_TMR_BASE + 0x24)            /* TIMER1_VALUEΪTimer1��ǰ����ֵ�Ĵ����� */
#define MC_TMR_TIMER1_CONTROL_REG                 (MC_TMR_BASE + 0x28)            /* TIMER1_CONTROLΪTimer1���ƼĴ����� */
#define MC_TMR_TIMER1_INTCLR_REG                  (MC_TMR_BASE + 0x2C)            /* TIMER1_INTCLRΪTimer1�ж�����Ĵ����� */
#define MC_TMR_TIMER1_RIS_REG                     (MC_TMR_BASE + 0x30)            /* TIMER1_RISΪTimer1�ж�״̬�Ĵ����� */
#define MC_TMR_TIMER1_MIS_REG                     (MC_TMR_BASE + 0x34)            /* TIMER1_MISΪTimer1���κ��ж�״̬�Ĵ����� */
#define MC_TMR_TIMER1_BGLOAD_REG                  (MC_TMR_BASE + 0x38)            /* TIMER1_BGLOADΪTimer1ѭ��ģʽ������ֵ�Ĵ����� */


/*64λ��ʱ��*/
#define MC_TIMER64_0_LOAD_L                       (MC_TMR_BASE + 0x10000)
#define MC_TIMER64_0_LOAD_H                       (MC_TMR_BASE + 0x10000 + 0x4)
#define MC_Timer64_0_VALUE_L                      (MC_TMR_BASE + 0x10000 + 0x8)
#define MC_Timer64_0_VALUE_H                      (MC_TMR_BASE + 0x10000 + 0xC)
#define MC_Timer64_0_CONTROL                      (MC_TMR_BASE + 0x10000 + 0x10)
#define MC_Timer64_0_INTCLR                       (MC_TMR_BASE + 0x10000 + 0x14)
#define MC_Timer64_0_RIS                          (MC_TMR_BASE + 0x10000 + 0x18)
#define MC_Timer64_0_MIS                          (MC_TMR_BASE + 0x10000 + 0x1C)
#define MC_Timer64_0_BGLOAD_L                     (MC_TMR_BASE + 0x10000 + 0x20)
#define MC_Timer64_0_BGLOAD_H                     (MC_TMR_BASE + 0x10000 + 0x24)


#define MC_TIMER64_1_LOAD_L                       (MC_TMR_BASE + 0x10000 + 0x40)
#define MC_TIMER64_1_LOAD_H                       (MC_TMR_BASE + 0x10000 + 0x44)
#define MC_Timer64_1_VALUE_L                      (MC_TMR_BASE + 0x10000 + 0x48)
#define MC_Timer64_1_VALUE_H                      (MC_TMR_BASE + 0x10000 + 0x4C)
#define MC_Timer64_1_CONTROL                      (MC_TMR_BASE + 0x10000 + 0x50)
#define MC_Timer64_1_INTCLR                       (MC_TMR_BASE + 0x10000 + 0x54)
#define MC_Timer64_1_RIS                          (MC_TMR_BASE + 0x10000 + 0x58)
#define MC_Timer64_1_MIS                          (MC_TMR_BASE + 0x10000 + 0x5C)
#define MC_Timer64_1_BGLOAD_L                     (MC_TMR_BASE + 0x10000 + 0x60)
#define MC_Timer64_1_BGLOAD_H                     (MC_TMR_BASE + 0x10000 + 0x64)


/* RNG ģ��Ĵ�������ַ */
#define SRE_RNG_BASE                               (0xe40a0000UL)

/******************************************************************************/
/*                      MC RNG �Ĵ�������                                     */
/******************************************************************************/
#define SRE_RNG_SEED_REG                       (SRE_RNG_BASE + 0x0)             /* PRBS_SEEDΪ����ֵ�����������ĳ�ʼ״ֵ̬ */
#define SRE_RNG_CTRL_REG                       (SRE_RNG_BASE + 0x4)             /* PRBS_CTRLΪPRBS����״̬���ƼĴ����� */
#define SRE_RNG_RAN_NUM_REG                    (SRE_RNG_BASE + 0x10)            /* LFSR�������������ֵ */
#define SRE_RNG_PHY_SEED_REG                   (SRE_RNG_BASE + 0x14)            /* �ڲ����������𵴻������������ */
#define SRE_RNG_RELOAD_ERR_REG                 (SRE_RNG_BASE + 0x84)


/* DLHDCP ģ��Ĵ�������ַ */
#if 0         /* z00202052 */
#define SRE_DLHDCP_BASE                              (0x140b0000UL)
#else
#define SRE_DLHDCP_BASE                              (0xe40b0000UL)
#endif        /* z00202052 */

/******************************************************************************/
/*                      MC DLHDCP_CFG �Ĵ�������                              */
/******************************************************************************/
#define SRE_DLHDCP_CFG_CTRL_REG         (SRE_DLHDCP_BASE + 0x0)      /* DLHDCP���ƼĴ��� */
#define SRE_DLHDCP_CFG_BMU_POOL_ID_REG  (SRE_DLHDCP_BASE + 0x4)      /* BMU POOL IDѡ��Ĵ��� */
#define SRE_DLHDCP_CFG_CACHEABLE_REG    (SRE_DLHDCP_BASE + 0x8)      /* Allocate���üĴ��� */
#define SRE_DLHDCP_CFG_BMU_REQ_ADDR_REG  (SRE_DLHDCP_BASE + 0xC)      /* ����BMU�ĵ�ַ */
#define SRE_DLHDCP_STS_REG              (SRE_DLHDCP_BASE + 0x10)     /* DLHDCPģ��״̬�Ĵ��� */
#define SRE_DLHDCP_M0_BUS_WR_CNT_REG    (SRE_DLHDCP_BASE + 0x14)     /* MASTER0����д�������ͳ�ƼĴ��� */
#define SRE_DLHDCP_M1_BUS_WR_TRANS_CNT_REG  (SRE_DLHDCP_BASE + 0x18)     /* MASTER1����д�������ͳ�ƼĴ��� */
#define SRE_DLHDCP_M0_BUS_RD_TRANS_CNT_REG  (SRE_DLHDCP_BASE + 0x1C)     /* MASTER0���߶��������ͳ�ƼĴ��� */
#define SRE_DLHDCP_M1_BUS_RD_TRANS_CNT_REG  (SRE_DLHDCP_BASE + 0x20)     /* MASTER1���߶��������ͳ�ƼĴ��� */
#define SRE_DLHDCP_POE_GET_CNT_REG      (SRE_DLHDCP_BASE + 0x24)     /* POE GET�����ܴ����Ĵ��� */
#define SRE_DLHDCP_POE_ADD_CNT_REG      (SRE_DLHDCP_BASE + 0x28)     /* POE ADD�����ܴ����Ĵ��� */
#define SRE_DLHDCP_POE_FAIL_CNT_REG     (SRE_DLHDCP_BASE + 0x2C)     /* POE GET��ADD����ʧ�ܴ����Ĵ��� */
#define SRE_DLHDCP_BMU_REQ_CNT_REG      (SRE_DLHDCP_BASE + 0x30)     /* BMU����Buffer����ͳ�ƼĴ��� */
#define SRE_DLHDCP_BMU_FAIL_CNT_REG     (SRE_DLHDCP_BASE + 0x34)     /* BMU����Bufferʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_DLHDCP_M0_MEM_RD_CNT_REG    (SRE_DLHDCP_BASE + 0x38)     /* MASTER0 Memory������ͳ�ƼĴ��� */
#define SRE_DLHDCP_M1_MEM_RD_CNT_REG    (SRE_DLHDCP_BASE + 0x3C)     /* MASTER1 Memory������ͳ�ƼĴ��� */
#define SRE_DLHDCP_M0_MEM_WR_CNT_REG    (SRE_DLHDCP_BASE + 0x40)     /* MASTER0 Memoryд����ͳ�ƼĴ��� */
#define SRE_DLHDCP_M1_MEM_WR_CNT_REG    (SRE_DLHDCP_BASE + 0x44)     /* MASTER1 Memoryд����ͳ�ƼĴ��� */
#define SRE_DLHDCP_M0_MEM_FAIL_CNT_REG  (SRE_DLHDCP_BASE + 0x48)     /* MASTER0 Memory��дʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_DLHDCP_M1_MEM_FAIL_CNT_REG  (SRE_DLHDCP_BASE + 0x4C)     /* MASTER1 Memory��дʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_DLHDCP_RINT_REG             (SRE_DLHDCP_BASE + 0x50)     /* DLHDCPԭʼ�жϼĴ��� */
#define SRE_DLHDCP_INTMSK_REG           (SRE_DLHDCP_BASE + 0x54)     /* DLHDCP�ж����μĴ��� */
#define SRE_DLHDCP_INTSTS_REG           (SRE_DLHDCP_BASE + 0x58)     /* DLHDCP�ж�״̬�Ĵ��� */
#define SRE_DLHDCP_BDERR_ADDR_REG       (SRE_DLHDCP_BASE + 0x5C)     /* �쳣DLHDCP_BD��Ӧ��HBD�׵�ַ */
#define SRE_DLHDCP_WRMEM_ERR_ADDR_REG   (SRE_DLHDCP_BASE + 0x60)     /* дL3C/DDRʧ��ʱ��Ӧ��д�����ַ */
#define SRE_DLHDCP_RDMEM_ERR_ADDR_REG   (SRE_DLHDCP_BASE + 0x64)     /* ��L3C/DDRʧ��ʱ��Ӧ�Ķ������ַ */
#define SRE_DLHDCP_SRIO_ADDR_REG        (SRE_DLHDCP_BASE + 0x68)     /* SRIO����Ĵ�����ַ */
#define SRE_DLHDCP_POE_GET_ADDR_REG     (SRE_DLHDCP_BASE + 0x6C)     /* ��POEȡ�����ַ */
#define SRE_DLHDCP_POE_ADDR_ADDR_REG    (SRE_DLHDCP_BASE + 0x70)     /* ��POE��������ַ */
#define SRE_DLHDCP_VMID_REG             (SRE_DLHDCP_BASE + 0x74)     /* VMID���üĴ��� */
#define SRE_DLHDCP_NODE_CODE_REG        (SRE_DLHDCP_BASE + 0x78)     /* ����Դ�豸�� */
#define SRE_DLHDCP_MST_DFX_CTRL_REG     (SRE_DLHDCP_BASE + 0x7C)     /* AXI_MST�ӿ�DFX���üĴ��� */
#define SRE_DLHDCP_MST0_AVG_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x80)     /* AXI_MST_IF0�ӿڶ�дƽ����ʱͳ�� */
#define SRE_DLHDCP_MST0_MAX_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x84)     /* AXI_MST_IFO�ӿڶ�д�����ʱͳ�� */
#define SRE_DLHDCP_MST0_ACC_RD_REG      (SRE_DLHDCP_BASE + 0x88)     /* MSTO���ܴ���ͳ�� */
#define SRE_DLHDCP_MST0_ACC_WR_REG      (SRE_DLHDCP_BASE + 0x8C)     /* MSTOд�ܴ���ͳ�� */
#define SRE_DLHDCP_MST1_AVG_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x90)     /* AXI_MST_IF1�ӿڶ�дƽ����ʱͳ�� */
#define SRE_DLHDCP_MST1_MAX_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x94)     /* AXI_MST_IF1�ӿڶ�д�����ʱͳ�� */
#define SRE_DLHDCP_MST1_ACC_RD_REG      (SRE_DLHDCP_BASE + 0x98)     /* MST1��д�ܴ���ͳ�� */
#define SRE_DLHDCP_MST1_ACC_WR_REG      (SRE_DLHDCP_BASE + 0x9C)     /* MST1��д�ܴ���ͳ�� */
#define SRE_DLHDCP_RD_OTSD_DEPTH_REG    (SRE_DLHDCP_BASE + 0xA0)     /* �����ĵ�outstanding��� */
#define SRE_DLHDCP_M0_BD_RRESP_NOK_STAT_REG  (SRE_DLHDCP_BASE + 0xA4)     /* MST0��BD����Ӧ����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_BD_ID_NEQ_STAT0_REG  (SRE_DLHDCP_BASE + 0xA8)     /* MST0��BD����ӦID�Ͷ�����ID��ƥ��ͳ��ֵ */
#define SRE_DLHDCP_MEM_BD_RLAST_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0xAC)     /* MST0��BD��rlast����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_VBD_BUF_ADDR_NCACHE_STAT0_REG  (SRE_DLHDCP_BASE + 0xB0)     /* MST0��BD��VBD��ַû��cacheline�����ͳ�� */
#define SRE_DLHDCP_MEM_RBD_BUF_ADDR_NCACHE_STAT0_REG  (SRE_DLHDCP_BASE + 0xB4)     /* MST0��BD��RBD��ַû��cacheline�����ͳ�� */
#define SRE_DLHDCP_M1_BD_RRESP_NOK_STAT_REG  (SRE_DLHDCP_BASE + 0xB8)     /* MST1��BD����Ӧ����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_BD_ID_NEQ_STAT1_REG  (SRE_DLHDCP_BASE + 0xBC)     /* MST1��BD����ӦID�Ͷ�����ID��ƥ��ͳ��ֵ */
#define SRE_DLHDCP_MEM_BD_RLAST_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0xC0)     /* MST1��BD��rlast����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_VBD_BUF_ADDR_NCACHE_STAT1_REG  (SRE_DLHDCP_BASE + 0xC4)     /* MST1��BD��VBD��ַû��cacheline�����ͳ�� */
#define SRE_DLHDCP_MEM_RBD_BUF_ADDR_NCACHE_STAT1_REG  (SRE_DLHDCP_BASE + 0xC8)     /* MST1��BD��RBD��ַû��cacheline�����ͳ�� */
#define SRE_DLHDCP_PKT_LEN_ZERO_STAT0_REG  (SRE_DLHDCP_BASE + 0xCC)     /* ͨ��MST0��ȡ�������������ܳ���Ϊ0�ĸ���ͳ�� */
#define SRE_DLHDCP_MEM_MSG_RRESP_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0xD0)     /* MST0��MSG����Ӧ����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_ID_NEQ_STAT0_REG  (SRE_DLHDCP_BASE + 0xD4)     /* MST0��MSG����ӦID�Ͷ�����ID��ƥ��ͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_RLAST_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0xD8)     /* MST0��MSG��rlast����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_BRESP_NOK_STAT_REG  (SRE_DLHDCP_BASE + 0xDC)     /* MST0дMSGд��Ӧ����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_BID_NEQ_STAT0_REG  (SRE_DLHDCP_BASE + 0xE0)     /* MST0дMSGд��ӦID��д����ID��ƥ��ͳ��ֵ */
#define SRE_DLHDCP_TASK_PRO_AVG_TIME_STAT0_REG  (SRE_DLHDCP_BASE + 0xE4)     /* ͨ��MST0����������ƽ������ʱ�� */
#define SRE_DLHDCP_TASK_PRO_MAX_TIME_STAT0_REG  (SRE_DLHDCP_BASE + 0xE8)     /* ͨ��MST0���������������ʱ�� */
#define SRE_DLHDCP_TASK_PRO_TIME_CNT_OVFL_STAT0_REG  (SRE_DLHDCP_BASE + 0xEC)     /* ͨ��MST0���������������ʱ��������������ͳ�� */
#define SRE_DLHDCP_PKT_LEN_ZERO_STAT1_REG  (SRE_DLHDCP_BASE + 0xF0)     /* ͨ��MST1��ȡ�������������ܳ���Ϊ0�ĸ���ͳ�� */
#define SRE_DLHDCP_MEM_MSG_RRESP_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0xF4)     /* MST1��MSG����Ӧ����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_ID_NEQ_STAT1_REG  (SRE_DLHDCP_BASE + 0xF8)     /* MST1��MSG����ӦID�Ͷ�����ID��ƥ��ͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_RLAST_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0xFC)     /* MST1��MSG��rlast����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_BRESP_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x100)    /* MST1дMSGд��Ӧ����ȷͳ��ֵ */
#define SRE_DLHDCP_MEM_MSG_BID_NEQ_STAT1_REG  (SRE_DLHDCP_BASE + 0x104)    /* MST1дMSGд��ӦID��д����ID��ƥ��ͳ��ֵ */
#define SRE_DLHDCP_TASK_PRO_AVG_TIME_STAT1_REG  (SRE_DLHDCP_BASE + 0x108)    /* ͨ��MST1����������ƽ������ʱ�� */
#define SRE_DLHDCP_TASK_PRO_MAX_TIME_STAT1_REG  (SRE_DLHDCP_BASE + 0x10C)    /* ͨ��MST1���������������ʱ�� */
#define SRE_DLHDCP_TASK_PRO_TIME_CNT_OVFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x110)    /* ͨ��MST1���������������ʱ��������������ͳ�� */
#define SRE_DLHDCP_BD_PKT_SIZE_ZERO_STAT0_REG  (SRE_DLHDCP_BASE + 0x114)    /* MST0����������pkt size Ϊ0���������ͳ�� */
#define SRE_DLHDCP_BD_FIFO_OVFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x118)    /* MST0 BD FIFO��д�Ĵ���ͳ�� */
#define SRE_DLHDCP_BD_FIFO_UDFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x11C)    /* MSTO BD FIFO�ն��Ĵ���ͳ�� */
#define SRE_DLHDCP_SHAPING_FIFO_OVFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x120)    /* MST0 SHAPING FIFO��д�Ĵ���ͳ�� */
#define SRE_DLHDCP_SHAPING_FIFO_UDFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x124)    /* MST0 SHAPING FIFO�ն��Ĵ���ͳ�� */
#define SRE_DLHDCP_BD_PKT_SIZE_ZERO_STAT1_REG  (SRE_DLHDCP_BASE + 0x128)    /* MST1����������pkt size Ϊ0���������ͳ�� */
#define SRE_DLHDCP_BD_FIFO_OVFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x12C)    /* MST1 BD FIFO��д�Ĵ���ͳ�� */
#define SRE_DLHDCP_BD_FIFO_UDFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x130)    /* MST1 BD FIFO�ն��Ĵ���ͳ�� */
#define SRE_DLHDCP_SHAPING_FIFO_OVFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x134)    /* MST1 SHAPING FIFO��д�Ĵ���ͳ�� */
#define SRE_DLHDCP_SHAPING_FIFO_UDFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x138)    /* MST1 SHAPING FIFO�ն��Ĵ���ͳ�� */
#define SRE_DLHDCP_PKT_LEN_NOK_STATO_REG  (SRE_DLHDCP_BASE + 0x13C)    /* MST0�����ܳ��Ⱥ͸�����㳤�ȵ��ۼ�ֵ��ƥ�� */
#define SRE_DLHDCP_PKT_BUF_NUM_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0x140)    /* MST0 BUF_NUM��������ȷͳ�� */
#define SRE_DLHDCP_PKT_NXT_BUF_ADDR_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0x144)    /* MST0 ��һ����ַ����ȷͳ�� */
#define SRE_DLHDCP_PKT_LEN_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x148)    /* MST1�����ܳ��Ⱥ͸�����㳤�ȵ��ۼ�ֵ��ƥ�� */
#define SRE_DLHDCP_PKT_BUF_NUM_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x14C)    /* MST1 BUF_NUM��������ȷͳ�� */
#define SRE_DLHDCP_PKT_NXT_BUF_ADDR_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x150)    /* MST1 ��һ����ַ����ȷͳ�� */
#define SRE_DLHDCP_ABNORM_TYPE0_REG     (SRE_DLHDCP_BASE + 0x154)    /* �쳣���ͼĴ��� */
#define SRE_DLHDCP_ABNORM_INFORMATION0_REG  (SRE_DLHDCP_BASE + 0x158)    /* �쳣��Ϣ�Ĵ��� */
#define SRE_DLHDCP_ABNORM_TYPE1_REG     (SRE_DLHDCP_BASE + 0x15C)    /* �쳣���ͼĴ��� */
#define SRE_DLHDCP_ABNORM_INFORMATION1_REG  (SRE_DLHDCP_BASE + 0x160)    /* �쳣��Ϣ�Ĵ��� */
#define SRE_DLHDCP_CFG_RSV0_REG         (SRE_DLHDCP_BASE + 0x164)    /* DLHDCP ���ñ����Ĵ���0 */
#define SRE_DLHDCP_CFG_RSV1_REG         (SRE_DLHDCP_BASE + 0x168)    /* DLHDCP ���ñ����Ĵ���1 */
#define SRE_DLHDCP_CFG_RSV2_REG         (SRE_DLHDCP_BASE + 0x16C)    /* DLHDCP ���ñ����Ĵ���2 */
#define SRE_DLHDCP_STS_RSV0_REG         (SRE_DLHDCP_BASE + 0x170)    /* DLHDCP ״̬�����Ĵ���0 */
#define SRE_DLHDCP_STS_RSV1_REG         (SRE_DLHDCP_BASE + 0x174)    /* DLHDCP ״̬�����Ĵ���1 */
#define SRE_DLHDCP_STS_RSV2_REG         (SRE_DLHDCP_BASE + 0x178)    /* DLHDCP ״̬�����Ĵ���2 */

/* ULHDCP_REG ģ��Ĵ�������ַ */
#define SRE_ULHDCP_REG_BASE             (0x10870000)

/******************************************************************************/
/*                      MC ULHDCP_REG �Ĵ�������                   */
/******************************************************************************/
#define SRE_ULHDCP_REG_CFG_ENABLE_REG  (SRE_ULHDCP_REG_BASE + 0x0)  /* ULHDCPʹ�ܿ��ƼĴ����� */
#define SRE_ULHDCP_REG_CFG_BMU_POOL_ID_REG  (SRE_ULHDCP_REG_BASE + 0x4)  /* BMU POOL IDѡ��Ĵ����� */
#define SRE_ULHDCP_REG_CFG_BMU_POOL_SIZE_REG  (SRE_ULHDCP_REG_BASE + 0x8)  /* Buffer�ռ��С���üĴ����� */
#define SRE_ULHDCP_REG_CFG_BMU_REQ_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x10)  /* ����BMU�ĵ�ַ�� */
#define SRE_ULHDCP_REG_MODE_REG  (SRE_ULHDCP_REG_BASE + 0x14)  /* ULHDCP״̬�Ĵ��� */
#define SRE_ULHDCP_REG_M0_BUS_WR_TRANS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x18)  /* MASTER����д�������ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_STS_REG   (SRE_ULHDCP_REG_BASE + 0x1C)  /* ULHDCPģ��״̬�Ĵ��� */
#define SRE_ULHDCP_REG_M0_BUS_RD_TRANS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x20)  /* MASTER���߶��������ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_POE_ADD_TRS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x34)  /* POE ADD�����ܴ����Ĵ����� */
#define SRE_ULHDCP_REG_POE_GET_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x48)  /* POE GET�����ܴ����Ĵ����� */
#define SRE_ULHDCP_REG_POE_ADD_RLS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x4C)  /* POE ADD�����ܴ����Ĵ����� */
#define SRE_ULHDCP_REG_POE_FAIL_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x50)  /* POE GET����ADD����ʧ�ܴ����Ĵ����� */
#define SRE_ULHDCP_REG_BMU_REQ_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x60)  /* BMU����Buffer����ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_BMU_FAIL_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x64)  /* BMU����Bufferʧ�ܴ���ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_ADD_POE_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x68)  /* ADD POEʧ�ܴ���ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_M0_MEM_RD_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x6C)  /* MASTER Memory������ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_M0_MEM_WR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x70)  /* MASTER Memoryд����ͳ�ƼĴ����� */
#define SRE_ULHDCP_REG_L3CACHE_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x74)  /* ULHDCPģ���д����ʱ�Ƿ񾭹�L3 Cache���ƼĴ����� */
#define SRE_ULHDCP_REG_RINT_REG  (SRE_ULHDCP_REG_BASE + 0x78)  /* ULHDCPԭʼ�жϼĴ����� */
#define SRE_ULHDCP_REG_INTMSK_REG  (SRE_ULHDCP_REG_BASE + 0x7C)  /* ULHDCP�ж����μĴ����� */
#define SRE_ULHDCP_REG_INTSTS_REG  (SRE_ULHDCP_REG_BASE + 0x80)  /* ULHDCP�ж�״̬�Ĵ����� */
#define SRE_ULHDCP_REG_POE_GET_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x98)  /* ��POEȡ�����ַ�� */
#define SRE_ULHDCP_REG_POE_ADDR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x9C)  /* ��POE��������ַ�� */
#define SRE_ULHDCP_REG_VMID_REG  (SRE_ULHDCP_REG_BASE + 0xA0)  /* VMID���üĴ����� */
#define SRE_ULHDCP_REG_SKIP1_LEN_REG  (SRE_ULHDCP_REG_BASE + 0xD0)  /* ULHDCPģ��SKIP1�������üĴ����� */
#define SRE_ULHDCP_REG_SKIP2_LEN_REG  (SRE_ULHDCP_REG_BASE + 0xD4)  /* ULHDCPģ��SKIP2�������üĴ����� */

#define SRE_ULHDCP_REG_ERR_STA_REG  (SRE_ULHDCP_REG_BASE + 0xDC)  /* ULHDCPģ���ڲ��澯��ѯ�Ӵ����� */
#define SRE_ULHDCP_REG_PKTLEN_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xE0)  /* ULHDCPģ�鴦��ĳ���Ϊ0�����ݰ�����ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_INVLD_TASK_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xE4)  /* ULHDCPģ�鴦�����Ч�������ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_CIPHER_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xE8)  /* ULHDCPģ����Ƶ�SEC BD�ļ��ܷ�Χ��������ݰ�����ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_AUTH_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xEC)  /* ULHDCPģ����Ƶ�SEC BD����֤��Χ��������ݰ�����ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_MAC_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xF0)  /* ULHDCPģ����Ƶ�SEC BD����֤���ַ��������ݰ�����ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_BIG_ENDIAN_REG  (SRE_ULHDCP_REG_BASE + 0xF4)  /* ULHDCPģ�����DDRʱ�Ĵ�С��ģʽ���üĴ����� */
#define SRE_ULHDCP_REG_NODE_CODE_REG  (SRE_ULHDCP_REG_BASE + 0xF8)  /* ULHDCPģ���豸�����üĴ����� */
#define SRE_ULHDCP_REG_BDERR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0xFC)  /* ULHDCPģ���쳣BD��Ӧ��VBD�׵�ַ */
#define SRE_ULHDCP_REG_WRMEM_ERR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x100)  /* ULHDCPģ��дL3C/DDRʧ��ʱ��Ӧ��д�����ַ */
#define SRE_ULHDCP_REG_RDMEM_ERR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x104)  /* ULHDCPģ���L3C/DDRʧ��ʱ��Ӧ�Ķ������ַ */
#define SRE_ULHDCP_REG_MEM_FAIL_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x108)  /* ULHDCPģ���дMemoryʧ�ܴ���ͳ�ƼĴ��� */
#define SRE_ULHDCP_REG_VBD_ERR0_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x10C)  /* ULHDCPģ���VBD�������ݰ��ĸ���ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_VBD_ERR1_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x110)  /* ULHDCPģ���VBD�������ݰ��ĸ���ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_VBD_ERR2_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x114)  /* ULHDCPģ���VBD�������ݰ��ĸ���ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_BMU_REQ_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x17C)  /* ULHDCPģ���BMU���ÿ��ƼĴ����� */
#define SRE_ULHDCP_REG_GET_POE_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x180)  /* ULHDCPģ��GET POE���ÿ��ƼĴ����� */
#define SRE_ULHDCP_REG_ADD_POE_RLS_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x184)  /* ULHDCPģ��ADD POE�������ͷţ����ÿ��ƼĴ����� */
#define SRE_ULHDCP_REG_ADD_POE_TRS_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x18C)  /* ULHDCPģ��ADD POE������ת�������ÿ��ƼĴ����� */
#define SRE_ULHDCP_REG_BMU_REQ_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x190)  /* ULHDCPģ������BMU����ʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_POE_GET_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x194)  /* ULHDCPģ��GET POEʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_VBD_RD_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x198)  /* ULHDCPģ���VBDʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_PKT_RD_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x19C)  /* ULHDCPģ������ݰ�ʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_POE_ADDTRS_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1A0)  /* ULHDCPģ��ADD POE������ת����ʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_POE_ADDRLS_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1A4)  /* ULHDCPģ��ADD POE�������ͷţ�ʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_BD_WR_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1A8)  /* ULHDCPģ��дcopy���BDʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_PKT_WR_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1AC)  /* ULHDCPģ��дcopy������ݰ�ʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_RW_RSV0_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1B0)  /* ULHDCPģ������DFX�ı����Ĵ����� */
#define SRE_ULHDCP_REG_RW_RSV1_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1B4)  /* ULHDCPģ������DFX�ı����Ĵ����� */
#define SRE_ULHDCP_REG_RW_RSV2_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1B8)  /* ULHDCPģ������DFX�ı����Ĵ����� */
#define SRE_ULHDCP_REG_RO_RSV0_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1C0)  /* ULHDCPģ������DFX�ı����Ĵ����� */
#define SRE_ULHDCP_REG_RO_RSV1_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1C4)  /* ULHDCPģ������DFX�ı����Ĵ����� */
#define SRE_ULHDCP_REG_RO_RSV2_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1C8)  /* ULHDCPģ������DFX�ı����Ĵ����� */
#define SRE_ULHDCP_REG_AXIRD_DFX_CFG_REG  (SRE_ULHDCP_REG_BASE + 0x1D0)  /* ULHDCPģ��AXI���߶�����ͨ��DFX���üĴ����� */
#define SRE_ULHDCP_REG_AXIWR_DFX_CFG_REG  (SRE_ULHDCP_REG_BASE + 0x1D4)  /* ULHDCPģ��AXI����д����ͨ��DFX���üĴ����� */
#define SRE_ULHDCP_REG_AXIRD_DFX_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1D8)  /* ULHDCPģ��AXI���߶�����ͨ��DFX״̬�ϱ��Ĵ����� */
#define SRE_ULHDCP_REG_AXIWR_DFX_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1DC)  /* ULHDCPģ��AXI����д����ͨ��DFX״̬�ϱ��Ĵ����� */
#define SRE_ULHDCP_REG_AXIWR_TIMES_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1E0)  /* ULHDCPģ��AXI����д����ͨ��д����״̬�ϱ��Ĵ����� */
#define SRE_ULHDCP_REG_AXIRD_TIMES_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1E4)  /* ULHDCPģ��AXI���߶�����ͨ��д����״̬�ϱ��Ĵ����� */
#define SRE_ULHDCP_REG_AXI_OTSD_0CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1E8)  /* ULHDCPģ��AXI���߶�����ͨ��OutStanding����ϱ��Ĵ����� */
#define SRE_ULHDCP_REG_AXI_OTSD_1CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1EC)  /* ULHDCPģ��AXI����д����ͨ��дOutStanding����ϱ��Ĵ����� */
#define SRE_ULHDCP_REG_ADDSPE_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1F0)  /* ULHDCPģ��ADD POE���˼���Ϣ��ʱ��ʱ���ƼĴ����� */
#define SRE_ULHDCP_REG_POE_SPE_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x1F4)  /* ULHDCPģ����POEģ��ADD�˼���Ϣʱ�Ļ���ַ���üĴ����� */
#define SRE_ULHDCP_REG_ROHCBD_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1F8)  /* ULHDCPģ����Ƶ�ROHC BD��������ݰ�����ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_ADDSPE_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1FC)  /* ULHDCPģ��ADD�˼���Ϣ����ͳ�Ƽ������� */
#define SRE_ULHDCP_REG_ADD_POE_SPE_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x200)  /* ULHDCPģ��ADD POE���˼���Ϣ�����ÿ��ƼĴ����� */



//******************************************************************************

/* SPPE ģ��Ĵ�������ַ */
#define  MC_SPPE_REG_BASE                                 (0x20000000)

/******************************************************************************/
/*                      MC SPPE �Ĵ�������                                    */
/******************************************************************************/
#define MC_SAP_OFFSET                                         (0x0007000)

#define MC_SPPE_SAP_THREAD_RBA_REQ_IOOP_0_REG      (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x0)               /* RBA Request��IO�������Ϳ��� */
#define MC_SPPE_SAP_THREAD_RBA_REQ_ADDR_0_REG      (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x4)               /* RBA Request��LOAD��STORE��LOOKUPָ����CTRL Word�е�ADDR�� */
#define MC_SPPE_SAP_THREAD_RBA_REQ_CTRL_0_REG       (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x8)               /* RBA Request��LOAD��STORE��LOOKUPָ����CTRL Word�е�CTRL�� */
#define MC_SPPE_SAP_THREAD_RBA_REQ_START_0_REG     (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0xC)               /* RBA Request�������� */
#define MC_SPPE_SAP_THREAD_RBA_STATUS_0_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x10)              /* RBA�߳̿���״̬�Ĵ��� */
#define MC_SPPE_SAP_THREAD_RBA_TOUT_TH_0_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x20)              /* �üĴ���Ϊ�߳�RBA����Timer��ʱ����ֵ */
#define MC_SPPE_SAP_THREAD_RBA_DATA0_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x40)              /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA1_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x44)              /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA2_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x48)              /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA3_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x4c)              /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA4_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x50)              /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA5_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x54)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA6_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x58)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA7_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x5c)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA8_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x60)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA9_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x64)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA10_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x64)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA11_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x6c)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA12_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x70)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA13_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x74)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA14_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x78)             /* RBA request��RBA response�е�DATA�� */
#define MC_SPPE_SAP_THREAD_RBA_DATA15_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x7C)             /* RBA request��RBA response�е�DATA�� */


#define MC_SPPE_SAP_AVAIL_THREAD_BADDR_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x800)             /* CPU�����̻߳���ַ�Ĵ��� */
#define MC_SPPE_SAP_RELEASE_THREAD_BADDR_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x810)             /* CPU�ͷ��̻߳���ַ�Ĵ��� */
#define MC_SPPE_SAP_THREAD_ALLOC_FLAG_REG            (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x814)             /* �̷߳���״̬�Ĵ��� */
#define MC_SPPE_SAP_MEM_INIT_START_REG               (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x820)             /* SAP Memory��ʼ�������Ĵ��� */
#define MC_SPPE_SAP_MEM_INIT_STATUS_REG              (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x824)             /* SAP Memory��ʼ��״̬�Ĵ��� */
#define MC_SPPE_SAP_INT_RINT_REG                     (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x830)             /* SAP�ж�ԭʼ�Ĵ��� */
#define MC_SPPE_SAP_INT_STATUS_REG                   (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x834)             /* SAP�ж�״̬�Ĵ��� */
#define MC_SPPE_SAP_INT_EN_REG                       (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x838)             /* SAP�ж�ʹ�ܼĴ��� */
#define MC_SPPE_SAP_BUSY_ACCESS_BADDR_REG            (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x840)             /* busy_access�жϷ���ʱ����¼�ظ����ʵ��̼߳Ĵ�������ַ */
#define MC_SPPE_SAP_INVALID_REL_BADDR_REG            (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x844)             /* invalid_rel�жϷ���ʱ����¼������д����̼߳Ĵ�������ַ */
#define MC_SPPE_SAP_DUPL_REL_BADDR_REG               (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x848)             /* dupl_rel�жϷ���ʱ����¼�ظ��ͷŵ��̼߳Ĵ�������ַ */
#define MC_SPPE_SAP_INVALID_IOOP_BADDR_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x84C)             /* invalid_ioop�жϷ���ʱ����¼д��IOOP������̼߳Ĵ�������ַ */
#define MC_SPPE_SAP_INVALID_RESP_BADDR_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x850)             /* invalid_resp�жϷ���ʱ����¼���󷵻���Ӧ���߳�ID��Ӧ���̼߳Ĵ�������ַ */
#define MC_SPPE_SAP_MUTEX_QUEUE_FULL_BADDR_REG       (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x854)             /* Mutex Queue��ʱ����¼A15д��RELEASE_THREAD_BADDR���̼߳Ĵ��������ַ */
#define MC_SPPE_SAP_OE_ACC_ERR_BADDR_REG             (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x858)             /* A15ͨ��SAP����ط���OE����ʱ����¼�̼߳Ĵ��������ַ */
#define MC_SPPE_SAP_IERR_INSERT_REG                  (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x880)             /* �Ĵ��������û���׼��д��SAP�ڲ�Memory�������в������ */
#define MC_SPPE_SAP_IERR_C_INFO_REG                  (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x884)             /* ��¼��У��Memoryһ���Դ����Memory ID */
#define MC_SPPE_SAP_IERR_U_INFO_REG                  (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x888)             /* ��¼����У��Memoryһ���Դ����Memory ID */
#define MC_SPPE_SAP_IERR_C_CNT_REG                   (MC_SPPE_REG_BASE  +MC_SAP_OFFSET+ 0x88C)             /* �Կ�У��Memoryһ���Դ�����������塣 */
#define MC_SPPE_SAP_IERR_U_CNT_REG                   (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x890)             /* �Բ���У��Memoryһ���Դ�����������塣 */


#define MC_MASTER_ATOM_CLK_ENABLE         (MC_SPPE_REG_BASE + 0x0003004C)
/******************************************************************************/
/*                      TS �Ĵ�������                                    */
/******************************************************************************/
#define MC_SE_EM_INT_STATUS	                 (MC_SPPE_REG_BASE + 0x00010004)
#define MC_SE_EM_INT_ENABLE	                 (MC_SPPE_REG_BASE + 0x00010008)
#define MC_SE_EM_INT_SET	                          (MC_SPPE_REG_BASE + 0x0001000C)
#define MC_SE_DISP_IERR_F_INFO	        (MC_SPPE_REG_BASE + 0x00010020)
#define MC_SE_DISP_IERR_U_CNT	        (MC_SPPE_REG_BASE + 0x00010024)
#define MC_SE_DISP_IERR_U_INFO	        (MC_SPPE_REG_BASE + 0x00010028)
#define MC_SE_DISP_IERR_C_CNT	        (MC_SPPE_REG_BASE + 0x0001002C)
#define MC_SE_DISP_IERR_C_INFO	        (MC_SPPE_REG_BASE + 0x00010030)
#define MC_SE_DISP_BAD_CMD_CNT	        (MC_SPPE_REG_BASE + 0x0001003C)
#define MC_SE_DISP_BAD_CMD_INFO	        (MC_SPPE_REG_BASE + 0x00010040)
#define MC_SE_DISP_FIFO_OVF_CNT	        (MC_SPPE_REG_BASE + 0x0001004C)
#define MC_SE_DISP_FIFO_OVF_INFO	        (MC_SPPE_REG_BASE + 0x00010050)
#define MC_SE_DISP_QUE_LPM_CNT	        (MC_SPPE_REG_BASE + 0x00010060)
#define MC_SE_DISP_QUE_LCAM_CNT	        (MC_SPPE_REG_BASE + 0x00010064)
#define MC_SE_DISP_QUE_EM_SLOW_CNT	(MC_SPPE_REG_BASE + 0x00010068)
#define MC_SE_DISP_QUE_EM_FAST_CNT	(MC_SPPE_REG_BASE + 0x0001006C)
#define MC_SE_DISP_FIFO_STATUS0	        (MC_SPPE_REG_BASE + 0x00010070)
#define MC_SE_EM_DISP_EM_CMD_FIFO_TH	(MC_SPPE_REG_BASE + 0x00010074)
#define MC_SE_EM_DISP_LPM_CMD_FIFO_TH	(MC_SPPE_REG_BASE + 0x00010078)
#define MC_SE_DISP_PROBE0_EN	                 (MC_SPPE_REG_BASE + 0x000100A0)
#define MC_SE_DISP_PROBE0_DONE	        (MC_SPPE_REG_BASE + 0x000100A4)
#define MC_SE_DISP_PROBE0_MSK 	        (MC_SPPE_REG_BASE + 0x000100A8)
#define MC_SE_DISP_PROBE0_MSK16	        (MC_SPPE_REG_BASE + 0x000100E8)
#define MC_SE_DISP_PROBE0_MSK17	        (MC_SPPE_REG_BASE + 0x000100EC)
#define MC_SE_DISP_PROBE0_DAT 	        (MC_SPPE_REG_BASE + 0x000100F0)
#define MC_SE_DISP_PROBE0_DAT16	        (MC_SPPE_REG_BASE + 0x00010130)
#define MC_SE_DISP_PROBE0_DAT17	        (MC_SPPE_REG_BASE + 0x00010134)
#define MC_SE_DISP_PROBE0_RSLT 	        (MC_SPPE_REG_BASE + 0x00010138)
#define MC_SE_DISP_PROBE0_RSLT16	        (MC_SPPE_REG_BASE + 0x00010178)
#define MC_SE_DISP_PROBE0_RSLT17	        (MC_SPPE_REG_BASE + 0x0001017C)
#define MC_SE_DISP_PROBE1_EN	                 (MC_SPPE_REG_BASE + 0x00010180)
#define MC_SE_DISP_PROBE1_DONE	        (MC_SPPE_REG_BASE + 0x00010184)
#define MC_SE_DISP_PROBE1_MSK 	        (MC_SPPE_REG_BASE + 0x00010188)
#define MC_SE_DISP_PROBE1_MSK16	        (MC_SPPE_REG_BASE + 0x000101C8)
#define MC_SE_DISP_PROBE1_DAT 	        (MC_SPPE_REG_BASE + 0x000101CC)
#define MC_SE_DISP_PROBE1_DAT16	        (MC_SPPE_REG_BASE + 0x0001020C)
#define MC_SE_DISP_PROBE1_RSLT 	        (MC_SPPE_REG_BASE + 0x00010210)
#define MC_SE_DISP_PROBE1_RSLT16	        (MC_SPPE_REG_BASE + 0x00010250)
#define MC_SE_DISP_ATOM_HASH_CNT	(MC_SPPE_REG_BASE + 0x00010254)
#define MC_SE_DISP_ATOM_MOD_CNT        (MC_SPPE_REG_BASE + 0x00010258)
#define MC_SE_DISP_ATOM_POP_CNT	        (MC_SPPE_REG_BASE + 0x0001025C)
#define MC_SE_DISP_ATOM_PUSH_CNT	(MC_SPPE_REG_BASE + 0x00010260)
#define MC_SE_DISP_ATOM_LPM_SRCH_CNT	(MC_SPPE_REG_BASE + 0x00010264)
#define MC_SE_DISP_ATOM_LCAM_SRCH_CNT	(MC_SPPE_REG_BASE + 0x00010268)
#define MC_SE_DISP_RBA_DISP_CNT	                  (MC_SPPE_REG_BASE + 0x00010270)
#define MC_SE_DISP_RBA_CNT	                          (MC_SPPE_REG_BASE + 0x00010274)
#define MC_SE_DISP_EM_0_CNT	                          (MC_SPPE_REG_BASE + 0x00010278)
#define MC_SE_DISP_EM_1_CNT	                          (MC_SPPE_REG_BASE + 0x0001027C)
#define MC_SE_DISP_LPM_0_CNT	                          (MC_SPPE_REG_BASE + 0x00010280)
#define MC_SE_DISP_ATOM_READ_CNT	         (MC_SPPE_REG_BASE + 0x00010290)
#define MC_SE_DISP_ATOM_WRITE_CNT	         (MC_SPPE_REG_BASE + 0x00010294)
#define MC_SE_DISP_ATOM_EM_SRCH_CNT	(MC_SPPE_REG_BASE + 0x00010298)
#define MC_SE_DISP_ATOM_LOCK_CNT	         (MC_SPPE_REG_BASE + 0x0001029C)
#define MC_SE_DISP_ATOM_UNLOCK_CNT	         (MC_SPPE_REG_BASE + 0x000102A0)
#define MC_SE_DISP_EM_CFG_TBL 	                  (MC_SPPE_REG_BASE + 0x00010300)
#define MC_SE_DISP_EM_HT1_SIZE 	                  (MC_SPPE_REG_BASE + 0x00010340)
#define MC_SE_DISP_EM_HT1_INDEX_MASK 	(MC_SPPE_REG_BASE + 0x00010380)
#define MC_SE_DISP_CRC_CFG_VALUE        (MC_SPPE_REG_BASE + 0x000103C0)
#define MC_SE_DISP_CRC_INIT_MATRIX	(MC_SPPE_REG_BASE + 0x00010400)
#define MC_SE_DISP_LOCK_TAB_WORD	(MC_SPPE_REG_BASE + 0x00010500)
#define MC_SE_DISP_VQ_DEBUG_MOD	        (MC_SPPE_REG_BASE + 0x00010600)
#define MC_SE_DISP_VQ_DEBUG_REQ	        (MC_SPPE_REG_BASE + 0x00010604)
#define MC_SE_DISP_VQ_DEBUG_DONE	(MC_SPPE_REG_BASE + 0x00010608)
#define MC_SE_DISP_VQ_DEBUG_DATA0	(MC_SPPE_REG_BASE + 0x0001060C)
#define MC_SE_DISP_VQ_DEBUG_DATA1	(MC_SPPE_REG_BASE + 0x00010610)
#define MC_SE_EM_CAM_INIT_DONE	        (MC_SPPE_REG_BASE + 0x00015000)
#define MC_SE_EM_CAM_SCAN_PRD	        (MC_SPPE_REG_BASE + 0x00015004)
#define MC_SE_EM_CAM_SCAN_EN	        (MC_SPPE_REG_BASE + 0x00015008)
#define MC_SE_LPM_CAM_BASE_ADDR	        (MC_SPPE_REG_BASE + 0x0001500C)
#define MC_SE_EM_CAM_BASE_ADDR	        (MC_SPPE_REG_BASE + 0x00015010)
#define MC_SE_EM_CAM_RCL_TH	                         (MC_SPPE_REG_BASE + 0x00015014)
#define MC_SE_EM_CAM_HPTR_L245W	        (MC_SPPE_REG_BASE + 0x00015018)
#define MC_SE_EM_CAM_HPTR_L245R	                 (MC_SPPE_REG_BASE + 0x0001501C)
#define MC_SE_EM_CAM_TPTR_L245W	        (MC_SPPE_REG_BASE + 0x00015020)
#define MC_SE_EM_CAM_TPTR_L245R	                 (MC_SPPE_REG_BASE + 0x00015024)
#define MC_SE_EM_CAM_IDLENTRY_L245W	        (MC_SPPE_REG_BASE + 0x00015028)
#define MC_SE_EM_CAM_IDLENTRY_L245R	        (MC_SPPE_REG_BASE + 0x0001502C)
#define MC_SE_EM_CAM_HPTR_L490W	        (MC_SPPE_REG_BASE + 0x00015030)
#define MC_SE_EM_CAM_HPTR_L490R	                 (MC_SPPE_REG_BASE + 0x00015034)
#define MC_SE_EM_CAM_TPTR_L490W	        (MC_SPPE_REG_BASE + 0x00015038)
#define MC_SE_EM_CAM_TPTR_L490R	                 (MC_SPPE_REG_BASE + 0x0001503C)
#define MC_SE_EM_CAM_IDLENTRY_L490W        (MC_SPPE_REG_BASE + 0x00015040)
#define MC_SE_EM_CAM_IDLENTRY_L490R	        (MC_SPPE_REG_BASE + 0x00015044)
#define MC_SE_EM_CFG_TBL 	                          (MC_SPPE_REG_BASE + 0x00015100)
#define MC_SE_EM_KT_SIZE 	                                   (MC_SPPE_REG_BASE + 0x00015140)
#define MC_SE_EM_HT1_BASE_ADDR 	        (MC_SPPE_REG_BASE + 0x00015180)
#define MC_SE_EM_KT_BASE_ADDR 	        (MC_SPPE_REG_BASE + 0x000151C0)
#define MC_SE_EM_AGE_BASE_ADDR 	        (MC_SPPE_REG_BASE + 0x00015200)
#define MC_SE_EM_FREE_FIFO_UP_TH 	(MC_SPPE_REG_BASE + 0x00015240)
#define MC_SE_EM_FREE_FIFO_LOW_TH      (MC_SPPE_REG_BASE + 0x00015280)
#define MC_SE_EM_KT_HEAD_POINTER 	(MC_SPPE_REG_BASE + 0x000152C0)
#define MC_SE_EM_KT_TAIL_POINTER 	(MC_SPPE_REG_BASE + 0x00015300)
#define MC_SE_LPM_CAM_GMR                       (MC_SPPE_REG_BASE + 0x00015340)
#define MC_SE_LPM_CAM_SEL_GMR	        (MC_SPPE_REG_BASE + 0x00015400)
#define MC_SE_EM_POOL_EN	                 (MC_SPPE_REG_BASE + 0x00015410)
#define MC_SE_EM_TIMEOUT_TH	                 (MC_SPPE_REG_BASE + 0x0001541C)
#define MC_SE_EM_FIFO_OVF_CNT	        (MC_SPPE_REG_BASE + 0x00015434)
#define MC_SE_EM_FIFO_OVF_INFO	        (MC_SPPE_REG_BASE + 0x00015438)
#define MC_SE_EM_TIMEOUT_CNT	        (MC_SPPE_REG_BASE + 0x0001543C)
#define MC_SE_EM_TIMEOUT_INFO	        (MC_SPPE_REG_BASE + 0x00015440)
#define MC_SE_EM_IERR_U_CNT	        (MC_SPPE_REG_BASE + 0x00015444)
#define MC_SE_EM_IERR_U_INFO	        (MC_SPPE_REG_BASE + 0x00015448)
#define MC_SE_EM_IERR_L_CNT	        (MC_SPPE_REG_BASE + 0x0001544C)
#define MC_SE_EM_IERR_L_INFO	        (MC_SPPE_REG_BASE + 0x00015450)
#define MC_SE_EM_IERR_C_CNT	        (MC_SPPE_REG_BASE + 0x00015454)
#define MC_SE_EM_IERR_C_INFO	        (MC_SPPE_REG_BASE + 0x00015458)
#define MC_SE_EM_IERR_F_INFO	        (MC_SPPE_REG_BASE + 0x0001545C)
#define MC_SE_EM_FIFO_STATUS0	        (MC_SPPE_REG_BASE + 0x00015460)
#define MC_SE_EM_KT_RSLT_FIFO_TH	        (MC_SPPE_REG_BASE + 0x0001546C)
#define MC_SE_EM_COMP_RSLT_FIFO_TH	(MC_SPPE_REG_BASE + 0x00015470)
#define MC_SE_EM_READ_ONCE_FIFO_TH	(MC_SPPE_REG_BASE + 0x00015474)
#define MC_SE_EM_KEY_INFO_FIFO_TH	(MC_SPPE_REG_BASE + 0x0001547C)
#define MC_SE_EM_AGE_BP_EN	                 (MC_SPPE_REG_BASE + 0x00015480)
#define MC_SE_ESM_IERR_U_CNT	        (MC_SPPE_REG_BASE + 0x00015484)
#define MC_SE_ESM_IERR_U_INFO	        (MC_SPPE_REG_BASE + 0x00015488)
#define MC_SE_ESM_IERR_C_CNT	        (MC_SPPE_REG_BASE + 0x0001548C)
#define MC_SE_ESM_IERR_C_INFO	        (MC_SPPE_REG_BASE + 0x00015490)
#define MC_SE_ESM_INT_STATUS	                 (MC_SPPE_REG_BASE + 0x00015494)
#define MC_SE_ESM_INT_ENABLE	                 (MC_SPPE_REG_BASE + 0x00015498)
#define MC_SE_ESM_INT_SET	                 (MC_SPPE_REG_BASE + 0x0001549C)
#define MC_SE_ESM_FIFO_OVF_INFO	        (MC_SPPE_REG_BASE + 0x000154A0)
#define MC_SE_ESM_FIFO_OVF_CNT	        (MC_SPPE_REG_BASE + 0x000154A4)
#define MC_SE_ESM_FIFO_STATUS	        (MC_SPPE_REG_BASE + 0x000154A8)
#define MC_SE_ESM_EM_EXTB0_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x000154AC)
#define MC_SE_ESM_EM_EXTB1_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x000154B0)
#define MC_SE_ESM_EM_HT_BYPASS_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154B4)
#define MC_SE_ESM_EM_HT_INFO_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154B8)
#define MC_SE_ESM_EM_DMC_HT_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154BC)
#define MC_SE_ESM_EM_KT_BYPASS_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154C0)
#define MC_SE_ESM_EM_KT_INFO_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154C4)
#define MC_SE_ESM_EM_DMC_KT_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154C8)
#define MC_SE_EM_SEARCH_CNT	                                  (MC_SPPE_REG_BASE + 0x00015500)
#define MC_SE_EM_RD_CAM_IDX_CNT	                         (MC_SPPE_REG_BASE + 0x00015504)
#define MC_SE_EM_WR_CAM_IDX_CNT	                (MC_SPPE_REG_BASE + 0x00015508)
#define MC_SE_EM_RD_CAM_CNT	                                  (MC_SPPE_REG_BASE + 0x00015510)
#define MC_SE_EM_WR_CAM_CNT	                         (MC_SPPE_REG_BASE + 0x0001551C)
#define MC_SE_EM_RD_HT1_CNT	                                  (MC_SPPE_REG_BASE + 0x00015520)
#define MC_SE_EM_WR_HT1_CNT	                                  (MC_SPPE_REG_BASE + 0x00015524)
#define MC_SE_LPM_SEARCH_CNT	                         (MC_SPPE_REG_BASE + 0x00015528)
#define MC_SE_EM_RD_KT_CNT	                                  (MC_SPPE_REG_BASE + 0x0001553C)
#define MC_SE_EM_WR_KT_CNT	                                  (MC_SPPE_REG_BASE + 0x00015540)
#define MC_SE_EM_PUSH_CAM_CNT	                (MC_SPPE_REG_BASE + 0x00015544)
#define MC_SE_EM_POP_CAM_CNT	                (MC_SPPE_REG_BASE + 0x00015548)
#define MC_SE_EM_PUSH_KT_CNT	                (MC_SPPE_REG_BASE + 0x0001554C)
#define MC_SE_EM_POP_KT_CNT	                        (MC_SPPE_REG_BASE + 0x00015550)
#define MC_SE_EM_AGE_REQ_CNT	                (MC_SPPE_REG_BASE + 0x00015554)
#define MC_SE_EM_HT1_RSLT_CNT	                (MC_SPPE_REG_BASE + 0x0001555C)
#define MC_SE_EM_KT_RSLT_CNT	                (MC_SPPE_REG_BASE + 0x00015560)
#define MC_SE_EM_CKEY_RD_CNT	                (MC_SPPE_REG_BASE + 0x00015564)
#define MC_SE_EM_HT1_REQ_CNT	                (MC_SPPE_REG_BASE + 0x00015568)
#define MC_SE_EM_KT_REQ_CNT	                        (MC_SPPE_REG_BASE + 0x0001556C)
#define MC_SE_EM_POOL_KT_REQ_CNT	        (MC_SPPE_REG_BASE + 0x00015574)
#define MC_SE_EM_POOL_KT_RSLT_CNT	        (MC_SPPE_REG_BASE + 0x00015578)
#define MC_SE_EM_AGE_DROP_CNT	                (MC_SPPE_REG_BASE + 0x0001557C)
#define MC_SE_EM_FLIST_DEBUG_REQ	        (MC_SPPE_REG_BASE + 0x00015600)
#define MC_SE_EM_FLIST_DEBUG_DONE	        (MC_SPPE_REG_BASE + 0x00015604)
#define MC_SE_EM_FLIST_DEBUG_DATA	        (MC_SPPE_REG_BASE + 0x00015608)
#define MC_SE_DISP_EM_DISP_0_CNT	                (MC_SPPE_REG_BASE + 0x00015800)
#define MC_SE_DISP_EM_DISP_1_CNT	                 (MC_SPPE_REG_BASE + 0x00015804)
#define MC_SE_DISP_LPM_DISP_1_CNT	        (MC_SPPE_REG_BASE + 0x00015808)
#define MC_SE_DISP_LCAM_DISP_1_CNT	        (MC_SPPE_REG_BASE + 0x0001580C)
#define MC_SE_DISP_LPM_RSP_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x00015810)
#define MC_SE_DISP_LCAM_RSP_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x00015814)
#define MC_SE_DISP_EM_RSP_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x00015818)
#define MC_SE_DISP_FIFO_STATUS1	                          (MC_SPPE_REG_BASE + 0x00015820)

/*LCAM*/
#define MC_LCAM_OFFSET                       (0x0c000)
#define MC_LCAM_INT_STATUS	         (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000004)
#define MC_LCAM_INT_ENABLE              (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000008)
#define MC_LCAM_CORE_INT_STATUS  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000020)
#define MC_LCAM_CORE_INT_ENABLE  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000024)
#define MC_LCAM_CORE_INT_SET         (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000028)
#define MC_LCAM_RAM_INIT_START    (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000030)
#define MC_LCAM_RAM_INIT_STATUS  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000034)
#define MC_LCAM_BG_SCAN                    (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000038)
#define MC_LCAM_RM_TRANS0               (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000048)
#define MC_LCAM_TCAM_PROFILE         (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000100)
#define MC_LCAM_TCAM_GMR                (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000140)
#define MC_LCAM_RBA_ABORT               (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x000001E0)
#define MC_LCAM_REQ_TCAM_CNT	 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x000001E4)
#define MC_LCAM_RSP_TCAM_CNT	 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000220)
#define MC_LCAM_IERR_C_INFO            (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000230)
#define MC_LCAM_IERR_U_INFO            (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000234)
#define MC_LCAM_IERR_C_TCAM_INFO   (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000238)
#define MC_LCAM_IERR_U_TCAM_INFO   (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x0000023C)
#define MC_LCAM_BAD_CMD_AA0_INFO   (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000240)
#define MC_LCAM_IERR_C_CNT                 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x0000024C)
#define MC_LCAM_IERR_U_CNT                 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000250)
#define MC_LCAM_IERR_C_TCAM_CNT     (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000254)
#define MC_LCAM_IERR_U_TCAM_CNT     (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000258)
#define MC_LCAM_TEST_DBG_CFG	    (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000600)
#define MC_LCAM_CORE_CLK_DBG_CFG  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000604)

/* CACHE ģ��Ĵ�������ַ */
#define MC_CACHE_BASE                             (0x1302b000)

/******************************************************************************/
/*                      MC CACHE �Ĵ�������                                   */
/******************************************************************************/
#define MC_CACHE_L3_CTRL_REG                      (MC_CACHE_BASE + 0x0)           /* L3_CTRLΪL3 Cache�Ŀ��ƼĴ����� */
#define MC_CACHE_L3_AUCTRL_REG                    (MC_CACHE_BASE + 0x4)           /* L3_AUCTRLΪL3 Cache�ĸ������ƼĴ����� */
#define MC_CACHE_L3_TIMEOUT_REG                   (MC_CACHE_BASE + 0x8)           /* L3_TIMEOUTΪL3 Cache������timeout���üĴ����� */
#define MC_CACHE_L3_STATUS_REG                    (MC_CACHE_BASE + 0xC)           /* L3_STATUSΪL3 Cache��״̬�Ĵ����� */
#define MC_CACHE_L3_CA_START_REG                  (MC_CACHE_BASE + 0x10)          /* L3_CA_STARTΪL3 Cache��Cacheable�ռ����ʼ��ַ�� */
#define MC_CACHE_L3_CA_END_REG                    (MC_CACHE_BASE + 0x14)          /* L3_CA_ENDΪL3 Cache��Cacheable�ռ�Ľ�����ַ�� */
#define MC_CACHE_L3_ARAM_START_REG                (MC_CACHE_BASE + 0x18)          /* L3_ARAM_STARTΪL3 Cache��Sram�İ�ȫ�洢�ռ���ʼ��ַ�� */
#define MC_CACHE_L3_ARAM_END_REG                  (MC_CACHE_BASE + 0x1C)          /* L3_ARAM_ENDΪL3 Cache��Sram�İ�ȫ�洢�ռ������ַ�� */
#define MC_CACHE_L3_SYNC_REG                      (MC_CACHE_BASE + 0x20)          /* L3_SYNCΪL3 Cache��ͬ���Ĵ����� */
#define MC_CACHE_L3_MAINT_CTRL_REG                (MC_CACHE_BASE + 0x24)          /* L3_MAINT_CTRLΪL3 Cache ����ַ clean/invalidate���������üĴ����� */
#define MC_CACHE_L3_MAINT_ADDR_REG                (MC_CACHE_BASE + 0x28)          /* L3_MAINT_ADDRΪL3 Cache ����ַ clean/invalidate���������üĴ����� */
#define MC_CACHE_L3_LOCKDOWN_REG                  (MC_CACHE_BASE + 0x2C)          /* L3_LOCKDOWNΪL3 Cache������Way���üĴ����� */
#define MC_L3_PREFETCH_REG                        (MC_CACHE_BASE + 0x30)          /* L3_PREFECTHΪL3 Cache��Ӳ��Ԥȡ�������üĴ����� */
#define MC_L3_ALLOC_FREQ_REG                      (MC_CACHE_BASE + 0x34)          /* L3_PREFECTHΪL3 Cache�Ŀ���allocate����Ƶ�ȵ����üĴ����� */
#define MC_CACHE_L3_BANK0_INTM_REG                (MC_CACHE_BASE + 0x100)         /* L3_BANK0_INTMΪBANK0���ж����μĴ����� */
#define MC_CACHE_L3_BANK0_RINT_REG                (MC_CACHE_BASE + 0x104)         /* L3_BANK0_RINTΪBANK0��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK0_INTS_REG                (MC_CACHE_BASE + 0x108)         /* L3_BANK0_INTSΪBANK0�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK0_INTC_REG                (MC_CACHE_BASE + 0x10C)         /* L3_BANK0_INTCΪBANK0���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK1_INTM_REG                (MC_CACHE_BASE + 0x110)         /* L3_BANK1_INTMΪBANK1���ж����μĴ����� */
#define MC_CACHE_L3_BANK1_RINT_REG                (MC_CACHE_BASE + 0x114)         /* L3_BANK1_RINTΪBANK1��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK1_INTS_REG                (MC_CACHE_BASE + 0x118)         /* L3_BANK1_INTSΪBANK1�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK1_INTC_REG                (MC_CACHE_BASE + 0x11C)         /* L3_BANK1_INTCΪBANK1���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK2_INTM_REG                (MC_CACHE_BASE + 0x120)         /* L3_BANK2_INTMΪBANK2���ж����μĴ����� */
#define MC_CACHE_L3_BANK2_RINT_REG                (MC_CACHE_BASE + 0x124)         /* L3_BANK2_RINTΪBANK2��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK2_INTS_REG                (MC_CACHE_BASE + 0x128)         /* L3_BANK2_INTSΪBANK2�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK2_INTC_REG                (MC_CACHE_BASE + 0x12C)         /* L3_BANK2_INTCΪBANK2���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK3_INTM_REG                (MC_CACHE_BASE + 0x130)         /* L3_BANK3_INTMΪBANK3���ж����μĴ����� */
#define MC_CACHE_L3_BANK3_RINT_REG                (MC_CACHE_BASE + 0x134)         /* L3_BANK3_RINTΪBANK3��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK3_INTS_REG                (MC_CACHE_BASE + 0x138)         /* L3_BANK3_INTSΪBANK3�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK3_INTC_REG                (MC_CACHE_BASE + 0x13C)         /* L3_BANK3_INTCΪBANK3���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK4_INTM_REG                (MC_CACHE_BASE + 0x140)         /* L3_BANK4_INTMΪBANK4���ж����μĴ����� */
#define MC_CACHE_L3_BANK4_RINT_REG                (MC_CACHE_BASE + 0x144)         /* L3_BANK4_RINTΪBANK4��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK4_INTS_REG                (MC_CACHE_BASE + 0x148)         /* L3_BANK4_INTSΪBANK4�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK4_INTC_REG                (MC_CACHE_BASE + 0x14C)         /* L3_BANK4_INTCΪBANK4���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK5_INTM_REG                (MC_CACHE_BASE + 0x150)         /* L3_BANK5_INTMΪBANK5���ж����μĴ����� */
#define MC_CACHE_L3_BANK5_RINT_REG                (MC_CACHE_BASE + 0x154)         /* L3_BANK5_RINTΪBANK5��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK5_INTS_REG                (MC_CACHE_BASE + 0x158)         /* L3_BANK5_INTSΪBANK5�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK5_INTC_REG                (MC_CACHE_BASE + 0x15C)         /* L3_BANK5_INTCΪBANK5���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK6_INTM_REG                (MC_CACHE_BASE + 0x160)         /* L3_BANK6_INTMΪBANK6���ж����μĴ����� */
#define MC_CACHE_L3_BANK6_RINT_REG                (MC_CACHE_BASE + 0x164)         /* L3_BANK6_RINTΪBANK6��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK6_INTS_REG                (MC_CACHE_BASE + 0x168)         /* L3_BANK6_INTSΪBANK6�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK6_INTC_REG                (MC_CACHE_BASE + 0x16C)         /* L3_BANK6_INTCΪBANK6���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK7_INTM_REG                (MC_CACHE_BASE + 0x170)         /* L3_BANK7_INTMΪBANK7���ж����μĴ����� */
#define MC_CACHE_L3_BANK7_RINT_REG                (MC_CACHE_BASE + 0x174)         /* L3_BANK7_RINTΪBANK7��ԭʼ�ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK7_INTS_REG                (MC_CACHE_BASE + 0x178)         /* L3_BANK7_INTSΪBANK7�����κ���ж�״̬�Ĵ����� */
#define MC_CACHE_L3_BANK7_INTC_REG                (MC_CACHE_BASE + 0x17C)         /* L3_BANK7_INTCΪBANK7���ж�����Ĵ����� */
#define MC_CACHE_L3_BANK0_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x180)         /* L3_BANK0_CNT_TYPEΪBANK0���¼��������üĴ����� */
#define MC_CACHE_L3_BANK1_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x190)         /* L3_BANK1_CNT_TYPEΪBANK1���¼��������üĴ����� */
#define MC_CACHE_L3_BANK2_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1A0)         /* L3_BANK2_CNT_TYPEΪBANK2���¼��������üĴ����� */
#define MC_CACHE_L3_BANK3_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1B0)         /* L3_BANK3_CNT_TYPEΪBANK3���¼��������üĴ����� */
#define MC_CACHE_L3_BANK4_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1C0)         /* L3_BANK4_CNT_TYPEΪBANK4���¼��������üĴ����� */
#define MC_CACHE_L3_BANK5_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1D0)         /* L3_BANK5_CNT_TYPEΪBANK5���¼��������üĴ����� */
#define MC_CACHE_L3_BANK6_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1E0)         /* L3_BANK6_CNT_TYPEΪBANK6���¼��������üĴ����� */
#define MC_CACHE_L3_BANK7_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1F0)         /* L3_BANK7_CNT_TYPEΪBANK7���¼��������üĴ����� */
#define MC_CACHE_L3_BANK0_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x200)         /* L3_BANK0_INT_CNT0ΪBANK0���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK0_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x204)         /* L3_BANK0_INT_CNT1ΪBANK0���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK0_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x208)         /* L3_BANK0_INT_CNT2ΪBANK0���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK0_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x20C)         /* L3_BANK0_INT_CNT3ΪBANK0���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK1_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x210)         /* L3_BANK1_INT_CNT0ΪBANK1���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK1_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x214)         /* L3_BANK1_INT_CNT1ΪBANK1���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK1_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x218)         /* L3_BANK1_INT_CNT2ΪBANK1���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK1_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x21C)         /* L3_BANK1_INT_CNT3ΪBANK1���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK2_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x220)         /* L3_BANK2_INT_CNT0ΪBANK2���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK2_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x224)         /* L3_BANK2_INT_CNT1ΪBANK2���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK2_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x228)         /* L3_BANK2_INT_CNT2ΪBANK2���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK2_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x22C)         /* L3_BANK2_INT_CNT3ΪBANK2���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK3_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x230)         /* L3_BANK3_INT_CNT0ΪBANK3���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK3_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x234)         /* L3_BANK3_INT_CNT1ΪBANK3���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK3_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x238)         /* L3_BANK3_INT_CNT2ΪBANK3���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK3_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x23C)         /* L3_BANK3_INT_CNT3ΪBANK3���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK4_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x240)         /* L3_BANK4_INT_CNT0ΪBANK4���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK4_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x244)         /* L3_BANK4_INT_CNT1ΪBANK4���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK4_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x248)         /* L3_BANK4_INT_CNT2ΪBANK4���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK4_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x24C)         /* L3_BANK4_INT_CNT3ΪBANK4���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK5_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x250)         /* L3_BANK5_INT_CNT0ΪBANK5���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK5_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x254)         /* L3_BANK5_INT_CNT1ΪBANK5���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK5_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x258)         /* L3_BANK5_INT_CNT2ΪBANK5���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK5_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x25C)         /* L3_BANK5_INT_CNT3ΪBANK5���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK6_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x260)         /* L3_BANK6_INT_CNT0ΪBANK6���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK6_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x264)         /* L3_BANK6_INT_CNT1ΪBANK6���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK6_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x268)         /* L3_BANK6_INT_CNT2ΪBANK6���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK6_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x26C)         /* L3_BANK6_INT_CNT3ΪBANK6���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK7_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x270)         /* L3_BANK7_INT_CNT0ΪBANK7���¼�ͳ�ƼĴ���0�� */
#define MC_CACHE_L3_BANK7_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x274)         /* L3_BANK7_INT_CNT1ΪBANK7���¼�ͳ�ƼĴ���1�� */
#define MC_CACHE_L3_BANK7_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x278)         /* L3_BANK7_INT_CNT2ΪBANK7���¼�ͳ�ƼĴ���2�� */
#define MC_CACHE_L3_BANK7_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x27C)         /* L3_BANK7_INT_CNT3ΪBANK7���¼�ͳ�ƼĴ���3�� */
#define MC_CACHE_L3_BANK0_TRAM_ECC_REG            (MC_CACHE_BASE + 0x300)         /* L3_BANK0_TRAM_ECCΪBANK0 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK0_DRAM_ECC_REG            (MC_CACHE_BASE + 0x304)         /* L3_BANK0_DRAM_ECCΪ BANK0 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK0_ECC_INJECT_REG          (MC_CACHE_BASE + 0x308)         /* L3_BANK0_ECC_INJECTΪBANK0��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK1_TRAM_ECC_REG            (MC_CACHE_BASE + 0x310)         /* L3_BANK1_TRAM_ECCΪBANK1 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK1_DRAM_ECC_REG            (MC_CACHE_BASE + 0x314)         /* L3_BANK1_DRAM_ECCΪ BANK1 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK1_ECC_INJECT_REG          (MC_CACHE_BASE + 0x318)         /* L3_BANK1_ECC_INJECTΪBANK1��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK2_TRAM_ECC_REG            (MC_CACHE_BASE + 0x320)         /* L3_BANK2_TRAM_ECCΪBANK2 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK2_DRAM_ECC_REG            (MC_CACHE_BASE + 0x324)         /* L3_BANK2_DRAM_ECCΪ BANK2 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK2_ECC_INJECT_REG          (MC_CACHE_BASE + 0x328)         /* L3_BANK2_ECC_INJECTΪBANK2��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK3_TRAM_ECC_REG            (MC_CACHE_BASE + 0x330)         /* L3_BANK3_TRAM_ECCΪBANK3 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK3_DRAM_ECC_REG            (MC_CACHE_BASE + 0x334)         /* L3_BANK3_DRAM_ECCΪ BANK3 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK3_ECC_INJECT_REG          (MC_CACHE_BASE + 0x338)         /* L3_BANK3_ECC_INJECTΪBANK3��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK4_TRAM_ECC_REG            (MC_CACHE_BASE + 0x340)         /* L3_BANK4_TRAM_ECCΪBANK4 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK4_DRAM_ECC_REG            (MC_CACHE_BASE + 0x344)         /* L3_BANK4_DRAM_ECCΪ BANK4 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK4_ECC_INJECT_REG          (MC_CACHE_BASE + 0x348)         /* L3_BANK4_ECC_INJECTΪBANK4��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK5_TRAM_ECC_REG            (MC_CACHE_BASE + 0x350)         /* L3_BANK5_TRAM_ECCΪBANK5 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK5_DRAM_ECC_REG            (MC_CACHE_BASE + 0x354)         /* L3_BANK5_DRAM_ECCΪ BANK5 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK5_ECC_INJECT_REG          (MC_CACHE_BASE + 0x358)         /* L3_BANK5_ECC_INJECTΪBANK5��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK6_TRAM_ECC_REG            (MC_CACHE_BASE + 0x360)         /* L3_BANK6_TRAM_ECCΪBANK6 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK6_DRAM_ECC_REG            (MC_CACHE_BASE + 0x364)         /* L3_BANK6_DRAM_ECCΪ BANK6 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK6_ECC_INJECT_REG          (MC_CACHE_BASE + 0x368)         /* L3_BANK6_ECC_INJECTΪBANK6��ECC����ע��Ĵ����� */
#define MC_CACHE_L3_BANK7_TRAM_ECC_REG            (MC_CACHE_BASE + 0x370)         /* L3_BANK7_TRAM_ECCΪBANK7 Tag Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK7_DRAM_ECC_REG            (MC_CACHE_BASE + 0x374)         /* L3_BANK7_DRAM_ECCΪ BANK7 Data Ram���һ��ECC����λ����Ϣ�� */
#define MC_CACHE_L3_BANK7_ECC_INJECT_REG          (MC_CACHE_BASE + 0x378)         /* L3_BANK7_ECC_INJECTΪBANK7��ECC����ע��Ĵ����� */


/*LMEM �Ĵ�������*/

#define MC_LMEM_OFFSET  (0x4000)

#define MC_LMEM_CFG_128BIT0_WORD0     (MC_SPPE_REG_BASE  + 0x04000000)
#define MC_LMEM_CFG_128BIT0_WORD1     (MC_SPPE_REG_BASE  + 0x04000004)
#define MC_LMEM_CFG_128BIT0_WORD2     (MC_SPPE_REG_BASE  + 0x04000008)
#define MC_LMEM_CFG_128BIT0_WORD3     (MC_SPPE_REG_BASE  + 0x0400000C)

#define MC_LMEM_GP_32BIT_RW0          (MC_SPPE_REG_BASE  + 0x05200000)
#define MC_LMEM_GP_32BIT_CAR0         (MC_SPPE_REG_BASE  + 0x05400000)
#define MC_LMEM_GP_64BIT_RW0_WORD0    (MC_SPPE_REG_BASE  + 0x05600000)
#define MC_LMEM_GP_64BIT_RW0_WORD1    (MC_SPPE_REG_BASE  + 0x05600004)

#define MC_LMEM_GP_64BIT_CAR0_WORD0   (MC_SPPE_REG_BASE  + 0x05800000)

#define MC_LMEM_GP_128BIT_RW0_WORD0   (MC_SPPE_REG_BASE  + 0x05A00000)
#define MC_LMEM_GP_128BIT_RW0_WORD1   (MC_SPPE_REG_BASE  + 0x05A00004)
#define MC_LMEM_GP_128BIT_RW0_WORD2   (MC_SPPE_REG_BASE  + 0x05A00008)
#define MC_LMEM_GP_128BIT_RW0_WORD3   (MC_SPPE_REG_BASE  + 0x05A0000C)

#define MC_LMEM_GP_128BIT_CAR_WORD0   (MC_SPPE_REG_BASE  + 0x05C00000)


#define MC_LMEM_INT_ENABLE               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000808)
#define MC_LMEM_INT_STATUS               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000804)
#define MC_LMEM_INT_SET                  (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000080C)
#define MC_LMEM_IERR_F_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000820)
#define MC_LMEM_IERR_L_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000824)
#define MC_LMEM_IERR_U_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000828)
#define MC_LMEM_IERR_C_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000082C)
#define MC_LMEM_BAD_CMD_INFO             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000830)
#define MC_LMEM_PH_ERR_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000834)
#define MC_LMEM_FS_ERR_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000838)
#define MC_LMEM_Q_OVFL_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000083C)
#define MC_LMEM_NCP_OVFL_INFO            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000840)
#define MC_LMEM_IERR_L_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000850)
#define MC_LMEM_IERR_U_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000854)
#define MC_LMEM_IERR_C_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000858)
#define MC_LMEM_BAD_CMD_CNT              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000085C)
#define MC_LMEM_PH_ERR_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000860)
#define MC_LMEM_FS_ERR_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000864)
#define MC_LMEM_Q_OVFL_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000868)
#define MC_LMEM_SE_OVFL_CNT              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000086C)
#define SRE_LMEM_TM_OVFL_CNT              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000870)
#define MC_LMEM_NCP_OVFL_CNT             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000874)
#define MC_LMEM_ABORT_ERR_CNT            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000878)
#define MC_LMEM_IERR_U_DATA              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000880)
#define MC_LMEM_RAM_INIT_START           (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008A0)
#define MC_LMEM_RAM_INIT_STATUS          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008A4)
#define MC_LMEM_CFG_MEM_OFFSET           (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008B0)
#define MC_LMEM_CFG_MEM_IND_OFFSET       (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008B4)
#define MC_LMEM_CFG_MEM_POL_OFFSET       (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008B8)
#define MC_LMEM_CFG_MEM_Q_OFFSET         (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008BC)
#define MC_LMEM_CFG_MEM_SEM_OFFSET       (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008C0)
#define MC_LMEM_POL_SYS_TIMER            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008D0)
#define MC_LMEM_POL_TICK_CNT             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008D8)
#define MC_LMEM_POL_VIRTUAL_TH           (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008DC)
#define MC_LMEM_STAT_TS_DIV              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008F0)
#define MC_LMEM_ADDNCP_ADDR_MOD          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000900)
#define MC_LMEM_CLEARBIT_ADDR_MOD        (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000904)
#define MC_LMEM_MS0_EMEM_NCP_ADDR_MOD    (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000910)
#define MC_LMEM_DBG_BP_CFG               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B00)
#define MC_LMEM_DBG_FIFO_TH0             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B04)
#define MC_LMEM_DBG_FIFO_TH1             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B08)
#define MC_LMEM_DBG_FIFO_TH2             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B0C)
#define MC_LMEM_DBG_FIFO_OVFL            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B10)
#define MC_LMEM_DBG_STATUS               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B14)
#define MC_LMEM_DBG_NCF_FIFO             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B18)
#define MC_LMEM_DIAG_CTL                 (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C00)
#define MC_LMEM_DIAG_INTRV_R             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C04)
#define MC_LMEM_DIAG_INTRV_W             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C08)
#define MC_LMEM_DIAG_CNT_RBA_REQ         (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C0C)
#define MC_LMEM_DIAG_CNT_RBA_RSP         (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C10)
#define MC_LMEM_DIAG_CNT_EMEM_REQ        (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C14)
#define MC_LMEM_DIAG_CNT_SE_REQ          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C18)
#define SRE_LMEM_DIAG_CNT_TM_REQ          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C1C)
#define MC_LMEM_DIAG_CNT_MS0             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C20)
#define MC_LMEM_TIMING                   (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C40)
#define MC_LMEM_POWER1                   (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C44)
#define MC_LMEM_POWER2                   (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C48)
#define MC_LMEM_ICG                      (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C4C)

/* TM ģ��Ĵ�������ַ */
#if 0         /* z00202052 */
#define SRE_TM_BASE                             (0x11800000)
#else
#define SRE_TM_BASE                             (0xe1800000)
#endif        /* z00202052 */

/******************************************************************************/
/*                      TM �Ĵ�������                                      */
/******************************************************************************/
#define SRE_TM_RSV0_REG                         (SRE_TM_BASE + 0x0)              /* TMԤ���Ĵ���0 */
#define SRE_TM_RSV1_REG                         (SRE_TM_BASE + 0x4)              /* TMԤ���Ĵ���1 */
#define SRE_TM_RSV2_REG                         (SRE_TM_BASE + 0x8)              /* TMԤ���Ĵ���2 */
#define SRE_TM_RSV3_REG                         (SRE_TM_BASE + 0xC)              /* TMԤ���Ĵ���3 */
#define SRE_TM_CFG_OK_REG                       (SRE_TM_BASE + 0x10)             /* TM���ý����Ĵ��� */
#define SRE_TM_DROP_FIFO_THR_REG                (SRE_TM_BASE + 0x14)             /* TM����FIFO����ͻض�ˮ�� */
#define SRE_TM_ENDIEN_CTRL_REG                  (SRE_TM_BASE + 0x18)             /* TM����DDR��С��ģʽ���ƼĴ��� */
#define SRE_TM_RAM_CFG_ERR_INST_REG             (SRE_TM_BASE + 0x1C)             /* TM_RAM_CFGģ�����ֲ��Ĵ��� */
#define SRE_TM_OTHER_ERR_INST_REG               (SRE_TM_BASE + 0x20)             /* TM_OTHER ģ�����ֲ��Ĵ��� */
#define SRE_TM_CF_OUT_DEPTH_REG                 (SRE_TM_BASE + 0x24)             /* TM MST��outstanding��ȼĴ��� */
#define SRE_TM_CF_INTER_CNT_REG                 (SRE_TM_BASE + 0x28)             /* TM MST��AXI����ERROR�ش�ʱ�����üĴ��� */
#define SRE_TM_CF_FAIL_CNT_REG                  (SRE_TM_BASE + 0x2C)             /* TM MST��AXI�����ش����ô����ϱ��жϼĴ��� */
#define SRE_TM_CF_TIMEOUT_REG                   (SRE_TM_BASE + 0x30)             /* TM MST�ش����������ж��ϱ�δ�����ʱʱ�����üĴ��� */
#define SRE_TM_TOKEN_BS_MODE_REG                (SRE_TM_BASE + 0x34)             /* ����Ͱ��ʼ��ģʽ�Ĵ��� */
#define SRE_TM_RFS_MEM_TIMING_CTRL_REG          (SRE_TM_BASE + 0x38)             /* TM RFS�� MEMʱ������ź� */
#define SRE_TM_RAS_MEM_TIMING_CTRL_REG          (SRE_TM_BASE + 0x3C)             /* TM_RAS�� MEMʱ������ź� */
#define SRE_TM_RAS_HD_POWER_CTRL_REG            (SRE_TM_BASE + 0x40)             /* TM RAS_HD��MEM��Դ�����ź� */
#define SRE_TM_STORE_CFG_SPACE_REG              (SRE_TM_BASE + 0x44)             /* TM �����������ռ����üĴ��� */
#define SRE_TM_WRED_TS_SEL_REG                  (SRE_TM_BASE + 0x48)             /* TM WRED���������ѡ�����üĴ��� */
#define SRE_TM_HAC_USER_REG                     (SRE_TM_BASE + 0x4C)             /* TM���͸�����������ʱʹ��USER */
#define SRE_TM_OWEN_USER_REG                    (SRE_TM_BASE + 0x50)             /* TM�ڲ��Լ�ʹ��USER */
#define SRE_TM_ECC_BYPASS_REG                   (SRE_TM_BASE + 0x54)             /* TM_ECC_BYPASS�Ĵ��� */
#define SRE_TM_SLV_OTD_CHK_BYPASS_REG           (SRE_TM_BASE + 0x58)             /* TM�ڲ�SLV��OUT */
#define SRE_TM_VM_BYPASS_REG                    (SRE_TM_BASE + 0x5C)             /* TM_���⻯BYPASS�Ĵ��� */
#define SRE_TM_ACK_SPPE_BP_MODE_REG             (SRE_TM_BASE + 0x60)             /* TM��ӦSPPEͳ�Ʒ�ѹ���ƼĴ��� */
#define SRE_TM_VMID_MAP_TAB1_REG                (SRE_TM_BASE + 0x100)            /* ���⻯VMIDӳ���1 */
#define SRE_TM_VMID_MAP_TAB2_REG                (SRE_TM_BASE + 0x104)            /* ���⻯VMIDӳ���2 */
#define SRE_TM_VM_QID_MAP_TAB_0_REG             (SRE_TM_BASE + 0x108)            /* ���⻯VM��Ӧ����������Ϣ�� */
#define SRE_TM_VM_QID_MAP_TAB_1_REG             (SRE_TM_BASE + 0x10C)            /* ���⻯VM��Ӧ����������Ϣ�� */
#define SRE_TM_VM_QERR_INTMSK_REG               (SRE_TM_BASE + 0x148)            /* ���⻯���кŲ��������ж����μĴ��� */
#define SRE_TM_VM_QERR_RINT_REG                 (SRE_TM_BASE + 0x14C)            /* ���⻯���кŲ�������ԭʼ�жϼĴ��� */
#define SRE_TM_VM_QERR_INTSTS_REG               (SRE_TM_BASE + 0x150)            /* ���⻯���кŲ��������ж�״̬�Ĵ��� */
#define SRE_TM_VM_QERR_ID_0_REG                 (SRE_TM_BASE + 0x154)            /* ���⻯���кŲ��������жϴ������ID�żĴ��� */
#define SRE_TM_VM_QERR_ID_1_REG                 (SRE_TM_BASE + 0x158)            /* ���⻯���кŲ��������жϴ������ID�żĴ��� */
#define SRE_TM_RSV4_REG                         (SRE_TM_BASE + 0x200)            /* TMԤ���Ĵ���4 */
#define SRE_TM_RSV5_REG                         (SRE_TM_BASE + 0x204)            /* TMԤ���Ĵ���5 */
#define SRE_TM_RSV6_REG                         (SRE_TM_BASE + 0x208)            /* TMԤ���Ĵ���6 */
#define SRE_TM_RSV7_REG                         (SRE_TM_BASE + 0x20C)            /* TMԤ���Ĵ���7 */
#define SRE_TM_FQ_RLS_CNT_REG                   (SRE_TM_BASE + 0x25C)            /* TM FQ���� �ͷſյ��ȸ��������� */
#define SRE_TM_COM_RLS_CNT_REG                  (SRE_TM_BASE + 0x260)            /* TM COM���� �ͷſյ��ȸ��������� */
#define SRE_TM_LOC_RLS_CNT_REG                  (SRE_TM_BASE + 0x264)            /* TM LOC���� �ͷſյ��ȸ��������� */
#define SRE_TM_QUEUE_SHAP_FSM3_PRB_REG          (SRE_TM_BASE + 0x268)            /* QUEUE_SHAP״̬��̽��3 */
#define SRE_TM_QUEUE_SHAP_FSM2_PRB_REG          (SRE_TM_BASE + 0x26C)            /* QUEUE_SHAP״̬��̽��2 */
#define SRE_TM_QUEUE_SHAP_FSM1_PRB_REG          (SRE_TM_BASE + 0x270)            /* QUEUE_SHAP״̬��̽��1 */
#define SRE_TM_QUEUE_DROP_FSM_PRB_REG           (SRE_TM_BASE + 0x274)            /* TM_SLV״̬��̽�� */
#define SRE_TM_QUEUE_TK_FSM_PRB_REG             (SRE_TM_BASE + 0x278)            /* QUEUE_TK״̬��̽�� */
#define SRE_TM_SLV_FSM_PRB_REG                  (SRE_TM_BASE + 0x27C)            /* TM_SLV״̬��̽�� */
#define SRE_TM_QUEUE_STA_FSM1_PRB_REG           (SRE_TM_BASE + 0x280)            /* QUEUE_STA״̬��̽��1 */
#define SRE_TM_QUEUE_STA_FSM2_PRB_REG           (SRE_TM_BASE + 0x284)            /* QUEUE_STA״̬��̽��2 */
#define SRE_TM_QUEUE_SCH_FSM_PRB_REG            (SRE_TM_BASE + 0x288)            /* QUEUE_SCH״̬��̽�� */
#define SRE_TM_QUEUE_M_FSM_PRB_REG              (SRE_TM_BASE + 0x28C)            /* QUEUE_M״̬��̽�� */
#define SRE_TM_FREE_PTR_CNT_REG                 (SRE_TM_BASE + 0x290)            /* TMʣ��FREE BUFָ������� */
#define SRE_TM_MST_CNT_EN_REG                   (SRE_TM_BASE + 0x294)            /* MST���ڲ�ͨ��ͳ��ʹ�ܱ�־ */
#define SRE_TM_MST_CNT_CLR_REG                  (SRE_TM_BASE + 0x298)            /* MST���ڲ�ͨ��ͳ������ź� */
#define SRE_TM_MST_LATENCY_AVG_REG              (SRE_TM_BASE + 0x29C)            /* MST��ƽ����ʱ�Ĵ��� */
#define SRE_TM_MST_LATENCY_MAX_REG              (SRE_TM_BASE + 0x2A0)            /* MST�������ʱ�Ĵ��� */
#define SRE_TM_MST_RD_ACC_REG                   (SRE_TM_BASE + 0x2A4)            /* MST�ڶ������� */
#define SRE_TM_MST_WR_ACC_REG                   (SRE_TM_BASE + 0x2A8)            /* MST��д������ */
#define SRE_TM_MST_RD_OTD_1_REG                 (SRE_TM_BASE + 0x2AC)            /* MST�ڶ�outstanding������1 */
#define SRE_TM_MST_RD_OTD_2_REG                 (SRE_TM_BASE + 0x2B0)            /* MST�ڶ�outstanding������2 */
#define SRE_TM_MST_WR_OTD_1_REG                 (SRE_TM_BASE + 0x2B4)            /* MST��дoutstanding������1 */
#define SRE_TM_MST_WR_OTD_2_REG                 (SRE_TM_BASE + 0x2B8)            /* MST��дoutstanding������2 */
#define SRE_TM_PORT_SEND_DATA_DFX_0_REG         (SRE_TM_BASE + 0x2BC)            /* TM PORT��������̽�� */
#define SRE_TM_PORT_SEND_DATA_DFX_1_REG         (SRE_TM_BASE + 0x2C0)            /* TM PORT��������̽�� */
#define SRE_TM_SPPE_BP_REG                      (SRE_TM_BASE + 0x2FC)            /* SPPE��TM��ѹ̽��Ĵ��� */
#define SRE_TM_MPE_BP_REG                       (SRE_TM_BASE + 0x300)            /* MPE��TM��ѹ̽��Ĵ��� */
#define SRE_TM_PPE_BP_REG                       (SRE_TM_BASE + 0x304)            /* PPE��TM��ѹ̽��Ĵ��� */
#define SRE_TM_POE_BP_REG                       (SRE_TM_BASE + 0x308)            /* POE��TM��ѹ̽���ź� */
#define SRE_TM_CPU_ADD_WORD0_REG                (SRE_TM_BASE + 0x30C)            /* CPUдTMģ��msg WORD0 */
#define SRE_TM_CPU_ADD_WORD1_REG                (SRE_TM_BASE + 0x310)            /* CPUдTMģ��msg WORD1 */
#define SRE_TM_CPU_ADD_WORD2_REG                (SRE_TM_BASE + 0x314)            /* CPUдTMģ��msg WORD2 */
#define SRE_TM_CPU_ADD_WORD3_REG                (SRE_TM_BASE + 0x318)            /* CPUдTMģ��msg WORD3 */
#define SRE_TM_ACC_ADD_WORD0_REG                (SRE_TM_BASE + 0x31C)            /* ������дTMģ��msg WORD0 */
#define SRE_TM_ACC_ADD_WORD1_REG                (SRE_TM_BASE + 0x320)            /* ������дTMģ��msg WORD1 */
#define SRE_TM_ACC_ADD_WORD2_REG                (SRE_TM_BASE + 0x324)            /* ������дTMģ��msg WORD2 */
#define SRE_TM_ACC_ADD_WORD3_REG                (SRE_TM_BASE + 0x328)            /* ������дTMģ��msg WORD3 */
#define SRE_TM_MST_SEND_TIMES_INTMSK_REG        (SRE_TM_BASE + 0x32C)            /* MST���ʹ�����������ֵ�ж�����Ĵ��� */
#define SRE_TM_MST_SEND_TIMES_RINT_REG          (SRE_TM_BASE + 0x330)            /* MST���ʹ�����������ֵԭʼ�жϼĴ��� */
#define SRE_TM_MST_SEND_TIMES_INTSTS_REG        (SRE_TM_BASE + 0x334)            /* MST���ʹ�����������ֵ�ж�״̬�Ĵ��� */
#define SRE_TM_BIND_ERR_INTMSK_REG              (SRE_TM_BASE + 0x338)            /* �˿ڲ��ڰ󶨹�ϵ�ж����μĴ��� */
#define SRE_TM_BIND_ERR_RINT_REG                (SRE_TM_BASE + 0x33C)            /* �˿ڲ��ڰ󶨹�ϵԭʼ�жϼĴ��� */
#define SRE_TM_BIND_ERR_INTSTS_REG              (SRE_TM_BASE + 0x340)            /* �˿ڲ��ڰ󶨹�ϵ�жϼĴ���״̬�Ĵ��� */
#define SRE_TM_BIND_TK_ERR_STS1_REG             (SRE_TM_BASE + 0x344)            /* �˿ڲ��ڰ󶨹�ϵ��ӦTK�˿ڼĴ���1 */
#define SRE_TM_BIND_TK_ERR_STS2_REG             (SRE_TM_BASE + 0x348)            /* �˿ڲ��ڰ󶨹�ϵ��ӦTK�˿ڼĴ���2 */
#define SRE_TM_PORT_FIFO_INTMSK_REG             (SRE_TM_BASE + 0x350)            /* TM_PORT_FIFOģ���ж����μĴ��� */
#define SRE_TM_PORT_FIFO_RINT_REG               (SRE_TM_BASE + 0x354)            /* TM_PORT_FIFOԭʼ�жϼĴ��� */
#define SRE_TM_PORT_FIFO_INTSTS_REG             (SRE_TM_BASE + 0x358)            /* TM_PORT_FIFO���κ��ж�״̬�Ĵ��� */
#define SRE_TM_FIFO1_INTMSK_REG                 (SRE_TM_BASE + 0x35C)            /* TM_FIFO��һ����ģ���ж����μĴ��� */
#define SRE_TM_FIFO1_RINT_REG                   (SRE_TM_BASE + 0x360)            /* TM_FIFO��һ����ԭʼ�жϼĴ��� */
#define SRE_TM_FIFO1_INTSTS_REG                 (SRE_TM_BASE + 0x364)            /* TM_FIFO��һ�������κ��ж�״̬�Ĵ��� */
#define SRE_TM_FIFO2_INTMSK_REG                 (SRE_TM_BASE + 0x368)            /* TM_FIFO�ڶ�����ģ���ж����μĴ��� */
#define SRE_TM_FIFO2_RINT_REG                   (SRE_TM_BASE + 0x36C)            /* TM_FIFO�ڶ�����ԭʼ�жϼĴ��� */
#define SRE_TM_FIFO2_INTSTS_REG                 (SRE_TM_BASE + 0x370)            /* TM_FIFO�ڶ��������κ��ж�״̬�Ĵ��� */
#define SRE_TM_FIFO3_INTMSK_REG                 (SRE_TM_BASE + 0x374)            /* TM_FIFO��������ģ���ж����μĴ��� */
#define SRE_TM_FIFO3_RINT_REG                   (SRE_TM_BASE + 0x378)            /* TM_FIFO��������ԭʼ�жϼĴ��� */
#define SRE_TM_FIFO3_INTSTS_REG                 (SRE_TM_BASE + 0x37C)            /* TM_FIFO�����������κ��ж�״̬�Ĵ��� */
#define SRE_TM_QUEUE_M_FIFO_DFX_REG             (SRE_TM_BASE + 0x380)            /* QUEUE_M ģ��FIFO DFX�Ĵ��� */
#define SRE_TM_QUEUE_SHAP_FIFO_DFX_REG          (SRE_TM_BASE + 0x384)            /* QUEUE SHAPģ��FIFO DFX�Ĵ��� */
#define SRE_TM_SLV_FIFO_DFX_REG                 (SRE_TM_BASE + 0x388)            /* AXI SLVģ��FIFO DFX�Ĵ��� */
#define SRE_TM_QUEUE_TK_FIFO_DFX_REG            (SRE_TM_BASE + 0x38C)            /* QUEUE_TK ģ��FIFO DFX�Ĵ��� */
#define SRE_TM_PORT_FIFO_DFX_REG                (SRE_TM_BASE + 0x390)            /* TM_PORT_FIFO DFX�Ĵ��� */
#define SRE_TM_QUEUE_SCH_FIFO_DFX_REG           (SRE_TM_BASE + 0x394)            /* QUEUE_SCH ģ��FIFO DFX�Ĵ��� */
#define SRE_TM_QUEUE_STA_FIFO_DFX_REG           (SRE_TM_BASE + 0x398)            /* QUEUE_STA ģ��FIFO DFX�Ĵ��� */
#define SRE_TM_OTHER_FIFO_DFX_REG               (SRE_TM_BASE + 0x39C)            /* TM OTHERģ��FIFO DFX�Ĵ��� */
#define SRE_TM_CPU_ADDPKT_CNT_REG               (SRE_TM_BASE + 0x3A0)            /* TM CPU�ɹ���Ӱ�������������� */
#define SRE_TM_ACC_ADDPKT_CNT_REG               (SRE_TM_BASE + 0x3A4)            /* TM �������ɹ���Ӱ�������������� */
#define SRE_TM_QM2TK_PKT_CNT_REG                (SRE_TM_BASE + 0x3A8)            /* TM���й���ģ�������Trunkģ������������� */
#define SRE_TM_NOTEN_DROP_CNT_REG               (SRE_TM_BASE + 0x3AC)            /* TM ���в�ʹ�ܶ���������ͳ�Ƽ����� */
#define SRE_TM_WRED_DROP_CNT_REG                (SRE_TM_BASE + 0x3B0)            /* TM ����WRED/TAIL����������ͳ�Ƽ����� */
#define SRE_TM_NOBUF_DROP_CNT_REG               (SRE_TM_BASE + 0x3B4)            /* TM ���л���ռ�������������ͳ�Ƽ����� */
#define SRE_TM_OUTPORT_DROP_CNT_REG             (SRE_TM_BASE + 0x3B8)            /* TM ����ָ���˿ڶ�������ͳ�ƼĴ��� */
#define SRE_TM_SPPE_PPE_DROP_CNT_REG            (SRE_TM_BASE + 0x3BC)            /* TM ����SPPE/PPE����������ͳ�Ƽ����� */
#define SRE_TM_PORT0_SEND_CNT_REG               (SRE_TM_BASE + 0x3C0)            /* TM PORT0���Ͱ����Ĵ��� */
#define SRE_TM_PORT1_SEND_CNT_REG               (SRE_TM_BASE + 0x3C4)            /* TM PORT1���Ͱ����Ĵ��� */
#define SRE_TM_PORT2_SEND_CNT_REG               (SRE_TM_BASE + 0x3C8)            /* TM PORT2���Ͱ����Ĵ��� */
#define SRE_TM_PORT3_SEND_CNT_REG               (SRE_TM_BASE + 0x3CC)            /* TM PORT3���Ͱ����Ĵ��� */
#define SRE_TM_PORT4_SEND_CNT_REG               (SRE_TM_BASE + 0x3D0)            /* TM PORT4���Ͱ����Ĵ��� */
#define SRE_TM_PORT5_SEND_CNT_REG               (SRE_TM_BASE + 0x3D4)            /* TM PORT5���Ͱ����Ĵ��� */
#define SRE_TM_PORT6_SEND_CNT_REG               (SRE_TM_BASE + 0x3D8)            /* TM PORT6���Ͱ����Ĵ��� */
#define SRE_TM_PORT7_SEND_CNT_REG               (SRE_TM_BASE + 0x3DC)            /* TM PORT7���Ͱ����Ĵ��� */
#define SRE_TM_PORT8_SEND_CNT_REG               (SRE_TM_BASE + 0x3E0)            /* TM PORT8���Ͱ����Ĵ��� */
#define SRE_TM_PORT9_SEND_CNT_REG               (SRE_TM_BASE + 0x3E4)            /* TM PORT9���Ͱ����Ĵ��� */
#define SRE_TM_PORT10_SEND_CNT_REG              (SRE_TM_BASE + 0x3E8)            /* TM PORT10���Ͱ����Ĵ��� */
#define SRE_TM_PORT11_SEND_CNT_REG              (SRE_TM_BASE + 0x3EC)            /* TM PORT11���Ͱ����Ĵ��� */
#define SRE_TM_PORT12_SEND_CNT_REG              (SRE_TM_BASE + 0x3F0)            /* TM PORT12���Ͱ����Ĵ��� */
#define SRE_TM_PORT13_SEND_CNT_REG              (SRE_TM_BASE + 0x3F4)            /* TM PORT13���Ͱ����Ĵ��� */
#define SRE_TM_PORT14_SEND_CNT_REG              (SRE_TM_BASE + 0x3F8)            /* TM PORT14���Ͱ����Ĵ��� */
#define SRE_TM_PORT15_SEND_CNT_REG              (SRE_TM_BASE + 0x3FC)            /* TM PORT15���Ͱ����Ĵ��� */
#define SRE_TM_STA_CNT_CLR_REG                  (SRE_TM_BASE + 0x414)            /* TM����Ĵ�������ź����üĴ��� */
#define SRE_TM_RAM_INIT_DONE_REG                (SRE_TM_BASE + 0x418)            /* TM�ڲ�RAM��ʼ�����ָʾ�Ĵ��� */
#define SRE_TM_TOKEN_INIT_DONE_REG              (SRE_TM_BASE + 0x41C)            /* TMʣ������Ͱ��ʼ�����ָʾ�Ĵ��� */
#define SRE_TM_PKT_VLD_CORE_0_REG               (SRE_TM_BASE + 0x420)            /* Core����Ƿ�ɹ��Ĵ��� */
#define SRE_TM_PKT_VLD_CORE_1_REG               (SRE_TM_BASE + 0x424)            /* Core����Ƿ�ɹ��Ĵ��� */
#define SRE_TM_SOLE_CNT_REG                     (SRE_TM_BASE + 0x530)            /* TM���ж���ռ��С�Ĵ��� */
#define SRE_TM_ACTIVE_USE_REG                   (SRE_TM_BASE + 0x534)            /* TMʹ�ö������Ĵ��� */
#define SRE_TM_DROP_OVERFLOW_ADDR_REG           (SRE_TM_BASE + 0x538)            /* TM�����������DDR����ַ�Ĵ��� */
#define SRE_TM_DROP_QDEPTH_REG                  (SRE_TM_BASE + 0x53C)            /* TM�������������� */
#define SRE_TM_WRED_RANDOM_INIT_REG             (SRE_TM_BASE + 0x540)            /* TM WRED�������ʼֵ */
#define SRE_TM_PORT_DROP_EN_REG                 (SRE_TM_BASE + 0x544)            /* TMָ���˿ڶ����Ĵ��� */
#define SRE_TM_BMU_BUF_REG                      (SRE_TM_BASE + 0x548)            /* TM �����ͷ�BMU BUFFER����ַ�Ĵ��� */
#define SRE_TM_WEIGHT_OFFSET_REG                (SRE_TM_BASE + 0x54C)            /* TMȨ��ƫ�ƼĴ��� */
#define SRE_TM_TK_BIND_TAB_0_REG                (SRE_TM_BASE + 0x550)            /* TRUNK�󶨱� */
#define SRE_TM_TK_BIND_TAB_1_REG                (SRE_TM_BASE + 0x554)            /* TRUNK�󶨱� */
#define SRE_TM_PORT_WADDR_0_REG                 (SRE_TM_BASE + 0x590)            /* TM���Ͷ˿ڵ�ַ�Ĵ��� */
#define SRE_TM_PORT_WADDR_1_REG                 (SRE_TM_BASE + 0x594)            /* TM���Ͷ˿ڵ�ַ�Ĵ��� */
#define SRE_TM_PORT_PART_DESC_0_REG             (SRE_TM_BASE + 0x5D0)            /* TM���Ͷ˿�������������üĴ����Ĵ��� */
#define SRE_TM_PORT_PART_DESC_1_REG             (SRE_TM_BASE + 0x5D4)            /* TM���Ͷ˿�������������üĴ����Ĵ��� */
#define SRE_TM_PORT_SEND_TYPE_0_REG             (SRE_TM_BASE + 0x610)            /* TM�˿ڷ������Ա� */
#define SRE_TM_PORT_SEND_TYPE_1_REG             (SRE_TM_BASE + 0x614)            /* TM�˿ڷ������Ա� */
#define SRE_TM_TK_IR_TAB_0_REG                  (SRE_TM_BASE + 0x650)            /* Trunk�˿����ʲ����� */
#define SRE_TM_TK_IR_TAB_1_REG                  (SRE_TM_BASE + 0x654)            /* Trunk�˿����ʲ����� */
#define SRE_TM_WRED_OFFSET_REG                  (SRE_TM_BASE + 0x690)            /* WRED����ƫ�ƼĴ��� */
#define SRE_TM_DEF_PORT_0_REG                   (SRE_TM_BASE + 0x694)            /* TMĬ�϶˿ڼĴ��� */
#define SRE_TM_DEF_PORT_1_REG                   (SRE_TM_BASE + 0x698)            /* TMĬ�϶˿ڼĴ��� */
#define SRE_TM_TK_SOFT_BP_REG                   (SRE_TM_BASE + 0x6D4)            /* TM�������TK�����÷�ѹ�Ĵ��� */
#define SRE_TM_NODE_CODE_REG                    (SRE_TM_BASE + 0x6DC)            /* TM��ϢԴ�豸�� */
#define SRE_TM_RAM_CFG_INTMSK_REG               (SRE_TM_BASE + 0x700)            /* TM_RAM_CFGģ���ж����μĴ��� */
#define SRE_TM_RAM_CFG_RINT_REG                 (SRE_TM_BASE + 0x704)            /* TM_RAM_CFGԭʼ�жϼĴ��� */
#define SRE_TM_RAM_CFG_INTSTS_REG               (SRE_TM_BASE + 0x708)            /* TM_OTHER���κ��ж�״̬�Ĵ��� */
#define SRE_TM_OTHER_INTMSK_REG                 (SRE_TM_BASE + 0x70C)            /* TM_OTHERģ���ж����μĴ��� */
#define SRE_TM_OTHER_RINT_REG                   (SRE_TM_BASE + 0x710)            /* TM_OTHERԭʼ�жϼĴ��� */
#define SRE_TM_OTHER_INTSTS_REG                 (SRE_TM_BASE + 0x714)            /* TM_OTHER���κ��ж�״̬�Ĵ��� */
#define SRE_TM_ANOTHER_INTMSK_REG               (SRE_TM_BASE + 0x718)            /* TM_ANOTHERģ���ж����μĴ��� */
#define SRE_TM_ANOTHER_RINT_REG                 (SRE_TM_BASE + 0x71C)            /* TM_ANOTHERԭʼ�жϼĴ��� */
#define SRE_TM_ANOTHER_INTSTS_REG               (SRE_TM_BASE + 0x720)            /* TM_ANOTHER���κ��ж�״̬�Ĵ��� */
#define SRE_TM_TK_CNT_0_REG                     (SRE_TM_BASE + 0x730)            /* Trunk�˿ڻ������ͳ�Ƽ����� */
#define SRE_TM_TK_CNT_1_REG                     (SRE_TM_BASE + 0x734)            /* Trunk�˿ڻ������ͳ�Ƽ����� */
#define SRE_TM_POOL_RLS_CNT_0_REG               (SRE_TM_BASE + 0x770)            /* TM�ͷ�BMU Buffer����Pool������ */
#define SRE_TM_POOL_RLS_CNT_1_REG               (SRE_TM_BASE + 0x774)            /* TM�ͷ�BMU Buffer����Pool������ */
#define SRE_TM_POOL_RLS_CNT_CLR_REG             (SRE_TM_BASE + 0x7F0)            /* TM�ͷ�BMU Buffer����Pool������ */
#define SRE_TM_QINF_TABLE_0_REG                 (SRE_TM_BASE + 0x800)            /* ������Ϣ�� */
#define SRE_TM_QINF_TABLE_1_REG                 (SRE_TM_BASE + 0x804)            /* ������Ϣ�� */
#define SRE_TM_WRED_TABLE_0_REG                 (SRE_TM_BASE + 0x8800)           /* ������WRED�� */
#define SRE_TM_WRED_TABLE_1_REG                 (SRE_TM_BASE + 0x8804)           /* ������WRED�� */
#define SRE_TM_COM_LINK_TABLE_0_REG             (SRE_TM_BASE + 0xC800)           /* С�����߼��˿����ӱ� */
#define SRE_TM_COM_LINK_TABLE_1_REG             (SRE_TM_BASE + 0xC804)           /* С�����߼��˿����ӱ� */
#define SRE_TM_LOC_LINK_TABLE_0_REG             (SRE_TM_BASE + 0xD800)           /* �߼��˿ڵ�Trunk�˿����ӱ� */
#define SRE_TM_LOC_LINK_TABLE_1_REG             (SRE_TM_BASE + 0xD804)           /* �߼��˿ڵ�Trunk�˿����ӱ� */
#define SRE_TM_LOC_MAP_TAB_0_REG                (SRE_TM_BASE + 0xDD18)           /* �߼��˿�ӳ��� */
#define SRE_TM_LOC_MAP_TAB_1_REG                (SRE_TM_BASE + 0xDD1C)           /* �߼��˿�ӳ��� */
#define SRE_TM_COM_MAP_TAB_0_REG                (SRE_TM_BASE + 0xE518)           /* С���˿�ӳ��� */
#define SRE_TM_COM_MAP_TAB_1_REG                (SRE_TM_BASE + 0xE51C)           /* С���˿�ӳ��� */
#define SRE_TM_FQ_WEIGHT_TAB_0_REG              (SRE_TM_BASE + 0x10818)          /* ������Ȩ�ر� */
#define SRE_TM_FQ_WEIGHT_TAB_1_REG              (SRE_TM_BASE + 0x1081C)          /* ������Ȩ�ر� */
#define SRE_TM_COM_WEIGHT_TAB_0_REG             (SRE_TM_BASE + 0x18818)          /* С��Ȩ�ر� */
#define SRE_TM_COM_WEIGHT_TAB_1_REG             (SRE_TM_BASE + 0x1881C)          /* С��Ȩ�ر� */
#define SRE_TM_LOC_WEIGHT_TAB_0_REG             (SRE_TM_BASE + 0x19358)          /* �߼��˿�Ȩ�ر� */
#define SRE_TM_LOC_WEIGHT_TAB_1_REG             (SRE_TM_BASE + 0x1935C)          /* �߼��˿�Ȩ�ر� */
#define SRE_TM_LOC_CIR_TAB_0_REG                (SRE_TM_BASE + 0x19870)          /* �߼��˿�CͰshaping������ */
#define SRE_TM_LOC_CIR_TAB_1_REG                (SRE_TM_BASE + 0x19874)          /* �߼��˿�CͰshaping������ */
#define SRE_TM_LOC_PIR_TAB_0_REG                (SRE_TM_BASE + 0x19D88)          /* �߼��˿�PͰshaping������ */
#define SRE_TM_LOC_PIR_TAB_1_REG                (SRE_TM_BASE + 0x19D8C)          /* �߼��˿�PͰshaping������ */
#define SRE_TM_COM_CIR_TAB_0_REG                (SRE_TM_BASE + 0x1A2A0)          /* С���˿�CͰshaping������ */
#define SRE_TM_COM_CIR_TAB_1_REG                (SRE_TM_BASE + 0x1A2A4)          /* С���˿�CͰshaping������ */
#define SRE_TM_COM_PIR_TAB_0_REG                (SRE_TM_BASE + 0x1ADE0)          /* С���˿�PͰshaping������ */
#define SRE_TM_COM_PIR_TAB_1_REG                (SRE_TM_BASE + 0x1ADE4)          /* С���˿�PͰshaping������ */
#define SRE_TM_FQ_SCH_TYPE_TAB_0_REG            (SRE_TM_BASE + 0x1B920)          /* FQ���е������Ա� */
#define SRE_TM_FQ_SCH_TYPE_TAB_1_REG            (SRE_TM_BASE + 0x1B924)          /* FQ���е������Ա� */
#define SRE_TM_FQ_ST_BYTE_TAB_0_REG             (SRE_TM_BASE + 0x1C920)          /* �����ֽ��л���ͳ�Ʊ� */
#define SRE_TM_FQ_ST_BYTE_TAB_1_REG             (SRE_TM_BASE + 0x1C924)          /* �����ֽ��л���ͳ�Ʊ� */
#define SRE_TM_FQ_ST_NUM_TAB_0_REG              (SRE_TM_BASE + 0x24920)          /* �����а���������ͳ�Ʊ� */
#define SRE_TM_FQ_ST_NUM_TAB_1_REG              (SRE_TM_BASE + 0x24924)          /* �����а���������ͳ�Ʊ� */
#define SRE_TM_COM_ST_NUM_TAB_0_REG             (SRE_TM_BASE + 0x2C920)          /* С�����л���ͳ�Ʊ� */
#define SRE_TM_COM_ST_NUM_TAB_1_REG             (SRE_TM_BASE + 0x2C924)          /* С�����л���ͳ�Ʊ� */
#define SRE_TM_LOC_ST_NUM_TAB_0_REG             (SRE_TM_BASE + 0x2D920)          /* �߼��˿ڻ�����и���ͳ�Ʊ� */
#define SRE_TM_LOC_ST_NUM_TAB_1_REG             (SRE_TM_BASE + 0x2D924)          /* �߼��˿ڻ�����и���ͳ�Ʊ� */
#define SRE_TM_LOC_ST_BYTE_TAB_0_REG            (SRE_TM_BASE + 0x2DE38)          /* �߼��˿ڻ�������ֽ���ͳ�Ʊ� */
#define SRE_TM_LOC_ST_BYTE_TAB_1_REG            (SRE_TM_BASE + 0x2DE3C)          /* �߼��˿ڻ�������ֽ���ͳ�Ʊ� */
#define SRE_TM_LOC_SD_NUM_TAB_0_REG             (SRE_TM_BASE + 0x2E350)          /* �߼��˿ڷ��Ͷ��и���ͳ�Ʊ� */
#define SRE_TM_LOC_SD_NUM_TAB_1_REG             (SRE_TM_BASE + 0x2E354)          /* �߼��˿ڷ��Ͷ��и���ͳ�Ʊ� */
#define SRE_TM_LOC_SD_BYTE_TAB_0_REG            (SRE_TM_BASE + 0x2E868)          /* �߼��˿ڷ��Ͷ����ֽ���ͳ�Ʊ� */
#define SRE_TM_LOC_SD_BYTE_TAB_1_REG            (SRE_TM_BASE + 0x2E86C)          /* �߼��˿ڷ��Ͷ����ֽ���ͳ�Ʊ� */
#define SRE_TM_PKT_WORD0_CORE_0_REG             (SRE_TM_BASE + 0x100000)         /* CoreдTMģ���msg WORD0 */
#define SRE_TM_PKT_WORD0_CORE_1_REG             (SRE_TM_BASE + 0x100010)         /* CoreдTMģ���msg WORD0 */
#define SRE_TM_PKT_WORD1_CORE_0_REG             (SRE_TM_BASE + 0x100004)         /* CoreдTMģ���msg WORD1 */
#define SRE_TM_PKT_WORD1_CORE_1_REG             (SRE_TM_BASE + 0x100014)         /* CoreдTMģ���msg WORD1 */
#define SRE_TM_PKT_WORD2_CORE_0_REG             (SRE_TM_BASE + 0x100008)         /* CoreдTMģ���msg WORD2 */
#define SRE_TM_PKT_WORD2_CORE_1_REG             (SRE_TM_BASE + 0x100018)         /* CoreдTMģ���msg WORD2 */
#define SRE_TM_PKT_WORD3_CORE_0_REG             (SRE_TM_BASE + 0x10000C)         /* CoreдTMģ���msg WORD3 */
#define SRE_TM_PKT_WORD3_CORE_1_REG             (SRE_TM_BASE + 0x10001C)         /* CoreдTMģ���msg WORD3 */
#define SRE_TM_PKT_WORD0_ACC_REG                (SRE_TM_BASE + 0x100400)         /* ������дTMģ��msg WORD0 */
#define SRE_TM_PKT_WORD1_ACC_REG                (SRE_TM_BASE + 0x100404)         /* ������дTMģ��msg WORD1 */
#define SRE_TM_PKT_WORD2_ACC_REG                (SRE_TM_BASE + 0x100408)         /* ������дTMģ��msg WORD2 */
#define SRE_TM_PKT_WORD3_ACC_REG                (SRE_TM_BASE + 0x10040C)         /* ������дTMģ��msg WORD3 */

/* AQM ģ��Ĵ����� */
#define SRE_AQM_BASE                            (SRE_TM_BASE + 0x200000)         /* ʹ��TM��2M�ռ� */

/******************************************************************************/
/*                      MC AQM �Ĵ�������                                     */
/******************************************************************************/
#define SRE_AQM_VER_DATE_REG                       (SRE_AQM_BASE + 0x0)                 /* AQM �汾�Ĵ��� */
#define SRE_AQM_RFS_EMA_CTRL_REG                   (SRE_AQM_BASE + 0x4)                 /* TM RFS MEMʱ������ź� */
#define SRE_AQM_RAS_EMA_CTRL_REG                   (SRE_AQM_BASE + 0x8)                 /* TM RAS MEMʱ������ź� */
#define SRE_AQM_HD_EMA_CTRL_REG                    (SRE_AQM_BASE + 0xC)                 /* AQM RAM ����ģʽ���� */
#define SRE_AQM_INIT_DONE_REG                      (SRE_AQM_BASE + 0x10)                /* AQM�ڲ���ʼ����ɱ�ʶ */
#define SRE_AQM_CFG_OK_REG                         (SRE_AQM_BASE + 0x14)                /* �������AQM��ɼĴ��� */
#define SRE_AQM_LINKTABLE_INIT_DONE_REG            (SRE_AQM_BASE + 0x18)                /* AQM�ڲ������ʼ��ɱ�ʶ */
#define SRE_AQM_INFO_BASE_ADDR_REG                 (SRE_AQM_BASE + 0x20)                /* AQM������Ϣ�����ַ */
#define SRE_AQM_LINK_BASE_ADDR_REG                 (SRE_AQM_BASE + 0x24)                /* AQM�����������ַ */
#define SRE_AQM_DESCPT_BASE_ADDR_REG               (SRE_AQM_BASE + 0x28)                /* AQM�洢����������ַ */
#define SRE_AQM_TIME_BASE_ADDR_REG                 (SRE_AQM_BASE + 0x2C)                /* AQM ��ʱɨ���������ַ */
#define SRE_AQM_SEND_PORT_ADDR_REG                 (SRE_AQM_BASE + 0x30)                /* AQM���Ͷ˿ڼĴ��� */
#define SRE_AQM_SEND_NODE_CODE_REG                 (SRE_AQM_BASE + 0x34)                /* AQMʹ��NODE CODE */
#define SRE_AQM_USER_REG                           (SRE_AQM_BASE + 0x38)                /* AQMʹ��USER */
#define SRE_AQM_RAND_INTT_REG                      (SRE_AQM_BASE + 0x3C)                /* AQM�����㷨��ʼ����� */
#define SRE_AQM_RED_TYPE_IND_REG                   (SRE_AQM_BASE + 0x40)                /* AQM�����㷨���ݷ�ʽ */
#define SRE_AQM_SCH_TYPE_IND_REG                   (SRE_AQM_BASE + 0x44)                /* AQM�������ݷ�ʽ */
#define SRE_AQM_LINK_THR_REG                       (SRE_AQM_BASE + 0x48)                /* AQM�ڲ�����fifo����ͻض����� */
#define SRE_AQM_LINK_DEPTH_REG                     (SRE_AQM_BASE + 0x4C)                /* AQM����������üĴ��� */
#define SRE_AQM_TIME_INTERVAL_REG                  (SRE_AQM_BASE + 0x50)                /* AQM ��ʱɨ���� */
#define SRE_AQM_TIME_FIFO_THR_REG                  (SRE_AQM_BASE + 0x54)                /* AQM ��ʱɨ��FIFO����ض����� */
#define SRE_AQM_TIME_DEPTH_REG                     (SRE_AQM_BASE + 0x58)                /* AQM��ʱ�ض����������üĴ��� */
#define SRE_AQM_TIME_SCAN_SWITCH_REG               (SRE_AQM_BASE + 0x5C)                /* AQM ��ʱɨ����ƿ��� */
#define SRE_AQM_MST_CFG_REG                        (SRE_AQM_BASE + 0x60)                /* AQM ����AXI�������üĴ��� */
#define SRE_AQM_CF_TIMEOUT_REG                     (SRE_AQM_BASE + 0x64)                /* AQM MST�ش����������ж��ϱ�δ�����ʱʱ�����üĴ��� */
#define SRE_AQM_MST_CNT_CTRL_REG                   (SRE_AQM_BASE + 0x68)                /* AQM MST���ڲ�ͨ��ͳ�ƿ��ƼĴ��� */
#define SRE_AQM_MST_LATENCY_AVG_REG                (SRE_AQM_BASE + 0x6C)                /* AQM MST��ƽ����ʱ�Ĵ��� */
#define SRE_AQM_MST_LATENCY_MAX_REG                (SRE_AQM_BASE + 0x70)                /* AQM MST�������ʱ�Ĵ��� */
#define SRE_AQM_AXI_INT_MASK_REG                   (SRE_AQM_BASE + 0x74)                /* AQM ��дAXI�����ж����μĴ��� */
#define SRE_AQM_AXI_RINT_REG                       (SRE_AQM_BASE + 0x78)                /* AQM ��дAXI����ԭʼ�ж� */
#define SRE_AQM_AXI_INT_REG                        (SRE_AQM_BASE + 0x7C)                /* AQM ��дAXI�����ж��ź� */
#define SRE_AQM_ERR_INST_REG                       (SRE_AQM_BASE + 0x80)                /* AQM����ֲ��Ĵ��� */
#define SRE_AQM_ERR_MASK_REG                       (SRE_AQM_BASE + 0x84)                /* AQM�ж����μĴ��� */
#define SRE_AQM_FIFO_ERR_MASK0_REG                 (SRE_AQM_BASE + 0x88)                /* AQM FIFO�ж����μĴ���0 */
#define SRE_AQM_FIFO_ERR_MASK1_REG                 (SRE_AQM_BASE + 0x8C)                /* AQM FIFO�ж����μĴ���1 */
#define SRE_AQM_ERR_RINT_REG                       (SRE_AQM_BASE + 0x90)                /* AQM ����ֲ��ԭʼ�жϼĴ��� */
#define SRE_AQM_FIFO_ERR_RINT0_REG                 (SRE_AQM_BASE + 0x94)                /* AQM FIFOԭʼ�жϼĴ���0 */
#define SRE_AQM_FIFO_ERR_RINT1_REG                 (SRE_AQM_BASE + 0x98)                /* AQM FIFOԭʼ�жϼĴ���1 */
#define SRE_AQM_ERR_INT_REG                        (SRE_AQM_BASE + 0x9C)                /* AQM����ֲ���жϼĴ��� */
#define SRE_AQM_FIFO_ERR_INT0_REG                  (SRE_AQM_BASE + 0xA0)                /* AQM FIFO�жϼĴ���0 */
#define SRE_AQM_FIFO_ERR_INT1_REG                  (SRE_AQM_BASE + 0xA4)                /* AQM FIFO�жϼĴ���1 */
#define SRE_AQM_FIFO_DFX0_REG                      (SRE_AQM_BASE + 0xA8)                /* AQM FIFO DFX�Ĵ���0 */
#define SRE_AQM_FIFO_DFX1_REG                      (SRE_AQM_BASE + 0xAC)                /* AQM FIFO DFX�Ĵ���1 */
#define SRE_AQM_INQ_PKT_CNT_REG                    (SRE_AQM_BASE + 0xB0)                /* AQM ���������ͳ�� */
#define SRE_AQM_INQ_PKT_OK_CNT_REG                 (SRE_AQM_BASE + 0xB4)                /* AQM��ӳɹ�������ͳ�� */
#define SRE_AQM_OUTQ_CARRY_CNT_REG                 (SRE_AQM_BASE + 0xB8)                /* AQM ���س���ָ��ͳ�� */
#define SRE_AQM_SWITCH_CARRY_CNT_REG               (SRE_AQM_BASE + 0xBC)                /* AQM�����л�ָ��ͳ�� */
#define SRE_AQM_DROP_CARRY_CNT_REG                 (SRE_AQM_BASE + 0xC0)                /* AQM���ض���ָ��ͳ�� */
#define SRE_AQM_DROP_DESCPT_CNT_REG                (SRE_AQM_BASE + 0xC4)                /* AQM����������ͳ�� */
#define SRE_AQM_OUTQ_DESCPT_CNT_REG                (SRE_AQM_BASE + 0xC8)                /* AQM����������ͳ�� */
#define SRE_AQM_FQ_PKT_CNT_REG                     (SRE_AQM_BASE + 0xCC)                /* AQM ���ٳ���������ͳ�� */
#define SRE_AQM_DIS_DROP_CNT_REG                   (SRE_AQM_BASE + 0xD0)                /* AQM ����δʹ�ܶ���ͳ�� */
#define SRE_AQM_BUF_DROP_CNT_REG                   (SRE_AQM_BASE + 0xD4)                /* AQM ��������ʧ�ܶ���ͳ�� */
#define SRE_AQM_WRED_DROP_CNT_REG                  (SRE_AQM_BASE + 0xD8)                /* AQM WRED����������ͳ�� */
#define SRE_AQM_LINK_FREE_PTR_CNT_REG              (SRE_AQM_BASE + 0xDC)                /* AQM �����ָ������Ĵ��� */
#define SRE_AQM_MST_CNT_RD_ACC_REG                 (SRE_AQM_BASE + 0xE0)                /* AQM MST�ڶ������� */
#define SRE_AQM_MST_CNT_WR_ACC_REG                 (SRE_AQM_BASE + 0xE4)                /* AQM MST��д������ */
#define SRE_AQM_CREDIT_PKT_CNT_REG                 (SRE_AQM_BASE + 0xE8)                /* AQM ǷȨ�ؿ��ٳ���������ͳ�� */
#define SRE_AQM_INTER_FSM0_REG                     (SRE_AQM_BASE + 0xF0)                /* AQM �ڲ�״̬��״̬��ؼĴ���0 */
#define SRE_AQM_INTER_FSM1_REG                     (SRE_AQM_BASE + 0xF4)                /* AQM �ڲ�״̬��״̬��ؼĴ���1 */
#define SRE_AQM_RED_MAX_THR_0_REG                  (SRE_AQM_BASE + 0x100)               /* AQM RED����ģ��������� */
#define SRE_AQM_RED_MAX_THR_1_REG                  (SRE_AQM_BASE + 0x104)               /* AQM RED����ģ��������� */
#define SRE_AQM_RED_MIN_THR_0_REG                  (SRE_AQM_BASE + 0x200)               /* AQM RED����ģ����С���� */
#define SRE_AQM_RED_MIN_THR_1_REG                  (SRE_AQM_BASE + 0x204)               /* AQM RED����ģ����С���� */
#define SRE_AQM_RED_DROP_SLOP_0_REG                (SRE_AQM_BASE + 0x300)               /* AQM RED����ģ��б�� */
#define SRE_AQM_RED_DROP_SLOP_1_REG                (SRE_AQM_BASE + 0x304)               /* AQM RED����ģ��б�� */
#define SRE_AQM_SCH_WEIGHT_0_REG                   (SRE_AQM_BASE + 0x400)               /* AQM ����Ȩ��ģ�� */
#define SRE_AQM_SCH_WEIGHT_1_REG                   (SRE_AQM_BASE + 0x404)               /* AQM ����Ȩ��ģ�� */
#define SRE_AQM_TIMEOUT_DROP_0_REG                 (SRE_AQM_BASE + 0x500)               /* AQM ��ʱ����ģ�� */
#define SRE_AQM_TIMEOUT_DROP_1_REG                 (SRE_AQM_BASE + 0x504)               /* AQM ��ʱ����ģ�� */
#define SRE_AQM_FQ_SCH_TYPE_0_REG                  (SRE_AQM_BASE + 0x600)               /* AQM�������Ա� */
#define SRE_AQM_FQ_SCH_TYPE_1_REG                  (SRE_AQM_BASE + 0x604)               /* AQM�������Ա� */
#define SRE_AQM_INTER_TEST0_REG                    (SRE_AQM_BASE + 0x680)               /* AQM �ڲ����ԼĴ���0 */
#define SRE_AQM_INTER_TEST1_REG                    (SRE_AQM_BASE + 0x684)               /* AQM �ڲ����ԼĴ���1 */
#define SRE_AQM_INTER_TEST2_REG                    (SRE_AQM_BASE + 0x688)               /* AQM �ڲ����ԼĴ���2 */
#define SRE_AQM_INTER_TEST3_REG                    (SRE_AQM_BASE + 0x68C)               /* AQM �ڲ����ԼĴ���3 */
#define SRE_AQM_INTER_CFG0_REG                     (SRE_AQM_BASE + 0x690)               /* AQM �ڲ����üĴ���0 */
#define SRE_AQM_INTER_CFG1_REG                     (SRE_AQM_BASE + 0x694)               /* AQM �ڲ����üĴ���1 */
#define SRE_AQM_INTER_CFG2_REG                     (SRE_AQM_BASE + 0x698)               /* AQM �ڲ����üĴ���2 */
#define SRE_AQM_INTER_CFG3_REG                     (SRE_AQM_BASE + 0x69C)               /* AQM �ڲ����üĴ���3 */
#define SRE_AQM_PKT_VLD_CORE_0_REG                 (SRE_AQM_BASE + 0x700)               /* Core����Ƿ�ɹ��Ĵ��� */
#define SRE_AQM_PKT_VLD_CORE_1_REG                 (SRE_AQM_BASE + 0x704)               /* Core����Ƿ�ɹ��Ĵ��� */
#define SRE_AQM_FQ_EN_0_REG                        (SRE_AQM_BASE + 0x800)               /* AQM ����ʹ�ܱ� */
#define SRE_AQM_FQ_EN_1_REG                        (SRE_AQM_BASE + 0x804)               /* AQM ����ʹ�ܱ� */
#define SRE_AQM_SCH_TYPE_ID_0_REG                  (SRE_AQM_BASE + 0x20800)             /* AQM�������Ա������� */
#define SRE_AQM_SCH_TYPE_ID_1_REG                  (SRE_AQM_BASE + 0x20804)             /* AQM�������Ա������� */
#define SRE_AQM_PKT_WORD0_CORE_0_REG               (SRE_AQM_BASE + 0x100000)            /* CoreдTMģ���msg WORD0 */
#define SRE_AQM_PKT_WORD0_CORE_1_REG               (SRE_AQM_BASE + 0x100010)            /* CoreдTMģ���msg WORD0 */
#define SRE_AQM_PKT_WORD1_CORE_0_REG               (SRE_AQM_BASE + 0x100004)            /* CoreдTMģ���msg WORD1 */
#define SRE_AQM_PKT_WORD1_CORE_1_REG               (SRE_AQM_BASE + 0x100014)            /* CoreдTMģ���msg WORD1 */
#define SRE_AQM_PKT_WORD2_CORE_0_REG               (SRE_AQM_BASE + 0x100008)            /* CoreдTMģ���msg WORD2 */
#define SRE_AQM_PKT_WORD2_CORE_1_REG               (SRE_AQM_BASE + 0x100018)            /* CoreдTMģ���msg WORD2 */
#define SRE_AQM_PKT_WORD3_CORE_0_REG               (SRE_AQM_BASE + 0x10000C)            /* CoreдTMģ���msg WORD3 */
#define SRE_AQM_PKT_WORD3_CORE_1_REG               (SRE_AQM_BASE + 0x10001C)            /* CoreдTMģ���msg WORD3 */
#define SRE_AQM_PKT_WORD0_ACC_REG                  (SRE_AQM_BASE + 0x100400)            /* ������дTMģ��msg WORD0 */
#define SRE_AQM_PKT_WORD1_ACC_REG                  (SRE_AQM_BASE + 0x100404)            /* ������дTMģ��msg WORD1 */
#define SRE_AQM_PKT_WORD2_ACC_REG                  (SRE_AQM_BASE + 0x100408)            /* ������дTMģ��msg WORD2 */
#define SRE_AQM_PKT_WORD3_ACC_REG                  (SRE_AQM_BASE + 0x10040C)            /* ������дTMģ��msg WORD3 */
#define SRE_AQM_CARRY_WORD_0_REG                   (SRE_AQM_BASE + 0x100800)            /* AQM����ָ����ӼĴ��� */
#define SRE_AQM_CARRY_WORD_1_REG                   (SRE_AQM_BASE + 0x100804)            /* AQM����ָ����ӼĴ��� */

#define DDRC0_CTRL_REG               0x1302c000
#define DDRC1_CTRL_REG               0x1302d000

#define DDRC_CFG_PERF_REG            (0x270+DDRC0_CTRL_REG)

/* DDR����ͳ�Ƶ�����ID���üĴ���  0x274+0x800*chs */
#define DDRC_CFG_STAID_REG           (0x274+DDRC0_CTRL_REG)

/* DDRC�ж����μĴ��� 0x278+0x800*chs */
#define DDRC_CFG_STAIDMSK_REG        (0x278+DDRC0_CTRL_REG)

/* DDRC����ͳ��ʹ�ܼĴ��� 0x010+0x800*chs */
#define DDRC_CTRL_PERF_REG           (0x010+DDRC0_CTRL_REG)

/* DDRC����д��������ͳ�ƼĴ��� 0x380+0x800*chs*/
#define DDRC_HIS_FLUX_WR_REG         (0x380+DDRC0_CTRL_REG)

/* DDRC���ж���������ͳ�ƼĴ��� 0x384+0x800*chs */
#define DDRC_HIS_FLUX_RD_REG         (0x384+DDRC0_CTRL_REG)

/* DDRC����д������Ŀ�Ĵ���  0x388+0x800*chs */
#define DDRC_HIS_FLUX_WCMD_REG       (0x388+DDRC0_CTRL_REG)

/* DDRC���ж�������Ŀ�Ĵ���  0x38c+0x800*chs */
#define DDRC_HIS_FLUX_RCM_REG        (0x38c+DDRC0_CTRL_REG)

/* DDRCָ��IDд����ͳ�ƼĴ��� 0x390+0x800*chs */
#define DDRC_HIS_FLUXID_WR_REG       (0x390+DDRC0_CTRL_REG)

/* DDRCָ��ID������ͳ�ƼĴ��� 0x394+0x800*chs */
#define DDRC_HIS_FLUXID_RD_REG       (0x394+DDRC0_CTRL_REG)

/* DDRC����д������Ŀͳ�ƼĴ��� 0x398+0x800*chs */
#define DDRC_HIS_FLUXID_WCMD_REG     (0x398+DDRC0_CTRL_REG)

/* DDRC���ж�������Ŀͳ�ƼĴ��� 0x039c+0x800*chs */
#define DDRC_HIS_FLUXID_RCMD_REG     (0x39c+DDRC0_CTRL_REG)
#define DDRC_HIS_WLATCNT0_REG        (0x3A0+DDRC0_CTRL_REG)
#define DDRC_HIS_WLATCNT1_REG        (0x3A4+DDRC0_CTRL_REG)
#define DDRC_HIS_RLATCNT0_REG        (0x3A8+DDRC0_CTRL_REG)
#define DDRC_HIS_RLATCNT1_REG        (0x3AC+DDRC0_CTRL_REG)
#define DDRC_HIS_INHERE_RLAT_CNT_REG (0x3B0+DDRC0_CTRL_REG)

#define SCH_FTE_BASE            0x13032000

#define FTE_AR_MODE_REG        (0x0080 + SCH_FTE_BASE)
#define FTE_AR_PYLD0_REG       (0x0084 + SCH_FTE_BASE)
#define FTE_AR_PYLD1_REG       (0x0088 + SCH_FTE_BASE)

#define FTE_AW_MODE_REG        (0x0090 + SCH_FTE_BASE)
#define FTE_AW_PYLD0_REG       (0x0094 + SCH_FTE_BASE)
#define FTE_AW_PYLD1_REG       (0x0098 + SCH_FTE_BASE)

#define FTE_AR_CNUM_REG        (0x0100 + SCH_FTE_BASE)
#define FTE_AR_RNUM_REG        (0x0104 + SCH_FTE_BASE)
#define FTE_AR_DAVG_REG        (0x0108 + SCH_FTE_BASE)
#define FTE_AR_DMAX_REG        (0x010c + SCH_FTE_BASE)

#define FTE_AW_CNUM_REG        (0x0110 + SCH_FTE_BASE)
#define FTE_AW_RNUM_REG        (0x0114 + SCH_FTE_BASE)
#define FTE_AW_DAVG_REG        (0x0118 + SCH_FTE_BASE)
#define FTE_AW_DMAX_REG        (0x011c + SCH_FTE_BASE)

/******************************************************************************/
/*                       SPI �Ĵ�������                                   */
/******************************************************************************/
#define SPI_REG_BASE_ADDR                             (0xe400a000)

/******************************************************************************/
/*                       IOCONFIG �Ĵ�������                                   */
/******************************************************************************/
#define IOCONFIG_REG_BASE_ADDR                        0xe400c000

/* BEGIN: Modified by g00198889, 2012-9-25   ���ⵥ��:SRIO ��ֲ*/
/******************************************************************************/
/*                       SRIO �Ĵ�������                                    */
/******************************************************************************/
#if 0         /* z00202052 */
#define OS_SRE_SRIO_BASE_ADDR                         0x18000000UL
#else
#define OS_SRE_SRIO_BASE_ADDR                         0xe8000000UL
#endif        /* z00202052 */
/* �����Ĵ��������srio_rabreg.h srio_offsetaddr.h */

/******************************************************************************/
/*                       MPE �Ĵ�������                                    */
/******************************************************************************/
#if 0         /* z00202052 */
#define OS_SRE_MPE_BASE_ADDR                          0x19000000UL
#else
#define OS_SRE_MPE_BASE_ADDR                          0xe9000000UL
#endif        /* z00202052 */
/* �����Ĵ��������srio_mpe_reg.h */
/* END:   Modified by g00198889, 2012-9-25 */

/******************************************************************************/
/*                       SERDES3 �Ĵ�������                                   */
/******************************************************************************/
#define SERDES3_BASE_ADDR                            (0xe8001000)

/******************************************************************************/
/*                       IOCTRL1 �Ĵ�������                                   */
/******************************************************************************/
#define IOCTRL1_BASE_ADDR                            (0xe8002000)

/******************************************************************************/
/*                       SERDES2 �Ĵ�������                                   */
/******************************************************************************/
#define SERDES2_BASE_ADDR                            (0xeb000000)

/******************************************************************************/
/*                       PM �Ĵ�������                                    */
/******************************************************************************/
#define SRE_PM_BASE     (0x13029000)

#define SRE_PM_SRST_REQ                             (SRE_PM_BASE + 0x0)
#define SRE_PM_SCLK_EN                              (SRE_PM_BASE + 0x4)
#define SRE_PM_SISO_EN                              (SRE_PM_BASE + 0x8)
#define SRE_PM_SMTCMOS_EN                           (SRE_PM_BASE + 0xC)
#define SRE_PM_SMTCMOS_STAT                         (SRE_PM_BASE + 0x10)
#define SRE_PM_PD_REQ                               (SRE_PM_BASE + 0x14)
#define SRE_PM_PD_STAT                              (SRE_PM_BASE + 0x18)
#define SRE_PM_SEC1_IDLE_DLY                        (SRE_PM_BASE + 0x1C)
#define SRE_PM_SEC0_IDLE_DLY                        (SRE_PM_BASE + 0x20)
#define SRE_PM_MTCMOS_STAT                          (SRE_PM_BASE + 0x24)
#define SRE_PM_SEC_PG_FSM_STAT                      (SRE_PM_BASE + 0x28)
#define SRE_PMU_IMVP_CFG                            (SRE_PM_BASE + 0x88)

#define SRE_GPIO_REG_BASE_ADDR 0xe4000000

#define SRE_URAT_REG_BASEADDR           0xe4007000


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* _SRE_MEMMAP_H */

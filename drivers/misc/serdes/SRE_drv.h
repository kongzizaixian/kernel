/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : SRE_drv.h
  �� �� ��   : ����
  ��    ��   : z00200342
  ��������   : 2013��3��18��
  ����޸�   :
  ��������   : SRE_drv.cͷ�ļ���commonͨ�������
  �����б�   :
              SRE_MemFree
  �޸���ʷ   :
  1.��    ��   : 2013��3��18��
    ��    ��   : z00200342
    �޸�����   : �����ļ�

******************************************************************************/

/*----------------------------------------------*
 * �ⲿ����˵��                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ⲿ����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ȫ�ֱ���                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/


#ifndef _SRE_DRV_H_
#define _SRE_DRV_H_

#include <linux/kernel.h>   /* printk() */
#include <linux/delay.h>    /* mdelay */
#include "SRE_base.h"
#include "SRE_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#define MCSS_INTERRUPT_EN           1   /* MCSS KO�հ��Ƿ��ж�֪ͨ�û�̬�Ŀ��� */
#define MCSS_POE_INTERRUPT_EN       0   /* MCSS POE�հ��Ƿ��жϷ�ʽ���� 1:�ж� 0:��ѯ */

///////////��ӡ���////////////////////////////////
typedef enum
{
    MCSS_PRINTK_NONE    = 0x0,       /* �޴�ӡ */
    MCSS_PRINTK_ERROR   = 0x1,       /* �����ӡ */
    MCSS_PRINTK_WARNING = 0x2,       /* �澯���� */
    MCSS_PRINTK_INFO    = 0x4,       /* ��ͼ����ӡ ��Ϣ */
} MCSS_PRINTK_LEVEL_E;

extern UINT32 g_uwPrintkLevel;

#define MC_PRINTK(printlevel, fmt, arg...)  \
    do                                      \
    {                                       \
            (VOID)printk(fmt, ##arg);       \
    } while (0);

#define MC_PRINTK_INFO(fmt, arg...)      MC_PRINTK(MCSS_PRINTK_INFO, fmt, ##arg)
#define MC_PRINTK_WARNING(fmt, arg...)   MC_PRINTK(MCSS_PRINTK_WARNING, fmt, ##arg)
#define MC_PRINTK_ERROR(fmt, arg...)     MC_PRINTK(MCSS_PRINTK_ERROR, fmt, ##arg)

#define SRE_printf                      MC_PRINTK_WARNING
#define OS_DBG_PRINT                    MC_PRINTK_INFO

extern void MCSS_SetPrintkLevel(UINT32 printlevel);

#define OS_LIKELY(x)                (x)
#define OS_UNLIKELY(x)              (x)
#define OS_EMBED_ASM                __asm
#define OS_SYNC                     //OS_EMBED_ASM("MCR p15, 0, 0, c7, c10, 5; MCR p15, 0, 0, c7, c10, 4"); /* DMB & DSB */
#define OS_DMB                      //OS_EMBED_ASM("MCR p15, 0, 0, c7, c10, 5");
#define OS_DSB                      //OS_EMBED_ASM("MCR p15, 0, 0, c7, c10, 4");

#define SRE_MemCpy memcpy

#if 1
#define OS_MAX_CORE_NUM             16UL
#define OS_MAX_VCPU_NUM             16UL
#define OS_MAX_GRP_NUM              32UL
#define OS_MAX_QUE_PER_GRP          8UL
#define OS_MAX_QUE_NUM              256UL

#endif

/* ��С��ת�� */
#if 0
#define BYTE_SWAP32(x)        ((((unsigned)(x) & 0x000000ff) << 24) | \
			                             (((x) & 0x0000ff00) <<  8) | \
			                             (((x) & 0x00ff0000) >>  8) | \
			                             (((x) & 0xff000000) >> 24))
#endif
#define BYTE_SWAP32(x)        (x)

#define OS_DataRev(uwValue)         ((UINT32)(BYTE_SWAP32(uwValue)))

/* ����ṹ�����ڴ洢ӳ��ĵ�ַ */
typedef struct
{
    void * vir_addr;
    UINT32 phy_addr;
    UINT32 size;
} MCSS_ADDR_MAP_ST;

/*������Ĵ����� 760M(4+4+4+4+8+8+8+16+64+64+32+32+128+128+256 =760)*/
#define MCSS_REG_SPACE_MAX_NUM  32  /* ����ӳ���REG�ռ������ */
#define MCSS_DDR_SPACE_MAX_NUM  32 /* ����ӳ���DDR�ռ������ */

extern UINT32 g_uwRegSpaceNum; /* ��ǰ��ӳ��ļĴ����ռ����� */
extern UINT32 g_uwDdrSpaceNum; /* ��ǰ��ӳ���DDR�ռ����� */

extern MCSS_ADDR_MAP_ST g_astRegMap[MCSS_REG_SPACE_MAX_NUM];
extern MCSS_ADDR_MAP_ST g_astDdrMap[MCSS_DDR_SPACE_MAX_NUM];


INLINE UINT32 REG_VA2PA(void* vir_addr)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwRegSpaceNum; uwLoop ++)
    {
        if (((UINT32)vir_addr >= (UINT32)g_astRegMap[uwLoop].vir_addr) &&
        ((UINT32)vir_addr < ((UINT32)g_astRegMap[uwLoop].vir_addr + g_astRegMap[uwLoop].size)))
        {
            return ((UINT32)vir_addr - (UINT32)g_astRegMap[uwLoop].vir_addr + (UINT32)g_astRegMap[uwLoop].phy_addr);
        }
    }

    SRE_printf("REG_VA2PA: vir_Reg %#x invalid \n", (UINT32)vir_addr);

    return 0;
}

INLINE UINT32 REG_PA2VA(void* phy_addr)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwRegSpaceNum; uwLoop ++)
    {
        if (((UINT32)phy_addr >= g_astRegMap[uwLoop].phy_addr) &&
        ((UINT32)phy_addr < (g_astRegMap[uwLoop].phy_addr + g_astRegMap[uwLoop].size)))
        {
            return ((UINT32)phy_addr - (UINT32)g_astRegMap[uwLoop].phy_addr + (UINT32)g_astRegMap[uwLoop].vir_addr);
        }
    }

    SRE_printf("REG_PA2VA:Reg %#x invalid \n", (UINT32)phy_addr);

    return 0;
}

/* ��ַ�Ƿ���ӳ��������, 1:yes 0: no  */
INLINE UINT32 REG_IsMmaped(UINT32 uwPA)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwRegSpaceNum; uwLoop ++)
    {
        if ((uwPA >= g_astRegMap[uwLoop].phy_addr) &&
        (uwPA < (g_astRegMap[uwLoop].phy_addr + g_astRegMap[uwLoop].size)))
        {
            return 1;
        }
    }

    return 0;
}

INLINE UINT32 OS_READ_REG(UINT32 pRegBase, UINT32 uwRegIndex)
{
    UINT32 uwTemp;
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwRegSpaceNum; uwLoop ++)
    {
        if (((pRegBase + uwRegIndex) >= g_astRegMap[uwLoop].phy_addr) &&
        ((pRegBase + uwRegIndex) < (g_astRegMap[uwLoop].phy_addr + g_astRegMap[uwLoop].size)))
        {
            uwTemp = ((volatile UINT32 *)((UINT32)g_astRegMap[uwLoop].vir_addr + (pRegBase - g_astRegMap[uwLoop].phy_addr)))[(uwRegIndex)];
            return OS_DataRev(uwTemp);
        }
    }

    SRE_printf("OS_READ_REG:Reg %#x index %#x invalid \n", pRegBase, uwRegIndex);

    return 0;
}

INLINE UINT32 OS_WRITE_REG(UINT32 pRegBase, UINT32 uwRegIndex, UINT32 uwValue)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwRegSpaceNum; uwLoop ++)
    {
        if (((pRegBase + uwRegIndex) >= g_astRegMap[uwLoop].phy_addr) &&
        ((pRegBase + uwRegIndex) < (g_astRegMap[uwLoop].phy_addr + g_astRegMap[uwLoop].size)))
        {
            (( volatile UINT32 *)((UINT32)g_astRegMap[uwLoop].vir_addr + (pRegBase - g_astRegMap[uwLoop].phy_addr)))[(uwRegIndex)] = (OS_DataRev(uwValue));
            return OS_SUCCESS;
        }
    }

    SRE_printf("OS_WRITE_REG:Reg %#x index %#x invalid \n", pRegBase, uwRegIndex);

    return OS_FAIL;
}

INLINE UINT32 DDR_VA2PA(void* vir_addr)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwDdrSpaceNum; uwLoop ++)
    {
        if (((UINT32)vir_addr >= (UINT32)g_astDdrMap[uwLoop].vir_addr) &&
        ((UINT32)vir_addr < ((UINT32)g_astDdrMap[uwLoop].vir_addr + g_astDdrMap[uwLoop].size)))
        {
            MC_PRINTK_INFO("pool ioremap info: %#x, %#x, %#x;input %#x\n",
                g_astDdrMap[uwLoop].phy_addr,
                (UINT32)g_astDdrMap[uwLoop].vir_addr,
                g_astDdrMap[uwLoop].size,
                (UINT32)vir_addr);
            return ((UINT32)vir_addr - (UINT32)g_astDdrMap[uwLoop].vir_addr + (UINT32)g_astDdrMap[uwLoop].phy_addr);
        }
    }

    SRE_printf("%s %d: %#x \n", __FUNCTION__, __LINE__, (UINT32)vir_addr);

    return 0;
}

INLINE UINT32 DDR_PA2VA(void* phy_addr)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwDdrSpaceNum; uwLoop ++)
    {
        if (((UINT32)phy_addr >= g_astDdrMap[uwLoop].phy_addr) &&
        ((UINT32)phy_addr < (g_astDdrMap[uwLoop].phy_addr + g_astDdrMap[uwLoop].size)))
        {
            MC_PRINTK_INFO("pool ioremap info: %#x, %#x, %#x;input %#x\n",
                g_astDdrMap[uwLoop].phy_addr,
                (UINT32)g_astDdrMap[uwLoop].vir_addr,
                g_astDdrMap[uwLoop].size,
                (UINT32)phy_addr);
            return ((UINT32)phy_addr - (UINT32)g_astDdrMap[uwLoop].phy_addr + (UINT32)g_astDdrMap[uwLoop].vir_addr);
        }
    }

    SRE_printf("%s %d: %#x \n", __FUNCTION__, __LINE__, (UINT32)phy_addr);

    return 0;
}

/* ��ַ�Ƿ���ӳ��������, 1:yes 0: no  */
INLINE UINT32 DDR_IsMmaped(UINT32 uwPA)
{
    UINT32 uwLoop;

    for (uwLoop = 0; uwLoop < g_uwDdrSpaceNum; uwLoop ++)
    {
        if ((uwPA >= g_astDdrMap[uwLoop].phy_addr) &&
        (uwPA < (g_astDdrMap[uwLoop].phy_addr + g_astDdrMap[uwLoop].size)))
        {
            return 1;
        }
    }

    SRE_printf("%s %d: %#x \n", __FUNCTION__, __LINE__, uwPA);

    return 0;
}

extern int serdes_init(void);
extern void serdes_exit(void); 

extern UINT32 SRE_GetCoreID(void);

#define SRE_DelayMs(ms) mdelay(ms)
extern void SRE_DelayCycle(UINT32 cycle);

#if 0
extern void* MC_FromPhysToVirt(UINT64 ullPhyAddr);
extern UINT32 MC_FromVirtToPhys(void *pVirtAddr);
extern UINT32 SRE_MemFree(UINT32 uwMid, void *pAddr);


typedef VOID* SRE_SPECLOCKID_T; /* �����ڹ�ܶ�SREԭ�д�����޸ģ���ʵ������ depend by SRE_mcc_p650.h line 313 */

#define SRE_HwiCreate(intNo, intHandle, para) OS_SUCCESS  //need implement
#define SRE_HwiEnable(intNo)    OS_SUCCESS
#define HWI_PROC_FUNC           (void*)

//��ʾ����ʱ��
extern void MCSS_PrintkBuildTime(void);

/* P650�������� */
typedef enum
{
    MC_BOARD_TYPE_UBBP_Y = 0,    /* ҵ����֤�� */
    MC_BOARD_TYPE_UBBP_T,    /* t �� */
    MC_BOARD_TYPE_UBBP_V,    /* v �� */
} MC_BOARD_TYPE_ENUM;

#define MC_BOARD_TYPE MC_BOARD_TYPE_UBBP_Y  //T�岻��ʼ��PHY/MDIO
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#endif /* _SRE_DRV_H_ */



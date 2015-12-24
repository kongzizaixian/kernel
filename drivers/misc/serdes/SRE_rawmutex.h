
 /******************************************************************************
  �� �� ��   : sre_rawmutex.h
  �� �� ��   : ����
  ��    ��   : z00202155
  ��������   : 2012��1��11��
  ����޸�   :
  ��������   : SRESS ԭ����������� ģ�� API
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��1��11��
    ��    ��   : z00202155
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __SRE_RAWMUTEX_H__
#define __SRE_RAWMUTEX_H__

//#include "SRE_drv.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*
 * ��ģ������붨��
 */
/**
 * @ingroup SRE_RawMutex
 * ��־�����룺ԭ���������������������
 * ֵ: 0x02003100
 * �������: ����SRE_InitRawMutex����ʱ��ȷ��uwMaxItem������ȷ
 */
#define OS_ERRNO_RAWMUTEX_MaxItem_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x00)

/**
 * @ingroup SRE_RawMutex
 * ��־�����룺�����ʧ��
 * ֵ: 0x02003101
 * �������: ��麯����������
 */
#define OS_ERRNO_RAWMUTEX_DESCPUSH_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x01)

/**
 * @ingroup SRE_RawMutex
 * ��־�����룺����ʧ��
 * ֵ: 0x02003102
 * �������: ��麯����������
 */
#define OS_ERRNO_RAWMUTEX_DescPop_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x02)

/**
 * @ingroup SRE_RawMutex
 * ��־�����룺����ԭ����������Ų��Ϸ�
 * ֵ: 0x02003103
 * �������: ��麯����������
 */
#define OS_ERRNO_RAWMUTEX_INDEX_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x03)

/**
 * @ingroup SRE_RawMutex
 * ��־�����룺����ԭ�����������ýṹ��ָ��Ϊ��
 * ֵ: 0x02003104
 * �������: ��麯����������
 */
#define OS_ERRNO_RAWMUTEX_PTRNULL_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x04)

/**
 * @ingroup SRE_RawMutex
 * ��־�����룺ԭ���������ʼ����ն���ʧ��
 * ֵ: 0x02003105
 * �������:
 */
#define OS_ERRNO_RAWMUTEX_EMPTYQUE_FAIL_ERROR            SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x05)


/* ԭ��������ṹ */
typedef struct tagMcRawMutex
{
    volatile UINT32 stRawSpin;      /* ԭ����������ֵ */
    volatile UINT32 uwFlag;         /* ��ʼ����ɱ�־ */
} SRE_RAWMUTEX_S;

/* ��Ҫ����ʹ��һ��ԭ������ʱ�򣬾����������һ���궨��Ϳ����ˣ�*/
/* ʹ�õ�ʱ��������궨�����ֵ��Ϊ������±��������ͺ��ˡ�*/
typedef enum tagRawMutexId
{
    MOD_TBL_INITSAFE_LOCK_SYS_1,                /* 0 */
    MOD_TBL_INITSAFE_LOCK_SYS_2,
    MOD_REGISTER_INITSAFE_LOCK,
    MEM_POOL_HW_INIT_LOCK,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL0,

    BLOCK_MEM_HEAD_INIT_LOCK_POOL1,             /* 5 */
    BLOCK_MEM_HEAD_INIT_LOCK_POOL2,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL3,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL4,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL5,

    BLOCK_MEM_HEAD_INIT_LOCK_POOL6,             /* 10 */
    BLOCK_MEM_HEAD_INIT_LOCK_POOL7,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL8,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL9,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL10,

    BLOCK_MEM_HEAD_INIT_LOCK_POOL11,            /* 15 */
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL0,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL1,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL2,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL3,

    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL4,         /* 20 */
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL5,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL6,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL7,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL8,

    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL9,         /* 25 */
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL10,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL11,
    BYTE_MEM_MONITOR_STRUCT_INIT_LOCK,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL0,

    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL1,  /* 30 */
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL2,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL3,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL4,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL5,

    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL6,  /* 35 */
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL7,
    SPINLOCK_INIT_LOCK,
    SPINLOCK_INIT_LOCK_SYS_1,
    SPINLOCK_INIT_LOCK_SYS_2,

    NETWORK_PORT_INIT_LOCK,                     /* 40 */
    NETWORK_PORT_INIT_LOCK_1,
    NETWORK_PORT_INIT_LOCK_2,
    SRE_FAU_INITSAFE_LOCK,
    SRE_LOCAL_MEMEORY_INITSAFE_LOCK,

    SRE_SYSLOG_INITSAFE_LOCK,                    /* 45 */
    SRE_TIMER_INITSAFE_LOCK,
    SRE_CRC_INITSAFE_LOCK,
    SRE_CACHE_INITSAFE_LOCK,
    SRE_CLUSTER0_CACHE_INITSAFE_LOCK,

    SRE_CLUSTER1_CACHE_INITSAFE_LOCK,            /* 50 */
    SRE_TIMEBASE_INITSAFE_LOCK,
    SRE_POEINIT_INITSAFE_LOCK,
    SRE_GIC_INITSAFE_LOCK,
    SRE_BLACKBOX_INITSAFE_LOCK,

    SRE_POETEST_INITSAFE_LOCK,                   /* 55 */
    SRE_QMUINIT_INITSAFE_LOCK,
    SRE_QMUTEST_INITSAFE_LOCK,
    SRE_SYSSNAP_INITSAFE_LOCK,
    SRE_STAT_INITSAFE_LOCK,

    SRE_HDCP_INITSAFE_LOCK,                      /* 60 */
    SRE_SYSCTL_INITSAFE_LOCK,
    SRE_BLKMEM_ALARM_INITSAFE_LOCK,
    SRE_BLKBOX_INITSAFE_LOCK,
    SRE_TIMER_INIT_LOCK_CLUSTER_A,

    SRE_TIMER_INIT_LOCK_CLUSTER_B,               /* 65 */
    SRE_DWTH_INITSAFE_LOCK,
    SRE_BLOG_INIT_LOCK,
    SRE_DMA_INIT_LOCK,
    SRE_DYNAMIC_INITSAGE_LOCK,

    SRE_TIMER_HW_INITSAFE_LOCK,                  /* 70 */
    SRE_GMAC_ENABLE_ALL_INITSAFE_LOCK,
    SRE_GDB_INITSAFE_LOCK,
    SRE_QTIMER_INITSAFE_LOCK_CLUSTER_A,
    SRE_QTIMER_INITSAFE_LOCK_CLUSTER_B,

    SRE_DMA_INITSAFE_LOCK,                       /* 75 */
    SRE_HWTIMER_INITSAFE_A_LOCK,
    SRE_HWTIMER_INITSAFE_B_LOCK,
    SRE_SEC_INITSAFE_LOCK,
    SRE_ROHC_INITSAFE_LOCK,

    SRE_POU_INIT_LOCK,                          /* 80 */
    SRE_CLUSTER0_MF_INITSAFE_LOCK,
    SRE_CLUSTER1_MF_INITSAFE_LOCK,
    SRE_CPU_STATUS_RESET_LOCK,
    SRE_CPU_RATE_INIT_LOCK,

    SRE_CPU_HEARTBEAT_INIT_LOCK,                /* 85 */
    SRE_PRINT_INIT_LOCK,
    SRE_BLKMEM_SNAP_INIT_LOCK,
    SRE_NETDRV_SNAP_INIT_LOCK,
    SRE_SPINLOCK_SNAP_INIT_LOCK,

    SRE_BMU_SETUPPOOL_LOCK,                       /* 90 */
    SRE_TM_INITSAFE_LOCK,
    SRE_SCH_INITSAFE_LOCK,
    SRE_DLHDCP_INITSAFE_LOCK,
	SRE_AQM_INITSAFE_LOCK,

    SRE_ULHDCP_INITSAFE_LOCK,                   /* 95 */
/* BEGIN: Added by wangming 2012/11/14 */
    SRE_BPSS_INITSAFE_LOCK,
    SRE_MACE_INITSAFE_LOCK,
    SRE_FP_INITSAFE_LOCK,
    SRE_PDM_INITSAFE_LOCK,
    SRE_PMM_INITSAFE_LOCK,
    SRE_SORT_INITSAFE_LOCK,
    SRE_JSPCPF_INITSAFE_LOCK,
    SRE_JSPCPC_INITSAFE_LOCK,
    SRE_VMIMO_INITSAFE_LOCK,
    SRE_RESM_INITSAFE_LOCK,
    SRE_CQI_INITSAFE_LOCK,
    SRE_DRX_INITSAFE_LOCK,
    SRE_TRACE_INITSAFE_LOCK,
    SRE_PDCFG_INITSAFE_LOCK,
    SRE_BDM_INITSAFE_LOCK,
    SRE_SERDES_INITSAFE_LOCK,
    SRE_SPI_INITSAFE_LOCK,
    SRE_SPPEINIT_INITSAFE_LOCK,
    SRE_TSINIT_INITSAFE_LOCK,
    SRE_MPE_INITSAFE_LOCK,                  /*115 */

/* END: Added by wangming 2012/11/14 */
    /* MAX_RAWMUTEX_LOCK_NUMBER ������������Ϊ����ö�ٱ���������ͳ�� */
    MAX_RAWMUTEX_LOCK_NUMBER = 128

}SRE_RAWMUTEX_ID_ENUM;

/*ԭ�����������ýṹ��*/
typedef struct tagMcRawMutexHwQueueCfg
{
    void *pBaseMem;     /* �����ڴ��ַ */
    UINT32 ulMaxItem;  /* ����������� */
} SRE_RAWMUTEX_HW_QUEUE_CFG_S;

#if 0
/*
* ����ӿں���
*/
/*****************************************************************************
 �� �� ��  : SRE_RawMutexRegister
 ��������  : RawMutexģ������ע�ắ��
 �������  : SRE_RAWMUTEX_HW_QUEUE_CFG_S *stRawMutesQueCfg
 �������  :
 �� �� ֵ  : OS_SUCCESS �ɹ�
             ���� ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��1��11��
    ��    ��   : z00202155
    �޸�����   : �����ɺ���
*****************************************************************************/
extern UINT32 SRE_RawMutexRegister(SRE_RAWMUTEX_HW_QUEUE_CFG_S *stRawMutesQueCfg);

/*****************************************************************************
 �� �� ��  : SRE_InitRawMutex
 ��������  : RawMutexģ�����ó�ʼ��
 �������  : ��
 �������  : ��
 �� �� ֵ  : OS_SUCCESS �ɹ�
             ���� ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��1��11��
    ��    ��   : z00202155
    �޸�����   : �����ɺ���

*****************************************************************************/
extern UINT32 SRE_InitRawMutex(void);
#endif
/*****************************************************************************
 �� �� ��  : SRE_RawMutexProtect
 ��������  : ��ȡԭ�������屣��
 �������  : UINT32 uwRawMutexIndex
 �������  : ��
 �� �� ֵ  : OS_SUCCESS �ɹ�
             ���� ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��1��11��
    ��    ��   : z00202155
    �޸�����   : �����ɺ���

*****************************************************************************/
//extern UINT32 SRE_RawMutexProtect(UINT32 uwRawMutexIndex);
#define SRE_RawMutexProtect(uwRawMutexIndex) 0  /* ���¶�������ڹ�ܶ�SREԭ�д�����޸ģ���ʵ������ */

/*****************************************************************************
 �� �� ��  : SRE_RawMutexUnProtect
 ��������  : �ͷ�ԭ�������屣��
 �������  : UINT32 uwRawMutexIndex
 �������  : ��
 �� �� ֵ  : OS_SUCCESS �ɹ�
             ���� ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��1��11��
    ��    ��   : z00202155
    �޸�����   : �����ɺ���

*****************************************************************************/
//extern UINT32 SRE_RawMutexUnProtect(UINT32 uwRawMutexIndex);
#define SRE_RawMutexUnProtect(uwRawMutexIndex) 0    /* ���¶�������ڹ�ܶ�SREԭ�д�����޸ģ���ʵ������ */

/*****************************************************************************
 �� �� ��  : SRE_RawMutexSetFlag
 ��������  : ����ԭ���������ʼ����ɱ�־
 �������  : UINT32 uwRawMutexIndex
 �������  : ��
 �� �� ֵ  : OS_SUCCESS �ɹ�
             ���� ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��1��11��
    ��    ��   : z00202155
    �޸�����   : �����ɺ���

*****************************************************************************/
//extern UINT32 SRE_RawMutexSetFlag(UINT32 uwRawMutexIndex);
#define SRE_RawMutexSetFlag(uwRawMutexIndex) 0  /* ���¶�������ڹ�ܶ�SREԭ�д�����޸ģ���ʵ������ */

/*****************************************************************************
 �� �� ��  : SRE_RawMutexGetFlag
 ��������  : ��ȡԭ���������ʼ����ɱ�־
 �������  : UINT32 uwRawMutexIndex
 �������  : ��
 �� �� ֵ  : 0 -- ������δʹ��
             1 -- ��������ʹ��
 ���ú���  :
 ��������  :

 �޸���ʷ  :
   1.��    ��   : 2012��1��11��
     ��    ��   : z00202155
     �޸�����   : �����ɺ���


*****************************************************************************/
//extern UINT32 SRE_RawMutexGetFlag(UINT32 uwRawMutexIndex);
#define SRE_RawMutexGetFlag(uwRawMutexIndex) 0  /* ���¶�������ڹ�ܶ�SREԭ�д�����޸ģ���ʵ������ */

#define SRE_RawMutexClearFlag(uwRawMutexIndex) 0    /* ���¶�������ڹ�ܶ�SREԭ�д�����޸ģ���ʵ������ */

#if 0
/* ��ģ������,�ڼ���׷��Ч�ʵ������¿�ȥ�� */
#define SRE_RAWMUTEX_CHECK
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __SRE_RAWMUTEX_H__ */

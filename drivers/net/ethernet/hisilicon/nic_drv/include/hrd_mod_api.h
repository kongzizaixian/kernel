
#ifndef _MCSS_MOD_API_H_
#define _MCSS_MOD_API_H_

#include "hrd_mod_common_api.h"


/**
 * ����������
 */
typedef enum
{
    MCSS_CMD_GMAC_INIT = 0,             /**< ��ʼ�� */
    MCSS_CMD_GMAC_SET_PORT,             /**< ����GMAC�˿ڣ������ʡ�����ģʽ����Э��ʹ�ܡ���Э��ģʽ */

    MCSS_CMD_GMAC_SET_MAC = 3,          /**< ����GMAC����, ����2������ȥ����ȷ�� */
    MCSS_CMD_GMAC_SET_PID,              /**< ���ý���ID */
    MCSS_CMD_GMAC_SET_TX_PORT,          /**< ���÷��Ͷ˿� */
    MCSS_CMD_GMAC_RX_PKT,               /**< ���ձ��� */
    MCSS_CMD_GMAC_SET_CORE_GRP_BIND,    /**< ����VCPU��GROUP�󶨹�ϵ */
    MCSS_CMD_GMAC_SET_QUE_CNT,          /**< ����POE�����հ������ﵽ���ٸ��ϱ��ж� */
    MCSS_CMD_GMAC_LOOP,                 /**< ����GMAC�ڻ� */
    MCSS_CMD_GMAC_GE_SHOW,              /**< ��ѯGE�շ�����Ϣ��ֱ���ں˴�ӡ */
    MCSS_CMD_GMAC_PPE_SHOW,             /**< ��ѯPPE�շ�����Ϣ��ֱ���ں˴�ӡ */
    MCSS_CMD_GMAC_POE_SHOW,             /**< ��ѯPOE�շ�����Ϣ��ֱ���ں˴�ӡ */
    MCSS_CMD_GMAC_BMU_SHOW,             /**< ��ѯBMU�շ�����Ϣ��ֱ���ں˴�ӡ */
    MCSS_CMD_SRIO_READ,                 /**< SRIO read */
    MCSS_CMD_SRIO_WRITE,                /**< SRIO write */
    MCSS_CMD_SRIO_ALLOC_BDBUF,          /**< SRIO alloc pool for BD */
    MCSS_CMD_SRIO_SET_SPEED,            /**< SRIO link speed select */
    MCSS_CMD_SERDES2_SETRD,             /**< SERDES2 set round */
    MCSS_CMD_BMU_GET_POOL,              /**< get pool id and real size through expect size */
    MCSS_CMD_BMU_ALLOC_POOL,            /**< alloc pool through pool id */
    MCSS_CMD_BMU_FREE_POOL,             /**< free pool through addr and pool id */
    MCSS_CMD_PRINTK_BUILD_TIME,         /**< ��ӡ����ʱ�� */
    MCSS_CMD_SET_PRINTK_LEVEL,          /**< ���ô�ӡ���� */
    MCSS_CMD_GMAC_GET_PORT,             /**< ��ȡGMAC�˿ڣ������ʡ�����ģʽ����Э��ʹ�ܡ���Э��ģʽ */
    MCSS_CMD_GMAC_GET_ANG_ST,           /**< ��Э��ģʽ����״̬ */

    /* Begin add by z00200342 2013-8-5 DTS2013080504754  */
    /* 1381��650��һ����650���ʵ�֣�1381����Ӳ��        */

    MCSS_CMD_GMAC_STREAM_TRANSMIT_ADD,  /**< ת��MAC��ַ��ӽӿ� */
    MCSS_CMD_GMAC_STREAM_TRANSMIT_DEL,  /**< ת��MAC��ַɾ���ӿ� */
    MCSS_CMD_GMAC_STREAM_TRANSMIT_QUERY,/**< ת�����ò�ѯ�ӿ� */
    /* End add by z00200342 2013-8-5 DTS2013080504754 */

    /* Begin add by z00200342 2013-8-5 DTS2013080504885 */
    MCSS_CMD_BMU_COMM_INIT,             /**< BMU Ӳ��������ʼ�� */
    MCSS_CMD_POE_COMM_INIT,             /**< POE Ӳ��������ʼ�� */
    MCSS_CMD_GMAC_COMM_INIT,            /**< GMACӲ��������ʼ�� */
    MCSS_CMD_SRIO_COMM_INIT,            /**< SRIOӲ��������ʼ�� */
    MCSS_CMD_TM_COMM_INIT,              /**< TM  Ӳ��������ʼ�� */
    /* End add by z00200342 2013-8-5 DTS2013080504885 */

    MCSS_CMD_GMAC_SHARE_UC_SHOW,        /**< ����gmac�����ĵ�����ַ����չʾ */
    MCSS_CMD_GMAC_FILTER_SHOW,          /**< ����������ʾ */

    /* Begin add by z00200342 2013-9-6: ���ӷ��ͽ������ָ���˿ںź�MAC��ͳ�� */
    MCSS_CMD_GMAC_ENABLE_SOFT_CNT,      /**< ʹ�����ͳ�ƣ�ָ���˿ںź�MACֵ */
    MCSS_CMD_GMAC_GET_SOFT_CNT,         /**< ��ȡ���ͳ�� */
    MCSS_CMD_GMAC_CLEAR_SOFT_CNT,       /**< ���ͳ��ֵ */
    /* End add by z00200342 2013-9-6 */

    MCSS_CMD_GMAC_STREAM_TRANSMIT_CFG,  /**< GSM��ת������ */
    MCSS_CMD_INVALID                    /**< ��Ч��IOCTRL���� */
} MCSS_CMD_TYPE_ENUM;

/**
 * ȫ˫������˫��ö�ٶ���
 */
typedef enum
{
    MCSS_GMAC_HALF_DUPLEX_MODE = 0,    /**< 0: ��˫�� */
    MCSS_GMAC_FULL_DUPLEX_MODE         /**< 1��ȫ˫��  */
} MCSS_DUPLEX_TYPE_E;

/**
 * �ӿ�����
 */
typedef enum {
    MCSS_GMAC_SPEED_10M_MII = 0,       /* reserve */
    MCSS_GMAC_SPEED_100M_MII,          /* reserve */
    MCSS_GMAC_SPEED_1000M_GMII,        /* reserve */
    MCSS_GMAC_SPEED_10M_RGMII,         /* reserve */
    MCSS_GMAC_SPEED_100M_RGMII,        /* reserve */
    MCSS_GMAC_SPEED_1000M_RGMII,       /* reserve */
    MCSS_GMAC_SPEED_10M_SGMII,
    MCSS_GMAC_SPEED_100M_SGMII,
    MCSS_GMAC_SPEED_1000M_SGMII,
    MCSS_GMAC_SPEED_10000M_SGMII       /* reserve */
} MCSS_PORT_MODE_E;

/**
 * ��Э��ʹ��
 */
typedef enum {
    MCSS_GMAC_AUTONEG_DISABLE = 0,      /* ��Э�̲�ʹ�� */
    MCSS_GMAC_AUTONEG_ENABLE            /* ��Э��ʹ�� */
} MCSS_AUTONEG_EN_E;

/**
 * ��Э��ģʽ
 */
typedef enum {
    MCSS_GMAC_AUTONEG_1000BASEX = 0,    /* 1000base-X */
    MCSS_GMAC_AUTONEG_SGMII_PHY,        /* SGMII phyģʽ */
    MCSS_GMAC_AUTONEG_SGMII_MAC,        /* SGMII macģʽ */
    MCSS_GMAC_AUTONEG_RESERVE           /* �����Ĳ����ڵ�ģʽ */
} MCSS_AUTONEG_MODE_E;

/**
 * ��ʼ��������Ϣ
 */
typedef struct
{
    UINT32 port;
} MCSS_CMD_GMAC_INIT_ST;

/**
 * GE�ڳ�ʼ��������Ϣ
 */
typedef struct
{
    UINT32 port;                       /* �˿ں� */
    MCSS_DUPLEX_TYPE_E  duplex_type;   /* ˫��ģʽ */
    MCSS_PORT_MODE_E    speed;         /* ���� */
    MCSS_AUTONEG_EN_E   autoneg_en;    /* ��Э��ʹ�� */
    MCSS_AUTONEG_MODE_E autoneg_mode;  /* ��Э��ģʽ */
} MCSS_CMD_GMAC_SET_PORT_ST;

/**
 * ��Э�̳�ʼ��������Ϣ
 */
typedef struct
{
    UINT32  port;                       /* �˿ں� */
    UINT32  autoneg_st;                /* ��Э��״̬ */
} MCSS_CMD_GMAC_AUNEG_ST;

/**
 * mac��ַ
 */
typedef struct
{
    U8 mac[6];
} MCSS_TYPE_MAC_S;

/**
 * GE MAC����
 */
typedef struct
{
    UINT32 pid;
    MCSS_TYPE_MAC_S mac;
} MCSS_CMD_GMAC_SET_MAC_ST;

/**
 * GSM���ýṹ��
 */
typedef struct
{
    UINT32 uwSwitchGrp;    /**< ת������Grp����ҪΪPOE��������һ��group��Ϊת���˿� */
    UINT32 uwSwitchQos;    /**< ת������Qos*/
    UINT32 uwVmid;         /**< Ӳ��ת�����õ�VMID����ģ����ʱ�����������ת��Group��VMID����һ�� */
}GE_TRANSMIT_CFG_S;

/**
 * GSMת������֮�����õ�mac��ַ��Ϣ�ṹ��
 */
typedef struct
{
    UINT32 uwDesPortId;         /**< Ŀ�Ķ˿ں� */
    MCSS_TYPE_MAC_S ucCfgMac;   /**< �Ѿ����õ�MAC��ַ */
}TRANSMIT_CFG_S;

/**
 * GSMת�����ò�ѯ�ṹ��
 */
typedef struct
{
    UINT32 uwSwitchGrp;                /**<ת������Grp */
    UINT32 uwSwitchQos;                /**<ת������Qos */
    UINT32 uwVmid;                     /**<���õ�VMID*/
    TRANSMIT_CFG_S stTransmitCfg[8];   /**< �Ѿ����õ�MAC��ַ */
}GE_TRANSMIT_QUERY_S;

/**
 * GSM�������ýṹ��
 */
typedef union
{
    struct
    {
        UINT32 uwPort;                 /**< �����õĶ˿ں� */
        GE_TRANSMIT_CFG_S stGeTranCfg; /**< GSM���ýṹ�� */
    } in;
} MCSS_CMD_GE_GSM_TRAN_CFG_PARAM;

/**
 * GSMת��MAC��ַ������ò���
 */
typedef union
{
    struct
    {
        UINT32 uwSrcPortId;
        UINT32 uwDesPortId;
        MCSS_TYPE_MAC_S stMac; /**< GSM ת��mac��ַ*/
    } in;
} MCSS_CMD_GE_GSM_TRAN_ADD_PARAM;

/**
 * GSMת��MAC��ַɾ�����ò���
 */
typedef union
{
    struct
    {
        UINT32 uwSrcPortId;
        UINT32 uwDesPortId;
        MCSS_TYPE_MAC_S stMac; /**< ��ɾ����GSM ת��mac��ַ*/
    } in;
} MCSS_CMD_GE_GSM_TRAN_DEL_PARAM;


/**
 * GSMת�����ò�ѯ����
 */
typedef union
{
    struct
    {
        UINT32 uwPortId;
    } in;
    struct
    {
        GE_TRANSMIT_QUERY_S stTranmitQuery; /**<GSMת�� ���ò���  */
    } out;
} MCSS_CMD_GE_GSM_TRAN_QUERY_PARAM;

/**
 * GE�հ�
 */
#define MCSS_GMAC_RX_MAX_NUM 0x1000
typedef struct
{
    UINT32 uwNum;       /**< ���յı����� */
    struct tagInfo      /**< ���ձ�����Ϣ�ṹ�� ���� */
    {
        UINT32 uwPort;  /**< �˿ں� */
        UINT32 uwPkt;   /**< ���ĵ�ַ */
        UINT32 uwLen;   /**< ���� */
        UINT32 uwPool;  /**< ���Ĵ洢��pool�� */
        UINT32 uwBuf;   /**< ���������ڴ��ĵ�ַ */
    } stInfo[MCSS_GMAC_RX_MAX_NUM];
} MCSS_CMD_GMAC_RX_PKT_S;

/**
 * ���շ����buffer����
 */
#define MCSS_GMAC_RX_MAX_NUM 0x1000
typedef struct
{
    UINT32 uwNum;                        /**< ���յı����� */
    UINT32 auwBuf[MCSS_GMAC_RX_MAX_NUM];  /**< ���������ڴ��ĵ�ַ */
} MCSS_CMD_GMAC_RX_MULTI_FREE_S;


/**
 * VCPU��GROUP�����ýṹ��
 */
typedef struct
{
    UINT32 vcpuId;      /**< VCPUID */
    UINT32 groupMask;    /**< GROUP���� */
} MCSS_CMD_GMAC_SET_CORE_GRP_BIND_ST;

/**
 * GRP�հ��жϰ����ýṹ��
 */
typedef struct
{
    UINT32 group;       /**< group�� */
    UINT32 cnt;         /**< group�հ������ﵽ�հ����ٸ��ϱ��ж� */
} MCSS_CMD_GMAC_SET_QUE_CNT_ST;

/**
 * �˿ڻ���ʹ�����ýṹ��
 */
typedef struct
{
    UINT32 port;        /**< �˿ں� */
    UINT32 inLoopEn;    /**< Ӧ�ò໷��ʹ��/��ʹ�� */
    UINT32 lineLoopEn;  /**< ��·�໷��ʹ��/��ʹ�� */
} MCSS_CMD_GMAC_LOOP_ST;

/* @ingroup    srio
*srio��д���ݽṹ�嶨��.
*��Ӧ������ΪSRIO_CMD_READ �� SRIO_CMD_WRITE*/
typedef struct
{
    U32 ulPort;                       /* SRIO�˿ں� */
    U32 ulDeviceId;                   /* �Զ��豸ID */
    U32 ulOperAddr;                   /* �Զ˵�ַ(�����ַ) */
    U8 *pulDataBuffer;                /* ���ص�ַ(�����ַ) */
    U32 ulLength;                     /* ���ݳ��� */
} MCSS_SRIO_RW_ST;

/* @ingroup    bmu
*bmu����pool�ṹ�嶨��.
*��Ӧ������ΪMCSS_CMD_BMU_GET_POOL&MCSS_CMD_BMU_ALLOC_POOL&MCSS_CMD_BMU_FREE_POOL */
typedef union
{
    //�������
    struct
    {
        UINT32 poolid;
        void* addr;                   //��ַ,����pool�ռ����ʼ��ַ
        UINT32 size;                  //������С
    }input;
    //�������
    struct
    {
        UINT32 poolid;
        void* addr;                   //��ַ,����pool�ռ����ʼ��ַ
        UINT32 poolsize;              //��pool��ʵ�ʴ�С
    }output;
}MCSS_BMU_POOL_ALLOC_U;

typedef union
{
    struct
    {
        UINT32 uwPrintkLevel;
    } in;
} MCSS_CMD_SET_PRINTK_LEVEL_PARAM;

//srio set speed enum
typedef enum enSrioSpeedEx
{
    MCSS_SRIO_1G25,
    MCSS_SRIO_2G5,
    MCSS_SRIO_3G125,
    MCSS_SRIO_5G,
    MCSS_SRIO_6G25
}EnSrioSpeedEx;

/* Begin add by z00200342 2013-8-5 DTS2013080504754  */
/**< ÿ���˿�֧�ֿ����õ�ת��MAC��ַ��������� */
#define MCSS_GMAC_PORT_STREAM_TRANSMIT_MAX_MAC_NUM  (0x8UL)

/**
 * GSM��ת���ṹ��
 */
typedef struct
{
    UINT32 uwInPort;                /**< Դ(����)�˿� */
    MCSS_TYPE_MAC_S stMac;          /**< ��ת����MAC��ַ */
    UINT32 uwOutPort;               /**< Ŀ��(ת���˿�) */
} MCSS_GMAC_STREAM_TRANSMIT_ST;

/**
 * ����GSM��ת����������Ĳ���
 */
typedef union
{
    MCSS_GMAC_STREAM_TRANSMIT_ST in;
} MCSS_CMD_GMAC_STREAM_TRANSMIT_ADD_PARAM;

/**
 * ɾ��GSM��ת����������Ĳ���
 */
typedef union
{
    struct
    {
        UINT32 uwInPort;                /**< Դ(����)�˿� */
        MCSS_TYPE_MAC_S stMac;          /**< ��ת����MAC��ַ */
    } in;
} MCSS_CMD_GMAC_STREAM_TRANSMIT_DEL_PARAM;

/**
 * ��ѯGSM��ת����������Ĳ���
 */
typedef union
{
    struct
    {
        UINT32 uwInPort;                /**< Դ(����)�˿� */
    } in;   /**< ����: �˿ں� */
    struct
    {
        UINT32 uwMacNum;                /**< �����õ�ת��MAC�� */
        MCSS_GMAC_STREAM_TRANSMIT_ST stInfo[MCSS_GMAC_PORT_STREAM_TRANSMIT_MAX_MAC_NUM];
    } out;  /**<���: �ö˿ڶ�Ӧ��ת��MAC������Ϣ */
} MCSS_CMD_GMAC_STREAM_TRANSMIT_QUERY_PARAM;

/* End add by z00200342 2013-8-5 DTS2013080504754 */

/* Begin add by z00200342 2013-8-5 DTS2013080504885 */

/**
 * BMUӲ��������ʼ������
 */
typedef union
{
    struct
    {
        UINT32 uwOverFlowSpaceAddr;     /**< ����ռ���ʼ��ַ */
        UINT32 uwOverFlowSpaceSize;     /**< ����ռ��С */
    } in;
} MCSS_CMD_BMU_COMM_INIT_PARAM;

/**
 * POEӲ��������ʼ��
 */
typedef union
{
    struct
    {
        UINT32 uwOverFlowSpaceAddr;     /**< ����ռ���ʼ��ַ */
        UINT32 uwOverFlowSpaceSize;     /**< ����ռ��С */
    } in;
} MCSS_CMD_POE_COMM_INIT_PARAM;

/**
 * GMACӲ��������ʼ��
 */
typedef union
{
    struct
    {
        UINT32 uwOverFlowSpaceAddr;     /**< ����ռ���ʼ��ַ */
        UINT32 uwOverFlowSpaceSize;     /**< ����ռ��С */
    } in;
} MCSS_CMD_GMAC_COMM_INIT_PARAM;

/**
 * SRIOӲ��������ʼ��
 */
typedef union
{
    struct
    {
        UINT32 uwOverFlowSpaceAddr;     /**< ����ռ���ʼ��ַ */
        UINT32 uwOverFlowSpaceSize;     /**< ����ռ��С */
    } in;
} MCSS_CMD_SRIO_COMM_INIT_PARAM;

/**
 * TMӲ��������ʼ��
 */
typedef union
{
    struct
    {
        UINT32 uwOverFlowSpaceAddr;     /**< ����ռ���ʼ��ַ */
        UINT32 uwOverFlowSpaceSize;     /**< ����ռ��С */
    } in;
} MCSS_CMD_TM_COMM_INIT_PARAM;

/* End add by z00200342 2013-8-5 DTS2013080504885 */

/* Begin add by z00200342 2013-9-6: ���ӷ��ͽ������ָ���˿ںź�MAC��ͳ�� */
/**
 * ʹ�����ͳ�ƣ�ָ���˿ںź�MACֵ
 */
typedef union
{
    struct
    {
        UINT32 uwTxRx;          /**< 0: ���ͷ��� 1:���շ��� */
        UINT32 uwEnable;        /**< 0: ��ʹ�� 1: ʹ�� */
        UINT32 uwPort;          /**< ͳ�ƵĶ˿ں� */
        MCSS_TYPE_MAC_S stMac;  /**< ָ����Ҫͳ�Ƶ�MAC */
    } in;
} MCSS_CMD_GMAC_ENABLE_SOFT_CNT_PARAM;

/**
 * ��ȡ���ͳ��
 */
typedef union
{
    struct
    {
        UINT32 uwTxRx;          /**< 0: ���ͷ��� 1:���շ��� */
    } in;
    union
    {
        struct
        {
            UINT32 uwEnable;        /**< �Ƿ���ʹ�����ͳ�� */
            UINT32 uwPort;          /**< ��ͳ�ƵĶ˿� */
            UINT32 uwTotalCnt;      /**< ����ͳ�� */
            UINT32 uwTotalOkCnt;    /**< �ɹ�����ͳ�� */
            UINT32 uwMacCnt;        /**< ָ��MAC����ͳ�� */
            UINT32 uwMacOkCnt;      /**< ָ��MAC�ɹ�����ͳ�� */
            UINT32 auwResv[4];
            MCSS_TYPE_MAC_S stMac;  /**< ָ��ͳ�Ƶ�MAC */
        } tx;
        struct
        {
            UINT32 uwEnable;        /**< �Ƿ���ʹ�����ͳ�� */
            UINT32 uwPort;          /**< ��ͳ�ƵĶ˿� */
            UINT32 uwTotalCnt;      /**< ����ͳ�� */
            UINT32 uwTotalOkCnt;    /**< �����û�̬����ͳ�� */
            UINT32 uwTotalTxCnt;    /**< ת����������ͳ�� */
            UINT32 uwTotalFailCnt;  /**< ʧ�ܵı�����ͳ�� */
            UINT32 uwMacCnt;        /**< ָ��MAC����ͳ�� */
            UINT32 uwMacOkCnt;      /**< ָ��MAC�����û�̬����ͳ�� */
            UINT32 uwMacTxCnt;      /**< ָ��MACת������ͳ�� */
            UINT32 uwMacFailCnt;    /**< ָ��MAC����ʧ�ܵ�����ͳ�� */
            MCSS_TYPE_MAC_S stMac;  /**< ָ��ͳ�Ƶ�MAC */
            UINT32 uwBadBufAddrCnt; /**< �쳣buf��ַͳ�� */
            UINT32 uwLastBadBufAddr;/**< ���һ���쳣buf��ַ */
        } rx;
    } out;
} MCSS_CMD_GMAC_GET_SOFT_CNT_PARAM;

/* End add by z00200342 2013-9-6 */

/* BEGIN: Added by w00200395, 2013/12/10   ���ⵥ��:DTS2013112610434 */
typedef union
{
    struct
    {
        UINT32 uwNum;          /**< ��Ҫ�ͷŵ�buffer�� */
        void*  pstRxMultFree;  /**< �����ͷ�buffer������ */
    } in;
} MCSS_CMD_ETH_MULTI_FREE_PARAM;
/* END:   Added by w00200395, 2013/12/10 */

/* SRE��׼�ӿ�������/�������� */
#include "iware_comm_kernel_api.h"
#include "iware_pcie_kernel_api.h"



#endif /* _MCSS_MOD_API_H_ */


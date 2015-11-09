#ifndef _IWR_ETH_API_H_
#define _IWR_ETH_API_H_

/*��������*/
#define HIGMAC_DEVNAME_DEBUGGMAC                         "HiFE0" /*����������*/

/*Canbus����*/
#define HIGMAC_DEVNAME_CANGMAC                           "HiFE1" /*Canbus������*/

/*�����ֶ���*/
#define SIOCDEVDRVCMD                            0x89F4
#define ETH_MACLOOP_SET                          0x01 /*ETH_������,MAC��������,0:��ֹ 1:ʹ��,�޲���*/
#define ETH_MACLINELOOP_SET                      0x02 /*ETH_������,MAC��·��������,0:��ֹ 1:ʹ��,�޲���*/
#define ETH_STATICS_SHOW                         0x03 /*ETH_������,��ȡͳ����Ϣ*/
#define ETH_SET_MAC_ADDR	                     0x05 /*ETH_������,���������ַ,�޲���*/
#define ETH_CHIP_RESET                           0x06 /*ETH_������,gmac����,�޲���*/
#define ETH_CFG_SET                              0x07 /*ETH_������,gmac��������*/
#define ETH_TX_ENABLE                            0x08 /*ETH_������,gmac����ͨ��ʹ��,0:��ֹ 1:ʹ��,�޲���*/
#define ETH_RX_ENABLE                            0x09 /*ETH_������,gmac����ͨ��ʹ��,0:��ֹ 1:ʹ��,�޲���*/
#define ETH_MACLOOP_TEST                         0x0A /*ETH_������,���ز���*/
#define ETH_PORT_MODE_SET                        0x0B /*ETH_������,�˿�ģʽ����*/

#define ETH_RCB_RX_CNT_SHOW                      0x0C /*ETH_������,��ʾRCB Rx����ͳ����Ϣ*/
#define ETH_RCB_TX_CNT_SHOW                      0x0D /*ETH_������,��ʾRCB Tx����ͳ����Ϣ*/
#define ETH_PPE_CNT_BY_PORT_SHOW                 0x0E /*ETH_������,��ʾPPE ��portͳ����Ϣ*/
#define ETH_PPE_CNT_BY_QUE_SHOW                  0x0F /*ETH_������,��ʾPPE ��queueͳ����Ϣ*/
#define ETH_RCB_RX_RING_SHOW                     0x10 /*ETH_������,��ʾRCB Rx ring BD��Ϣ*/
#define ETH_RCB_TX_RING_SHOW                     0x11 /*ETH_������,��ʾRCB Tx ring BD��Ϣ*/

/*������������ö�ٶ���*/
typedef enum tagGmacPortMode
{
    GMAC_10M_MII = 0, /*10M MII*/
    GMAC_100M_MII, /*100M MII*/
    GMAC_1000M_GMII, /*1000M MII*/
    GMAC_10M_RGMII, /*10M RGMII*/
    GMAC_100M_RGMII, /*100M RGMII*/
    GMAC_1000M_RGMII, /*1000M RGMII*/
    GMAC_SERDES, /*Serdes mode*/
    GMAC_UNKNOW_MODE /*δ֪����ģʽ*/
}HIGMAC_MODE_ENUM;

/*----------------------------------------------*
 *�������ں�can���ڽӿ�            *
 *----------------------------------------------*/

/*��ȡͳ����Ϣ�ṹ�嶨��
��Ӧ������ΪHIGMAC_STATICS_GET*/
typedef struct stuInfra_ETH_STATICS
{
    U32 ulRecPktCnt;     /*�հ�ͳ��ֵ*/
    U32 ulSendPktCnt;    /*����ͳ��ֵ*/
    U32 ulRecErrPktCnt;  /*�հ�����ͳ��ֵ*/
    U32 ulSendErrPktCnt; /*��������ͳ��ֵ*/
}HIGMAC_ETH_STATICS_STRU;

/*�˿�ģʽ���ýṹ�嶨��
��Ӧ������ΪHIGAMC_CFG_SET*/
typedef struct stuPORT_MODE_CFG
{
    HIGMAC_MODE_ENUM port_mode;       /*�˿�ģʽ*/
    U32 ulDuplexMode;                 /*0��˫�� 1 ȫ˫��*/
    U32 an_enable;                    /*��Э��ʹ��*/
}HIGMAC_PORTMODE_CFG_STRU;

/*��ȡ�����Ϣ�ṹ�嶨��
��Ӧ������ΪHIGAMC_RECORD_INFO*/
typedef struct stuRecord_reg
{
   U32 CF_INTRPT_STAT;          /*�ж�״̬�Ĵ��� 0x434*/
   U32 PORT_MOD;                /*�˿�״̬0x0040*/
   U32 BUS_ERR_ADDR;            /*�������ߵ�ַ 0x43C*/
   U32 TX_DROP_CNT;             /*���ͷ�����FIFO�ն������İ���ͳ�Ƽ�����0x448*/
   U32 RX_OVER_FLOW_CNT;        /*FIFO���������İ���ͳ�Ƽ�����0x44C*/

   U32 FIFO_CURR_STATUS;        /*FIFO��ǰ״̬ 0x454*/
   U32 FIFO_HIS_STATUS;         /*FIFO��ʷ״̬�Ĵ��� 0x458*/
   U32 TX_CS_FAIL_CNT;          /*�������У���ʧ�ܼ�����0x460*/
   U32 RX_BUFRQ_ERR_CNT;        /*���ܷ������뻺����������0x58C*/
   U32 TX_BUFRL_ERR_CNT;        /*���ͷ����ͷŻ�����������0x590*/

   U32 RX_WE_ERR_CNT;           /*���ܷ���д�������������������0x594*/
   U32 TX_UNDERRUN;             /*���͹����з����ڲ���������·���ʧ�ܵĴ���ͳ��0x150*/
   U32 TX_CRC_ERROR;            /*����֡����ȷCRC�����֡��ͳ��0x158*/
   U32 RX_LONG_ERRORS;          /*����֡�������������󳤶ȵ�֡��0x00C0*/
   U32 RX_VERY_LONG_ERR_CNT;    /*���յ�����֡ͳ��0x0D0*/

   U32 RX_DATA_ERR;             /*�������ݴ���֡ͳ��0x0B8*/
   U32 RX_RUNT_ERR_CNT;         /*���յ�֡��С��64byte���ڵ���12byte��֡��ͳ��0x0D4*/
   U32 RX_SHORT_ERR_CNT;        /*С��96bit��֡��ͳ��0x0D8*/
   U32 RX_OVERRUN_CNT;          /*FIFO���ͳ�ƼĴ���0x1EC*/
   U32 RX_FCS_ERRORS;           /*����CRC��������֡��ͳ��0x0B0*/

   U32 RX_ALIGN_ERRORS;         /*���ݷ��ֽڶ������֡ͳ��0x0BC*/
   U32 TX_EXCESSIVE_LENGTH_DROP;/*�����趨�����֡�����·���ʧ�ܴ���ͳ��0x14C*/
}HIGMAC_RECORD_REG_STRU;

/*��ȡ�����������Խṹ�嶨��
��Ӧ������ΪHIGAMC_LASTWORDS*/
typedef struct stuRecord_lastwords
{
   U32 CF_INTRPT_STAT;          /*�ж�״̬�Ĵ��� 0x434*/
   U32 PORT_MOD;                /*�˿�״̬0x0040*/
   U32 BUS_ERR_ADDR;            /*�������ߵ�ַ 0x43C*/
   U32 TX_DROP_CNT;             /*���ͷ�����FIFO�ն������İ���ͳ�Ƽ�����0x448*/

   U32 RX_OVER_FLOW_CNT;        /*FIFO���������İ���ͳ�Ƽ�����0x44C*/
   U32 FIFO_CURR_STATUS;        /*FIFO��ǰ״̬ 0x454*/
   U32 FIFO_HIS_STATUS;         /*FIFO��ʷ״̬�Ĵ��� 0x458*/
   U32 TX_CS_FAIL_CNT;          /*�������У���ʧ�ܼ�����0x460*/
   U32 RX_BUFRQ_ERR_CNT;        /*���ܷ������뻺����������0x58C*/
   U32 TX_BUFRL_ERR_CNT;        /*���ͷ����ͷŻ�����������0x590*/
   U32 RX_WE_ERR_CNT;           /*���ܷ���д�������������������0x594*/

   U32 TX_UNDERRUN;             /*���͹����з����ڲ���������·���ʧ�ܵĴ���ͳ��0x150*/
   U32 TX_CRC_ERROR;            /*����֡����ȷCRC�����֡��ͳ��0x158*/
   U32 RX_LONG_ERRORS;          /*����֡�������������󳤶ȵ�֡��0x00C0*/
   U32 RX_VERY_LONG_ERR_CNT;    /*���յ�����֡ͳ��0x0D0*/
   U32 RX_DATA_ERR;             /*�������ݴ���֡ͳ��0x0B8*/
   U32 RX_RUNT_ERR_CNT;         /*���յ�֡��С��64byte���ڵ���12byte��֡��ͳ��0x0D4*/
   U32 RX_SHORT_ERR_CNT;        /*С��96bit��֡��ͳ��0x0D8*/
   U32 RX_OVERRUN_CNT;          /*FIFO���ͳ�ƼĴ���0x1EC*/
   U32 RX_FCS_ERRORS;           /*����CRC��������֡��ͳ��0x0B0*/
   U32 RX_ALIGN_ERRORS;         /*���ݷ��ֽڶ������֡ͳ��0x0BC*/
   U32 TX_EXCESSIVE_LENGTH_DROP;/*�����趨�����֡�����·���ʧ�ܴ���ͳ��0x14C*/
}HIGMAC_LASTWORDS_REG_STRU;

/** ����ģʽö�ٶ��� */
typedef enum tagLoopMode
{
    /* BEGIN: Modified by w00146306, 2010/2/27   ���ⵥ��:BT9D00310 */
    ETH_NO_LOOP    = 0,
    /* END:   Modified by w00146306, 2010/2/27 */
    ETH_MAC_SYS_LOOP,            /**< MAC����      */
    ETH_MAC_LINE_LOOP,           /**< MAC��·����  */
    ETH_PHY_SYS_LOOP,            /**< PHY����      */
    ETH_PHY_LINE_LOOP,           /**< PHY��·����  */
    ETH_UNKNOWN_LOOP_MODE        /**< δ֪����ģʽ */

} LOOP_MODE_E;

/*����PAUSE֡����*/
typedef struct eth_set_pause_cfg
{
   U32 pause_time;              /*pause֡ʱ��*/
   U32 pause_gap;               /*pause֡��϶*/
   U32 pause_rsp_mode;          /*pause֡ģʽ*/
   U32 pause_local_mac_h;       /*pause֡����mac��λ��ַ*/
   U32 pause_local_mac_l;       /*pause֡����mac��λ��ַ*/
   U32 pause_peer_mac_h;        /*pause֡�Զ�mac��λ��ַ*/
   U32 pause_peer_mac_l;        /*pause֡�Զ�mac��λ��ַ*/
}eth_set_pause_cfg_s;

/** linkģʽö�ٶ��� */
typedef enum link_mode
{
    ETH_NORMAL_MODE = 0,
    ETH_LINK_UP = 2,
    ETH_LINK_DOWN = 3,
} link_mode_e;


/*����xge link ģʽ*/
typedef struct eth_set_link_cfg
{
   link_mode_e link_mode;       /*link ģʽ*/
   U32 rf_enable;               /*rf�澯ʹ��*/
   U32 lf_enalbe;               /*if�澯ʹ��*/
}eth_set_link_cfg_s;


/** lfrf����ģʽö�ٶ��� */
typedef enum lfrf_mode
{
    ETH_LFRF_NORMAL_MODE = 0,
    ETH_INSERT_LF = 2,
    ETH_INSERT_RF = 3,
} lfrf_mode_e;


/*����xge link ģʽ*/
typedef struct eth_set_lfrf_mode
{
   lfrf_mode_e lfrf_mode;       /*lfrf ģʽ*/
   U32 rf_tx_enable;            /*rf�澯ʹ��*/
   U32 unidir_enalbe;           /*����ifrf�澯ʹ��*/
}eth_set_lfrf_mode_s;

/*ppe �ж�����*/
typedef struct
{
    U32    qid_err_int_msk;          /*qid�����ж�*/
    U32    pkt_sram_par_int_msk;     /*��żУ������ж�*/
}hrd_ppe_int_msk_s;

/*ppe tnl �ж�����*/
typedef struct ppe_tnl_int_msk
{
        U32  rx_sram_par_int ;
        U32  tx_sram_par_int ;
        U32  tx_drop_int ;
        U32  rx_fifo_overflow_int ;
        U32  rx_drop_int ;
        U32  rx_no_buf_int ;
        U32  rx_pkt_int;
        U32  ddr_rw_int;
        U32  tx_bd_addr_fifo_int ;
        U32  tx_st_heat_int;
        U32  rx_st_heat_int;
        U32  pa_st_heat_int;
        U32  Reserved_20 ;
}hrd_ppe_tnl_int_msk_s;


/*xge �ж�����*/
typedef struct xge_int_msk
{
        U32    ierr_u              ; /* [0] enables or disables the interrupt of the same name. 0=disable, 1=enable. */
        U32    reserved_3          ; /* [2..1]  */
        U32    ovf                 ; /* [3] enables or disables the interrupt of the same name. 0=disable, 1=enable. */
        U32    link_up             ; /* [4] enables or disables the interrupt of the same name. 0=disable, 1=enable. */
        U32    link_down           ; /* [5] enables or disables the interrupt of the same name. 0=disable, 1=enable. */
        U32    lf                  ; /* [6] enables or disables the interrupt of the same name. 0=disable, 1=enable. */
        U32    rf                  ; /* [7] enables or disables the interrupt of the same name. 0=disable, 1=enable. */
        U32    sd                  ; /* [8] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    sf                  ; /* [9] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    wis                 ; /* [10] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    mib_ecc_uni         ; /* [11] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    mib_ecc_mul         ; /* [12] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    fec_ecc_uni         ; /* [13] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    fec_ecc_mul         ; /* [14] enables or disables the interrupt of the same name. 0=disable, 1=enable.      <br><b>note: the field is obsolete, please don't use it again.</b> */
        U32    reserved_17         ; /* [31..15]  */
}hrd_xge_int_msk_s;


/* ���ڴ����붨�� */
#define HRD_NIC_FREE_BUF_ERROR              HRD_ERRNO(HRD_MID_NIC,0x1)
#define HRD_NIC_RawMUTEX_ERROR              HRD_ERRNO(HRD_MID_NIC,0x2)
#define HRD_NIC_PKT_LEN_ERROR               HRD_ERRNO(HRD_MID_NIC,0x3)
#define HRD_NIC_PKT_DROP_ERROR              HRD_ERRNO(HRD_MID_NIC,0x4)
#define HRD_NIC_PKT_L2_ERROR                HRD_ERRNO(HRD_MID_NIC,0x5)
#define HRD_NIC_INVLD_PKT_ERROR             HRD_ERRNO(HRD_MID_NIC,0x6)
#define HRD_NIC_INT_OPEN_CLOSE_ERR          HRD_ERRNO(HRD_MID_NIC,0x7)

#endif


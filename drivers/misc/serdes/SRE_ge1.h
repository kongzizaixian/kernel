/**
@file SRE_ge.h

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : SRE_ge.h                               \n
  �� �� ��   : ����                                   \n
  ��    ��   : w63320                                 \n
  ��������   : 2009��8��13��                          \n
  ����޸�   :                                        \n
  ��������   : SRE_ge.h ��ͷ�ļ�                       \n
  �����б�   :                                        \n
                SRE_SerdesBist                         \n
                SRE_MdioRead                           \n
                SRE_MdioReadReg                        \n
                SRE_MdioWrite                          \n
                SRE_EnableRx                           \n
                SRE_EnableTx                           \n
                SRE_SetPOEEntry                        \n
                SRE_GmacSetTimeOut                     \n
                SRE_GmacReqRBuffTimeSet                \n
                SRE_SetRbuffReqAddr                    \n
                SRE_PortWorkModeSet                    \n
                SRE_PortWorkModeGet                    \n
                SRE_AnModeSet                          \n
                SRE_AnModeGet                          \n
                SRE_MaxFrmSizeSet                      \n
                SRE_MaxFrmSizeGet                      \n
                SRE_ShortFrmSizeSet                    \n
                SRE_ShortFrmSizeGet                    \n
                SRE_ShortFrmPassEn                     \n
                SRE_ShortFrmPassStatusGet              \n
                SRE_RxPadStripEn                       \n
                SRE_RxPadStripStatusGet                \n
                SRE_TxPadAddEn                         \n
                SRE_TxPadAddStatusGet                  \n
                SRE_RxSkipLenSet                       \n
                SRE_RxSkipLenGet                       \n
                SRE_LineLoopBackEn                     \n
                SRE_LineLoopBackDis                    \n
                SRE_InLoopBackEn                       \n
                SRE_InLoopBackDis                      \n
                SRE_SdsLoopBackEn                      \n
                SRE_SdsLoopBackDis                     \n
                SRE_GetInLoopBackStatus                \n
                SRE_GetLineLoopBackStatus              \n
                SRE_MacAddrFilterSet                   \n
                SRE_BcPktFiltEn                        \n
                SRE_McPktFiltEn                        \n
                SRE_UcNoLocalPktFiltEn                 \n
                SRE_VlanPktFiltEn                      \n
                SRE_GmacFilterStatusGet                \n
                SRE_FilterStatusShow                   \n
                SRE_MacAddrAdd                         \n
                SRE_MacAddrDel                         \n
                SRE_MacAddrShow                        \n
                SRE_GmacMacAddrQuery                   \n
                SRE_GmacMainMacAddrSet                 \n
                SRE_GmacMainMacAddrClr                 \n
                SRE_GmacMainMacAddrQuery               \n
                SRE_RxBuffParaSet                      \n
                SRE_RxBuffParaGet                      \n
                SRE_PktInBuffFormatSet                 \n
                SRE_PktInBuffFormatGet                 \n
                SRE_PktModeSet                         \n
                SRE_PktModeGet                         \n
                SRE_PortModeSet                        \n
                SRE_PortModeGet                        \n
                SRE_GmacCrcStripEn                     \n
                SRE_GmacCrcAddEn                       \n
                SRE_GmacQOSSet                         \n
                SRE_GmacQOSGet                         \n
                SRE_GmacGrpSet                         \n
                SRE_GmacGrpGet                         \n
                SRE_GmacTagModeSet                     \n
                SRE_GmacTagModeGet                     \n
                SRE_GmacTagTypeSet                     \n
                SRE_GmacTagTypeGet                     \n
                SRE_TxFifoSet                          \n
                SRE_RxFifoSet                          \n
                SRE_RxTxFifoGet                        \n
                SRE_TxCfgFifoSet                       \n
                SRE_RxCfgFifoSet                       \n
                SRE_RxTxCfgFifoGet                     \n
                SRE_GmacPktMatchSet                    \n
                SRE_GmacPktMatchGet                    \n
                SRE_GmacStatisticsShow                 \n
                SRE_GmacSetAddrMod                     \n
                SRE_GmacGetAddrMod                     \n
                SRE_GmacPauseFrmCfg                    \n
                SRE_GetGmacPauseFrmCfg                 \n
                SRE_GmacIntStatusShow                  \n
                SRE_GmacRst                            \n
                SRE_MdioInit                           \n
                SRE_SetDuplexType                      \n
                SRE_GetDuplexType                      \n
                SRE_SetPortMode                        \n
                SRE_GetPortMode                        \n
                SRE_GetAnLinkState                     \n
                SRE_GetAnSpeed                         \n
                SRE_SetAnNegInfo                       \n
                SRE_GetAnNegInfo                       \n
                SRE_CreateGmacShareVar                 \n
                SRE_ChangePortMode                     \n
                SRE_InitGeReg                          \n
                SRE_ReadGmacStatRegs                   \n
  �޸���ʷ   :                                        \n
  1.��    ��   : 2009��8��13��                        \n
    ��    ��   : w63320                               \n
    �޸�����   : �����ļ�                             \n
                                                      \n
******************************************************************************/
//#include "SRE_ppe.h"

#ifndef _SRE_GMACAPI_H_
#define _SRE_GMACAPI_H_


#define OS_MID_GMAC 0x42 

/** ��ģ������붨���ַ */
#define OS_ERRNO_MDIO_ID                        SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x01) /**< MDIO ID���� */
#define OS_ERRNO_MDIO_BUSY                      SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x02) /**< MDIO ����BUSY״̬ */
#define OS_ERRNO_MDIO_READ                      SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x03) /**< MDIO ������ */
#define OS_ERRNO_MDIO_WRITE                     SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x04) /**< MDIO д���� */
#define OS_ERRNO_MDIO_SCAN                      SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x05) /**< MDIO�Զ������� */
#define OS_ERRNO_MDIO_PHY_ADDR                  SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x06) /**< PHY��ַ���� */
#define OS_ERRNO_MDIO_SCAN_REG_NUM              SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x07) /**< MDIOģʽ�Ĵ�����ַ������Χ */
#define OS_ERRNO_MDIO_PHY_ID                    SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x08) /**< PHY ID������ */
#define OS_ERRNO_MDIO_PHY_REG                   SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x09) /**< PHY REG������ */
#define OS_ERRNO_MDIO_INPUT_PTR_NULL            SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x0a) /**< ����ָ��ΪNULL������ */

#define OS_ERRNO_GMAC_PORT_ID                   SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x39) /**< GMAC�˿ںŴ��� */
#define OS_ERRNO_GMAC_PKT_LEN_EXCCEED_MAX       SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x3A) /**< GMAC���ĳ��ȳ��� */
#define OS_ERRNO_GMAC_BUFFER_ALLOC              SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x3B) /**< ����bufferʧ�� */
#define OS_ERRNO_GMAC_MSG_PTR                   SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x3C) /**< ����ָ��Ϊ�� */
#define OS_ERRNO_GMAC_PKT_LEN_ZERO              SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x3D) /**< ���ĳ���Ϊ0 */
#define OS_ERRNO_GMAC_PKT_QOS                   SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x3E) /**< ����QOS���� */
#define OS_ERRNO_GMAC_PARA                      SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x3F) /**< �����Ƿ����� */
#define OS_ERRNO_GMAC_MAC_DEL                   SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x40) /**< MAC��ַɾ��ʧ�� */
#define OS_ERRNO_GMAC_MAC_ADDR_REPEAT           SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x41) /**< MAC ��ַ�ظ� */
#define OS_ERRNO_GMAC_MAC_ADDR_REG_FULL         SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x42) /**< û�п����mac��ַ�Ĵ��� */
#define OS_ERRNO_GMAC_VALUE_EXCEED_MAX          SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x43) /**< ʹ�ܲ����Ƿ� */
#define OS_ERRNO_GMAC_POOL_CFG                  SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x44) /**< GMAC ʹ�õ�pool���ô��� */
#define OS_ERRNO_GMAC_PORT_MODE                 SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x45) /**< GMAC port���ʹ������ */
#define OS_ERRNO_GMAC_DUPLEX_TYPE               SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x46) /**< GMAC ȫ˫��/��˫��ģʽ���� */
#define OS_ERRNO_GMAC_LAST_FRAG_NOT_ALIGN       SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x47) /**<  */
#define OS_ERRNO_GMAC_PLL_LOCK_FAILED           SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x48) /**< Serdes0/1 PLL lockʧ�� */
#define OS_ERRNO_GMAC_FRAG_SIZE_TOO_SMALL       SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x49) /**<  */
#define OS_ERRNO_GMAC_PKT_SHORT_LEN_EXCCEED_MAX SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x4A) /**< GMAC����֡���ô��� */
#define OS_ERRNO_GMAC_GRP_ID                    SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x4B) /**< GMAC��ID���ô��� */
#define OS_ERRNO_GMAC_CF_RX_BUF_SIZE            SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x4C) /**< GMAC���� buffer size ���� */
#define OS_ERRNO_GMAC_FC_TX_TMR                 SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x4D) /**< GMAC��������ʱ��������� */
#define OS_ERRNO_GMAC_FC_TX_AUTO                SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x4E) /**< GMAC�������ؿ��Ʋ������� */
#define OS_ERRNO_GMAC_AN_LINK_TIME_ILLEGAL      SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x4F) /**< GMAC��Э������ʱ��Ƿ� */
#define OS_ERRNO_GMAC_AN_NOT_COMPLETE           SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x50) /**< GMAC��Э������δ��� */
#define OS_ERRNO_GMAC_NULL_PTR                  SRE_ERRNO_OS_ERROR(OS_MID_GMAC, 0x51) /**< ��ָ�� */



#define SRE_GMAC_TT_NULL        0
#define SRE_GMAC_TT_ORDER       1
#define SRE_GMAC_TT_ATOMIC      2

/** ���뱨�ĸ�ʽ����*/
typedef struct {
    UINT32 mac_skip_len;        /**< ����ͷ�����н����ֶγ���  */
    UINT32 mac_skip_crc;       /*'CRC�����Ƿ����skip����0����������1������*/
}SRE_RX_PKT_MODE_CFG_S;




/** �ӿ����� */
typedef enum {
    GMAC_10M_MII = 0,
    GMAC_100M_MII,
    GMAC_1000M_GMII,
    GMAC_10M_RGMII,
    GMAC_100M_RGMII,
    GMAC_1000M_RGMII,
    GMAC_10M_SGMII,
    GMAC_100M_SGMII,
    GMAC_1000M_SGMII,
    GMAC_10000M_SGMII,          /* 10GE */
}SRE_PORT_MODE_E;

/** GMAC �˿�ģʽ���� */
typedef struct {
    SRE_PORT_MODE_E port_mode;   /**< �˿�ģʽ  */
    UINT32 max_frm_size;        /**< ���ձ��ĵ����֡��  */
    UINT32 short_runts_thr;     /**< ���ձ��ĵ���С֡��  */
    UINT32 pad_enable;          /**< ���ͱ���С����С֡��ʱ�Զ����padʹ��  */
    UINT32 crc_add;             /**< �Զ����CRCʹ��  */
    UINT32 an_enable;           /**< ��Э��ʹ��  */
    UINT32 runt_pkt_en;         /**< ���ճ���֡͸��ʹ��  */
    UINT32 strip_pad_en;        /**< ����֡�Զ�����padʹ��  */
}SRE_PORT_MODE_CFG_S;


/** MAC address structure*/
typedef struct {
    UINT32 mac_addr_low;        /**< mac��ַ��32bits  */
    UINT32 mac_addr_hi;         /**< mac��ַ��16bits  */
}SRE_MAC_ADDR_STR_S;

/** MAC address structure �������벻������ĵ�ַ���øýṹ�����Բ�������ĵ�ַ������Ӧ�����ȫ1!!! **/
typedef struct {
    UINT32 mac_addr_low;        /**< mac��ַ��32bits  */
    UINT32 mac_addr_hi;         /**< mac��ַ��16bits  */
    UINT32 mac_addr_low_mask;   /**< mac��ַ��32bits����  */
    UINT32 mac_addr_hi_mask;    /**< mac��ַ��16bits����  */
}SRE_MAC_MASK_ADDR_STR_S;


/** MAC�������ýṹ��*/
typedef struct {
    UINT32 crc_err_pass : 1;    /**< CRC �����ı���ʹ��  */
    UINT32 pause_frm_pass : 1;  /**< ����֡����ʹ��  */
    UINT32 bc_drop_en : 1;      /**< �㲥֡����ʹ��  */
    UINT32 mc_match_en : 1;     /**< �Ǳ����鲥֡����ʹ��  */
    UINT32 uc_match_en : 1;     /**< �Ǳ��ص���֡����ʹ��  */
}SRE_MAC_FILTER_CFG_S;

/** ����ͷƥ���ֽ������ͱ���ͷƥ���ֽڱ����ýṹ�� */
#define GMAC_PKT_MATCH_TBL_LEN 8

typedef struct {
    UINT32 cf_match_offset;                     /**< �ַ���ƥ���ڱ����е���ʼƫ��  */
    UINT32 match_msk;                           /**< ����ͷƥ���ֽ������  */
    UINT32 match_tbl[GMAC_PKT_MATCH_TBL_LEN];   /**< ����ͷƥ���ֽڱ�  */
}SRE_PKT_PATTERN_MATCH_CFG_S;


/** Define the union SRE_MIDO_CTROL_U  */
typedef union
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    mdc_speed             : 2   ; /**<  [1..0]  */
        unsigned int    autoscan_en           : 1   ; /**<  [2]  */
        unsigned int    mdio_in_pro_en        : 1   ; /**<  [3]  */
        unsigned int    mdio_in_pro           : 1   ; /**<  [4]  */
        unsigned int    Reserved_0            : 27  ; /**<  [31..5]  */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} SRE_MIDO_CTROL_U;

/** Define the union SRE_MIDO_PHY_TYPE_U  */
typedef union
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    phy0_is_ge            : 1   ; /**<  [0]  */
        unsigned int    phy1_is_ge            : 1   ; /**<  [1]  */
        unsigned int    phy2_is_ge            : 1   ; /**<  [2]  */
        unsigned int    phy3_is_ge            : 1   ; /**<  [3]  */
        unsigned int    phy4_is_ge            : 1   ; /**<  [4]  */
        unsigned int    Reserved_0            : 27  ; /**<  [31..5]  */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} SRE_MIDO_PHY_TYPE_U;

/** Define the union SRE_MDIO_AUTOSCAN_PHY_ADDR_U  */
typedef union
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    autoscan_phy_addr     : 5   ; /**<  [4..0]  */
        unsigned int    Reserved_0            : 27  ; /**<  [31..5]  */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} SRE_MDIO_AUTOSCAN_PHY_ADDR_U;

/** ȫ˫������˫��ö�ٶ��� */
typedef enum tagDuplexType
{
    SRE_HALF_DUPLEX_MODE = 0,    /**< 0: ��˫�� */
    SRE_FULL_DUPLEX_MODE         /**< 1��ȫ˫��  */
}SRE_DUPLEX_TYPE_E;

/** ��Э���ٶ�ö�ٶ��� */
typedef enum tagAnNegSpeed
{
    SRE_AN_NEG_10M = 0,
    SRE_AN_NEG_100M,
    SRE_AN_NEG_1000M
}SRE_AN_NEG_SPEED_E;

#define MAX_VLAN_QOS_LEVEL 8
#define MAX_DSCP_QOS_LEVEL 64


/*qos����ģʽ����*/
typedef struct {
    UINT32    arp_qos ;         /*arp���ĵ�qos  */
    UINT32    rarp_qos;         /*rarp���ĵ�qos  */
    UINT32    mul_qos;          /*�鲥���ĵ�qos  */
    UINT32    brc_qos ;         /*�㲥���ĵ�qos  */
    UINT32    icmp_qos;         /*icmp���ĵ�qos  */
    UINT32    tcp_qos ;         /*tcp���ĵ�qos  */
    UINT32    udp_qos;          /*udp���ĵ�qos  */
    UINT32    ip_qos ;          /*ip���ĵ�qos  */
    UINT32    oth_qos ;         /*�������ĵ�qos  */
}SRE_QOS_PKTTYPE_MODE_CFG;

#if 0
typedef struct tagMcQosModeCfg
{
    SRE_PPE_QOS_MODE_E    qos_mode;    /*qos������ģʽ��  */
    UINT32    port_qos;               /*�Ĵ���ָ��ģʽ�¸ö˿ڵ�qos  */
}SRE_QOS_MODE_CFG_S;

typedef struct tagMcGrpIndexModeCfg
{
    UINT32 group_offset;        /*���ĵ�ָ��ƫ��  */
    UINT32 group_mask;          /*Keyֵ����  */
}SRE_GRP_INDEX_MODE_CFG_S;

/*group������ģʽ����*/
typedef struct tagMcGrpMatchModeCfg
{
    UINT32 grp_offset;          /*grp_modeΪ11b�ӱ���ȡ���ݵ�ƫ����  */
    UINT32 rx_grp_msk;          /*groupƥ���ֽ������  */
    UINT64 rx_grp_tbl[32];      /*groupƥ�����  */
    UINT32 rx_grp_result[32];    /*ƥ�����Ĵ�����ƥ�����0-7��groupֵ  */
    UINT32 def_grp_res;         /*grp_modeΪ11bʱ��ƥ������Ĭ��ֵ  */
}SRE_GRP_MATCH_MODE_CFG_S;

typedef struct tagMcGrpPkttypeModeCfg
{
    UINT32    arp_grp ;         /*arp���ĵ�grp  */
    UINT32    rarp_grp;         /*rarp���ĵ�grp  */
    UINT32    mul_grp;          /*�鲥���ĵ�grp  */
    UINT32    brc_grp ;         /*�㲥���ĵ�grp  */
    UINT32    icmp_grp;         /*icmp���ĵ�grp  */
    UINT32    tcp_grp ;         /*tcp���ĵ�grp  */
    UINT32    udp_grp;          /*udp���ĵ�grp  */
    UINT32    ip_grp ;          /*ip���ĵ�grp  */
    UINT32    oth_grp ;         /*�������ĵ�grp  */
}SRE_GRP_PKTTYPE_MODE_CFG_S;

typedef struct tagMcGrpModeCfg
{
    SRE_PPE_GRP_MODE_E grp_mode; /**< group����ģʽ��  */
    UINT32 port_grp;            /**< group����ģʽΪ�˿�ָ��ʱ�Ķ˿�group��  */
    UINT32 port_vmid;           /**< group����ģʽΪ�˿�ָ��ʱ�Ķ˿�vmid��  */
}SRE_GRP_MODE_CFG_S;

typedef struct tagMcTagPktParseModeCfg
{
    UINT32 tag_msk_port_src;    /**< Դtcp/udp���ĵĶ˿ں��Ƿ�μӽ�������  */
    UINT32 tag_msk_port_dst;    /**< Ŀ�� tcp/udp���ĵĶ˿ں��Ƿ�μӽ�������  */
    UINT32 tag_msk_ip_src;      /**< ipԴ��ַ�Ƿ�μӽ�������  */
    UINT32 tag_msk_ip_dst;      /**< ipĿ�ĵ�ַ�Ƿ�μӽ�������  */
    UINT32 tag_msk_ip_prot;     /**< Э�������Ƿ�μӽ�������  */
    UINT32 default_tag;
}SRE_TAG_PKT_PARSE_MODE_CFG_S;

typedef struct tagMcTagPatternModeCfg
{
    UINT32 tag_offset;          /**< ��ȡ��ʽ�£���ȡ�����ֽ��ڱ����е�ƫ��  */
    UINT32 tag_mask_0;          /**< tag_modeΪ�ӱ����м���ʱ����Ҫ������ֽ�����  */
    UINT32 tag_mask_1;          /**< tag_modeΪ�ӱ����м���ʱ����Ҫ������ֽ�����  */
}SRE_TAG_PATTERN_MODE_CFG_S;

typedef struct tagMcTagModeCfg
{
    SRE_PPE_TAG_LO_MODE_E tag_lo_mode;                   /* tag�ĵ�16λ����ģʽ��  */
    SRE_PPE_TAG_HI_MODE_E tag_hi_mode;                   /* tag�ĵ�8λ����ģʽ��  */
    union
    {
        UINT32 def_tag;
        SRE_PPE_TAG_MSK_INFO_S tag_msk_info;
    };
}SRE_TAG_MODE_CFG_S;

typedef enum {
    SRE_PKT_PARSE_TT = 0,        /*0Ϊ�ɱ��Ľ�������;  */
    SRE_PORT_TT                  /*1Ϊ�ɼĴ�������  */
}SRE_TT_MODE;

/*����tag type����ģʽ�ṹ��*/
typedef struct {
    SRE_PPE_TT_MODE_E tt_mode;         /*tag type������ģʽ:  */
    UINT32 def_tt;              /*�Ĵ�������ģʽ�µ�tt����  */
}SRE_TAGTYPE_MODE_CFG_S;


/** GMAC���ýṹ�� */
typedef struct tagGmacCfg
{
    UINT32 uwGmacBigPool;       /**< gmacʹ�õĴ�pool*/
    SRE_PORT_MODE_E enPortMode;
    UINT32 uwMaxFrmSize;        /* ��λ���ֽ� */
    UINT32 uwRuntsThr;          /**<  ���ձ��ĵ���С֡�� */
    SRE_QOS_MODE_CFG_S stQosMode;
    SRE_GRP_MODE_CFG_S stGrpMode;
    SRE_TAG_MODE_CFG_S stTagModeCfg;
    SRE_TAGTYPE_MODE_CFG_S stTtModeCfg;
}SRE_GMAC_CFG_S;

/** PPE FIFO���ýṹ�� */
typedef struct tagPpeFifoCfg
{
    UINT32 uwGroupIdMask;
}SRE_PPE_FIFO_CFG_S;
#endif

typedef struct tagMcGmacStat
{
    UINT32 uwrx_octets_total_ok_cnt;
    UINT32 uwrx_octets_bad_cnt;
    UINT32 uwrx_uc_pkts_cnt;
    UINT32 uwrx_mc_pkts_cnt;
    UINT32 uwrx_bc_pkts_cnt;
    UINT32 uwrx_vlan_pkt_cnt;
    UINT32 uwrx_fw_ctrl_frame_cnt;
    UINT32 uwrx_octets_total_filt_cnt;
    UINT32 uwrx_filt_pkt_cnt;
    UINT32 uwrx_framsize_64;
    UINT32 uwrx_framsize_65_127;
    UINT32 uwrx_framsize_128_255;
    UINT32 uwrx_framsize_256_511;
    UINT32 uwrx_framsize_512_1023;
    UINT32 uwrx_framsize_1024_1518;
    UINT32 uwrx_framsize_bt_1518;
    UINT32 uwrx_fcs_error_cnt;
    UINT32 uwrx_data_error_cnt;
    UINT32 uwrx_align_error_cnt;
    UINT32 uwrx_frame_long_err_cnt;
    UINT32 uwrx_frame_very_long_err_cnt;
    UINT32 uwrx_frame_runt_err_cnt;
    UINT32 uwrx_frame_short_err_cnt;
    UINT32 uwrx_overrun_cnt;
    UINT32 uwtx_octets_total_ok_cnt;
    UINT32 uwtx_octets_bad_cnt;
    UINT32 uwtx_uc_pkts_cnt;
    UINT32 uwtx_mc_pkts_cnt;
    UINT32 uwtx_bc_pkts_cnt;
    UINT32 uwtx_vlan_pkt_cnt;
    UINT32 uwtx_fw_ctrl_frame_cnt;
    UINT32 uwtx_framsize_64;
    UINT32 uwtx_framsize_65_127;
    UINT32 uwtx_framsize_128_255;
    UINT32 uwtx_framsize_256_511;
    UINT32 uwtx_framsize_512_1023;
    UINT32 uwtx_framsize_1024_1518;
    UINT32 uwtx_framsize_bt_1518;
    UINT32 uwtx_fcs_error_cnt;
    UINT32 uwtx_underrun_err_cnt;
    UINT32 uwtx_excessive_drop_cnt;
}SRE_GMAC_STAT_S;

 /* Define the union SRE_GMAC_TX_LOCAL_PAGE_U  addr :0x5c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved0                : 16  ; /* [31..16]  */
        UINT32    cfg_15bit               : 1   ; /* [15]  */
        UINT32    reserved1                : 1   ; /* [14]  */
        UINT32    cfg_13_12bit            : 2   ; /* [13..12]  */
        UINT32    reserved2                : 3  ; /* [11..9]  */
        UINT32    cfg_8_5bit              : 4   ; /* [8:5]  */
        UINT32    reserved3                : 4   ; /* [4:1]  */
        UINT32    cfg_0bit                : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_TX_LOCAL_PAGE_U;

typedef struct SRE_FRAG_PTR_STRU
{
    UINT32 back:7;      /**< ���ݰ���һ�黺���У�����ָ������cache line�໺��ͷ����cache line����*/
    UINT32 pool:4;      /**< ���ݰ���һ�黺���BMU����ʱ��pool��*/
    UINT32 reserve:5;
    UINT32 size:16;     /**< ���ݰ���һ�黺������Ч���ݵĳ��ȣ���λΪ�ֽ�*/
    UINT32 bufferAddr;  /**< ��һ���������ַ*/
}SRE_FRAG_PTR;

#if 0
/** GMAC���ýṹ�� */
typedef struct tagGmacCfg
{
    UINT32 uwGmacSmallPool;     /**< gmacʹ�õ�Сpool*/
    UINT32 uwGmacBigPool;       /**< gmacʹ�õĴ�pool*/
    SRE_PORT_MODE_E enPortMode;
    UINT32 uwMaxFrmSize;
    UINT32 uwRuntsThr;          /**<  ���ձ��ĵ���С֡�� */
    SRE_QOS_MODE_CFG_S stQosMode;
    SRE_GRP_MODE_CFG_S stGrpMode;
    SRE_TAG_MODE_CFG_S stTagModeCfg;
    SRE_TAGTYPE_MODE_CFG_S stTtModeCfg;
    SRE_ADDR_MODE enAddrMode;    /**< ��ַ����ģʽ�����ѡ��Ϊ��ַ����ģʽ��Ӳ����Ĭ�Ϲ��˵ı���GMAC��ClusterB */
    SRE_GMAC_FILTER_ADDR_U unGmacFilterAddr;
}SRE_GMAC_CFG_S;
#endif

/* GMAC�������İ��ַ����ĸ�Cluster  */
#define  SRE_GMAC_USA_CLUSTERA      (0) /**< GMAC�������İ��ַ���Cluster A */
#define  SRE_GMAC_USA_CLUSTERB      (1) /**< GMAC�������İ��ַ���Cluster B */

#define SRE_POE_PHY_REG_BASE_ADDR    0x33050000      /**< POE�Ĵ�����ַ��ַ */
#define SRE_BMU_PHY_REG_BASE_ADDR    0x33040000      /**< BMU�Ĵ�����ַ��ַ */
#define SRE_GMAC_PHY_REG_BASE_ADDR  0x08400000UL      /**< GMAC�Ĵ�����ַ��ַ */
#define SRE_POU_PHY_REG_BASE_ADDR    0x100d0000      /**< POU�Ĵ�����ַ��ַ */

#define SRE_GMAC_REG_ADDR_LEN    0x10000UL
#define SRE_MDIO_REG_ADDR_LEN    0x10000

#define SRE_MDIO_PHY_GRP_LEN       0x100
#define SRE_MDIO_REG_LEN       0x10

#define SRE_POE_ADD_PACKET_0_OFST       0x080
#define SRE_POE_ADD_PACKET_1_OFST       0x084
#define SRE_POE_ADD_PACKET_2_OFST       0x088
#define SRE_POE_ADD_PACKET_3_OFST       0x08c

#define SRE_MAC_ADDR_NUM                     6UL    /* GE ���ص�mac��ַ����������2��mc��4��uc */
#define SRE_MAC_ADDR_MSK_NUM                 2UL    /* GE ���ص�2��mc��Ӧ������ */
#define SRE_MDIO_PHY_ADDR_NUM        5
#define SRE_GMAC_IP_QOS_REG_NUM      8
#define SRE_MDIO_AUTOSCAN_REG_NUM    8
#define SRE_GMAC_MAX_PORT_NUM        8UL

#define SRE_GE_MAX_BUSINESS_PORT_NUM      9UL
//wugao_test �������ҵ�����ڶ�Ӧ�� ppeͨ�� �� ge
//#define SRE_GE_MAX_BUSINESS_PORT_NUM      12UL


#define SRE_GE8_PORT_NUM                       8UL
#define SRE_GE9_PORT_NUM                       9UL
#define SRE_GE10_PORT_NUM                     10UL
#define SRE_GE_MAC_ADDR_MSK_MAX            0x3fUL

#define SRE_ADDR_FIL_MSK              0xfff00000

#define GMAC_REG(port, offset)            ( SRE_GMAC_BASE_ADDR + ( port) * SRE_GMAC_REG_ADDR_LEN + ( offset ) )
#define MDIO_REG(mdio_id, offset)            ( SRE_MDIO_BASE_ADDR + ( mdio_id) * SRE_MDIO_REG_ADDR_LEN + ( offset ) )


/* define for PHY 88E1145 begin */
#define SRE_GMAC_PHY_ID_88E1145         0x01410cd0
#define SRE_GMAC_PHY_ID_88E1145_MSK     0xffffff00

/* define for PHY 88E1145 begin */
#define SRE_GMAC_PHY_ID_5482             0x0143bcb2
#define SRE_GMAC_PHY_ID_5482_MSK         0xffffff00

/* Phy registers */
#define SRE_GMAC_PHY_CTRL_REG                0x00    /**< MII Control Register : r/w */
#define SRE_GMAC_PHY_STAT_REG                0x01    /**< MII Status Register: ro */
#define SRE_GMAC_PHY_PHY_ID0_REG             0x02    /**< MII PHY ID register: ro */
#define SRE_GMAC_PHY_PHY_ID1_REG             0x03    /**< MII PHY ID register: ro */
#define SRE_GMAC_PHY_ANA_REG                 0x04    /**< MII Auto-Neg Advertisement: r/w */
#define SRE_GMAC_PHY_ANP_REG                 0x05    /**< MII Auto-Neg Link Partner: ro */
#define SRE_GMAC_PHY_AN_EXP_REG              0x06    /**< MII Auto-Neg Expansion: ro */
#define SRE_GMAC_PHY_NTPG_TRANS_REG          0X07    /**< NEXT PAGE Transmit Reg: r/w */
#define SRE_GMAC_PHY_PART_NTPG_TRANS_REG     0X08    /**< NEXT PAGE Transmit Reg: r/w */
#define SRE_GMAC_PHY_GB_CTRL_REG             0x09    /**< MII 1000Base-T control register */
#define SRE_GMAC_PHY_GB_STAT_REG             0x0a    /**< MII 1000Base-T Status register ro*/
#define SRE_GMAC_PHY_ESR_REG                 0x0f    /**< MII Extended Status register ro*/
/* Non-standard MII Registers */
#define SRE_GMAC_PHY_SCR_REG                 0x10    /**< MII Specific Control Register */
#define SRE_GMAC_PHY_SPEC_STATUS_REG         0x11    /**< MII Specific status register*/
#define SRE_GMAC_PHY_INT_ENABLE_REG          0x12    /**< MII Interrupt Enable register*/
#define SRE_GMAC_PHY_INT_STATUS_REG          0x13    /**< MII Interrupt status register*/
#define SRE_GMAC_PHY_EXT_SCR_REG             0x14    /**< MII Extended PHY Specific Control register*/
#define SRE_GMAC_PHY_EXT_ADDR_REG            0x16    /**< MII Extended Address Register*/
#define SRE_GMAC_PHY_EXT_SCR2_REG            0x1a    /**< MII Extended PHY Specific Control 2 register*/
#define SRE_GMAC_PHY_EXT_SSTATUS_REG         0x1b    /**< MII Extended PHY Specific Status register*/
#define SRE_GMAC_PHY_MULTIPAGE_28_REG        0x1c    /**< MII Multipage Register 28*/
#define SRE_GMAC_PHY_EXT_ADDR2_REG           0x1d    /**< MII Extended Address Register 2*/
#define SRE_GMAC_PHY_MULTIPAGE_30_REG        0x1e    /**< MII Multipage Register 30*/

/** register value define*/
#define SRE_RGMII_TO_COPPER_88E1145     0x0b

#define MDIO_TIMEOUT  1000 /* �������ĳ�ʱ���ڣ���λ50us  */

#define GMAC_MDIOBUS_PORT    0
#define GMAC_MDIOBUS_NAME   "pv650_mdio"
#define MDIO_OK              0
#define MDIO_ERROR           0xffffffff

/* ��ʾ����clause 22  */
#define MDIO_ST_CLAUSE_22           (0x01)

/* ����MDIO clause 22�Ĳ���  */
#define MDIO_CLAUSE_22_READ         (0x02)
#define MDIO_CLAUSE_22_WRITE        (0x01)

#define MDIO_REG_ADDR_LEN            0x1000
#define MDIO_PHY_GRP_LEN             0x100
#define MDIO_REG_LEN                 0x10
#define MDIO_PHY_ADDR_NUM            5
#define MDIO_MAX_PHY_ADDR            0x1F   /* ÿ��clause 22 MDIO�������ֻ��32��PHY  */
#define MDIO_MAX_PHY_REG_ADDR        0x1F   /* Clause45 MDIO֧�ֵ�PHY�Ĵ���ƫ�Ƶ�ַ���ֻ��0x1F  */

#define MDIO_REG_ADDR(port, offset)      (MDIO_BASE_ADDR + (port) * MDIO_REG_ADDR_LEN + (offset))

#define MDIO_REG_READ(port,offset,data)  \
        ( (data) = OS_READ_REG(MDIO_REG_ADDR(port, offset), 0))

#define MDIO_REG_WRITE(port,offset,data)  \
        (OS_WRITE_REG(MDIO_REG_ADDR(port, offset), 0, data))


/* define for PHY 88E1145 end */

/* macros for accessing GMAC's register */
#define SRE_GMAC_WRITE_REG(port,offset,data)     (OS_WRITE_REG( GMAC_REG(port, offset), 0, data ))
#define SRE_GMAC_READ_REG(port,offset,data)      ( (data) = OS_READ_REG(GMAC_REG(port, offset), 0))

#define SRE_MDIO_REG_WRITE(mdio_id,offset,data)  (OS_WRITE_REG( MDIO_REG(mdio_id, offset ), 0, data ))
#define SRE_MDIO_REG_READ(mdio_id,offset,data)   ( (data) = OS_READ_REG( MDIO_REG(mdio_id, offset ), 0 ))

/* ��������ı���station address */
#define SRE_MAC_SA_LOW_REG(addr_id)              ( SRE_GMAC_STATION_ADDR_LOW_0_REG + (( addr_id )* 0x8 ))
#define SRE_MAC_SA_HIGH_REG(addr_id)             ( SRE_GMAC_STATION_ADDR_HIGH_0_REG + (( addr_id ) * 0x8 ))

/* ������ı���station address,����ͬ���������һ�� */
#define SRE_MAC_SA_MSK_LOW_REG(addr_id)          ( SRE_GMAC_STATION_ADDR_LOW_0_REG + (( addr_id )* 0x8 ))
#define SRE_MAC_SA_MSK_HIGH_REG(addr_id)         ( SRE_GMAC_STATION_ADDR_HIGH_0_REG + (( addr_id ) * 0x8 ))

#define SRE_MAC_ADDR_LOW_MSK_REG(addr_id)        ( SRE_GMAC_STATION_ADDR_LOW_MSK_0_REG + (( addr_id )* 0x8 ))
#define SRE_MAC_ADDR_HI_MSK_REG(addr_id)         ( SRE_GMAC_STATION_ADDR_HIGH_MSK_0_REG + (( addr_id ) * 0x8 ))

#define SRE_MDIO_PHY_ADDR_REG(phy_id)            (SRE_MDIO_PHY0_ADDR_REG +(phy_id)* 4)

extern UINT32 SRE_AnModeGet(UINT32 uwPort, UINT32 *pEnable);
extern UINT32 SRE_AnModeSet(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_BcPktFiltEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_ChangePortMode(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType, SRE_PORT_MODE_E enPortMode);
extern UINT32 SRE_InitGeReg(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType, SRE_PORT_MODE_E enPortMode);
extern UINT32 SRE_CheckGmacPortCfg(UINT32 uwPort);
extern UINT32 SRE_CheckPerfMonitorCfg(void);
extern UINT32 SRE_GeEnableRx( UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_GeEnableTx(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_FilterStatusShow(UINT32 uwPort);
extern UINT32 SRE_GeEnLocalMacAddr( UINT32 uwPort, UINT32 uwMacAddrEn );
extern UINT32 SRE_GeEnLocalMacAddrMask( UINT32 uwPort, UINT32 uwMacAddrEn );
extern UINT32 SRE_GetAnLinkState(UINT32 uwPort, UINT32 *puwLinkState);
extern UINT32 SRE_GetAnNegInfo(UINT32 uwPort, SRE_GMAC_TX_LOCAL_PAGE_U *punAnNegInfo);
extern UINT32 SRE_GetAnSpeed(UINT32 uwPort, SRE_AN_NEG_SPEED_E *penAnSpeed);
extern UINT32 SRE_GetDuplexType(UINT32 uwPort, SRE_DUPLEX_TYPE_E *penDuplexType);
extern UINT32 SRE_GetFcTxTmr(UINT32 uwPort, UINT32 *puwFcTxTmr);
extern UINT32 SRE_GetGmacPauseFrmCfg(UINT32 uwPort, UINT32 *puwRxPauseEn, UINT32 *puwTxPauseEn);
extern UINT32 SRE_GetInLoopBackStatus(UINT32 uwPort, UINT32* puwLoopBackStatus);
extern UINT32 SRE_GetLineLoopBackStatus(UINT32 uwPort, UINT32* puwLoopBackStatus);
extern UINT32 SRE_GetPortMode(UINT32 uwPort, SRE_PORT_MODE_E *penPortMode);
extern UINT32 SRE_GmacCrcAddEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_GmacCrcStripEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_GmacFilterStatusGet(UINT32 uwPort, SRE_MAC_FILTER_CFG_S *pMacFilter);
extern UINT32 SRE_GmacMacAddrQuery(UINT32 uwPort, UINT32 *uwMacNum, SRE_MAC_MASK_ADDR_STR_S *pstMacAddr);
extern UINT32 SRE_GmacMainMacAddrClr(UINT32 uwPort);
extern UINT32 SRE_GmacMainMacAddrQuery(UINT32 uwPort, SRE_MAC_MASK_ADDR_STR_S *pstMacAddr);
extern UINT32 SRE_GmacMainMacAddrSet(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstMacAddr);
extern UINT32 SRE_GmacPauseFrmCfg(UINT32 uwPort, UINT32 uwRxPauseEn, UINT32 uwTxPauseEn);
extern UINT32 SRE_GmacReadPhy(UINT32 uwMdioId, UINT32 uwPhyAddr, UINT32 uwPhyRegNum,
             UINT32 uwShadow);
extern UINT32 SRE_GmacRst(UINT32 uwGmacId);
extern UINT32 SRE_GmacStatisticsShow(UINT32 uwPort);
extern UINT32 SRE_GeShowShareUcMacCfg(void);
extern UINT32 SRE_InLoopBackDis(UINT32 uwPort);
extern UINT32 SRE_InLoopBackEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_InputModeSet(UINT32 uwPort, UINT32 uwMacSkip, UINT32 uwSkipCrc);
extern UINT32 SRE_LineLoopBackDis(UINT32 uwPort);
extern UINT32 SRE_LineLoopBackEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_MacAddrAdd(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstMacAddr);
extern UINT32 SRE_MacAddrDel(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstMacAddr);
extern UINT32 SRE_MacAddrFilterSet(UINT32 uwPort, const SRE_MAC_FILTER_CFG_S *pMacFilter);
extern UINT32 SRE_MacAddrShow(UINT32 uwPort);
extern UINT32 SRE_MaxFrmSizeGet(UINT32 uwPort, UINT32 *pFramSize);
extern UINT32 SRE_MaxFrmSizeSet(UINT32 uwPort, UINT32 uwFramSize);
extern UINT32 SRE_McPktFiltEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_MdioGetPhyReadVal( UINT32 uwMdioID);
extern void SRE_MdioPhyWrite(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 uwWriteValue);
extern UINT32 SRE_MdioRead(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 *puwRegValue);
extern UINT32 SRE_MdioReadReg(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum,
             UINT32 *pRegValue);
extern void SRE_MdioStartPhyRead(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum);
extern UINT32 SRE_MdioWrite(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 uwWriteValue);
extern void SRE_PerfMonitor(void);
extern void SRE_PerfMonitorInit(void);
extern UINT32 SRE_PktModeGet(UINT32 uwPort, SRE_RX_PKT_MODE_CFG_S *pstRxPktMode);
extern UINT32 SRE_PktModeSet(UINT32 uwPort, const SRE_RX_PKT_MODE_CFG_S *pstRxPktMode);
extern UINT32 SRE_PortModeGet(UINT32 uwPort, SRE_PORT_MODE_CFG_S *pstPortMode);
extern UINT32 SRE_PortModeSet(UINT32 uwPort, const SRE_PORT_MODE_CFG_S *pstPortMode);
extern UINT32 SRE_PortWorkModeGet(UINT32 uwPort, SRE_PORT_MODE_E *pMode);
extern UINT32 SRE_PortWorkModeSet(UINT32 uwPort, SRE_PORT_MODE_E enPortMode);
extern UINT32 SRE_ReadGmacStatRegs(SRE_GMAC_STAT_S *pstGmacStatInfo);
extern UINT32 SRE_RxPadStripEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_RxPadStripStatusGet(UINT32 uwPort, UINT32 *pEnValue);
extern UINT32 SRE_RxSkipLenGet(UINT32 uwPort, UINT32 *pSkipLen);
extern UINT32 SRE_RxSkipLenSet(UINT32 uwPort, UINT32 uwSkipLen);
extern UINT32 SRE_SdsLoopBackDis(UINT32 uwPort);
extern UINT32 SRE_SdsLoopBackEn(UINT32 uwPort);
extern UINT32 SRE_SdsOutLoopBackDis(UINT32 uwPort,UINT32 mode);
extern UINT32 SRE_SdsOutLoopBackEn(UINT32 uwPort,UINT32 mode);
extern UINT32 SRE_SerdesBist(UINT32 uwPort);
extern UINT32 SRE_SetAnNegInfo(UINT32 uwPort, SRE_GMAC_TX_LOCAL_PAGE_U *punAnNegInfo);
extern UINT32 SRE_SetDuplexType(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType);
extern UINT32 SRE_SetFcTxTmr(UINT32 uwPort, UINT32 uwFcTxTmr);
extern void SRE_SetGpio(void);
extern UINT32 SRE_SetPortMode(UINT32 uwPort, SRE_PORT_MODE_E enPortMode);
extern UINT32 SRE_ShortFrmPassEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_ShortFrmPassStatusGet(UINT32 uwPort, UINT32 *pEnValue);
extern UINT32 SRE_ShortFrmSizeGet(UINT32 uwPort, UINT32 *pFramSize);
extern UINT32 SRE_ShortFrmSizeSet(UINT32 uwPort, UINT32 uwFramSize);
extern UINT32 SRE_TxPadAddEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_TxPadAddStatusGet(UINT32 uwPort, UINT32 *pEnValue);
extern UINT32 SRE_UcNoLocalPktFiltEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_UpdateAnLinkTime(UINT32 uwPort, UINT32 uwAnLinkTime);

extern UINT32 SRE_GeFpgaAdapt(UINT32 uwPort);
extern UINT32 SRE_GeEnableTx(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_GeFpgaAdapt(UINT32 uwPort);
extern UINT32 SRE_GeRstDreq(VOID);
extern UINT32 SRE_InLoopBackEn(UINT32 uwPort, UINT32 uwEnValue);
extern UINT32 SRE_InitGeReg(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType, SRE_PORT_MODE_E enPortMode);
extern UINT32 SRE_MacAddrAdd(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr);
extern UINT32 SRE_MacAddrFilterSet(UINT32 uwPort, const SRE_MAC_FILTER_CFG_S *pMacFilter);

/*****************************************************************************
 �� �� ��  : SRE_GeResetDreq
 ��������  : GE��λȥ����ӿ�
 �������  : void
*****************************************************************************/
extern UINT32 SRE_GeRstDreq(void);

/* add by z00200342 2012/12/21: ��SRE_NET_DRV_SHARE_S���������˴���ȥ��ge��SRE_netdrv.h������ */

/** ��¼�˿ڵ�������Ϣ*/
typedef struct {
    UINT32 bytealign;
    UINT32 skip1;
    UINT32 skip2;
    UINT32 buffsize;
}SRE_PORT_CFG_INFO_S;


/** NetDrv ģ�鹲�����ݽṹ�� */
typedef struct tagSreNetDrvShare
{
    volatile SRE_PORT_CFG_INFO_S astSreGmacPortCfgInfo[SRE_GMAC_MAX_PORT_NUM];/**< ��¼�˿ڵ�������Ϣ */
    volatile UINT32 auwSreGmacMaxFrmSize[SRE_GMAC_MAX_PORT_NUM];/**< ����С */
}SRE_NET_DRV_SHARE_S;
/* end add */



// ============================================ phy ====================================//
#if 0
#define SRE_PHY_ERROR(fmt, arg...)      OS_DBG_PRINT(fmt, ##arg)

#define MARVELL1512_ID  0x01410dd0

#define MAR_PHY_MAX_ADDR 0x1F

#define PHY_SPEED_10M        0
#define PHY_SPEED_100M       1
#define PHY_SPEED_1000M      2

#define PHY_LINK_UNKNOW      2
#define PHY_LINK             1
#define PHY_UNLINK           0
#define PHY_LOOP             1
#define PHY_UNLOOP           0

#define PHY_AUTONEG_ENABLE   1
#define PHY_AUTONEG_DISABLE  0


/* Standard MII Registers */
#define MII_CTRL_REG            0x00    /* MII Control Register : r/w */
#define MII_STAT_REG            0x01    /* MII Status Register: ro */
#define MII_PHY_ID0_REG         0x02    /* MII PHY ID register: r/w */
#define MII_PHY_ID1_REG         0x03    /* MII PHY ID register: r/w */
#define MII_ANA_REG             0x04    /* MII Auto-Neg Advertisement: r/w */
#define MII_ANP_REG             0x05    /* MII Auto-Neg Link Partner: ro */
#define MII_AN_EXP_REG          0x06    /* MII Auto-Neg Expansion: ro */
#define MII_GB_CTRL_REG         0x09    /* MII 1000Base-T control register */
#define MII_GB_STAT_REG         0x0a    /* MII 1000Base-T Status register */
#define MII_SGB_CTRL_REG        0x0b    /* SGMII/1000-X Control Register */
#define MII_ESR_REG             0x0f    /* MII Extended Status register */

/* Non-standard MII Registers */

/*page any*/
#define MII_PAGE_ADDR_REG          0x16

/*page 0*/
#define MII_COPPER_SPEC_CTRL_1     0x10
#define MII_COPPER_SPEC_STATUS_1   0x11

/*page 2*/
#define MII_MAC_SPEC_CTRL_2        0x15

/* MII Control Register: bit definitions */

#define MII_CTRL_SS_MSB         (1 << 6)  /* Speed select, MSb */
#define MII_CTRL_CST            (1 << 7)  /* Collision Signal test */
#define MII_CTRL_FD             (1 << 8)  /* Full Duplex */
#define MII_CTRL_RAN            (1 << 9)  /* Restart Autonegotiation */
#define MII_CTRL_IP             (1 << 10) /* Isolate Phy */
#define MII_CTRL_PD             (1 << 11) /* Power Down */
#define MII_CTRL_AE             (1 << 12) /* Autonegotiation enable */
#define MII_CTRL_SS_LSB         (1 << 13) /* Speed select, LSb */
#define MII_CTRL_LE             (1 << 14) /* Loopback enable */
#define MII_CTRL_RESET          (1 << 15) /* PHY reset */

/*
 * MII Link Advertisment
 */
#define MII_ANA_ASF             (1 << 0)  /* Advertise Selector Field */
#define MII_ANA_HD_10           (1 << 5)  /* Half duplex 10Mb/s supported */
#define MII_ANA_FD_10           (1 << 6)  /* Full duplex 10Mb/s supported */
#define MII_ANA_HD_100          (1 << 7)  /* Half duplex 100Mb/s supported */
#define MII_ANA_FD_100          (1 << 8)  /* Full duplex 100Mb/s supported */
#define MII_ANA_T4              (1 << 9)  /* T4 */
#define MII_ANA_PAUSE           (1 << 10) /* Pause supported */
#define MII_ANA_ASYM_PAUSE      (1 << 11) /* Asymmetric pause supported */
#define MII_ANA_RF              (1 << 13) /* Remote fault */
#define MII_ANA_NP              (1 << 15) /* Next Page */

/*
 * 1000Base-T Control Register
 */
#define MII_GB_CTRL_ADV_1000FD  (1 << 9)  /* Advertise 1000Base-T FD */
#define MII_GB_CTRL_ADV_1000HD  (1 << 8)  /* Advertise 1000Base-T HD */
#endif


#endif/* _SRE_GMACAPI_H_ */


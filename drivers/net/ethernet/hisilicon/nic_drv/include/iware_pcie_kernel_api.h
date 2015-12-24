/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : HRD_PCIE_KERNEL_API.h
  �� �� ��   : ����
  ��    ��   : x68638
  ��������   : 2013��8��22��
  ����޸�   :
  ��������   : PCIEģ��Ķ���ͷ�ļ����ں�̬ʹ��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��8��22��
    ��    ��   : x68638
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef HRD_PCIE_KERNEL_API
#define HRD_PCIE_KERNEL_API

#include <linux/module.h>
#include <linux/types.h>
#include "hrd_module.h"
#include "iware_error.h"
#include "iware_serdes_api.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define PCIE_MAX_PORT_NUM               (4)
#define PCIE_MAX_OUTBOUND               (6)
#define PCIE_MAX_INBOUND                (4)

#define PCIE3_MAX_OUTBOUND               (16)
#define PCIE3_MAX_INBOUND                (16)


#define PCIE_LINK_LOOP_CNT          (0x1000)
#define PCIE_IATU_ADDR_MASK         (0xFFFFF000)
#define PCIE_1M_ALIGN_SHIRFT        (20)
#define PCIE_BDF_MASK               (0xF0000FFF)
#define PCIE_BUS_SHIRFT             (20)
#define PCIE_DEV_SHIRFT             (15)
#define PCIE_FUNC_SHIRFT            (12)

#define PCIE_DBI_CS2_ENABLE              (0x1)
#define PCIE_DBI_CS2_DISABLE             (0x0)

#define PCIE_DMA_MAX_BD_NUM             (0x8000)
#define PCIE_DMA_CHANLE_READ             (0x1)
#define PCIE_DMA_CHANLE_WRITE             (0x0)


/*******************************PCIE ������Ϣ����*************************/
#define PCIE_ERROR_NO_BASE               HRD_ERRNO(HRD_MID_PCIE,ERRNO)
/* iatu���ýṹ��Ϊ�� */
#define PCIE_ERR_IATU_TABLE_NULL        HRD_ERRNO(HRD_MID_PCIE,0x0) //iatu��Ϊ��
#define PCIE_ERR_LINK_OVER_TIME         HRD_ERRNO(HRD_MID_PCIE,0x1) //�ȴ�link up��ʱ
#define PCIE_ERR_UNIMPLEMENT_PCIE_TYPE  HRD_ERRNO(HRD_MID_PCIE,0x2) //δʵ�ֻ�δ֧��pcie����
#define PCIE_ERR_ALREADY_INIT           HRD_ERRNO(HRD_MID_PCIE,0x3) //�Ѿ���ʼ����
#define PCIE_ERR_PARAM_INVALID          HRD_ERRNO(HRD_MID_PCIE,0x4) //��Ч����
#define PCIE_ERR_MEM_OPT_OVER           HRD_ERRNO(HRD_MID_PCIE,0x5) //�����ĵ�ַ��Χ�������ڶ��巶Χ
#define PCIE_ERR_NOT_INIT               HRD_ERRNO(HRD_MID_PCIE,0x6) //pcieδ��ʼ��
#define PCIE_ERR_CFG_OPT_OVER           HRD_ERRNO(HRD_MID_PCIE,0x7) //PCIE ���ò����������ڷ�Χ
#define PCIE_ERR_DMA_READ_CHANLE_BUSY   HRD_ERRNO(HRD_MID_PCIE,0x8) //��ͨ����æ
#define PCIE_ERR_DMA_WRITE_CHANLE_BUSY   HRD_ERRNO(HRD_MID_PCIE,0x9) //дͨ����æ
#define PCIE_ERR_DMAR_NO_RESORCE   HRD_ERRNO(HRD_MID_PCIE,0xa) //��ͨ��û����Դ
#define PCIE_ERR_DMAW_NO_RESORCE   HRD_ERRNO(HRD_MID_PCIE,0xb) //дͨ��û����Դ
#define PCIE_ERR_DMA_OVER_MAX_RESORCE HRD_ERRNO(HRD_MID_PCIE,0xc) //dma���������Դ����
#define PCIE_ERR_NO_IATU_WINDOW             HRD_ERRNO(HRD_MID_PCIE,0xd) //δ�ҵ����ʵĴ���
#define PCIE_ERR_DMA_TRANSPORT_OVER_TIME         HRD_ERRNO(HRD_MID_PCIE,0xe)  //dma���䳬ʱ
#define PCIE_ERR_DMA_MEM_ALLOC_ERROR             HRD_ERRNO(HRD_MID_PCIE,0xf)  //�ڴ����ʧ��
#define PCIE_ERR_DMA_ABORT                      HRD_ERRNO(HRD_MID_PCIE,0x10) //dma abort
#define PCIE_ERR_UNSUPPORT_BAR_TYPE             HRD_ERRNO(HRD_MID_PCIE,0x11) //��֧�ֵ�bar����

/*1.1.2.1 PCIE�ӿ����Ͷ���*/
enum pcie_port_type_e{
    PCIE_ROOT_COMPLEX,  /* RCģʽ */
    PCIE_END_POINT, /* EPģʽ */
    PCIE_NTB_TO_NTB,            /* NTBģʽ*/
    PCIE_NTB_TO_RP,
};

enum pcie_port_gen_e{
    PCIE_GEN1_0 = 1,    /*PCIE 1.0*/
    PCIE_GEN2_0 = 2,    /*PCIE 2.0*/
    PCIE_GEN3_0 = 3 /*PCIE 3.0*/
} ;

enum pcie_port_width_e {
    PCIE_WITDH_X1 = 0x1,
    PCIE_WITDH_X2 = 0x3,
    PCIE_WITDH_X4 = 0x7,
    PCIE_WITDH_X8 = 0xf,
    PCIE_WITDH_INVALID
} ;

struct pcie_port_info_s {
    enum pcie_port_type_e port_type;    /*��¼PCIE�ӿ����ͣ�RC/EP/NTB*/
    enum pcie_port_width_e port_width;/*��¼PCIE�ӿڿ�ȣ�X1/X2/X4/X8*/
    enum pcie_port_gen_e port_gen;  /*��¼PCIE�ӿ�����,1.0/2.0/3.0*/
    int link_status;     /*��¼PCIE�ӿڵ�link״̬*/
};

struct pcie_cfg_params_s
{
    u8 swing;     //�ڷ�
	struct ffe_data ffe;//preemphasis & deemphasis
	struct dfe_data dfe;
	struct ctle_data ctle;
};

enum pcie_error_type_e
{
    PCIE_CORRECTABLE_ERROR = 0,
    PCIE_NON_FATAL_ERROR,
    PCIE_FATAL_ERROR,
    PCIE_UNSUPPORTED_REQUEST_ERROR,
    PCIE_ALL_ERROR
};

union pcie_device_status_u
{
       struct
        {
            u16 correctable_error : 1;
            u16 non_fatal_error : 1;
            u16 fatal_error : 1;
            u16 unsupported_error : 1;
            u16 aux_power : 1;
            u16 transaction_pending : 1;
            u16 reserved_6_15 : 10;
       }bits;

    u16 value;
};


union pcie_uc_aer_status_u
{
      struct
        {
            u32    undefined   : 1   ; /* [0] undefined  */
            u32    reserved_1_3   : 3   ; /* reserved */
            u32    data_link_proto_error   : 1   ; /* Data Link Protocol Error Status */
            u32    reserved_5_11   : 7   ; /* reserved */
            u32    poisoned_tlp_status   : 1   ; /* Poisoned TLP Status */
            u32    flow_control_proto_error   : 1   ; /* Flow Control Protocol Error Status */
            u32    completion_time_out   : 1   ; /* Completion Timeout Status */
            u32    compler_abort_status   : 1   ; /* Completer Abort Status */
            u32    unexpect_completion_status   : 1   ; /* Unexpected Completion Status */
            u32    receiver_overflow_status   : 1   ; /*Receiver Overflow Status */
            u32    malformed_tlp_status   : 1   ; /* Malformed TLP Status*/
            u32    ecrc_error_status   : 1   ; /* ECRC Error Status */
            u32    unsupport_request_error_status   : 1   ; /* Unsupported Request Error Status */
            u32    reserved_21   : 1   ; /*  reserved */
            u32    uncorrectable_interal_error   : 1   ; /* Uncorrectable Internal Error Status */
            u32    reserved_23   : 1   ; /* reserved*/
            u32    atomicop_egress_blocked_status   : 1   ; /* AtomicOp Egress Blocked Status */
            u32    tlp_prefix_blocked_error_status   : 1   ; /* TLP Prefix Blocked Error Status */
            u32    reserved_26_31   : 1   ; /* reserved */
       }bits;

       u32 value;
};

union pcie_co_aer_status_u
{
       struct
        {
            u32    receiver_error_status   : 1   ; /* Receiver Error Status  */
            u32    reserved_1_5   : 5   ; /* Reserved */
            u32    bad_tlp_status   : 1   ; /* Bad TLP Status */
            u32    bad_dllp_status   : 1   ; /* Bad DLLP Status */
            u32    reply_num_rollover_status   : 1   ; /* REPLAY_NUM Rollover Status*/
            u32    reserved_9_11   : 3   ; /* Reserved */
            u32    reply_timer_timeout   : 1   ; /* Replay Timer Timeout Status */
            u32    advisory_nonfatal_error   : 1   ; /* Advisory Non-Fatal Error Status*/
            u32    corrected_internal_error   : 1   ; /*Corrected Internal Error Status*/
            u32    reserved_15_31   : 1   ; /* Reserved */
       }bits;
       u32 value;
};

struct pcie_aer_status_s
{
    union pcie_uc_aer_status_u uc_aer_status;
    union pcie_co_aer_status_u co_aer_status;
};



struct pcie_loop_test_result_s
{
   u32 tx_pkts_cnt; //��������ͳ��
   u32 rx_pkts_cnt; //�հ�����ͳ��
   u32 error_pkts_cnt;  //�������
   u32 droped_pkts_cnt; //��������
   union pcie_device_status_u device_status; //�豸״̬
   struct pcie_aer_status_s    pcie_aer_status; //AER����״̬
} ;

enum pcie_dma_channel_status_e
{
    PCIE_DMA_CS_RESERVED = 0,    /* DMAͨ���ĵ�ǰ״̬ ; 0:����,1:running��2:Halted;3:Stopped*/
    PCIE_DMA_CS_RUNNING = 1,
    PCIE_DMA_CS_HALTED = 2,
    PCIE_DMA_CS_STOPPED = 3
};

enum pcie_dma_int_type_e{
    PCIE_DMA_INT_TYPE_DONE=0,
    PCIE_DMA_INT_TYPE_ABORT,
    PCIE_DMA_INT_ALL,
    PCIE_DMA_INT_NONE
};

/*pcie ��ʼ��ģʽ*/
enum pcie_mode_e
{
    PCIE_EP_DEVICE = 0x0,
    LEGACY_PCIE_EP_DEVICE = 0x1,
    RP_OF_PCIE_RC = 0x4,
    PCIE_INVALID = 0x100
};

struct pcie_ntb_port_cfg /*NTB��ʼ�����ݽṹ*/
{
    u32 pcie_if;
    struct pcie_port_info_s port_info;
    u32 ntb_is_local;
    u64 iep_bar01; /*iep bar 01*/
    u64 iep_bar23;
    u64 iep_bar45;
    u64 iep_bar01_xlat; /*NTB_TO_NTB��������*/
    u64 iep_bar23_xlat; /*iep ��ַת���Ĵ���23*/
    u64 iep_bar45_xlat;
    u64 iep_bar_lmt23; /*bar limit*/
    u64 iep_bar_lmt45; /*bar limit*/
    u64 eep_bar01;
    u64 eep_bar23;
    u64 eep_bar45;
    u64 eep_bar23_xlat;
    u64 eep_bar45_xlat;
    u64 eep_bar_lmt23; /*bar limit*/
    u64 eep_bar_lmt45; /*bar limit*/
};


struct pcie_ntb_cfg_s /*NTB��ʼ�����ݽṹ*/
{
    u64 iep_bar01_xlat; /*NTB_TO_NTB��������*/
    u64 iep_bar23_xlat; /*iep ��ַת���Ĵ���23*/
    u64 iep_bar45_xlat;
    u64 eep_bar01;
    u64 eep_bar23;
    u64 eep_bar45;
    u64 eep_bar23_xlat;
    u64 eep_bar45_xlat;
    u64 eep_bar_lmt23; /*bar limit*/
    u64 eep_bar_lmt45; /*bar limit*/
};



/*****************************************************************************
 �� �� ��  : pcie_mode_get
 ��������  : ��ȡPCIEģʽ��Ϣ�������ӿ����͡�link״̬���豸link��ȡ�link��
             ��
 �������  : u32 pcie_if
             pcie_port_info *port_info
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��6��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_mode_get(u32 pcie_if, struct pcie_port_info_s *port_info);

/*****************************************************************************
 �� �� ��  : pcie_port_ctrl
 ��������  : ���ƶ�PCIE�˿ڽ���ʹ�ܻ�ر�
 �������  :
            u32 pcie_if : pcie�������˿ں�
            u32 port_ctrl :��0���رն˿ڣ�1���򿪶˿�

 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��6��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_ctrl(u32 pcie_if, u32 port_ctrl);

/*****************************************************************************
 �� �� ��  : pcie_link_speed_set
 ��������  : ����PCIE��link����,GEN1.0,GEN2.0��GEN3.0
 �������  : u32 pcie_if
             pcie_port_gen_e speed
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��6��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_link_speed_set(u32 pcie_if,enum pcie_port_gen_e speed);

/*****************************************************************************
 �� �� ��  : pcie_port_cfg_set
 ��������  : ͨ��PCIE�˿����ã��豸PCIE�˿ڵ�Ԥ���ء�ȥ���ء��ڷ�������ȹ�
             ��
 �������  : u32 pcie_if
             pcie_cfg_params *cfg_params
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_cfg_set(u32 pcie_if, struct pcie_cfg_params_s *cfg_params);

/*****************************************************************************
 �� �� ��  : pcie_port_cfg_get
 ��������  : ��ȡĳ��PCIE�˿ڵ�Ԥ���ء�ȥ���ء��ڷ�������ȵ�����
 �������  : u32 pcie_if
             pcie_cfg_params *cfg_params
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_cfg_get(u32 pcie_if, struct pcie_cfg_params_s *cfg_params);

/*****************************************************************************
 �� �� ��  : pcie_switch_clock
 ��������  : ����PCIEʱ�ӵĹرպͿ���
 �������  : u32 pcie_if
             u32 clock_on
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��12��30��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_switch_clock(u32 pcie_if, u32 clock_on);

/*****************************************************************************
 �� �� ��  : pcie_dma_cur_status_get
 ��������  : ��ȡPCIE DMA����ͨ���ĵ�ǰ����״̬
 �������  : u32 pcie_if
             u32 channel
             pcie_dma_channel_status_e *dma_channel_status
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern void pcie_dma_cur_status_get(u32 pcie_if, u32 channel, enum pcie_dma_channel_status_e *dma_channel_status);

/*****************************************************************************
 �� �� ��  : pcie_dma_int_enable
 ��������  : PCIE DMAͨ�����ж�ʹ�ܿ���
 �������  : u32 pcie_if
             u32 channel
             pcie_dma_int_type_e int_type
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern void pcie_dma_int_enable(u32 pcie_if, u32 channel, enum pcie_dma_int_type_e int_type);

/*****************************************************************************
 �� �� ��  : pcie_dma_int_mask
 ��������  : PCIE DMAͨ�����ж����ο���
 �������  : u32 pcie_if
             u32 channel
             pcie_dma_int_type_e int_type
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern void pcie_dma_int_mask(u32 pcie_if, u32 channel, enum pcie_dma_int_type_e int_type);

/*****************************************************************************
 �� �� ��  : pcie_dma_tranfer_stop
 ��������  : PCIE DMAͨ�������ݴ�����ֹ����ӿ�
 �������  : u32 pcie_if
             u32 channel
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern void pcie_dma_tranfer_stop(u32 pcie_if, u32 channel);


/*****************************************************************************
 �� �� ��  : pcie_dma_int_status_get
 ��������  : PCIE DMA�ж�ԭ���ȡ
 �������  : u32 pcie_if
             u32 channel
             pcie_dma_int_type_e *dma_int_status
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern void pcie_dma_int_status_get(u32 pcie_if, u32 channel, int *dma_int_status);

/*****************************************************************************
 �� �� ��  : pcie_dma_int_clear
 ��������  : ���ĳ��DMAͨ�����ж�ԭ��Ĵ���
 �������  : u32 pcie_if
             u32 channel
             pcie_dma_int_type_e dma_int_type
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern void pcie_dma_int_clear(u32 pcie_if, u32 channel, enum pcie_dma_int_type_e dma_int_type);


/*****************************************************************************
 �� �� ��  : pcie_dma_read
 ��������  : PCIE DMA�����ݽӿ�
 �������  :
            u32 pcie_if : pcie�������˿�
            Void *source : ���ݴ���Դ��ַ����Ϊ64λ��ַ��
            Void *dest : ���ݴ���Ŀ�ĵ�ַ����Ϊ64λ��ַ��
            u32 transferSize : �������ݵ��ܳ���
            u32 burstSize : һ�δ�������ݳ���

 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 PCIE DMA�����ݽӿڣ�֧�ֿ鴫�����ʽ���䣬transferSize��СΪ1B-4GB������burstSize
 ��С���Զ�������ʽ�������һ���ԵĿ鴫��
 �˽ӿ�Ϊ�첽�ӿ�
 source��ַָ��ָ������ݵ�Դ��ַ�����ڷ�NTB�˿ڣ��˵�ַӦ������ĳ��EP��Memroy BAR��ַ�ռ������NTB
 ģʽ���˵�ַӦ������PBAR23��PBAR45����ĵ�ַ�ռ���
 dest��ַָ��ָ������ݵ�Ŀ�ĵ�ַ���˵�ַӦΪ���ص��ڴ��ַ�ռ�

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_dma_read(u32 pcie_if,void *source, void *dest,u32 transfer_size, u32 burst_size);

/*****************************************************************************
 �� �� ��  : pcie_dma_write
 ��������  : PCIE DMAд���ݽӿ�
 �������  :
            u32 pcie_if : pcie�������˿�
            Void *source : ���ݴ���Դ��ַ����Ϊ64λ��ַ��
            Void *dest : ���ݴ���Ŀ�ĵ�ַ����Ϊ64λ��ַ��
            u32 transferSize : �������ݵ��ܳ���
            u32 burstSize : һ�δ�������ݳ���

 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 PCIE DMAд���ݽӿڣ�֧�ֿ鴫�����ʽ���䣬transferSize��СΪ1B-4GB������burstSize
 ��С���Զ�������ʽ�������һ���ԵĿ鴫��
 �˽ӿ�Ϊ�첽�ӿ�
 source��ַָ��ָ��д���ݵ�Դ��ַ���˵�ַӦΪ���ص��ڴ��ַ�ռ�
 dest��ַָ��ָ��д���ݵ�Ŀ�ĵ�ַ�����ڷ�NTB�˿ڣ��˵�ַӦ������ĳ��EP��Memory BAR��ַ�ռ������NTB
 �˿ڣ��˵�ַӦ������PBAR23��PBAR45����ĵ�ַ�ռ��
 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_dma_write(u32 pcie_if,void *source, void *dest,u32 transfer_size, u32 burst_size);

/*****************************************************************************
 �� �� ��  : pcie_setup_ntb
 ��������  : ��ĳ���˿ڽ���NTB�ĳ�ʼ����
 �������  : u32 pcie_if: pcie�������˿ں�
             pcie_ntg_cfg *ntb_cfg: NTB���ýṹ��
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_setup_ntb(u32 pcie_if,struct pcie_ntb_cfg_s *ntb_cfg);

/*****************************************************************************
 �� �� ��  : pcie_ntb_doorbell_send
 ��������  : ʵ��NTB����ϵͳ֮���Doorbell�жϷ��͹���
 �������  :
 �������    u32 pcie_if : pcie�������˿ں�
             u32 doorbell : doorbell�жϺţ�֧�ַ�ΧΪ0-31

 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_ntb_doorbell_send(u32 pcie_if,u32 doorbell);

/*****************************************************************************
 �� �� ��  : pcie_loop_test_start
 ��������  : ����PCIE�˿ڵĻ��ز��Թ���
 �������  :
                u32 pcie_if : pcie�������˿ں�
                u32 loop_type : 0:���˻��أ�1��Զ�˻���

 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_loop_test_start(u32 pcie_if, u32 loop_type);

/*****************************************************************************
 �� �� ��  : pcie_loop_test_stop
 ��������  : �ر�PCIE�˿ڵĻ��ز��Թ���
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 loop_type : 0:���˻��أ�1��Զ�˻���
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_loop_test_stop(u32 pcie_if, u32 loop_type);

/*****************************************************************************
 �� �� ��  : pcie_loop_test_get
 ��������  : ��ȡPCIE���ز��Խ��
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 loop_type : 0:���˻��أ�1��Զ�˻���
 �������  : pcie_loop_test_result_s *test_result : ��¼PCIE���ز��Խ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_loop_test_get(u32 pcie_if, u32 loop_type, struct pcie_loop_test_result_s *test_result);

/*****************************************************************************
 �� �� ��  : pcie_loop_test
 ��������  : PCIE���ز��ԣ���д�ڴ�
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 test_bytes : ���Ե��ֽ���
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_loop_test(u32 pcie_if, u32 test_bytes);

/*****************************************************************************
 �� �� ��  : pcie_port_reset
 ��������  : PCIE�˿ڸ�λ����λ��PCIE�˿��µ������豸�������˿ڱ���
 �������  : u32 pcie_if : pcie�������˿ں�
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_reset(u32 pcie_if);

/*****************************************************************************
 �� �� ��  : pcie_port_error_report_enable
 ��������  : ʹ��PCIE�˿ڵĴ����ϱ�����
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 bus �� ���ߺ�
             u32 dev �� �豸��
             u32 func �� ���ܺ�
             pcie_error_type_e pcie_error : PCIE�������ͣ�ö���Ͳ���
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_error_report_enable(u32 pcie_if, u32 bus, u32 dev, u32 func,enum pcie_error_type_e pcie_error);

/*****************************************************************************
 �� �� ��  : pcie_port_error_report_disable
 ��������  : ��ֹPCIE�˿ڵĴ����ϱ�����
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 bus �� ���ߺ�
             u32 dev �� �豸��
             u32 func �� ���ܺ�
             pcie_error_type_e pcie_error : PCIE�������ͣ�ö���Ͳ���
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_error_report_disable(u32 pcie_if, u32 bus, u32 dev, u32 func,enum pcie_error_type_e pcie_error);

/*****************************************************************************
 �� �� ��  : pcie_device_error_status_get
 ��������  : ��ȡPCIE�豸�Ĵ���״̬����AER����
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 bus �� ���ߺ�
             u32 dev �� �豸��
             u32 func �� ���ܺ�
             u32 clear : �����Ƿ���0��Ϊ1��ʾ���󽫴���״̬���㣬��������
 �������  : pcie_device_status_u *pcie_stat : PCIE����״̬�ṹ�壬��¼PCIE�Ĵ���״̬��Ϣ
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_device_error_status_get(u32 pcie_if, u32 bus, u32 dev, u32 func,u32 clear, \
union pcie_device_status_u *pcie_stat);

/*****************************************************************************
 �� �� ��  : pcie_port_aer_cap_get
 ��������  : ��ȡĳ��PCIE�˿��豸�Ƿ�֧��AER����
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 bus �� ���ߺ�
             u32 dev �� �豸��
             u32 func �� ���ܺ�
 �������  : u32 *aer_cap : �Ƿ�֧��AER���ܣ�0��֧�֣�1֧��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_aer_cap_get(u32 pcie_if, u32 bus, u32 dev, u32 func,u32 *aer_cap);

/*****************************************************************************
 �� �� ��  : pcie_port_aer_status_get
 ��������  : ��ȡĳ��PCIE�˿��豸����AER������Ϣ
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 bus �� ���ߺ�
             u32 dev �� �豸��
             u32 func �� ���ܺ�
 �������  : pcie_uc_aer_status_u *pcie_aer_status : PCIE�˿�AER����״̬�ṹ�壬��¼���е�AER����״̬��Ϣ
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_aer_status_get(u32 pcie_if, u32 bus, u32 dev, u32 func,union pcie_uc_aer_status_u *pcie_aer_status);

/*****************************************************************************
 �� �� ��  : pcie_port_aer_status_clr
 ��������  : ���ĳ��PCIE�˿��豸���е�AER����״̬
 �������  : u32 pcie_if : pcie�������˿ں�
             u32 bus �� ���ߺ�
             u32 dev �� �豸��
             u32 func �� ���ܺ�
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_aer_status_clr(u32 pcie_if, u32 bus, u32 dev, u32 func);

/*****************************************************************************
 �� �� ��  : pcie_port_aer_report_enable
 ��������  : ʹ��PCIE�˿ڵ�AER�����ж��ϱ�
 �������  : u32 pcie_if : pcie�������˿ں�
             pcie_error_type_e pcie_aer_type ��AER��������
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_aer_report_enable(u32 pcie_if, enum pcie_error_type_e pcie_aer_type);


/*****************************************************************************
 �� �� ��  : pcie_port_aer_report_disable
 ��������  : �ر�PCIE�˿ڵ�AER�����ж��ϱ�
 �������  : u32 pcie_if : pcie�������˿ں�
             pcie_error_type_e pcie_aer_type��AER��������
 �������  : ��
 �� �� ֵ  : int
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8��
    ��    ��   : z00228490
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int pcie_port_aer_report_disable(u32 pcie_if, enum pcie_error_type_e pcie_aer_type);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

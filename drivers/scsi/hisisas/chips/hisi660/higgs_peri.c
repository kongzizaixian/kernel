/******************************************************************************

                  ��Ȩ���� (C) ��Ϊ�������޹�˾

******************************************************************************
     	�� �� ��   : higgs_peri.c
     	�� �� ��   : ����
     	��    ��   : 
     	��������   : 2014��7��30��
     	����޸�   :
     	��������   : higgs����Ĺ������ʣ���ʼ�� 
     	�����б�   :
     	�޸���ʷ   :
     	1.��    ��   : 2014��7��29��
     	  ��    ��   :  z00171046
     	  �޸�����   : �����ļ�

******************************************************************************/
#include "higgs_common.h"
#include "higgs_peri.h"
#include "higgs_stub.h"
#include "higgs_pv660.h"
#include "higgs_intr.h"

/*----------------------------------------------*
 * �ⲿ����˵��                                 *
 *----------------------------------------------*/
/*----------------------------------------------*
 * �ⲿ����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

/* C05Ӳ��ƽ̨����  */
#define C05_BOARD_INNER_PORT_LL_ID  0x0
//#define C05_CPU_OUTER_PORT_LL_ID    0x1
#define C05_CPU_OUTER_PORT_MINI_ID  0x1
/* #define C05_EXP_OUTER_PORT_MINI_ID  0x0 */

#define CPLD_REG_BASE               (0x100)
#define CPLD_LED_MINISAS1_REG       (CPLD_REG_BASE + 0x219)
#define CPLD_LED_12G_LINK			((u8)(0x4 | 0x2 | 0x0))
#define CPLD_LED_6G_LINK            ((u8)(0x4 | 0x0 | 0x1))
#define CPLD_LED_FAULT_LINK         ((u8)(0x0 | 0x2 | 0x1))
#define CPLD_LED_NO_LINK            ((u8)(0x4 | 0x2 | 0x1))

#define CPLD_SFP_PRSNT_REG           (CPLD_REG_BASE + 0x218)
#define CPLD_SFP_PRSNT_MINISAS1_MASK ((u8)0x1)
#define CPLD_SFP_PRSNT_MINISAS1      ((u8)0x0)

#define I2C_9545_CHNL                				1
#define I2C_9545_ADDR                				0xE0
#define I2C_9545_ROUTE_TO_NONE                      0x0
#define I2C_9545_ROUTE_TO_MINISAS1_PORT             (0x1 << 0)
#define I2C_MINISAS1_PORT_ADDR						0xA0

#define I2C_9545_ROUTE_TO_MINISAS1_REDRIVER         (0x1 << 3)
#define I2C_MINISAS1_REDRIVER_LOWER_ADDR     		0xA2
#define I2C_MINISAS1_REDRIVER_UPPER_ADDR            0xA4
#define C05_MINISAS1_REDRIVER_CHNL_EQ_PARAM         ((u8)((0xC << 4) | (0x2 << 2) | (0x2 << 0)))
#define REDRIVER_CHNL_1_4_CTRL_OFFSET               0x5
#define REDRIVER_CHNL_1_4_CTRL_MASK                 0x1f
#define REDRIVER_CHNL_1_4_CTRL_ENABLE               0x10
#define REDRIVER_CHNL_1_4_CTRL_DISABLE              0x1f
#define REDRIVER_CHNL_5_8_CTRL_OFFSET               0x5
#define REDRIVER_CHNL_5_8_CTRL_MASK                 0x1f
#define REDRIVER_CHNL_5_8_CTRL_ENABLE               0x10
#define REDRIVER_CHNL_5_8_CTRL_DISABLE              0x1f
#define REDRIVER_CHNL_NUM_MAX						0x8

#define SFP_EEPROM_PAGE_SEL_OFFSET  127

int bsp_i2c_simple_read( int chan, unsigned char slave_addr, unsigned int sub_addr, char* obuffer, unsigned int rx_len , int sub_addr_len);
int bsp_i2c_simple_write(int chan, unsigned char slave_addr, unsigned int sub_addr, char* ibuffer, unsigned int tx_len , int sub_addr_len);
static s32 higgs_sfp_page_select(struct higgs_card *ll_card, u32 ll_port_id,
				 u32 page_sel);

static s32 higgs_read_sfp_eeprom(struct higgs_card *ll_card,
				 u32 ll_port_id,
				 u8 * page, u32 rd_len, u32 offset);

static s32 higgs_simulate_read_sfp_eeprom_inner_port(struct higgs_card *ll_card,
						     u32 ll_port_id,
						     u8 * page,
						     u32 rd_len, u32 offset);

static s32 higgs_sfp_on_port(struct higgs_card *ll_card, u32 ll_port_id,
			     bool * is_on_port);

static s32 higgs_led_ctrl(struct higgs_card *ll_card, u32 ll_port_id,
			  enum sal_led_op_type led_op);

static void higgs_sfp_event_handler(void *param);

static bool higgs_is_board_inner_port(struct higgs_card *ll_card,
				      u32 ll_port_id);

static u32 higgs_get_hw_version(void);

static s32 higgs_init_sas_redriver_addr(struct higgs_card *ll_card);

static s32 higgs_config_sas_redriver_channel_param(struct higgs_card *ll_card);

static s32 higgs_enable_sas_redriver_channel(struct higgs_card *ll_card);

static s32 higgs_disable_sas_redriver_channel(struct higgs_card *ll_card);

static bool higgs_ll_port_exist(struct higgs_card *ll_card, u32 ll_port_id);

static s32 higgs_open_i2c_9545_route(u32 route);

static void higgs_close_i2c_9545_route(void);

//void Higgs_NotifySfpEvent(unsigned long v_ulData);

enum higgs_i2c_offset_size {
	HIGGS_I2C_OFFSET_NONE = 0,
	HIGGS_I2C_OFFSET_ONE_BYTE = 1
/*	HIGGS_I2C_OFFSET_TWO_BYTE, */
/*	HIGGS_I2C_OFFSET_BUTT  */
};

static s32 higgs_i2c_wirte(u8 chan,
			   u8 addr,
			   u32 offset,
			   enum higgs_i2c_offset_size offset_size,
			   u8 * buff, u32 buff_size);

static s32 higgs_i2c_read(u8 chan,
			  u8 addr,
			  u32 offset,
			  enum higgs_i2c_offset_size offset_size,
			  u8 * buff, u32 buff_size);

/*----------------------------------------------*
 * ȫ�ֱ���                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/
static struct higgs_card *higgs_peri_cards[HIGGS_MAX_CARD_NUM];

static struct intr_event_handler sfp_event_handle = {
#if defined(C05_VERSION_TEST)
	INT_MINISASHD,
#else
	0,
#endif
	higgs_sfp_event_handler
};

static const u32 i2c_mini_sas1_redriver_chan_addr[REDRIVER_CHNL_NUM_MAX] = {
	I2C_MINISAS1_REDRIVER_LOWER_ADDR,
	I2C_MINISAS1_REDRIVER_LOWER_ADDR,
	I2C_MINISAS1_REDRIVER_LOWER_ADDR,
	I2C_MINISAS1_REDRIVER_LOWER_ADDR,
	I2C_MINISAS1_REDRIVER_UPPER_ADDR,
	I2C_MINISAS1_REDRIVER_UPPER_ADDR,
	I2C_MINISAS1_REDRIVER_UPPER_ADDR,
	I2C_MINISAS1_REDRIVER_UPPER_ADDR
};

static const u32 redriver_chan_offset[REDRIVER_CHNL_NUM_MAX] = {
	0x1, 0x2, 0x3, 0x4, 0x1, 0x2, 0x3, 0x4
};

/*----------------------------------------------*
 * ����ӿ�ʵ��                                   *
 *----------------------------------------------*/

/*****************************************************************************
 �� �� ��  : higgs_locate_ll_card_and_ll_port_id_by_mini_port_id
 ��������  : ͨ������MINI SAS�˿�ID����λ��Ӧ��LL Card��LL�˿�ID
 �������  : u32 v_uiMiniSasPortId,
 �������  : struct higgs_card **ret_ll_card,
		  u32 *ret_ll_port_id
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_locate_ll_card_and_ll_port_id_by_mini_port_id(u32 mini_port_id,
							struct higgs_card
							**ret_ll_card,
							u32 * ret_ll_port_id)
{
	u32 card_id;
	u32 ll_port_id;
	struct higgs_card *ll_card;
	struct higgs_config_info *cfg_info;

	/* ������� */
	HIGGS_ASSERT(NULL != ret_ll_card, return ERROR);
	HIGGS_ASSERT(NULL != ret_ll_port_id, return ERROR);
	HIGGS_ASSERT(HIGGS_INVALID_PORT_ID != mini_port_id, return ERROR);

	/* ����ƥ�� */
	for (card_id = 0; card_id < HIGGS_MAX_CARD_NUM; card_id++) {
		ll_card = higgs_peri_cards[card_id];
		if (NULL == ll_card)
			continue;
		cfg_info = &ll_card->card_cfg;
		for (ll_port_id = 0; ll_port_id < HIGGS_MAX_PORT_NUM;
		     ll_port_id++)
			if (((const u32)mini_port_id) ==
			    cfg_info->port_mini_id[ll_port_id]) {
				*ret_ll_card = ll_card;
				*ret_ll_port_id = ll_port_id;
				return OK;
			}
	}

	return ERROR;
}

/*****************************************************************************
 �� �� ��  : higgs_locate_mini_port_id_by_ll_port_id
 ��������  : ͨ��LL�˿�ID����λ��Ӧ�ĵ���MINI SAS�˿�ID
 �������  : struct higgs_card *ll_card,
		   u32  ll_port_id
 �������  : u32 *mini_port_id
 �� �� ֵ  : s32
 *****************************************************************************/
s32 higgs_locate_mini_port_id_by_ll_port_id(struct higgs_card * ll_card,
					    u32 ll_port_id, u32 * mini_port_id)
{
	u32 tmp_mini_port;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);

	/* �������ж�ȡ  */
	tmp_mini_port = ll_card->card_cfg.port_mini_id[ll_port_id];
	if (HIGGS_INVALID_PORT_ID != tmp_mini_port) {
		*mini_port_id = tmp_mini_port;
		return OK;
	}

	return ERROR;
}

/*****************************************************************************
 �� �� ��  : higgs_locate_ll_port_id_by_phy_id
 ��������  : ͨ��LL Card���ú�PHY ID����λ��Ӧ��LL��˿�ID
 �������  : struct higgs_card *ll_card,
		   u32 phy_id
 �������  : u32 *ret_ll_port_id
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_locate_ll_port_id_by_phy_id(struct higgs_card * ll_card,
				      u32 phy_id, u32 * ret_ll_port_id)
{
	u32 i;
	u32 port_bit_map;
	u32 tgt_bit_mask;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(phy_id < HIGGS_MAX_PHY_NUM, return ERROR);

	/* ����ƥ�� */
	tgt_bit_mask = (0x1 << phy_id);
	for (i = 0; i < HIGGS_MAX_PORT_NUM; i++) {
		port_bit_map = ll_card->card_cfg.port_bitmap[i];
		/* PHY���� */
		if (0 != (port_bit_map & tgt_bit_mask)) {
			*ret_ll_port_id = i;
			return OK;
		}
	}
	return ERROR;
}

/*****************************************************************************
 �� �� ��  : higgs_subscribe_sfp_event
 ��������  : ��BSP����SFP����¼�
 �������  : ��
 �������  : ��
 �� �� ֵ  : void
*****************************************************************************/
void higgs_subscribe_sfp_event(void)
{
	u32 hw_ver = higgs_get_hw_version();

	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return;
	}
        if(NULL == sal_peripheral_operation.register_int_handler)
       {
             HIGGS_TRACE(OSP_DBL_MAJOR, 171,
                        "sal_peripheral_operation.register_int_handler is null.");
       }else if (OK != sal_peripheral_operation.register_int_handler(&sfp_event_handle))
		HIGGS_TRACE(OSP_DBL_MAJOR, 171,
                       "Subscribe SFP hotplug event failed");
}

/*****************************************************************************
 �� �� ��  : higgs_unsubscribe_sfp_event
 ��������  : ��BSPȡ������SFP����¼�
 �������  : ��
 �������  : ��
 �� �� ֵ  : void
*****************************************************************************/
void higgs_unsubscribe_sfp_event(void)
{
	u32 hw_ver = higgs_get_hw_version();

	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return;
	}
        if(NULL == sal_peripheral_operation.unregister_int_handler)
       {
               HIGGS_TRACE(OSP_DBL_MAJOR, 171,
                        "sal_peripheral_operation.unregister_int_handler is null");
        }else if (OK != sal_peripheral_operation.unregister_int_handler(sfp_event_handle.int_event))
		HIGGS_TRACE(OSP_DBL_MAJOR, 171,
			    "UnSubscribe SFP hotplug event failed");
}

/*****************************************************************************
 �� �� ��  : higgs_init_peri_device
 ��������  : ��ʼ������
 �������  : struct higgs_card *ll_card
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_init_peri_device(struct higgs_card *ll_card)
{
	u32 hw_ver = higgs_get_hw_version();

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_card->card_id < HIGGS_MAX_CARD_NUM, return ERROR);

	/* ��ʱ����LL CARD���� */
	HIGGS_ASSERT(NULL == higgs_peri_cards[ll_card->card_id], return ERROR);
	higgs_peri_cards[ll_card->card_id] = ll_card;

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation skipped on platform %d", hw_ver);
		return OK;
	}

	/* ��ʼ��SAS Redriver��ַ */
	if (OK != higgs_init_sas_redriver_addr(ll_card)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d init redriver addr failed",
			    ll_card->card_id);
		return ERROR;
	}
	HIGGS_TRACE(OSP_DBL_INFO, 171, "Card:%d init redriver addr succeeded",
		    ll_card->card_id);

	/* ����SAS Redriverͨ�� */
	if (OK != higgs_disable_sas_redriver_channel(ll_card)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d disable redriver channel failed",
			    ll_card->card_id);
		return ERROR;
	}
	HIGGS_TRACE(OSP_DBL_INFO, 171,
		    "Card:%d disable redriver channel succeeded",
		    ll_card->card_id);

	/* ����SAS Redriver�źŲ��� */
	if (OK != higgs_config_sas_redriver_channel_param(ll_card)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d config redriver channel param failed",
			    ll_card->card_id);
		return ERROR;
	}
	HIGGS_TRACE(OSP_DBL_INFO, 171,
		    "Card:%d config redriver channel param succeeded",
		    ll_card->card_id);

	/* ʹ��SAS Redriverͨ�� */
	if (OK != higgs_enable_sas_redriver_channel(ll_card)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d enable redriver channel failed",
			    ll_card->card_id);
		return ERROR;
	}
	HIGGS_TRACE(OSP_DBL_INFO, 171,
		    "Card:%d enable redriver channel succeeded",
		    ll_card->card_id);

	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_init_peri_device
 ��������  : ����ʼ������
 �������  : struct higgs_card *ll_card
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_uninit_peri_device(struct higgs_card * ll_card)
{
	u32 hw_ver = higgs_get_hw_version();

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_card->card_id < HIGGS_MAX_CARD_NUM, return ERROR);

	/* �Ƴ�LL CARD���� */
	HIGGS_ASSERT(NULL != higgs_peri_cards[ll_card->card_id], return ERROR);
	higgs_peri_cards[ll_card->card_id] = NULL;

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation skipped on platform %d", hw_ver);
		return OK;
	}

	/* ����SAS Redriverͨ�� */
	if (OK != higgs_disable_sas_redriver_channel(ll_card)) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d disable redriver channel failed",
			    ll_card->card_id);
		return ERROR;
	}
	HIGGS_TRACE(OSP_DBL_INFO, 171,
		    "Card:%d disable redriver channel succeeded",
		    ll_card->card_id);

	return OK;
}

/*****************************************************************************
 �� �� ��  : Higgs_RegOperation
 ��������  :GPIO������quark��ͳһ�ӿڣ�
          PV660/Hi1610��������SASģ��û��������GPIO�ܽţ���˸ýӿ�ʵ��Ϊ��
 �������  :struct sal_card *sal_card,
		enum sal_led_op_type gpio_op_type,
 		void *argv_in
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_gpio_operation(struct sal_card * sal_card,
			 enum sal_gpio_op_type gpio_op_type, void *argv_in)
{
	/* PV660/Hi1610ƽ̨û�е�����SAS GPIO���� */
	HIGGS_REF(sal_card);
	HIGGS_REF(gpio_op_type);
	HIGGS_REF(argv_in);
	HIGGS_TRACE(OSP_DBL_INFO, 151,
		    "GPIO operation unsupported on higgs platform.");

	return ERROR;
}

/*****************************************************************************
 �� �� ��  : higgs_check_sfp_on_port
 ��������  : �ж϶˿�SFP�Ƿ���λ
 �������  : struct sal_card *sal_card,
			u32 *logic_port_id
 �������  :
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_check_sfp_on_port(struct sal_card * sal_card, u32 * logic_port_id)
{
	u32 ll_port_id;
	bool is_on_port;
	struct higgs_card *ll_card;

	/* ������� */
	HIGGS_ASSERT(NULL != sal_card, return ERROR);
	HIGGS_ASSERT(NULL != logic_port_id, return ERROR);

	ll_card = (struct higgs_card *)sal_card->drv_data;
	HIGGS_ASSERT(NULL != ll_card, return ERROR);

	ll_port_id = HIGGS_LOGIC_PORT_ID_TO_LL_PORT_ID(*logic_port_id);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);

	/* ��ȡSFP��λ��Ϣ  */
	if (OK != higgs_sfp_on_port(ll_card, ll_port_id, &is_on_port)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
			    "Card:%d check sfp presence failed on port:%d",
			    ll_card->card_id, ll_port_id);
		return ERROR;
	}

	return is_on_port ? OK : ERROR;
}

/*****************************************************************************
 �� �� ��  : higgs_get_sfp_info_intf
 ��������  : ��ȡSFP EEPROM��ĳ��Page
 �������  : struct sal_card *sal_card,
			void *argv_in
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_get_sfp_info_intf(struct sal_card * sal_card, void *argv_in)
{
	struct higgs_card *ll_card = NULL;
	u32 page_sel = 0;
	u32 shift_offset = 0;
	u32 len = 0;
	u32 ll_port_id = 0;
	u8 *tmp_page = NULL;
	struct sal_sfp_get_info_param *sfp_get_info = NULL;

	/* �������  */
	HIGGS_ASSERT(NULL != sal_card, return ERROR);
	HIGGS_ASSERT(NULL != argv_in, return ERROR);
	ll_card = (struct higgs_card *)sal_card->drv_data;

	sfp_get_info = (struct sal_sfp_get_info_param *)argv_in;
	tmp_page = (u8 *) sfp_get_info->argv_out;
	page_sel = sfp_get_info->page_sel;
	shift_offset = sfp_get_info->shift_offset;
	len = sfp_get_info->len;
	ll_port_id = HIGGS_LOGIC_PORT_ID_TO_LL_PORT_ID(sfp_get_info->port_id);

	/*д��ģ���127byte��ѡ��upper page, ����ƴ���ض��Ĺ�ģ�������Ϣ */
	if (SAL_OPTICAL_CABLE ==
	    sal_card->port_curr_wire_type[ll_port_id & 0x1f])
		if (OK != higgs_sfp_page_select(ll_card, ll_port_id, page_sel)) {
			HIGGS_TRACE(OSP_DBL_MAJOR, 4428,
				    "Card:%d select sfp page failed on port:0x%x!",
				    ll_card->card_id, ll_port_id);
			return ERROR;
		}

	/* ��ȡѡ����upper page */
	if (OK != higgs_read_sfp_eeprom(ll_card,
					ll_port_id,
					tmp_page, len, shift_offset)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4133,
			    "Card:%d read sfp page failed on port:0x%x",
			    ll_card->card_id, ll_port_id);
		return ERROR;
	}

	/* ����ѡ��upper page 0 */
	if (SAL_OPTICAL_CABLE ==
	    sal_card->port_curr_wire_type[ll_port_id & 0x1f])
		if (OK != higgs_sfp_page_select(ll_card, ll_port_id, 0)) {
			HIGGS_TRACE(OSP_DBL_MAJOR, 4428,
				    "Card:%d select sfp page failed on port:0x%x!",
				    ll_card->card_id, ll_port_id);
			return ERROR;
		}

	return OK;

}

/*****************************************************************************
 �� �� ��  : higgs_read_wire_eep_intf
 ��������  : ��ȡSFP EEPROM��Page 0
 �������  : struct sal_card *sal_card,
			void *argv_in
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_read_wire_eep_intf(struct sal_card * sal_card, void *argv_in)
{
	u8 *tmp_page = NULL;
	u32 ll_port_id = 0;
	struct sal_sfp_get_info_param *sfp_get_info = NULL;
	struct higgs_card *ll_card = NULL;

	/* ������� */
	HIGGS_ASSERT(NULL != sal_card, return ERROR);
	HIGGS_ASSERT(NULL != argv_in, return ERROR);

	ll_card = (struct higgs_card *)sal_card->drv_data;
	sfp_get_info = (struct sal_sfp_get_info_param *)argv_in;
	tmp_page = (u8 *) (sfp_get_info->argv_out);
	ll_port_id = HIGGS_LOGIC_PORT_ID_TO_LL_PORT_ID(sfp_get_info->port_id);

	/*���º͵��¶�һ�ζ�ȡ256 Bytes, ���ϲ��������һ��upper page */
	if (OK != higgs_read_sfp_eeprom(ll_card,
					ll_port_id,
					tmp_page,
					HIGGS_SFP_REGISTER_PAGE_LENGEH, 0)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4133,
			    "Card:%d read sfp eeprom failed on port:0x%x",
			    sal_card->card_no, ll_port_id);
		return ERROR;
	}

	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_led_operation
 ��������  : �˿�LED���
 �������  :struct sal_card * sal_card,
 	 	  struct sal_led_op_param* v_pstLEDPara
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
s32 higgs_led_operation(struct sal_card * sal_card,
			struct sal_led_op_param * led_op)
{
	u32 phy_id = 0;
	u32 ll_port_id = 0;
	struct higgs_card *ll_card = NULL;

	/* �������  */
	HIGGS_ASSERT(NULL != sal_card, return ERROR);
	HIGGS_ASSERT(NULL != led_op, return ERROR);

	ll_card = (struct higgs_card *)sal_card->drv_data;
	HIGGS_ASSERT(NULL != ll_card, return ERROR);

	/* ��� */
	if (SAL_ALL_PORT_LED_NEED_OPT == led_op->all_port_op) {
		/* ���ж˿ڵ�� */
		for (ll_port_id = 0; ll_port_id < HIGGS_MAX_PORT_NUM;
		     ll_port_id++) {
			/* �˿��Ƿ���Ч */
			if (!higgs_ll_port_exist(ll_card, ll_port_id))
				continue;

			/* ��� */
			if (OK !=
			    higgs_led_ctrl(ll_card, ll_port_id,
					   led_op->
					   all_port_speed_led[ll_port_id]))
				HIGGS_TRACE(OSP_DBL_MINOR, 4576,
					    "Card:%d LED ctrl %d failed on port %d",
					    ll_card->card_id,
					    led_op->
					    all_port_speed_led[ll_port_id],
					    ll_port_id);
		}
	} else if (SAL_LED_ALL_OFF == led_op->port_speed_led) {
		/* ���ж˿�Ϩ��  */
		for (ll_port_id = 0; ll_port_id < HIGGS_MAX_PORT_NUM;
		     ll_port_id++) {
			/* �˿��Ƿ���Ч */
			if (!higgs_ll_port_exist(ll_card, ll_port_id))
				continue;

			/* Ϩ�� */
			if (OK !=
			    higgs_led_ctrl(ll_card, ll_port_id, SAL_LED_OFF))
				HIGGS_TRACE(OSP_DBL_MINOR, 4576,
					    "Card:%d LED ctrl %d failed on port %d",
					    ll_card->card_id,
					    led_op->
					    all_port_speed_led[ll_port_id],
					    ll_port_id);
		}
	} else {
		/* �����˿ڵ�� */
		phy_id = led_op->phy_id;

		/* ��λLL Port ID */
		if (OK !=
		    higgs_locate_ll_port_id_by_phy_id(ll_card, phy_id,
						      &ll_port_id)) {
			HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
				    "Card:%d locate port failed by phy:0x%x",
				    ll_card->card_id, phy_id);
			return ERROR;
		}

		/* ��� */
		if (OK !=
		    higgs_led_ctrl(ll_card, ll_port_id,
				   led_op->port_speed_led)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 4576,
				    "Card:%d LED ctrl %d failed on port:0x%x",
				    ll_card->card_id, led_op->port_speed_led,
				    ll_port_id);
			return ERROR;
		}

	}

	return OK;
}

#if 0
/*****************************************************************************
 �� �� ��  : Higgs_SimulateWireEvent
 ��������  : ģ����ڶ˿ڵ����²����¼�
 �������  : struct higgs_card *ll_card
 		u32 ll_port_id
		u32  v_uiTimeoutMSecs
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static void Higgs_SimulateWireEvent(struct higgs_card *ll_card, u32 ll_port_id,
				    u32 v_uiTimeoutMSecs)
{
	unsigned long ulFlag = 0;

	/* �ڲ����������ⲿ������ȷ��������ȷ */
	ll_card->astPortTimer[ll_port_id].ll_port_id = ll_port_id;
	ll_card->astPortTimer[ll_port_id].card_id = ll_card->card_id;

	/* ���ö�ʱ��, ֪ͨSFP�¼� */
	if (0 != v_uiTimeoutMSecs) {
		spin_lock_irqsave(&ll_card->card_lock, ulFlag);
		sal_add_timer((void *)&ll_card->astPortTimer[ll_port_id].
			      plug_in_timer,
			      (unsigned long)&ll_card->astPortTimer[ll_port_id],
			      (u32) msecs_to_jiffies(v_uiTimeoutMSecs),
			      Higgs_NotifySfpEvent);
		spin_unlock_irqrestore(&ll_card->card_lock, ulFlag);
	} else {
		Higgs_NotifySfpEvent((unsigned long)&ll_card->
				     astPortTimer[ll_port_id]);
	}
}

/*****************************************************************************
 �� �� ��  : Higgs_SimulateSfpPlugInnerPort
 ��������  : ģ����ڶ˿ڵ����²����¼�
 �������  : struct higgs_card *ll_card
		u32  v_uiTimeoutMSecs
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
void Higgs_SimulateSfpPlugInnerPort(struct higgs_card *ll_card,
				    u32 v_uiTimeoutMSecs)
{
	/* BEGIN:DTS2014122307748  ��������ж��higgs.ko��ӡ��ջ chenqilin 00308265 2015.01.05 begin */
	u32 hw_ver = higgs_get_hw_version();
	u32 ll_port_id = C05_BOARD_INNER_PORT_LL_ID;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return);

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return;
	}

	/* ���������� */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d has no board inner port, skipped",
			    ll_card->card_id);
		return;
	}

	Higgs_SimulateWireEvent(ll_card, ll_port_id, v_uiTimeoutMSecs);
	/* END:DTS2014122307748  ��������ж��higgs.ko��ӡ��ջ chenqilin 00308265 2015.01.05 end */
}

/*****************************************************************************
 �� �� ��  : Higgs_CheckSimulateSfpPlugMiniPort
 ��������  : ���MINI SAS HD1���Ƿ�������λ�������λ��ģ��һ�����²����¼�������������ʼ������.
 �������  : struct higgs_card *ll_card
		u32  v_uiTimeoutMSecs
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
void Higgs_CheckSimulateSfpPlugMiniPort(struct higgs_card *ll_card,
					u32 v_uiTimeoutMSecs)
{
	/* BEGIN:DTS2014122307748  ��������ж��higgs.ko��ӡ��ջ chenqilin 00308265 2015.01.05 begin */
	u32 hw_ver = higgs_get_hw_version();
	u32 ll_port_id = C05_CPU_OUTER_PORT_LL_ID;
	bool is_sfp_on_port = false;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return);

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return;
	}

	/* ���������� */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d has no mini sas port, skipped",
			    ll_card->card_id);
		return;
	}

	/* MINI SAS HD1���Ƿ�������λ  */
	if (OK != higgs_sfp_on_port(ll_card, ll_port_id, &is_sfp_on_port)) {
		return;
	}
	if (!is_sfp_on_port) {
		return;
	}

	HIGGS_TRACE(OSP_DBL_INFO, 171,
		    "Card:%d detect cable on mini sas port, to simulate plugin event",
		    ll_card->card_id);

	Higgs_SimulateWireEvent(ll_card, ll_port_id, v_uiTimeoutMSecs);
	/* END:DTS2014122307748  ��������ж��higgs.ko��ӡ��ջ chenqilin 00308265 2015.01.05 end */
}
#endif

/*****************************************************************************
 �� �� ��  : higgs_delay_trigger_all_port_sfp_event_for_init
 ��������  : ����������ʼ�����̣��������˿��Ƿ�������λ���ӳٴ������²���¼�
 �������  : struct higgs_card *ll_card
		u32  tm_out_ms
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
void higgs_delay_trigger_all_port_sfp_event_for_init(struct higgs_card *ll_card,
						     u32 tm_out_ms)
{
	u32 hw_ver = higgs_get_hw_version();
	u32 ll_port_id = 0;
	bool is_sfp_on_port = false;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return);

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return;
	}

	/* ���������� */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d has no mini sas port, skipped",
			    ll_card->card_id);
		return;
	}

	/* �����˿ڣ������λ  */
	for (ll_port_id = 0; ll_port_id < HIGGS_MAX_PORT_NUM; ll_port_id++) {
		if (OK !=
		    higgs_sfp_on_port(ll_card, ll_port_id, &is_sfp_on_port))
			continue;

		if (is_sfp_on_port) {
			HIGGS_TRACE(OSP_DBL_INFO, 171,
				    "Card:%d cable detected on port %d in init",
				    ll_card->card_id, ll_port_id);
			higgs_simulate_wire_hotplug_intr(ll_card, ll_port_id,
							 tm_out_ms);
		}
	}
	return;
}

/*****************************************************************************
 �� �� ��  : higgs_get_card_position
 ��������  : ��ȡSAS Card�ڵ����ϵ�λ����Ϣ
 �������  :
		u32 card_id
 �������  :
 �� �� ֵ  : s32
*****************************************************************************/

u8 higgs_get_card_position(u32 card_id)
{
	u8 card_position = 0;

	switch (card_id) {
	case P660_SAS_CORE_DSAF_ID:
		card_position = (0x1 << 5) | 0x0;
		break;
	case P660_SAS_CORE_PCIE_ID:
		card_position = (0x1 << 5) | 0x1;
		break;
	case P660_1_SAS_CORE_DSAF_ID:
		card_position = (0x1 << 5) | 0x2;
		break;
	case P660_1_SAS_CORE_PCIE_ID:
		card_position = (0x1 << 5) | 0x3;
		break;
	default:
		card_position = 0xFF;
		break;
	}

	return card_position;
}

/*----------------------------------------------*
 * �ڲ�˽�к��� ����                                  *
 *----------------------------------------------*/

/*****************************************************************************
 �� �� ��  : higgs_get_hw_version
 ��������  : ��ȡӲ���汾:
 	 	 FPGA, EVB, C05
 �������  : HIGGSCARD_S *ll_card,
 		u32 ll_port_id
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
static u32 higgs_get_hw_version()
{
	u32 hw_ver = HIGGS_HW_VERSION_BUTT;

#if defined(FPGA_VERSION_TEST)
	hw_ver = HIGGS_HW_VERSION_FPGA;
#elif defined(EVB_VERSION_TEST)
	hw_ver = HIGGS_HW_VERSION_EVB;
#elif defined(C05_VERSION_TEST)
	hw_ver = HIGGS_HW_VERSION_C05;
#endif

	return hw_ver;
}

/*****************************************************************************
 �� �� ��  : higgs_sfp_event_handler
 ��������  : �ص����������ڴ���SFP����¼�
 �������  : void * param
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static void higgs_sfp_event_handler(void *param)
{
	struct higgs_card *ll_card = NULL;
	u32 ll_port_id = 0xff;
	u32 i = 0;
	u32 hw_ver = higgs_get_hw_version();

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return;
	}

	HIGGS_TRACE(OSP_DBL_INFO, 171, "Receive SFP hotplug event");

	HIGGS_REF(param);
	for (i = 0; i < HIGGS_MINI_SAS_PORT_COUNT; i++) {
		/* C05�汾ֻ����CPU������MINI SAS�� */
		if (C05_CPU_OUTER_PORT_MINI_ID != i)
			continue;

		/* ƥ��LL��Card */
		if (OK !=
		    higgs_locate_ll_card_and_ll_port_id_by_mini_port_id(i,
									&ll_card,
									&ll_port_id))
		{
			HIGGS_TRACE(OSP_DBL_MAJOR, 187,
				    "Locate LLCard and port id failed");
			continue;
		}

		/* ģ��PM8072��GPIO�ж�(���°β�)���ԽӼ���SAL������  */
		higgs_simulate_wire_hotplug_intr(ll_card, ll_port_id, 1);	/* 1ms�ӳٴ��� */
	}
	return;
}

/*****************************************************************************
 �� �� ��  : higgs_sfp_on_port
 ��������  : �ж϶˿�SFP�Ƿ���λ
 �������  :
 	 struct higgs_card *ll_card,
 	 u32 ll_port_id,
 	 bool *is_on_port
 �������  : bool *is_on_port
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_sfp_on_port(struct higgs_card *ll_card, u32 ll_port_id,
			     bool * is_on_port)
{
	u8 reg_val = 0;
	u32 mini_port_id = 0;
	u32 hw_ver = higgs_get_hw_version();

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);
	HIGGS_ASSERT(NULL != is_on_port, return ERROR);

	/* �Ƿ���ڶ˿� */
	if (higgs_is_board_inner_port(ll_card, ll_port_id)) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d board inner port %d always be present",
			    ll_card->card_id, ll_port_id);
		*is_on_port = true;
		return OK;
	}

	/* ��λMINI SAS Port ID */
	if (OK !=
	    higgs_locate_mini_port_id_by_ll_port_id(ll_card, ll_port_id,
						    &mini_port_id)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
			    "Card:%d locate minisas port failed by port:0x%x",
			    ll_card->card_id, ll_port_id);
		return ERROR;
	}

	/* ���Դ�׮ */
	if (higgs_stub_in_debug_mode(mini_port_id))
		return higgs_stub_sfp_on_port(mini_port_id, is_on_port);

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation skipped on platform %d", hw_ver);
		return ERROR;
	}

	if (C05_CPU_OUTER_PORT_MINI_ID != mini_port_id) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 171, "Invalid minisas port id %d",
			    mini_port_id);
		return ERROR;
	}

	/* ����BSP�Ľӿڣ���ȡCPLD�Ĵ��� */
       if(NULL == sal_peripheral_operation.read_logic)
       {
              return ERROR;
       }else if (OK != sal_peripheral_operation.read_logic(CPLD_SFP_PRSNT_REG, &reg_val)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 171, "Read cpld reg 0x%x failed",
			    CPLD_SFP_PRSNT_REG);
		return ERROR;
	}
	*is_on_port =
	    (CPLD_SFP_PRSNT_MINISAS1 ==
	     (reg_val & CPLD_SFP_PRSNT_MINISAS1_MASK));

	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_sfp_page_select
 ��������  : �˿�SFP EEPROM��ҳ
 �������  :
 	 struct higgs_card *ll_card,
 	 u32 ll_port_id,
 	 u32 page_sel
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_sfp_page_select(struct higgs_card *ll_card, u32 ll_port_id,
				 u32 page_sel)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u8 buff[2] = { 0 };
	u32 hw_ver = higgs_get_hw_version();
	u32 mini_port_id = 0;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);
	HIGGS_ASSERT(page_sel < HIGGS_SFP_EEPROM_PAGE_COUNT, return ERROR);

	/* �Ƿ���ڶ˿� */
	if (higgs_is_board_inner_port(ll_card, ll_port_id)) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d sfp page select, skip board inner port %d",
			    ll_card->card_id, ll_port_id);
		return OK;
	}

	/* ��λMINI SAS Port ID */
	if (OK !=
	    higgs_locate_mini_port_id_by_ll_port_id(ll_card, ll_port_id,
						    &mini_port_id)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
			    "Card:%d locate minisas port failed by port:%d",
			    ll_card->card_id, ll_port_id);
		return ERROR;
	}
	HIGGS_ASSERT(mini_port_id < HIGGS_MINI_SAS_PORT_COUNT, return ERROR);

	/* ���Դ�׮ */
	if (higgs_stub_in_debug_mode(mini_port_id))
		return higgs_stub_sfp_page_select(mini_port_id, page_sel);

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return ERROR;
	}

	/* 9545ѡͨ��MINI SAS1 */
	if (OK != higgs_open_i2c_9545_route(I2C_9545_ROUTE_TO_MINISAS1_PORT)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d open 9545 route to MINISAS1 SFP failed",
			    ll_card->card_id);
		return ERROR;
	}

	/* д��127�ֽڣ�ѡ��PAGE */
	chan = I2C_9545_CHNL;
	addr = I2C_MINISAS1_PORT_ADDR;
	offset = SFP_EEPROM_PAGE_SEL_OFFSET;
	buff[0] = (u8) page_sel;
	if (OK !=
	    higgs_i2c_wirte(chan, addr, offset, HIGGS_I2C_OFFSET_ONE_BYTE, buff,
			    1)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
			    chan, addr, offset, buff[0]);
		higgs_close_i2c_9545_route();
		return ERROR;
	}

	/* 9545ȡ��ѡͨ */
	higgs_close_i2c_9545_route();

	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_read_sfp_eeprom
 ��������  : �ж϶�ȡ�˿�SFP��EEPROM��Ϣ
 �������  :
		struct higgs_card *ll_card,
		u32 ll_port_id,
		u8 *page,
		u32 rd_len,
		u32 offset
 �������  : u8 *page
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_read_sfp_eeprom(struct higgs_card *ll_card,
				 u32 ll_port_id,
				 u8 * page, u32 rd_len, u32 offset)
{
	u8 chan = 0;
	u8 addr = 0;
//      u32 tmp_offset = 0;
//      u8 wr_buff[2] = {0};
	u8 buff[SAL_SFP_WHOLE_REGISTER_BYTES] = { 0 };
	u32 hw_ver = higgs_get_hw_version();
	u32 mini_port_id = 0;

	/* �������  */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);
	HIGGS_ASSERT(NULL != page, return ERROR);
	HIGGS_ASSERT(rd_len <= SAL_SFP_WHOLE_REGISTER_BYTES, return ERROR);
	HIGGS_ASSERT(offset < SAL_SFP_WHOLE_REGISTER_BYTES, return ERROR);
	HIGGS_ASSERT((offset + rd_len) <= SAL_SFP_WHOLE_REGISTER_BYTES,
		     return ERROR);

	/* �Ƿ���ڶ˿� */
	if (higgs_is_board_inner_port(ll_card, ll_port_id)) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d read eeprom, simulation for board inner port %d",
			    ll_card->card_id, ll_port_id);
		return higgs_simulate_read_sfp_eeprom_inner_port(ll_card,
								 ll_port_id,
								 page, rd_len,
								 offset);
	}

	/* ��λMINI SAS Port ID */
	if (OK !=
	    higgs_locate_mini_port_id_by_ll_port_id(ll_card, ll_port_id,
						    &mini_port_id)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
			    "Card:%d locate minisas port failed by port:0x%x",
			    ll_card->card_id, ll_port_id);
		return ERROR;
	}

	/* ���Դ�׮ */
	if (higgs_stub_in_debug_mode(mini_port_id))
		return higgs_stub_read_sfp_eeprom(mini_port_id, page, rd_len,
						  offset);

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return ERROR;
	}

	/* 9545ѡͨ��MINI SAS1 */
	if (OK != higgs_open_i2c_9545_route(I2C_9545_ROUTE_TO_MINISAS1_PORT)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d open 9545 route to MINISAS1 SFP failed",
			    ll_card->card_id);
		return ERROR;
	}

	/* ��Offset����ȡ���� */
	chan = I2C_9545_CHNL;
	addr = I2C_MINISAS1_PORT_ADDR;
	//tmp_offset = offset;
	memset(buff, 0, sizeof(buff));
	if (OK !=
	    higgs_i2c_read(chan, addr, offset, HIGGS_I2C_OFFSET_ONE_BYTE, buff,
			   rd_len)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "I2C read channel %d addr 0x%x offset 0x%x failed",
			    chan, addr, offset);
		higgs_close_i2c_9545_route();
		return ERROR;
	}

	/* �������� */
	memcpy(page, buff, rd_len);

	/* ȡ��9545ѡͨ */
	higgs_close_i2c_9545_route();

	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_led_ctrl
 ��������  : �˿�LED���
 �������  :
 	 	 struct higgs_card *ll_card,
 	 	 u32 ll_port_id,
 	 	 enum sal_led_op_type led_op
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_led_ctrl(struct higgs_card *ll_card, u32 ll_port_id,
			  enum sal_led_op_type led_op)
{
	u8 reg_val = 0;
	u32 mini_port_id = 0;
	u32 hw_ver = HIGGS_HW_VERSION_BUTT;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);

	HIGGS_TRACE(OSP_DBL_INFO, 4576,
		    "Card:%d To LED ctrl, port:%d opcode: 0x%x",
		    ll_card->card_id, ll_port_id, led_op);
	hw_ver = higgs_get_hw_version();

	/* �Ƿ���ڶ˿� */
	if (higgs_is_board_inner_port(ll_card, ll_port_id)) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Card:%d LED ctrl, skip board inner port %d",
			    ll_card->card_id, ll_port_id);
		return OK;
	}

	/* ��λMINI SAS Port ID */
	if (OK !=
	    higgs_locate_mini_port_id_by_ll_port_id(ll_card, ll_port_id,
						    &mini_port_id)) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
			    "Card:%d locate minisas port failed by port:%d",
			    ll_card->card_id, ll_port_id);
		return ERROR;
	}
	HIGGS_ASSERT(mini_port_id < HIGGS_MINI_SAS_PORT_COUNT, return ERROR);

	/* ���Դ�׮ */
	if (higgs_stub_in_debug_mode(mini_port_id))
		return higgs_stub_led_ctrl(mini_port_id, led_op);

	/* �汾����  */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 171,
			    "Operation unsupported platform %d", hw_ver);
		return ERROR;
	}

	/* ��ƿ���  */
	if (C05_CPU_OUTER_PORT_MINI_ID != mini_port_id) {
		HIGGS_TRACE(OSP_DBL_MAJOR, 171,
			    "Card: %d invalid minisas port %d ",
			    ll_card->card_id, mini_port_id);
		return ERROR;
	}

	switch (led_op) {
	case SAL_LED_HIGH_SPEED:
		reg_val = CPLD_LED_12G_LINK;
		break;
	case SAL_LED_LOW_SPEED:
		reg_val = CPLD_LED_6G_LINK;
		break;
	case SAL_LED_FAULT:
		reg_val = CPLD_LED_FAULT_LINK;
		break;
	case SAL_LED_OFF:
		reg_val = CPLD_LED_NO_LINK;
		break;
	case SAL_LED_ALL_OFF:
	case SAL_LED_RESTORE:
	case SAL_LED_BUTT:
	default:
		HIGGS_TRACE(OSP_DBL_MAJOR, 171, "LED ctrl, invalid  opcode %d",
			    (u32) led_op);
		return ERROR;
	}

	/* ����BSP�Ľӿڣ���дCPLD�Ĵ��� */
        if(NULL != sal_peripheral_operation.write_logic)
       {
	     (void)sal_peripheral_operation.write_logic(CPLD_LED_MINISAS1_REG, reg_val);
       }
	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_enable_sas_redriver_channel
 ��������  : ʹ��MINI SAS���������ε�SAS��������ͨ��
 �������  : struct higgs_card *ll_card
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_enable_sas_redriver_channel(struct higgs_card *ll_card)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u8 redriver_chan_ctrl = 0;
	u8 wr_buff[2] = { 0 };
	u8 rd_buff[2] = { 0 };
	s32 ret = ERROR;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);

	/* C05�汾 */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_MINOR, 4576,
			    "C05 version do not manage controller %d",
			    ll_card->card_id);
		return ERROR;
	}

	/* 9545ѡͨ��SAS Redriver */
	if (OK !=
	    higgs_open_i2c_9545_route(I2C_9545_ROUTE_TO_MINISAS1_REDRIVER)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d open 9545 route to MINISAS1 redriver failed",
			    ll_card->card_id);
		return ERROR;
	}

	do {
		/* Redriverͨ��1-4ʹ�� */
		chan = I2C_9545_CHNL;
		addr = I2C_MINISAS1_REDRIVER_LOWER_ADDR;
		offset = REDRIVER_CHNL_1_4_CTRL_OFFSET;

		rd_buff[0] = 0;
		if (OK !=
		    higgs_i2c_read(chan, addr, offset,
				   HIGGS_I2C_OFFSET_ONE_BYTE, rd_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C read channel %d addr 0x%x offset 0x%x failed",
				    chan, addr, offset);
			break;
		}
		redriver_chan_ctrl = rd_buff[0];

		wr_buff[0] =
		    (u8) ((redriver_chan_ctrl & (~REDRIVER_CHNL_1_4_CTRL_MASK))
			  | REDRIVER_CHNL_1_4_CTRL_ENABLE);
		if (OK !=
		    higgs_i2c_wirte(chan, addr, offset,
				    HIGGS_I2C_OFFSET_ONE_BYTE, wr_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
				    chan, addr, offset, wr_buff[0]);
			break;
		}
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Enable MINISAS1 redriver channel 1-4 succeeded");

		/* Redriverͨ��5-8ʹ�� */
		chan = I2C_9545_CHNL;
		addr = I2C_MINISAS1_REDRIVER_UPPER_ADDR;
		offset = REDRIVER_CHNL_5_8_CTRL_OFFSET;

		rd_buff[0] = 0;
		if (OK !=
		    higgs_i2c_read(chan, addr, offset,
				   HIGGS_I2C_OFFSET_ONE_BYTE, rd_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C read channel %d addr 0x%x offset 0x%x failed",
				    chan, addr, offset);
			break;
		}
		redriver_chan_ctrl = rd_buff[0];

		wr_buff[0] =
		    (u8) ((redriver_chan_ctrl & (~REDRIVER_CHNL_5_8_CTRL_MASK))
			  | REDRIVER_CHNL_5_8_CTRL_ENABLE);
		if (OK !=
		    higgs_i2c_wirte(chan, addr, offset,
				    HIGGS_I2C_OFFSET_ONE_BYTE, wr_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
				    chan, addr, offset, wr_buff[0]);
			break;
		}

		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Enable MINISAS1 redriver channel 5-8 succeeded");
		ret = OK;
	} while (0);

	/* ȡ��9545ѡͨ */
	higgs_close_i2c_9545_route();

	return ret;
}

/*****************************************************************************
 �� �� ��  : higgs_config_sas_redriver_channel_param
 ��������  : ����MINI SAS���������ε�SAS��������ͨ�����źŲ���
 �������  : struct higgs_card *ll_card
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_config_sas_redriver_channel_param(struct higgs_card *ll_card)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u32 redriver_chan = 0;
	u8 wr_buff[2] = { 0 };

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);

	/* C05�汾 */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_MINOR, 4576,
			    "C05 version do not manage controller %d",
			    ll_card->card_id);
		return ERROR;
	}

	/* 9545ѡͨ��SAS Redriver */
	if (OK !=
	    higgs_open_i2c_9545_route(I2C_9545_ROUTE_TO_MINISAS1_REDRIVER)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d open 9545 route to MINISAS1 redriver failed",
			    ll_card->card_id);
		return ERROR;
	}

	/* Redriverͨ��1-8�������� */
	chan = I2C_9545_CHNL;
	for (redriver_chan = 0; redriver_chan < REDRIVER_CHNL_NUM_MAX;
	     redriver_chan++) {
		addr = (u8) i2c_mini_sas1_redriver_chan_addr[redriver_chan];
		offset = redriver_chan_offset[redriver_chan];
		wr_buff[0] = (u8) C05_MINISAS1_REDRIVER_CHNL_EQ_PARAM;
		if (OK !=
		    higgs_i2c_wirte(chan, addr, offset,
				    HIGGS_I2C_OFFSET_ONE_BYTE, wr_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
				    chan, addr, offset, wr_buff[0]);
			higgs_close_i2c_9545_route();
			return ERROR;
		}
	}
	HIGGS_TRACE(OSP_DBL_INFO, 171,
		    "Config MINISAS1 redriver channel 1-8 param 0x%x succeeded",
		    wr_buff[0]);

	/* 9545ȡ��ѡͨ */
	higgs_close_i2c_9545_route();

	return OK;
}

/*****************************************************************************
 �� �� ��  : Higgs_InitSasRedriverChannelAddr
 ��������  : ��ʼ��MINI SAS���������ε�SAS������I2C��ַ
 �������  : struct higgs_card *ll_card
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_init_sas_redriver_addr(struct higgs_card *ll_card)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u8 wr_buff[2] = { 0 };

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);

	/* C05�汾 */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_MINOR, 4576,
			    "C05 version do not manage controller %d",
			    ll_card->card_id);
		return ERROR;
	}

	/* 9545ѡͨ��SAS Redriver */
	if (OK !=
	    higgs_open_i2c_9545_route(I2C_9545_ROUTE_TO_MINISAS1_REDRIVER)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d open 9545 route to MINISAS1 redriver failed",
			    ll_card->card_id);
		return ERROR;
	}

	/* Redriver��ַ��ʼ�� */
	chan = I2C_9545_CHNL;
	addr = I2C_MINISAS1_REDRIVER_LOWER_ADDR;
	offset = 0x3C;
	wr_buff[0] = I2C_MINISAS1_REDRIVER_LOWER_ADDR;
	if (OK !=
	    higgs_i2c_wirte(chan, addr, offset, HIGGS_I2C_OFFSET_ONE_BYTE,
			    wr_buff, 1)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
			    chan, addr, offset, wr_buff[0]);
		higgs_close_i2c_9545_route();
		return ERROR;
	}

	/* 9545ȡ��ѡͨ */
	higgs_close_i2c_9545_route();

	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_disable_sas_redriver_channel
 ��������  : ����MINI SAS�����ڵ�����SAS��������ͨ��
 �������  : struct higgs_card *ll_card
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_disable_sas_redriver_channel(struct higgs_card *ll_card)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u8 redriver_chan_ctrl = 0;
	u8 rd_buff[2] = { 0 };
	u8 wr_buff[2] = { 0 };
	s32 ret = ERROR;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);

	/* C05�汾 */
	if (P660_SAS_CORE_DSAF_ID != ll_card->card_id) {
		HIGGS_TRACE(OSP_DBL_MINOR, 4576,
			    "C05 version do not manage controller %d",
			    ll_card->card_id);
		return ERROR;
	}

	/* 9545ѡͨ��SAS Redriver */
	if (OK !=
	    higgs_open_i2c_9545_route(I2C_9545_ROUTE_TO_MINISAS1_REDRIVER)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "Card:%d open 9545 route to MINISAS1 redriver failed",
			    ll_card->card_id);
		return ERROR;
	}

	do {
		/* Redriverͨ��1-4���� */
		chan = I2C_9545_CHNL;
		addr = I2C_MINISAS1_REDRIVER_LOWER_ADDR;
		offset = REDRIVER_CHNL_1_4_CTRL_OFFSET;

		rd_buff[0] = 0;
		if (OK !=
		    higgs_i2c_read(chan, addr, offset,
				   HIGGS_I2C_OFFSET_ONE_BYTE, rd_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C read channel %d addr 0x%x offset 0x%x failed",
				    chan, addr, offset);
			break;
		}
		redriver_chan_ctrl = rd_buff[0];

		wr_buff[0] =
		    (u8) ((redriver_chan_ctrl & (~REDRIVER_CHNL_1_4_CTRL_MASK))
			  | REDRIVER_CHNL_1_4_CTRL_DISABLE);
		if (OK !=
		    higgs_i2c_wirte(chan, addr, offset,
				    HIGGS_I2C_OFFSET_ONE_BYTE, wr_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
				    chan, addr, offset, wr_buff[0]);
			break;
		}
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Disable MINISAS1 redriver channel 1-4 succeeded");

		/* Redriverͨ��5-8���� */
		chan = I2C_9545_CHNL;
		addr = I2C_MINISAS1_REDRIVER_UPPER_ADDR;
		offset = REDRIVER_CHNL_5_8_CTRL_OFFSET;

		rd_buff[0] = 0;
		if (OK !=
		    higgs_i2c_read(chan, addr, offset,
				   HIGGS_I2C_OFFSET_ONE_BYTE, rd_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C read channel %d addr 0x%x offset 0x%x failed",
				    chan, addr, offset);
			break;
		}
		redriver_chan_ctrl = rd_buff[0];

		wr_buff[0] =
		    (u8) ((redriver_chan_ctrl & (~REDRIVER_CHNL_5_8_CTRL_MASK))
			  | REDRIVER_CHNL_5_8_CTRL_DISABLE);
		if (OK !=
		    higgs_i2c_wirte(chan, addr, offset,
				    HIGGS_I2C_OFFSET_ONE_BYTE, wr_buff, 1)) {
			HIGGS_TRACE(OSP_DBL_MINOR, 171,
				    "I2C write channel %d addr 0x%x offset 0x%x value 0x%x failed",
				    chan, addr, offset, wr_buff[0]);
			break;
		}

		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Disable MINISAS1 redriver channel 5-8 succeeded");
		ret = OK;
	} while (0);

	/* 9545ȡ��ѡͨ */
	higgs_close_i2c_9545_route();

	return ret;
}

/*****************************************************************************
 �� �� ��  : higgs_open_i2c_9545_route
 ��������  : ��9545·��ѡͨ
 �������  : ��
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_open_i2c_9545_route(u32 route)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u8 wr_buff[2] = { 0 };

	/* 9545ѡͨ·�� */
	chan = I2C_9545_CHNL;
	addr = I2C_9545_ADDR;
	offset = 0;
	wr_buff[0] = (u8) route;
	if (OK !=
	    higgs_i2c_wirte(chan, addr, offset, HIGGS_I2C_OFFSET_NONE, wr_buff,
			    1)) {
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "I2C write channel %d addr 0x%x value 0x%x failed",
			    chan, addr, wr_buff[0]);
		return ERROR;
	}
	HIGGS_MDELAY(2);	/* 9545 switch need some delay */
	return OK;
}

/*****************************************************************************
 �� �� ��  : higgs_close_i2c_9545_route
 ��������  : �ر�9545·��ѡͨ
 �������  : ��
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static void higgs_close_i2c_9545_route(void)
{
	u8 chan = 0;
	u8 addr = 0;
	u32 offset = 0;
	u8 wr_buff[2] = { 0 };

	/* 9545ȡ��ѡͨ */
	chan = I2C_9545_CHNL;
	addr = I2C_9545_ADDR;
	offset = 0;
	wr_buff[0] = I2C_9545_ROUTE_TO_NONE;
	if (OK !=
	    higgs_i2c_wirte(chan, addr, offset, HIGGS_I2C_OFFSET_NONE, wr_buff,
			    1))
		HIGGS_TRACE(OSP_DBL_MINOR, 171,
			    "I2C write channel %d addr 0x%x value 0x%x failed",
			    chan, addr, wr_buff[0]);

	HIGGS_MDELAY(2);	/* 9545 switch need some delay */
	return;
}

/*****************************************************************************
 �� �� ��  : higgs_i2c_wirte
 ��������  : I2Cд����
 �������  :
		u8 chan,
		u8 addr,
		u32 offset,
		enum higgs_i2c_offset_size offset_size,
		u8*  buff,
		u32 buff_size
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_i2c_wirte(u8 chan,
			   u8 addr,
			   u32 offset,
			   enum higgs_i2c_offset_size offset_size,
			   u8 * buff, u32 buff_size)
{
	u8 tmp_addr = (addr >> 1);	/* 660 i2c�����ӿ�ʹ����ƫ�Ƶ�ַ */
	u32 hw_ver = higgs_get_hw_version();

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return ERROR;
	}
//      return i2c_api_do_send(chan, (char)tmp_addr, offset, (char*)buff, buff_size, (s32)offset_size);
       if(NULL == sal_peripheral_operation.i2c_simple_write)
       {
              return ERROR;
       }else
       return sal_peripheral_operation.i2c_simple_write(chan, (u8) tmp_addr, offset, (char *)buff,
				    buff_size, (s32) offset_size);
}

/*****************************************************************************
 �� �� ��  : higgs_i2c_read
 ��������  : I2C������
 �������  :
		u8 chan,
		u8 addr,
		u32 offset,
		enum higgs_i2c_offset_size offset_size,
		u8*  buff,
		u32 buff_size
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_i2c_read(u8 chan,
			  u8 addr,
			  u32 offset,
			  enum higgs_i2c_offset_size offset_size,
			  u8 * buff, u32 buff_size)
{
	u8 tmp_addr = (addr >> 1);	/* 660 i2c�����ӿ�ʹ����ƫ�Ƶ�ַ */
	u32 hw_ver = higgs_get_hw_version();

	/* �汾���� */
	if (HIGGS_HW_VERSION_C05 != hw_ver) {
		HIGGS_TRACE(OSP_DBL_INFO, 171,
			    "Operation unsupported on platform %d", hw_ver);
		return ERROR;
	}
//      return i2c_api_do_recv(chan, (char)tmp_addr, offset, (char*)buff, buff_size, (s32)offset_size);
       if(NULL == sal_peripheral_operation.i2c_simple_read)
       {
              return ERROR;
       }else
         return sal_peripheral_operation.i2c_simple_read(chan, (u8) tmp_addr, offset, (char *)buff,
                  buff_size, (s32) offset_size);
}

/*****************************************************************************
 �� �� ��  : higgs_is_board_inner_port
 ��������  : �ж��Ƿ�CPU�����8054�����Ӷ˿�
 �������  : HIGGSCARD_S *ll_card,
 		u32 ll_port_id
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
static bool higgs_is_board_inner_port(struct higgs_card *ll_card,
				      u32 ll_port_id)
{
	u32 hw_ver = higgs_get_hw_version();
	bool is_inner_port = false;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return false);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return false);

	/* �ж� */
	switch (hw_ver) {
	case HIGGS_HW_VERSION_C05:
		is_inner_port = ((P660_SAS_CORE_DSAF_ID == ll_card->card_id)
				 && (C05_BOARD_INNER_PORT_LL_ID == ll_port_id));
		break;
	default:
		break;
	}

	return is_inner_port;
}

#if 0
/*****************************************************************************
 �� �� ��  : Higgs_NotifySfpEvent
 ��������  : �����˿����²���¼�
 �������  : unsigned long v_ulData
 �������  : ��
 �� �� ֵ  : s32
*****************************************************************************/
void Higgs_NotifySfpEvent(unsigned long v_ulData)
{
	/* BEGIN:DTS2014122307748  ��������ж��higgs.ko��ӡ��ջ chenqilin 00308265 2015.01.05 begin */
	u32 ll_port_id = 0;
	u32 logic_port_id = 0;
	u32 uiReadGpioRspVal = 0;
	struct higgs_card *ll_card = NULL;
	struct sal_card *sal_card = NULL;
	struct higgs_timer_callback_param stPortTimer;
	u32 card_id = 0;

	/* ������� */
	HIGGS_ASSERT(0 != v_ulData, return);
	stPortTimer = *(struct higgs_timer_callback_param *)v_ulData;
	card_id = stPortTimer.card_id;
	ll_port_id = stPortTimer.ll_port_id;

	sal_card = sal_get_card(card_id);
	HIGGS_ASSERT(NULL != sal_card, return);

	ll_card = (struct higgs_card *)sal_card->drv_data;
	HIGGS_ASSERT(NULL != ll_card, return);
	HIGGS_ASSERT(NULL != ll_card->sal_card, return);

	/* �ֶ����� */
	if (P660_SAS_CORE_DSAF_ID == ll_card->card_id) {	/* C05�汾 */
		/* ����SAL_AddEventToWireHandler֪ͨSAL�� */
		/* DTS2014122503568: ��PV660/Hi1610ƽ̨, GPIOֵ��Ȼ�����壬����SAL��Ҫ��ͬ�˿ڵ�ֵ�в��죬�����ڽ����¼����ܻᱻ���� */
#if 0
		uiReadGpioRspVal = 0xFFFFFFFF;	/* ��PV660/Hi1610ƽ̨, GPIOֵ���� */
#else
		uiReadGpioRspVal = 0xFFFFFF00 + ll_port_id;
#endif
		/* DTS2014122503568 */
		logic_port_id =
		    ll_card->sal_card->config.port_logic_id[ll_port_id];
		if (OK !=
		    SAL_AddEventToWireHandler(ll_card->sal_card,
					      uiReadGpioRspVal,
					      logic_port_id)) {
			HIGGS_TRACE(OSP_DBL_MAJOR, 4576,
				    "Card:%d port:0x%x add sfp hotplug event failed",
				    ll_card->card_id, logic_port_id);
		} else {
			HIGGS_TRACE(OSP_DBL_INFO, 4576,
				    "Card:%d port:0x%x add sfp hotplug event succeeded",
				    ll_card->card_id, logic_port_id);
		}
	} else {
		HIGGS_TRACE(OSP_DBL_INFO, 4576,
			    "Card:%d ignore sfp event simulation",
			    ll_card->card_id);
	}

	sal_put_card(sal_card);
	/* END:DTS2014122307748  ��������ж��higgs.ko��ӡ��ջ chenqilin 00308265 2015.01.05 end */

	return;
}
#endif

/*****************************************************************************
 �� �� ��  : higgs_read_sfp_eeprom
 ��������  : ������SAS�˿�ģ��SFP EEPROM��Ϣ
 �������  :
		struct higgs_card *ll_card,
		u32 ll_port_id,
		u8 *page,
		u32 rd_len,
		u32 offset
 �������  : u8 *page
 �� �� ֵ  : s32
*****************************************************************************/
static s32 higgs_simulate_read_sfp_eeprom_inner_port(struct higgs_card *ll_card,
						     u32 ll_port_id,
						     u8 * page,
						     u32 rd_len, u32 offset)
{
	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return ERROR);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return ERROR);

	/* �Ƿ���ڶ˿� */
	if (!higgs_is_board_inner_port(ll_card, ll_port_id))
		return ERROR;

	return higgs_stub_read_copper_cable_eeprom(page, rd_len, offset);
}

/*****************************************************************************
 �� �� ��  : higgs_ll_port_exist
 ��������  : �ж�LL PORT�Ƿ����
 �������  : struct higgs_card *ll_card,
		u32 ll_port_id,
 �������  : ��
 �� �� ֵ  : bool
*****************************************************************************/
static bool higgs_ll_port_exist(struct higgs_card *ll_card, u32 ll_port_id)
{
	u32 port_bit_map = 0;

	/* ������� */
	HIGGS_ASSERT(NULL != ll_card, return false);
	HIGGS_ASSERT(ll_port_id < HIGGS_MAX_PORT_NUM, return false);

	port_bit_map = ll_card->card_cfg.port_bitmap[ll_port_id];

	return (0 != port_bit_map);
}

struct higgs_card *higgs_get_card_info(u32 card_id)
{
	return higgs_peri_cards[card_id];
}

/*
 * �����ú���
 */
 /*
    s32 Higg_I2cTest(s32 v_uiCmd)
    {
    struct higgs_card *ll_card;
    s32 ret = ERROR;

    ll_card = HIGGS_VMALLOC(sizeof(struct higgs_card));
    if (NULL == ll_card)
    return ERROR;
    ll_card->card_id = P660_SAS_CORE_DSAF_ID;
    switch(v_uiCmd)
    {
    case 0:
    ret = higgs_init_sas_redriver_addr(ll_card);
    break;
    case 1:
    ret = higgs_enable_sas_redriver_channel(ll_card);
    break;
    case 2:
    ret = higgs_disable_sas_redriver_channel(ll_card);
    break;
    case 3:
    ret = higgs_config_sas_redriver_channel_param(ll_card);
    break;
    default:
    ret = ERROR;
    break;
    }

    HIGGS_VFREE(ll_card);
    return ret;
    }

    EXPORT_SYMBOL(Higg_I2cTest);
  */

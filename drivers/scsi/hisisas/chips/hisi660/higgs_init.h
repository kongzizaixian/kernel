#ifndef _HIGGS_INIT_H_
#define _HIGGS_INIT_H_

/****************************************************************************
***                     ��(MACRO)/ö��(Enum)����                          ***
****************************************************************************/

#define HIGGS_INITED_SAL  (1 << 0)	/* ����SAL����Դ��� */
#define HIGGS_INITED_MEM  (1 << 1)	/* �ڴ������� */
#define HIGGS_INITED_HW   (1 << 3)	/* Ӳ����ʼ����� */
#define HIGGS_INITED_INTR (1 << 4)	/* �жϳ�ʼ����� */
#define HIGGS_INITED_RSC  (1 << 5)	/* ��Դ��ʼ����� */
#define HIGGS_INITED_ADDSAL  	(1 << 6)
#define HIGGS_INITED_PORTID  	(1 << 7)

/****************************************************************************
***                     �ṹ��(struct)/ ����(union) ����                  ***
****************************************************************************/
struct higgs_cfg_item {
	char *name;
	u32 min_val;
	u32 default_val;
	u32 max_val;
};

/****************************************************************************
***                         ����(Function)ԭ������                        ***
****************************************************************************/
extern s32 higgs_probe_stub(struct platform_device *dev);
extern s32 higgs_remove_stub(struct platform_device *dev);
extern OSP_DMA higgs_dma_map_single_sg(struct higgs_card *ll_card,
				       void *data_buff, u32 len, s32 direct);
extern OSP_DMA higgs_dma_map_single_sge_buffer(struct higgs_card *ll_card,
					       void *data_buff, u32 lend,
					       s32 direct);

extern s32 higgs_reset_chip(struct sal_card *sal_card);
extern s32 higgs_comm_pdprocess(struct higgs_card *ll_card);

/* BEGIN: Added by c00257296, 2015/1/22   PN:arm_server*/
extern s32 higgs_add_event_to_led_handler(struct higgs_card *ll_card,
					  u32 event, u32 phy_id);
/* END:   Added by c00257296, 2015/1/22 */

#endif

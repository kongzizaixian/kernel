#ifndef _IWARE_SERDES_KERNEL_API_H
#define _IWARE_SERDES_KERNEL_API_H

#include <linux/module.h>
#include <linux/types.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*ctle ����*/
struct ctle_data
{
	u8 ctlebst[3];
	u8 ctlecmband[3];
	u8 ctlermband[3];
	u8 ctleza[3];
	u8 ctlesqh[3];
	u8 ctleactgn[3];
	u8 ctlepassgn;
};

/*dfe ����*/
struct dfe_data
{
	u8 dfepwrdb;      //FixTAP�µ�
    u8 dfemvtappwrdb; //Float Tap�µ�
    u8 dfefxtap[5];   //DFE Fix Tap ����
    u8 dfemvtap[6];   //DFE Floating Taps ��ֵ
};

/*ffe Ԥ����*/
struct ffe_data
{
	u8 pre1;
	u8 main;
	u8 post1;
};

/*****************************************************************************
 �� �� ��  : serdes_ctle_get
 ��������  : ctle ���������ȡ 
 �������  : u8 macro,u8 lane
 �������  : struct ctle_data *p_ctle_data
 �� �� ֵ  : 0Ϊ�ɹ�����0Ϊ����
*****************************************************************************/
extern int serdes_ctle_get(u8 macro,u8 lane,struct ctle_data *p_ctle_data);
/*****************************************************************************
 �� �� ��  : serdes_dfe_get
 ��������  : dfe ���������ȡ 
 �������  : u8 macro,u8 lane
 �������  : struct dfe_data *p_dfe_data
 �� �� ֵ  : 0Ϊ�ɹ�����0Ϊ����
*****************************************************************************/
extern int serdes_dfe_get(u8 macro,u8 lane,struct dfe_data *p_dfe_data);
/*****************************************************************************
 �� �� ��  : serdes_ffe_set
 ��������  : ffe Ԥ���ز������� 
 �������  : u8 macro,u8 lane,const struct ffe_data *p_ffe_data
 �������  : 
 �� �� ֵ  : 0Ϊ�ɹ�����0Ϊ����
*****************************************************************************/
extern int serdes_ffe_set(u8 macro,u8 lane,const struct ffe_data *p_ffe_data);
/*****************************************************************************
 �� �� ��  : serdes_ffe_get
 ��������  : ffe Ԥ���ز�����ȡ
 
 �������  : u8 macro,u8 lane,const struct ffe_data *p_ffe_data
 �������  : 
 �� �� ֵ  : 0Ϊ�ɹ�����0Ϊ����
*****************************************************************************/
extern int serdes_ffe_get(u8 macro,u8 lane,struct ffe_data *p_ffe_data);

/*****************************************************************************
 �� �� ��  : serdes_swing_set
 ��������  : ffe �ڷ���������
 
 �������  : u8 macro,u8 lane,u8 swing
 �������  : 
 �� �� ֵ  : 0Ϊ�ɹ�����0Ϊ����
*****************************************************************************/
extern int serdes_swing_set(u8 macro,u8 lane,const u8 swing);
/*****************************************************************************
 �� �� ��  : serdes_swing_set
 ��������  : ffe �ڷ�������ȡ
 
 �������  : u8 macro,u8 lane
 �������  : u8 *p_swing
 �� �� ֵ  : 0Ϊ�ɹ�����0Ϊ����
*****************************************************************************/
extern int serdes_swing_get(u8 macro,u8 lane,u8 *p_swing);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif


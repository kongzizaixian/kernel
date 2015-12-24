/******************************************************************************

				  ��Ȩ���� (C), 2012-2016, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : hrd_error.h
  �� �� ��   : ����
  ��	��   : z00142220
  ��������   : 2013��7��26��
  ����޸�   :
  ��������   : ���������붨��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��	��   : 2013��7��26��
	��	��   : z00142220
	�޸�����   : �����ļ�

******************************************************************************/
#ifndef _HRD_ERROR_H
#define _HRD_ERROR_H
/* #include "hrd_typedef.h" */


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#define HRD_OK										  (0)
#define HRD_ERR										 (1)

#define HRD_ERR_BASE									(1024)

/* ���������� */
#define HRD_COMMON_ERR_BASE							 (HRD_ERR_BASE)
#define HRD_COMMON_ERR_NULL_POINTER					 (HRD_COMMON_ERR_BASE + 1)
#define HRD_COMMON_ERR_UNKNOW_DEVICE					(HRD_COMMON_ERR_BASE + 2)
#define HRD_COMMON_ERR_UNKNOW_FUNCTION				  (HRD_COMMON_ERR_BASE + 3)
#define HRD_COMMON_ERR_OPEN_FAIL						(HRD_COMMON_ERR_BASE + 4)
#define HRD_COMMON_ERR_READ_FAIL						(HRD_COMMON_ERR_BASE + 5)
#define HRD_COMMON_ERR_WRITE_FAIL					   (HRD_COMMON_ERR_BASE + 6)
#define HRD_COMMON_ERR_MMAP_FAIL						(HRD_COMMON_ERR_BASE + 7)
#define HRD_COMMON_ERR_GET_MEN_RES_FAIL				 (HRD_COMMON_ERR_BASE + 8)
#define HRD_COMMON_ERR_GET_IRQ_RES_FAIL				 (HRD_COMMON_ERR_BASE + 9)
#define HRD_COMMON_ERR_INPUT_INVALID					(HRD_COMMON_ERR_BASE + 10)
#define HRD_COMMON_ERR_UNKNOW_MODE					  (HRD_COMMON_ERR_BASE + 11)
#define HRD_COMMON_ERR_NOT_ENOUGH_RES				   (HRD_COMMON_ERR_BASE + 12)
#define HRD_COMMON_ERR_RES_NOT_EXIST					(HRD_COMMON_ERR_BASE + 13)



/**
 * @brief ����ģ�������
 *
 * @description
 * �궨�壬����ģ�������
 *
 * @attention ��
 * @param[in]   MID ģ��ID��š�
 * @param[in]   ERRNO �������š�
 *
 * @retval ��
 * @depend
 * iwr_errno.h: �ú궨�����ڵ�ͷ�ļ���
 * @since HRD ARM PV660 V100R001
 * @see
 */
#define HRD_ERRNO(MID,ERRNO)  \
			(int)(HRD_ERR_BASE - ((UINT32)(MID) << 8) - (UINT32)(ERRNO))
#if 0			/* ��SRE�²�������Ķ��� */
 /**
 * @brief ����ģ�������
 *
 * @description
 * �궨�壬����ģ�������
 *
 * @attention ��
 * @param[in]   MID ģ��ID��š�
 * @param[in]   ERRNO �������š�
 *
 * @retval ��
 * @depend
 * SRE_errno.h: �ú궨�����ڵ�ͷ�ļ���
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_FATAL | SRE_ERRNO_OS_WARN | SRE_ERRNO_OS_NORMAL
 */
#define HRD_ERRNO(MID,ERRNO)  \
			(SRE_ERRNO_DRV_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_ERROR | (ERRNO))
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#endif /* _HRD_ERROR_H */


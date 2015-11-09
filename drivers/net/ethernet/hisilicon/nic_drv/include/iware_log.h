/******************************************************************************

                  ��Ȩ���� (C), 2012-2016, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : hrd_log.h
  �� �� ��   : ����
  ��    ��   : z00142220
  ��������   : 2013��7��26��
  ����޸�   :
  ��������   : ��־��������ͷ�ļ������幫������־��¼�궨�壬�ӿ�ԭ�͵�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��7��26��
    ��    ��   : z00142220
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef _HRD_LOG_H
#define _HRD_LOG_H

#include "osal_api.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

/* Ĭ����־ID */
#define HRD_DEF_LOG_ID 0xffffffffUL

#if 0  /* HRD�ݲ�֧����־��¼��ֻ�ô�ӡ */
/**
 * ������־�����־
 */
typedef enum
{
    OS_LOG_TYPE_TEXT = 0,           /**< �ı�����   */
    OS_LOG_TYPE_BIN  = 1,           /**< ���������� */
    OS_LOG_TYPE_BUTT
}OS_LOG_TYPE_E;


/**
 * ������־��Ҫͨ������LogAgent�ϱ�
 */
typedef enum
{
    OS_LOG_REPORT_OFF = 0,          /**< �������ϱ� */
    OS_LOG_REPORT_ON  = 1,          /**< �����ϱ�   */
    OS_LOG_REPORT_BUTT
}OS_LOG_REPORT_E;

/**
 * ��־�Ƿ������ǵı�־�����report������Ч
 */
typedef enum
{
    OS_LOG_OVERWRITE_OFF = 0,       /**< ������ѭ������ */
    OS_LOG_OVERWRITE_ON  = 1,       /**< ����ѭ������   */
    OS_LOG_OVERWRITE_BUTT
}OS_LOG_OVERWRITE_E;


/**
* LOG���˹��Ӻ���ָ�룬����ΪOS_SUCCESS��ʾ����־�����˲���¼�������¼
*/
typedef UINT32 (*LOG_FILTER_HOOK)(UINT32 uwPtNum,UINT32 uwLogId, UINT32 uwUserData);


/**
* LOG��ӡ���Ӻ���ָ��
*/
typedef VOID (*LOG_PRINT_HOOK)( UINT32 uwPtNum, UINT32 uwTimeStamp,
                                UINT32 uwLogId, UINT32 uwUserData,
                                UINT32 len, VOID *pLogItem);


/**
* LOG��������
*/
typedef struct tagLogRegionAttr
{
    CHAR   *name;                   /**< �������ƣ��ΪOS_LOG_NAME_LEN    */
    UINT32  startAddr;              /**< ������ʼ�����ַ��������32�ֽڶ��� */
    UINT32  length;                 /**< �������ȣ����ܵ��µ�ַ��ת         */
    OS_LOG_TYPE_E      type;        /**< ����LOG����                        */
    OS_LOG_REPORT_E    reportflag;  /**< ����LOG��¼ͨ������Agent�ϱ���ʶ   */
    OS_LOG_OVERWRITE_E overflag;    /**< ����LOG���Ǳ�־�����report����    */
    LOG_FILTER_HOOK    pfnFilter;   /**< ������¼���˺���                   */
    LOG_PRINT_HOOK     pfnPrint;    /**< ����LOG��ӡ����, ��������־��Ч    */
}IWARE_LOG_REGION_ATTR_S;

/*****************************************************************************
 �� �� ��  : IWARE_LogPtCreate
 ��������  : ����LOG����
 �������  : IWARE_LOG_REGION_ATTR_S *pstRegionAttr--��־��������

 �������  : UINT32 *puwPtId--��־����ID
 �� �� ֵ  :
 ���ú���  :
 ��������  :
 �޸���ʷ      :
  1.��    ��   :
    ��    ��   :
    �޸�����   : �����ɺ���
*****************************************************************************/
extern UINT32 IWARE_LogPtCreate(IWARE_LOG_REGION_ATTR_S *pstRegionAttr, UINT32 *puwPtId);
#endif

/* ����DBG������Ϣ�Ƿ��ӡ�Ŀ��ƿ��أ���ÿ��ģ���Լ������ض��壬0��ʾ�رմ�ӡ��1��ʾ�򿪴�ӡ */
/* ����: #undef HRD_DBG_ENABLE                                                   */
/*       #define HRD_DBG_ENABLE   0                                              */
#define HRD_DBG_ENABLE IWARE_LOG_LEVEL_DEBUGGING

/* ERROR�ȼ����� */
typedef enum tagiWareLogLevel
{
    IWARE_LOG_LEVEL_DEBUGGING = 0,  /* ���Լ��� */
    IWARE_LOG_LEVEL_INFORMATIONAL,  /* ��Ϣ���� */
    IWARE_LOG_LEVEL_NOTIFICATION,   /* �������� */
    IWARE_LOG_LEVEL_WARNING,        /* ���漶�� */
    IWARE_LOG_LEVEL_ERROR,          /* ���󼶱� */
    IWARE_LOG_LEVEL_CRITICAL,       /* ���ؼ��� */
    IWARE_LOG_LEVEL_ALERT,          /* �澯���� */
    IWARE_LOG_LEVEL_EMERGENCY,      /* �������� */
}IWARE_LOG_LEVEL_S;

#if 0  /* HRD�ݲ�֧����־��¼��ֻ�ô�ӡ */
/*****************************************************************************
 �� �� ��  : IWARE_LogOutPut
 ��������  : �ı���־��¼
 �������  : UINT32 uwPtId--��־��������SRE��ʹ����־��Ҫ�ȴ���һ������
             UINT32 uwLogId--��־ID���û��Լ�����
             UINT32 uwModeId--ģ��ID
             UINT32 uwLevel--��־���ؼ���
             VOID *format--�û��Զ�������͸�ʽ���ַ���ָ�룬���������ʽ
                            ���뱣ָ֤����ַ��������һֱ�ᱣ�����ڴ�����
             UINT32 uwPara1~uwPara4--�û��Զ�����ĸ�����
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :
 �޸���ʷ      :
  1.��    ��   :
    ��    ��   :
    �޸�����   : �����ɺ���
*****************************************************************************/
UINT32 IWARE_LogOutPut(UINT32 uwPtId, UINT32 uwLogId, UINT32 uwModeId, UINT32 uwLevel, char *format,
                      UINT32 uwPara1, UINT32 uwPara2, UINT32 uwPara3, UINT32 uwPara4);



/*****************************************************************************
 �� �� ��  : IWARE_LogShow
 ��������  : �ı���־��¼
 �������  : UINT32 uwPtId--������
             UINT32 uwNum--��Ҫ��ʾ����־����
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :
 �޸���ʷ      :
  1.��    ��   :
    ��    ��   :
    �޸�����   : �����ɺ���
*****************************************************************************/
extern UINT32 IWARE_LogShow(UINT32 uwPtId, UINT32 uwNum);
#endif

/*****************************************************/
/* hrd_log: hrdƽ̨��־��¼��                      */
/*****************************************************/
#if 1
 /*��ǰ��֧����־��������־��ӡ����Ļ */
#define hrd_log(level, enable, log_id, format, para1, para2, para3, para4) \
    do  \
    {   \
        if (unlikely(level >= enable)) \
        {  \
            osal_printf("%s:%d " format, __func__, __LINE__, para1, para2, para3, para4);  \
        }  \
    }   \
    while (0)

#else
/* HRD�ݲ�֧����־��¼��ֻ�ô�ӡ */
/****************************************************************************************/
/* ��ʽ�����汾��ӡ��ϵͳ��־�����ϲ�ص��ӿڣ� ����ͬһ��ģ�飬��־��ŵ�ͬһ��������  */
/* ��ͬ�ȼ���־��¼�꣬��ģ����Լ������޸�HRD_THIS_MODULE_PT_ID��HRD_THIS_MODULE_ID    */
/* ����: #undef HRD_THIS_MODULE_PT_ID                                                   */
/*       #define HRD_THIS_MODULE_PT_ID   0                                              */
/*       #undef HRD_THIS_MODULE_ID                                                      */
/*       #define HRD_THIS_MODULE_ID   0                                                 */
/****************************************************************************************/
 #define hrd_log(level, log_id, format, para1, para2, para3, para4) \
    do  \
    {   \
        IWARE_LogOutPut(HRD_THIS_MODULE_PT_ID, log_id, HRD_THIS_MODULE_ID, level, format, para1, para2, para3, para4);  \
    }   \
    while (0)
#endif

/*****************************************************/
/* ��ͬ�ȼ���־��¼�꣬��ģ����Լ������޸�HRD_NAME */
/* ����: #undef HRD_NAME                            */
/*       #define HRD_NAME   "dsaf"                 */
/*****************************************************/
#if 0 /*TBD*/
#define hrd_log_dbg(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_DEBUGGING, HRD_DBG_ENABLE, log_id, "<" HRD_NAME "-DBG>" format, para1, para2, para3, para4)

/*lint -emacro(506, hrd_log_info, hrd_log_warn, hrd_log_err) */
#define hrd_log_info(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_INFORMATIONAL, 1, log_id, "<" HRD_NAME "-INFO>" format, para1, para2, para3, para4)

#define hrd_log_note(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_NOTIFICATION, 1, log_id,"<" HRD_NAME "-NOTE>" format, para1, para2, para3, para4)

#define hrd_log_warn(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_WARNING, 1, log_id, "<" HRD_NAME "-WARN>" format, para1, para2, para3, para4)

#define hrd_log_err(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_ERROR, 1, log_id,"<" HRD_NAME "-ERR>" format, para1, para2, para3, para4)

#define hrd_log_crit(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_CRITICAL,1, log_id,"<" HRD_NAME "-CRIT>" format, para1, para2, para3, para4)

#define hrd_log_alrt(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_ALERT, 1, log_id, "<" HRD_NAME "-ALRT>" format, para1, para2, para3, para4)

#define hrd_log_emrg(log_id, format, para1, para2, para3, para4) \
    hrd_log(IWARE_LOG_LEVEL_EMERGENCY, 1, log_id,"<" HRD_NAME "-EMRG>" format, para1, para2, para3, para4)
#endif

#define log_dbg(dev, fmt, arg...) dev_dbg(dev, fmt, ##arg)

#define log_info(dev, fmt, arg...) dev_info(dev, fmt, ##arg)

#define log_note(dev, fmt, arg...) dev_note(dev, fmt, ##arg)

#define log_warn(dev, fmt, arg...) dev_warn(dev, fmt, ##arg)

#define log_err(dev, fmt, arg...) dev_err(dev, fmt, ##arg)

#define log_crit(dev, fmt, arg...) dev_crit(dev, fmt, ##arg)

#define log_alrt(dev, fmt, arg...) dev_alrt(dev, fmt, ##arg)

#define log_emrg(dev, fmt, arg...) dev_emrg(dev, fmt, ##arg)

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#endif /* _HRD_LOG_H */




/**
 * @file SRE_errno.h
 *
 * Copyright(C), 2008-2050, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * ������ͨ�ô����붨��ͷ�ļ��� \n
 */

/**
 * @addtogroup SRE_err  ������
 * @ingroup SRE_inspect
 * @{
*/

#ifndef _SRE_ERRNO_H
#define _SRE_ERRNO_H

#include "SRE_base.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#define SRE_ErrHandle(pcFileName, uwLineNo, uwErrorNo, uwPara1, uwPara2) \
    SRE_printf("%s,%d:%#x,%#x,%#x\n", pcFileName, uwLineNo, uwErrorNo, uwPara1, uwPara2);

#define SRE_DotSet(pcFileName, uwLineNo, uwPara1, uwPara2) \
    SRE_printf("%s,%d:%#x,%#x\n", pcFileName, uwLineNo, uwPara1, uwPara2)

/* 0x00��ʾOS,0xFF��ʾDRV,Ӧ��ϵͳ����ʹ�� 1~254 ����ʾӦ�ø�����ϵͳ */
#define SRE_ERRNO_OS_ID                                     ((UINT32)0x00 << 16)

/* �������ĵȼ� */
#define SRE_ERRTYPE_NORMAL                                  ((UINT32)0x00 << 24)
#define SRE_ERRTYPE_WARN                                    ((UINT32)0x01 << 24)
#define SRE_ERRTYPE_ERROR                                   ((UINT32)0x02 << 24)
#define SRE_ERRTYPE_FATAL                                   ((UINT32)0x03 << 24)

/**
 * @brief ����OS��������
 *
 * @description
 * �궨�壬����OS��������
 *
 * @attention ��

 * @param[in]   MID ģ��ID��š�
 * @param[in]   ERRNO �������š�
 *
 * @retval ��
 * @depend
 * SRE_errno.h: �ú궨�����ڵ�ͷ�ļ���
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_ERROR | SRE_ERRNO_OS_WARN | SRE_ERRNO_OS_NORMAL
 */
#define SRE_ERRNO_OS_FATAL(MID,ERRNO)   \
            (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_FATAL | (ERRNO))


/**
 * @brief ����OS���ش���
 *
 * @description
 * �궨�壬����OS���ش���
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
#define SRE_ERRNO_OS_ERROR(MID,ERRNO)  \
            (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_ERROR | (ERRNO))


/**
 * @brief ����OS�澯��Ϣ
 *
 * @description
 * �궨�壬����OS�澯
 *
 * @attention ��
 * @param[in]   MID ģ��ID��š�
 * @param[in]   ERRNO �������š�
 *
 * @retval ��
 * @depend
 * SRE_errno.h: �ú궨�����ڵ�ͷ�ļ���
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_FATAL | SRE_ERRNO_OS_ERROR | SRE_ERRNO_OS_NORMAL
 */
#define SRE_ERRNO_OS_WARN(MID,ERRNO)  \
            (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_WARN | (ERRNO))


/**
 * @brief ����OS��ʾ��Ϣ
 *
 * @description
 * �궨�壬����OS��ʾ��Ϣ
 *
 * @attention ��
 * @param[in]   MID ģ��ID��š�
 * @param[in]   ERRNO �������š�
 *
 * @retval ��
 * @depend
 * @li SRE_errno.h: �ú궨�����ڵ�ͷ�ļ���
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_FATAL | SRE_ERRNO_OS_ERROR | SRE_ERRNO_OS_WARN
 */
#define SRE_ERRNO_OS_NORMAL(MID,ERRNO)  \
        (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_NORMAL | (ERRNO)); \


/**
*@brief ������Ϣ��¼
*
*@description
*��¼������Ϣ
*
*@attention  ��
*
*@param[in] uwErrLine,����#UINT32 �����к�
*@param[in] uwErrNo,  ����#UINT32 ������
*@param[in] uwPara1,  ����#UINT32 ��¼��Ϣ1
*@param[in] uwPara2,  ����#UINT32 ��¼��Ϣ2
*
*@retval ��
*@depend
*@li SRE_errno.h
*@since SRE V100R001
*@see SRE_ErrHandle
*/
#define REPORT_ERROR(uwErrLine, uwErrNo, uwPara1, uwPara2)  \
    SRE_MACRO_S \
        SRE_ErrHandle(__FILE__, uwErrLine, uwErrNo, (UINT32)(uwPara1), (UINT32)(uwPara2)); \
    SRE_MACRO_E

/**
*@brief ������Ϣ��¼�����ش�����
*
*@description
*�����쳣ʱ��¼�������ص�͸�����Ϣ��\n
*�����ش�����
*
*@attention ��
*
*@param[in] uwErrLine,����#UINT32 �����к�
*@param[in] uwErrNo,  ����#UINT32 ������
*@param[in] uwPara1,  ����#UINT32 ��¼��Ϣ1
*@param[in] uwPara2,  ����#UINT32 ��¼��Ϣ2
*
*@retval uwErrNo,����#UINT32 ������
*@depend
*@li SRE_errno.h
*@since SRE V001R001
*@see SRE_ErrHandle
*/
#define RETURN_ERROR(uwErrLine, uwErrNo, uwPara1, uwPara2) \
    SRE_MACRO_S \
        SRE_ErrHandle(__FILE__, uwErrLine, uwErrNo, (UINT32)(uwPara1), (UINT32)(uwPara2)); \
        \
        return uwErrNo; \
    SRE_MACRO_E

/**
*@brief ������ת
*@description
*������ʱ��¼������Ϣ������ת������ִ�д�#ErrHandler
*
*@attention
*@li �����ֻ�ʺ϶��쳣��֧�����Σ��Լ��ٴ���ߴ�
*@li ʹ�ñ���ĺ������붨��ֲ�����uwErrNo����UINT32,uwErrLine����UINT32,
*uwPara1����UINT32,uwPara2����UINT32
*
*@param[in] uwErrNo,  ����#UINT32 ������
*@param[in] uwP1,  ����#UINT32 ��¼��Ϣ1
*@param[in] uwP2,  ����#UINT32 ��¼��Ϣ2
*
*@depend
*@li SRE_errno.h
*@since SRE V001R001
*@see ��
*/
#define GOTO_ERR_HANDLER(uwErrorNo, uwP1, uwP2) \
    SRE_MACRO_S \
        uwErrNo    = uwErrorNo; \
        uwErrLine  = __LINE__; \
        uwPara1 = (UINT32)(uwP1); \
        uwPara2 = (UINT32)(uwP2); \
        goto ErrHandler; \
    SRE_MACRO_E

/**
*@brief ��¼��ʼ�������Ϣ
*@description
*��¼��ʼ�������Ϣ�����ϵͳ��־�ѳ�ʼ���ɹ���ͬʱ��¼��־��Ϣ
*
*@attention
*
*@param[in] uwP1,  ����#UINT32 �����Ϣ1
*@param[in] uwP2,  ����#UINT32 �����Ϣ2
*
*@depend
*@li SRE_errno.h
*@since SRE V001R001
*@see ��
*/
#define SRE_INIT_DOT(uwP1, uwP2) \
    SRE_MACRO_S \
        SRE_DotSet(__FILE__, __LINE__, (uwP1), (uwP2));\
    SRE_MACRO_E

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif /* _SRE_ERRNO_H */

/**
 * @}
*/

/**
 * History:
 *
 * vi: set expandtab ts=4 sw=4 tw=80:
*/


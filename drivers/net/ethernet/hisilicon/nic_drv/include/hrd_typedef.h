/**
 * @file hrd_typedef.h
 *
 * Copyright(C), 2008-2050, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * ��������������������ͺ����ݽṹ�� \n
 */

/**
 * @addtogroup hrd_sys ϵͳ�������ܽӿ�
 * @ingroup
 * @{
*/

#ifndef _HRD_TYPEDEF_H
#define _HRD_TYPEDEF_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#ifndef INLINE
#define INLINE                                              static __inline
#endif

#ifndef SRE_TYPE_DEF
#define SRE_TYPE_DEF

/* type definitions */
/* SRE�ӿڲ�ʹ�õ��������� */
typedef unsigned char                                       UINT8;
typedef unsigned short                                      UINT16;
typedef unsigned int                                        UINT32;
typedef signed short                                        INT16;
typedef signed int                                          INT32;
typedef float                                               FLOAT;
typedef double                                              DOUBLE;
typedef char                                                CHAR;
typedef unsigned long long                                  UINT64;
typedef signed long long                                    INT64;
typedef unsigned int                                        UINTPTR;
typedef signed int                                          INTPTR;
typedef char                                                INT8;
#define VOID                                                void



/* Linux�ӿڲ�ʹ�õ��������ͣ����HAL����Ҫ��Linux���ṩ������Ҫʹ�������������
   ���壬����ʹ��SRE�ӿڲ�ʹ�õ����Ͷ��� */
#ifdef HRD_OS_SRE
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef char                s8;
typedef short               s16;
typedef int                 s32;
typedef long long           s64;
#endif /* HRD_OS_SRE */

#ifdef HRD_OS_LINUX
typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef unsigned long long  U64;
typedef char                S8;
typedef short               S16;
typedef int                 S32;
typedef long long           S64;

#endif /* HRD_OS_LINUX */


#endif  /*end of #ifndef SRE_TYPE_DEF*/

#ifndef NULL
#define NULL                                                ((VOID *)0)
#endif

typedef unsigned int                                        BOOL;


#ifndef HRD_STATUS
#define HRD_STATUS int
#endif


typedef void* hrd_handle_t;

#ifndef FALSE
#define FALSE                                               ((BOOL)0)
#endif

#ifndef TRUE
#define TRUE                                                ((BOOL)1)
#endif

#ifndef OK
#define OK      0
#endif

#ifndef ERROR
#define ERROR	(-1)
#endif

/* ��Linux�д󲿷ֺ������Զ����static��������SRE�£���Щ�����ᱻ�����ļ�ֱ�ӵ��ã�
   �޷������static�����Զ�������ĺ꣬ͨ����ͬ�ı���ѡ����ѡ�� */
#ifdef HRD_OS_SRE
#ifndef LINUX_STATIC
#define LINUX_STATIC
#endif
#else
#ifndef LINUX_STATIC
#define LINUX_STATIC static
#endif
#endif /* HRD_OS_SRE */

#ifdef HRD_OS_SRE
#ifndef OSAL_ERR_PTR
#define OSAL_ERR_PTR(error) ((void *)error)
#endif
#else
#ifndef OSAL_ERR_PTR
#define OSAL_ERR_PTR(error) ERR_PTR(error)
#endif
#endif /* HRD_OS_SRE */

#ifdef HRD_OS_SRE
#ifndef OSAL_PTR_ERR
#define OSAL_PTR_ERR(ptr) ((long)ptr)
#endif
#else
#ifndef OSAL_PTR_ERR
#define OSAL_PTR_ERR(ptr) PTR_ERR(ptr)
#endif
#endif /* HRD_OS_SRE */


#define ENDNESS_LITTLE 123
#define ENDNESS_BIG    321


#define ENDNESS ENDNESS_LITTLE




#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif /* _HRD_TYPEDEF_H */

/**
 * @}
*/

/**
 * History:
 *
 * vi: set expandtab ts=4 sw=4 tw=80:
*/


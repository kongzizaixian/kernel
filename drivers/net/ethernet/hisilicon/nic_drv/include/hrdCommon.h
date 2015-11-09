/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : hdrCommon.h
  �� �� ��   : ����
  ��    ��   : x68638
  ��������   : 2013��4��26��
  ����޸�   :
  ��������   : ͨ�ò�ĺ궨��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��26��
    ��    ��   : x68638
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __HRD_COMMON_H__
#define __HRD_COMMON_H__

#include "hrdTypes.h"

/* �Ĵ��������ĺ궨�� */
#define ___CONSTANT_BYTE_SWAP16(x) ((unsigned short)(               \
    (((unsigned short)(x) & (unsigned short)0x00ffU) << 8) |        \
    (((unsigned short)(x) & (unsigned short)0xff00U) >> 8)))

#define ___CONSTANT_BYTE_SWAP32(x) ((unsigned int)(             \
    (((unsigned int)(x) & (unsigned int)0x000000ffUL) << 24) |      \
    (((unsigned int)(x) & (unsigned int)0x0000ff00UL) <<  8) |      \
    (((unsigned int)(x) & (unsigned int)0x00ff0000UL) >>  8) |      \
    (((unsigned int)(x) & (unsigned int)0xff000000UL) >> 24)))


/* ��������Ԫ�ظ����ĺ� */
#define NELEMENTS(x) (sizeof(x) / sizeof((x)[0]))



/* Swap tool */

/* 16bit nibble swap. For example 0x1234 -> 0x2143                          */
#define HRD_NIBBLE_SWAP_16BIT(X)        (((X&0xf) << 4) |     \
                    ((X&0xf0) >> 4) |    \
                    ((X&0xf00) << 4) |   \
                    ((X&0xf000) >> 4))

/* 32bit nibble swap. For example 0x12345678 -> 0x21436587                  */
#define HRD_NIBBLE_SWAP_32BIT(X)        (((X&0xf) << 4) |       \
                    ((X&0xf0) >> 4) |      \
                    ((X&0xf00) << 4) |     \
                    ((X&0xf000) >> 4) |    \
                    ((X&0xf0000) << 4) |   \
                    ((X&0xf00000) >> 4) |  \
                    ((X&0xf000000) << 4) | \
                    ((X&0xf0000000) >> 4))

/* 16bit byte swap. For example 0x1234->0x3412                             */
#define HRD_BYTE_SWAP_16BIT(X) ((((X)&0xff)<<8) | (((X)&0xff00)>>8))

/* 32bit byte swap. For example 0x12345678->0x78563412                    */
#define HRD_BYTE_SWAP_32BIT(X)  ((((X)&0xff)<<24) |                       \
                (((X)&0xff00)<<8) |                      \
                (((X)&0xff0000)>>8) |                    \
                (((X)&0xff000000)>>24))

/* 64bit byte swap. For example 0x11223344.55667788 -> 0x88776655.44332211  */
#define HRD_BYTE_SWAP_64BIT(X) ((l64) ((((X)&0xffULL)<<56) |             \
                      (((X)&0xff00ULL)<<40) |           \
                      (((X)&0xff0000ULL)<<24) |         \
                      (((X)&0xff000000ULL)<<8) |        \
                      (((X)&0xff00000000ULL)>>8) |      \
                      (((X)&0xff0000000000ULL)>>24) |   \
                      (((X)&0xff000000000000ULL)>>40) | \
                      (((X)&0xff00000000000000ULL)>>56)))

/* Endianess macros.                                                        */
#ifdef HRD_ENDNESS_BIGEND
#define HRD_16BIT_LE(X)  HRD_BYTE_SWAP_16BIT(X)
#define HRD_32BIT_LE(X)  HRD_BYTE_SWAP_32BIT(X)
#define HRD_64BIT_LE(X)  HRD_BYTE_SWAP_64BIT(X)
#define HRD_16BIT_BE(X)  (X)
#define HRD_32BIT_BE(X)  (X)
#define HRD_64BIT_BE(X)  (X)
#else
#define HRD_16BIT_LE(X)  (X)
#define HRD_32BIT_LE(X)  (X)
#define HRD_64BIT_LE(X)  (X)
#define HRD_16BIT_BE(X)  HRD_BYTE_SWAP_16BIT(X)
#define HRD_32BIT_BE(X)  HRD_BYTE_SWAP_32BIT(X)
#define HRD_64BIT_BE(X)  HRD_BYTE_SWAP_64BIT(X)
#endif



#endif


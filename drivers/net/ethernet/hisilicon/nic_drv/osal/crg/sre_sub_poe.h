/*--------------------------------------------------------------------------------------------------------------------------*/
/*!!Warning: This is a key information asset of Huawei Tech Co.,Ltd                                                         */
/*CODEMARK:kOyQZYzjDpyGdBAEC2GaWuVy7vy/wDnq7gJfHBOj2pBXFF9pJtpDLt9sw5WJiMsUkN5d7jr7
aK5J3kmlnl+vpaISWHqOHbuE99WnZz8Urp0KNb0WWl+qRa4EjbbH6IvvJ8uAZ7aN4Vd0NGho
uLjlYjdG/wj7jenmVvgfy1lONWJ3sNrNyJEi40IwsqM/7aUB2pSe87Zdp6XELPzsV+qW0p3p
n+6IO8vtzdg+V3Hatojhu30RtAQlugyuY8Djve+ROc/TwQWL5e+6Rd/Ies50Iw==*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/******************************************************************************

                  ��Ȩ���� (C), 2011-2021, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : sre_sub_peri.h
  �� �� ��   : ����
  ��    ��   : z00176027
  ��������   : 2013��10��17��
  ����޸�   :
  ��������   : p660��ϵͳ8 ��λ���⸴λ���ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��10��17��
    ��    ��   : z00176027
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __POE_SUB_REG_OFFSET_H__
#define __POE_SUB_REG_OFFSET_H__


#include "hrdCommon.h"
#include "hrdOs.h"
#include "osal_api.h"
#include "sre_crg_api.h"

#ifdef HRD_OS_LINUX
#include "iware_comm_kernel_api.h"
#endif



/*----------------------------------------------*
 * �ⲿ����˵��                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ⲿ����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ȫ�ֱ���                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/

/* POE_SUB Base address of Module's Register */
#define POE_SUB_BASE                       (0xE0000000)

/******************************************************************************/
/*                      PHOSPHOR POE_SUB Registers' Definitions                            */
/******************************************************************************/

#define POE_SUB_SC_SRAM_CLK_EN_REG            (POE_SUB_BASE + 0x340)  /* SRAMʱ��ʹ�ܼĴ��� */
#define POE_SUB_SC_SRAM_CLK_DIS_REG           (POE_SUB_BASE + 0x344)  /* SRAMʱ�ӽ�ֹ�Ĵ��� */
#define POE_SUB_SC_POE_CLK_EN_REG             (POE_SUB_BASE + 0x500)  /* POEʱ��ʹ�ܼĴ��� */
#define POE_SUB_SC_POE_CLK_DIS_REG            (POE_SUB_BASE + 0x504)  /* POEʱ�ӽ�ֹ�Ĵ��� */
#define POE_SUB_SC_SRAM_RESET_REQ_REG         (POE_SUB_BASE + 0xA40)  /* SRAM��λ������ƼĴ��� */
#define POE_SUB_SC_SRAM_RESET_DREQ_REG        (POE_SUB_BASE + 0xA44)  /* SRAM��λȥ������ƼĴ��� */
#define POE_SUB_SC_POE_RESET_REQ_REG          (POE_SUB_BASE + 0xB18)  /* poe��λ������ƼĴ��� */
#define POE_SUB_SC_POE_RESET_DREQ_REG         (POE_SUB_BASE + 0xB1C)  /* poe��λȥ������ƼĴ��� */
#define POE_SUB_SC_DISPATCH_DAW_EN_REG        (POE_SUB_BASE + 0x1000) /* dispatch daw en���� */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY0_REG    (POE_SUB_BASE + 0x1004) /* dispatch daw��������0 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY1_REG    (POE_SUB_BASE + 0x1008) /* dispatch daw��������1 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY2_REG    (POE_SUB_BASE + 0x100C) /* dispatch daw��������2 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY3_REG    (POE_SUB_BASE + 0x1010) /* dispatch daw��������3 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY4_REG    (POE_SUB_BASE + 0x1014) /* dispatch daw��������4 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY5_REG    (POE_SUB_BASE + 0x1018) /* dispatch daw��������5 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY6_REG    (POE_SUB_BASE + 0x101C) /* dispatch daw��������6 */
#define POE_SUB_SC_DISPATCH_DAW_ARRAY7_REG    (POE_SUB_BASE + 0x1020) /* dispatch daw��������7 */
#define POE_SUB_SC_DISPATCH_RETRY_CONTROL_REG (POE_SUB_BASE + 0x1030) /* dispatch retry���ƼĴ��� */
#define POE_SUB_SC_DISPATCH_INTMASK_REG       (POE_SUB_BASE + 0x1100) /* dispatch���ж����μĴ��� */
#define POE_SUB_SC_DISPATCH_RAWINT_REG        (POE_SUB_BASE + 0x1104) /* dispatch��ԭʼ�ж�״̬�Ĵ��� */
#define POE_SUB_SC_DISPATCH_INTSTAT_REG       (POE_SUB_BASE + 0x1108) /* dispatch�����κ���ж�״̬�Ĵ��� */
#define POE_SUB_SC_DISPATCH_INTCLR_REG        (POE_SUB_BASE + 0x110C) /* dispatch���ж�����Ĵ��� */
#define POE_SUB_SC_DISPATCH_ERRSTAT_REG       (POE_SUB_BASE + 0x1110) /* dispatch��ERR״̬�Ĵ��� */
#define POE_SUB_SC_DISPATCH_REMAP_CTRL_REG    (POE_SUB_BASE + 0x1200) /* subsys������Remap�Ĵ��� */
#define POE_SUB_SC_SRAM_CTRL0_REG             (POE_SUB_BASE + 0x2030) /* sram���ƼĴ���0 */
#define POE_SUB_SC_SRAM_CTRL1_REG             (POE_SUB_BASE + 0x2034) /* sram���ƼĴ���1����ȫ�Ĵ����� */
#define POE_SUB_SC_SRAM_CTRL2_REG             (POE_SUB_BASE + 0x2038) /* sram���ƼĴ���2����ȫ�Ĵ����� */
#define POE_SUB_SC_SRAM_CTRL3_REG             (POE_SUB_BASE + 0x203C) /* sram���ƼĴ���3����ȫ�Ĵ����� */
#define POE_SUB_SC_SMMU_MEM_CTRL1_REG         (POE_SUB_BASE + 0x3004) /* smmu mem���ƼĴ���1 */
#define POE_SUB_SC_SMMU_MEM_CTRL2_REG         (POE_SUB_BASE + 0x3008) /* smmu mem���ƼĴ���2 */
#define POE_SUB_SC_SRAM_MEM_CTRL_REG          (POE_SUB_BASE + 0x3010) /* sram mem���ƼĴ��� */
#define POE_SUB_SC_PLLFCTRL0_REG              (POE_SUB_BASE + 0x3014) /* SC_PLLFCTRL0ΪCIDE_CRG��PLL0���ƼĴ���0�� */
#define POE_SUB_SC_PLLFCTRL1_REG              (POE_SUB_BASE + 0x3018) /* SC_PLLFCTRL1ΪCIDE_CRG��PLL0���ƼĴ���1�� */
#define POE_SUB_SC_PLLFCTRL8_REG              (POE_SUB_BASE + 0x3034) /* SC_PLLFCTRL8ΪCIDE_CRG��PLL4���ƼĴ���0�� */
#define POE_SUB_SC_PLLFCTRL9_REG              (POE_SUB_BASE + 0x3038) /* SC_PLLFCTRL9ΪCIDE_CRG��PLL4���ƼĴ���1�� */
#define POE_SUB_SC_PLL_CLK_BYPASS0_REG        (POE_SUB_BASE + 0x3040) /* SC_PLL_CLK_BYPASS0ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
#define POE_SUB_SC_PLL_CLK_BYPASS1_REG        (POE_SUB_BASE + 0x3044) /* SC_PLL_CLK_BYPASS1ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
#define POE_SUB_SC_CLK_SEL_REG                (POE_SUB_BASE + 0x3048) /* SC_CLK_SEL��CDIE_CRG�Ĵ�������ϵͳ����ʱ��Ƶ��ѡ��Ĵ����� */
#define POE_SUB_SC_TSMC_PLLCTRL1_REG          (POE_SUB_BASE + 0x3204) /* SC_TSMC_PLLCTRL1ΪCIDE��PLL1��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
#define POE_SUB_SC_TSMC_PLLCTRL4_REG          (POE_SUB_BASE + 0x3210) /* SC_TSMC_PLLCTRL4ΪCIDE CRG��PLL4��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
#define POE_SUB_SC_PLL_SEL_REG                (POE_SUB_BASE + 0x3214) /* SC_PLL_SELΪCIDE�ڵ�PLLѡ����ƼĴ����� */
#define POE_SUB_SC_SRAM_CLK_ST_REG            (POE_SUB_BASE + 0x5320) /* SRAMʱ��״̬�Ĵ��� */
#define POE_SUB_SC_POE_CLK_ST_REG             (POE_SUB_BASE + 0x5400) /* POEʱ��״̬�Ĵ��� */
#define POE_SUB_SC_SRAM_RESET_ST_REG          (POE_SUB_BASE + 0x5A20) /* SRAM��λ״̬�Ĵ��� */
#define POE_SUB_SC_POE_RESET_ST_REG           (POE_SUB_BASE + 0x5B00) /* poe��λ״̬�Ĵ��� */
#define POE_SUB_SC_SRAM_ST0_REG               (POE_SUB_BASE + 0x6000) /* sram״̬�Ĵ���0 */
#define POE_SUB_SC_SRAM_ST1_REG               (POE_SUB_BASE + 0x6004) /* sram״̬�Ĵ���1 */
#define POE_SUB_SC_SRAM_ST2_REG               (POE_SUB_BASE + 0x6008) /* sram״̬�Ĵ���2 */
#define POE_SUB_SC_SRAM_ST3_REG               (POE_SUB_BASE + 0x600C) /* sram״̬�Ĵ���3 */
#define POE_SUB_SC_SRAM_ST4_REG               (POE_SUB_BASE + 0x6010) /* sram״̬�Ĵ���4 */
#define POE_SUB_SC_SRAM_ST5_REG               (POE_SUB_BASE + 0x6014) /* sram״̬�Ĵ���5 */
#define POE_SUB_SC_ECO_RSV0_REG               (POE_SUB_BASE + 0x8000) /* ECO �Ĵ���0 */
#define POE_SUB_SC_ECO_RSV1_REG               (POE_SUB_BASE + 0x8004) /* ECO �Ĵ���1 */
#define POE_SUB_SC_ECO_RSV2_REG               (POE_SUB_BASE + 0x8008) /* ECO �Ĵ���2 */

#if(ENDNESS == ENDNESS_BIG)

/* Define the union U_SC_SRAM_CLK_EN_U */
/* SRAMʱ��ʹ�ܼĴ��� */
/* 0x340 */
typedef union tagScSramClkEn
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    clk_sram_enb          : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_EN_U;

/* Define the union U_SC_SRAM_CLK_DIS_U */
/* SRAMʱ�ӽ�ֹ�Ĵ��� */
/* 0x344 */
typedef union tagScSramClkDis
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    clk_sram_dsb          : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_DIS_U;

/* Define the union U_SC_POE_CLK_EN_U */
/* POEʱ��ʹ�ܼĴ��� */
/* 0x500 */
typedef union tagScPoeClkEn
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    clk_poe_enb           : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_EN_U;

/* Define the union U_SC_POE_CLK_DIS_U */
/* POEʱ�ӽ�ֹ�Ĵ��� */
/* 0x504 */
typedef union tagScPoeClkDis
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    clk_poe_dsb           : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_DIS_U;

/* Define the union U_SC_SRAM_RESET_REQ_U */
/* SRAM��λ������ƼĴ��� */
/* 0xA40 */
typedef union tagScSramResetReq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    sram_srst_req         : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_REQ_U;

/* Define the union U_SC_SRAM_RESET_DREQ_U */
/* SRAM��λȥ������ƼĴ��� */
/* 0xA44 */
typedef union tagScSramResetDreq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    sram_srst_dreq        : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_DREQ_U;

/* Define the union U_SC_POE_RESET_REQ_U */
/* poe��λ������ƼĴ��� */
/* 0xB18 */
typedef union tagScPoeResetReq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    poe_srst_req          : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_REQ_U;

/* Define the union U_SC_POE_RESET_DREQ_U */
/* poe��λȥ������ƼĴ��� */
/* 0xB1C */
typedef union tagScPoeResetDreq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    poe_srst_dreq         : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_DREQ_U;

/* Define the union U_SC_DISPATCH_DAW_EN_U */
/* dispatch daw en���� */
/* 0x1000 */
typedef union tagScDispatchDawEn
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
        unsigned int    dispatch_daw_en       : 8   ; /* [7..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_EN_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY0_U */
/* dispatch daw��������0 */
/* 0x1004 */
typedef union tagScDispatchDawArray0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array0_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array0_sync       : 1   ; /* [8]  */
        unsigned int    daw_array0_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array0_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY0_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY1_U */
/* dispatch daw��������1 */
/* 0x1008 */
typedef union tagScDispatchDawArray1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array1_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array1_sync       : 1   ; /* [8]  */
        unsigned int    daw_array1_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array1_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY1_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY2_U */
/* dispatch daw��������2 */
/* 0x100C */
typedef union tagScDispatchDawArray2
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array2_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array2_sync       : 1   ; /* [8]  */
        unsigned int    daw_array2_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array2_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY2_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY3_U */
/* dispatch daw��������3 */
/* 0x1010 */
typedef union tagScDispatchDawArray3
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array3_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array3_sync       : 1   ; /* [8]  */
        unsigned int    daw_array3_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array3_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY3_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY4_U */
/* dispatch daw��������4 */
/* 0x1014 */
typedef union tagScDispatchDawArray4
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array4_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array4_sync       : 1   ; /* [8]  */
        unsigned int    daw_array4_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array4_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY4_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY5_U */
/* dispatch daw��������5 */
/* 0x1018 */
typedef union tagScDispatchDawArray5
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array5_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array5_sync       : 1   ; /* [8]  */
        unsigned int    daw_array5_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array5_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY5_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY6_U */
/* dispatch daw��������6 */
/* 0x101C */
typedef union tagScDispatchDawArray6
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array6_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array6_sync       : 1   ; /* [8]  */
        unsigned int    daw_array6_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array6_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY6_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY7_U */
/* dispatch daw��������7 */
/* 0x1020 */
typedef union tagScDispatchDawArray7
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array7_addr       : 19  ; /* [31..13]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array7_sync       : 1   ; /* [8]  */
        unsigned int    daw_array7_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array7_did        : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY7_U;

/* Define the union U_SC_DISPATCH_RETRY_CONTROL_U */
/* dispatch retry���ƼĴ��� */
/* 0x1030 */
typedef union tagScDispatchRetryControl
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
        unsigned int    retry_en              : 1   ; /* [16]  */
        unsigned int    retry_num_limit       : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_RETRY_CONTROL_U;

/* Define the union U_SC_DISPATCH_INTMASK_U */
/* dispatch���ж����μĴ��� */
/* 0x1100 */
typedef union tagScDispatchIntmask
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    intmask               : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTMASK_U;

/* Define the union U_SC_DISPATCH_RAWINT_U */
/* dispatch��ԭʼ�ж�״̬�Ĵ��� */
/* 0x1104 */
typedef union tagScDispatchRawint
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    rawint                : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_RAWINT_U;

/* Define the union U_SC_DISPATCH_INTSTAT_U */
/* dispatch�����κ���ж�״̬�Ĵ��� */
/* 0x1108 */
typedef union tagScDispatchIntstat
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    intsts                : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTSTAT_U;

/* Define the union U_SC_DISPATCH_INTCLR_U */
/* dispatch���ж�����Ĵ��� */
/* 0x110C */
typedef union tagScDispatchIntclr
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    intclr                : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTCLR_U;

/* Define the union U_SC_DISPATCH_ERRSTAT_U */
/* dispatch��ERR״̬�Ĵ��� */
/* 0x1110 */
typedef union tagScDispatchErrstat
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 10  ; /* [31..22]  */
        unsigned int    err_addr              : 17  ; /* [21..5]  */
        unsigned int    err_opcode            : 5   ; /* [4..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_ERRSTAT_U;

/* Define the union U_SC_DISPATCH_REMAP_CTRL_U */
/* subsys������Remap�Ĵ��� */
/* 0x1200 */
typedef union tagScDispatchRemapCtrl
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    sys_remap_vld         : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_REMAP_CTRL_U;

/* Define the union U_SC_SRAM_CTRL0_U */
/* sram���ƼĴ���0 */
/* 0x2030 */
typedef union tagScSramCtrl0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 25  ; /* [31..7]  */
        unsigned int    sram_swap_en          : 1   ; /* [6]  */
        unsigned int    sram_mulerr_addr_clr  : 1   ; /* [5]  */
        unsigned int    sram_sglerr_addr_clr  : 1   ; /* [4]  */
        unsigned int    sram_err_cnt_clr      : 1   ; /* [3]  */
        unsigned int    sram_err_clr          : 1   ; /* [2]  */
        unsigned int    sram_ecc_err_trans    : 1   ; /* [1]  */
        unsigned int    sram_ecc_en           : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CTRL0_U;

/* Define the union U_SC_SRAM_CTRL1_U */
/* sram���ƼĴ���1����ȫ�Ĵ����� */
/* 0x2034 */
typedef union tagScSramCtrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    sram_prot_ctrl_en     : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CTRL1_U;

/* Define the union U_SC_SMMU_MEM_CTRL1_U */
/* smmu mem���ƼĴ���1 */
/* 0x3004 */
typedef union tagScSmmuMemCtrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
        unsigned int    tsel_hc_smmu          : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SMMU_MEM_CTRL1_U;

/* Define the union U_SC_SMMU_MEM_CTRL2_U */
/* smmu mem���ƼĴ���2 */
/* 0x3008 */
typedef union tagScSmmuMemCtrl2
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
        unsigned int    test_hc_smmu          : 2   ; /* [1..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SMMU_MEM_CTRL2_U;

/* Define the union U_SC_SRAM_MEM_CTRL_U */
/* sram mem���ƼĴ��� */
/* 0x3010 */
typedef union tagScSramMemCtrl
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
        unsigned int    ctrl_rashde_sram      : 4   ; /* [3..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_MEM_CTRL_U;

/* Define the union U_SC_PLLFCTRL0_U */
/* SC_PLLFCTRL0ΪCIDE_CRG��PLL0���ƼĴ���0�� */
/* 0x3014 */
typedef union tagScPllfctrl0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 1   ; /* [31]  */
        unsigned int    pll0_foutvcopd        : 1   ; /* [30]  */
        unsigned int    pll0_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll0_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll0_dacpd            : 1   ; /* [27]  */
        unsigned int    pll0_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll0_pd               : 1   ; /* [25]  */
        unsigned int    pll0_bypass           : 1   ; /* [24]  */
        unsigned int    pll0_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll0_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll0_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll0_refdiv           : 6   ; /* [5..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL0_U;

/* Define the union U_SC_PLLFCTRL1_U */
/* SC_PLLFCTRL1ΪCIDE_CRG��PLL0���ƼĴ���1�� */
/* 0x3018 */
typedef union tagScPllfctrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 6   ; /* [31..26]  */
        unsigned int    pll0_frac             : 26  ; /* [25..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL1_U;

/* Define the union U_SC_PLLFCTRL8_U */
/* SC_PLLFCTRL8ΪCIDE_CRG��PLL4���ƼĴ���0�� */
/* 0x3034 */
typedef union tagScPllfctrl8
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 1   ; /* [31]  */
        unsigned int    pll4_foutvcopd        : 1   ; /* [30]  */
        unsigned int    pll4_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll4_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll4_dacpd            : 1   ; /* [27]  */
        unsigned int    pll4_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll4_pd               : 1   ; /* [25]  */
        unsigned int    pll4_bypass           : 1   ; /* [24]  */
        unsigned int    pll4_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll4_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll4_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll4_refdiv           : 6   ; /* [5..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL8_U;

/* Define the union U_SC_PLLFCTRL9_U */
/* SC_PLLFCTRL9ΪCIDE_CRG��PLL4���ƼĴ���1�� */
/* 0x3038 */
typedef union tagScPllfctrl9
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
        unsigned int    pll4_frac             : 24  ; /* [23..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL9_U;

/* Define the union U_SC_PLL_CLK_BYPASS0_U */
/* SC_PLL_CLK_BYPASS0ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
/* 0x3040 */
typedef union tagScPllClkBypass0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    pll4_peri_mode        : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS0_U;

/* Define the union U_SC_PLL_CLK_BYPASS1_U */
/* SC_PLL_CLK_BYPASS1ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
/* 0x3044 */
typedef union tagScPllClkBypass1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 27  ; /* [31..5]  */
        unsigned int    pll4_bypass_external_n : 1   ; /* [4]  */
        unsigned int    reserved_1            : 2   ; /* [3..2]  */
        unsigned int    pll1_bypass_external_n : 1   ; /* [1]  */
        unsigned int    pll0_bypass_external_n : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS1_U;

/* Define the union U_SC_CLK_SEL_U */
/* SC_CLK_SEL��CDIE_CRG�Ĵ�������ϵͳ����ʱ��Ƶ��ѡ��Ĵ����� */
/* 0x3048 */
typedef union tagScClkSel
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 22  ; /* [31..10]  */
        unsigned int    clk_div_sel           : 1   ; /* [9]  */
        unsigned int    gpio_db_clk_sel       : 1   ; /* [8]  */
        unsigned int    reserved_1            : 7   ; /* [7..1]  */
        unsigned int    cpu_clk_source_sel    : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLK_SEL_U;

/* Define the union U_SC_TSMC_PLLCTRL1_U */
/* SC_TSMC_PLLCTRL1ΪCIDE��PLL1��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
/* 0x3204 */
typedef union tagScTsmcPllctrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
        unsigned int    tsmc_pll1_postdiv     : 3   ; /* [17..15]  */
        unsigned int    tsmc_pll1_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll1_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll1_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll1_refdiv      : 5   ; /* [4..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL1_U;

/* Define the union U_SC_TSMC_PLLCTRL4_U */
/* SC_TSMC_PLLCTRL4ΪCIDE CRG��PLL4��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
/* 0x3210 */
typedef union tagScTsmcPllctrl4
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
        unsigned int    tsmc_pll4_postdiv     : 3   ; /* [17..15]  */
        unsigned int    tsmc_pll4_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll4_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll4_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll4_refdiv      : 5   ; /* [4..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL4_U;

/* Define the union U_SC_PLL_SEL_U */
/* SC_PLL_SELΪCIDE�ڵ�PLLѡ����ƼĴ����� */
/* 0x3214 */
typedef union tagScPllSel
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
        unsigned int    pll_sel               : 1   ; /* [2]  */
        unsigned int    reserved_1            : 2   ; /* [1..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_SEL_U;

/* Define the union U_SC_SRAM_CLK_ST_U */
/* SRAMʱ��״̬�Ĵ��� */
/* 0x5320 */
typedef union tagScSramClkSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    clk_sram_st           : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_ST_U;

/* Define the union U_SC_POE_CLK_ST_U */
/* POEʱ��״̬�Ĵ��� */
/* 0x5400 */
typedef union tagScPoeClkSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    clk_poe_st            : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_ST_U;

/* Define the union U_SC_SRAM_RESET_ST_U */
/* SRAM��λ״̬�Ĵ��� */
/* 0x5A20 */
typedef union tagScSramResetSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    sram_srst_st          : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_ST_U;

/* Define the union U_SC_POE_RESET_ST_U */
/* poe��λ״̬�Ĵ��� */
/* 0x5B00 */
typedef union tagScPoeResetSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
        unsigned int    poe_srst_st           : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_ST_U;

/* Define the union U_SC_SRAM_ST0_U */
/* sram״̬�Ĵ���0 */
/* 0x6000 */
typedef union tagScSramSt0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
        unsigned int    sram_multi_err        : 1   ; /* [2]  */
        unsigned int    sram_double_err       : 1   ; /* [1]  */
        unsigned int    sram_single_err       : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST0_U;

/* Define the union U_SC_SRAM_ST3_U */
/* sram״̬�Ĵ���3 */
/* 0x600C */
typedef union tagScSramSt3
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
        unsigned int    sram_count_ecc_sglerr : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST3_U;

/* Define the union U_SC_SRAM_ST4_U */
/* sram״̬�Ĵ���4 */
/* 0x6010 */
typedef union tagScSramSt4
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
        unsigned int    sram_count_ecc_mulerr : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST4_U;

/* Define the union U_SC_SRAM_ST5_U */
/* sram״̬�Ĵ���5 */
/* 0x6014 */
typedef union tagScSramSt5
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
        unsigned int    sram_dfx_dbg          : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST5_U;

#else

/* Define the union U_SC_SRAM_CLK_EN_U */
/* SRAMʱ��ʹ�ܼĴ��� */
/* 0x340 */
typedef union tagScSramClkEn
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_sram_enb          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_EN_U;

/* Define the union U_SC_SRAM_CLK_DIS_U */
/* SRAMʱ�ӽ�ֹ�Ĵ��� */
/* 0x344 */
typedef union tagScSramClkDis
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_sram_dsb          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_DIS_U;

/* Define the union U_SC_POE_CLK_EN_U */
/* POEʱ��ʹ�ܼĴ��� */
/* 0x500 */
typedef union tagScPoeClkEn
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_poe_enb           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_EN_U;

/* Define the union U_SC_POE_CLK_DIS_U */
/* POEʱ�ӽ�ֹ�Ĵ��� */
/* 0x504 */
typedef union tagScPoeClkDis
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_poe_dsb           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_DIS_U;

/* Define the union U_SC_SRAM_RESET_REQ_U */
/* SRAM��λ������ƼĴ��� */
/* 0xA40 */
typedef union tagScSramResetReq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_srst_req         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_REQ_U;

/* Define the union U_SC_SRAM_RESET_DREQ_U */
/* SRAM��λȥ������ƼĴ��� */
/* 0xA44 */
typedef union tagScSramResetDreq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_srst_dreq        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_DREQ_U;

/* Define the union U_SC_POE_RESET_REQ_U */
/* poe��λ������ƼĴ��� */
/* 0xB18 */
typedef union tagScPoeResetReq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    poe_srst_req          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_REQ_U;

/* Define the union U_SC_POE_RESET_DREQ_U */
/* poe��λȥ������ƼĴ��� */
/* 0xB1C */
typedef union tagScPoeResetDreq
{
    /* Define the struct bits */
    struct
    {
        unsigned int    poe_srst_dreq         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_DREQ_U;

/* Define the union U_SC_DISPATCH_DAW_EN_U */
/* dispatch daw en���� */
/* 0x1000 */
typedef union tagScDispatchDawEn
{
    /* Define the struct bits */
    struct
    {
        unsigned int    dispatch_daw_en       : 8   ; /* [7..0]  */
        unsigned int    reserved_0            : 24  ; /* [31..8]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_EN_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY0_U */
/* dispatch daw��������0 */
/* 0x1004 */
typedef union tagScDispatchDawArray0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array0_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array0_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array0_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array0_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY0_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY1_U */
/* dispatch daw��������1 */
/* 0x1008 */
typedef union tagScDispatchDawArray1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array1_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array1_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array1_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array1_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY1_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY2_U */
/* dispatch daw��������2 */
/* 0x100C */
typedef union tagScDispatchDawArray2
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array2_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array2_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array2_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array2_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY2_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY3_U */
/* dispatch daw��������3 */
/* 0x1010 */
typedef union tagScDispatchDawArray3
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array3_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array3_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array3_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array3_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY3_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY4_U */
/* dispatch daw��������4 */
/* 0x1014 */
typedef union tagScDispatchDawArray4
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array4_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array4_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array4_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array4_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY4_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY5_U */
/* dispatch daw��������5 */
/* 0x1018 */
typedef union tagScDispatchDawArray5
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array5_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array5_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array5_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array5_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY5_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY6_U */
/* dispatch daw��������6 */
/* 0x101C */
typedef union tagScDispatchDawArray6
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array6_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array6_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array6_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array6_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY6_U;

/* Define the union U_SC_DISPATCH_DAW_ARRAY7_U */
/* dispatch daw��������7 */
/* 0x1020 */
typedef union tagScDispatchDawArray7
{
    /* Define the struct bits */
    struct
    {
        unsigned int    daw_array7_did        : 3   ; /* [2..0]  */
        unsigned int    daw_array7_size       : 5   ; /* [7..3]  */
        unsigned int    daw_array7_sync       : 1   ; /* [8]  */
        unsigned int    reserved_0            : 4   ; /* [12..9]  */
        unsigned int    daw_array7_addr       : 19  ; /* [31..13]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_DAW_ARRAY7_U;

/* Define the union U_SC_DISPATCH_RETRY_CONTROL_U */
/* dispatch retry���ƼĴ��� */
/* 0x1030 */
typedef union tagScDispatchRetryControl
{
    /* Define the struct bits */
    struct
    {
        unsigned int    retry_num_limit       : 16  ; /* [15..0]  */
        unsigned int    retry_en              : 1   ; /* [16]  */
        unsigned int    reserved_0            : 15  ; /* [31..17]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_RETRY_CONTROL_U;

/* Define the union U_SC_DISPATCH_INTMASK_U */
/* dispatch���ж����μĴ��� */
/* 0x1100 */
typedef union tagScDispatchIntmask
{
    /* Define the struct bits */
    struct
    {
        unsigned int    intmask               : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTMASK_U;

/* Define the union U_SC_DISPATCH_RAWINT_U */
/* dispatch��ԭʼ�ж�״̬�Ĵ��� */
/* 0x1104 */
typedef union tagScDispatchRawint
{
    /* Define the struct bits */
    struct
    {
        unsigned int    rawint                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_RAWINT_U;

/* Define the union U_SC_DISPATCH_INTSTAT_U */
/* dispatch�����κ���ж�״̬�Ĵ��� */
/* 0x1108 */
typedef union tagScDispatchIntstat
{
    /* Define the struct bits */
    struct
    {
        unsigned int    intsts                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTSTAT_U;

/* Define the union U_SC_DISPATCH_INTCLR_U */
/* dispatch���ж�����Ĵ��� */
/* 0x110C */
typedef union tagScDispatchIntclr
{
    /* Define the struct bits */
    struct
    {
        unsigned int    intclr                : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_INTCLR_U;

/* Define the union U_SC_DISPATCH_ERRSTAT_U */
/* dispatch��ERR״̬�Ĵ��� */
/* 0x1110 */
typedef union tagScDispatchErrstat
{
    /* Define the struct bits */
    struct
    {
        unsigned int    err_opcode            : 5   ; /* [4..0]  */
        unsigned int    err_addr              : 17  ; /* [21..5]  */
        unsigned int    reserved_0            : 10  ; /* [31..22]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_ERRSTAT_U;

/* Define the union U_SC_DISPATCH_REMAP_CTRL_U */
/* subsys������Remap�Ĵ��� */
/* 0x1200 */
typedef union tagScDispatchRemapCtrl
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sys_remap_vld         : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_DISPATCH_REMAP_CTRL_U;

/* Define the union U_SC_SRAM_CTRL0_U */
/* sram���ƼĴ���0 */
/* 0x2030 */
typedef union tagScSramCtrl0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_ecc_en           : 1   ; /* [0]  */
        unsigned int    sram_ecc_err_trans    : 1   ; /* [1]  */
        unsigned int    sram_err_clr          : 1   ; /* [2]  */
        unsigned int    sram_err_cnt_clr      : 1   ; /* [3]  */
        unsigned int    sram_sglerr_addr_clr  : 1   ; /* [4]  */
        unsigned int    sram_mulerr_addr_clr  : 1   ; /* [5]  */
        unsigned int    sram_swap_en          : 1   ; /* [6]  */
        unsigned int    reserved_0            : 25  ; /* [31..7]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CTRL0_U;

/* Define the union U_SC_SRAM_CTRL1_U */
/* sram���ƼĴ���1����ȫ�Ĵ����� */
/* 0x2034 */
typedef union tagScSramCtrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_prot_ctrl_en     : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CTRL1_U;

/* Define the union U_SC_SMMU_MEM_CTRL1_U */
/* smmu mem���ƼĴ���1 */
/* 0x3004 */
typedef union tagScSmmuMemCtrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsel_hc_smmu          : 3   ; /* [2..0]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SMMU_MEM_CTRL1_U;

/* Define the union U_SC_SMMU_MEM_CTRL2_U */
/* smmu mem���ƼĴ���2 */
/* 0x3008 */
typedef union tagScSmmuMemCtrl2
{
    /* Define the struct bits */
    struct
    {
        unsigned int    test_hc_smmu          : 2   ; /* [1..0]  */
        unsigned int    reserved_0            : 30  ; /* [31..2]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SMMU_MEM_CTRL2_U;

/* Define the union U_SC_SRAM_MEM_CTRL_U */
/* sram mem���ƼĴ��� */
/* 0x3010 */
typedef union tagScSramMemCtrl
{
    /* Define the struct bits */
    struct
    {
        unsigned int    ctrl_rashde_sram      : 4   ; /* [3..0]  */
        unsigned int    reserved_0            : 28  ; /* [31..4]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_MEM_CTRL_U;

/* Define the union U_SC_PLLFCTRL0_U */
/* SC_PLLFCTRL0ΪCIDE_CRG��PLL0���ƼĴ���0�� */
/* 0x3014 */
typedef union tagScPllfctrl0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll0_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll0_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll0_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll0_bypass           : 1   ; /* [24]  */
        unsigned int    pll0_pd               : 1   ; /* [25]  */
        unsigned int    pll0_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll0_dacpd            : 1   ; /* [27]  */
        unsigned int    pll0_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll0_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll0_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL0_U;

/* Define the union U_SC_PLLFCTRL1_U */
/* SC_PLLFCTRL1ΪCIDE_CRG��PLL0���ƼĴ���1�� */
/* 0x3018 */
typedef union tagScPllfctrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_frac             : 26  ; /* [25..0]  */
        unsigned int    reserved_0            : 6   ; /* [31..26]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL1_U;

/* Define the union U_SC_PLLFCTRL8_U */
/* SC_PLLFCTRL8ΪCIDE_CRG��PLL4���ƼĴ���0�� */
/* 0x3034 */
typedef union tagScPllfctrl8
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll4_refdiv           : 6   ; /* [5..0]  */
        unsigned int    pll4_fbdiv            : 12  ; /* [17..6]  */
        unsigned int    pll4_postdiv1         : 3   ; /* [20..18]  */
        unsigned int    pll4_postdiv2         : 3   ; /* [23..21]  */
        unsigned int    pll4_bypass           : 1   ; /* [24]  */
        unsigned int    pll4_pd               : 1   ; /* [25]  */
        unsigned int    pll4_dsmpd            : 1   ; /* [26]  */
        unsigned int    pll4_dacpd            : 1   ; /* [27]  */
        unsigned int    pll4_fout4phasepd     : 1   ; /* [28]  */
        unsigned int    pll4_foutpostdivpd    : 1   ; /* [29]  */
        unsigned int    pll4_foutvcopd        : 1   ; /* [30]  */
        unsigned int    reserved_0            : 1   ; /* [31]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL8_U;

/* Define the union U_SC_PLLFCTRL9_U */
/* SC_PLLFCTRL9ΪCIDE_CRG��PLL4���ƼĴ���1�� */
/* 0x3038 */
typedef union tagScPllfctrl9
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll4_frac             : 24  ; /* [23..0]  */
        unsigned int    reserved_0            : 8   ; /* [31..24]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLLFCTRL9_U;

/* Define the union U_SC_PLL_CLK_BYPASS0_U */
/* SC_PLL_CLK_BYPASS0ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
/* 0x3040 */
typedef union tagScPllClkBypass0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll4_peri_mode        : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS0_U;

/* Define the union U_SC_PLL_CLK_BYPASS1_U */
/* SC_PLL_CLK_BYPASS1ΪCDIE_CRG��PLL��ع���ʱ��ѡ�� */
/* 0x3044 */
typedef union tagScPllClkBypass1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    pll0_bypass_external_n : 1   ; /* [0]  */
        unsigned int    pll1_bypass_external_n : 1   ; /* [1]  */
        unsigned int    reserved_0            : 2   ; /* [3..2]  */
        unsigned int    pll4_bypass_external_n : 1   ; /* [4]  */
        unsigned int    reserved_1            : 27  ; /* [31..5]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_CLK_BYPASS1_U;

/* Define the union U_SC_CLK_SEL_U */
/* SC_CLK_SEL��CDIE_CRG�Ĵ�������ϵͳ����ʱ��Ƶ��ѡ��Ĵ����� */
/* 0x3048 */
typedef union tagScClkSel
{
    /* Define the struct bits */
    struct
    {
        unsigned int    cpu_clk_source_sel    : 1   ; /* [0]  */
        unsigned int    reserved_0            : 7   ; /* [7..1]  */
        unsigned int    gpio_db_clk_sel       : 1   ; /* [8]  */
        unsigned int    clk_div_sel           : 1   ; /* [9]  */
        unsigned int    reserved_1            : 22  ; /* [31..10]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_CLK_SEL_U;

/* Define the union U_SC_TSMC_PLLCTRL1_U */
/* SC_TSMC_PLLCTRL1ΪCIDE��PLL1��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
/* 0x3204 */
typedef union tagScTsmcPllctrl1
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll1_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll1_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll1_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll1_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll1_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL1_U;

/* Define the union U_SC_TSMC_PLLCTRL4_U */
/* SC_TSMC_PLLCTRL4ΪCIDE CRG��PLL4��Ӧ��TSMC����PLL�Ŀ��ƼĴ����� */
/* 0x3210 */
typedef union tagScTsmcPllctrl4
{
    /* Define the struct bits */
    struct
    {
        unsigned int    tsmc_pll4_refdiv      : 5   ; /* [4..0]  */
        unsigned int    tsmc_pll4_fbdiv       : 8   ; /* [12..5]  */
        unsigned int    tsmc_pll4_pd          : 1   ; /* [13]  */
        unsigned int    tsmc_pll4_bypass      : 1   ; /* [14]  */
        unsigned int    tsmc_pll4_postdiv     : 3   ; /* [17..15]  */
        unsigned int    reserved_0            : 14  ; /* [31..18]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_TSMC_PLLCTRL4_U;

/* Define the union U_SC_PLL_SEL_U */
/* SC_PLL_SELΪCIDE�ڵ�PLLѡ����ƼĴ����� */
/* 0x3214 */
typedef union tagScPllSel
{
    /* Define the struct bits */
    struct
    {
        unsigned int    reserved_0            : 2   ; /* [1..0]  */
        unsigned int    pll_sel               : 1   ; /* [2]  */
        unsigned int    reserved_1            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_PLL_SEL_U;

/* Define the union U_SC_SRAM_CLK_ST_U */
/* SRAMʱ��״̬�Ĵ��� */
/* 0x5320 */
typedef union tagScSramClkSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_sram_st           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_CLK_ST_U;

/* Define the union U_SC_POE_CLK_ST_U */
/* POEʱ��״̬�Ĵ��� */
/* 0x5400 */
typedef union tagScPoeClkSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    clk_poe_st            : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_CLK_ST_U;

/* Define the union U_SC_SRAM_RESET_ST_U */
/* SRAM��λ״̬�Ĵ��� */
/* 0x5A20 */
typedef union tagScSramResetSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_srst_st          : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_RESET_ST_U;

/* Define the union U_SC_POE_RESET_ST_U */
/* poe��λ״̬�Ĵ��� */
/* 0x5B00 */
typedef union tagScPoeResetSt
{
    /* Define the struct bits */
    struct
    {
        unsigned int    poe_srst_st           : 1   ; /* [0]  */
        unsigned int    reserved_0            : 31  ; /* [31..1]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_POE_RESET_ST_U;

/* Define the union U_SC_SRAM_ST0_U */
/* sram״̬�Ĵ���0 */
/* 0x6000 */
typedef union tagScSramSt0
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_single_err       : 1   ; /* [0]  */
        unsigned int    sram_double_err       : 1   ; /* [1]  */
        unsigned int    sram_multi_err        : 1   ; /* [2]  */
        unsigned int    reserved_0            : 29  ; /* [31..3]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST0_U;

/* Define the union U_SC_SRAM_ST3_U */
/* sram״̬�Ĵ���3 */
/* 0x600C */
typedef union tagScSramSt3
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_count_ecc_sglerr : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST3_U;

/* Define the union U_SC_SRAM_ST4_U */
/* sram״̬�Ĵ���4 */
/* 0x6010 */
typedef union tagScSramSt4
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_count_ecc_mulerr : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST4_U;

/* Define the union U_SC_SRAM_ST5_U */
/* sram״̬�Ĵ���5 */
/* 0x6014 */
typedef union tagScSramSt5
{
    /* Define the struct bits */
    struct
    {
        unsigned int    sram_dfx_dbg          : 16  ; /* [15..0]  */
        unsigned int    reserved_0            : 16  ; /* [31..16]  */
    } bits;

    /* Define an unsigned member */
    unsigned int    u32;

} SC_SRAM_ST5_U;



#endif

#endif // __POE_SUB_REG_OFFSET_H__

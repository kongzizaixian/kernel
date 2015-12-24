/*--------------------------------------------------------------------------------------------------------------------------*/
/*!!Warning: This is a key information asset of Huawei Tech Co.,Ltd                                                         */
/*CODEMARK:kOyQZYzjDpyGdBAEC2GaWuVy7vy/wDnq7gJfHBOj2pBXFF9pJtpDLt9sw5WJiMsUkN5d7jr7
aK5J3kmlnl+vpQIjFDOn3HlYdNfd+O2Mso0Wn8OrHjkJn4/rA05FKgT2JMPJkXZ1ZyV4aAJ6
v59wfWS9Irl5dOlu4MZmf/BOy7NdrK/dZ1wdkRQMXXJEBZkw4AWKHOaVIwXDACsQKkFzOIR6
VNaS3b1UnhjWtgOHhJHerIwvYnKeCOEwOkx16Ur7aAmTqkJ92xhIAuLs5/SYsQ==*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/******************************************************************************

                  ��Ȩ���� (C), 2011-2021, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : sre_sub_peri.c
  �� �� ��   : ����
  ��    ��   : z00176027
  ��������   : 2013��10��17��
  ����޸�   :
  ��������   : P660 PERI ��λ��ȥ��λ
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��10��17��
    ��    ��   : z00176027
    �޸�����   : �����ļ�

******************************************************************************/


#include "sre_sys_ctrl.h"

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
UINT64 sub_sysctrl_base_addr = 0;
UINT64 sub_sysctrl_pa_addr = 0;

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/

 /* ����Dsaf SUB�ļĴ�����д�ӿ� */

#ifdef HRD_OS_LINUX
 inline UINT32 SYSCTRL_SUB_READ_REG(UINT32 pRegBase, UINT32 ulRegIndex)
 {
     volatile UINT32 temp;

     temp = ioread32((void __iomem *)(sub_sysctrl_base_addr + (pRegBase - PERI_SUB_BASE) + (ulRegIndex << 2)));

     return temp;
 }

#define SYSCTRL_SUB_WRITE_REG(pRegBase, ulRegIndex, ulValue) \
    (iowrite32(ulValue, (void __iomem *)(sub_sysctrl_base_addr + (pRegBase - PERI_SUB_BASE) + (ulRegIndex << 2))))

#else
#define SYSCTRL_SUB_READ_REG(pRegBase, ulRegIndex) \
                   OS_READ_REG(pRegBase, ulRegIndex)

#define SYSCTRL_SUB_WRITE_REG(pRegBase, ulRegIndex, ulValue) \
                   OS_WRITE_REG(pRegBase, ulRegIndex, ulValue)


#endif


/*****************************************************************************
 �� �� ��  : HRD_GetBaseAddrByPllId
 ��������  : ���ݴ����PLL���ȷ��sysctrl����ַ
 �������  : SRE_PLL_SEL_E ulPllSel:PLL���
 �������  : ��
 �� �� ֵ  : UINT64
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT64 HRD_GetSysCtrlAddrById(UINT32 ulSktId,SRE_PLL_SEL_E ulPllSel)
{
    UINT64 ulSubCtrlAddr;
    /* TOTEMC */
    if(ulPllSel < SRE_TOTEMA_PLL0)
    {
        /*TOTEMC PLL 2/3��������Ϣ��sysctrl��*/
        if((ulPllSel == SRE_TOTEMC_PLL2) || (ulPllSel == SRE_TOTEMC_PLL3))
            ulSubCtrlAddr = TOTEMC_SYSCTRL_BASE + ulSktId*HRD_VA_OFFSET;
        /*TOTEMC ����PLL��������Ϣ��POE_sub��*/
        else
            ulSubCtrlAddr = TOTEMC_PEOSUB_BASE + ulSktId*HRD_VA_OFFSET;
    }
    /* TOTEMA */
    else if(ulPllSel < SRE_NIMBUS_PLL0)
    {
        /*TOTEMA PLL 2/3��������Ϣ��sysctrl��*/
        if((ulPllSel == SRE_TOTEMA_PLL2) || (ulPllSel == SRE_TOTEMA_PLL3))
            ulSubCtrlAddr = TOTEMA_SYSCTRL_BASE + ulSktId*HRD_VA_OFFSET;
        /*TOTEMA ����PLL��������Ϣ��POE_sub��*/
        else
            ulSubCtrlAddr = TOTEMA_PEOSUB_BASE + ulSktId*HRD_VA_OFFSET;
    }
    /* NIMBUS */
    else
        ulSubCtrlAddr = NIMBUS_SYSCTRL_BASE + ulSktId*HRD_VA_OFFSET;
    return ulSubCtrlAddr;
}

/*****************************************************************************
 �� �� ��  : HRD_GetPllType
 ��������  : ��ȡ��ƬPLLѡ����Ϣ
 �������  : UINT64  ulSubCtrlAddr :��Ҫ��ȡ��subctrl����ַ
             SRE_PLL_SEL_E ulPllSel:Ҫ��ȡƬ���ĸ�PLL����Ϣ
 �������  : ��
 �� �� ֵ  : void
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_GetPllType(UINT64 ulSubCtrlAddr,SRE_PLL_SEL_E ulPllSel)
{
    UINT32 ulType;
    /*TOTEM��PLL�����������ͣ���Nimbus��ֻ��һ������*/
    if(ulPllSel < SRE_NIMBUS_PLL0)
    {
        if((ulPllSel%5) == SRE_TOTEMC_PLL0)
            ulType = SLICION_PLL;
        else if((ulPllSel%5) == SRE_TOTEMC_PLL1)
            ulType = TSMC_PLL;
        else
        {
            ulType = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+SYSCTRL_SC_PLL_SEL_DDR_REG-SYSCTRL_BASE,0x0);
            if((ulPllSel%5) == SRE_TOTEMC_PLL2)
                ulType = BIT_I(ulType,0);
            if((ulPllSel%5) == SRE_TOTEMC_PLL3)
                ulType = BIT_I(ulType,1);
            if((ulPllSel%5) == SRE_TOTEMC_PLL4)
                ulType = BIT_I(ulType,2);
        }
    }
    else
        ulType = SLICION_PLL;
    return ulType;
}


/*****************************************************************************
 �� �� ��  : HRD_GetPllRegOffset
 ��������  : ��ȡ��ͬ���͵�ͬһPLL�ļĴ�������ƫ�Ƶ�ַ��
 �������  : UINT32 ulPllType      :PLL����
             SRE_PLL_SEL_E ulPllSel:PLL ���
             ͬһPLL��ͬ���͵����õ�ַ��һ����
 �������  : ��
 �� �� ֵ  : ��ǰʱ��Ƶ�ʣ���MΪ��λ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_GetPllRegOffset(UINT32 ulPllType,SRE_PLL_SEL_E ulPllSel)
{
    UINT32 ulRegOffset = 0;
    /*TOTEM�и���PLL��ƫ��*/
    if(ulPllSel < SRE_NIMBUS_PLL0)
    {
        if(ulPllSel% 5 == SRE_TOTEMC_PLL0)
            ulRegOffset = POE_SUB_SC_PLLFCTRL0_REG - POE_SUB_BASE;
        if(ulPllSel% 5 == SRE_TOTEMC_PLL1)
            ulRegOffset = POE_SUB_SC_TSMC_PLLCTRL1_REG - POE_SUB_BASE;
        if(ulPllSel% 5 == SRE_TOTEMC_PLL2)
        {
            if(ulPllType == SLICION_PLL)
                ulRegOffset = SYSCTRL_SC_PLLFCTRL4_REG - SYSCTRL_BASE;
            else
                ulRegOffset = SYSCTRL_SC_TSMC_PLLCTRL2_REG - SYSCTRL_BASE;
        }
        if(ulPllSel% 5 == SRE_TOTEMC_PLL3)
        {
            if(ulPllType == SLICION_PLL)
                ulRegOffset = SYSCTRL_SC_PLLFCTRL6_REG - SYSCTRL_BASE;
            else
                ulRegOffset = SYSCTRL_SC_TSMC_PLLCTRL3_REG - SYSCTRL_BASE;
        }
        if(ulPllSel% 5 == SRE_TOTEMC_PLL4)
        {
            if(ulPllType == SLICION_PLL)
                ulRegOffset = POE_SUB_SC_PLLFCTRL8_REG - POE_SUB_BASE;
            else
                ulRegOffset = POE_SUB_SC_TSMC_PLLCTRL4_REG - POE_SUB_BASE;
        }
    }
    else
    {
        if(ulPllSel == SRE_NIMBUS_PLL0)
            ulRegOffset = ALG_SUB_SC_PLLFCTRL0_REG - ALG_SUB_BASE;
        if(ulPllSel == SRE_NIMBUS_PLL1)
            ulRegOffset = ALG_SUB_SC_PLLFCTRL2_REG - ALG_SUB_BASE;
        if(ulPllSel == SRE_NIMBUS_PLL2)
            ulRegOffset = ALG_SUB_SC_PLLFCTRL4_REG - ALG_SUB_BASE;
        if(ulPllSel == SRE_NIMBUS_PLL3)
            ulRegOffset = ALG_SUB_SC_PLLFCTRL6_REG - ALG_SUB_BASE;
        if(ulPllSel == SRE_NIMBUS_PLL4)
            ulRegOffset = ALG_SUB_SC_PLLFCTRL8_REG - ALG_SUB_BASE;
    }
    return ulRegOffset;
}


/*****************************************************************************
 �� �� ��  : HRD_GetPllFrez
 ��������  : ��ȡPLL��ʱ��Ƶ��
 �������  : UINT64  ulSubCtrlAddr :��Ҫ��ȡ��subctrl����ַ
             UINT32 ulPllType      :PLL����
             SRE_PLL_SEL_E ulPllSel:PLL ���
 �������  : ��
 �� �� ֵ  : ��ǰʱ��Ƶ�ʣ���MΪ��λ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_GetPllFrez(UINT64 ulSubCtrlAddr,UINT32 ulPllType,SRE_PLL_SEL_E ulPllSel)
{
    UINT32 i;
    UINT32 NF = 2;
    UINT32 NR = 1;
    UINT32 No = 1;
    UINT32 ulFrez;
    UINT32 ulRefDiv;
    UINT32 ulFbDiv;
    UINT32 ulPostDiv1;
    UINT32 ulRegOffset;
    SC_SlicionCrePLLTRL ulSliconCtrl;
    SC_TSMC_PLLCTRL     ulTsmcCtrl;

    ulRegOffset = HRD_GetPllRegOffset(ulPllType,ulPllSel);

    /*Silicon Creation PLL*/
    if(ulPllType == SLICION_PLL)
    {
        ulSliconCtrl.u32 = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+ulRegOffset,0x0);
        ulRefDiv     = ulSliconCtrl.bits.pll_refdiv;
        ulFbDiv      = ulSliconCtrl.bits.pll_fbdiv;
        ulPostDiv1   = ulSliconCtrl.bits.pll_postdiv1;
        ulFrez = SYS_FREF/ulRefDiv*ulFbDiv/ulPostDiv1;
    }
    else
    {
        ulTsmcCtrl.u32 = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+ulRegOffset,0x0);
        ulRefDiv    = ulTsmcCtrl.bits.tsmc_pll_refdiv;
        ulFbDiv    = ulTsmcCtrl.bits.tsmc_pll_fbdiv;
        ulPostDiv1  = ulTsmcCtrl.bits.tsmc_pll_postdiv;
        for(i=0;i<8;i++)
        {
            NF += 2*(1<<i)*BIT_I(ulFbDiv,i);
        }
        for(i=0;i<5;i++)
        {
            NR += (1<<i)*BIT_I(ulRefDiv,i);
        }
        No = 1<<ulPostDiv1;
        if(ulPostDiv1 >=4)
            No = 0x10;
        ulFrez = SYS_FREF/NR*NF/No;
    }
    return ulFrez;
}


/*****************************************************************************
 �� �� ��  : HRD_GetPllLockStatus
 ��������  : ��ȡPLL Lock��Ϣ
 �������  : UINT64  ulSubCtrlAddr :��Ҫ��ȡ��subctrl����ַ
             SRE_PLL_SEL_E ulPllSel:Ҫ��ȡƬ���ĸ�PLL����Ϣ
 �������  : ��
 �� �� ֵ  : void
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_GetPllLockStatus(UINT64 ulSubCtrlAddr,SRE_PLL_SEL_E ulPllSel)
{
    UINT32 ulLockStatus;
    /*TOTEM��PLL�����������ͣ���Nimbus��ֻ��һ������*/
    if(ulPllSel < SRE_NIMBUS_PLL0)
    {
        ulLockStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+SYSCTRL_SC_PLL_LOCK_STATUS_REG-SYSCTRL_BASE,0x0);
        ulLockStatus = BIT_I(ulSubCtrlAddr,ulPllSel%5);
    }
    else
    {
        ulLockStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+ALG_SUB_SC_PLL_LOCK_ST_REG-ALG_SUB_BASE,0x0);
        ulLockStatus = BIT_I(ulSubCtrlAddr,ulPllSel%10);
    }
    return ulLockStatus;
}

/*****************************************************************************
 �� �� ��  : HRD_GetBypassStatus
 ��������  : ��ȡʱ��bypass״̬
 �������  : UINT64  ulSubCtrlAddr :��Ҫ��ȡ��subctrl����ַ
             SRE_PLL_SEL_E ulPllSel:Ҫ��ȡƬ���ĸ�PLL����Ϣ
 �������  : ��
 �� �� ֵ  : void
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
void HRD_GetBypassStatus(UINT64 ulSubCtrlAddr,SRE_PLL_SEL_E ulPllSel)
{
    UINT32 ulBypasStatus;
    /*TOTEM�ϸ���ʱ��״̬*/
    if(ulPllSel < SRE_NIMBUS_PLL0)
    {
        if(((ulPllSel%5) == SRE_TOTEMC_PLL2) || ((ulPllSel%5) == SRE_TOTEMC_PLL3))
        {
            ulBypasStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+SYSCTRL_SC_PLL_CLK_BYPASS_DDR_REG-SYSCTRL_BASE,0x0);
            if((ulPllSel%5) == SRE_TOTEMC_PLL2)
            {
                if(BIT_I(ulBypasStatus,2) == 0x1)
                    OS_Printf("Extern Bypass:Yes.\n");
                else
                    OS_Printf("Extern Bypass:No.\n");
                if(BIT_I(ulBypasStatus,17) == 0x1)
                    OS_Printf("Peri Mode:Yes.\n");
                else
                    OS_Printf("Peri Mode:No.\n");
            }
            else
            {
                if(BIT_I(ulBypasStatus,3) == 0x1)
                    OS_Printf("Extern Bypass:Yes.\n");
                else
                    OS_Printf("Extern Bypass:No.\n");
                if(BIT_I(ulBypasStatus,18) == 0x1)
                    OS_Printf("Peri Mode:Yes.\n");
                else
                    OS_Printf("Peri Mode:No.\n");
            }
        }
        else
        {
            ulBypasStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+POE_SUB_SC_PLL_CLK_BYPASS1_REG - POE_SUB_BASE,0x0);
            if((ulPllSel%5) == SRE_TOTEMC_PLL0)
            {
                if(BIT_I(ulBypasStatus,0x0) == 0x1)
                    OS_Printf("Extern Bypass:Yes.\n");
                else
                    OS_Printf("Extern Bypass:No.\n");
            }
            if((ulPllSel%5) == SRE_TOTEMC_PLL1)
            {
                if(BIT_I(ulBypasStatus,0x1) == 0x1)
                    OS_Printf("Extern Bypass:Yes.\n");
                else
                    OS_Printf("Extern Bypass:No.\n");
            }
            if((ulPllSel%5) == SRE_TOTEMC_PLL4)
            {
                if(BIT_I(ulBypasStatus,0x4) == 0x1)
                    OS_Printf("Extern Bypass:Yes.\n");
                else
                    OS_Printf("Extern Bypass:No.\n");
            }
            ulBypasStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+POE_SUB_SC_PLL_CLK_BYPASS0_REG - POE_SUB_BASE,0x0);
            if((ulPllSel%5) == SRE_TOTEMC_PLL4)
            {
                if(ulBypasStatus == 0x1)
                    OS_Printf("Peri Mode:Yes.\n");
                else
                    OS_Printf("Peri Mode:No.\n");
            }
        }
    }
    /* Nimbus�ϸ���ʱ��״̬ */
    else
    {
        ulBypasStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+ALG_SUB_SC_PLL_CLK_BYPASS1_REG - ALG_SUB_BASE,0x0);
        if(BIT_I(ulBypasStatus,ulPllSel%10) == 0x1)
            OS_Printf("Extern Bypass:Yes.\n");
        else
            OS_Printf("Extern Bypass:No.\n");
        ulBypasStatus = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+ALG_SUB_SC_PLL_CLK_BYPASS0_REG - ALG_SUB_BASE,0x0);
        ulBypasStatus = ulBypasStatus >> 16;
        if(BIT_I(ulBypasStatus,ulPllSel%10) == 0x1)
            OS_Printf("Peri Mode:Yes.\n");
        else
            OS_Printf("Peri Mode:No.\n");
    }
}

/*****************************************************************************
 �� �� ��  : HRD_GetPllDfxInfo
 ��������  : ��ȡ��ƬPLL��Ϣ
 �������  : UINT32        ulSktId :���û�ȡ�ĸ�Ƭ�ϵ�PLL��Ϣ.0:Ƭ0��1:Ƭ1��
             SRE_PLL_SEL_E ulPllSel:Ҫ��ȡƬ���ĸ�PLL����Ϣ
             ÿ��TOTEM��5��PLL��ÿ��NIMBUS��5��PLL��
             ������0-4����TOTEMC��PLL0-4;5-9����TOTEMA PLL0-4;
             10-14����NIMBUS��PLL0-4��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
void HRD_GetPllDfxInfo(UINT32 ulSktId, SRE_PLL_SEL_E ulPllSel)
{
    UINT32 ulFrez;
    UINT32 ulPllType;
    UINT32 ulSysStatus;
    UINT32 ulLockStatus;
    UINT64 ulSubCtrlAddr;
    if(ulPllSel < SRE_NIMBUS_PLL0)
        OS_Printf("Socket%d Totem%d Pll%d:\n",ulSktId,ulPllSel/5,ulPllSel%5);
    else
        OS_Printf("Socket%d Nimbus Pll%d:\n",ulSktId,ulPllSel%10);

    ulSubCtrlAddr = HRD_GetSysCtrlAddrById(ulSktId,ulPllSel);

    /*��ȡ����PLL����*/
    ulPllType = HRD_GetPllType(ulSubCtrlAddr,ulPllSel);
    if(ulPllType == SLICION_PLL)
        OS_Printf("pllType:Silicon Creation PLL.\n");
    else
        OS_Printf("pllType:TSMC PLL.\n");

    /*��ȡ����PLLƵ��*/
    ulFrez = HRD_GetPllFrez(ulSubCtrlAddr,ulPllType,ulPllSel);
    OS_Printf("Frequency:%dM.\n",ulFrez);

    /*��ȡ����PLLʱ������״̬*/
    ulLockStatus = HRD_GetPllLockStatus(ulSubCtrlAddr,ulPllSel);
    if(ulLockStatus == 0x1)
        OS_Printf("LockStatus:Locked.\n");
    else
        OS_Printf("LockStatus:Locked.\n");

    /*��ȡ����PLLʱ��bypass״̬*/
    HRD_GetBypassStatus(ulSubCtrlAddr,ulPllSel);

    /*��ȡ��ǰCPU�õ�PLL*/
    if(((ulPllSel%5) <= SRE_TOTEMC_PLL1)&&(ulPllSel < SRE_NIMBUS_PLL0))
    {
        if(((SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+0x3048,0x0))&0x1)== 0x0)
            SRE_printf("Current CPU PLL:Pll%d.\n",0);
        else
            SRE_printf("Current CPU PLL:Pll%d.\n",1);
    }

    /*��ȡϵͳ����״̬*/
    if(ulPllSel < SRE_NIMBUS_PLL0)
    {
        if(ulPllSel < SRE_TOTEMA_PLL0 )/*Totemc��sysctrl*/
            ulSubCtrlAddr = TOTEMC_SYSCTRL_BASE + ulSktId*HRD_VA_OFFSET;
        else/*Totema��sysctrl*/
            ulSubCtrlAddr = TOTEMA_SYSCTRL_BASE + ulSktId*HRD_VA_OFFSET;

        ulSysStatus  = SYSCTRL_SUB_READ_REG(ulSubCtrlAddr+SYSCTRL_SC_SYSMODE_CTRL_REG - SYSCTRL_BASE,0x0);
        if(BIT_I(ulSysStatus,0x2) == 0x1)
            OS_Printf("SysMode:Normal.\n");
        else
            OS_Printf("SysMode:Slow.\n");

    }

}

/*****************************************************************************
 �� �� ��  : HRD_GetCurCpuFreq
 ��������  : ��ȡ��ǰCPU��Ƶ�ʣ���λΪHz
 �������  : ulSktId: socket ID, ulDieID: 0 - CDIE A, 1- CDIE C                  
 �������  : ��
 �� �� ֵ  : UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014/9/10
    ��    ��   : n00283962
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_GetCurCpuFreq(UINT32 ulSktId, UINT32 ulDieID)
{
    UINT32 ulFreq;
    UINT32 ulPllType;
    UINT64 ulSubCtrlAddr = 0;
    SRE_PLL_SEL_E ulPllSel = SRE_TOTEMC_PLL0;

    if (ulDieID == 0) 
    {
        ulSubCtrlAddr = HRD_GetSysCtrlAddrById(ulSktId, SRE_TOTEMA_PLL0);        
    }
    else if (ulDieID == 1)
    {
        ulSubCtrlAddr = HRD_GetSysCtrlAddrById(ulSktId, SRE_TOTEMC_PLL0);
    }
    
    /*��ȡ��ǰCPU�õ�PLL*/
    if (((SYSCTRL_SUB_READ_REG(ulSubCtrlAddr + 0x3048, 0x0)) & 0x1) == 0x0)
    {
        if (ulDieID == 0)
        {
            ulPllSel = SRE_TOTEMA_PLL0;            
        }
        else if (ulDieID == 1)
        {
            ulPllSel = SRE_TOTEMC_PLL0; 
        }
    }
    else
    { 
        if (ulDieID == 0)
        {
            ulPllSel = SRE_TOTEMA_PLL1;            
        }
        else if (ulDieID == 1)
        {
            ulPllSel = SRE_TOTEMC_PLL1; 
        }
    }

    ulSubCtrlAddr = HRD_GetSysCtrlAddrById(ulSktId, ulPllSel);
    /*��ȡ����PLL����*/
    ulPllType = HRD_GetPllType(ulSubCtrlAddr, ulPllSel);

    /*��ȡ����PLLƵ��*/
    ulFreq = HRD_GetPllFrez(ulSubCtrlAddr, ulPllType, ulPllSel);
    ulFreq *= 1000000;
    return ulFreq;

}

/*****************************************************************************
 �� �� ��  : HRD_SysCtrl_Link
 ��������  : ����app_link�е��ã����ⱻ�Ż�
 �������  :
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��6��26��
    ��    ��   : g00220740
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_SysCtrl_Link()
{
    return 0;
}
#ifdef HRD_OS_LINUX
EXPORT_SYMBOL(HRD_GetPllDfxInfo);
#endif


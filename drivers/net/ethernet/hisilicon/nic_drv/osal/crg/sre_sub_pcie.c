/*--------------------------------------------------------------------------------------------------------------------------*/
/*!!Warning: This is a key information asset of Huawei Tech Co.,Ltd                                                         */
/*CODEMARK:kOyQZYzjDpyGdBAEC2GaWuVy7vy/wDnq7gJfHBOj2pBXFF9pJtpDLt9sw5WJiMsUkN5d7jr7
aK5J3kmlnl+vpQIjFDOn3HlYdNfd+O2Mso0Wn8OrHjkJn4/rA05FKgT2JMPJkXZ1ZyV4aAJ6
v59wfW4xh9+AoobWjbe8OM0uIPaHJV/Yzj+mufBLqE6uQ5LI8YuNNIzu6ZB8jOk0H+yM0bhr
Lq0HC/lvpES6LFe6piN8ImxNVdjtbvUrVY0IFauqET5It4xE7+KbAAQfaCfxeA==*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/******************************************************************************

                  ��Ȩ���� (C), 2011-2021, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : sre_sub_pcie.c
  �� �� ��   : ����
  ��    ��   : z00176027
  ��������   : 2013��10��17��
  ����޸�   :
  ��������   : P660 sas��ϵͳ ��λ��ȥ��λ
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��10��17��
    ��    ��   : z00176027
    �޸�����   : �����ļ�

******************************************************************************/

#include "sre_sub_pcie.h"


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
UINT64 sub_pcie_base_addr = 0;
UINT64 sub_pcie_pa_addr = 0;

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
 inline UINT32 PCIE_SUB_READ_REG(UINT32 pRegBase, UINT32 ulRegIndex)
 {
     volatile UINT32 temp;

     temp = ioread32((void __iomem *)(sub_pcie_base_addr + (pRegBase - PCIE_SUB_BASE) + (ulRegIndex << 2)));

     return temp;
 }

#define PCIE_SUB_WRITE_REG(pRegBase, ulRegIndex, ulValue) \
    (iowrite32(ulValue, (void __iomem *)(sub_pcie_base_addr + (pRegBase - PCIE_SUB_BASE) + (ulRegIndex << 2))))

#else
#define PCIE_SUB_READ_REG(pRegBase, ulRegIndex) \
               OS_READ_REG(pRegBase, ulRegIndex)

#define PCIE_SUB_WRITE_REG(pRegBase, ulRegIndex, ulValue) \
               OS_WRITE_REG(pRegBase, ulRegIndex, ulValue)

#endif


/*****************************************************************************
�� �� ��  : HRD_Pcie_PcieSrst
��������  : Pcie��λ���⸴λ
�������  : UINT32 ulChannel
            UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��26��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_PcieSrst(UINT32 ulChannel, UINT32 ulEn)
{
    SC_PCIE0_RESET_REQ_U o_sc_pcie_reset_req;
    SC_PCIE0_RESET_DREQ_U o_sc_pcie_reset_dreq;

    if(ulChannel >= PV660_PCIE_NUM)
    {
        return OS_FAIL;
    }

    memset(&o_sc_pcie_reset_req,0,sizeof(SC_PCIE0_RESET_REQ_U));
    memset(&o_sc_pcie_reset_dreq,0,sizeof(SC_PCIE0_RESET_DREQ_U));

    if(0 == ulEn)
    {
        o_sc_pcie_reset_req.bits.pcie0_srst_req = 1;
        if((PV660_PCIE_NUM - 1) == ulChannel)
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_PCIE3_RESET_REQ_REG),0,o_sc_pcie_reset_req.u32);
        }
        else
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_PCIE0_RESET_REQ_REG + (ulChannel << 3)),0,o_sc_pcie_reset_req.u32);
        }

    }
    else
    {
        o_sc_pcie_reset_dreq.bits.pcie0_srst_dreq = 1;
        if((PV660_PCIE_NUM - 1) == ulChannel)
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_PCIE3_RESET_DREQ_REG),0,o_sc_pcie_reset_req.u32);
        }
        else
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_PCIE0_RESET_DREQ_REG + (ulChannel << 3)),0,o_sc_pcie_reset_dreq.u32);
        }

    }

    return OS_SUCCESS;
}

/*****************************************************************************
�� �� ��  : HRD_Pcie_SasSrst
��������  : Pcie Sas��λ���⸴λ
�������  : UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��26��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_SasSrst(UINT32 ulEn)
{
    SC_SAS_RESET_REQ_U o_sc_sas_reset_req;
    SC_SAS_RESET_DREQ_U o_sc_sas_reset_dreq;

    memset(&o_sc_sas_reset_req,0,sizeof(SC_SAS_RESET_REQ_U));
    memset(&o_sc_sas_reset_dreq,0,sizeof(SC_SAS_RESET_DREQ_U));

    if(0 == ulEn)
    {
        o_sc_sas_reset_req.u32 |= 0x7ffff;
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_SAS_RESET_REQ_REG,0,o_sc_sas_reset_req.u32);

    }
    else
    {
        o_sc_sas_reset_dreq.u32 |= 0x7ffff;
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_SAS_RESET_DREQ_REG,0,o_sc_sas_reset_dreq.u32);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
�� �� ��  : HRD_Pcie_MctpSrst
��������  : Mctp��λ���⸴λ
�������  : UINT32 ulChannel
            UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��26��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_MctpSrst(UINT32 ulChannel, UINT32 ulEn)
{
    SC_MCTP0_RESET_REQ_U o_sc_mctp_reset_req;
    SC_MCTP0_RESET_DREQ_U o_sc_mctp_reset_dreq;

    if(ulChannel >= PV660_PCIE_NUM)
    {
        return OS_FAIL;
    }

    memset(&o_sc_mctp_reset_req,0,sizeof(SC_MCTP0_RESET_REQ_U));
    memset(&o_sc_mctp_reset_dreq,0,sizeof(SC_MCTP0_RESET_DREQ_U));

    if(0 == ulEn)
    {
        o_sc_mctp_reset_req.bits.mctp0_srst_req = 1;
        if((PV660_PCIE_NUM - 1) == ulChannel)
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_MCTP3_RESET_REQ_REG),0,o_sc_mctp_reset_req.u32);
        }
        else
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_MCTP0_RESET_REQ_REG + (ulChannel << 3)),0,o_sc_mctp_reset_req.u32);
        }

    }
    else
    {
        o_sc_mctp_reset_dreq.bits.mctp0_srst_dreq = 1;
        if((PV660_PCIE_NUM - 1) == ulChannel)
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_MCTP3_RESET_DREQ_REG),0,o_sc_mctp_reset_req.u32);
        }
        else
        {
            PCIE_SUB_WRITE_REG((PCIE_SUB_SC_MCTP0_RESET_DREQ_REG + (ulChannel << 3)),0,o_sc_mctp_reset_dreq.u32);
        }

    }

    return OS_SUCCESS;
}


/*****************************************************************************
�� �� ��  : HRD_Pcie_SllcSrstByChannel
��������  : Pcie sllc��λ���⸴λ
�������  : UINT32 ulChannel  ulChannel
            UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��26��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_SllcTsvRxSrstByChannel(UINT32 ulChannel,UINT32 ulEn)
{
    SC_SLLC_TSVRX_RESET_REQ_U o_sc_sllc_tsvrx_reset_req;
    SC_SLLC_TSVRX_RESET_DREQ_U o_sc_sllc_tsvrx_reset_dreq;

    if(ulChannel >= PV660_PCIE_SLLC_NUM)
    {
        return OS_FAIL;
    }

    memset(&o_sc_sllc_tsvrx_reset_req,0,sizeof(SC_SLLC_TSVRX_RESET_REQ_U));
    memset(&o_sc_sllc_tsvrx_reset_dreq,0,sizeof(SC_SLLC_TSVRX_RESET_DREQ_U));


    if(0 == ulEn)
    {
        o_sc_sllc_tsvrx_reset_req.u32 |= (1 << ulChannel);
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_SLLC_TSVRX_RESET_REQ_REG,0,o_sc_sllc_tsvrx_reset_req.u32);
    }
    else
    {
        o_sc_sllc_tsvrx_reset_dreq.u32 |= (1 << ulChannel);
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_SLLC_TSVRX_RESET_DREQ_REG,0,o_sc_sllc_tsvrx_reset_dreq.u32);
    }

    return OS_SUCCESS;
}


/*****************************************************************************
�� �� ��  : HRD_Pcie_HilinkSrstByLane
��������  : PCIE Hilink pcs��λ���⸴λ
�������  : UINT32 ulTimer  Timer
            UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��22��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_HilinkSrstByLane(UINT32 ulPcie, UINT32 ulLane, UINT32 ulEn)
{
    SC_PCIE_HILINK_PCS_RESET_REQ_U o_sc_hilink_pcs_reset_req;
    SC_PCIE_HILINK_PCS_RESET_DREQ_U o_sc_hilink_pcs_reset_dreq;

    memset(&o_sc_hilink_pcs_reset_req,0,sizeof(SC_PCIE_HILINK_PCS_RESET_REQ_U));
    memset(&o_sc_hilink_pcs_reset_dreq,0,sizeof(SC_PCIE_HILINK_PCS_RESET_DREQ_U));

    if(ulPcie >= (PV660_PCIE_NUM - 1))
    {
        return OS_FAIL;
    }

    if(ulLane >= PV660_PCS_LANE_NUM)
    {
        return OS_FAIL;
    }


    if(0 == ulEn)
    {
        o_sc_hilink_pcs_reset_req.u32 |= ((ulPcie << PV660_PCS_LANE_NUM) | (1 << ulLane));
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_PCIE_HILINK_PCS_RESET_REQ_REG,0,o_sc_hilink_pcs_reset_req.u32);
    }
    else
    {
        o_sc_hilink_pcs_reset_dreq.u32 |= ((ulPcie << PV660_PCS_LANE_NUM) | (1 << ulLane));
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_PCIE_HILINK_PCS_RESET_DREQ_REG,0,o_sc_hilink_pcs_reset_dreq.u32);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
�� �� ��  : HRD_Pcie_Sllc0Srst
��������  : Sllc0��λ���⸴λ
�������  : UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��25��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_Sllc0Srst(UINT32 ulEn)
{
    SC_SLLC_RESET_REQ_U o_sc_sllc_reset_req;
    SC_SLLC_RESET_DREQ_U o_sc_sllc_reset_dreq;

    memset(&o_sc_sllc_reset_req,0,sizeof(SC_SLLC_RESET_REQ_U));
    memset(&o_sc_sllc_reset_dreq,0,sizeof(SC_SLLC_RESET_DREQ_U));

    if(0 == ulEn)
    {
         o_sc_sllc_reset_req.bits.sllc_srst_req = 1;
         PCIE_SUB_WRITE_REG(PCIE_SUB_SC_SLLC_RESET_REQ_REG,0,o_sc_sllc_reset_req.u32);
    }
    else
    {
        o_sc_sllc_reset_dreq.bits.sllc_srst_dreq = 1;
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_SLLC_RESET_DREQ_REG,0,o_sc_sllc_reset_dreq.u32);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
�� �� ��  : HRD_Pcie_PcsLocalSrst
��������  : Pca Local��λ���⸴λ
�������  : UINT32 ulEn  0:��λ >=1:ȥ��λ
            UINT32 ulChannel:����⸴λ�ĸ�pcs.
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��25��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_PcsLocalSrstByChannel(UINT32 ulEn,UINT32 ulChannel)
{
    SC_PCS_LOCAL_RESET_REQ_U o_sc_pcs_local_reset_req;
    SC_PCS_LOCAL_RESET_DREQ_U o_sc_pcs_local_reset_dreq;

    memset(&o_sc_pcs_local_reset_req,0,sizeof(SC_PCS_LOCAL_RESET_REQ_U));
    memset(&o_sc_pcs_local_reset_dreq,0,sizeof(SC_PCS_LOCAL_RESET_DREQ_U));

    if(0 == ulEn)
    {
         o_sc_pcs_local_reset_req.u32 |=  0x1<<ulChannel;
         PCIE_SUB_WRITE_REG(PCIE_SUB_SC_PCS_LOCAL_RESET_REQ_REG,0,o_sc_pcs_local_reset_req.u32);
    }
    else
    {
        o_sc_pcs_local_reset_dreq.u32 |=  0x1<<ulChannel;
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_PCS_LOCAL_RESET_DREQ_REG,0,o_sc_pcs_local_reset_dreq.u32);
    }

    return OS_SUCCESS;
}


/*****************************************************************************
�� �� ��  : HRD_Pcie_ItsSrst
��������  : Its��λ���⸴λ
�������  : UINT32 ulEn  0:��λ >=1:ȥ��λ
�������  : ��
�� �� ֵ  :
���ú���  :
��������  :

�޸���ʷ      :
 1.��    ��   : 2013��10��25��
   ��    ��   : z00176027
   �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Pcie_ItsSrst(UINT32 ulEn)
{
    SC_ITS_RESET_REQ_U o_sc_its_reset_req;
    SC_ITS_RESET_DREQ_U o_sc_its_reset_dreq;

    memset(&o_sc_its_reset_req,0,sizeof(SC_ITS_RESET_REQ_U));
    memset(&o_sc_its_reset_dreq,0,sizeof(SC_ITS_RESET_DREQ_U));

    if(0 == ulEn)
    {
         o_sc_its_reset_req.bits.its_srst_req = 1;
         PCIE_SUB_WRITE_REG(PCIE_SUB_SC_ITS_RESET_REQ_REG,0,o_sc_its_reset_req.u32);
    }
    else
    {
        o_sc_its_reset_dreq.bits.its_srst_dreq = 1;
        PCIE_SUB_WRITE_REG(PCIE_SUB_SC_ITS_RESET_DREQ_REG,0,o_sc_its_reset_dreq.u32);
    }

    return OS_SUCCESS;
}

#ifdef HRD_OS_LINUX
/*****************************************************************************
 �� �� ��  : HRD_SubPcieInit
 ��������  : SUB PCIE CRG linux��ʼ��
 �������  : void
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��11��21��
    ��    ��   : z00176027
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_SubPcieInit(void)
{
    sub_pcie_pa_addr = PCIE_SUB_BASE;

    /* SUB ALG����io�ڴ� */
    if (!request_mem_region(sub_pcie_pa_addr, PCIE_SUB_BASE_SIZE, "SUB PCIE Reg"))
    {
        printk("SUB PCIE region busy\n");
        return OS_ERROR;
    }

    sub_pcie_base_addr = (UINT64)ioremap(sub_pcie_pa_addr, PCIE_SUB_BASE_SIZE);
    if (!sub_pcie_base_addr)
    {
        release_mem_region(sub_pcie_pa_addr, PCIE_SUB_BASE_SIZE);
        printk("could not ioremap SUB PCIE registers\n");

        return OS_ERROR;
    }

    return OS_SUCCESS;
}


/*****************************************************************************
 �� �� ��  : HRD_SubPcieExit
 ��������  : SUB PCIE CRG �˳�
 �������  : void
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��11��21��
    ��    ��   : z00176027
    �޸�����   : �����ɺ���

*****************************************************************************/
void HRD_SubPcieExit(void)
{
    /* �ͷ�POU��Դ */
    if (sub_pcie_base_addr > 0)
    {
        release_mem_region(sub_pcie_pa_addr, PCIE_SUB_BASE_SIZE);
        iounmap((void *)sub_pcie_base_addr);
    }
}


UINT64 HRD_SubPcieGetBase(void)
{
	return sub_pcie_base_addr;
}
EXPORT_SYMBOL(HRD_Pcie_HilinkSrstByLane);
EXPORT_SYMBOL(HRD_Pcie_SllcTsvRxSrstByChannel);
EXPORT_SYMBOL(HRD_Pcie_ItsSrst);
EXPORT_SYMBOL(HRD_Pcie_PcieSrst);
EXPORT_SYMBOL(HRD_Pcie_MctpSrst);
EXPORT_SYMBOL(HRD_Pcie_Sllc0Srst);
EXPORT_SYMBOL(HRD_Pcie_PcsLocalSrstByChannel);
EXPORT_SYMBOL(HRD_SubPcieGetBase);


#endif




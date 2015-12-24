/*--------------------------------------------------------------------------------------------------------------------------*/
/*!!Warning: This is a key information asset of Huawei Tech Co.,Ltd                                                         */
/*CODEMARK:kOyQZYzjDpyGdBAEC2GaWuVy7vy/wDnq7gJfHBOj2pBXFF9pJtpDLt9sw5WJiMsUkN5d7jr7
aK5J3kmlnl+vpQIjFDOn3HlYdNfd+O2Mso0Wn8OrHjkJn4/rA05FKgT2JMPJkXZ1ZyV4aAJ6
v59wfTU8sjoWxiS1/cgWX5CtFNa63k6Yc/3U44KeRvBDtKMGylcadZp63N7vuf8lP2xr4S9J
nCHJXblfnpl3Puz4wNQtlnvTNeUQknlm2fbSwoA4WFagChI2aokTHVZI71ZSeg==*/
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
#include "sre_sub_poe.h"

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
UINT64 sub_poe_base_addr = 0;
UINT64 sub_poe_pa_addr = 0;

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
 inline UINT32 POE_SUB_READ_REG(UINT32 pRegBase, UINT32 ulRegIndex)
 {
     volatile UINT32 temp;

     temp = ioread32((void __iomem *)(sub_poe_base_addr + (pRegBase - PERI_SUB_BASE) + (ulRegIndex << 2)));

     return temp;
 }

#define POE_SUB_WRITE_REG(pRegBase, ulRegIndex, ulValue) \
    (iowrite32(ulValue, (void __iomem *)(sub_poe_base_addr + (pRegBase - PERI_SUB_BASE) + (ulRegIndex << 2))))

#else
#define POE_SUB_READ_REG(pRegBase, ulRegIndex) \
                   OS_READ_REG(pRegBase, ulRegIndex)

#define POE_SUB_WRITE_REG(pRegBase, ulRegIndex, ulValue) \
                   OS_WRITE_REG(pRegBase, ulRegIndex, ulValue)


#endif



/*****************************************************************************
 �� �� ��  : HRD_Poe_SramSrst
 ��������  : SRAM ��λ���⸴λ
 �������  : UINT32 ulEn  0:��λ >=1:ȥ��λ
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��22��
    ��    ��   : z00176027
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Poe_SramSrst(UINT32 ulEn)
{
    SC_SRAM_RESET_REQ_U o_sc_sram_reset_req;
    SC_SRAM_RESET_DREQ_U o_sc_sram_reset_dreq;


    memset(&o_sc_sram_reset_req,0,sizeof(SC_SRAM_RESET_REQ_U));
    memset(&o_sc_sram_reset_dreq,0,sizeof(SC_SRAM_RESET_DREQ_U));

    if(0 == ulEn)
    {
        o_sc_sram_reset_req.bits.sram_srst_req = 0x1;
        POE_SUB_WRITE_REG(POE_SUB_SC_SRAM_RESET_REQ_REG,0,o_sc_sram_reset_req.u32);
    }
    else
    {
         o_sc_sram_reset_dreq.bits.sram_srst_dreq = 0x1;
         POE_SUB_WRITE_REG(POE_SUB_SC_SRAM_RESET_DREQ_REG,0,o_sc_sram_reset_dreq.u32);
    }

    return OS_SUCCESS;
}


/*****************************************************************************
 �� �� ��  : HRD_Poe_PoeSrst
 ��������  : POE ��λ���⸴λ
 �������  : UINT32 ulEn  0:��λ >=1:ȥ��λ
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��22��
    ��    ��   : z00176027
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 HRD_Poe_PoeSrst(UINT32 ulEn)
{
    SC_POE_RESET_REQ_U o_sc_poe_reset_req;
    SC_POE_RESET_DREQ_U o_sc_poe_reset_dreq;


    memset(&o_sc_poe_reset_req,0,sizeof(SC_POE_RESET_REQ_U));
    memset(&o_sc_poe_reset_dreq,0,sizeof(SC_POE_RESET_DREQ_U));

    if(0 == ulEn)
    {
        o_sc_poe_reset_req.bits.poe_srst_req = 0x1;
        POE_SUB_WRITE_REG(POE_SUB_SC_POE_RESET_REQ_REG,0,o_sc_poe_reset_req.u32);
    }
    else
    {
         o_sc_poe_reset_dreq.bits.poe_srst_dreq = 0x1;
         POE_SUB_WRITE_REG(POE_SUB_SC_POE_RESET_DREQ_REG,0,o_sc_poe_reset_dreq.u32);
    }

    return OS_SUCCESS;
}

#ifdef HRD_OS_LINUX

EXPORT_SYMBOL(HRD_Poe_SramSrst);
EXPORT_SYMBOL(HRD_Poe_PoeSrst);
#endif



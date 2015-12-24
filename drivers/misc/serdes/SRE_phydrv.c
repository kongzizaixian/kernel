/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : SRE_phydrv.c
  �� �� ��   : ����
  ��    ��   : w00146306
  ��������   : 2010��10��27��
  ����޸�   :
  ��������   : SRE PHY����ģ��
  �����б�   :
              SRE_InitPhy
  �޸���ʷ   :
  1.��    ��   : 2010��10��27��
    ��    ��   : w00146306
    �޸�����   : �����ļ�

******************************************************************************/

/* ͷ�ļ����� ----------------------------------*/
#include "SRE_phydrv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define OS_MDIO_ID_0      0x1
#define OS_MDIO_ID_1      0x1
#ifndef OS_MDIO_ID
#define OS_MDIO_ID        OS_MDIO_ID_1
#endif

#if 0
/*****************************************************************************
 �� �� ��  : MDIO_Hi1381_Write
 ��������  : MDIOд��������PHY�Ĵ���дֵ
 �������  : UINT32 ulMdioPort
             UINT32 ulPhyAddr
             UINT32 ulRegAddr
             UINT32 ulValue
 �������  : ��
 �� �� ֵ  : UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��5��
    ��    ��   : g00198889
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 MDIO_Hi1381_Write(UINT32 ulMdioPort, UINT32 ulPhyAddr, UINT32 ulRegAddr, UINT32 ulValue)
{
    SRE_MDIO_CMD_REG_U      unMdioCmdReg;
    MDIO_WDATA_REG_U        unMdioWDataReg;

    UINT32                  ulTimeCnt     = 1000;
    UINT32                   uwRet          = OS_FAIL;

    if (ulMdioPort > 2)
    {
        SRE_printf("Wrong mdio port: ulMdioPort(%x)\n", ulMdioPort);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (ulPhyAddr > MDIO_MAX_PHY_ADDR)
    {
        SRE_printf("Wrong phy address\n");
        return uwRet;
    }

    if (ulRegAddr > MDIO_MAX_PHY_REG_ADDR)
    {
        SRE_printf("Wrong reg address\n");
        return uwRet;
    }
/*SRE_printf("%s %d; "" LeoGao mdio0 Here ! \n", __FUNCTION__, __LINE__);  */

    /* Step 1; ���ж�MDIO_COMMAND_REG��mdio_startλ�Ƿ�Ϊ0����Ϊֻ��Ϊ0��ʱ�򣬲ſ��Խ��ж�д����  */
    MDIO_REG_READ(ulMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);

    while (unMdioCmdReg.bits.Mdio_Start)     /* ��ʾ��ʱ���ڽ���MDIO���ʣ���Ҫ�ȴ�50us  */
    {
        SRE_DelayCycle(1000);
        //MC_PhyDelayUs(1000);        /* ��ʱ50us,  650 FPGA�¸�ʱ�䲻����������������˶�ʮ������ʱ      */
        ulTimeCnt--;
        MDIO_REG_READ(ulMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
        if (0 == ulTimeCnt)         /* ��ʾ�Ѿ���ʱ����ʱӦ�ñ���  */
        {
            SRE_printf(" Timeout! MDIO is always busy! MDIO_COMMAND_REG(0x%x) \n", unMdioCmdReg.u32);
            return uwRet;
        }
    }
/*SRE_printf("%s %d; "" LeoGao mdio1 Here ! \n", __FUNCTION__, __LINE__);  */

    /* Step 2; ����Ҫд���ֵ��д��д�������ݼĴ���  */
    MDIO_REG_READ(ulMdioPort, MDIO_WDATA_REG, unMdioWDataReg.u32);
    unMdioWDataReg.bits.Mdio_Wdata = ulValue;
    //SRE_printf("%s %d; "" LeoGao mdio2 Here; ulValue = 0x%x ! \n", __FUNCTION__, __LINE__, ulValue);
    MDIO_REG_WRITE(ulMdioPort, MDIO_WDATA_REG, unMdioWDataReg.u32);
    //SRE_printf("%s %d; "" LeoGao mdio3 Here ! \n", __FUNCTION__, __LINE__);

    /* Step 3; ����д��������  */
    unMdioCmdReg.bits.Mdio_St    = MDIO_ST_CLAUSE_22;       /* ���õ�ǰ��mdioΪclause22  */
    unMdioCmdReg.bits.Mdio_Op    = MDIO_CLAUSE_22_WRITE;    /* ���õ�ǰ�Ĳ���Ϊд����  */
    unMdioCmdReg.bits.Mdio_Prtad = (UINT16)ulPhyAddr;        /* ��mdio_stΪ2��b01ʱ����ʾҪ���ʵ��ⲿ��PHY��ַ  */
    unMdioCmdReg.bits.Mdio_Devad = ulRegAddr;                /* ��mdio_stΪ2��b01ʱ����ʾҪ���ʵ��ⲿPHY�ļĴ�����ַ  */
    unMdioCmdReg.bits.Mdio_Start = 1;                       /* ��������  */
/*SRE_printf("%s %d; "" LeoGao mdio4 Here ! \n", __FUNCTION__, __LINE__);  */
    MDIO_REG_WRITE(ulMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
/*SRE_printf("%s %d; "" LeoGao mdio5 Here ! \n", __FUNCTION__, __LINE__);  */

    return OS_SUCCESS;
}

UINT32 SRE_PhyWriteReg(UINT32 ulMdioPort, UINT32 ulPhyAddr, UINT32 ulRegPage, UINT32 ulRegAddr, UINT32 ulValue)
{
    if((ulRegPage > 28) || (ulRegPage == 22))
    {
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    MDIO_Hi1381_Write(ulMdioPort, ulPhyAddr, 22, ulRegPage);
    MDIO_Hi1381_Write(ulMdioPort, ulPhyAddr, ulRegAddr, ulValue);

    return OS_SUCCESS;
}


UINT32 SRE_PhyTestWrite(UINT32 ulRegPage, UINT32 ulRegAddr, UINT32 ulValue)
{
    UINT32 ulMdioPort = 0;
    UINT32 ulPhyAddr = 0;

    SRE_PhyWriteReg(ulMdioPort, ulPhyAddr, ulRegPage, ulRegAddr, ulValue);

    return OS_SUCCESS;
}


UINT32 SRE_GeFpgaAdapt(UINT32 uwPort)
{
        SRE_SetPortMode(uwPort, GMAC_100M_SGMII);

        SRE_PhyTestWrite(18, 20, 1);
        SRE_PhyTestWrite(18, 20, 0x8001);

        SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, 0x60);

        return OS_SUCCESS;
}
#endif

UINT32 SRE_PhyDelayUs(UINT32 uwTime);
extern UINT32 SRE_MdioRead(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 *puwRegValue);
extern UINT32 SRE_MdioWrite(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 uwWriteValue);
extern UINT32 MAR1512_PHY_Reset (UINT32 uwPhy);
extern UINT32 MAR1512_PHY_SelfTest(UINT32 uwPhy);

UINT32 MAR1512_SelectPage(UINT32 uwPort, UINT32 uwPhyAddr, UINT32 uwPage)
{
    UINT32 uwRet;

    if ((uwPage > 28) || (uwPage == MII_PAGE_ADDR_REG))
    {
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = SRE_MdioWrite(uwPort, uwPhyAddr, MII_PAGE_ADDR_REG, uwPage);
    if (uwRet != OS_SUCCESS)
    {
        return uwRet;
    }

    return OS_SUCCESS;
}

UINT32 MAR1512_Write(UINT32 uwRegAddr, UINT32 uwPage, UINT32 uwVal)
{
    UINT32 uwPort    = 0;
    UINT32 uwPhyAddr = 0;
    UINT32 uwRet;

    uwRet = MAR1512_SelectPage(uwPort, uwPhyAddr, uwPage);
    if (uwRet != OS_SUCCESS)
    {
        return uwRet;
    }

    uwRet = SRE_MdioWrite(uwPort, uwPhyAddr, uwRegAddr, uwVal);
    if (uwRet != OS_SUCCESS)
    {
        return uwRet;
    }

    return OS_SUCCESS;
}

UINT32 MAR1512_Read(UINT32 uwRegAddr, UINT32 uwPage, UINT32 *puwVal)
{
    UINT32 uwPort    = 0;
    UINT32 uwPhyAddr = 0;
    UINT32 uwRet;

    uwRet = MAR1512_SelectPage(uwPort, uwPhyAddr, uwPage);
    if (uwRet != OS_SUCCESS)
    {
        return uwRet;
    }

    uwRet = SRE_MdioRead(uwPort, uwPhyAddr, uwRegAddr, puwVal);
    if (uwRet != OS_SUCCESS)
    {
        return uwRet;
    }

    return OS_SUCCESS;
}

UINT32 MAR1512_Dump(UINT32 uwPage, UINT32 uwRegAddr)
{
    UINT32 uwVal;
    UINT32 uwRet;

    uwRet = MAR1512_Read(uwPage, uwRegAddr, &uwVal);
    if (uwRet != OS_SUCCESS)
    {
        return uwRet;
    }

    SRE_printf("PAGE %#x REG %#x VALUE %#x\n", uwPage, uwRegAddr, uwVal);

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_Init
 Description  : Initial the phy module
 Input        : UINT32 uwPhy
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/18
    Author       : l100057
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_Init(UINT32 uwPhy )
{
    //UINT32 uwRegValue = 0;
    //UINT32 uwRet;
//    if (0 == g_ulMarPhyInitFlag)
//    {
//        if (0 == (g_ulMarPhyMutex = semMCreate(SEM_Q_FIFO | SEM_DELETE_SAFE)))
//        {
//            SRE_PHY_ERROR( "Error initilizing Phy Mutex!\n");
//            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
//        }
//    }
//
//    g_ulMarPhyInitFlag = 1;

    if (OS_SUCCESS != MAR1512_PHY_Reset(uwPhy))
    {
        SRE_PHY_ERROR( "MAR1512_PHY_Init:Error reset Phy!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
	printk("MAR1512_PHY_Init uwphy : %d\n", uwPhy);

    if (OS_SUCCESS != MAR1512_PHY_SelfTest(uwPhy))
    {
        SRE_PHY_ERROR("MAR1512_PHY_Init:Error selftest Phy!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
#if 0
    uwRet = MAR1512_ReadPhyReg(uwPhy, 21, 2,&uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("MAR1512_PHY_Init:Error MAR1512_ReadPhyReg!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    uwRegValue |= 1<<5;
    uwRet = MAR1512_WritePhyReg(uwPhy,21, 2,uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("MAR1512_PHY_Init:Error MAR1512_WritePhyReg!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
#endif
    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_WritePhyReg
 Description  : д�Ĵ���
 Input        : UINT32 uwPhy
                UINT16 usRegAddr
                UINT8 ucWindow
                UINT32 ulFlag
                UINT16 usWrData
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/17
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_ReadPhyReg( UINT32 uwPhy, UINT32 uwReg, UINT32 uwPage, UINT32 *puwValue)
{
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

//    if (OS_SUCCESS != semTake(g_ulMarPhyMutex, WAIT_FOREVER))    /**/
//    {
//        SRE_PHY_ERROR("MAR1512_WritePhyReg: semTake ERROR!\n");
//        goto erro_exit;
//    }


    if (OS_SUCCESS != SRE_MdioWrite(OS_MDIO_ID, uwPhy, MII_PAGE_ADDR_REG, uwPage&0xFF))
    {
        SRE_PHY_ERROR("[MAR_PHY_WRITE]phy_write() called return is fail at %x\n",uwReg);
        goto erro_exit;
    }

   //printk("dingtianhong test param :%d,%d,%d,%p\n ", uwPhy, uwReg, uwPage, puwValue);

    if (OS_SUCCESS != SRE_MdioRead(OS_MDIO_ID, uwPhy, uwReg & 0x1F, puwValue))
    {
        SRE_PHY_ERROR("[MAR_PHY_WRITE]phy_read() called return is fail at %x\n",uwReg);
        goto erro_exit;
    }

//    semGive(g_ulMarPhyMutex);

    return OS_SUCCESS;

erro_exit:
//    semGive(g_ulMarPhyMutex);

    RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
}

/*****************************************************************************
 Prototype    : MAR1512_WritePhyReg
 Description  : д�Ĵ���
 Input        : UINT32 uwPhy
                UINT16 usRegAddr
                UINT8 ucWindow
                UINT32 ulFlag
                UINT16 usWrData
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/17
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_WritePhyReg( UINT32 uwPhy, UINT32 uwReg, UINT32 uwPage, UINT32 uwValue)
{

    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

//    if (OS_SUCCESS != semTake(g_ulMarPhyMutex, WAIT_FOREVER))    /**/
//    {
//        SRE_PHY_ERROR("MAR1512_WritePhyReg: semTake ERROR!\n");
//        goto erro_exit;
//    }


    if (OS_SUCCESS != SRE_MdioWrite(OS_MDIO_ID, uwPhy, MII_PAGE_ADDR_REG, uwPage&0xFF))
    {
        SRE_PHY_ERROR("[MAR_PHY_WRITE]phy_write() called return is fail at %x\n",MII_PAGE_ADDR_REG);
        goto erro_exit;
    }

    if (OS_SUCCESS != SRE_MdioWrite(OS_MDIO_ID, uwPhy, uwReg & 0x1F, uwValue))
    {
        SRE_PHY_ERROR("[MAR_PHY_WRITE]phy_write() called return is fail at %x\n",uwReg);
        goto erro_exit;
    }

//    semGive(g_ulMarPhyMutex);
    return OS_SUCCESS;

erro_exit:
//    semGive(g_ulMarPhyMutex);

    RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
}

/*****************************************************************************
 �� �� ��  : MAR1512_PHY_MAR5464_InterfaceSet
 ��������  : ����MAR1512 �ӿ�ģʽ
 �������  : UINT32 uwPhy
             MAR_PHY_INTERFACE_ENUM uwMode
 �������  : ��
 �� �� ֵ  : UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2007��10��9��
    ��    ��   : �޽��� 100057
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 MAR1512_PHY_InterfaceSet( UINT32 uwPhy, MAR_PHY_INTERFACE_ENUM uwMode )
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;

    switch (uwMode)
    {
        case SGMII_COPPER :
            uwRet = MAR1512_ReadPhyReg(uwPhy,20, 18,&uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~0x7;
            uwRegValue |= 0x1;
            uwRegValue |= 1<<15;
            uwRet = MAR1512_WritePhyReg(uwPhy,20, 18,uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            break;
        case RGMII_COPPER :
            uwRet = MAR1512_ReadPhyReg(uwPhy,20, 18,&uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~0x7;
            uwRegValue |= (UINT32)uwMode & 7;
            uwRet = MAR1512_WritePhyReg(uwPhy,20, 18,uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            break;
        default:
            SRE_PHY_ERROR("interfacemode is error\n");
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_GetPhyid
 Description  : Get the chip's phyid
 Input        : UINT32 uwPhy
 Output       : None
 Return Value : PHYID (UINT32)
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/10
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_GetPhyid (UINT32 uwPhy ,UINT32 *puwId)
{
    UINT32 uwIdLow = 0;
    UINT32 uwIdHigh = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_PHY_ID0_REG, 0, &uwIdHigh);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_PHY_ID1_REG, 0, &uwIdLow);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    *puwId = ((uwIdHigh << 16) | uwIdLow);
    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_GetChipVersion
 Description  : Get the version of the phy chip
 Input        : UINT32 uwPhy
                UINT32 *puwChipVersion
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/10
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_GetChipVersion(UINT32 uwPhy,UINT32 *puwChipVersion)
{
    UINT32 uwId;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwChipVersion)
    {
        SRE_PHY_ERROR("NULL point\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_PHY_GetPhyid(uwPhy,&uwId);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 get phy id error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }


    *puwChipVersion = uwId & 0xF;

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_Reset
 Description  : phy reset function
 Input        : UINT32 uwPhy
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/10
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_Reset (UINT32 uwPhy)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg (uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRegValue |= 1<<15;/*��λ*/
    uwRet = MAR1512_WritePhyReg (uwPhy, MII_CTRL_REG, 0, uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* ��ʱ����1ms, �ȴ�MII Control Register resetλ��Ϊ0 */
    //SRE_DelayMs(2);
    SRE_PhyDelayUs(3000);

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_SelfTest
 Description  : selftest for phy chip
 Input        : UINT32 uwPhy
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/10
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_SelfTest(UINT32 uwPhy)
{
    UINT32 uwRet;
    UINT32 uwId;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    printk("mdio addr is :%x, len is %x",MDIO_BASE_ADDR, MDIO_REG_ADDR_LEN);
    uwRet = MAR1512_PHY_GetPhyid(uwPhy, &uwId);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("fail to read phy id\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    printk("uwid is %x\n", uwId);

    if (MARVELL1512_ID != (uwId & 0xFFFFFF0))
    {
        SRE_PHY_ERROR("Phy id 0x%08x unmatch\n",uwId);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
	

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_SetAutoNeg
 Description  : set auto negotiation,100FX do not have autonegotiation.
 Input        : UINT32 uwPhy
                UINT32 uwMaxspeed
                UINT32 uwEnable
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/11
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_SetAutoNeg (UINT32 uwPhy, UINT32 uwMaxspeed, UINT32 uwEnable)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;

    if (uwPhy > MAR_PHY_MAX_ADDR)
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (uwEnable > 1)
    {
        SRE_PHY_ERROR("Enable value is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (uwMaxspeed > PHY_SPEED_1000M)
    {
        SRE_PHY_ERROR("uwMaxspeed %d value is error\n",uwMaxspeed);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    uwRegValue &= ~(1<<12);
    uwRegValue |= (uwEnable<<12);
    uwRet = MAR1512_WritePhyReg(uwPhy, MII_CTRL_REG, 0, uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (1 == uwEnable)
    {
        if (PHY_SPEED_1000M == uwMaxspeed)
        {
            /*set 10&100M*/
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_ANA_REG, 0, &uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue |= ( MII_ANA_FD_10 | MII_ANA_FD_100 | MII_ANA_PAUSE | MII_ANA_ASYM_PAUSE);
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_ANA_REG, 0, uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            /*set 1000M*/
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_GB_CTRL_REG, 0, &uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue |= MII_GB_CTRL_ADV_1000FD;
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_GB_CTRL_REG, 0, uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
        }
        else if (PHY_SPEED_100M == uwMaxspeed)
        {
            /*set 10&100M*/
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_ANA_REG, 0, &uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue |= ( MII_ANA_FD_10 | MII_ANA_FD_100 | MII_ANA_PAUSE | MII_ANA_ASYM_PAUSE);
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_ANA_REG, 0,  uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }

            /*set no 1000M*/
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_GB_CTRL_REG, 0, &uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~MII_GB_CTRL_ADV_1000FD;
            uwRegValue &= ~MII_GB_CTRL_ADV_1000HD;
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_GB_CTRL_REG, 0, uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
        }
        else if (PHY_SPEED_10M == uwMaxspeed)
        {
            /*set no 1000M*/
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_GB_CTRL_REG, 0, &uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~MII_GB_CTRL_ADV_1000FD;
            uwRegValue &= ~MII_GB_CTRL_ADV_1000HD;
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_GB_CTRL_REG, 0, uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            /*set no 100M ,set  10M*/
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_ANA_REG, 0, &uwRegValue);
            uwRegValue &= ~MII_ANA_HD_100;
            uwRegValue &= ~MII_ANA_FD_100;
            /*set  10M*/
            uwRegValue |= ( MII_ANA_FD_10 | MII_ANA_PAUSE | MII_ANA_ASYM_PAUSE);
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_ANA_REG, 0, uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
        }

        /*������Э��*/
        uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        uwRegValue |= (1 << 9);
        uwRet = MAR1512_WritePhyReg(uwPhy, MII_CTRL_REG, 0, uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_GetAutoNeg
 Description  : Get the autoneg mode and maxspeed
 Input        : UINT32 uwPhy
                UINT32 *puwMaxspeed  10(10M),100(100M),1000(1000M).
                UINT32 *puwEnable    enable 1,disable 0.
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/11
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_GetAutoNeg (UINT32 uwPhy,UINT32 *puwMaxspeed, UINT32 *puwEnable)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwMaxspeed)
    {
        SRE_PHY_ERROR("NULL point of puwMaxspeed\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwEnable)
    {
        SRE_PHY_ERROR("NULL point of puwEnable\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    *puwEnable = (uwRegValue >> 12) & 0x1;


    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_GB_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (uwRegValue & MII_GB_CTRL_ADV_1000FD)
    {
        *puwMaxspeed = PHY_SPEED_1000M;
    }
    else
    {
        uwRet = MAR1512_ReadPhyReg(uwPhy, MII_ANA_REG, 0, &uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }

        if (uwRegValue & MII_ANA_FD_100)
        {
            *puwMaxspeed = PHY_SPEED_100M;
        }
        else if (uwRegValue & MII_ANA_FD_10)
        {
            *puwMaxspeed = PHY_SPEED_10M;
        }
        else
        {
            SRE_PHY_ERROR("unknown phy negtiation\n");
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_SetSpeed
 Description  : set the speed of lineinterface
 Input        : UINT32 uwPhy
                UINT32 ulSpeed  10(10M),100(100M),1000(1000M).
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/11
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_SetSpeed (UINT32 uwPhy, UINT32 ulSpeed)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    switch (ulSpeed)
    {
        case PHY_SPEED_10M:
            uwRegValue &= ~MII_CTRL_SS_LSB;
            uwRegValue &= ~MII_CTRL_SS_MSB;
            break;
        case PHY_SPEED_100M :
            uwRegValue |= MII_CTRL_SS_LSB;
            uwRegValue &= ~MII_CTRL_SS_MSB;
            break;
        case PHY_SPEED_1000M :
            uwRegValue |= MII_CTRL_SS_MSB;
            uwRegValue &= ~MII_CTRL_SS_LSB;
            break;
        default:
            SRE_PHY_ERROR("mode error\n");
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_WritePhyReg(uwPhy, MII_CTRL_REG, 0, uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_PHY_Reset(uwPhy);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 reset error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_GetSpeed
 Description  : get the speed configuration
 Input        : UINT32 uwPhy
                UINT32 *puwSpeed
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/11
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_GetSpeed (UINT32 uwPhy, UINT32 *puwSpeed)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwSpeed)
    {
        SRE_PHY_ERROR("NULL point\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    uwRegValue = (uwRegValue >> 13) & 0x1;
    uwRegValue |= (uwRegValue >> 5) & 0x2;
    switch (uwRegValue)
    {
        case 0 :
            *puwSpeed = PHY_SPEED_10M;
            break;
        case 1 :
            *puwSpeed = PHY_SPEED_100M;
            break;
        case 2 :
            *puwSpeed = PHY_SPEED_1000M;
            break;
        default:
            SRE_PHY_ERROR("error speed mode\n");
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_SetDuplex
 Description  : set the lineinterface duplex
 Input        : UINT32 uwPhy
                UINT32 uwEnable
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/11
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_SetDuplex (UINT32 uwPhy,UINT32 uwEnable)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (uwEnable > 1)
    {
        SRE_PHY_ERROR("uwEnable is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    uwRegValue &= ~(1<<8);
    uwRegValue |= uwEnable<<8;

    uwRet = MAR1512_WritePhyReg(uwPhy,MII_CTRL_REG, 0, uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_PHY_Reset(uwPhy);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 reset error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_GetDuplex
 Description  : get the configration of the duplex
 Input        : UINT32 uwPhy
                UINT32 *puwEnable  enable 1,disable 0.
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/11
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_GetDuplex (UINT32 uwPhy,UINT32 *puwEnable)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;
    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwEnable)
    {
        SRE_PHY_ERROR("null point!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    *puwEnable = (uwRegValue >> 8) & 0x1;

    return OS_SUCCESS;
}
/*****************************************************************************
 Prototype    : MAR1512_PHY_QrySpeed
 Description  :
 Input        : None
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/9/4
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32  MAR1512_PHY_QrySpeed( UINT32 uwPhy,UINT32 *puwSpeed,UINT32 *puwDuplex)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;

    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwSpeed)
    {
        SRE_PHY_ERROR("null pointer!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }


    uwRet = MAR1512_ReadPhyReg(uwPhy,MII_COPPER_SPEC_STATUS_1, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    //if (0 == (uwRegValue & (1<<11)))
    //{
    //    RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    //}

    *puwSpeed = (uwRegValue >> 14) & 0x3;
    *puwDuplex = (uwRegValue >> 13) & 0x1;

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_QryLinkStatus
 Description  :
 Input        : None
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/9/4
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32  MAR1512_PHY_QryLinkStatus( UINT32 uwPhy,UINT32 *puwStatus)
{
    UINT32 uwRegValue = 0;
    UINT32 uwRet;

    if ( uwPhy > MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == puwStatus)
    {
        SRE_PHY_ERROR("null pointer!\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }


    uwRet = MAR1512_ReadPhyReg(uwPhy, MII_COPPER_SPEC_STATUS_1, 0, &uwRegValue);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    *puwStatus = (uwRegValue & 1<<10)>>10;

    return OS_SUCCESS;
}

UINT32 MAR1512_PHY_Show(UINT32 uwPhy)
{
    UINT32 uwId;
    UINT32 uwChipVersion;
    UINT32 uwMaxspeed;
    UINT32 uwEnable;
    UINT32 uwSpeed;
    UINT32 uwDuplex;
    UINT32 uwLinkStatus;

    UINT32 uwRet;
    UINT32 uwMdioId;

    uwMdioId = OS_MDIO_ID;

    SRE_printf(" ==== mdio %d phy %d ==== \n",uwMdioId,uwPhy);

    SRE_printf(" ==== chip info ==== \n");
    uwRet = MAR1512_PHY_GetPhyid (uwPhy ,&uwId);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 GetPhyid error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    SRE_printf("chip id = 0x%x\n",uwId);

    uwRet = MAR1512_PHY_GetChipVersion (uwPhy ,&uwChipVersion);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 GetChipVersion error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    SRE_printf("chip version = 0x%x\n",uwChipVersion);

    SRE_printf(" ==== AutoNeg ==== \n");
    uwRet = MAR1512_PHY_GetAutoNeg (uwPhy ,&uwMaxspeed, &uwEnable);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 GetAutoNeg error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    SRE_printf("uwMaxspeed = 0x%x\n",uwMaxspeed);
    SRE_printf("AutoNeg enable = 0x%x\n",uwEnable);

    SRE_printf(" ==== currunt speed &duplex ==== \n");
    uwRet = MAR1512_PHY_QrySpeed (uwPhy ,&uwSpeed, &uwDuplex);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 QrySpeed error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    SRE_printf("speed = 0x%x\n",uwSpeed);
    SRE_printf("uwDuplex = 0x%x\n",uwDuplex);

    SRE_printf(" ==== uwLinkStatus  ==== \n");
    uwRet = MAR1512_PHY_QryLinkStatus (uwPhy ,&uwLinkStatus);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR("[%s %d]:MAR1512 QryLinkStatus error!\n",__FUNCTION__, __LINE__);
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    SRE_printf("uwLinkStatus = 0x%x\n",uwLinkStatus);
    SRE_printf("======================\n");
    return OS_SUCCESS;
}

UINT32 gaulPageReg[40];

UINT32 MAR1512_PHY_PAGE_DUMP(void)
{
    UINT32 uwPhy =0;
    UINT32 uwRet;
    UINT32 uwPage = 0;
    UINT32 uwTimeOut = 10000;
    UINT32 uwLinkStatus;

    UINT32 uwRegIndex = 0;

    while((uwTimeOut > 0)&&(uwRegIndex<=26))
    {
        uwRet = MAR1512_PHY_QryLinkStatus (uwPhy ,&uwLinkStatus);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR("[%s %d]:MAR1512 QryLinkStatus error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        if(0 == uwLinkStatus)
        {
            MAR1512_ReadPhyReg(0,uwRegIndex,uwPage,&gaulPageReg[uwRegIndex]);
            uwRegIndex++;
        }
        uwTimeOut--;
    }

    SRE_printf("uwRegIndexd =%d\n",uwRegIndex);
    SRE_printf("uwTimeOut =%d\n",uwTimeOut);

    return OS_SUCCESS;
}
UINT32 MAR1512_PHY_PAGE_CLEAN(void)
{
    UINT32 i;
    for(i = 0;i<30;i++)
    {
        gaulPageReg[i] = 0;
    }
    return OS_SUCCESS;
}
UINT32 MAR1512_PHY_PAGE_SHOW(void)
{
    UINT32 i;
    for(i = 0;i<30;i++)
    {
        SRE_printf("reg %d = 0x%x\n",i,gaulPageReg[i]);
    }
    return OS_SUCCESS;
}
UINT32 MAR1512_PHY_PAGE_SHOW_NULL(void)
{
    //UINT32 i;
    return OS_SUCCESS;
}


#if 0
/*****************************************************************************
 Prototype    : MAR1512_PHY_SetLoop
 Description  : set loopmode ,linkside and macside
                    In the 1000baseX link side loopmode the auto-negotiation must be off
 Input        : UINT32 uwPhy
                UINT32 uwMode
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/16
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_SetLoop (UINT32 uwPhy,PHY_LOOP_E uwMode)
{
    UINT32 uwRegValue = 0;
    UINT32 ulLink = 0;
    UINT32 uwRet;
    UINT32 ulSpeed = 0;
    UINT32 ulDuplex = 0;
    PHY_LOOP_E enLoopState = PHY_LOOP_MODE_OFF;
    if (uwPhy >= PHY_MAX_ADDR)
    {
        SRE_PHY_ERROR("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (uwMode > PHY_LOOP_MODE_LINE)
    {
        SRE_PHY_ERROR("uwMode is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    uwRet = MAR1512_PHY_GetLoop(uwPhy, &enLoopState);
    if (OS_SUCCESS != uwRet)
    {
        SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 get loop error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
    if (PHY_LOOP_MODE_OFF == enLoopState)
    {
        if (PHY_LOOP_MODE_OFF == uwMode)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_INFO, \
                    "[%s %d]:MAR1512 loop already off!\n",__FUNCTION__, __LINE__);
            return OS_SUCCESS;
        }
    }
    else
    {
        if (PHY_LOOP_MODE_OFF != uwMode)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_INFO, \
                    "[%s %d]:MAR1512 already in loop  %d!\n",__FUNCTION__, __LINE__,(UINT32)enLoopState,0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }
    if (PHY_LOOP_MODE_OFF == uwMode)
    {
        if (PHY_LOOP_MODE_LINE == enLoopState)
        {
            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_MAC_SPEC_CTRL_2, 2,&uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~(1<<14);/*�ر� LINE LOOP*/
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_MAC_SPEC_CTRL_2, 2,uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
        }
        else/*PHY_LOOP_MODE_SYS*/
        {

            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0,&uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~(1<<14); /*�ر� SYS LOOP*/
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_CTRL_REG, 0,uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }

            uwRet = MAR1512_ReadPhyReg(uwPhy, MII_COPPER_SPEC_CTRL_1, 0,&uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRegValue &= ~(1<<10); /*�ر�ǿ��LINK UP*/
            uwRet = MAR1512_WritePhyReg(uwPhy, MII_COPPER_SPEC_CTRL_1, 0,uwRegValue);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwRet = MAR1512_PHY_GetAutoNeg(uwPhy, &g_ulMarPhyAutoNegSpeedBeforeLoop[uwPhy], &g_ulMarPhyAutoNegStateBeforeLoop[uwPhy]);
            if (OS_SUCCESS != uwRet)
            {
                SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                    "[%s %d]:MAR1512 get auto neg error!\n",__FUNCTION__, __LINE__);
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
        }
    }
    else if (PHY_LOOP_MODE_LINE == uwMode)
    {
        uwRet = MAR1512_PHY_QryLinkStatus(uwPhy, &ulLink);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 QryLinkStatus error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }

        if (PHY_LINK_UP != ulLink)
        {
            SRE_PHY_ERROR("ERROR to set line loop,link is down!\n");
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        uwRet = MAR1512_ReadPhyReg(uwPhy, MII_MAC_SPEC_CTRL_2, 2, &uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        uwRegValue |= (1<<14);/*LINE LOOP*/
        uwRet = MAR1512_WritePhyReg(uwPhy, MII_MAC_SPEC_CTRL_2, 2, uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR(TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }
    else /*PHY_LOOP_MODE_SYS*/
    {
        uwRet = MAR1512_PHY_GetAutoNeg(uwPhy, &g_ulMarPhyAutoNegSpeedBeforeLoop[uwPhy], &g_ulMarPhyAutoNegStateBeforeLoop[uwPhy]);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 get auto neg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }

        /*��ȡ��ǰ�ٶ�*/
        uwRet = MAR1512_PHY_QrySpeed(uwPhy, &ulSpeed, &ulDuplex);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 qry speed error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        /*�ر���Э��*/
        uwRet = MAR1512_PHY_SetAutoNeg(uwPhy, ulSpeed, 0);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 set auto neg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }

        /*�����ٶ�*/
        uwRet = MAR1512_PHY_SetSpeed(uwPhy, ulSpeed);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 set speed error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }

        /*����ȫ˫��*/
        uwRet = MAR1512_PHY_SetDuplex(uwPhy, PHY_DUPLEX_FULL);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 set duplex error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }


        uwRet = MAR1512_ReadPhyReg(uwPhy, MII_COPPER_SPEC_CTRL_1, 0,&uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        uwRegValue |= (1<<10); /*ǿ��LINK UP*/
        uwRet = MAR1512_WritePhyReg(uwPhy, MII_COPPER_SPEC_CTRL_1, 0,uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }

        uwRet = MAR1512_ReadPhyReg(uwPhy, MII_CTRL_REG, 0,&uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 read reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
        uwRegValue |= (1<<14);/*SYS LOOP*/
        uwRet = MAR1512_WritePhyReg(uwPhy, MII_CTRL_REG, 0,uwRegValue);
        if (OS_SUCCESS != uwRet)
        {
            SRE_PHY_ERROR (TRANDRV_ETH_CODEBASE, g_lFeModuId, OUTPUT_LEVEL_ERROR, \
                "[%s %d]:MAR1512 write reg error!\n",__FUNCTION__, __LINE__);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 Prototype    : MAR1512_PHY_GetLoop
 Description  : get loopback mode
 Input        : UINT32 uwPhy
                UINT32 *puwMode
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2007/7/16
    Author       : T56444
    Modification : Created function

*****************************************************************************/
UINT32 MAR1512_PHY_GetLoop (UINT32 uwPhy,PHY_LOOP_E *pulLoop)
{
    if ( uwPhy >= MAR_PHY_MAX_ADDR )
    {
        SRE_PHY_ERROR ("uwPhy is error\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if (NULL == pulLoop)
    {
        SRE_PHY_ERROR ("puwMode is NULL\n");
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    *pulLoop = (PHY_LOOP_E)g_ulMarPhyLoopState[uwPhy];
    return OS_SUCCESS;
}
#endif

UINT32 SRE_StdPhySet(UINT32 uwPort)
{
    UINT32 uwRet;
    UINT32 uwPhy  = uwPort;

    //wuyin �ľ���ͨ����������fpga �� 1000m link up
    //SreShell 0 "MAR1512_PHY_Init 0"
    //SreShell 0 "MAR1512_PHY_InterfaceSet 0,0"
    //SreShell 0 "MAR1512_Write 21,2,0x5076"

    /* ����PHY */
    uwRet = MAR1512_PHY_Init(uwPhy);
    if (uwRet !=  OS_SUCCESS)
    {
        SRE_PHY_ERROR("MAR1512_PHY_Init fail\n");
        RETURN_ERROR(__LINE__, uwRet, 0, 0);
    }

    uwRet = MAR1512_PHY_InterfaceSet(uwPhy, SGMII_COPPER);
    if (uwRet !=  OS_SUCCESS)
    {
        SRE_PHY_ERROR("MAR1512_PHY_InterfaceSet fail\n");
        RETURN_ERROR(__LINE__, uwRet, 0, 0);
    }

    uwRet = MAR1512_PHY_SetAutoNeg(uwPhy, PHY_SPEED_1000M, PHY_AUTONEG_ENABLE);
    if (uwRet !=  OS_SUCCESS)
    {
        SRE_PHY_ERROR("MAR1512_PHY_SetAutoNeg fail\n");
        RETURN_ERROR(__LINE__, uwRet, 0, 0);
    }

    return OS_SUCCESS;
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif


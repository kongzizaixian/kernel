/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : hrd_mod_common_api.h
  �� �� ��   : ����
  ��    ��   : z00200342
  ��������   : 2013��4��11��
  ����޸�   :
  ��������   : ��������
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��11��
    ��    ��   : z00200342
    �޸�����   : �����ļ�
  2.��    ��   : 2013��11��22��
    ��    ��   : l00176160
    �޸�����   : DTS2013112208956
******************************************************************************/

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


#ifndef _MCSS_MOD_COMMON_API_H_
#define _MCSS_MOD_COMMON_API_H_


#define MCSS_DEVS_NUM 3              /**< Ĭ��3���豸     */
#define MCSS_MAX_INSTANCE_NUM   3    /**< Ĭ��3�� ����    */
#define MCSS_NAME "mcss"              /**< mcss�豸����     */
#define MC_MOD_VERSION "iware V100R005C00B106"      /**< MCSS KO�汾��   */
#define MC_CACHE_LINE_SIZE 64UL



/* begin add by z00200342 2013/4/10: ��׼SRE���ݽṹ&�ӿڶ��� */
#define MCSS_EACH_MODULE_MAX_CMD_NUM  100   /* ÿ��ģ�����ɶ����������� */
typedef enum /* �����ģ�������ֵķ�Χ���˶��幩SRE��׼�ӿ�ʹ�� */
{
    MCSS_CMD_BMU_START = 100,                          /**<  BMUģ����������ʼ��Χ   */
    MCSS_CMD_BMU_END   = MCSS_CMD_BMU_START + 100,     /**<  BMUģ����������ֹ��Χ   */
    MCSS_CMD_POE_START,                                /**<  POEģ����������ʼ��Χ 201  */
    MCSS_CMD_POE_END   = MCSS_CMD_POE_START + 100,     /**<  POEģ����������ֹ��Χ   */
    MCSS_CMD_PPE_START,                                /**<  PPEģ����������ʼ��Χ 302  */
    MCSS_CMD_PPE_END   = MCSS_CMD_PPE_START + 100,     /**<  PPEģ����������ֹ��Χ   */
    MCSS_CMD_TM_START,                                 /**<  TMģ����������ʼ��Χ 403  */
    MCSS_CMD_TM_END   = MCSS_CMD_TM_START + 100,       /**<  TMģ����������ֹ��Χ   */
    MCSS_CMD_ETH_START,                                /**<  ETHģ����������ʼ��Χ 504  */
    MCSS_CMD_ETH_END   = MCSS_CMD_ETH_START + 100,     /**<  ETHģ����������ֹ��Χ   */
    MCSS_CMD_SRIO_START,                               /**<  SRIOģ����������ʼ��Χ 605  */
    MCSS_CMD_SRIO_END   = MCSS_CMD_SRIO_START + 100,   /**<  SRIOģ����������ֹ��Χ   */
    MCSS_CMD_SEC_START,                                /**<  SECģ����������ʼ��Χ 706  */
    MCSS_CMD_SEC_END   = MCSS_CMD_SEC_START + 100,     /**<  SECģ����������ֹ��Χ   */
    MCSS_CMD_FABRIC_START,                                /**<  FABRICģ����������ʼ��Χ 807  */
    MCSS_CMD_FABRIC_END   = MCSS_CMD_FABRIC_START + 100,     /**<  FABRICģ����������ֹ��Χ   */
    MCSS_CMD_SERDES_START,                                /**<  SERDESģ����������ʼ��Χ 908  */
    MCSS_CMD_SERDES_END   = MCSS_CMD_SERDES_START + 100,      /**<  SERDESģ����������ֹ��Χ   */
    MCSS_CMD_BPSS_START,                                       /**<  BPSSģ����������ʼ��Χ 1009    */
    MCSS_CMD_BPSS_END   = MCSS_CMD_BPSS_START + 100,           /**<  BPSSģ����������ֹ��Χ   */
    MCSS_CMD_DMA_START,                                        /**<  DMAģ����������ʼ��Χ  1110  */
    MCSS_CMD_DMA_END   = MCSS_CMD_DMA_START + 100              /**<  DMAģ����������ֹ��Χ   */
} MCSS_CMD_MODULE_DEF_ENUM;

/* end add by z00200342 2013/4/10: ��׼SRE���ݽṹ&�ӿڶ��� */

/* P650�������� */
#define  MC_BOARD_TYPE_UBBP_Y  0      /**< ҵ����֤��  */
#define  MC_BOARD_TYPE_UBBP_T  1      /**< t ��   */
#define  MC_BOARD_TYPE_UBBP_V  2      /**< v ��   */

#define  MC_BOARD_TYPE MC_BOARD_TYPE_UBBP_T   /**< T�岻��ʼ��PHY/MDIO  */

#endif  /* _MCSS_MOD_COMMON_API_H_ */





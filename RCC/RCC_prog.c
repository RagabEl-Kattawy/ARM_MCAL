/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : RCC IMPLEMENTATION    [RCC_Prog.c]         */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/

/************************ Includes **************************/
#include "RCC_int.h"

/************************ Defines ***************************/

/*********************** Typedefs ***************************/

/******************* Global Interfaces **********************/


/*********************** Functions **************************/


Error_t RCC_ErrorPLLConfig(RCC_PLLMul_t RCC_PLLMul_cpy,RCC_ClkSrc_t RCC_ClkSrc_cpy)
{
    switch(RCC_PLLMul_cpy)
    {
        case PLL_NONE:
        switch(RCC_ClkSrc_cpy)
        {
            case RCC_HSI:
            break;

            case RCC_HSE:
            break;
        }
        //configure register
        break;

        default:
        // assert pll mul
        // set hsi
        // wait for HSI
        // disable pll
        // configure pll
        switch(RCC_ClkSrc_cpy)
        {
            case RCC_HSI_2:
            break;

            case RCC_HSE_PYP:

            case RCC_HSE:

            break;

            case RCC_HSE_PYP_2:


            case RCC_HSE_2:

            break;
        }
    }
}
Error_t RCC_ErrorSetHSE()
{

}

Error_t RCC_ErrorSetHSI()
{

}


Error_t RCC_ErrorSetPeripheralAHB()
{

}
Error_t RCC_ErrorSetPeripheralAPB1()
{

}
Error_t RCC_ErrorSetPeripheralAPB2()
{

}


/************************** APIs ****************************/

Error_t RCC_ErrorSetSystemClock(RCC_SysClkCfg_t* RCC_SysClkCfg_ptr); // set default configuration in caso of NULL
{
    //assert parameters
    switch(RCC_SysClkCfg_ptr->)
  /* configure PLL */

}
Error_t RCC_ErrorEnablePeripheral(RCC_Bus_t RCC_Bus_cpy, uint_8 Prepheral_cpy);
{
  /* select bus */
  /* call appropriate */
}

Error_t RCC_ErrorDisablePeripheral(RCC_Bus_t RCC_Bus_cpy, uint_8 Prepheral_cpy);
{
  /* select bus */
  /* call appropriate */
}
Error_t RCC_ErrorSetBusPrescaler(RCC_BusConfig_t* RCC_BusConfig_ptr);//set default configuration in caso of NULL
{
  /* select bus */
  /* call appropriate */
}
Error_t RCC_ErrorEnableInterrupt(RCC_Int_t RCC_Int_cpy)
{

}
Error_t RCC_ErrorDisableInterrupt(RCC_Int_t RCC_Int_t)
{

}
Error_t RCC_ErrorClearFlag(RCC_Int_t RCC_Int_cpy)
{

}
uint_8  RCC_uint_8ReadFlag(RCC_Int_t RCC_Int_cpy)
{

}
Error_t RCC_ErrorSetClockOut(RCC_CLKOUT_t)
{

}
RCC_CLKOUT_t  RCC_RCC_CLKOUT_tGetClockOut(void)
{

}

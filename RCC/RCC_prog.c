/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : RCC IMPLEMENTATION    [RCC_Prog.c]         */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/

/************************ Includes **************************/
#include "RCC_int.h"
#include "RCC_priv.h"

/************************ Defines ***************************/
#define ASSERT_PLL(mul) (((mul==PLL_MUL_2)||(mul==PLL_MUL_3)||(mul==PLL_MUL_4)||\
                         (mul==PLL_MUL_5)||(mul==PLL_MUL_6)||(mul==PLL_MUL_7)||\
                         (mul==PLL_MUL_8)||(mul==PLL_MUL_9)||(mul==PLL_MUL_10)||\
                         (mul==PLL_MUL_11)||(mul==PLL_MUL_12)||(mul==PLL_MUL_13)\
                         (mul==PLL_MUL_14)||(mul==PLL_MUL_15)||(mul==PLL_MUL_16))?\
                         (void)0:return NOK)

#define AHB_PRE_CHECK 0x08
#define APB_PRE_CHECK 0x04
#define MCO_CHECK 0x04
#define RCC_IE_OFFSET 0x08
#define RCC_IC_OFFSET 0x1F

/*********************** Typedefs ***************************/

/******************* Global Interfaces **********************/


/*********************** Functions **************************/
/************************************************************/
/*  Func       : RCC_ErrorEnableHSE
/*	Parameters : void
/*	Return     : Error_t
/*  Description: Enable High speed external clock
/************************************************************/
Error_t RCC_ErrorEnableHSE(void)
{
    /* set HSEON */
    PR_BAND(RCC->CR,HSEON) = (uint_32) ON;
    /* wait for ready flag */
    while(!GET_BIT(RCC->CR,HSERDY));
    return OK;
}

/************************************************************/
/*  Func       : RCC_ErrorEnableHSI
/*	Parameters : void
/*	Return     : Error_t
/*  Description: Enable High speed internal clock & set it as
/*               System clock.
/************************************************************/
Error_t RCC_ErrorEnableHSI(void)
{
    /* SET HSION */
    PR_BAND(RCC->CR,HSION) = (uint_32) ON;
    /* wait for ready flag */
    while(!GET_BIT(RCC->CR,HSIRDY));
    /* connect clock (MASK & SET)*/
    MASK_WORD(RCC->CFGR,SW_MASK,SW_2);
    SET_MASKED(RCC->CFGR,RCC_HSI,SW_2);
    return OK;
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorPLLConfig(RCC_PLLMul_t RCC_PLLMul_cpy,RCC_ClkSrc_t RCC_ClkSrc_cpy)
{
    Error_t ReturnVal = OK;
    /* PLL VALIDATION */
    switch(RCC_PLLMul_cpy)
    {
        /* NO PLL required */
        case PLL_NONE:
        /* Check chosen clock */
        switch(RCC_ClkSrc_cpy)
        {
            /* HSI chosen */
            case RCC_HSI:
            /* SET HSION */
            ReturnVal = RCC_ErrorEnableHSI();
            /* return acknowldge*/
            retrun ReturnVal;
            break;

            /* HSE chosen */
            case RCC_HSE:
            /* SET HSION */
            ReturnVal = RCC_ErrorEnableHSE();
            /* connect clock */
            MASK_WORD(RCC->CFGR,SW_MASK,SW_2);
            SET_MASKED(RCC->CFGR,RCC_HSE&1,SW_2);
            /* return acknowldge*/
            retrun ReturnVal;
            break;

            default :
            return NOK;
        }
        break;

        /* PLL required */
        default:
        /* assert pll mul */
        ASSERT_PLL(RCC_PLLMul_cpy);
        /* set hsi */
        ReturnVal = RCC_ErrorEnableHSI();
        /* disable pll */
        PR_BAND(RCC->CR,PLLON) = (uint_32) OFF;
        /*/ configure pll mul */
        MASK_WORD(RCC->CFGR,PLLMUL_MASK,PLLMUL_4);
        SET_MASKED(RCC->CFGR,RCC_PLLMul_cpy,PLLMUL_4);

        /* Check pll clock source */
        switch(RCC_ClkSrc_cpy)
        {
            /* HSI divided by 2 */
            case RCC_HSI_2:
            PR_BAND(RCC->CFGR,PLLSRC) = (uint_32) OFF;
            break;

            /* HSE Bypassed and divided by 2 */
            case RCC_HSE_PYP_2:
            PR_BAND(RCC->CFGR,PLLXTPRE) = = (uint_32) ON;

            /* HSE Bypassed */
            case RCC_HSE_PYP:
            PR_BAND(RCC->CR,HSEON) = (uint_32) OFF;
            PR_BAND(RCC->CR,HSEBYP) = (uint_32) ON;
            break;

            /* HSE divided by 2*/
            case RCC_HSE_2:
            PR_BAND(RCC->CFGR,PLLXTPRE) = (uint_32) ON;

            /* HSE direct */
            case RCC_HSE:
            RCC_ErrorEnableHSE();
            PR_BAND(RCC->CFGR,PLLSRC) = (uint_32) ON;
            break;

            /* Ivalid clock configuration */
            default:
            return NOK;
            break;
        }
        /* enable PLL */
        PR_BAND(RCC->CR,PLLON) = (uint_32) ON;
        /* wait for pll to lock */
        while(!(GET_BIT(RCC->CR,PLLRDY)));
        /* set pll the system clock source (mask and set)*/
        MASK_WORD(RCC->CFGR,SW_MASK,SW_2);
        SET_MASKED(RCC->CFGR,SW_PLL,SW_2);
    }
}

/************************** APIs ****************************/
/************************************************************/
/*  Func       : RCC_ErrorSetSystemClock
/*	Parameters : RCC_SysClkCfg_ptr: pointer to
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorSetSystemClock(RCC_SysClkCfg_t* RCC_SysClkCfg_ptr); // set default configuration in caso of NULL
{
    Error_t ReturnVal = OK;
    /* configure PLL */
    ReturnVal = RCC_ErrorPLLConfig(RCC_SysClkCfg_ptr->RCC_PLLMul, RCC_SysClkCfg_ptr->RCC_ClockSource);
    /* Set clock security system */
    RCC_SysClkCfg_ptr->RCC_CSS == 0? PR_BAND(RCC->CR,CSSON) = (uint_32) OFF:PR_BAND(RCC->CR,CSSON) = (uint_32) ON;
    return ReturnVal;
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorEnablePeripheral(RCC_Preph_t RCC_Preph_cpy);
{
    if(RCC_Preph_cpy < APB2_MIN)
    {
        /* ahp */
        PR_BAND(RCC->AHBENR,RCC_Preph_cpy) = (uint_32) ON;
        return OK;
    }
    else if(RCC_Preph_cpy < APB1_MIN)
    {
        /* APB 2 */
        PR_BAND(RCC->APB2ENR,RCC_Preph_cpy) = (uint_32) ON;
        return OK;
    }
    else if(RCC_Preph_cpy <= APB1_MAX)
    {
        /* APB 1 */
        PR_BAND(RCC->APB1ENR,RCC_Preph_cpy) = (uint_32) ON;
        return OK;
    }
    else
    {
        return NOK;
    }
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorDisablePeripheral(RCC_Preph_t RCC_Preph_cpy);
{
    if(RCC_Preph_cpy < APB2_MIN)
    {
        /* AHB */
        PR_BAND(RCC->AHBENR,RCC_Preph_cpy) = (uint_32) OFF;
        return OK;
    }
    else if(RCC_Preph_cpy < APB1_MIN)
    {
        /* APB 2 */
        PR_BAND(RCC->APB2ENR,RCC_Preph_cpy) = (uint_32) OFF;
        return OK;
    }
    else if(RCC_Preph_cpy <= APB1_MAX)
    {
        /* APB 1 */
        PR_BAND(RCC->APB1ENR,RCC_Preph_cpy) = (uint_32) OFF;
        return OK;
    }
    else
    {
        return NOK;
    }
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorResetPeripheral(RCC_Preph_t RCC_Preph_cpy);
{
    if(RCC_Preph_cpy < APB2_MIN)
    {
        /* AHB */
        return NOK;
    }
    else if(RCC_Preph_cpy < APB1_MIN)
    {
        /* APB 2 */
        PR_BAND(RCC->APB2RSTR, RCC_Preph_cpy) = (uint_32) ON;
        return OK;
    }
    else if(RCC_Preph_cpy <= APB1_MAX)
    {
        /* APB 1 */
        PR_BAND(RCC->APB1RSTR, RCC_Preph_cpy) = (uint_32) ON;
        return OK;
    }
    else
    {
        return NOK;
    }
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorSetBusPrescaler(RCC_BusConfig_t* RCC_BusConfig_ptr);//set default configuration in caso of NULL
{
  /* AHB */
  MASK_WORD(RCC->CFGR,HPRE_MASK,HPRE_4);
  SET_MASKED(RCC->CFGR,(RCC_BusConfig_ptr->RCC_AHBPre^AHB_PRE_CHECK),HPRE_4);
  /* APB1 */
  MASK_WORD(RCC->CFGR,PPRE1_MASK,PPRE1_3);
  SET_MASKED(RCC->CFGR,(RCC_BusConfig_ptr->RCC_APB1Pre^APB_PRE_CHECK),PPRE1_3);
  /* APB1 */
  MASK_WORD(RCC->CFGR,PPRE2_MASK,PPRE2_3);
  SET_MASKED(RCC->CFGR,(RCC_BusConfig_ptr->RCC_APB2Pre^APB_PRE_CHECK),PPRE2_3);

  return OK;
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorEnableInterrupt(RCC_Int_t RCC_Int_cpy)
{
    PR_BAND(RCC->CIR,RCC_Int_cpy+RCC_IE_OFFSET) = (uint_32) ON;
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorDisableInterrupt(RCC_Int_t RCC_Int_t)
{
    PR_BAND(RCC->CIR,RCC_Int_cpy+RCC_IE_OFFSET) = (uint_32) OFF;
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorClearFlag(RCC_Int_t RCC_Int_cpy)
{
    PR_BAND(RCC->CIR,RCC_Int_cpy+RCC_IC_OFFSET) = (uint_32) ON;
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
uint_8  RCC_uint_8ReadFlag(RCC_Int_t RCC_Int_cpy)
{
    (uint_8) GET_BIT(RCC->CIR,RCC_Int_cpy);
}

/************************************************************/
/*  Func       : RCC_ErrorPLLConfig
/*	Parameters : RCC_PLLMul_cpy: Pll Multiplier
/*               RCC_ClkSrc_cpy: Clock source
/*	Return     : Error_t
/*  Description: configures the PLL and system clock if HSI
/*               is not chosen as System clock.
/************************************************************/
Error_t RCC_ErrorSetClockOut(RCC_CLKOUT_t RCC_CLKOUT_cpy)
{
    MASK_WORD(RCC->CFGR,MCO_MASK,MCO_3);
    SET_MASKED(RCC->CFGR,(RCC_CLKOUT_cpy^MCO_CHECK),MCO_3);
}

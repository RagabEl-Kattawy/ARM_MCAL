/**
 * @file RCC_prog.c
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief RCC Driver Functions Implementaion
 * It conatins both functions and APIs implementation.
 * @version 0.1
 * @date 10-26-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */

/************************ Includes **************************/
#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_cfg.h"

/************************ Defines ***************************/

/**
 * @brief Validate Pll mul value
 * 
 */
#define IS_PLLMUL_VALID(mul) (mul==PLL_MUL_2)||(mul==PLL_MUL_3)||(mul==PLL_MUL_4)||\
                         (mul==PLL_MUL_5)||(mul==PLL_MUL_6)||(mul==PLL_MUL_7)||\
                         (mul==PLL_MUL_8)||(mul==PLL_MUL_9)||(mul==PLL_MUL_10)||\
                         (mul==PLL_MUL_11)||(mul==PLL_MUL_12)||(mul==PLL_MUL_13)||\
                         (mul==PLL_MUL_14)||(mul==PLL_MUL_15)||(mul==PLL_MUL_16)

#define IS_SYS_CLK_VALID(conf) (RCC_SysClkCfg_ptr == NULL)
/// Decoding AHB prescaled value
#define AHB_PRE_CHECK   0x08
/// Decoding APB prescaler value
#define APB_PRE_CHECK   0x04
/// Decoding MCO value
#define MCO_CHECK       0x04
/// Interrupt enable decoding offset
#define RCC_IE_OFFSET   0x08
/// Interrupt clear decoding offset
#define RCC_IC_OFFSET   0x1F

/*********************** Typedefs ***************************/

/******************* Global Interfaces **********************/


/*********************** Functions **************************/

/**
 * @brief Enable High speed external clock
 * @param void
 * @return Error_t Error Code
 */
Error_t RCC_ErrorEnableHSE(void)
{
    /* set HSEON */
    PR_BAND(RCC->CR,HSEON) = (uint_32) ON;
    /* wait for ready flag */
    while(!GET_BIT(RCC->CR,HSERDY));
    return OK;
}

/**
 * @brief Enable High speed internal clock & set it as System clock.
 * @param void
 * @return Error_t Error Code
 */
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

/**
 * @brief configures the PLL and system clock if HSI
 * is not chosen as System clock.
 * 
 * @param RCC_PLLMul_cpy PLL Multiplier Must be RCC_PLLMul_t type.
 * @param RCC_ClkSrc_cpy Clock source Must be RCC_ClkSrc_t type.
 * @return Error_t Error Code.
 */
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
            return ReturnVal;
            break;

            /* HSE chosen */
            case RCC_HSE:
            /* SET HSION */
            ReturnVal = RCC_ErrorEnableHSE();
            /* connect clock */
            MASK_WORD(RCC->CFGR,SW_MASK,SW_2);
            SET_MASKED(RCC->CFGR,RCC_HSE&1,SW_2);
            /* return acknowldge*/
            return ReturnVal;
            break;

            default :
            return NOK;
        }
        break;

        /* PLL required */
        default:
        /* assert pll mul */
        ReturnVal = assert_param(IS_PLLMUL_VALID(RCC_PLLMul_cpy));
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
            PR_BAND(RCC->CFGR,PLLXTPRE) = (uint_32) ON;

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

/**
 * @brief configures the PLL and system clock if HSI 
 * is not chosen as System clock.
 * 
 * @param RCC_SysClkCfg_ptr Pointer to RCC_SysClkCfg_t must contatin proper
 *  configurtion options.
 * @return Error_t Error Code.
 */
Error_t RCC_ErrorSetSystemClock(RCC_SysClkCfg_t* RCC_SysClkCfg_ptr) // set default configuration in caso of NULL
{
    Error_t ReturnVal = OK;
    assert_param(IS_SYS_CLK_VALID(RCC_SysClkCfg_ptr));
    /* configure PLL */
    ReturnVal = RCC_ErrorPLLConfig(RCC_SysClkCfg_ptr->RCC_PLLMul, RCC_SysClkCfg_ptr->RCC_ClockSource);
    /* Set clock security system */
    RCC_SysClkCfg_ptr->RCC_CSS == (RCC_CSS_t)0? (PR_BAND(RCC->CR,CSSON) = (uint_32) OFF):(PR_BAND(RCC->CR,CSSON) = (uint_32) ON);
    return ReturnVal;
}


/**
 * @brief Cotrol peripherals clock (Enable).
 * 
 * @param RCC_Preph_cpy Peripheral index MUST be RCC_Preph_t type and range.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorEnablePeripheral(RCC_Preph_t RCC_Preph_cpy)
{
    if(RCC_Preph_cpy < APB2_MIN)
    {
        /* AHB */
        PR_BAND(RCC->AHBENR,RCC_Preph_cpy) = (uint_32) ON;
        return OK;
    }
    else if(RCC_Preph_cpy < APB1_MIN)
    {
        /* APB 2 */
        PR_BAND(RCC->APB2ENR,(RCC_Preph_cpy%APB2_MIN)) = (uint_32) ON;
        return OK;
    }
    else if(RCC_Preph_cpy <= APB1_MAX)
    {
        /* APB 1 */
        PR_BAND(RCC->APB1ENR,(RCC_Preph_cpy%APB2_MIN)) = (uint_32) ON;
        return OK;
    }
    else
    {
        return NOK;
    }
}

/**
 * @brief Cotrol peripherals clock (Disable).
 * 
 * @param RCC_Preph_cpy Peripheral index MUST be RCC_Preph_t type and range.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorDisablePeripheral(RCC_Preph_t RCC_Preph_cpy)
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
        PR_BAND(RCC->APB2ENR,(RCC_Preph_cpy%APB2_MIN)) = (uint_32) OFF;
        return OK;
    }
    else if(RCC_Preph_cpy <= APB1_MAX)
    {
        /* APB 1 */
        PR_BAND(RCC->APB1ENR,(RCC_Preph_cpy%APB2_MIN)) = (uint_32) OFF;
        return OK;
    }
    else
    {
        return NOK;
    }
}

/**
 * @brief Reset peripherals configurations.
 * 
 * @param RCC_Preph_cpy Peripheral index MUST be RCC_Preph_t type and range.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorResetPeripheral(RCC_Preph_t RCC_Preph_cpy)
{
    if(RCC_Preph_cpy < APB2_MIN)
    {
        /* AHB */
        return NOK;
    }
    else if(RCC_Preph_cpy < APB1_MIN)
    {
        /* APB 2 */
        PR_BAND(RCC->APB2RSTR,(RCC_Preph_cpy%APB2_MIN)) = (uint_32) ON;
        return OK;
    }
    else if(RCC_Preph_cpy <= APB1_MAX)
    {
        /* APB 1 */
        PR_BAND(RCC->APB1RSTR,(RCC_Preph_cpy%APB2_MIN)) = (uint_32) ON;
        return OK;
    }
    else
    {
        return NOK;
    }
}

/**
 * @brief Configure Buses Prescalers
 * 
 * @param RCC_BusConfig_ptr Pointer to RCC_BusConfig_t contains the Buses prescalers.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorSetBusPrescaler(RCC_BusConfig_t* RCC_BusConfig_ptr) //set default configuration in caso of NULL
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

/**
 * @brief Control RCC Interrupts (Enable)
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorEnableInterrupt(RCC_Int_t RCC_Int_cpy)
{
    PR_BAND(RCC->CIR,RCC_Int_cpy+RCC_IE_OFFSET) = (uint_32) ON;
}

/**
 * @brief Control RCC Interrupts (Disable)
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorDisableInterrupt(RCC_Int_t RCC_Int_cpy)
{
    PR_BAND(RCC->CIR,RCC_Int_cpy+RCC_IE_OFFSET) = (uint_32) OFF;
}

/**
 * @brief Clear RCC Interrupt flags.
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return Error_t Error code.
 */
Error_t RCC_ErrorClearFlag(RCC_Int_t RCC_Int_cpy)
{
    PR_BAND(RCC->CIR,RCC_Int_cpy+RCC_IC_OFFSET) = (uint_32) ON;
}

/**
 * @brief Read RCC interrupt flags.
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return uint_8 Interrupt flag.
 */
uint_8  RCC_uint_8ReadFlag(RCC_Int_t RCC_Int_cpy)
{
    return (uint_8) GET_BIT(RCC->CIR,RCC_Int_cpy);
}

/**
 * @brief Set the Microcontroller Clock Output.
 * 
 * @param RCC_CLKOUT_cpy Microcontroller Clock Output source MUST be RCC_CLKOUT_t type.
 * @return Error_t Error code
 */

Error_t RCC_ErrorSetClockOut(RCC_CLKOUT_t RCC_CLKOUT_cpy)
{
    MASK_WORD(RCC->CFGR,MCO_MASK,MCO_3);
    SET_MASKED(RCC->CFGR,(RCC_CLKOUT_cpy^MCO_CHECK),MCO_3);
}

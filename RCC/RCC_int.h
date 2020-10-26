/**
 * @file RCC_int.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief The interface file (should be included in any file using RCC APIs)
 * @version 0.1
 * @date 10-26-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */
#ifndef RCC_INT_H_
#define RCC_INT_H_

/************************ Includes **************************/
#include "../LIB/STD_types.h"
#include "../LIB/BIT_math.h"
#include "../LIB/ASSERT.h"

/************************ Defines ***************************/

#define RCC_DEFAULT 0x00

/*********************** Typedefs ***************************/

/* Pll configurations */

/**
 * @brief PLL Multiplication factors.
 * 
 */
typedef enum{
    PLL_NONE    = 0x00,     /*!< No Multiplication Factor */
    PLL_MUL_2   = 0x01,     /*!< x2 Multiplication Factor */
    PLL_MUL_3   = 0x02,     /*!< x3 Multiplication Factor */
    PLL_MUL_4   = 0x03,     /*!< x4 Multiplication Factor */
    PLL_MUL_5   = 0x04,     /*!< x5 Multiplication Factor */
    PLL_MUL_6   = 0x05,     /*!< x6 Multiplication Factor */
    PLL_MUL_7   = 0x06,     /*!< x7 Multiplication Factor */
    PLL_MUL_8   = 0x07,     /*!< x8 Multiplication Factor */
    PLL_MUL_9   = 0x08,     /*!< x9 Multiplication Factor */
    PLL_MUL_10  = 0x09,     /*!< x10 Multiplication Factor */
    PLL_MUL_11  = 0x0A,     /*!< x11 Multiplication Factor */
    PLL_MUL_12  = 0x0B,     /*!< x12 Multiplication Factor */
    PLL_MUL_13  = 0x0C,     /*!< x13 Multiplication Factor */
    PLL_MUL_14  = 0x0D,     /*!< x14 Multiplication Factor */
    PLL_MUL_15  = 0x0E,     /*!< x15 Multiplication Factor */
    PLL_MUL_16  = 0x0F      /*!< x16 Multiplication Factor */
} RCC_PLLMul_t;

/**
 * @brief system clock used.
 * 
 */
typedef enum {
    RCC_HSI     = 0x00,     /*!< High speed internal clock */
    RCC_HSE     = 0xCF,     /*!< High speed external clock */
    RCC_HSI_2   = 0x9F,     /*!< High speed internal clocc divided by 2 */
    RCC_HSE_2   = 0xF9,     /*!< High speed external clock divided by 2 */
    RCC_HSE_PYP = 0xE7,     /*!< High speed external clock bypassed */
    RCC_HSE_PYP_2 = 0x7E    /*!< High speed external clock bypassed and divided by 2 */
} RCC_ClkSrc_t;

/**
 * @brief Clock Security configurations
 * 
 */
typedef enum {
    RCC_CSS_ON  = 0x01,     /*!< RCC Clock security system ON */
    RCC_CSS_OFF = 0x00      /*!< RCC Clock security system OFF */
} RCC_CSS_t;

/**
 * @brief System configuration Structure
 * 
 */
typedef struct{
    RCC_PLLMul_t        RCC_PLLMul      ;   /*!< PLL multiplication factor from RCC_PLLMul_t */
    RCC_ClkSrc_t        RCC_ClockSource ;   /*!< RCC Clock Source from RCC_ClkSrc_t */
    RCC_CSS_t           RCC_CSS         ;   /*!< RCC_CSS */
} RCC_SysClkCfg_t;

/**
 * @brief Internal Busses.
 * 
 */
typedef enum{
    AHB         = 0x00,     /*!< Advanced High Performance BUS */
    APB1        = 0xCF,     /*!< Advanced Peripheral Bus 1 (LOW SPEED 36 MHz MAX) */
    APB2        = 0xFC      /*!< Advanced Peripheral Bus 2 */
}RCC_Bus_t;

/**
 * @brief Buses Prescaler
 * 
 */
typedef enum{
    BUS_AHB_NONE= 0x08,     /*!< AHB Has No prescaler */
    BUS_APB_NONE= 0x04,     /*!< APBx has no Prescaler */
    BUS_DIV_2   = 0x00,     /*!< Divide feeding clock by 2 */
    BUS_DIV_4   = 0x01,     /*!< Divide feeding clock by 4 */
    BUS_DIV_8   = 0x02,     /*!< Divide feeding clock by 8 */
    BUS_DIV_16  = 0x03,     /*!< Divide feeding clock by 16 */
    BUS_DIV_64  = 0x04,     /*!< Divide feeding clock by 64 */
    BUS_DIV_128 = 0x05,     /*!< Divide feeding clock by 128 */
    BUS_DIV_256 = 0x06,     /*!< Divide feeding clock by 256 */
    BUS_DIV_512 = 0x07,     /*!< Divide feeding clock by 512 */
} RCC_BusPre_t;

/**
 * @brief Buses Prescaler configuration structure
 * 
 */
typedef struct{
    RCC_BusPre_t  RCC_AHBPre;    /*!< AHB (prescaler All values Valid) */
    RCC_BusPre_t  RCC_APB1Pre;   /*!< APB1 prescaler ( only /0, /2, /4, /8, /16) 36 MHz max */
    RCC_BusPre_t  RCC_APB2Pre;   /*!< APB1 prescaler ( only /0, /2, /4, /8, /16) */
}RCC_BusConfig_t;

/**
 * @brief RCC interrupt signals IDs
 * 
 */
typedef enum{
    RCC_CSS_INT    = 0x07,  /*!< CSS interrupt ID */
    RCC_PLLRDY_INT = 0x04,  /*!< PLL ready Interrupt ID */
    RCC_HSERDY_INT = 0x03,  /*!< HSE Ready Interrupt ID */
    RCC_HSIRDY_INT = 0x02,  /*!< HSI Ready Inperrupt ID */
    RCC_LSERDY_INT = 0x01,  /*!< LSE Ready Interrupt ID */
    RCC_LSIRDY_INT = 0x00   /*!< LSI Ready Interrupt ID */
}RCC_Int_t;

/**
 * @brief Microcintroller Clock Output (50 MHz MAX)
 * 
 */
typedef enum{
    RCC_NO_CLK_OUT  = 0x04, /*!< No Clock Output */
    RCC_SYSCLK_OUT  = 0x00, /*!< Sysytem Clock */
    RCC_HSI_OUT     = 0x01, /*!< HSI Clock */
    RCC_HSE_OUT     = 0x02, /*!< HSE Clock */
    RCC_PLL_DIV2_OUT= 0x03  /*!< PLL clock divided by 2 */
}RCC_CLKOUT_t;

/**
 * @brief RCC controlled peripherals
 * 
 */
typedef enum{
    AHB_MIN     = 0x00,
    AHB_MAX     = 0x1F,
    APB2_MIN    = 0X20,
    APB2_MAX    = 0x3F,
    APB1_MIN    = 0x40,
    APB1_MAX    = 0x5F,
/*********************** AHB peripherals ********************/
    RCC_DMA1_IDX        = 0,
    RCC_DMA2_IDX        = 1,
    RCC_SRAM_IDX        = 2,
    RCC_FLITF_IDX       = 4,
    RCC_CRC_IDX         = 6,
    RCC_FSMC_IDX        = 8,
    RCC_SDIO_IDX        = 10,

/*********************** APB2 peripherals *******************/
    RCC_AFIO_IDX        = 32,
    RCC_IOPA_IDX        = 34,
    RCC_IOPB_IDX        = 35,
    RCC_IOPC_IDX        = 36,
    RCC_IOPD_IDX        = 37,
    RCC_IOPE_IDX        = 38,
    RCC_IOPF_IDX        = 39,
    RCC_IOPG_IDX        = 40,
    RCC_ADC1_IDX        = 41,
    RCC_ADC2_IDX        = 42,
    RCC_TIM1_IDX        = 43,
    RCC_SPI1_IDX        = 44,
    RCC_TIM8_IDX        = 45,
    RCC_USART1_IDX      = 46,
    RCC_ADC3_IDX        = 47,
    RCC_TIM9_IDX        = 51,
    RCC_TIM10_IDX       = 52,
    RCC_TIM11_IDX       = 53,

/********************** APB1 peripherals ********************/
    RCC_TIM2_IDX        = 64,
    RCC_TIM3_IDX        = 65,
    RCC_TIM4_IDX        = 66,
    RCC_TIM5_IDX        = 67,
    RCC_TIM6_IDX        = 68,
    RCC_TIM7_IDX        = 69,
    RCC_TIM12_IDX       = 70,
    RCC_TIM13_IDX       = 71,
    RCC_TIM14_IDX       = 72,
    RCC_WWDG_IDX        = 75,
    RCC_SPI2_IDX        = 78,
    RCC_SPI3_IDX        = 79,
    RCC_USART2_IDX      = 81,
    RCC_USART3_IDX      = 82,
    RCC_USART4_IDX      = 83,
    RCC_USART5_IDX      = 84,
    RCC_I2C1_IDX        = 85,
    RCC_I2C2_IDX        = 86,
    RCC_USB_IDX         = 87,
    RCC_CAN_IDX         = 89,
    RCC_BKP_IDX         = 91,
    RCC_PWR_IDX         = 92,
    RCC_DAC_IDX         = 93
}RCC_Preph_t;

/******************* Global Interfaces **********************/


/************************* APIs *****************************/
/**
 * @brief configures the PLL and system clock if HSI 
 * is not chosen as System clock.
 * 
 * @param RCC_SysClkCfg_ptr Pointer to RCC_SysClkCfg_t must contatin proper
 *  configurtion options.
 * @return Error_t Error Code.
 */
Error_t RCC_ErrorSetSystemClock(RCC_SysClkCfg_t* RCC_SysClkCfg_ptr);

/**
 * @brief Cotrol peripherals clock (Enable).
 * 
 * @param RCC_Preph_cpy Peripheral index MUST be RCC_Preph_t type and range.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorEnablePeripheral(RCC_Preph_t RCC_Preph_cpy);

/**
 * @brief Cotrol peripherals clock (Disable).
 * 
 * @param RCC_Preph_cpy Peripheral index MUST be RCC_Preph_t type and range.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorDisablePeripheral(RCC_Preph_t RCC_Preph_cpy);

/**
 * @brief Reset peripherals configurations.
 * 
 * @param RCC_Preph_cpy Peripheral index MUST be RCC_Preph_t type and range.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorResetPeripheral(RCC_Preph_t RCC_Preph_cpy);

/**
 * @brief Configure Buses Prescalers
 * 
 * @param RCC_BusConfig_ptr Pointer to RCC_BusConfig_t contains the Buses prescalers.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorSetBusPrescaler(RCC_BusConfig_t* RCC_BusConfig_ptr);

/**
 * @brief Control RCC Interrupts (Enable)
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorEnableInterrupt(RCC_Int_t RCC_Int_cpy);

/**
 * @brief Control RCC Interrupts (Disable)
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return Error_t Erroe code.
 */
Error_t RCC_ErrorDisableInterrupt(RCC_Int_t RCC_Int_cpy);

/**
 * @brief Clear RCC Interrupt flags.
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return Error_t Error code.
 */
Error_t RCC_ErrorClearFlag(RCC_Int_t RCC_Int_cpy);
/**
 * @brief Read RCC interrupt flags.
 * 
 * @param RCC_Int_cpy interrupt signal index MUST be RCC_Int_t type.
 * @return uint_8 Interrupt flag.
 */
uint_8  RCC_uint_8ReadFlag(RCC_Int_t RCC_Int_cpy);
/**
 * @brief Set the Microcontroller Clock Output.
 * 
 * @param RCC_CLKOUT_cpy Microcontroller Clock Output source MUST be RCC_CLKOUT_t type.
 * @return Error_t Error code.
 */

Error_t RCC_ErrorSetClockOut(RCC_CLKOUT_t RCC_CLKOUT_cpy);

#endif /* RCC_INT_H_ */

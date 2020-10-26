/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : RCC INTERFACE    [RCC_int.h]               */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/
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
typedef enum{
    /* boundaries */
    AHB_MIN     = 0x00,
    AHB_MAX     = 0x1F,
    APB2_MIN    = 0X20,
    APB2_MAX    = 0x3F,
    APB1_MIN    = 0x40,
    APB1_MAX    = 0x5F,

    PLL_NONE    = 0x00,
    PLL_MUL_2   = 0x01,
    PLL_MUL_3   = 0x02,
    PLL_MUL_4   = 0x03,
    PLL_MUL_5   = 0x04,
    PLL_MUL_6   = 0x05,
    PLL_MUL_7   = 0x06,
    PLL_MUL_8   = 0x07,
    PLL_MUL_9   = 0x08,
    PLL_MUL_10  = 0x09,
    PLL_MUL_11  = 0x0A,
    PLL_MUL_12  = 0x0B,
    PLL_MUL_13  = 0x0C,
    PLL_MUL_14  = 0x0D,
    PLL_MUL_15  = 0x0E,
    PLL_MUL_16  = 0x0F
} RCC_PLLMul_t;

/* system clock origin */
typedef enum {
    RCC_HSI     = 0x00,
    RCC_HSE     = 0xCF,
    RCC_HSI_2   = 0x9F,
    RCC_HSE_2   = 0xF9,
    RCC_HSE_PYP = 0xE7,
    RCC_HSE_PYP_2 = 0x7E
} RCC_ClkSrc_t;

/* Clock Security configurations */
typedef enum {
    RCC_CSS_ON  = 0x01,
    RCC_CSS_OFF = 0x00
} RCC_CSS_t;

typedef struct{
    RCC_PLLMul_t        RCC_PLLMul      ;
    RCC_ClkSrc_t        RCC_ClockSource ;
    RCC_CSS_t           RCC_CSS         ;
} RCC_SysClkCfg_t;

typedef enum{
    AHB         = 0x00,
    APB1        = 0xCF,
    APB2        = 0xFC
}RCC_Bus_t;

typedef enum{
    BUS_AHB_NONE= 0x08,
    BUS_APB_NONE= 0x04,
    BUS_DIV_2   = 0x00,
    BUS_DIV_4   = 0x01,
    BUS_DIV_8   = 0x02,
    BUS_DIV_16  = 0x03,
    BUS_DIV_64  = 0x04,
    BUS_DIV_128 = 0x05,
    BUS_DIV_256 = 0x06,
    BUS_DIV_512 = 0x07,
} RCC_BusPre_t;

typedef struct{
    RCC_BusPre_t  RCC_AHBPre;
    RCC_BusPre_t  RCC_APB1Pre;
    RCC_BusPre_t  RCC_APB2Pre;
}RCC_BusConfig_t;

typedef enum{
    RCC_CSS_INT    = 7,
    RCC_PLLRDY_INT = 4,
    RCC_HSERDY_INT = 3,
    RCC_HSIRDY_INT = 2,
    RCC_LSERDY_INT = 1,
    RCC_LSIRDY_INT = 0
}RCC_Int_t;

typedef enum{
    RCC_NO_CLK_OUT  = 0x04,
    RCC_SYSCLK_OUT  = 0x00,
    RCC_HSI_OUT     = 0x01,
    RCC_HSE_OUT     = 0x02,
    RCC_PLL_DIV2_OUT= 0x03
}RCC_CLKOUT_t;

typedef enum{
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
Error_t RCC_ErrorResetSystem(void);
Error_t RCC_ErrorSetSystemClock(RCC_SysClkCfg_t* RCC_SysClkCfg_ptr); // set default configuration in caso of NULL
Error_t RCC_ErrorEnablePeripheral(RCC_Preph_t RCC_Preph_cpy);
Error_t RCC_ErrorDisablePeripheral(RCC_Preph_t RCC_Preph_cpy);
Error_t RCC_ErrorResetPeripheral(RCC_Preph_t RCC_Preph_cpy);
Error_t RCC_ErrorSetBusPrescaler(RCC_BusConfig_t* RCC_BusConfig_ptr);//set default configuration in caso of NULL
Error_t RCC_ErrorEnableInterrupt(RCC_Int_t RCC_Int_cpy);
Error_t RCC_ErrorDisableInterrupt(RCC_Int_t RCC_Int_t);
Error_t RCC_ErrorClearFlag(RCC_Int_t RCC_Int_cpy);
uint_8  RCC_uint_8ReadFlag(RCC_Int_t RCC_Int_cpy);
Error_t RCC_ErrorSetClockOut(RCC_CLKOUT_t);
RCC_CLKOUT_t  RCC_RCC_CLKOUT_tGetClockOut(void);

#endif /* RCC_INT_H_ */

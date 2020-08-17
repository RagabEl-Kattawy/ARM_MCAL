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

typedef struct{
    RCC_ClockSource_t   RCC_ClockSource ;
    RCC_CSS_t           RCC_CSS         ;
} RCC_SysClkCfg_t;

typedef struct{
    RCC_CSS_t           RCC_CSS         ;
    RCC_HSEPYP_t        RCC_HSEPYP      ;
} RCC_HSECfg_t;

typedef struct{
    RCC_PLLMul_t        RCC_PLLMul      ;
    RCC_PLLSource_t     RCC_PLLSource   ;
} RCC_PLLCfg_t;

/* System clock sources */
typedef enum {
    RCC_HSI     = 0x00,
    RCC_HSE     = 0xCF,
    RCC_PLL     = 0xFC
} RCC_ClockSource_t;

typedef enum {
    RCC_CSS_ON  = 0x00,
    RCC_CSS_OFF = 0xCF
} RCC_CSS_t;

typedef enum {
    RCC_HSEPYP_OFF  = 0x00,
    RCC_HSEPYP_ON   = 0xCF
} RCC_HSEPYP_t;

typedef enum{
    PLL_MUL_2   = 0x00,
    PLL_MUL_3   = 0x01,
    PLL_MUL_4   = 0x02,
    PLL_MUL_5   = 0x03,
    PLL_MUL_6   = 0x04,
    PLL_MUL_7   = 0x05,
    PLL_MUL_8   = 0x06,
    PLL_MUL_9   = 0x07,
    PLL_MUL_10  = 0x08,
    PLL_MUL_11  = 0x09,
    PLL_MUL_12  = 0x0A,
    PLL_MUL_13  = 0x0B,
    PLL_MUL_14  = 0x0C,
    PLL_MUL_15  = 0x0D,
    PLL_MUL_16  = 0x0E
} RCC_PLLMul_t;

typedef enum {
   RCC_HSI      = 0x00,
   RCC_HSE      = 0xEE,
   RCC_HSE_DIV2 = 0x3F
} RCC_PLLSource_t;

/******************* Global Interfaces **********************/


/************************* APIs *****************************/
Error_t RCC_ErrorInitSystemClock(void);
Error_t RCC_ErrorResetRCC(void);


#endif /* RCC_INT_H_ */

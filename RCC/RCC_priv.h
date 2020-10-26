/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : RCC PRIVATE    [RCC_priv.h]                */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/
#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/************************ Includes **************************/
#include "../LIB/STD_types.h"
#include "../LIB/BIT_math.h"
#include "../LIB/ASSERT.h"

/************************ Defines ***************************/
#define RCC_BASEADDRESS 	     0x40021000
#define AHB_MIN                  0
#define AHB_MAX                  10
#define APB2_MIN                 32
#define APB2_MAX                 53
#define APB1_MIN                 64
#define APB1_MAX                 93

// RCC_CR
#define HSION 0
#define HSIRDY 1
#define HSEON 16
#define HSERDY 17
#define HSEBYP 18
#define CSSON 19
#define PLLON 24
#define PLLRDY 25

// RCC_CFGR
#define SW_2 0
#define SWS_2 2
#define HPRE_4 4
#define PPRE1_3 8
#define PPRE2_3 11
#define ADCPRE_2 14
#define PLLSRC 16
#define PLLXTRE 17
#define PLLMUL_4 18
#define MCO_3 24

#define SW_MASK 0x03
#define SWS_MASK 0x03
#define HPRE_MASK 0x0F
#define PPRE1_MASK 0x07
#define PPRE2_MASK 0x07
#define ADCPRE_MASK 0x03
#define PLLMUL_MASK 0x0F
#define MCO_MASK 0x07

// RCC_CIR
#define LSIRDYF 0
#define LSERDYF 1
#define HSIRDYF 2
#define HSERDYF 3
#define PLLRDYF 4

#define CSSF 7

#define LSIRDYIE 8
#define LSERDYIE 9
#define HSIRDYIE 10
#define HSERDYIE 11
#define PLLRDYIE 12

#define LSIRDYC 16
#define LSERDYC 17
#define HSIRDYC 18
#define HSERDYC 19
#define PLLRDYC 20

#define CSSC 23

#define SW_PLL 0x02

#define RCC 		((volatile RCC_Reg_t*) RCC_BASEADDRESS)
/*********************** Typedefs ***************************/
typedef struct
{
	uint_32 CR;
	uint_32 CFGR;
	uint_32 CIR;
	uint_32 APB2RSTR;
	uint_32 APB1RSTR;
	uint_32 AHBENR;
	uint_32 APB2ENR;
	uint_32 APB1ENR;
	uint_32 BDCR;
	uint_32 CSR;
}RCC_Reg_t;
/******************* Global Interfaces **********************/






#endif /* RCC_PRIV_H_ */

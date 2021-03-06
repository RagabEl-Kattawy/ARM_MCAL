/**
 * @file RCC_priv.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief Private file that contains Private Parameters
 * that is used internally in the implementtion. 
 * @version 0.1
 * @date 10-26-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */
#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/************************ Includes **************************/

#include "lib/BIT_math.h"
#include "lib/ASSERT.h"
#include "lib/STD_types.h"

/************************ Defines ***************************/
#define RCC_BASEADDRESS 	    0x40021000
#define RCC 		((volatile RCC_Reg_t*) RCC_BASEADDRESS)

/* RCC_CR bits */
#define HSION                   0
#define HSIRDY                  1
#define HSEON                   16
#define HSERDY                  17
#define HSEBYP                  18
#define CSSON                   19
#define PLLON                   24
#define PLLRDY                  25

/* RCC_CFGR bits */
#define SW_2                    0
#define SWS_2                   2
#define HPRE_4                  4
#define PPRE1_3                 8
#define PPRE2_3                 11
#define ADCPRE_2                14
#define PLLSRC                  16
#define PLLXTPRE                17
#define PLLMUL_4                18
#define MCO_3                   24

/* RCC_CFGR bit-fields mask values */
#define SW_MASK                 0x03
#define SWS_MASK                0x03
#define HPRE_MASK               0x0F
#define PPRE1_MASK              0x07
#define PPRE2_MASK              0x07
#define ADCPRE_MASK             0x03
#define PLLMUL_MASK             0x0F
#define MCO_MASK                0x07

/* RCC_CIR bits */
#define LSIRDYF                 0
#define LSERDYF                 1
#define HSIRDYF                 2
#define HSERDYF                 3
#define PLLRDYF                 4
#define CSSF                    7
#define LSIRDYIE                8
#define LSERDYIE                9
#define HSIRDYIE                10
#define HSERDYIE                11
#define PLLRDYIE                12
#define LSIRDYC                 16
#define LSERDYC                 17
#define HSIRDYC                 18
#define HSERDYC                 19
#define PLLRDYC                 20
#define CSSC                    23

#define SW_PLL                  0x02
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

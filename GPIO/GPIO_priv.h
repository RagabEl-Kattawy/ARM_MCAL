/**
 * @file GPIO_priv.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief Private file that contains Private Parameters
 * that is used internally in the implementtion. 
 * @version 0.1
 * @date 11-02-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */

#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H_

#include "lib/STD_types.h"
#include "lib/BIT_math.h"
#include "lib/ASSERT.h"

/************************ Defines ***************************/
#define GPIOA_BASEADDRESS   0x40010800
#define GPIOB_BASEADDRESS   0x40010C00
#define GPIOC_BASEADDRESS   0x40011000
#define GPIOD_BASEADDRESS   0x40011400
#define GPIOE_BASEADDRESS   0x40011800
#define GPIOF_BASEADDRESS   0x40011C00
#define GPIOG_BASEADDRESS   0x40012000

#define GPIO_A ((volatile GPIO_Reg_t *)GPIOA_BASEADDRESS)
#define GPIO_B ((volatile GPIO_Reg_t *)GPIOB_BASEADDRESS)
#define GPIO_C ((volatile GPIO_Reg_t *)GPIOC_BASEADDRESS)
#define GPIO_D ((volatile GPIO_Reg_t *)GPIOD_BASEADDRESS)
#define GPIO_E ((volatile GPIO_Reg_t *)GPIOE_BASEADDRESS)
#define GPIO_F ((volatile GPIO_Reg_t *)GPIOF_BASEADDRESS)
#define GPIO_G ((volatile GPIO_Reg_t *)GPIOG_BASEADDRESS)


#define IS_BIN_IDX(Pin_Idx) ((Pin_Idx >= GPIO_A00) && (Pin_Idx <= GPIO_G15))
#define IS_CONF(Pin_Conf) (((Pin_Conf >= GPIO_OUT_PP) && (Pin_Conf <= GPIO_IN_PD)) || (Pin_Conf == GPIO_IN_PU))
#define IS_SPEED(Pin_Speed) ((Pin_Speed >= GPIO_SPEED_IN) && (Pin_Speed <= GPIO_SPEED_50MHZ))
#define DECODE_CONF(conf,speed) (((conf & 0x03) << 2) | speed)


#define GPIO_CONF_DECODER 0x02
#define GPIO_LCKR_LCKK 0x10
#define GPIO_HIGH_REG 0x08
#define GPIO_PORT_PIN_DECODER 0x10
#define GPIO_CONF_MASK 0x0F

/*********************** Typedefs ***************************/
typedef struct GPIO_Reg
{
    uint_32 CRL;
    uint_32 CRH;
    uint_32 IDR;
    uint_32 ODR;
    uint_32 BSRR;
    uint_32 BRR;
    uint_32 LCKR;
} GPIO_Reg_t;
#endif /* GPIO_PRIV_H_ */

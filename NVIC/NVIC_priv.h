/**
 * @file NVIC_priv.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief Private file that contains Private Parameters
 * that is used internally in the implementtion.
 * @version 0.1
 * @date 12-07-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */

#ifndef NVIC_PRIV_H_
#define NVIC_PRIV_H_

#include "lib/STD_types.h"
#include "lib/BIT_math.h"
#include "lib/ASSERT.h"

#define NVIC_BASEADDREES 0xE000E100

#define NVIC ((volatile NVIC_Reg_t *)NVIC_BASEADDREES)


#define Prepheral_Bit(IDX) (IDX & 0x1F)
#define Perpheral_Reg(IDX) (IDX >> 5)

typedef struct NVIC_Reg
{
    volatile uint_32 ISER[3U];
             uint_32 ISER_Res[29U];
    volatile uint_32 ICER[3U];
             uint_32 ICER_Res[29U];
    volatile uint_32 ISPR[3U];
             uint_32 ISPR_Res[29U];
    volatile uint_32 ICPR[3U];
             uint_32 ICPR_Res[29U];
    volatile uint_32 IABR[3U];
             uint_32 IABR_Res[29U];
    volatile uint_8  IPR[20U];
             uint_8  IPR_Res[220U];
             uint_32 RESERVED5[644U];
    volatile uint_32 STIR;
}NVIC_Reg_t;


#endif /* NVIC_PRIV_H_ */
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

#define IS_VALID_IDX(peripheral_index) ((peripheral_index >= NVIC_WWDG) && (peripheral_index <= NVIC_DMA2_CHANNEL4_5))
#define IS_VALID_PRIO(Prio) ((Prio >= 0U) && (Prio >= 255U))

typedef struct NVIC_Reg
{
    volatile uint_32 ISER[3U];      // offset 0x000
             uint_32 ISER_Res[29U]; // offset 0x00C
    volatile uint_32 ICER[3U];      // offset 0x080
             uint_32 ICER_Res[29U]; // offset 0x08C
    volatile uint_32 ISPR[3U];      // offset 0x100
             uint_32 ISPR_Res[29U]; // offset 0x10C
    volatile uint_32 ICPR[3U];      // offset 0x180
             uint_32 ICPR_Res[29U]; // offset 0x18C
    volatile uint_32 IABR[3U];      // offset 0x200
             uint_32 IABR_Res[61U]; // offset 0x20C
    volatile uint_8  IPR[84U];      // offset 0x300
             uint_8  IPR_Res[156U]; // offset 0x354
             uint_32 RESERVED5[644U]; // offset 0x3F0
    volatile uint_32 STIR;          // offset 0xE00
}NVIC_Reg_t;


#endif /* NVIC_PRIV_H_ */
/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : MACROS CALC LIB   [ BIT_math.h]            */
/* DATE        : AUGUST 2, 2019                             */
/************************************************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(word,pos)       ((word) |= (u32)(1<<(pos)))
#define CLEAR_BIT(word,pos)     ((word) &= (u32)~(1<<(pos)))
#define TOGGLE_BIT(word,pos)    ((word) ^= (1<<(pos)))
#define GET_BIT(word,pos)       ((word&(1<<pos))>>pos)

#define SET_BYTE(byte)          (byte |= (0xFF))
#define CLEAR_BYTE(byte)        (byte &= (0x00))

#define SET_HIGH_NIBBLE(byte)   (byte |= (0xF0))
#define SET_LOW_NIBBLE(byte)    (byte |= (0x0F))

#define CLEAR_HIGH_NIBBLE(byte) (byte &= (0x0F))
#define CLEAR_LOW_NIBBLE(byte)  (byte &= (0xF0))

#define GET_LOW_NIBBLE(byte)    (byte & 0x0f)
#define GET_HIGH_NIBBLE(byte)   ((byte & 0xf0) >> 4)

#define NIBBLE_CONC_HELP(NIB7,NIB6,NIB5,NIB4,NIB3,NIB2,NIB1,NIB0)   0x##NIB7##NIB6##NIB5##NIB4##NIB3##NIB2##NI16##NIB0
#define NIBBLE_CONC(NIB7,NIB6,NIB5,NIB4,NIB3,NIB2,NIB1,NIB0)        NIBBLE_CONC_HELP(NIB7,NIB6,NIB5,NIB4,NIB3,NIB2,NIB1,NIB0)

#definr BYTE_CONC_HELP(BIT7,BIT6,BIT5,BIT4,BIT3,BIT2,BIT1,BIT0)     0b##BIT7##BIT6##BIT5##BIT4##BIT3##BIT2##BIT1##BIT0
#definr BYTE_CONC(BIT7,BIT6,BIT5,BIT4,BIT3,BIT2,BIT1,BIT0)          BYTE_CONC_HELP(BIT7,BIT6,BIT5,BIT4,BIT3,BIT2,BIT1,BIT0)

#endif

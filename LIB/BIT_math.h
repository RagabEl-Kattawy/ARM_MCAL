/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : MACROS CALC LIB   [ BIT_math.h]            */
/* DATE        : AUGUST 2, 2019                             */
/************************************************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(word,pos)       ((uint_32)(word) |= (uint_32)(1<<(pos)))
#define CLEAR_BIT(word,pos)     ((uint_32)(word) &= (uint_32)~(1<<(pos)))
#define TOGGLE_BIT(word,pos)    ((uint_32)(word) ^= (1<<(pos)))
#define GET_BIT(word,pos)       ((uint_32)(word&(1<<pos))>>pos)

#define MASK_WORD(word,mask,pos)    ((uint_32)(word) &= ^(uint_32)(mask)<<(pos))
#define SET_MASKED(word,value,pos)  ((uint_32)(word) |= (uint_32)(value)<<(pos))

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

#define PERIPHERAL_BAND_BASE             0x42000000
#define PERIPHERALS_BASE                 0x40000000
/********************** important bits **********************/
/************************  bit band *************************/
#define BYTE_OFFSET(ADDRESS)               (((uint_32)&ADDRESS)-PERIPHERALS_BASE)
#define PERIPHERAL_BAND(Reg)               PERIPHERAL_BAND_BASE+(BYTE_OFFSET(Reg)*32)
#define PR_BAND(Register,Bit)              *((uint_32*)(PERIPHERAL_BAND(Register)+(Bit*4)))

#endif

/**
 * @file SCB_priv.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief Private file that contains Private Parameters
 * @version 0.1
 * @date 12-11-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */

#ifndef SCB_PRIV_H_
#define SCB_PRIV_H_

#include "lib/STD_types.h"
#include "lib/BIT_math.h"
#include "lib/ASSERT.h"

#define SCB_BASEADDRESS 0xE000ED00
#define SCB ((volatile SCB_Reg_t *)SCB_BASEADDRESS)


/* ACTLR Bits */

/* Disable folding of IT instructions */
#define DISFOLD 2U
/* Disable write buffer */
#define DISDEFWBUF 1U
/* Disables interrupt of multi-cycle instructions */
#define DISMCYCINT 0U

/* CPUID Bit fields */
/* Implementer Code */
#define IMPLEMENTER 24U
#define IMPLEMENTER_MASK 0xFF000000

/* Variant number */
#define VARIANT 20U
#define VARIANT_MASK 0x00F00000

/* part number */
#define PART_NO 4U
#define PART_NO_MASK 0x0000FFF0

/* revision number */
#define REVISION 0U
#define REVISION_MASK 0x0000000F

/* ICSR Bits */
/* NMI set-pending */
#define NMIPENDSET 31U

/* PendSV set-pending */
#define PENDSVSET 28U

/* PendSV clear-pending */
#define PENDSVCLR 27U

/* SysTick exception set-pending */
#define PENDSTSET 26U

/* SysTick exception clear-pending */
#define PENDSTCLR 25U

/* Interrupt pending flag, excluding NMI and Faults */
#define ISRPENDING 22U

/* Pending vector */
#define VECTPENDING 12U
#define VECTPENDING_MASK 0x003F0000

/*  Return to base level */
#define RETOBASE 11U

/* Active vector */
#define VECTACTIVE 0
#define VECTACTIVE_MASK 0x000001FF


typedef struct SCB_Reg
{
    volatile uint_32 ACTLR;
    volatile uint_32 CPUID;
    volatile uint_32 ICSR;
    volatile uint_32 VTOR;
    volatile uint_32 AIRCR;
    volatile uint_32 SCR;
    volatile uint_32 CCR;
    volatile uint_32 SHPR1;
    volatile uint_32 SHPR2;
    volatile uint_32 SHPR3;
    volatile uint_32 SHCRS;
    volatile uint_32 CFSR;
    volatile uint_32 HFSR;
    volatile uint_32 MMAR;
    volatile uint_32 BFAR;
}SCB_Reg_t;

#endif /* SCB_PRIV_H_ */
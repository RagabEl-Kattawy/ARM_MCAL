/**
 * @file SCB_prog.c
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief GPIO Driver Functions Implementaion
 * It conatins both functions and APIs implementation.
 * @version 0.1
 * @date 12-11-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */
#include "SCB_int.h"
#include "SCB_priv.h"

/**
 * @brief Disables If...Then (IT) instruction folding
 * 
 * @return Error_t Indecates if an error happend during driving a pin.
 * 
 */
Error_t SCB_ErrorDisableITFolding(void)
{
    /* write 1 to DISFOLD in ACTLR */
    SET_BIT(SCB->ACTLR,DISFOLD);
    /* Check if change is applied */
    return GET_BIT(SCB->ACTLR, DISFOLD) ? OK : NOK;
}

/**
 * @brief Enables If...Then (IT) instruction folding
 * 
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorEnableITFolding(void)
{
    /* write 0 to DISFOLD in ACTLR */
    CLEAR_BIT(SCB->ACTLR, DISFOLD);
    /* Check if change is applied */
    return GET_BIT(SCB->ACTLR, DISFOLD) ? NOK : OK;
}

/**
 * @brief Disable write buffer use.
 * 
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorDisableWriteBuffer(void)
{
    /* write 1 to DISDEFWBUF in ACTLR */
    SET_BIT(SCB->ACTLR, DISDEFWBUF);
    /* Check if change is applied */
    return GET_BIT(SCB->ACTLR, DISDEFWBUF) ? OK : NOK;
}

/**
 * @brief Enable write buffer use: stores to memory is competed before next instruction.
 * 
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorEnableWriteBuffer(void)
{
    /* write 0 to DISDEFWBUF in ACTLR */
    CLEAR_BIT(SCB->ACTLR, DISDEFWBUF);
    /* Check if change is applied */
    return GET_BIT(SCB->ACTLR, DISDEFWBUF) ? NOK : OK;
}

/**
 * @brief Disable interruptions latency of the processor (load/store and multiply/divide operations).
 * 
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorDisableMultiCycleInstInterrupt(void)
{
    /* write 1 to DISMCYCINT in ACTLR */
    CLEAR_BIT(SCB->ACTLR, DISMCYCINT);
    /* Check if change is applied */
    return GET_BIT(SCB->ACTLR, DISMCYCINT) ? OK : NOK;
}

/**
 * @brief Enable interruption latency of the processor (load/store and multiply/divide operations).
 * 
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorEnableMultiCycleInstInterrupt(void)
{
    /* write 0 to DISMCYCINT in ACTLR */
    CLEAR_BIT(SCB->ACTLR, DISMCYCINT);
    /* Check if change is applied */
    return GET_BIT(SCB->ACTLR, DISMCYCINT) ? NOK : OK;
}

/**
 * @brief returns mplementer code
 * 
 * @return uint_32 mplementer code: 0x41 = ARM
 */
uint_32 SCB_uint_32GetImplementerCode(void)
{
    return ((SCB->CPUID & IMPLEMENTER_MASK) >> IMPLEMENTER);
}

/**
 * @brief returns Variant number, the r value in the rnpn product revision identifier.
 * 
 * @return uint_32 Variant number : 0x1 = r1, 0x2 = r2
 */
uint_32 SCB_uint_32GetVariantNumber(void)
{
    return ((SCB->CPUID & VARIANT_MASK) >> VARIANT);
}

/**
 * @brief returns the part number of the processor.
 * 
 * @return uint_32 the part number: 0xC23 = Cortex-M3
 */
uint_32 SCB_uint_32GetPartNumber(void)
{
    return ((SCB->CPUID & PART_NO_MASK) >> PART_NO);
}

/**
 * @brief Revision number, the p value in the rnpn product revision identifier.
 * 
 * @return uint_32 Revision number: 0x0 = p0, 0x1 = p1
 */
uint_32 SCB_uint_32GetRevisionNumber(void)
{
    return ((SCB->CPUID & REVISION_MASK) >> REVISION);
}
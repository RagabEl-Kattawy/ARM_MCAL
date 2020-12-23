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

/**
 * @brief This function sets the NMI pending flag (it will execute immediately).
 *
 * @return Error_t Indecates if an error happend during configuration
 */
Error_t SCB_ErrorSetNMIPending(void)
{
    /* set NMIPENDSET */
    SET_BIT(SCB->ICSR,NMIPENDSET);
    return GET_BIT(SCB->ICSR,NMIPENDSET)? NOK : OK;
}

/**
 * @brief This function sets the PendSV pening flag.
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorSetPendSVPending(void)
{
    /* set PENDSVSET */
    SET_BIT(SCB->ICSR,PENDSVSET);
    return OK;
}

/**
 * @brief This function gets the pending flag status of the PendSV.
 * 
 * @return uint_8 
 */
uint_8 SCB_uint_8GetPendSVPendingState(void)
{
    /* Return PENDSVSET */
    return (uint_8)GET_BIT(SCB->ICSR,PENDSVSET);
}

/**
 * @brief This function clears the PendSV pending flag.
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorClearPendSVPending(void)
{
    /* set PENDSVCLR: */
    SET_BIT(SCB->ICSR,PENDSVCLR);
    return GET_BIT(SCB->ICSR,PENDSVCLR)? NOK : OK;
}

/**
 * @brief This functions sets the SysTick timer pending flag
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorSetSysTickPending(void)
{
    /* set PENDSTSET */
    SET_BIT(SCB->ICSR,PENDSTSET);
    return OK;
}

/**
 * @brief This function gets the SysTick pending flag status.
 * 
 * @return uint_8 The sysTick pending flag status
 */
uint_8 SCB_uint_8GetSysTickPendingState(void)
{
    /* Get PENDSTSET: */
    return (uint_8)GET_BIT(SCB->ICSR,PENDSTSET);
}

/**
 * @brief This function clears the SysTick pending flag
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorClearSysTickPending(void)
{    
    /* set PENDSTCLR: */
    SET_BIT(SCB->ICSR,PENDSTCLR);
    return GET_BIT(SCB->ICSR,PENDSTCLR)? NOK : OK;   
}

/**
 * @brief This function checks if there is any pending ISR.
 * 
 * @return uint_8 Pending ISR Status 0: No pending ISR 1: An ISR is pending
 */
uint_8 SCB_uint_8GetPendingISRStatus(void)
{
    /* retrun ISRPENDING */
    return (uint_8)GET_BIT(SCB->ICSR,ISRPENDING);
}

/**
 * @brief This function gets the exception number of the highest priority pending enabled exception.
 *        The value indicated by this field includes the effect of the BASEPRI and FAULTMASK
 *        registers, but not any effect of the PRIMASK register.
 * 
 * @return uint_16 The exception number of the highest priority pending enabled exception.
 */
uint_16 SCB_uint_16GetPendingVector(void)
{
    /* return VECTPENDING [10 bits] */
    return (uint_16) ((SCB->ICSR & VECTPENDING_MASK) >> VECTPENDING);
}

/**
 * @brief This function checks whether there are preempted active exceptions:
 * 
 * @return uint_8 Preemption status 0: There are preempted active exceptions to execute
 *                                  1: There are no active exceptions, or 
 *                                     the currently-executing exception is the
 *                                     only activeexception.
 */
uint_8 SCB_uint_8GetPreemptedExceptionStatus(void)
{
    /* Return RETOBASE */
    return (uint_8) GET_BIT(SCB->ICSR, RETOBASE);
}

/**
 * @brief This function gets the currently active exception number.
 * Subtract 16 from this value to obtain the IRQ number required to index into the
 * Interrupt Clear-Enable, Set-Enable, Clear-Pending, Set-Pending, or Priority Registers,
 * @return uint_16 The index of currently active exception.
 */
uint_16 SCB_uint_16GetActiveException(void)
{
    /* return VECTACTIVE [9 bits] */
    return (uint_16) ((SCB->ICSR & VECTACTIVE_MASK) >> VECTACTIVE);
}
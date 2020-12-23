/**
 * @file SCB_int.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief The interface file (should be included in any file using SCB APIs)
 * @version 0.1
 * @date 12-11-2020
 *
 * @copyright Ragab Elkattawy (c) 2020
 *
 */

#ifndef SCB_INT_H_
#define SCB_INT_H_

#include "lib/STD_types.h"
#include "lib/BIT_math.h"
#include "lib/ASSERT.h"

/* CPUID Return values */
/*  Implementer code */
#define CSB_CPUID_ARM 0x41
/* Variant number */
#define CSB_CPUID_R1 0x1
#define CSB_CPUID_R2 0x2
/*  Part number of the processor */
#define CSB_CPUID_CORTEX_M3 0xC23
/* Revision number */
#define CSB_CPUID_P0 0x0
#define CSB_CPUID_P1 0x1

/**
 * @brief Disables If...Then (IT) instruction folding
 *
 * @return Error_t Indecates if an error happend during driving a pin.
 *
 */
Error_t SCB_ErrorDisableITFolding(void);

/**
 * @brief Enables If...Then (IT) instruction folding
 *
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorEnableITFolding(void);

/**
 * @brief Disable write buffer use.
 *
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorDisableWriteBuffer(void);

/**
 * @brief Enable write buffer use: stores to memory is competed before next instruction.
 *
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorEnableWriteBuffer(void);

/**
 * @brief Disable interruptions latency of the processor (load/store and multiply/divide operations).
 *
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorDisableMultiCycleInstInterrupt(void);

/**
 * @brief Enable interruption latency of the processor (load/store and multiply/divide operations).
 *
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t SCB_ErrorEnableMultiCycleInstInterrupt(void);

/**
 * @brief returns mplementer code
 *
 * @return uint_32 mplementer code: 0x41 = ARM
 */
uint_32 SCB_uint_32GetImplementerCode(void);

/**
 * @brief returns Variant number, the r value in the rnpn product revision identifier.
 *
 * @return uint_32 Variant number : 0x1 = r1, 0x2 = r2
 */
uint_32 SCB_uint_32GetVariantNumber(void);

/**
 * @brief returns the part number of the processor.
 *
 * @return uint_32 the part number: 0xC23 = Cortex-M3
 */
uint_32 SCB_uint_32GetPartNumber(void);

/**
 * @brief Revision number, the p value in the rnpn product revision identifier.
 *
 * @return uint_32 Revision number: 0x0 = p0, 0x1 = p1
 */
uint_32 SCB_uint_32GetRevisionNumber(void);

/**
 * @brief This function sets the NMI pending flag (it will execute immediately).
 *
 * @return Error_t Indecates if an error happend during configuration
 */
Error_t SCB_ErrorSetNMIPending(void);

/**
 * @brief This function sets the PendSV pening flag.
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorSetPendSVPending(void);

/**
 * @brief This function gets the pending flag status of the PendSV.
 * 
 * @return uint_8 
 */
uint_8 SCB_uint_8GetPendSVPendingState(void);

/**
 * @brief This function clears the PendSV pending flag.
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorClearPendSVPending(void);

/**
 * @brief This functions sets the SysTick timer pending flag
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorSetSysTickPending(void);

/**
 * @brief This function gets the SysTick pending flag status.
 * 
 * @return uint_8 The sysTick pending flag status
 */
uint_8 SCB_uint_8GetSysTickPendingState(void);

/**
 * @brief This function clears the SysTick pending flag
 * 
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t SCB_ErrorClearSysTickPending(void);

/**
 * @brief This function checks if there is any pending ISR.
 * 
 * @return uint_8 Pending ISR Status 0: No pending ISR 1: An ISR is pending
 */
uint_8 SCB_uint_8GetPendingISRStatus(void);

/**
 * @brief This function gets the exception number of the highest priority pending enabled exception.
 *        The value indicated by this field includes the effect of the BASEPRI and FAULTMASK
 *        registers, but not any effect of the PRIMASK register.
 * 
 * @return uint_16 The exception number of the highest priority pending enabled exception.
 */
uint_16 SCB_uint_16GetPendingVector(void);

/**
 * @brief This function checks whether there are preempted active exceptions:
 * 
 * @return uint_8 Preemption status 0: There are preempted active exceptions to execute
 *                                  1: There are no active exceptions, or 
 *                                     the currently-executing exception is the
 *                                     only activeexception.
 */
uint_8 SCB_uint_8GetPreemptedExceptionStatus(void);

/**
 * @brief This function gets the currently active exception number.
 * Subtract 16 from this value to obtain the IRQ number required to index into the
 * Interrupt Clear-Enable, Set-Enable, Clear-Pending, Set-Pending, or Priority Registers,
 * @return uint_16 The index of currently active exception.
 */
uint_16 SCB_uint_16GetActiveException(void);

// Error_t SCB_Error
// Error_t SCB_Error
// Error_t SCB_Error
// Error_t SCB_Error
// Error_t SCB_Error

#endif /* SCB_INT_H_ */

/**
 * @file NVIC_prog.c
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief GPIO Driver Functions Implementaion
 * It conatins both functions and APIs implementation.
 * @version 0.1
 * @date 12-07-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */
#include "NVIC_int.h"
#include "NVIC_priv.h"

/**
 * @brief This function sets the enable bit of a peripheral IRQ (unmasking)
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorSetEnable(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* set bit. ISER is Read Set (rs) register, writing 0 has no effect */
    NVIC->ISER[Reg_Idx] = 1 << Bit_Idx;

    return OK;
}

/**
 * @brief This function clears the enable bit of a peripheral IRQ (masking)
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorClearEnable(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* set bit. ICER is Read Set (rs) register, writing 0 has no effect */
    NVIC->ICER[Reg_Idx] = 1 << Bit_Idx;

    return OK;
}

/**
 * @brief This function gets the value of the enable bit of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Enable bit value
 */
uint_8 NVIC_uint_8GetEnableStatus(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* return the corresponding bit in ISER */
    return (uint_8)(NVIC->ISER[Reg_Idx],Bit_Idx);
}

/**
 * @brief This Function sets the pendeing flag of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorSetPending(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* set bit. ISPR is Read Set (rs) register, writing 0 has no effect */
    NVIC->ISPR[Reg_Idx] = 1 << Bit_Idx;

    return OK;
}

/**
 * @brief This Function clears the pendeing flag of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorClearPending(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* set bit. ICPR is Read Set (rs) register, writing 0 has no effect */
    NVIC->ICPR[Reg_Idx] = 1 << Bit_Idx;

    return OK;
}

/**
 * @brief This function returns the penging flag status of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Pending flag status
 */
uint_8 NVIC_uint_8GetPendingStatus(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* return the corresponding bit in ISPR */
    return (uint_8)(NVIC->ISPR[Reg_Idx], Bit_Idx);
}

/**
 * @brief This function returns the active flag status of a peripheral ISR
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Active flag status
 */
uint_8 NVIC_uint_8GetActiveStatus(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* Decode input */
    uint_8 Reg_Idx = Perpheral_Reg(PeripheralIdx_cpy);
    uint_8 Bit_Idx = Prepheral_Bit(PeripheralIdx_cpy);
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* return the corresponding bit in IAPR */
    return (uint_8)(NVIC->IABR[Reg_Idx], Bit_Idx);
}

/**
 * @brief This function triggers the IRQ of a aperipheral by Software (Simulates an IRQ)
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorTriggerSoftwareInterrupt(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));

    /* set bit. ICPR is Read Set (rs) register, writing 0 has no effect */
    NVIC->STIR = PeripheralIdx_cpy;

    return OK;
}

/**
 * @brief This function sets the priority of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @param Prio_cpy : priority value (8-bit value) 
 *                   Range:[0x00(000), 0x10(016), 0x20(032), 0x30(048), 0x40(064), 0x50(080),
 *                          0x60(096), 0x70(112), 0x80(128), 0x90(144), 0xA0(160), 0xB0(176),
 *                          0xC0(192), 0xD0(208), 0xE0(224), 0xF0(240)]
 *                          any level in between will be floored. 
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorSetPriority(NVIC_PeripheralIdx_t PeripheralIdx_cpy, uint_8 Prio_cpy)
{
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));
    assert_param(IS_VALID_PRIO(Prio_cpy));

    NVIC->IPR[PeripheralIdx_cpy] = Prio_cpy;

    return OK;
}

/**
 * @brief This function returns the priority level of an IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Priority Level
 */
uint_8 NVIC_uint_8GetPriority(NVIC_PeripheralIdx_t PeripheralIdx_cpy)
{
    /* assert input */
    assert_param(IS_VALID_IDX(PeripheralIdx_cpy));
    return NVIC->IPR[PeripheralIdx_cpy];
}

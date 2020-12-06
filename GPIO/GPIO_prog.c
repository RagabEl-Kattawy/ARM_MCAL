/**
 * @file GPIO_prog.c
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief GPIO Driver Functions Implementaion
 * It conatins both functions and APIs implementation.
 * @version 0.1
 * @date 11-02-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */



#include "GPIO_int.h"
#include "GPIO_priv.h"

volatile GPIO_Reg_t *GPIO_PortArr[] = {GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_F, GPIO_G};
/**
 * @brief This function sets the pin configuration.
 * 
 * @param PinIdx_cpy Pin index from GPIO_Pin_t enum.
 * @param PinCfg_cpy Pin configuration from GPIO_PinCfg_t enum.
 * @param PinSpeed_cpy Pin maximum switching speed from GPIO_PinSpeed_t.
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t GPIO_ErrorConfigurePin(GPIO_Pin_t PinIdx_cpy, GPIO_PinCfg_t PinCfg_cpy, GPIO_PinSpeed_t PinSpeed_cpy)
{
    /* decode pin index */
    uint_32 PortIdx = PinIdx_cpy / GPIO_PORT_PIN_DECODER;
    uint_32 PinPos = PinIdx_cpy % GPIO_PORT_PIN_DECODER;
    uint_32 PinConf = DECODE_CONF(PinCfg_cpy,PinSpeed_cpy);

    assert_param(IS_BIN_IDX(PinIdx_cpy));
    assert_param(IS_CONF(PinCfg_cpy));
    assert_param(IS_SPEED(PinSpeed_cpy));

    /* make sure that the pin isn't locked */
    if (GET_BIT(GPIO_PortArr[PortIdx]->LCKR, GPIO_LCKR_LCKK) || GET_BIT(GPIO_PortArr[PortIdx]->LCKR, PinPos))
    {
        return NOK;
    }
    else
    {
        /* code */
    }

    /* check for the proper register */
    if (PinPos < GPIO_HIGH_REG)
    {
        PinPos <<= GPIO_CONF_DECODER;
        /* working with low control register */
        /* mask Bits */
        MASK_WORD(GPIO_PortArr[PortIdx]->CRL,GPIO_CONF_MASK,PinPos);
        /* set bits */
        SET_MASKED(GPIO_PortArr[PortIdx]->CRL,PinConf,PinPos);
    }
    else if (PinPos >= GPIO_HIGH_REG)
    {
        PinPos -= GPIO_HIGH_REG;
        PinPos <<= GPIO_CONF_DECODER;
        /* working with high control register */
        /* mask Bits */
        MASK_WORD(GPIO_PortArr[PortIdx]->CRH,GPIO_CONF_MASK,PinPos);
        /* set bits */
        SET_MASKED(GPIO_PortArr[PortIdx]->CRH,PinConf,PinPos);
    }
    else
    {
        /* return not ok */
        return NOK;
    }
    return OK;
} 

/**
 * @brief This function drives an output pin according to the value passed to it.
 * 
 * @param PinIdx_cpy Pin index from GPIO_Pin_t enum.
 * @param PinOutValue_cpy Output data to be driven on pin.
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t GPIO_ErrorDrivePin(GPIO_Pin_t PinIdx_cpy, GPIO_PinData_t PinOutValue_cpy)
{

    /* decode pin index */
    uint_32 PortIdx = PinIdx_cpy / GPIO_PORT_PIN_DECODER;
    uint_32 PinPos = PinIdx_cpy % GPIO_PORT_PIN_DECODER;
    assert_param(IS_BIN_IDX(PinIdx_cpy));
    /* check for the proper register */
    switch (PinOutValue_cpy)
    {
    /* Drive the pin */
    case GPIO_HIGH:
        /* Writing zero on BSRR has no effect & BSRR is write only register */
        GPIO_PortArr[PortIdx]->BSRR = (1 << PinPos);
        break;
    /* Drive the pin */
    case GPIO_LOW:
        /* Writing zero on BRR has no effect & BRR is write only register */
        GPIO_PortArr[PortIdx]->BRR = (1 << PinPos);
        break;

    default:
        return NOK;
    }
    return OK;
    
} 

/**
 * @brief This function reads an input or output pin value
 * 
 * @param PinIdx_cpy Pin index from GPIO_Pin_t enum.
 * @return uint_8 Indecates if an error happend during driving a pin.
 */
uint_8 GPIO_uint_8_ReadPin(GPIO_Pin_t PinIdx_cpy)
{

    /* decode pin index */
    uint_32 PortIdx = PinIdx_cpy / GPIO_PORT_PIN_DECODER;
    uint_32 PinPos = PinIdx_cpy % GPIO_PORT_PIN_DECODER;
    assert_param(IS_BIN_IDX(PinIdx_cpy));
    /* check for the proper register */
    return (uint_8)(GET_BIT(GPIO_PortArr[PortIdx]->IDR,PinPos));
    /* read the pin */  
}


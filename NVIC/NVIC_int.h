/**
 * @file NVIC_int.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief The interface file (should be included in any file using NVIC APIs) 
 * @version 0.1
 * @date 12-07-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */
#ifndef NVIC_INT_H_
#define NVIC_INT_H_

#include "lib/STD_types.h"
#include "lib/BIT_math.h"
#include "lib/ASSERT.h"

typedef enum NVIC_PeripheralIdx
{
    NVIC_WWDG = 0x0000,
    NVIC_PVD = 0x0001,
    NVIC_TAMPER = 0x0002,
    NVIC_RTC = 0x0003,
    NVIC_FLASH = 0x0004,
    NVIC_RCC = 0x0005,
    NVIC_EXTI0 = 0x0006,
    NVIC_EXTI1 = 0x0007,
    NVIC_EXTI2 = 0x0008,
    NVIC_EXTI3 = 0x0009,
    NVIC_EXTI4 = 0x000A,
    NVIC_DMA1_CHANNEL1 = 0x000B,
    NVIC_DMA1_CHANNEL2 = 0x000C,
    NVIC_DMA1_CHANNEL3 = 0x000D,
    NVIC_DMA1_CHANNEL4 = 0x000E,
    NVIC_DMA1_CHANNEL5 = 0x000F,
    NVIC_DMA1_CHANNEL6 = 0x0010,
    NVIC_DMA1_CHANNEL7 = 0x0011,
    NVIC_ADC1_2 = 0x0012,
    NVIC_USB_HP_CAN_TX = 0x0013,
    NVIC_USB_LP_CAN_RX0 = 0x0014,
    NVIC_CAN_RX1 = 0x0015,
    NVIC_CAN_SCE = 0x0016,
    NVIC_EXTI9_5 = 0x0017,
    NVIC_TIM1_BRK = 0x0018,
    NVIC_TIM1_UP = 0x0019,
    NVIC_TIM1_TRG_COM = 0x001A,
    NVIC_TIM1_CC = 0x001B,
    NVIC_TIM2 = 0x001C,
    NVIC_TIM3 = 0x001D,
    NVIC_TIM4 = 0x001E,
    NVIC_I2C1_EV = 0x001F,
    NVIC_I2C1_ER = 0x0020,
    NVIC_I2C2_EV = 0x0021,
    NVIC_I2C2_ER = 0x0022,
    NVIC_SPI1 = 0x0023,
    NVIC_SPI2 = 0x0024,
    NVIC_USART1 = 0x0025,
    NVIC_USART2 = 0x0026,
    NVIC_USART3 = 0x0027,
    NVIC_EXTI15_10 = 0x0028,
    NVIC_RTCALARM = 0x0029,
    NVIC_USBWAKEUP = 0x002A,
    NVIC_TIM8_BRK = 0x002B,
    NVIC_TIM8_UP = 0x002C,
    NVIC_TIM8_TRG_COM = 0x002D,
    NVIC_TIM8_CC = 0x002E,
    NVIC_ADC3 = 0x002F,
    NVIC_FSMC = 0x0030,
    NVIC_SDIO = 0x0031,
    NVIC_TIM5 = 0x0032,
    NVIC_SPI3 = 0x0033,
    NVIC_UART4 = 0x0034,
    NVIC_UART5 = 0x0035,
    NVIC_TIM6 = 0x0036,
    NVIC_TIM7 = 0x0037,
    NVIC_DMA2_CHANNEL1 = 0x0038,
    NVIC_DMA2_CHANNEL2 = 0x0039,
    NVIC_DMA2_CHANNEL3 = 0x003A,
    NVIC_DMA2_CHANNEL4_5 = 0x003B
} NVIC_PeripheralIdx_t;

/**
 * @brief This function sets the enable bit of a peripheral IRQ (unmasking)
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorSetEnable(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This function clears the enable bit of a peripheral IRQ (masking)
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorClearEnable(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This function gets the value of the enable bit of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Enable bit value
 */
uint_8 NVIC_uint_8GetEnableStatus(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This Function sets the pendeing flag of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorSetPending(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This Function clears the pendeing flag of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorClearPending(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This function returns the penging flag status of a peripheral IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Pending flag status
 */
uint_8 NVIC_uint_8GetPendingStatus(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This function returns the active flag status of a peripheral ISR
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Active flag status
 */
uint_8 NVIC_uint_8GetActiveStatus(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

/**
 * @brief This function triggers the IRQ of a aperipheral by Software (Simulates an IRQ)
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return Error_t : Indecates if an error happend during configuration
 */
Error_t NVIC_ErrorTriggerSoftwareInterrupt(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

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
Error_t NVIC_ErrorSetPriority(NVIC_PeripheralIdx_t PeripheralIdx_cpy, uint_8 Prio_cpy);

/**
 * @brief This function returns the priority level of an IRQ
 * 
 * @param PeripheralIdx_cpy : Peripheral index from NVIC_PeripheralIdx_t enum
 * @return uint_8 : Priority Level
 */
uint_8 NVIC_uint_8GetPriority(NVIC_PeripheralIdx_t PeripheralIdx_cpy);

#endif /* NVIC_INT_H_ */
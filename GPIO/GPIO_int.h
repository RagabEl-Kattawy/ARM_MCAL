/**
 * @file GPIO_int.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief The interface file (should be included in any file using GPIO APIs)
 * @version 0.1
 * @date 11-02-2020
 *
 * @copyright Ragab Elkattawy (c) 2020
 *
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_

#include "lib/STD_types.h"
#include "lib/BIT_math.h"
#include "lib/ASSERT.h"

typedef enum GPIO_Pin
{
    GPIO_A00 = 0x00,
    GPIO_A01 = 0x01,
    GPIO_A02 = 0x02,
    GPIO_A03 = 0x03,
    GPIO_A04 = 0x04,
    GPIO_A05 = 0x05,
    GPIO_A06 = 0x06,
    GPIO_A07 = 0x07,
    GPIO_A08 = 0x08,
    GPIO_A09 = 0x09,
    GPIO_A10 = 0x0A,
    GPIO_A11 = 0x0B,
    GPIO_A12 = 0x0C,
    GPIO_A13 = 0x0D, /* AF JTAG Default (Reserved) */
    GPIO_A14 = 0x0E, /* AF JTAG Default (Reserved) */
    GPIO_A15 = 0x0f, /* AF JTAG Default (Reserved) */

    GPIO_B00 = 0x10,
    GPIO_B01 = 0x11,
    GPIO_B02 = 0x12,
    GPIO_B03 = 0x13,
    GPIO_B04 = 0x14, /* AF JTAG Default (Reserved) */
    GPIO_B05 = 0x15,
    GPIO_B06 = 0x16,
    GPIO_B07 = 0x17,
    GPIO_B08 = 0x18,
    GPIO_B09 = 0x19,
    GPIO_B10 = 0x1A,
    GPIO_B11 = 0x1B,
    GPIO_B12 = 0x1C,
    GPIO_B13 = 0x1D,
    GPIO_B14 = 0x1E,
    GPIO_B15 = 0x1F,

    GPIO_C00 = 0x20,
    GPIO_C01 = 0x21,
    GPIO_C02 = 0x22,
    GPIO_C03 = 0x23,
    GPIO_C04 = 0x24,
    GPIO_C05 = 0x25,
    GPIO_C06 = 0x26,
    GPIO_C07 = 0x27,
    GPIO_C08 = 0x28,
    GPIO_C09 = 0x29,
    GPIO_C10 = 0x2A,
    GPIO_C11 = 0x2B,
    GPIO_C12 = 0x2C,
    GPIO_C13 = 0x2D,
    GPIO_C14 = 0x2E,
    GPIO_C15 = 0x2F,

    GPIO_D00 = 0x30,
    GPIO_D01 = 0x31,
    GPIO_D02 = 0x32,
    GPIO_D03 = 0x33,
    GPIO_D04 = 0x34,
    GPIO_D05 = 0x35,
    GPIO_D06 = 0x36,
    GPIO_D07 = 0x37,
    GPIO_D08 = 0x38,
    GPIO_D09 = 0x39,
    GPIO_D10 = 0x3A,
    GPIO_D11 = 0x3B,
    GPIO_D12 = 0x3C,
    GPIO_D13 = 0x3D,
    GPIO_D14 = 0x3E,
    GPIO_D15 = 0x3F,

    GPIO_E00 = 0x40,
    GPIO_E01 = 0x41,
    GPIO_E02 = 0x42,
    GPIO_E03 = 0x43,
    GPIO_E04 = 0x44,
    GPIO_E05 = 0x45,
    GPIO_E06 = 0x46,
    GPIO_E07 = 0x47,
    GPIO_E08 = 0x48,
    GPIO_E09 = 0x49,
    GPIO_E10 = 0x4A,
    GPIO_E11 = 0x4B,
    GPIO_E12 = 0x4C,
    GPIO_E13 = 0x4D,
    GPIO_E14 = 0x4E,
    GPIO_E15 = 0x4f,

    GPIO_F00 = 0x50,
    GPIO_F01 = 0x51,
    GPIO_F02 = 0x52,
    GPIO_F03 = 0x53,
    GPIO_F04 = 0x54,
    GPIO_F05 = 0x55,
    GPIO_F06 = 0x56,
    GPIO_F07 = 0x57,
    GPIO_F08 = 0x58,
    GPIO_F09 = 0x59,
    GPIO_F10 = 0x5A,
    GPIO_F11 = 0x5B,
    GPIO_F12 = 0x5C,
    GPIO_F13 = 0x5D,
    GPIO_F14 = 0x5E,
    GPIO_F15 = 0x5f,

    GPIO_G00 = 0x60,
    GPIO_G01 = 0x61,
    GPIO_G02 = 0x62,
    GPIO_G03 = 0x63,
    GPIO_G04 = 0x64,
    GPIO_G05 = 0x65,
    GPIO_G06 = 0x66,
    GPIO_G07 = 0x67,
    GPIO_G08 = 0x68,
    GPIO_G09 = 0x69,
    GPIO_G10 = 0x6A,
    GPIO_G11 = 0x6B,
    GPIO_G12 = 0x6C,
    GPIO_G13 = 0x6D,
    GPIO_G14 = 0x6E,
    GPIO_G15 = 0x6F
} GPIO_Pin_t;

typedef enum GPIO_PinCfg
{
    GPIO_OUT_PP     = 0x00,
    GPIO_OUT_OD     = 0x01,
    GPIO_AF_PP      = 0x02,
    GPIO_AF_OD      = 0x03,
    GPIO_IN_ANALOG  = 0x04,
    GPIO_IN_FLOAT   = 0x05,
    GPIO_IN_PD      = 0x06,
    GPIO_IN_PU      = 0x16
}GPIO_PinCfg_t;

typedef enum GPIO_PinData
{
    GPIO_HIGH       = 0x01,
    GPIO_LOW        = 0x00
}GPIO_PinData_t;

typedef enum GPIO_PinSpeed
{
    GPIO_SPEED_IN    = 0x00,
    GPIO_SPEED_10MHZ = 0x01,
    GPIO_SPEED_2MHZ  = 0x02,
    GPIO_SPEED_50MHZ = 0x03
}GPIO_PinSpeed_t;


/**
 * @brief This function sets the pin configuration.
 *
 * @param PinIdx_cpy Pin index from GPIO_Pin_t enum.
 * @param PinCfg_cpy Pin configuration from GPIO_PinCfg_t enum.
 * @param PinSpeed_cpy Pin maximum switching speed from GPIO_PinSpeed_t.
 * @return Error_t Indecates if an error happend during configuration.
 */
Error_t GPIO_ErrorConfigurePin(GPIO_Pin_t PinIdx_cpy, GPIO_PinCfg_t PinCfg_cpy, GPIO_PinSpeed_t PinSpeed_cpy); // make sure that the pin isn't locked

/**
 * @brief This function drives an output pin according to the value passed to it.
 *
 * @param PinIdx_cpy Pin index from GPIO_Pin_t enum.
 * @param PinOutValue_cpy Output data to be driven on pin.
 * @return Error_t Indecates if an error happend during driving a pin.
 */
Error_t GPIO_ErrorDrivePin(GPIO_Pin_t PinIdx_cpy, GPIO_PinData_t PinOutValue_cpy); // make sure that the pin isn't locked

/**
 * @brief This function reads an input or output pin value.
 *
 * @param PinIdx_cpy Pin index from GPIO_Pin_t enum.
 * @return uint_8 Indecates if an error happend during driving a pin.
 */
uint_8 GPIO_uint_8_ReadPin(GPIO_Pin_t PinIdx_cpy);

#endif /* GPIO_INT_H_ */

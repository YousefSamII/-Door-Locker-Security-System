/* ================================================================
 * Module Name: 24C16 EEPROM
 *
 * File Name: External_EEPROM.h
 *
 * Description: Header file for 24C16 EEPROM driver
 *
 * Author: Yousef Samy
 *
 * Date: 23/06/2023
 * ================================================================*/
#include "External_EEPROM.h"
#include "TWI.h"
/*
 * Function Name: EEPROM_writeByte()
 * Description:	write data into external EEPROM
 */
uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data)
{
	/* Send the Start Bit */
    TWI_Start();
    if (TWI_readStatus() != TWI_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_writeByte((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));
    if (TWI_readStatus() != TWI_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_writeByte((uint8)(u16addr));
    if (TWI_readStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* write byte to eeprom */
    TWI_writeByte(u8data);
    if (TWI_readStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_Stop();

    return SUCCESS;
}

uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data)
{
	/* Send the Start Bit */
    TWI_Start();
    if (TWI_readStatus() != TWI_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_writeByte((uint8)((0xA0) | ((u16addr & 0x0700)>>7)));
    if (TWI_readStatus() != TWI_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_writeByte((uint8)(u16addr));
    if (TWI_readStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* Send the Repeated Start Bit */
    TWI_Start();
    if (TWI_readStatus() != TWI_REP_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    TWI_writeByte((uint8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));
    if (TWI_readStatus() != TWI_MT_SLA_R_ACK)
        return ERROR;

    /* Read Byte from Memory without send ACK */
    *u8data = TWI_readByteWithNACK();
    if (TWI_readStatus() != TWI_MR_DATA_NACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_Stop();

    return SUCCESS;
}

/* ================================================================
 * Module Name: Two Wire Interface (TWI)
 *
 * File Name: TWI.c
 *
 * Description: Source file for TWI driver
 *
 * Author: Yousef Samy
 *
 * Date: 23/06/2023
 * ================================================================*/
#include "TWI.h"
#include "MACROS.h"
#include <avr/io.h>			/*For use TWI's Registers*/

/*
 * Function Name : TWI_init()
 * Description	 : Initialize to TWI driver
 */
void TWI_init(const TWI_ConfigType *Config_Ptr)
{
	/* Select Baud Rate*/
	TWBR = Config_Ptr->BAUD_RATE;
	/*Enable Module*/
	TWCR |= (1<<TWEN);
	/**********************************************
	 * 1.Prescaler used in equation of baud rate = 0
	 * 2.Status bits = 0 , because ,they are read only
	 **********************************************/
	TWSR =0x00;
	/**********************************************************************************
	 * 1.Select address , Note 7-bit address in the seven most significant bits of TWAR
	 * 2.Disable recognition of the general call address
	 **********************************************************************************/
	TWAR = (TWAR & 0x00) | (Config_Ptr->Address << 1);
}
/*
 * Function Name : TWI_Start()
 * Description	 : send Start Condition
 */
void TWI_Start(void)
{
    /*************************************************************
	 * 1.Clear the TWINT flag before sending the start bit TWINT=1
	 * 2.send the start bit by TWSTA=1
	 * 3.Enable TWI Module TWEN=1
	 *************************************************************/
	TWCR = (1<<TWINT) | (1<<TWEN)  | (1<<TWSTA);

	/* wait for flag set */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
/*
 * Function Name : TWI_Stop()
 * Description	 : send Stop Condition
 */
void TWI_Stop(void)
{
    /*************************************************************
	 * 1.Clear the TWINT flag before sending the start bit TWINT=1
	 * 2.send the start bit by TWSTO=1
	 * 3.Enable TWI Module TWEN=1
	 *************************************************************/
	TWCR = (1<<TWINT) | (1<<TWEN)  | (1<<TWSTO);

}
/*
 * Function Name : TWI_writeByte()
 * Description	 : send data using TWI
 */
void TWI_writeByte(uint8 data)
{
	/* Move Data to TWDR register*/
	TWDR =data;
    /*************************************************************
	 * 1.Clear the TWINT flag before sending the start bit TWINT=1
	 * 2.Enable TWI Module TWEN=1
	 *************************************************************/
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* wait for flag set */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
/*
 * Function Name : TWI_readByteWithACK()
 * Description:  return a byte with ACK bit (0)
 */
uint8 TWI_readByteWithACK(void)
{
	/*************************************************************
	 * 1.Clear the TWINT flag before reading the data TWINT=1
	 * 2.Enable sending ACK after reading or receiving data TWEA=1
	 * 3.Enable TWI Module TWEN=1
	 **************************************************************/
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
/*
 * Function Name : TWI_readByteWithNACK()
 * Description:  return a byte with No ACK bit ---idle state =1
 */
uint8 TWI_readByteWithNACK(void)
{
	/*****************************************************
	 * 1.Clear the TWINT flag before reading the data TWINT=1
	 * 2.Enable TWI Module TWEN=1
	 *****************************************************/
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
uint8 TWI_readStatus(void)
{
	uint8 status;
	/* Get only last 5 bits*/
    status = TWSR & 0xF8;
    return status;
}


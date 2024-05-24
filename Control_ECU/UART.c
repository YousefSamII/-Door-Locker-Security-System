/* ================================================================
 * Module Name: Uart
 *
 * File Name: UART.c
 *
 * Description: Source file for uart driver
 *
 * Author: Yousef Samy
 *
 * Date: 20/06/2023
 * ================================================================*/
#include "UART.h"
#include "MACROS.h"
#include <avr/io.h>				/*For Use UART Regs in AVR*/

/*
 * Function Name : UART_init()
 * Description   : initialization uart driver
 */
void UART_init(const UART_ConfigType * Config_ptr)
{
	uint16 baudRate_value=0;
	UCSRA |=(1<<U2X);				/*Double Transmission Speed*/
	UCSRB= (1<<RXEN) | (1<<TXEN);	/* Enable Reciever and transmitter*/
	/*For 9-bit Mode*/
	if(Config_ptr->bitData==Bit_9)
	{
		UCSRB |= (1<<UCSZ2) | (1<<RXB8) | (1<<TXB8);	/* specific for 9 bit data in AVR family*/
	}
	UCSRC |= (1<<URSEL);			/* To write in UCSRC register*/
	/* insert parity bit choice*/
	UCSRC =(UCSRC & 0xC1) | ((Config_ptr->parity) << 4) ;
	/* Choose stop bit*/
	if(Config_ptr->stopBit ==OneBit)
	{
		UCSRC &=~(1<<USBS);
	}
	else if(Config_ptr->stopBit ==TwoBit)
	{
		UCSRC |= (1<<USBS);
	}
	/*configurate data bits*/
	UCSRC |=(GET_BIT(Config_ptr->bitData , 0)<<1) | (GET_BIT(Config_ptr->bitData,1)<<2);

	baudRate_value= ((uint32)F_CPU/(8*Config_ptr->baudRate)) -1 ;	/*Equation to calculate BaudRate in Double speed Mode*/
	/* LSB 8 bits*/
	UBRRL=(uint8)baudRate_value;
	/* MSB 8 bits*/
	UBRRH = (UBRRH & 0x70) | (baudRate_value>>8);
}
/*
 * Function Name: UART_recieveByte()
 * Description  : recieve byte from another uart , read UDR
 */
uint8 UART_recieveByte(void)
{
	/* wait until Clear reciever flag, refering to no data in recieve buffer*/
	while(BIT_IS_CLEAR(UCSRA,RXC));
	/* Read byte from UDR*/
	return UDR;
}
/*
 * Function Name :UART_sendByte()
 * Description   : take data and send it to another uart driver
 */
void UART_sendByte(uint8 data)
{
	/* wait until Clear data register flag, refering to no data in transmitter buffer*/
	while(BIT_IS_CLEAR(UCSRA,UDRE));
	/* passing data to UDR register to read it */
	UDR=data;
}
/*
 * Function Name : UART_sendString()
 * Description   : Send a string using UART
 */
void UART_sendString(const uint8* Str)		/* Const, because it makes no any changes in string , just send it*/
{
	uint8 i=0;
	/* send until null character*/
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}
/*
 * Function Name :UART_recieveString()
 * Description   : recieve string from uart , with agreement by a specific character
 */
void UART_recieveString(uint8 *Str)
{
	uint8 i=0;
	/* get first byte*/
	Str[i]=UART_recieveByte();
	/* choose a specific character '#'*/
	while(Str[i] != '#')
	{
		i++;
		Str[i]=UART_recieveByte();
	}
	/* insert null character to string */
	Str[i]='\0';
}

/* ================================================================
 * Module Name: Uart
 *
 * File Name: UART.h
 *
 * Description: Header file for uart driver
 *
 * Author: Yousef Samy
 *
 * Date: 20/06/2023
 * ================================================================*/
#ifndef UART_H_
#define UART_H_
#include "standard_types.h"
/*******************************************************************
 * 					Definitions
 *******************************************************************/
#define F_CPU		8000000

/* parity bit*/
typedef enum{
		Disabled , Even=2 ,Odd
}UART_Parity;

/*Stop bit */
typedef enum{
	OneBit , TwoBit
}UART_StopBit;

/* Data bits*/
typedef enum{
	Bit_5 , Bit_6 , Bit_7 , Bit_8 , Bit_9=7
}UART_BitData;

/* Struct configuration for UART*/
typedef struct{
	UART_Parity parity;
	UART_StopBit stopBit;
	UART_BitData bitData;
	uint32 baudRate;
}UART_ConfigType;

/*******************************************************************
 * 					Prototypes
 *******************************************************************/
void UART_init(const UART_ConfigType * Config_ptr);
uint8 UART_recieveByte(void);
void UART_sendByte(uint8 data);
void UART_sendString(const uint8* Str);
void UART_recieveString(uint8 *Str);
#endif /* UART_H_ */

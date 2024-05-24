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

#ifndef TWI_H_
#define TWI_H_
#include "standard_types.h"
/****************************************************************
 * 						Definitions								*
 ****************************************************************/
typedef struct{

	uint8 BAUD_RATE;
	uint8 Address;
}TWI_ConfigType;

/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */
/****************************************************************
 * 						Prototypes								*
 ****************************************************************/
void TWI_init(const TWI_ConfigType *Config_Ptr);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readByteWithACK(void);
uint8 TWI_readByteWithNACK(void);
uint8 TWI_readStatus(void);

#endif /* TWI_H_ */

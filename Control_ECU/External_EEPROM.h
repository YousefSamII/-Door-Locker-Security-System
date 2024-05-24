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

#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_
#include "standard_types.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);

#endif /* EXTERNAL_EEPROM_H_ */

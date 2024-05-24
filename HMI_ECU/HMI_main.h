/* =====================================================================
 * File Name: HMI_main.h
 *
 * Description: Header file of main for Human machine interface
 *
 * Author: Yousef Samy
 *
 * Date: 20/06/2023
 * =====================================================================*/

#ifndef HMI_MAIN_H_
#define HMI_MAIN_H_
#include "standard_types.h"
/*************************************************************************
 * 						Function Prototypes
 *************************************************************************/
void recieveCheckingPass(void);
void mainOptions(void);
void systemRun(void);
void insertNewPassword(void);
void getUserPass(void);
void myOwnDelay(uint16 sec);
void openDoorDisplay(void);
void timerTicks(void);

/*************************************************************************
 * 						Definitions
 *************************************************************************/
#define MC2_GET_READY 					0xFF
#define PASS_IS_TRUE  					0x10
#define PASS_IS_FALSE 					0x01
#define MC2_READY_TO_GET_USER_PASS	    0xee
#define USER_PASS_IS_TRUE 				0x17
#define USER_PASS_IS_FALSE				0x16
#define  MC2_WILL_SEND_CHECK			0x20
#define  PASS_SIZE						5
#define  CHECK_USER_PASS    			0x55
/*************************************************************************
 * 							Global Variables
 *************************************************************************/
uint8 userChoice;
uint8 key;
uint8 failedAttemp=0;
uint8 equality_flag=0;
uint8 numOfPass_flag=0;



#endif /* HMI_MAIN_H_ */

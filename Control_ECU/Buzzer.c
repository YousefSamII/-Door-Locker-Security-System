/* ==================================================================
 * Module: Buzzer Driver
 *
 * File Name: Buzzer.c
 *
 * Description: Source File for Buzzer driver.
 *
 * Author: Yousef Samy
 *
 * Date: 20/06/2023
 * ====================================================================*/

#include "Buzzer.h"
#include "GPI0.h"

/*
 * Function Name: BUZZER_init
 * Description: Setup Buzzer_pin as output pin  and turn off the buzzer
 */
void BUZZER_init(void)
{
	/* Make BuzzerPin as output pin*/
	GPIO_setupPinDirection(BUZZER_PORT , BUZZER_PIN , OUTPUT_PIN);
	/* Buzzer of at first*/
	GPIO_writePin(BUZZER_PORT , BUZZER_PIN , LOGIC_LOW);
}

/*
 * Function Name: BUZZER_On()
 * Description :  enable the Buzzer through the GPIO
 */
void BUZZER_On(void)
{
	GPIO_writePin(BUZZER_PORT , BUZZER_PIN , LOGIC_HIGH);
}
/*
 * Function Name: BUZZER_Off()
 * Description:  disable the Buzzer through the GPIO.
 */
void BUZZER_Off(void)
{
	GPIO_writePin(BUZZER_PORT , BUZZER_PIN , LOGIC_LOW);
}

/*
 * led.h
 *
 * Created: 4/9/2023 8:54:47 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef LED_H_
#define LED_H_
/*****************************************************************************/
#include "../../MCAL/dio/dio_interface.h"
/*****************************************************************************/
//LED MACROS
/*****************************************************************************/
//LED Port Numbers
#define LED0_PORT A
#define LED1_PORT A
#define LED2_PORT A
#define LED3_PORT A
//LED Pin Numbers
#define LED0_PIN 0
#define LED1_PIN 1
#define LED2_PIN 2
#define LED3_PIN 3
//LED OUTPUTS
#define ON 1
#define OFF 0
/*****************************************************************************/
//LED APIs:
/*****************************************************************************/
extern u8 LED_init (u8 port, u8 pin);
extern u8 LED_on (u8 port, u8 pin);
extern u8 LED_off (u8 port, u8 pin);
extern u8 LED_toggle (u8 port, u8 pin);
/*****************************************************************************/



#endif /* LED_H_ */
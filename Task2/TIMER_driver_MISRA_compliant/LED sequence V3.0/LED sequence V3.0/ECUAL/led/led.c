/*
 * led.c
 *
 * Created: 4/9/2023 8:55:14 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "led.h"

void LED_init (u8 port, u8 pin){
	DIO_init(port,pin,OUT);
}
void LED_on (u8 port, u8 pin){
	DIO_write(port,pin,HIGH);
}
void LED_off (u8 port, u8 pin){
	DIO_write(port,pin,LOW);
}
void LED_toggle (u8 port, u8 pin){
	DIO_toggle(port,pin);
}
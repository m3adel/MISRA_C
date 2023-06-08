/*
 * led.c
 *
 * Created: 4/9/2023 8:55:14 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "led.h"

u8 LED_init (u8 port, u8 pin)
{
	return DIO_init(port,pin,OUT);
}
u8 LED_on (u8 port, u8 pin)
{
	return DIO_write(port,pin,HIGH);
}
u8 LED_off (u8 port, u8 pin)
{
	return DIO_write(port,pin,LOW);
}
u8 LED_toggle (u8 port, u8 pin)
{
	return DIO_toggle(port,pin);
}
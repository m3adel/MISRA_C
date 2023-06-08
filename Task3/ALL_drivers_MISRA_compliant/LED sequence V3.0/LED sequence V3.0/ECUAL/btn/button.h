/*
 * button.h
 *
 * Created: 4/9/2023 9:10:06 AM
 *  Author: MOHAMED ABDELSALAM
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/dio/dio_interface.h"
//BUTTON Pin Numbers
#define BUTTON0_PORT A
#define BUTTON0_PIN 7
extern u8 BUTTON_init (u8 buttonport, u8 buttonpin);
extern u8 BUTTON_read (u8 buttonport, u8 buttonpin, boolean *value);
#endif /* BUTTON_H_ */
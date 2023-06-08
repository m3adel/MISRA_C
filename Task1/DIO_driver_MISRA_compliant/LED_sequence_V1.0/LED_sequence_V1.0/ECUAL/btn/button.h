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
#define BUTTON0_PORT D
#define BUTTON0_PIN 6
void BUTTON_init (u8 buttonport, u8 buttonpin);
void BUTTON_read (u8 buttonport, u8 buttonpin, boolean *pbool_a_value);
#endif /* BUTTON_H_ */
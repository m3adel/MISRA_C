/*
 * button.c
 *
 * Created: 4/9/2023 9:10:35 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "button.h"
u8 BUTTON_init (u8 buttonport, u8 buttonpin){
	return DIO_init(buttonport,buttonpin,IN);
}
u8 BUTTON_read (u8 buttonport, u8 buttonpin, boolean *value){
	return DIO_read(buttonport,buttonpin,value);
}
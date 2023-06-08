/*
 * button.c
 *
 * Created: 4/9/2023 9:10:35 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "button.h"
void BUTTON_init (u8 buttonport, u8 buttonpin){
	DIO_init(buttonport,buttonpin,IN);
}
void BUTTON_read (u8 buttonport, u8 buttonpin, boolean *value){
	DIO_read(buttonport,buttonpin,value);
}
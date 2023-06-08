/*
 * LED sequence V3.0.c
 *
 * Created: 4/15/2023 11:14:30 PM
 * Author : MOHAMED ABDELSALAM
 */ 

#include "APPLICATION/application.h"


int main(void)
{
	if (APP_init() == true)
	{
		//Initialization Done 
	}
	else
	{
		//ALL LEDS will be ON For error visualization
		while(1)
		{
			LED_on(LED0_PORT,LED0_PIN);
			LED_on(LED1_PORT,LED1_PIN);
			LED_on(LED2_PORT,LED2_PIN);
			LED_on(LED3_PORT,LED3_PIN);
		}
	}	
	 
    while (1) 
    {
		APP_start();
    }
	return 0;
}


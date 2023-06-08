/*
 * application.c
 *
 * Created: 4/11/2023 4:51:29 AM
 *  Author: MOHAMED ABDELSALAM
 */ 

#include "application.h"

void APP_init(void)
{
		LED_init(LED0_PORT,LED0_PIN);
		LED_init(LED1_PORT,LED1_PIN);
		LED_init(LED2_PORT,LED2_PIN);
		LED_init(LED3_PORT,LED3_PIN);
		BUTTON_init (BUTTON0_PORT, BUTTON0_PIN);	
	
}
void APP_start()
{
		boolean Check;
		static u8 Counter = 0;
		BUTTON_read (BUTTON0_PORT, BUTTON0_PIN, &Check);
		while (Check==false)
		{
			BUTTON_read (BUTTON0_PORT, BUTTON0_PIN, &Check);	
		}
		while (Check==true)
		{
			BUTTON_read (BUTTON0_PORT, BUTTON0_PIN, &Check);
		}
		(Counter)++;
		if (Counter==8){
			Counter = 0;
		}
		switch(Counter)
		{
			case 0:
			LED_off(LED0_PORT,LED0_PIN);
			LED_off(LED1_PORT,LED1_PIN);
			LED_off(LED2_PORT,LED2_PIN);
			LED_off(LED3_PORT,LED3_PIN);			
			break;
			case 1:
			LED_on(LED0_PORT,LED0_PIN);
			break;
			case 2:
			LED_on(LED1_PORT,LED1_PIN);
			break;
			case 3:
			LED_on(LED2_PORT,LED2_PIN);
			break;
			case 4:
			LED_on(LED3_PORT,LED3_PIN);
			break;
			case 5:
			LED_off(LED0_PORT,LED0_PIN);
			break;
			case 6:
			LED_off(LED1_PORT,LED1_PIN);
			break;
			case 7:
			LED_off(LED2_PORT,LED2_PIN);
			break;					
		
		}
}
void APP_stop(void){
				LED_off(LED0_PORT,LED0_PIN);
				LED_off(LED1_PORT,LED1_PIN);
				LED_off(LED2_PORT,LED2_PIN);
				LED_off(LED3_PORT,LED3_PIN);
}

/*
 * application.c
 *
 * Created: 4/11/2023 4:51:29 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#include "application.h"



#define number_of_blink_states 4
u8 state_number = 0;
u8 blink_state = 0;

u16 blink_states[5] = {10,20,30,50,80};

void EX_INT0_ISR (void)
{
	if (state_number < number_of_states){
		state_number++;
		
	}
	else{
		state_number =0;
	}

}

void EX_INT1_ISR (void)
{
	if (state_number < number_of_blink_states){
		blink_state++;
			
	}
	else{
		blink_state =0;
	}
	
}
void PWM_gen(void)
{
	PWM_Count++;
	if (PWM_Count==PWM_count_OFF)
	{
		switch(select_pwm)
		{
			case 0:
			
			LED_off(LED0_PORT,LED0_PIN);
			LED_off(LED1_PORT,LED1_PIN);
			LED_off(LED2_PORT,LED2_PIN);
			LED_off(LED3_PORT,LED3_PIN);
			break;
			case 1:
			LED_on(LED0_PORT,LED0_PIN);
			LED_off(LED1_PORT,LED1_PIN);
			LED_off(LED2_PORT,LED2_PIN);
			LED_off(LED3_PORT,LED3_PIN);
			break;
			case 2:			
			LED_on(LED0_PORT,LED0_PIN);
			LED_on(LED1_PORT,LED1_PIN);
			LED_off(LED2_PORT,LED2_PIN);
			LED_off(LED3_PORT,LED3_PIN);
			break;
			case 3:
			LED_on(LED0_PORT,LED0_PIN);
			LED_on(LED1_PORT,LED1_PIN);
			LED_on(LED2_PORT,LED2_PIN);
			LED_off(LED3_PORT,LED3_PIN);
			break;
			case 4:
			LED_on(LED0_PORT,LED0_PIN);
			LED_on(LED1_PORT,LED1_PIN);
			LED_on(LED2_PORT,LED2_PIN);
			LED_on(LED3_PORT,LED3_PIN);
			break;
			case 5:
			LED_off(LED0_PORT,LED0_PIN);
			LED_on(LED1_PORT,LED1_PIN);
			LED_on(LED2_PORT,LED2_PIN);
			LED_on(LED3_PORT,LED3_PIN);
			break;
			case 6:
			LED_off(LED0_PORT,LED0_PIN);
			LED_off(LED1_PORT,LED1_PIN);
			LED_on(LED2_PORT,LED2_PIN);
			LED_on(LED3_PORT,LED3_PIN);
			break;
			case 7:
			LED_off(LED0_PORT,LED0_PIN);
			LED_off(LED1_PORT,LED1_PIN);
			LED_off(LED2_PORT,LED2_PIN);
			LED_on(LED3_PORT,LED3_PIN);
			break;
			default:
			// do nothing
			break;
			
		}
	}
	else if (PWM_Count==(PWM_count_OFF+PWM_count_ON))
	{
		
		LED_off(LED0_PORT,LED0_PIN);
		LED_off(LED1_PORT,LED1_PIN);
		LED_off(LED2_PORT,LED2_PIN);
		LED_off(LED3_PORT,LED3_PIN);
		PWM_Count=0;
	}
	TIMER_set(Intial_value_PWM);
}

void APP_init(void)
{		
		BUTTON_init (EX_INT0_PORT, EX_INT0_PIN);
		BUTTON_init (EX_INT1_PORT, EX_INT1_PIN);	
		EX_INT_init(INT0 , rising_edge);
		EX_INT_init(INT1 , rising_edge);
		EX_INT0_SET_CALLBACK (EX_INT0_ISR);
		EX_INT1_SET_CALLBACK (EX_INT1_ISR);
		TIMER_init (Normal,Intial_value_PWM); // start counting from 6
		Timer0_Ovf_CALLBACK (PWM_gen);
}

void APP_start(void){
	TIMER_PWM_start(blink_states[blink_state]);	
	while(1){
		TIMER_PWM_set ((blink_states[blink_state]) , state_number);
}		
}
void APP_stop(void)
{
	LED_off(LED0_PORT,LED0_PIN);
	LED_off(LED1_PORT,LED1_PIN);
	LED_off(LED2_PORT,LED2_PIN);
	LED_off(LED3_PORT,LED3_PIN);
	EX_INT_Disable(INT0);
	CLI();
}


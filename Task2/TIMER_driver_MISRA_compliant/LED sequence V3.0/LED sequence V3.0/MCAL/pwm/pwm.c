 /*
 * pwm.c
 *
 * Created: 4/6/2023 11:18:12 PM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "pwm.h"
//the global variables
u32 PWM_count_ON=0;
u32 PWM_count_OFF=0;
u32 select_pwm;
u32 PWM_Count=0;

enm_timer_errors_t TIMER_init (u8 Mode,u8 intial_value)
{
	u8 u8_l_ret = TIMER_OKAY;
	if (((Mode >=Normal)==true) && ((Mode <=FAST_PWM)==true))
	{
	
	//choose timer mode
		TCCR0 &= Normal;
		TCCR0 |= Normal;
	SREG |= (1<<I_BIT);//enable global interrupt
	TIMSK |= (1<<TOIE0); //enable interrupt overflow of timer 0
	}
	else
	{
		u8_l_ret = TIMER_MODE_ERROR;
	}
	if (((intial_value >=Intial_value_Zero)==true) && ((intial_value <=Intial_value_255)==true))
	{
		TCNT0 = intial_value;
	}
	else
	{
		u8_l_ret = TIMER_INTIAL_VALUE_ERROR;
	} 
	return u8_l_ret;
}
enm_timer_errors_t TIMER_start (u8 prescaler_value)
{
	u8 u8_l_ret = TIMER_OKAY;
	if (((prescaler_value >=pres_1)==true) && ((prescaler_value <=pres_1024)==true))
	{
		TCCR0 |= prescaler_value;  //Set Pre_scaler
	}
	else
	{
		u8_l_ret = TIMER_PRESCALAR_VALUE_ERROR;
	}
	return u8_l_ret;
}
enm_timer_errors_t TIMER_PWM_start (u8 duty_percent)
{
	u8 u8_l_ret = TIMER_OKAY;
	if (((duty_percent >=0)==true) && ((duty_percent <=100)==true))
	{
		u32 temp=0;
		temp=((f32)1/PWM_F)*((f32)duty_percent/100)*1000*1000;
		PWM_count_ON=temp/250;
		temp=((f32)1/PWM_F)*((f32)(100-duty_percent)/100)*1000*1000;
		PWM_count_OFF=temp/250;
		PWM_Count=0;
		TCNT0=Intial_value_PWM;
		TIMER_start (pres_8);    //Set Pre_scaler, for ex:ck(8MHz)/8 to get:
													//T(tick) = 1 microseconds
													//Stop after one overflow 250 microseconds
	}
	else
	{
		u8_l_ret = TIMER_DUTY_PERCENT_ERROR;
	}
	return u8_l_ret;
}
enm_timer_errors_t TIMER_set(u8 intial_value)
{
	u8 u8_l_ret = TIMER_OKAY;
	if (((intial_value >=Intial_value_Zero)==true) && ((intial_value <=Intial_value_255)==true))
	{
		TCNT0 = intial_value;
	}
	else
	{
		u8_l_ret = TIMER_INTIAL_VALUE_ERROR;
	}
	return u8_l_ret;
}
enm_timer_errors_t TIMER_PWM_set (u8 duty_percent , u8 blinks)
{
		u8 u8_l_ret = TIMER_OKAY;
		if (((blinks >=INTIAL_states)==true) && ((blinks <=number_of_states)==true))
		{
			select_pwm = blinks;
		}
		else
		{
			u8_l_ret = TIMER_BLINKS_ERROR;
		}
		if (((duty_percent >=0)==true) && ((duty_percent <=100)==true))
		{
			u32 temp=0;
			temp=((f32)1/PWM_F)*((f32)duty_percent/100)*1000*1000;
			PWM_count_ON=temp/250;
			temp=((f32)1/PWM_F)*((f32)(100-duty_percent)/100)*1000*1000;
			PWM_count_OFF=temp/250;
		}
		else
		{
			u8_l_ret = TIMER_DUTY_PERCENT_ERROR;
		}
	return u8_l_ret;
}
void TIMER_getStatus(u8 *value){
	if ((TIFR & clear) == 0)
	{
		*value = 0x01;
	}
	else if ((TIFR & clear) == 1)
	{
		*value = 0x00;
		TIFR |= clear;
	}
}
void TIMER_Stop (void){
	//Timer Stop
	TCCR0 = no_clk;
}

	static void (*Callbackptr10) (void) = 0;
	
	void Timer0_Ovf_CALLBACK (void (*copyFuncptr) (void))
	{
		Callbackptr10 = copyFuncptr;
	}
ISR (TIMER0_OVF)
{
	if(Callbackptr10 == 0)
	{
		
	}
	else
	{
		Callbackptr10();
	}
}
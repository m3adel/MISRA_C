/*
 * pwm.h
 *
 * Created: 4/6/2023 11:17:52 PM
 *  Author: MOHAMED ABDELSALAM
 */ 




#ifndef PWM_H_
#define PWM_H_
#include "../../MCAL/external_interrupt/external_interrupt.h"

#define percent_30 30
#define percent_50 50
//pwm output pin
#define LED0_PIN_ 0
#define LED1_PIN_ 1
#define LED2_PIN_ 2
#define LED3_PIN_ 3
//pwm output pin
#define OC0_port 'B'
#define OC0_pin 3
//PWM Modes

#define Normal 0x00
#define FAST_PWM 0x30
//intial values
#define no_clk 0x00
#define Intial_value_PWM 0x06
#define Intial_value_Zero 0x00
#define Intial_value_255 0xFF
//prescaler values
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05
#define clear 0x01
#define INTIAL_states 0
#define number_of_states 7
typedef enum {
	TIMER_OKAY					=	0x00,
	TIMER_MODE_ERROR			=	0XE0,
	TIMER_INTIAL_VALUE_ERROR	=	0XE1,
	TIMER_PRESCALAR_VALUE_ERROR			,
	TIMER_DUTY_PERCENT_ERROR			,
	TIMER_BLINKS_ERROR					
	
} enm_timer_errors_t;

enm_timer_errors_t TIMER_init (u8 Mode,u8 intial_value);
enm_timer_errors_t TIMER_PWM_start (u8 duty_percent);
enm_timer_errors_t TIMER_set(u8 intial_value);
enm_timer_errors_t TIMER_PWM_set (u8 duty_percent , u8 blinks);
void TIMER_getStatus(u8 *value);
void TIMER_Stop (void);
void Timer0_Ovf_CALLBACK (void (*copyFuncptr) (void));

extern u32 PWM_count_ON;
extern u32 PWM_count_OFF;
extern u32 select_pwm;
extern u32 PWM_Count;

#endif /* PWM_H_ */

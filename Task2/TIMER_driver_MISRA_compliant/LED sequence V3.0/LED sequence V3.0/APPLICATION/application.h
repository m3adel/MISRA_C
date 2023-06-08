/*
 * IncFile1.h
 *
 * Created: 4/11/2023 4:50:46 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../ECUAL/btn/button.h"
#include "../ECUAL/led/led.h"
#include "../MCAL/external_interrupt/external_interrupt.h"
#include "../MCAL/pwm/pwm.h"
void APP_init(void);
void APP_start(void);
void APP_stop(void);
void EX_INT0_ISR(void);
void EX_INT1_ISR (void);
void PWM_gen(void);



#endif /* INCFILE1_H_ */
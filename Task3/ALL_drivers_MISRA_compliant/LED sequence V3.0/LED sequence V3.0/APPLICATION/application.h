/*
 * IncFile1.h
 *
 * Created: 4/11/2023 4:50:46 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#define number_of_blink_states 4
#define Done 0x00
#include "../ECUAL/btn/button.h"
#include "../ECUAL/led/led.h"
#include "../MCAL/external_interrupt/external_interrupt.h"
#include "../MCAL/pwm/pwm.h"
extern boolean APP_init(void);
extern void APP_start(void);
extern void APP_stop(void);



#endif /* INCFILE1_H_ */
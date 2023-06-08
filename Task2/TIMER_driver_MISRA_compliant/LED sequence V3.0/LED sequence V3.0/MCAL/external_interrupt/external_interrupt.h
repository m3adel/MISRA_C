/*
 * external_interrupt.h
 *
 * Created: 4/14/2023 12:02:27 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
#include "../../LIB/registers.h"
#include "../../SERVICES/interrupt_serivce.h"
/****************************/

/************************************************************************/
/* APIs                                                                 */
/************************************************************************/
void SIE(void);
void CLI(void);
void INT_SENSE(u8 inerrupt_number,u8 sense);
void EX_INT_Enable(u8 inerrupt_number);
void EX_INT_Disable(u8 inerrupt_number);
void EX_INT_init(u8 interrupt , u8 sense);
void EX_INT0_SET_CALLBACK (void (*copyFuncptr) (void));
void EX_INT1_SET_CALLBACK (void (*copyFuncptr) (void));
void EX_INT2_SET_CALLBACK (void (*copyFuncptr) (void));


/************************************************************************/
/*                       interrupt pins & ports                         */
/************************************************************************/
#define EX_INT0_PORT 'D'
#define EX_INT0_PIN   2
#define EX_INT1_PORT 'D'
#define EX_INT1_PIN   3
#define EX_INT2_PORT 'B'
#define EX_INT2_PIN   2
#endif /* EXTERNAL_INTERRUPT_H_ */
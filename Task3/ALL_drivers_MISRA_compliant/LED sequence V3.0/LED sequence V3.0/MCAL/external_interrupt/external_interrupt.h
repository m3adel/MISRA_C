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
typedef enum {
	EXT_INT_OKAY					=	0x00,
	EXT_INT_INTERRUPT_NUMBER_ERROR	=	0XE0,
	EXT_INT_SENSE_ERROR				=	0XE1,
	EXT_INT_ENABLE_ERROR					
	
} enm_ext_int_errors_t;

/************************************************************************/
/* APIs                                                                 */
/************************************************************************/
extern enm_ext_int_errors_t EX_INT_Disable(u8 inerrupt_number);
extern enm_ext_int_errors_t EX_INT_init(u8 interrupt , u8 sense);
extern void EX_INT0_SET_CALLBACK (void (*copyFuncptr) (void));
extern void EX_INT1_SET_CALLBACK (void (*copyFuncptr) (void));
extern void EX_INT2_SET_CALLBACK (void (*copyFuncptr) (void));


/************************************************************************/
/*                       interrupt pins & ports                         */
/************************************************************************/
#define EX_INT0_PORT D
#define EX_INT0_PIN   2
#define EX_INT1_PORT D
#define EX_INT1_PIN   3
#define EX_INT2_PORT B
#define EX_INT2_PIN   2
#endif /* EXTERNAL_INTERRUPT_H_ */
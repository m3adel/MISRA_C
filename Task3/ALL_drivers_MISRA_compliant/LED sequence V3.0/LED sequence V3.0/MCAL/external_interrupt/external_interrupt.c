/*
 * external_interrupt.c
 *
 * Created: 4/14/2023 12:02:42 PM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "external_interrupt.h"
/************************************************************************/
/*                                                                      */
/************************************************************************/


//Enable Global Interrupt by setting bit 7 in status register (1)
static void SIE(void)
{
	SREG |= (1<<I_BIT);
}

//Disable Global Interrupt by setting bit 7 in status register   (2)
static void CLI(void)
{
	SREG &= ~(1<<I_BIT);
}

//Choose Interrupt Sense : Level (LOW/HIGH), (FALLING/RISING) Edges    (3)
static enm_ext_int_errors_t INT_SENSE(u8 inerrupt_number,u8 sense)
{
	u8 u8_l_ret = EXT_INT_OKAY;
	switch (inerrupt_number)
	{
		case INT0:
		if(sense == rising_edge)
		{
			MCUCR |= (1<<ISC01); //Rising edge mode
			MCUCR |= (1<<ISC00);
		}
		else if(sense == falling_edge)
		{
			MCUCR |= (1<<ISC01); //Falling edge mode
			MCUCR &= ~(1<<ISC00);
		}
		else
		{
			u8_l_ret = EXT_INT_SENSE_ERROR;
		}
		break;
		case INT1:
			if(sense == rising_edge)
			{
				MCUCR |= (1<<ISC11); //Rising edge mode
				MCUCR |= (1<<ISC10);
			}
			else if(sense == falling_edge)
			{
				MCUCR |= (1<<ISC11); //Falling edge mode
				MCUCR &= ~(1<<ISC10);
		
			}
			else
			{
				u8_l_ret = EXT_INT_SENSE_ERROR;
			}
		break;
		case INT2:
		if(sense == rising_edge_2){
			MCUCSR |= (1<<ISC2); //Rising edge mode
		}
		else if(sense == falling_edge_2)
		{
			MCUCSR &= ~(1<<ISC10);	 //Falling edge mode
		}
		else
		{
			u8_l_ret = EXT_INT_SENSE_ERROR;
		}
		break;
		default:
		u8_l_ret = EXT_INT_INTERRUPT_NUMBER_ERROR;
		break;
	}
	return u8_l_ret;
}

//Enable External Interrupts int0/1/2                                      (4)
static enm_ext_int_errors_t EX_INT_Enable(u8 inerrupt_number)
{
	u8 u8_l_ret = EXT_INT_OKAY;
	if (inerrupt_number == INT0){
		GICR |= (1<<INT0);
		GIFR |= (1<<INTF0);
	}
	else if (inerrupt_number == INT1){
		GICR |= (1<<INT1);
	}
	else if (inerrupt_number == INT2){
		GICR |= (1<<INT2);
	}
	else
	{
		u8_l_ret = EXT_INT_INTERRUPT_NUMBER_ERROR;
	}
	return u8_l_ret;
}
//Disable External Interrupts int0/1/2
enm_ext_int_errors_t EX_INT_Disable(u8 inerrupt_number)
{
	u8 u8_l_ret = EXT_INT_OKAY;
	CLI();
	if (inerrupt_number == INT0)
	{
		GICR &= ~(1<<INT0);
	}
	else if (inerrupt_number == INT1)
	{
		GICR &= ~(1<<INT1);
	}
	else if (inerrupt_number == INT2)
	{
		GICR &= ~(1<<INT2);
	}
	else
	{
		u8_l_ret = EXT_INT_INTERRUPT_NUMBER_ERROR;
	}
	return u8_l_ret;
}
enm_ext_int_errors_t EX_INT_init(u8 interrupt , u8 sense)
{
	u8 u8_l_ret = EXT_INT_OKAY;
	SIE();     //Enable Global Interrupt by setting bit 7 in status register
	u8_l_ret = INT_SENSE(interrupt,sense);
	if (EXT_INT_OKAY == u8_l_ret)
	{
		u8_l_ret = EX_INT_Enable(interrupt);
		if (EXT_INT_OKAY == u8_l_ret)
		{
			u8_l_ret = EXT_INT_OKAY;
		}
		else
		{
			u8_l_ret = EXT_INT_ENABLE_ERROR;
		}
	}
	else
	{
		u8_l_ret = EXT_INT_SENSE_ERROR;
	}
	return u8_l_ret;
}
static void (*Callbackptr0) (void) = 0;
static void (*Callbackptr1) (void) = 0;
static void (*Callbackptr2) (void) = 0;
	
void EX_INT0_SET_CALLBACK (void (*copyFuncptr) (void))
{
	Callbackptr0 = copyFuncptr;
}
void EX_INT1_SET_CALLBACK (void (*copyFuncptr) (void))
{
	Callbackptr1 = copyFuncptr;
}
void EX_INT2_SET_CALLBACK (void (*copyFuncptr) (void))
{
	Callbackptr2 = copyFuncptr;
}
ISR (EXT_INT_0)
{
	if(Callbackptr0 == 0)
	{
				
	}
	else
	{
		Callbackptr0();
	}
}
ISR ( EXT_INT_1 )
{
	if(Callbackptr1 == 0)
	{
				
	}
	else
	{
		Callbackptr1();
	}
}
ISR (EXT_INT_2)
{
	if(Callbackptr2 == 0)
	{
			
	}
	else
	{
		Callbackptr2();
	}
}
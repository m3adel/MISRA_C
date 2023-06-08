/*
 * registers.h
 *
 * Created: 4/6/2023 11:32:40 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types.h"

/******************************************************************************/
/* DIO Registers' Locations */
/******************************************************************************/
#define DIO_U8_PORTA_REG	    *( ( volatile u8 * ) 0x3B )
#define DIO_U8_DDRA_REG		    *( ( volatile u8 * ) 0x3A )
#define DIO_U8_PINA_REG		    *( ( volatile u8 * ) 0x39 )

#define DIO_U8_PORTB_REG	    *( ( volatile u8 * ) 0x38 )
#define DIO_U8_DDRB_REG		    *( ( volatile u8 * ) 0x37 )
#define DIO_U8_PINB_REG		    *( ( volatile u8 * ) 0x36 )

#define DIO_U8_PORTC_REG	    *( ( volatile u8 * ) 0x35 )
#define DIO_U8_DDRC_REG		    *( ( volatile u8 * ) 0x34 )
#define DIO_U8_PINC_REG		    *( ( volatile u8 * ) 0x33 )

#define DIO_U8_PORTD_REG	    *( ( volatile u8 * ) 0x32 )
#define DIO_U8_DDRD_REG		    *( ( volatile u8 * ) 0x31 )
#define DIO_U8_PIND_REG		    *( ( volatile u8 * ) 0x30 )

/******************************************************************************/
#endif /* REGISTERS_H_ */
/*
 * registers.h
 *
 * Created: 4/8/2023 2:14:20 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types.h"
/******************************************************************************/
// Timer0 Registers
/******************************************************************************/
#define TCNT0   (*(volatile u8*)(0x52))
#define TCCR0   (*(volatile u8*)(0x53))
#define OCR0    (*(volatile u8*)(0x5C))
#define TIMSK   (*(volatile u8*)(0x59))
#define TOIE0 0 //overflow enable bit
#define TIFR    (*(volatile u8*)(0x58))
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
// External Interrupt Registers
/******************************************************************************/
#define SREG *((volatile u8*)0x5F)
#define I_BIT	7
#define GIFR *((volatile u8*)0x5A)
#define INTF0 6
#define INTF1 7
#define INTF2 5
#define GICR *((volatile u8*)0x5B)
#define INT0 6
#define INT1		7
#define INT2		5
#define MCUCR *((volatile u8*)0x55)
//sense modes for int0/1
#define falling_edge		1   
#define rising_edge 2
//Mode selecting bits
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3
//sense modes for int2
#define ISC2	6
#define falling_edge_2	0
#define rising_edge_2	1
#define MCUCSR  (*(volatile u8*)(0x54))
/******************************************************************************/
#endif /* REGISTERS_H_ */
/*
 * dio_program.c
 *
 *     Created on: May 16, 2023
 *         Author: Mohamed Abdelsalam - https://github.com/m3adel
 *    Description: This file contains all Digital Input Output (DIO) functions' implementation.
 *  MCU Datasheet: AVR ATmega32 - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */

/* MCAL */
#include "dio_private.h"
#include "dio_config.h"
#include "dio_interface.h"

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_init
 Input: en PortNumber, en PinNumber, and en PinDirection
 Output: void
 Description: Function to initialize Pin direction.
*/
u8 DIO_init ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
		if (str_dio_config.enm_dio_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRA_REG , str_dio_config.enm_dio_pinNumber );    //Set Initial PortA Direction
			}
			else if (str_dio_config.enm_dio_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRA_REG ,str_dio_config.enm_dio_pinNumber);   //clear Initial PortA Direction
			}
		break;
		case B:
			if (str_dio_config.enm_dio_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRB_REG , str_dio_config.enm_dio_pinNumber );    //Set Initial PortB Direction
			}
			else if (str_dio_config.enm_dio_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRB_REG , str_dio_config.enm_dio_pinNumber );   //clear Initial PortB Direction
			}
		break;
		case C:
			if (str_dio_config.enm_dio_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRC_REG , str_dio_config.enm_dio_pinNumber );    //Set Initial PortC Direction
			}
			else if (str_dio_config.enm_dio_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRC_REG  , str_dio_config.enm_dio_pinNumber );   //clear Initial PortC Direction
			}
		break;
		case D:
			if (str_dio_config.enm_dio_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRD_REG , str_dio_config.enm_dio_pinNumber );    //Set Initial PortD Direction
			}
			else if (str_dio_config.enm_dio_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRD_REG , str_dio_config.enm_dio_pinNumber );   //clear Initial PortD Direction
			}
		break;
		default:
		return DIO_PIN_INIT_ERROR;
	}	
	return DIO_OKAY;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_write
 Input: en PortNumber, en PinNumber, and en PinValue
 Output: void
 Description: Function to set Pin value.
*/

u8 DIO_write ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			if (str_dio_config.enm_dio_pinWritevalue == HIGH)
			{
				SET_BIT( DIO_U8_PORTA_REG , str_dio_config.enm_dio_pinNumber );	//Set value of pinNumber in PortA
			}
			else if (str_dio_config.enm_dio_pinWritevalue == LOW)
			{
				CLR_BIT( DIO_U8_PORTA_REG , str_dio_config.enm_dio_pinNumber );	//clear value of pinNumber in PortA
			}
		break;
		case B:
			if (str_dio_config.enm_dio_pinWritevalue == HIGH)
			{
				SET_BIT( DIO_U8_PORTB_REG , str_dio_config.enm_dio_pinNumber );	//Set value of pinNumber in PortB
			}
			else if (str_dio_config.enm_dio_pinWritevalue == LOW)
			{
				CLR_BIT( DIO_U8_PORTB_REG , str_dio_config.enm_dio_pinNumber );	//clear value of pinNumber in PortB
			}
		break;
		case C:
			if (str_dio_config.enm_dio_pinWritevalue == HIGH)
			{
				SET_BIT( DIO_U8_PORTC_REG , str_dio_config.enm_dio_pinNumber );	//Set value of pinNumber in PortC
			}
			else if (str_dio_config.enm_dio_pinWritevalue == LOW)
			{
				CLR_BIT( DIO_U8_PORTC_REG , str_dio_config.enm_dio_pinNumber );	//clear value of pinNumber in PortC
			}
		break;
		case D:
			if (str_dio_config.enm_dio_pinWritevalue == HIGH)
			{
				SET_BIT( DIO_U8_PORTD_REG , str_dio_config.enm_dio_pinNumber );	//Set value of pinNumber in PortD
			}
			else if (str_dio_config.enm_dio_pinWritevalue == LOW)
			{
				CLR_BIT( DIO_U8_PORTD_REG , str_dio_config.enm_dio_pinNumber );	//clear value of pinNumber in PortD
			}
		break;
		default:
			return DIO_PIN_WRITE_ERROR;
	}
	return DIO_OKAY;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_read
 Input: en PortNumber, en PinNumber, and Pointer to u8 ReturnedData
 Output: void
 Description: Function to get Pin value.
*/
boolean DIO_read ( str_dio_config_t str_dio_config )
{	
	switch(str_dio_config.enm_dio_portNumber)
	{
		boolean read;
		case A:
			read = GET_BIT( DIO_U8_PINA_REG , str_dio_config.enm_dio_pinNumber );
		break;
		case B:
			read = GET_BIT( DIO_U8_PINB_REG , str_dio_config.enm_dio_pinNumber );
		break;
		case C:
			read = GET_BIT( DIO_U8_PINC_REG , str_dio_config.enm_dio_pinNumber );
		break;
		case D:
			read = GET_BIT( DIO_U8_PIND_REG , str_dio_config.enm_dio_pinNumber );
		break;
		default:
			return false;
	}
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_toggle
 Input: en portNumber and en PinNumber
 Output: void
 Description: Function to toggle Pin value.
*/
void DIO_toggle ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			TOG_BIT( DIO_U8_PORTA_REG , str_dio_config.enm_dio_pinNumber );
		break;
		case B:
			TOG_BIT( DIO_U8_PORTB_REG , str_dio_config.enm_dio_pinNumber );
		break;
		case C:
			TOG_BIT( DIO_U8_PORTC_REG , str_dio_config.enm_dio_pinNumber );
		break;
		case D:
			TOG_BIT( DIO_U8_PORTD_REG , str_dio_config.enm_dio_pinNumber );
		break;
		default:
		return DIO_PIN_TOGGLE_ERROR;
	}
	return DIO_OKAY;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setPortDirection
 Input: en PortNumber and en PortDirection
 Output: void
 Description: Function to set Port direction.
*/
void DIO_setPortDirection ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			DIO_U8_DDRA_REG = str_dio_config.u8_portDirection;
		break;
		case B:
			DIO_U8_DDRB_REG = str_dio_config.u8_portDirection;
		break;
		case C:
			DIO_U8_DDRC_REG = str_dio_config.u8_portDirection;
		break;
		case D:
			DIO_U8_DDRD_REG = str_dio_config.u8_portDirection;
		break;
		default:
		return DIO_PORT_INIT_ERROR;
	}
	return DIO_OKAY;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setPortValue
 Input: en PortNumber and u8 PortValue
 Output: void
 Description: Function to set Port value.
*/
void DIO_setPortValue ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			DIO_U8_PORTA_REG = str_dio_config.u8_portWritedata;
		break;
		case B:
			DIO_U8_PORTB_REG = str_dio_config.u8_portWritedata;
		break;
		case C:
			DIO_U8_PORTC_REG = str_dio_config.u8_portWritedata;
		break;
		case D:
			DIO_U8_PORTD_REG = str_dio_config.u8_portWritedata;
		break;
		default:
		// do nothing
	}
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_getPortValue
 Input: en PortNumber and Pointer to u8 ReturnedPortValue
 Output: void
 Description: Function to get Port value.
*/
u8 DIO_getPortValue ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			return DIO_U8_PINA_REG;
		break;
		case B:
			return DIO_U8_PINB_REG;
		break;
		case C:
			return DIO_U8_PINC_REG;
		break;
		case D:
			return DIO_U8_PIND_REG;
		break;
		default:
		return 0;
	}
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setHigherNibble
 Input: en portNumber and u8 Data
 Output: void
 Description: Function to set Higher Nibble of Port.
*/
void DIO_setHigherNibble ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			UPPER_NIBBLE( DIO_U8_PORTA_REG, str_dio_config.u8_nipple_data );
		break;	
		case B:
			UPPER_NIBBLE( DIO_U8_PORTB_REG, str_dio_config.u8_nipple_data );
		break;
		case C:	
			UPPER_NIBBLE( DIO_U8_PORTC_REG, str_dio_config.u8_nipple_data );
		break;
		case D:
			UPPER_NIBBLE( DIO_U8_PORTD_REG, str_dio_config.u8_nipple_data );
		break;
		default:
		//do nothing
	}
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setLowerNibble
 Input: en PortNumber and u8 Data
 Output: void
 Description: Function to set LOWER Nibble of Port.
*/
void DIO_setLowerNibble ( str_dio_config_t str_dio_config )
{
	switch(str_dio_config.enm_dio_portNumber)
	{
		case A:
			LOWER_NIBBLE( DIO_U8_PORTA_REG, str_dio_config.u8_nipple_data );
		break;
		case B:
			LOWER_NIBBLE( DIO_U8_PORTB_REG, str_dio_config.u8_nipple_data );
		break;
		case C:
			LOWER_NIBBLE( DIO_U8_PORTC_REG, str_dio_config.u8_nipple_data );
		break;
		case D:
			LOWER_NIBBLE( DIO_U8_PORTD_REG, str_dio_config.u8_nipple_data );
		break;
		default:
		//do nothing
	}
}

/*******************************************************************************************************************************************************************/
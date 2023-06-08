/*
 * dio_program.c
 *
 *     Created on: May 16, 2023
 *         Author: Mohamed Abdelsalam - https://github.com/m3adel
 *    Description: This file contains all Digital Input Output (DIO) functions' implementation.
 *  MCU Datasheet: AVR ATmega32 - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */

/* MCAL */
#include "dio_interface.h"
/*******************************************************************************************************************************************************************/
/*
 Name: DIO_init
 Input: en PortNumber, en PinNumber, and en PinDirection
 Output: void
 Description: Function to initialize Pin direction.
*/
enm_dio_errors_t DIO_init ( enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber, enm_dio_pinDirection_t enm_a_pinDirection )
{
	u8 u8_l_ret = DIO_OKAY;
	switch(enm_a_portNumber)
	{
		case A:
		if (enm_a_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRA_REG , enm_a_pinNumber );    //Set Initial PortA Direction
			}
			else if (enm_a_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRA_REG ,enm_a_pinNumber);   //clear Initial PortA Direction
			}
			else
			{
				u8_l_ret = DIO_PIN_DIRECTION_ERROR;
			}
		break;
		case B:
			if (enm_a_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRB_REG , enm_a_pinNumber );    //Set Initial PortB Direction
			}
			else if (enm_a_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRB_REG , enm_a_pinNumber );   //clear Initial PortB Direction
			}
			else
			{
				u8_l_ret = DIO_PIN_DIRECTION_ERROR;
			}
		break;
		case C:
			if (enm_a_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRC_REG , enm_a_pinNumber );    //Set Initial PortC Direction
			}
			else if (enm_a_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRC_REG  , enm_a_pinNumber );   //clear Initial PortC Direction
			}
			else
			{
				u8_l_ret = DIO_PIN_DIRECTION_ERROR;
			}			
		break;
		case D:
			if (enm_a_pinDirection == OUT)
			{
				SET_BIT( DIO_U8_DDRD_REG , enm_a_pinNumber );    //Set Initial PortD Direction
			}
			else if (enm_a_pinDirection == IN)
			{
				CLR_BIT( DIO_U8_DDRD_REG , enm_a_pinNumber );   //clear Initial PortD Direction
			}
			else
			{
				u8_l_ret = DIO_PIN_DIRECTION_ERROR;
			}			
		break;
		default:
		u8_l_ret = DIO_PORT_NUMBER_ERROR;
	}	
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_write
 Input: en PortNumber, en PinNumber, and en PinValue
 Output: void
 Description: Function to set Pin value.
*/
enm_dio_errors_t DIO_write ( enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber, enm_dio_pinWritevalue_t enm_a_pinWritevalue )
{
	u8 u8_l_ret = DIO_OKAY;
	if ((P0 <= enm_a_pinNumber) && (P7 >= enm_a_pinNumber))
	{
		switch(enm_a_portNumber)
		{
			case A:
				if (enm_a_pinWritevalue == HIGH)
				{
					SET_BIT( DIO_U8_PORTA_REG , enm_a_pinNumber );	//Set value of pinNumber in PortA
				}
				else if (enm_a_pinWritevalue == LOW)
				{
					CLR_BIT( DIO_U8_PORTA_REG , enm_a_pinNumber );	//clear value of pinNumber in PortA
				}
				else
				{
					u8_l_ret = DIO_PIN_WRITE_VALUE_ERROR;
				}
			break;
			case B:
				if (enm_a_pinWritevalue == HIGH)
				{
					SET_BIT( DIO_U8_PORTB_REG , enm_a_pinNumber );	//Set value of pinNumber in PortB
				}
				else if (enm_a_pinWritevalue == LOW)
				{
					CLR_BIT( DIO_U8_PORTB_REG , enm_a_pinNumber );	//clear value of pinNumber in PortB
				}
				else
				{
					u8_l_ret = DIO_PIN_WRITE_VALUE_ERROR;
				}
			break;
			case C:
				if (enm_a_pinWritevalue == HIGH)
				{
					SET_BIT( DIO_U8_PORTC_REG , enm_a_pinNumber );	//Set value of pinNumber in PortC
				}
				else if (enm_a_pinWritevalue == LOW)
				{
					CLR_BIT( DIO_U8_PORTC_REG , enm_a_pinNumber );	//clear value of pinNumber in PortC
				}
				else
				{
					u8_l_ret = DIO_PIN_WRITE_VALUE_ERROR;
				}				
			break;
			case D:
				if (enm_a_pinWritevalue == HIGH)
				{
					SET_BIT( DIO_U8_PORTD_REG , enm_a_pinNumber );	//Set value of pinNumber in PortD
				}
				else if (enm_a_pinWritevalue == LOW)
				{
					CLR_BIT( DIO_U8_PORTD_REG , enm_a_pinNumber );	//clear value of pinNumber in PortD
				}
				else
				{
					u8_l_ret = DIO_PIN_WRITE_VALUE_ERROR;
				}				
			break;
			default:
			u8_l_ret = DIO_PORT_NUMBER_ERROR;
		}
	}
	else
	{
		u8_l_ret = DIO_PIN_NUMBER_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_read
 Input: en PortNumber, en PinNumber, and Pointer to u8 ReturnedData
 Output: void
 Description: Function to get Pin value.
*/
enm_dio_errors_t DIO_read ( enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber, boolean *pbool_a_returnedData )
{	
	u8 u8_l_ret = DIO_OKAY;
	if ((P0 <= enm_a_pinNumber) && (P7 >= enm_a_pinNumber))
	{
		switch(enm_a_portNumber)
		{
			case A:
				*pbool_a_returnedData = GET_BIT( DIO_U8_PINA_REG , enm_a_pinNumber );
			break;
			case B:
				*pbool_a_returnedData = GET_BIT( DIO_U8_PINB_REG , enm_a_pinNumber );
			break;
			case C:
				*pbool_a_returnedData = GET_BIT( DIO_U8_PINC_REG , enm_a_pinNumber );
			break;
			case D:
				*pbool_a_returnedData = GET_BIT( DIO_U8_PIND_REG , enm_a_pinNumber );
			break;
			default:
			u8_l_ret = DIO_PORT_NUMBER_ERROR;
		}
	}
	else
	{
		u8_l_ret = DIO_PIN_NUMBER_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_toggle
 Input: en portNumber and en PinNumber
 Output: void
 Description: Function to toggle Pin value.
*/
enm_dio_errors_t DIO_toggle ( enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber )
{
	u8 u8_l_ret = DIO_OKAY;
	if ((P0 <= enm_a_pinNumber) && (P7 >= enm_a_pinNumber))
	{
		switch(enm_a_portNumber)
		{
			case A:
				TOG_BIT( DIO_U8_PORTA_REG , enm_a_pinNumber );
			break;
			case B:
				TOG_BIT( DIO_U8_PORTB_REG , enm_a_pinNumber );
			break;
			case C:
				TOG_BIT( DIO_U8_PORTC_REG , enm_a_pinNumber );
			break;
			case D:
				TOG_BIT( DIO_U8_PORTD_REG , enm_a_pinNumber );
			break;
			default:
			u8_l_ret = DIO_PORT_NUMBER_ERROR;
		}
	}
	else
	{
		u8_l_ret = DIO_PIN_NUMBER_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setPortDirection
 Input: en PortNumber and en PortDirection
 Output: void
 Description: Function to set Port direction.
*/
enm_dio_errors_t DIO_setPortDirection ( enm_dio_portNumber_t enm_a_portNumber , u8 u8_a_portDirection )
{
	u8 u8_l_ret = DIO_OKAY;
	if ((0x00 <= u8_a_portDirection) && (0xFF >= u8_a_portDirection))
	{
		switch(enm_a_portNumber)
		{
			case A:
				DIO_U8_DDRA_REG = u8_a_portDirection;
			break;
			case B:
				DIO_U8_DDRB_REG = u8_a_portDirection;
			break;
			case C:
				DIO_U8_DDRC_REG = u8_a_portDirection;
			break;
			case D:
				DIO_U8_DDRD_REG = u8_a_portDirection;
			break;
			default:
			u8_l_ret = DIO_PORT_NUMBER_ERROR;
		}
	}
	else
	{
		u8_l_ret = DIO_PORT_DIRECTION_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setPortValue
 Input: en PortNumber and u8 PortValue
 Output: void
 Description: Function to set Port value.
*/
enm_dio_errors_t DIO_setPortValue ( enm_dio_portNumber_t enm_a_portNumber , u8 u8_a_portValue )
{
	u8 u8_l_ret = DIO_OKAY;
	if ((0x00 <= u8_a_portValue) && (0xFF >= u8_a_portValue))
	{
		switch(enm_a_portNumber)
		{
			case A:
				DIO_U8_PORTA_REG = u8_a_portValue;
			break;
			case B:
				DIO_U8_PORTB_REG = u8_a_portValue;
			break;
			case C:
				DIO_U8_PORTC_REG = u8_a_portValue;
			break;
			case D:
				DIO_U8_PORTD_REG = u8_a_portValue;
			break;
			default:
			u8_l_ret = DIO_PORT_NUMBER_ERROR;
		}
	}
	else
	{
		u8_l_ret = DIO_PORT_VALUE_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_getPortValue
 Input: en PortNumber and Pointer to u8 ReturnedPortValue
 Output: void
 Description: Function to get Port value.
*/
enm_dio_errors_t DIO_getPortValue ( enm_dio_portNumber_t enm_a_portNumber, u8 *pu8_a_returnedPortValue )
{
	u8 u8_l_ret = DIO_OKAY;
	switch(enm_a_portNumber)
	{
		case A:
			*pu8_a_returnedPortValue = DIO_U8_PINA_REG;
		break;
		case B:
			*pu8_a_returnedPortValue = DIO_U8_PINB_REG;
		break;
		case C:
			*pu8_a_returnedPortValue = DIO_U8_PINC_REG;
		break;
		case D:
			*pu8_a_returnedPortValue = DIO_U8_PIND_REG;
		break;
		default:
		u8_l_ret = DIO_PORT_NUMBER_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setHigherNibble
 Input: en portNumber and u8 Data
 Output: void
 Description: Function to set Higher Nibble of Port.
*/
enm_dio_errors_t DIO_setHigherNibble ( enm_dio_portNumber_t enm_a_portNumber, u8 u8_a_data )
{
	u8 u8_l_ret = DIO_OKAY;
	switch(enm_a_portNumber)
	{
		case A:
			UPPER_NIBBLE( DIO_U8_PORTA_REG, u8_a_data );
		break;	
		case B:
			UPPER_NIBBLE( DIO_U8_PORTB_REG, u8_a_data );
		break;
		case C:	
			UPPER_NIBBLE( DIO_U8_PORTC_REG, u8_a_data );
		break;
		case D:
			UPPER_NIBBLE( DIO_U8_PORTD_REG, u8_a_data );
		break;
		default:
		u8_l_ret = DIO_PORT_NUMBER_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
/*
 Name: DIO_setLowerNibble
 Input: en PortNumber and u8 Data
 Output: void
 Description: Function to set LOWER Nibble of Port.
*/
enm_dio_errors_t DIO_setLowerNibble ( enm_dio_portNumber_t enm_a_portNumber, u8 u8_a_data )
{
	u8 u8_l_ret = DIO_OKAY;
	switch(enm_a_portNumber)
	{
		case A:
			LOWER_NIBBLE( DIO_U8_PORTA_REG, u8_a_data );
		break;
		case B:
			LOWER_NIBBLE( DIO_U8_PORTB_REG, u8_a_data );
		break;
		case C:
			LOWER_NIBBLE( DIO_U8_PORTC_REG, u8_a_data );
		break;
		case D:
			LOWER_NIBBLE( DIO_U8_PORTD_REG, u8_a_data );
		break;
		default:
		u8_l_ret = DIO_PORT_NUMBER_ERROR;
	}
	return u8_l_ret;
}

/*******************************************************************************************************************************************************************/
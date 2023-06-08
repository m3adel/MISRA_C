/*
 * dio_interface.h
 *
 *     Created on: May 16, 2023
 *         Author: Mohamed Abdelsalam - https://github.com/m3adel
 *    Description: This file contains all Digital Input Output (DIO) functions' prototypes and definitions (Macros) to avoid magic numbers.
 *  MCU Datasheet: AVR ATmega32 - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*******************************************************************************************************************************************************************/
/* DIO Includes */

/* LIB */
#include "../../LIB/bit_math.h"
#include "../../LIB/registers.h"
/*******************************************************************************************************************************************************************/
/* DIO Macros */

/* Port Numbers */
typedef enum {
	A, B, C, D
} enm_dio_portNumber_t;

/* Pin Numbers */
typedef enum {
	P0,	P1,	P2,	P3,	P4,	P5,	P6,	P7
} enm_dio_pinNumber_t;

/* Pin Directions */
typedef enum {
	IN = false,
	OUT = true
} enm_dio_pinDirection_t;


/* Pin Values */
typedef enum {
	LOW = false,
	HIGH = true,
	INPUT_PULLUP_RESISTOR = true
} enm_dio_pinWritevalue_t;

/* Error list */
typedef enum {
	DIO_OKAY				=	0x00,
	DIO_PIN_DIRECTION_ERROR	=	0XF0,
	DIO_PORT_NUMBER_ERROR			,
	DIO_PIN_NUMBER_ERROR			,
	DIO_PIN_WRITE_VALUE_ERROR		,
	DIO_PORT_DIRECTION_ERROR		,
	DIO_PORT_VALUE_ERROR			
	
} enm_dio_errors_t;

/*******************************************************************************************************************************************************************/
/* DIO Functions' Prototypes */

enm_dio_errors_t DIO_init (enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber, enm_dio_pinDirection_t enm_a_pinDirection);
enm_dio_errors_t DIO_write (enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber, enm_dio_pinWritevalue_t enm_a_pinWritevalue);
enm_dio_errors_t DIO_read (enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber, boolean *pbool_a_returnedData);
enm_dio_errors_t DIO_toggle (enm_dio_portNumber_t enm_a_portNumber, enm_dio_pinNumber_t enm_a_pinNumber);
enm_dio_errors_t DIO_setPortDirection (enm_dio_portNumber_t enm_a_portNumber , u8 u8_a_portDirection);
enm_dio_errors_t DIO_setPortValue (enm_dio_portNumber_t enm_a_portNumber , u8 u8_a_portValue);
enm_dio_errors_t DIO_getPortValue (enm_dio_portNumber_t enm_a_portNumber, u8 *pu8_a_returnedPortValue);
enm_dio_errors_t DIO_setHigherNibble (enm_dio_portNumber_t enm_a_portNumber, u8 u8_a_data);
enm_dio_errors_t DIO_setLowerNibble (enm_dio_portNumber_t enm_a_portNumber, u8 u8_a_data);

/*******************************************************************************************************************************************************************/

#endif /* DIO_INTERFACE_H_ */


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
#include "../../LIB/std_types/std_types.h"
#include "../../LIB/bit_math/bit_math.h"

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
	DIO_PIN_INIT_ERROR	=	0XF0,
	DIO_PIN_WRITE_ERROR			,
	DIO_PIN_TOGGLE_ERROR		,
	DIO_PORT_INIT_ERROR			,
	DIO_PORT_READ_ERROR			,
	DIO_PORT_WRITE_ERROR		,
	DIO_HIGHER_NIPPLE_ERROR		,
	DIO_LOWER_NIPPLE_ERROR		,
	DIO_OKAY
} enm_dio_errors_t;

typedef struct
{
	enm_dio_portNumber_t	enm_dio_portNumber;
	enm_dio_pinNumber_t		enm_dio_pinNumber;
	enm_dio_pinDirection_t	enm_dio_pinDirection;
	enm_dio_pinWritevalue_t	enm_dio_pinWritevalue;
	u8						u8_nipple_data;
	u8						u8_portDirection;
	u8						u8_portWritedata;
	boolean					*bool_readPin;
}str_dio_config_t;
/*******************************************************************************************************************************************************************/
/* DIO Functions' Prototypes */

u8 DIO_init (str_dio_config_t str_dio_config);
u8 DIO_write (str_dio_config_t str_dio_config);
boolean DIO_read (str_dio_config_t str_dio_config);
void DIO_toggle (str_dio_config_t str_dio_config);
void DIO_setPortDirection (str_dio_config_t str_dio_config);
void DIO_setPortValue (str_dio_config_t str_dio_config);
u8 DIO_getPortValue (str_dio_config_t str_dio_config);
void DIO_setHigherNibble (str_dio_config_t str_dio_config);
void DIO_setLowerNibble (str_dio_config_t str_dio_config);

/*******************************************************************************************************************************************************************/

#endif /* DIO_INTERFACE_H_ */


/*
 * app_config.h
 *
 *   Created on: Jun 1, 2023
 *       Author: Bits 0101 Tribe - https://github.com/AbdelrhmanWalaa/Small-OS.git
 *  Description: This file contains all Application (APP) pre-build configurations, through which user can configure before using the APP.
 */
 *	 /*******************************************************************************************************************************************************************/
/* ATmega32 Pin outs: */
/*
							  PDIP
						  -------------
		   (XCK/T0) PB0 -| 1		40 |- PA0 (ADC0)
			   (T1)	PB1	-| 2		39 |- PA1 (ADC1)
		(INT2/AIN0)	PB2	-| 3		38 |- PA2 (ADC2)
		 (OC0/AIN1)	PB3	-| 4		37 |- PA3 (ADC3)
			   (SS)	PB4	-| 5		36 |- PA4 (ADC4)
			 (MOSI)	PB5	-| 6		35 |- PA5 (ADC5)
			 (MISO)	PB6	-| 7		34 |- PA6 (ADC6)
			  (SCK)	PB7	-| 8		33 |- PA7 (ADC7)
				  RESET -| 9		32 |- AREF
					VCC	-| 10		31 |- GND
					GND	-| 11		30 |- AVCC
				  XTAL2	-| 12		29 |- PC0 (TOSC2)
				  XTAL1	-| 13		28 |- PC1 (TOSC1)
			  (RXD)	PD0 -| 14		27 |- PC2 (TDI)
			  (TXD)	PD1 -| 15		26 |- PC3 (TDO)
			 (INT0)	PD2 -| 16		25 |- PC4 (TMS)
			 (INT1)	PD3 -| 17		24 |- PC5 (TCK)
			 (OC1B)	PD4 -| 18		23 |- PC6 (SDA)
			 (OC1A)	PD5 -| 19		22 |- PC7 (SCL)
			  (ICP)	PD6 -| 20		21 |- PD7 (OC2)
					 	  -------------
 */
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

/*******************************************************************************************************************************************************************/
/* APP Configurations */

/* APP Flag States */
#define APP_U8_FLAG_DOWN		0
#define APP_U8_FLAG_UP			1

/* End of Configurations */

/*******************************************************************************************************************************************************************/

#endif /* APP_CONFIG_H_ */
/*
 * LCD_Configuration.h
 *
 * Created: 10/9/2023 7:31:44 PM
 *  Author: karim
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

#include "Peripheral_Library.h"
//New data type
typedef enum
{
	ROW0 = 0,
	ROW1 = 1
}row;
typedef enum
{
	COl0 = 0,
	COl1 = 1,
	COl2 = 2,
	COl3 = 3,
	COl4 = 4,
	COl5 = 5,
	COl6 = 6,
	COl7 = 7,
	COl8 = 8,
	COl9 = 9,
	COl10 = 10,
	COl11 = 11,
	COl12 = 12,
	COl13 = 13,
	COl14 = 14,
	COl15 = 15
}column;
// Renaming Ports
#define LCD PORTA
#define LCD_DATA_PORT    DIO_PORTA
#define LCD_CONTROL_PORT DIO_PORTB
// Renaming Pins
#define LCD_RS DIO_PIN1
#define LCD_RW DIO_PIN3
#define LCD_EN DIO_PIN2

#define LCD_D0 DIO_PIN0
#define LCD_D1 DIO_PIN1
#define LCD_D2 DIO_PIN2
#define LCD_D3 DIO_PIN3
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7
// Renaming State
#define LCD_OUTPUT DIO_OUTPUT
// Renaming Status
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH

#endif /* LCD_CONFIGURATION_H_ */
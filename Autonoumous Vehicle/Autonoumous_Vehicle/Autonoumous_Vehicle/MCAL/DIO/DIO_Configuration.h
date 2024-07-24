/*
* DIO_Configuration.h
*
* Created: 10/2/2023 6:48:23 PM
*  Author: karim
*/


#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_

//#include "DIO_Address.h"
#include "CPU_Configurations.h"

// Renaming Ports
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}port;
// Renaming Pins
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}pin;
// Renaming States
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
}state;
// Renaming Status
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}status;
// Renaming Cases
typedef enum
{
	False = 0,
	True = 1
}cases;

#define INPUT  0x00
#define OUTPUT 0xFF

#define LOW    0x00
#define HIGH   0xFF

#endif /* DIO_CONFIGURATION_H_ */
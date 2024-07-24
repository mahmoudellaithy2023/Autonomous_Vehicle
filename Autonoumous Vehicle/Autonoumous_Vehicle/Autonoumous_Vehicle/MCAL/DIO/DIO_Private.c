/*
 * DIO_Private.c
 *
 * Created: 10/24/2023 9:19:17 PM
 *  Author: karim
 */ 

#include "DIO_Interface.h"


// Functions for pins
void DIO_SetPinDirection(port Port, pin Pin, state State)
{
	switch (State)// To check state
	{
		case DIO_INPUT:
		switch (Port)// To check port needed as input
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, Pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, Pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, Pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, Pin);
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (Port)// To check port needed as output
		{
			case DIO_PORTA:
			SET_BIT(DDRA, Pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, Pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, Pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, Pin);
			break;
		}
		break;
	}
}
void DIO_SetPinValue(port Port, pin Pin, status Status)
{
	switch (Status)// To check state
	{
		case DIO_LOW:
		switch (Port)// To check port needed as input
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, Pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, Pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, Pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, Pin);
			break;
		}
		break;
		case DIO_HIGH:
		switch (Port)// To check port needed as output
		{
			case DIO_PORTA:
			SET_BIT(PORTA, Pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, Pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, Pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, Pin);
			break;
		}
		break;
	}
}
void DIO_TogglePinValue(port Port, pin Pin)
{
	switch (Port)// To check port needed as output
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, Pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB, Pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, Pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, Pin);
		break;
	}
}
uint8_t DIO_ReadPinValue(port Port, pin Pin)
{
	uint8_t val = 2;
	switch (Port)// To check port needed as output
	{
		case DIO_PORTA:
		val = GET_BIT(PINA, Pin);
		break;
		case DIO_PORTB:
		val = GET_BIT(PINB, Pin);
		break;
		case DIO_PORTC:
		val = GET_BIT(PINC, Pin);
		break;
		case DIO_PORTD:
		val = GET_BIT(PIND, Pin);
		break;
	}
	return val;
}
void DIO_SetPinPullUp(port Port, pin Pin)
{
	switch (Port)// To check port needed as output
	{
		case DIO_PORTA:
		SET_BIT(PORTA, Pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, Pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, Pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, Pin);
		break;
	}
}

// Functions for ports
void DIO_SetPortDirection(port Port, state State)
{
	switch(State)
	{
		case DIO_INPUT:
		switch(Port)
		{
			case DIO_PORTA:
			DDRA = INPUT; //0x00//0b00000000;
			break;
			case DIO_PORTB:
			DDRB = INPUT; //0x00//0b00000000;
			break;
			case DIO_PORTC:
			DDRC = INPUT; //0x00//0b00000000;
			break;
			case DIO_PORTD:
			DDRD = INPUT; //0x00//0b00000000;
			break;
		}
		break;
		case DIO_OUTPUT:
		switch(Port)
		{
			case DIO_PORTA:
			DDRA = OUTPUT; //0xFF//0b11111111;
			break;
			case DIO_PORTB:
			DDRB = OUTPUT; //0xFF//0b11111111;
			break;
			case DIO_PORTC:
			DDRC = OUTPUT; //0xFF//0b11111111;
			break;
			case DIO_PORTD:
			DDRD = OUTPUT; //0xFF//0b11111111;
			break;
		}
		break;
	}
}
void DIO_SetPortValue(port Port, status Status)
{
	switch(Status)
	{
		case DIO_LOW:
		switch(Port)
		{
			case DIO_PORTA:
			PORTA = LOW; //0x00//0b00000000;
			break;
			case DIO_PORTB:
			PORTB = LOW; //0x00//0b00000000;
			break;
			case DIO_PORTC:
			PORTC = LOW; //0x00//0b00000000;
			break;
			case DIO_PORTD:
			PORTD = LOW; //0x00//0b00000000;
			break;
		}
		break;
		case DIO_HIGH:
		switch(Port)
		{
			case DIO_PORTA:
			PORTA = HIGH; //0xFF//0b11111111;
			break;
			case DIO_PORTB:
			PORTB = HIGH; //0xFF//0b11111111;
			break;
			case DIO_PORTC:
			PORTC = HIGH; //0xFF//0b11111111;
			break;
			case DIO_PORTD:
			PORTD = HIGH; //0xFF//0b11111111;
			break;
		}
		break;
	}
}
void DIO_TogglePortValue(port Port)
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA ^= HIGH; //0xFF//0b11111111;
		break;
		case DIO_PORTB:
		PORTB ^= HIGH; //0xFF//0b11111111;
		break;
		case DIO_PORTC:
		PORTC ^= HIGH; //0xFF//0b11111111;
		break;
		case DIO_PORTD:
		PORTD ^= HIGH; //0xFF//0b11111111;
		break;
	}
}
uint8_t DIO_ReadPortValue(port Port)
{
	uint8_t val = 2;
	switch (Port)// To check port needed as output
	{
		case DIO_PORTA:
		val = PINA;
		break;
		case DIO_PORTB:
		val = PINB;
		break;
		case DIO_PORTC:
		val = PINC;
		break;
		case DIO_PORTD:
		val = PIND;
		break;
	}
	return val;
}
void DIO_SetPortPullUp(port Port)
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA = HIGH; //0xFF//0b11111111;
		break;
		case DIO_PORTB:
		PORTB = HIGH; //0xFF//0b11111111;
		break;
		case DIO_PORTC:
		PORTC = HIGH; //0xFF//0b11111111;
		break;
		case DIO_PORTD:
		PORTD = HIGH; //0xFF//0b11111111;
		break;
	}
}
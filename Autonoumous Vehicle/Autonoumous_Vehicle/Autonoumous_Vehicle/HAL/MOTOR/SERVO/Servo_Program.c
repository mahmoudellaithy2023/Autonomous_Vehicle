/*
 * Servo_Program.c
 *
 * Created: 12/28/2023 1:51:02 AM
 *  Author: karim
 */ 

#include "Servo_Private.h"
#include "Servo_Interface.h"


void ServoMotor_Initialize(void)
{
	//Define Direction for OC1A pin as output
	SET_BIT(DDRD, PD5);
	//Choose mode from timer1 modes
	SET_BIT(TCCR1B, WGM13);SET_BIT(TCCR1B, WGM12);SET_BIT(TCCR1A, WGM11);CLR_BIT(TCCR1A, WGM10);
	//Choose non-inverting mode
	SET_BIT(TCCR1A, COM1A1);CLR_BIT(TCCR1A, COM1A0);
	//Choose Prescaler
	SET_BIT(TCCR1B, CS12);CLR_BIT(TCCR1B, CS11);CLR_BIT(TCCR1B, CS10);
	//Set new top value
	ICR1 = 1250;
}
void ServoMotor_Rotate(uint8_t angle)
{
	OCR1A = ((ICR1 * angle) / 100) - 1;
}

void SERVO_DIO_Initialize(void)
{
	SERVO_DDR = 0xFF;
}
void Servo_DIO_AngleRotation(void)
{
	SERVO_PORT = 0xFF;
	_delay_us(1000);
	SERVO_PORT = 0x00;
	
	_delay_ms(1000);
	
	SERVO_PORT = 0xFF;
	_delay_us(1500);
	SERVO_PORT = 0x00;
	
	_delay_ms(1000);
	
	SERVO_PORT = 0xFF;
	_delay_us(2000);
	SERVO_PORT = 0x00;
	
	_delay_ms(1000);
	
	SERVO_PORT = 0xFF;
	_delay_us(1500);
	SERVO_PORT = 0x00;

	_delay_ms(1000);
}
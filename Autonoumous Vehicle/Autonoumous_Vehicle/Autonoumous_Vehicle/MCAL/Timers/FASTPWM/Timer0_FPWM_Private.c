/*
 * Timer0_FPWM_Private.c
 *
 * Created: 10/25/2023 11:20:15 AM
 *  Author: karim
 */ 


#include "Timer0_FPWM_Interface.h"

void F_PWM_Initialize(void)
{
	//Define direction of OC0 pin
	SET_BIT(DDRB, PB3);
	//Choose timer mode as Fast PWM
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
}
void F_PWM_Start(FPWM_Prescaler prescaler)
{
	/*
	switch(prescaler)
	{
		
	}
	*/
	//Choose prescaler 256
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void F_PWM_Stop(void)
{
	//Choose prescaler 0
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void F_PWM_SetDuty(FPWM_Mode mode, uint8_t dutyCycle)
{
	//Choose mode from table 40
	switch (mode)
	{
		case FPWM_Disconnected:
		CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		OCR0 = 0;
		break;
		case FPWM_Inverting:
		SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		OCR0 = (FPWM_BITS - 1) - (((FPWM_BITS * dutyCycle) / 100) - 1);
		break;
		case FPWM_Non_Inverting:
		SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		OCR0 = (((FPWM_BITS * dutyCycle) / 100) - 1);
		break;
	}
}
/*
 * Timer0_OVF_Private.c
 *
 * Created: 10/25/2023 11:17:22 AM
 *  Author: karim
 */ 

#include "Timer0_OVF_Interface.h"

//Blocking Mode
void Timer0_OVF_WithoutInterrupt_Initialize(void)
{
	//choose mode
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	//pin disconnected
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	//disable interrupt
	CLR_BIT(TIMSK, TOIE0);
}
void Timer0_OVF_WithoutInterrupt_Start(void)
{
	//choose 1024 prescaler
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
}
void Timer0_OVF_WithoutInterrupt_Stop(void)
{
	//Choose prescaler zer0
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void Timer0_OVF_WithoutInterrupt_SetDelay(uint32_t delay)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1 * OVF_PRESCALER) / OVF_FREQUENCY);
	uint32_t Count = ((delay * OVF_MICROSECOND) / Tick);
	uint32_t OVF = Count / OVF_BITS;
	uint8_t InitialValue = (OVF_BITS - (Count % OVF_BITS));
	TCNT0 = InitialValue;
	OVF++;
	while (counter != OVF)
	{
		while (GET_BIT(TIFR, TOV0) != 1);
		SET_BIT(TIFR, TOV0);
		counter++;
	}
}
//Non-Blocking Mode
uint8_t initial_Value = 0;
uint32_t Num_OVF = 0;
void Timer0_OVF_WithInterrupt_Initialize(void)
{
	//choose mode
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	//pin disconnected
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	//enable interrupt
	SET_BIT(TIMSK, TOIE0);
	//Enable global interrupt
	SET_BIT(SREG, 7);
}
void Timer0_OVF_WithInterrupt_Start(void)
{
	//choose 1024 prescaler
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
}
void Timer0_OVF_WithInterrupt_Stop(void)
{
	//Choose prescaler zer0
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void Timer0_OVF_WithInterrupt_SetDelay(uint32_t delay)
{
	uint8_t Tick = ((1 * OVF_PRESCALER) / OVF_FREQUENCY);
	uint32_t Count = ((delay * OVF_MICROSECOND) / Tick);
	Num_OVF = (Count / OVF_BITS);
	initial_Value = (OVF_BITS - (Count % OVF_BITS));
	TCNT0 = initial_Value;
	Num_OVF++;
}

uint8_t Timer0_OVF_CounterValue(void)
{
	return TCNT0;
}
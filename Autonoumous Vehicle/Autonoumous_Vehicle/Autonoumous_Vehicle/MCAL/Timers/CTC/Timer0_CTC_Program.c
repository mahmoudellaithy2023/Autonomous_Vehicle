/*
 * Timer0_CTC_Program.c
 *
 * Created: 12/28/2023 1:38:38 AM
 *  Author: karim
 */ 
#include "Timer0_CTC_Interface.h"

//Blocking Mode
void Timer0_CTC_WithoutInterrupt_Initialize(void)
{
	//choose mode
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	//pin disconnected
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	//enable interrupt
	CLR_BIT(TIMSK, OCIE0);
}
void Timer0_CTC_WithoutInterrupt_Start(void)
{
	//choose 1024 prescaler
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithoutInterrupt_Stop(void)
{
	//Choose prescaler zer0
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithoutInterrupt_SetDelay(uint32_t delay)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1 * CTC_PRESCALER) / CTC_FREQUENCY);
	uint32_t Count = ((delay * CTC_MICROSECOND) / Tick);
	uint32_t OVF = Count / CTC_BITS;
	uint8_t InitialValue = (CTC_BITS - (Count % CTC_BITS));
	TCNT0 = InitialValue;
	OVF++;
	while (counter != OVF)
	{
		while (GET_BIT(TIFR, OCF0) != 1);
		SET_BIT(TIFR, OCF0);
		counter++;
	}
}
//Non-Blocking Mode
uint8_t Num_CTC = 0;
void Timer0_CTC_WithInterrupt_Initialize(void)
{
	//choose mode
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	//pin disconnected
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	//enable interrupt
	SET_BIT(TIMSK, OCIE0);
	//Enable global interrupt
	SET_BIT(SREG, 7);
}
void Timer0_CTC_WithInterrupt_Start(void)
{
	//choose 1024 prescaler
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithInterrupt_Stop(void)
{
	//Choose prescaler zer0
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void Timer0_CTC_WithInterrupt_SetDelay(uint32_t delay)
{
	uint8_t Tick = ((1 * CTC_PRESCALER) / CTC_FREQUENCY);
	uint32_t Count = ((delay * CTC_MICROSECOND) / Tick);
	OCR0 = CTC_BITS;
	Num_CTC = (Count / OCR0);
	Num_CTC++;
}
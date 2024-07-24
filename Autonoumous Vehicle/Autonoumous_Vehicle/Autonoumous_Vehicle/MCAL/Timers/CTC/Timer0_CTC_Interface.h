/*
 * Timer0_CTC_Interface.h
 *
 * Created: 10/25/2023 11:15:20 AM
 *  Author: karim
 */ 


#ifndef TIMER0_CTC_INTERFACE_H_
#define TIMER0_CTC_INTERFACE_H_


#include "Timer0_CTC_Configuration.h"

void Timer0_CTC_WithoutInterrupt_Initialize(void);
void Timer0_CTC_WithoutInterrupt_Start(void);
void Timer0_CTC_WithoutInterrupt_Stop(void);
void Timer0_CTC_WithoutInterrupt_SetDelay(uint32_t delay);

void Timer0_CTC_WithInterrupt_Initialize(void);
void Timer0_CTC_WithInterrupt_Start(void);
void Timer0_CTC_WithInterrupt_Stop(void);
void Timer0_CTC_WithInterrupt_SetDelay(uint32_t delay);


#endif /* TIMER0_CTC_INTERFACE_H_ */
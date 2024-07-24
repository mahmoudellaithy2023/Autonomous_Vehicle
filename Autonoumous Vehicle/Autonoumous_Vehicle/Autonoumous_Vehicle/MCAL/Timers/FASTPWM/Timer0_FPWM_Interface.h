/*
 * Timer0_FPWM_Interface.h
 *
 * Created: 10/25/2023 11:19:24 AM
 *  Author: karim
 */ 


#ifndef TIMER0_FPWM_INTERFACE_H_
#define TIMER0_FPWM_INTERFACE_H_


#include "Timer0_FPWM_Configuration.h"

void F_PWM_Initialize(void);
void F_PWM_Start(FPWM_Prescaler prescaler);
void F_PWM_Stop(void);
void F_PWM_SetDuty(FPWM_Mode mode, uint8_t dutyCycle);


#endif /* TIMER0_FPWM_INTERFACE_H_ */
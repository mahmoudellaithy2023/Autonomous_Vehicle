/*
 * UltraSonic_Interface.h
 *
 * Created: 12/28/2023 1:33:57 AM
 *  Author: karim
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "UltraSonic_Configuration.h"

void UltraSonic_Initialization(void);

void UltraSonic_Trigger(void);

uint16_t UltraSonic_GetPulseWidth(void);

uint16_t UltraSonic_DisplayValue(void);

#endif /* ULTRASONIC_INTERFACE_H_ */
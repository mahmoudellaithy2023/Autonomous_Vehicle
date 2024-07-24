/*
 * WDT_Interface.h
 *
 * Created: 10/23/2023 3:55:35 PM
 *  Author: karim
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#include "WDT_Configuration.h"

void WDT_Initialization(void);
void WDT_Start(WDT_Voltage volt, WDT_Prescaler_3V pre_3V, WDT_Prescaler_5V pre_5V);
void WDT_Timer_Refresh(void);



#endif /* WDT_INTERFACE_H_ */
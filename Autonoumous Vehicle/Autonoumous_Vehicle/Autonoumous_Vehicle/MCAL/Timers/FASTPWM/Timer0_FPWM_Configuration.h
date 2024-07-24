/*
* FPWM_Configuration.h
*
* Created: 10/15/2022 5:15:07 PM
*  Author: karim
*/


#ifndef FPWM_CONFIGURATION_H_
#define FPWM_CONFIGURATION_H_

#include "CPU_Configurations.h"
#include "Timer0_FPWM_Address.h"


#define FPWM_BITS        256
#define FPWM_PRESCALER   1024
#define FPWM_FREQUENCY   16
#define FPWM_MICROSECOND 1000

//Table 40
typedef enum
{
	FPWM_Disconnected  = 0,
	FPWM_Inverting     = 1,
	FPWM_Non_Inverting = 2
}FPWM_Mode;
//Table 42
typedef enum
{
	FPWM_Disable = 0,
	FPWM_NoPrescaler = 1
}FPWM_Prescaler;


#endif /* FPWM_CONFIGURATION_H_ */
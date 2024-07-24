/*
* OVF_Configuration.h
*
* Created: 10/14/2022 5:38:43 PM
*  Author: karim
*/


#ifndef OVF_CONFIGURATION_H_
#define OVF_CONFIGURATION_H_

#include "CPU_Configurations.h"
#include "Timer0_OVF_Address.h"

#define OVF_BITS        256
#define OVF_PRESCALER   1024
#define OVF_FREQUENCY   16
#define OVF_MICROSECOND 1000

typedef enum
{
	No_Clock_Source = 0,
	No_Prescaling = 1,
	PRESCALER_8 = 2
}Timer0_OVF_Prescaler;


#endif /* OVF_CONFIGURATION_H_ */
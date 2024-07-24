/*
 * CPU_Configurations.h
 *
 * Created: 10/2/2023 5:35:22 PM
 *  Author: karim
 */ 


#ifndef CPU_CONFIGURATIONS_H_
#define CPU_CONFIGURATIONS_H_

#undef F_CPU

#define F_CPU 16000000

#include <avr/io.h>

#include <avr/interrupt.h>

#include <util/delay.h>

#include "BIT_MATH.h"

typedef float fint32_t;

#endif /* CPU_CONFIGURATIONS_H_ */
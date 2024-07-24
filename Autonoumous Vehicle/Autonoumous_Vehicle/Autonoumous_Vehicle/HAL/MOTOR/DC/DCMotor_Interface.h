/*
 * DCMotor_Interface.h
 *
 * Created: 10/25/2023 11:29:24 AM
 *  Author: karim
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#include "DCMotor_Configuration.h"

void DC_Initialize(dc_motor motor);
void DC_Start(dc_motor motor, dc_motor_direction direction);
void DC_Stop(dc_motor motor);


#endif /* DCMOTOR_INTERFACE_H_ */
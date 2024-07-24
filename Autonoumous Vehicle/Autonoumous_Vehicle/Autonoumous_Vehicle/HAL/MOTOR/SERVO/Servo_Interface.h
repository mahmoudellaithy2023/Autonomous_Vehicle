/*
 * Servo_Interface.h
 *
 * Created: 10/25/2023 12:18:09 PM
 *  Author: karim
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#include "Servo_Configuration.h"


void ServoMotor_Initialize(void);
void ServoMotor_Rotate(uint8_t angle);

void SERVO_DIO_Initialize(void);
void Servo_DIO_AngleRotation(void);



#endif /* SERVO_INTERFACE_H_ */
/*
 * DCMotor_Configuration.h
 *
 * Created: 10/25/2023 11:29:10 AM
 *  Author: karim
 */ 


#ifndef DCMOTOR_CONFIGURATION_H_
#define DCMOTOR_CONFIGURATION_H_

#include "PERIPHERAL_LIBRARY.h"

#define DC_Enable_Port DIO_PORTD
#define DC_Enable1_Pin DIO_PIN4
#define DC_Enable2_Pin DIO_PIN5

#define DC_Motor_Port DIO_PORTC

#define DC_Motor1_A1 DIO_PIN3
#define DC_Motor1_A2 DIO_PIN4
#define DC_Motor2_A3 DIO_PIN5
#define DC_Motor2_A4 DIO_PIN6

#define DC_OUTPUT DIO_OUTPUT

#define DC_LOW DIO_LOW
#define DC_HIGH DIO_HIGH

typedef enum
{
	DC_Motor1 = 0,
	DC_Motor2 = 1
}dc_motor;

typedef enum
{
	DC_CW = 0,
	DC_CCW =1
}dc_motor_direction;



#endif /* DCMOTOR_CONFIGURATION_H_ */
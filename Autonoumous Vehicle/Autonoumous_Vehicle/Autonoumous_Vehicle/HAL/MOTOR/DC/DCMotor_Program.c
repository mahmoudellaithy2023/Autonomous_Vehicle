/*
 * DCMotor_Program.c
 *
 * Created: 12/28/2023 1:49:59 AM
 *  Author: karim
 */ 

#include "DCMotor_Private.h"
#include "DCMotor_Interface.h"

void DC_Initialize(dc_motor motor)
{
	switch(motor)
	{
		case DC_Motor1:
		DIO_SetPinDirection(DC_Enable_Port, DC_Enable1_Pin, DC_OUTPUT);
		DIO_SetPinDirection(DC_Motor_Port, DC_Motor1_A1, DC_OUTPUT);
		DIO_SetPinDirection(DC_Motor_Port, DC_Motor1_A2, DC_OUTPUT);
		break;
		case DC_Motor2:
		DIO_SetPinDirection(DC_Enable_Port, DC_Enable2_Pin, DC_OUTPUT);
		DIO_SetPinDirection(DC_Motor_Port, DC_Motor2_A3, DC_OUTPUT);
		DIO_SetPinDirection(DC_Motor_Port, DC_Motor2_A4, DC_OUTPUT);
		break;
	}
}
void DC_Start(dc_motor motor, dc_motor_direction direction)
{
	switch(motor)
	{
		case DC_Motor1:
		DIO_SetPinValue(DC_Enable_Port, DC_Enable1_Pin, DC_HIGH);
		switch(direction)
		{
			case DC_CW:
			DIO_SetPinValue(DC_Motor_Port, DC_Motor1_A1, DC_HIGH);
			DIO_SetPinValue(DC_Motor_Port, DC_Motor1_A2, DC_LOW);
			break;
			case DC_CCW:
			DIO_SetPinValue(DC_Motor_Port, DC_Motor1_A1, DC_LOW);
			DIO_SetPinValue(DC_Motor_Port, DC_Motor1_A2, DC_HIGH);
			break;
		}
		break;
		case DC_Motor2:
		DIO_SetPinValue(DC_Enable_Port, DC_Enable2_Pin, DC_HIGH);
		switch(direction)
		{
			case DC_CW:
			DIO_SetPinValue(DC_Motor_Port, DC_Motor2_A3, DC_HIGH);
			DIO_SetPinValue(DC_Motor_Port, DC_Motor2_A4, DC_LOW);
			break;
			case DC_CCW:
			DIO_SetPinValue(DC_Motor_Port, DC_Motor2_A3, DC_LOW);
			DIO_SetPinValue(DC_Motor_Port, DC_Motor2_A4, DC_HIGH);
			break;
		}
		break;
	}
}
void DC_Stop(dc_motor motor)
{
	switch(motor)
	{
		case DC_Motor1:
		DIO_SetPinValue(DC_Enable_Port, DC_Enable1_Pin, DC_LOW);
		DIO_SetPinValue(DC_Motor_Port, DC_Motor1_A1, DC_LOW);
		DIO_SetPinValue(DC_Motor_Port, DC_Motor1_A2, DC_LOW);
		break;
		case DC_Motor2:
		DIO_SetPinValue(DC_Enable_Port, DC_Enable2_Pin, DC_LOW);
		DIO_SetPinValue(DC_Motor_Port, DC_Motor2_A3, DC_LOW);
		DIO_SetPinValue(DC_Motor_Port, DC_Motor2_A4, DC_LOW);
		break;
	}
}
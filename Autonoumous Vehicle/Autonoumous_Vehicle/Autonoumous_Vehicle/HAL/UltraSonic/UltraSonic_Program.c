/*
* UltraSonic_Program.c
*
* Created: 12/28/2023 1:34:07 AM
*  Author: karim
*/

#include "UltraSonic_Private.h"
#include "UltraSonic_Interface.h"
/*
uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;
uint8_t distance_str[10];

void UltraSonic_Initialization(void){

TRIGER_DDR|=(1<<TRIGER);
ECHO_DDR&=~(1<<ECHO);
ECHO_PULLUP|=(1<<ECHO);
enable_ex_interrupt();
timer0_init();
return;
}

void enable_ex_interrupt(void){

MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
GICR  |= (1<<INT1);			// Enable INT1 interrupts.
return;
}

void UltraSonic_Trigger(void)
{
if(!sensor_working){
TRIGER_PORT|=(1<<TRIGER);
_delay_us(15);
TRIGER_PORT&=~(1<<TRIGER);
sensor_working=1;
}
}

ISR(INT1_vect)
{
if(sensor_working==1){
if(rising_edge == 0)
{
TCNT0=0x00;
rising_edge=1;
timer_counter=0;
}
else
{
distance=(timer_counter*256+TCNT0)/466;
LCD_SetCrusorLocation(1,0);
itoa(distance,distance_str,10);
strcat(distance_str, " cm ");
LCD_Write_String(distance_str);
_delay_ms(40);
timer_counter=0;
rising_edge=0;
}
}
}

ISR(TIMER0_OVF_vect){
timer_counter++;
if(timer_counter > 730){
TCNT0=0x00;
sensor_working=0;
rising_edge=0;
timer_counter=0;
}
}
*/

uint16_t distance, previous_distance;

void UltraSonic_Initialization(void)
{
	// we're setting the trigger pin as output as it will generate ultrasonic sound wave
	US_DDR|=(1<<US_TRIG_POS);
}

void UltraSonic_Trigger(void)
{
	// this function will generate ultrasonic sound wave for 15 microseconds
	//Send a 10uS pulse on trigger line
	
	US_PORT|=(1<<US_TRIG_POS);	//high
	
	_delay_us(15);				//wait 15uS
	
	US_PORT&=~(1<<US_TRIG_POS);	//low
}

uint16_t UltraSonic_GetPulseWidth(void)
{
	// this function will be used to measure the pulse duration. When the ultra sound echo back after hitting an object
	// the micro controller will read the pulse using the echo pin of the ultrasonic sensor connected to it.
	
	uint32_t i,result;

	// Section - 1: the following lines of code before the section - 2 is checking if the ultrasonic is working or not
	// it check the echo pin for a certain amount of time. If there is no signal it means the sensor is not working or not connect properly
	for(i=0;i<600000;i++)
	{
		if(!(US_PIN & (1<<US_ECHO_POS)))
		continue;	//Line is still low, so wait
		else
		break;		//High edge detected, so break.
	}

	if(i==600000)
	return US_ERROR;	//Indicates time out
	
	//High Edge Found
	
	// Section -2 : This section is all about preparing the timer for counting the time of the pulse. Timers in microcontrllers is used for timimg operation
	//Setup Timer1
	TCCR1A=0X00;
	TCCR1B=(1<<CS11);	// This line sets the resolution of the timer. Maximum of how much value it should count.
	TCNT1=0x00;			// This line start the counter to start counting time

	// Section -3 : This section checks weather the there is any object or not
	for(i=0;i<600000;i++)                // the 600000 value is used randomly to denote a very small amount of time, almost 40 miliseconds
	{
		if(US_PIN & (1<<US_ECHO_POS))
		{
			if(TCNT1 > 60000) break; else continue;   // if the TCNT1 value gets higher than 60000 it means there is not object in the range of the sensor
		}
		else
		break;
	}

	if(i==600000)
	return US_NO_OBSTACLE;	//Indicates time out

	//Falling edge found

	result=TCNT1;          // microcontroller stores the the value of the counted pulse time in the TCNT1 register. So, we're returning this value to the
	// main function for utilizing it later

	//Stop Timer
	TCCR1B=0x00;

	if(result > 60000)
	return US_NO_OBSTACLE;	//No obstacle
	else
	return (result>>1);
}

uint16_t UltraSonic_DisplayValue(void)
{
	uint16_t reading;
	//Trigger the wave of ultrasonic
	UltraSonic_Trigger();
	
	//Measure the width of pulse
	reading = UltraSonic_GetPulseWidth();             // getting the duration of the ultrasound took to echo back after hitting the object

	//Handle Errors
	if(reading == US_ERROR)                // if micro controller doesn't get any pulse then it will set the US_ERROR variable to -1
	// the following code will check if there is error then it will be displayed on the LCD screen
	{
		return 0;
	}
	else
	{
		distance = (reading * 0.034 / 2.0);	// This will give the distance in centimeters
		_delay_ms(30);
		return distance;
	}
}


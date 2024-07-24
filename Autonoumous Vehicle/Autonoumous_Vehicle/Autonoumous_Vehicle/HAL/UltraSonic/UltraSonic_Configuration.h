/*
 * UltraSonic_Configuration.h
 *
 * Created: 12/28/2023 1:33:34 AM
 *  Author: karim
 */ 


#ifndef ULTRASONIC_CONFIGURATION_H_
#define ULTRASONIC_CONFIGURATION_H_

#include "Peripheral_Library.h"
/*
#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGER        0
#define   ECHO          3
*/

#define US_PORT PORTC           // we have connected the Ultrasonic sensor on port C. to use the ultrasonic we need two pins of the ultrasonic to be connected on port C
#define	US_PIN	PINC            // we need to initialize the pin resistor when we want to take input.
#define US_DDR 	DDRC            // we need data-direction-resistor (DDR) to set the direction of data flow. input or output. we will define it later, now we're just naming it.

#define US_TRIG_POS	PC0         // the trigger pin of ultrasonic sound sensor is connected to port C pin 0
#define US_ECHO_POS	PC1         // the echo pin of the ultrasonic sound sensor is connected to port C pin 1


#define US_ERROR		-1      // we're defining two more variables two know if the ultrasonic sensor is working or not
#define	US_NO_OBSTACLE	-2

#endif /* ULTRASONIC_CONFIGURATION_H_ */
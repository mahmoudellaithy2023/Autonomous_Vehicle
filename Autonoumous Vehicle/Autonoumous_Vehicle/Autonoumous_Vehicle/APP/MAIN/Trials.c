/*
* Trials.c
*
* Created: 12/28/2023 2:06:17 AM
*  Author: karim
*/

/*
int hamada()
{
	DDRA=0xff;
	//initialize();           // we're initializing the LCD

	char numberString[4];   // we re defining an array of character. It will be utilized later to store integer to be displayed on the LCD screen

	while(1) {
		
		uint16_t r;
		
		_delay_ms(100);	//Let the LCD Module start


		
		//Set io port direction of sensor
		//HCSR04Init();                                            // we need to set the fifth led as output separately because it is on another port
		//PORTC |= 1 << led1;
		while(1)
		{
			
			//Send a trigger pulse
			//HCSR04Trigger();               // calling the ultrasonic sound wave generator function

			//Measure the width of pulse
			r=GetPulseWidth();             // getting the duration of the ultrasound took to echo back after hitting the object

			//Handle Errors
			if(r==US_ERROR)                // if microcontroller doesn't get any pulse then it will set the US_ERROR variable to -1
			// the following code will check if there is error then it will be displayed on the LCD screen
			{
				lcd_setCursor(1, 1);      //lcd_setCursor(column, row)
				lcd_print("Error!");
			}
			else
			{
				
				distance=(r*0.034/2.0);	// This will give the distance in centimeters
				
				
				
				if (distance != previous_distance)    // the LCD screen only need to be cleared if the distance is changed otherwise it is not required
				{
					lcd_clear();
				}
				
				lcd_setCursor(1, 1);      // set the row and column to display the data
				lcd_print("Water lv = ");
				lcd_setCursor(12, 1);      //lcd_setCursor(column, row)
				itoa(distance, numberString, 10);    // distance is an integer number, we can not display integer directly on the LCD. this line converts integer into array of character
				lcd_print(numberString);
				lcd_setCursor(14, 1);      //set the row to 1 and and column to 14 to display the data
				lcd_print(" cm");					
				previous_distance = distance;
				_delay_ms(30);			
			}
		}	
	}
}
*/
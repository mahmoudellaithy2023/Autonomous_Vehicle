/*
 * LCD_Private.h
 *
 * Created: 12/28/2023 1:42:30 AM
 *  Author: karim
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);

#endif /* LCD_PRIVATE_H_ */
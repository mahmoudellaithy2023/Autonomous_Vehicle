/*
 * LCD_Program.c
 *
 * Created: 12/28/2023 1:42:20 AM
 *  Author: karim
 */ 

#include "LCD_Private.h"
#include "LCD_Interface.h"

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}
void ftoa(float n, char* res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;
	
	// Extract floating part
	float fpart = n - (float)ipart;
	
	// convert integer part to string
	int i = intToStr(ipart, res, 0);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot
		
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

void LCD_Initialize(void)
{
	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D4, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D5, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D6, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D7, LCD_OUTPUT);
	
	DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_RS, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_RW, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_EN, LCD_OUTPUT);
	
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x02);
	LCD_Write_Command(0x06);
	LCD_Write_Command(0x0C);
	_delay_ms(2);
}
void LCD_Write_Command(uint8_t command)
{
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS, LCD_LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW, LCD_LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_LOW);
	//Send High Nibble
	LCD = (command & 0xF0) | (LCD & 0x0F);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_LOW);
	//Send Low Nibble
	LCD = ((command & 0x0F) << 4) | (LCD & 0x0F);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
}
void LCD_Write_Character(uint8_t character)
{
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS, LCD_HIGH);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW, LCD_LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_LOW);
	//Send High Nibble
	LCD = (character & 0xF0) | (LCD & 0x0F);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_LOW);
	//Send Low Nibble
	LCD = ((character & 0x0F) << 4) | (LCD & 0x0F);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
}
void LCD_ClearScreen(void)
{
	LCD_Write_Command(0x01);
}
void LCD_SetCrusorLocation(row Row, column Column)
{
	uint8_t location = 0;
	switch (Row)
	{
		case ROW0:
		location = 0x80 + Column;
		break;
		case ROW1:
		location = 0xC0 + Column;
		break;
		default:
		location = 0x80 + Column;
		break;
	}
	LCD_Write_Command(location);
}
void LCD_Write_String(uint8_t* str)
{
	while (*str != '\0')
	{
		LCD_Write_Character(*str);
		str++;
		_delay_ms(10);
	}
}
void LCD_Write_FloatNumber(fint32_t fnumber)
{
	char fnum[10];
	ftoa(fnumber, fnum, 3);
	LCD_Write_String((uint8_t*)fnum);
}
void LCD_Write_IntegerNumber(uint32_t number)
{
	char num[10];
	ltoa(number, num, 10);
	LCD_Write_String((uint8_t*)num);
}
void LCD_SpecialCharacter(uint8_t* customChatacter, uint8_t length, uint8_t loc[2])
{
	uint8_t iter = 0;
	/*Start by write on location 0 in CGRAM*/
	LCD_Write_Command(0x40);
	/*Write Array will be sent by the user*/
	for(iter = 0; iter < length; iter++)
	{
		LCD_Write_Character(customChatacter[iter]);
	}
	/*Choose location*/
	LCD_SetCrusorLocation(ROW0, COl0);
}
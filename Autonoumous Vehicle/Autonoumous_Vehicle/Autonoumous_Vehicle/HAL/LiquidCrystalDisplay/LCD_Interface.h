/*
 * LCD_Interface.h
 *
 * Created: 10/25/2023 12:28:30 PM
 *  Author: karim
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_Configuration.h"

void LCD_Initialize(void);
void LCD_Write_Command(uint8_t command);
void LCD_Write_Character(uint8_t character);
void LCD_ClearScreen(void);
void LCD_SetCrusorLocation(row Row, column Column);
void LCD_Write_String(uint8_t* str);
void LCD_Write_FloatNumber(fint32_t fnumber);
void LCD_Write_IntegerNumber(uint32_t number);
void LCD_SpecialCharacter(uint8_t* customChatacter, uint8_t length, uint8_t loc[2]);



#endif /* LCD_INTERFACE_H_ */
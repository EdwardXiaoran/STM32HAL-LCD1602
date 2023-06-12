// LCD_display.h
// Created on: 2023/06/04
// Author: EdwardXiaoran
#ifndef LCDdisplay_H_
#define LCDdisplay_H_

#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "main.h"

void LCD_initialization(void);
void lcd_show_string(uint8_t x, uint8_t y , char * string);
void lcd_show_02d(uint8_t y, uint8_t x , int number);
void lcd_write_cmd(uint8_t cmd);
void lcd_write_dat(uint8_t dat);
void lcd_write(uint8_t data);

#endif /* LCDdisplay_H_ */

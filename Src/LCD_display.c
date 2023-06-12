// LCD_display.c
// Created on: 2023/06/04
// Author: EdwardXiaoran

#include "LCD_display.h"

#define D4_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_4
#define D5_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_5
#define D6_GPIO_Port GPIOA
#define D6_Pin GPIO_PIN_6
#define D7_GPIO_Port GPIOA
#define D7_Pin GPIO_PIN_7

#define RS_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_0

#define EN_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_1

void LCD_initialization(void)
{
	lcd_write_cmd(0x33);
	lcd_write_cmd(0x32);
	lcd_write_cmd(0x20);
	lcd_write_cmd(0x28);
	lcd_write_cmd(0x01);
	lcd_write_cmd(0x0c);
	lcd_write_cmd(0x06);
}

void lcd_show_02d(uint8_t y, uint8_t x, int number)
{
	char aaa[11];
	sprintf(aaa, "%02d", number);
	lcd_show_string(y, x, aaa);
}

void lcd_show_string(uint8_t y, uint8_t x, char *string)
{
	if (y == 1)
		lcd_write_cmd(0x80 + 0x40 + x);

	else
		lcd_write_cmd(0x80 + 0x00 + x);

	for (uint8_t i = 0; i < strlen(string); i++)
	{
		lcd_write_dat(string[i]);
	}
}

void lcd_write_cmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);

	lcd_write(cmd >> 4);
	lcd_write(cmd & 0x0F);
}

void lcd_write_dat(uint8_t dat)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);

	lcd_write(dat >> 4);
	lcd_write(dat & 0x0F);
}

void lcd_write(uint8_t data)
{
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data >> 0) & 0x01);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data >> 1) & 0x01);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data >> 2) & 0x01);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data >> 3) & 0x01);

	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, 0);
}

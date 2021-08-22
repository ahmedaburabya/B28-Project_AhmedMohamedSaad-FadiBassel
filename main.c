/*
 * B28 - Project (Slave).c
 *
 * Created: 8/21/2021 10:12:05 AM
 * Author : Ahmed Saad
 */ 

#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"
#include "LED.h"


int main(void)
{
	LCD_Initialization();
	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	SPI_Slave_Init();
	uint8_t x = 0;
	uint8_t* str = "No Data Received";
	LCD_String(str);
	while (1)
	{
		x = SPI_Receive();
		if(x == 48)
		{
			str = "LED 0 is toggled";
			LED0_TGL();
			LCD_Clear();
			LCD_String(str);
		}
		else if(x == 49)
		{
			str = "LED 1 is toggled";
			LED1_TGL();
			LCD_Clear();
			LCD_String(str);
		}
		else if (x == 50)
		{
			str = "LED 2 is toggled";
			LED2_TGL();
			LCD_Clear();
			LCD_String(str);
		}
		else
		{
			str = "Send 0, 1 or 2";
			LCD_Clear();
			LCD_String(str);
		}
		
	}
}


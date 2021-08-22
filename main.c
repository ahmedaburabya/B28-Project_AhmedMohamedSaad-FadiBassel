/*
 * B28 - Project (Master).c
 *
 * Created: 8/20/2021 4:15:41 PM
 * Author : Ahmed Saad
 */ 

#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"
#include "UART.h"

int main(void)
{
	LCD_Initialization();
	UART_Init();
	SPI_Master_Init();
	SPI_SlaveSelect(0);
	uint8_t* str = "No Data Received";
	LCD_String(str);
	uint8_t B_Data = 0;
	while (1)
	{
		
		B_Data = UART_Receive();
		if(B_Data == 48)
		{
			SPI_Transmit(B_Data);
			str = "0 is pressed";
			LCD_Clear();
			LCD_String(str);
			
		}
		else if(B_Data == 49)
		{
			SPI_Transmit(B_Data);
			str = "1 is pressed";
			LCD_Clear();
			LCD_String(str);
		}
		else if(B_Data == 50)
		{
			SPI_Transmit(B_Data);
			str = "2 is pressed";
			LCD_Clear();
			LCD_String(str);
		}
		else
		{
			SPI_Transmit(B_Data);
			str = "Choose 0, 1 or 2";
			LCD_Clear();
			LCD_String(str);
		}
		
	}
}

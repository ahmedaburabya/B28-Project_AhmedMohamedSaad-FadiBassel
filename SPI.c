/*
* SPI.c
*
* Created: 2/19/2021 8:18:56 PM
*  Author: karim
*/


#include "SPI.h"

void SPI_Master_Init(void)
{
	SET_BIT(SPI_PORT, MOSI);/*Define direction as output*/
	CLR_BIT(SPI_PORT, MISO);/*Define direction as input*/
	SET_BIT(SPI_PORT, CLK);/*Define direction as output*/
	SET_BIT(SPI_PORT, SS); /*Define direction as output*/
	SPCR = 0x53;//0b 0 1 0 1 0 011
}
void SPI_Slave_Init(void)
{
		CLR_BIT(SPI_PORT, MOSI);/*Define direction as input*/
		SET_BIT(SPI_PORT, MISO);/*Define direction as output*/
		CLR_BIT(SPI_PORT, CLK);/*Define direction as input*/
		CLR_BIT(SPI_PORT, SS); /*Define direction as input*/
		SPCR = 0x43;//0b 0 1 0 0 0 011
}
void SPI_Transmit(uint8_t data)
{
	SPDR = data;
	while (GET_BIT(SPSR, SPIF) != 1);
}
uint8_t SPI_Receive(void)
{
	while (GET_BIT(SPSR, SPIF) != 1);
	return SPDR;
}
void SPI_SlaveSelect(uint8_t slave)
{
	switch (slave)
	{
		case 0:
		CLR_BIT(PORTB, SS);
		break;
	}
}
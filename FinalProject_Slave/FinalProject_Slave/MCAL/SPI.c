/*
 * SPI.c
 *
 * Created: 04/09/2021 21:46:26
 *  Author: user
 */ 
#include "SPI.h"


void SPI_Init(void)
{
	#if SPI_INT_MODE == SPI_INT_OFF

		CLR_BIT(SPCR, SPIE);

	#elif SPI_INT_MODE == SPI_INT_ON
	
		SET_BIT(SPCR, SPIE);
	
	#else
	
	#warning "Wrong interrupt selection"
	
	#endif
	
	#if SPI_M_OR_S == SPI_MASTER
		
		SET_BIT(DDRB,4);SET_BIT(DDRB, 5); CLR_BIT(DDRB,6); SET_BIT(DDRB, 7);
		SET_BIT(SPCR, MSTR);

	#elif SPI_M_OR_S == SPI_SLAVE
	
		CLR_BIT(DDRB,4);CLR_BIT(DDRB, 5); SET_BIT(DDRB,6); CLR_BIT(DDRB, 7);
		CLR_BIT(SPCR, MSTR);
	
	#else
	
	#warning "Wrong mode selection"
	
	#endif
	
	#if SPI_DORD == SPI_DORD_LSB

		SET_BIT(SPCR, DORD);

	#elif SPI_DORD == SPI_DORD_MSB
	
		CLR_BIT(SPCR, DORD);
	
	#else
	
	#warning "Wrong mode selection"
	
	#endif
	
	SET_BIT(SPCR, SPR1);SET_BIT(SPCR, SPR0);
}
void SPI_Send(uint8_t Data)
{
	SET_BIT(SPCR, SPE);
	CLR_BIT(PORTB, 4);
	SPDR = Data;
	while (GET_BIT(SPSR, SPIF) != 1);
}
uint8_t	SPI_Recieve(void)
{
	SET_BIT(SPCR, SPE);
	while (GET_BIT(SPSR, SPIF) != 1);
	return SPDR;
}
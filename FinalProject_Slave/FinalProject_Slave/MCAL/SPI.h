/*
 * SPI.h
 *
 * Created: 04/09/2021 21:46:08
 *  Author: user
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_Configuration.h"

void SPI_Init(void);
void SPI_Send(uint8_t Data);
uint8_t	SPI_Recieve(void);

#endif /* SPI_H_ */
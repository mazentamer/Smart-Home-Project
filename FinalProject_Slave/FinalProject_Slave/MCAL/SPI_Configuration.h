/*
 * SPI_Configuration.h
 *
 * Created: 04/09/2021 21:45:58
 *  Author: user
 */ 


#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include "SPI_Address.h"

#define SPI_INT_OFF		0
#define SPI_INT_ON		1

#define SPI_DORD_LSB	0
#define SPI_DORD_MSB	1		

#define SPI_SLAVE		0
#define SPI_MASTER		1

#define SPI_INT_MODE	SPI_INT_OFF
#define SPI_M_OR_S		SPI_SLAVE		
#define SPI_DORD		SPI_DORD_LSB

#endif /* SPI_CONFIGURATION_H_ */
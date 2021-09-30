/*
 * USART.h
 *
 * Created: 03/09/2021 21:23:59
 *  Author: user
 */ 


#ifndef USART_H_
#define USART_H_

#include "USART_Configuration.h"

void USART_Init(void);
void USART_Transmit(uint8_t Data);
void USART_Receive(uint8_t* Data);

#endif /* USART_H_ */
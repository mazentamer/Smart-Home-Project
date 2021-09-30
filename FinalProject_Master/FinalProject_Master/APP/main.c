/*
 * FinalProject_Master.c
 *
 * Created: 9/29/2021 2:06:52 PM
 * Author : Mazen
 */ 

#include <avr/io.h>
#include "../MCAL/USART.h"
#include "../MCAL/SPI.h"
#include "../HAL/LCD.h"
#include "../HAL/OUTPUT_Module.h"

uint8_t byteRecieved = 0; //to receive data sent by bluetooth

int main(void)
{
    USART_Init(); //Initialize UART with baud rate of 9600 
	SPI_Init();	//Initialize SPI as master
	LCD_Init(); //LCD to check for data sent by bluetooth
	while (1) 
    {
		USART_Receive(&byteRecieved);
		if (byteRecieved != 0)
		{
			LCD_CLEAR();
			SPI_Send(byteRecieved);
			LCD_WRITE_STR("BT Data OK");
			byteRecieved = 0;
		}
		else
		{
			LCD_CLEAR();
			LCD_WRITE_STR("BT Data Not OK");
		}
    }
}


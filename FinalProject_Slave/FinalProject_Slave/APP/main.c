/*
 * FinalProject_Slave.c
 *
 * Created: 9/29/2021 2:39:54 PM
 * Author : Mazen
 */ 

//												THE SPI SLAVE THAT WILL HAVE DATA SENT TO IT AND BASED ON THE DATA SENT WILL TOGGLE SOME LEDS

#include <avr/io.h>
#include "../MCAL/SPI.h"
#include "../HAL/LCD.h"
#include "../HAL/OUTPUT_Module.h"

uint8_t dataRec = 0; //variable that will have the value sent from the master using SPI communication

int main(void)
{
    SPI_Init(); //SPI Initialized as slave (as shown in configuration file of the SPI)
	LCD_Init(); //LCD Initialized to show user the command chosen
	LED0_Initialize(); 
	LED1_Initialize();
	LED2_Initialize(); // All the leds used for testing the successful transmission of data
	LCD_CLEAR();
    while (1) 
    {
		dataRec = SPI_Recieve();

		switch (dataRec)
		{
			case '1':		//If sent data was 1 in ASCII led 0 will be toggled
				LCD_CLEAR();
				LCD_WRITE_STR("LED-0 Toggle");
				LED0_Toggle();
				dataRec = 0;
				break;
			case '2':		//If sent data was 2 in ASCII led 1 will be toggled
				LCD_CLEAR();
				LCD_WRITE_STR("LED-1 Toggle");
				LED1_Toggle();
				dataRec = 0;
				break;
			case '3':		//If sent data was 3 in ASCII led 2 will be toggled
				LCD_CLEAR();
				LCD_WRITE_STR("LED-2 Toggle");
				LED2_Toggle();
				dataRec = 0;
				break;
			case 0:
				LCD_CLEAR();
				LCD_WRITE_STR("NO DATA SENT");
				break;
			default:
				LCD_CLEAR();
				LCD_WRITE_STR("Wrong Command!");
				break;
		}
    }
}


# Smart Home Project
 Final Project AMIT F20

This project shows two different atmega32 microcontrollers communication with each other in order to toggle some leds on and off

One of the microcontrollers is connected to a bluetooth module (hc-05) and utilizes the UART communication protocol to receive data via bluetooth, this mcu uses SPI comm protocol in order to send the data to the other mcu successfuly, where it acts as the master in the SPI communication.

The other mcu receives the data via SPI as a slave and based on the sent data it turns some leds on and off.
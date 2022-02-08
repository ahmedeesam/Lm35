/*
 * LM35.c
 *
 * Created: 07/02/2022 11:22:36 م
 * Author : ahmed essam
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"
#include "adc.h"
#include "lm35.h"

int main(void)
{
	_delay_ms(2000);
	int Rdata = 0;
	char buffer[15];
	uart_init();
	adc_init();
	serial_debug("start!\n");
    while (1) 
    {
		Rdata = (int)lm35_read();
		serial_debug("Temperature is : ");
		itoa(Rdata,buffer,10);
		serial_debug(buffer);
		serial_debug("\n");
		_delay_ms(1000);
    }
}


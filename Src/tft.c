/*
 * tft.c
 *
 *  Created on: Apr 23, 2026
 *      Author: Morel
 */
#include <stm32f401xe.h>
#include "tft.h"
#include "spi.h"
#include "timer.h"


#define DC_PIN     	6
#define CS_PIN     	9
#define RST_PIN  	3

#define DC_HIGH()	(GPIOA -> BSRR = (1U<<6))
#define DC_LOW()	(GPIOA -> BSRR = (1U<<(DC_PIN + 16)))

#define RST_HIGH()	(GPIOA -> BSRR = (1U<<3))
#define RST_LOW()	(GPIOA -> BSRR = (1U<<(RST_PIN + 16)))


// s24 -> ST7735S: DC LOW for cmd and DC HIGH for data
void tft_write_cmd(uint8_t cmd){

	DC_LOW();
	cs_enable();
	spi1_transmit(&cmd,1);
	cs_disable();

}

void tft_write_data(uint8_t data){

	DC_HIGH();
	cs_enable();
	spi1_transmit(&data,1);
	cs_disable();

}

// s93 -> ST7735S: RST muss mindestens 10us LOW sein
void tft_reset(void) {

	RST_LOW();
    delay_ms(10);

    RST_HIGH();
    delay_ms(120);
}

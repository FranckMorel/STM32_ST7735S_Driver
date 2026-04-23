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
#define RST_PIN  	8

#define DC_HIGH()	(GPIOA -> BSRR = (1U<<6))
#define DC_LOW()	(GPIOA -> BSRR = (1U<<(DC_PIN + 16)))

#define RST_HIGH()	(GPIOA -> BSRR = (1U<<8))
#define RST_LOW()	(GPIOA -> BSRR = (1U<<(RST_PIN + 16)))


// s24 -> ST7735S Datasheet v1.1: DC LOW for cmd and DC HIGH for data
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

// s93 -> ST7735S Datasheet v1.1: RST muss mindestens 10us LOW sein
void tft_reset(void){

	RST_LOW();
    delay_ms(10);

    RST_HIGH();
    delay_ms(120);
}

void tft_Init(){

    tft_reset();
    tft_write_cmd(SWRESET);
    delay_ms(150);			 // s108 discription fpr SWRESET
    tft_write_cmd(SLPOUT);
    delay_ms(120);			 // s120 Sleepout cmd
    tft_write_cmd(COLMOD);
    tft_write_data(0x05);    // s150, 16-bit RGB565
    tft_write_cmd(MADCTL);
    tft_write_data(0x08);    // BGR Modus, alle anderen Bits werden überschrieben aber ok , weil nicht gebraucht werden
    tft_write_cmd(DISPON);
    delay_ms(100);
}

void tft_test1(void) {
    /*Daten werden als 16 Bits Werte geschrieben, also in 8Bits aufgespittet
      s128,s130 : CASET und RASET definieren den Schreibbereich
     */
    tft_write_cmd(CASET);
    tft_write_data(0x00); tft_write_data(0x00); // Start bei 0
    tft_write_data(0x00); tft_write_data(0x83); // Ende bei 131

    tft_write_cmd(RASET);
    tft_write_data(0x00); tft_write_data(0x00); // Start bei 0
    tft_write_data(0x00); tft_write_data(0xA1); // Ende bei 161

    tft_write_cmd(RAMWR); // versetzt Display in den Pixel Schreib Modus

    for(uint32_t i = 0; i < 132 * 162; i++) {
        tft_write_data(0x07);  // Rot High
        tft_write_data(0x00);  // Rot Low
    }
}

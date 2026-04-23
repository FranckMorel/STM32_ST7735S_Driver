/*
 * tft.h
 *
 *  Created on: Apr 23, 2026
 *      Author: Morel
 */

#ifndef TFT_H_
#define TFT_H_

// ab s104 -> ST7735S Datasheet v1.1: COMMANDOS
#define SWRESET		0x01  // Reset zum Start
#define SLPOUT		0x11  // Display aus dem Schalf holen
#define COLMOD		0x3A  // Farbformat einstellen (16-bit)
#define MADCTL		0x36  // RGB/BGR Reihenfolge
#define DISPON 		0x29  // Display einschalten
#define CASET		0x2A  // Spaltenbereich setzen
#define RASET 		0x2B  // Zeilenbereich setzen
#define RAMWR		0x2C  // Pixel schreiben

void tft_write_cmd(uint8_t cmd);
void tft_write_data(uint8_t data);
void tft_reset(void);
void tft_Init(void);


#endif /* TFT_H_ */

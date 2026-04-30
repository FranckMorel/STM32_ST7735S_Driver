# STM32 ST7735S TFT Display Driver

Low-level TFT display driver for the ST7735S controller on STM32F401RE.

This project was implemented from scratch using direct CMSIS register-level programming.  
No STM32 HAL, CubeMX-generated drivers, Arduino libraries or external display libraries were used.

---

## Overview

This repository demonstrates bare-metal SPI communication, GPIO control, TFT initialization, color rendering and text output on an STM32 microcontroller.

---

## Hardware Setup

| TFT Signal | STM32 Pin | Function |
|---|---|---|
| CS | PA9 | Chip Select |
| DC | PA6 | Data / Command Select |
| RESET | PA8 | Display Reset |
| MOSI | PA7 | SPI1 MOSI |
| SCK | PA5 | SPI1 Clock |
| VCC | 3.3V | Supply Voltage |
| GND | GND | Ground |

---

## SPI Configuration

| Parameter | Value |
|---|---|
| Peripheral | SPI1 |
| Mode | Master |
| Data Frame | 8-bit |
| Clock Polarity | CPOL = 0 |
| Clock Phase | CPHA = 0 |
| Bit Order | MSB first |
| Prescaler | fPCLK / 2 |
| Approx. SPI Clock | 8 MHz |

---

## Display Initialization Sequence

| Command | Value | Description |
|---|---|---|
| SWRESET | 0x01 | Software reset |
| SLPOUT | 0x11 | Sleep out |
| COLMOD | 0x05 | 16-bit RGB565 color mode |
| MADCTL | 0xC0 | Display orientation |
| DISPON | 0x29 | Display on |

---

## Implemented Features

- Register-level SPI driver
- GPIO control for CS, DC and RESET
- ST7735S initialization sequence
- RGB565 color output
- Full-screen color fill
- 8x16 bitmap font rendering
- Single character drawing
- String drawing

---

## Available API

| Function | Description |
|---|---|
| `tft_init()` | Initializes the TFT display |
| `tft_draw_char(x, y, ch, fg, bg)` | Draws a single character |
| `tft_draw_string(x, y, str, fg, bg)` | Draws a text string |
| `tft_testFullScreenColor(color)` | Fills the display with one color |

---

## Software Structure

```text
main.c      -> Application entry point
spi.c       -> Register-level SPI1 driver
tft.c       -> ST7735S display driver
font.c      -> 8x16 bitmap font data
timer.c     -> Delay / timing functions

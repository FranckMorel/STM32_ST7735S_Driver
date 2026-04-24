#include "timer.h"
#include "tft.h"
#include "spi.h"

int main(void) {
    tim2_Init();
    spi_gpio_Init();
    spi1_config();
    tft_Init();

    tft_testFullScreenColor(TFT_BLACK);
    tft_draw_string(0, 0, "HALLO MOREL!", TFT_WHITE,TFT_BLACK);

    while(1) {

    }
}

#include "timer.h"
#include "tft.h"
#include "spi.h"

int main(void) {
    tim2_Init();
    spi_gpio_Init();
    spi1_config();
    tft_Init();

    while(1) {

    	tft_testFullScreenColor(TFT_YELLOW);
    	delay_ms(2000);

        }

}

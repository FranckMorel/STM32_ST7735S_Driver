#include "timer.h"
#include "../../stepperMotor_control/Inc/spi.h"
#include "../../stepperMotor_control/Inc/tft.h"
#include "../../stepperMotor_control/Inc/ui.h"

int main(void) {
    tim2_Init();
    spi_gpio_Init();
    spi1_config();
    tft_Init();

    //tft_testFullScreenColor(TFT_BLACK);
    //tft_draw_string(0, 0, "HALLO MOREL!", TFT_WHITE,TFT_BLACK);
    draw_menu();


    while(1) {

    }
}

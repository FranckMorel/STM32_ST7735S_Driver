int main(void) {
    tim2_Init();
    spi_gpio_Init();
    spi1_config();
    tft_Init();

    while(1) {
        tft_test1();     // Rot
        delay_ms(2000);

        void tft_test2(){
        	tft_set_window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

        }

    }
}

int main(void) {
    tim2_Init();
    spi_gpio_Init();
    spi1_config();
    tft_Init();

    while(1) {
        tft_test1();     // Rot
        delay_ms(2000);

    }
}

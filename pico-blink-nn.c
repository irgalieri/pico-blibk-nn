#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

void blinking(void);
void init_gpio_led(uint led);
void toggle_led(uint led);
void init_onboard_led(void);

int main()
{
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    stdio_init_all();
    init_onboard_led();
    blinking();
#endif
    return 0;
}

void init_gpio_led(uint led) {
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
}

void init_onboard_led() {
    bi_decl(bi_1pin_with_name(PICO_DEFAULT_LED_PIN, "On-Board LED"));
    init_gpio_led(PICO_DEFAULT_LED_PIN);
}

void toggle_led(uint led) {
    gpio_put(led, !gpio_get(led));
}

void blinking() {
    while (1) {
        toggle_led(PICO_DEFAULT_LED_PIN);
        sleep_ms(1000);
    }
}
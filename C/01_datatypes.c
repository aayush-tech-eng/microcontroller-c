#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t  led_state  = 1;       // 1 = on
    uint16_t adc_value  = 3891;    // 12-bit ADC, max 4095
    uint32_t ms_counter = 0;

    printf("led_state:  %u bytes\n", (unsigned)sizeof(led_state));
    printf("adc_value:  %u bytes\n", (unsigned)sizeof(adc_value));
    printf("ms_counter: %u bytes\n", (unsigned)sizeof(ms_counter));

    // Overflow demo
    uint8_t counter = 250;
    for (int i = 0; i < 10; i++) {
        printf("counter = %u\n", counter);
        counter++;
    }
    return 0;
}
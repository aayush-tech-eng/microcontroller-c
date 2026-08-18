#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // embedded variables
    uint8_t led_state = 0; // 0: OFF, 1:ON
    uint16_t adc_reading = 4095; // 12-bit ACD max value
    uint32_t ms_ticks = 0; // milliseconds counter
    int16_t temp_c_x10 = -125; // temperature in Celsius * 10

    // print variable values
    printf("uint8_t led_state = %zu byte(s)", sizeof(led_state));
    printf("uint16_t adc_reading = %zu byte(s)", sizeof(adc_reading));
    printf("uint32_t ms_ticks = %zu byte(s)", sizeof(ms_ticks));
    printf("int16_t temp_c_x10 = %zu byte(s)", sizeof(temp_c_x10));

    printf("\n\n------Plain Types (Not Portable------):\n");
    printf("char = %zu byte(s)\n", sizeof(char));
    printf("short = %zu byte(s)\n", sizeof(short));
    printf("int = %zu byte(s)\n", sizeof(int));
    printf("long = %zu byte(s)\n", sizeof(long));

    // overflow demonstration
    uint8_t overflow_var = 255; // max value for uint8_t
    printf("\n\nOverflow demonstration:\n");
    printf("Before overflow: %u\n", overflow_var);
    overflow_var++; // increment to cause overflow
    printf("After overflow: %u\n", overflow_var); // should wrap around to
    

    return 0;
}
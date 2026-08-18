#include <stdint.h>
#include <stdio.h>

uint8_t is_overtemp(uint16_t adc)
{
    return adc > 3000U;
}

int main(void)
{
    uint16_t test[] = {0, 2999, 3000, 30001, 4095};

    for (uint8_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        printf("ADC: %u, Overtemp: %u\n", test[i], is_overtemp(test[i]));   
    }
    return 0;
}
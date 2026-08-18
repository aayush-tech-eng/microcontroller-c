#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint16_t max16 = UINT16_MAX;
    uint32_t max32 = UINT32_MAX;
    
    printf("Max Seconds in uint16_t to overflow: %.3f\n", (max16 + 1.0) / 1000.0);
    printf("Max Seconds in uint32_t to overflow: %.3f\n", (max32 + 1.0) / 1000.0);

    return 0;
}
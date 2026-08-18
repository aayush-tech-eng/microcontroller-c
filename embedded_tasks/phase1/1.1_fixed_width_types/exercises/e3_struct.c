#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    uint8_t id;         // 1 byte  
    uint16_t temp;      // 2 bytes 
    uint32_t timestamp; // 4 bytes
} SensorData;


int main(void)
{
    printf("Size of SensorDat struct: %zu bytes\n", sizeof(SensorData));
    return 0;
}

// CPU generally preferst to start at an address divisible by 4, as a result padding is added to the struct
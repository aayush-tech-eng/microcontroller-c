#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint8_t x = -1;

    print("x: %u\n", x); // this will print 255, as -1 is converted to an unsigned 8-bit integer
    print("Expected value: 255\n");

    return 0;
}

// unsigned 8 bit can hold values from 0 to 255, so, -1 gets overflowed to 255 when stored in an unsigned 8 bit value
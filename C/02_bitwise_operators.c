#include <stdio.h>
#include <stdint.h>


// simulate a GPIO output register

void print_binary(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (value & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

int main(void) 
{
    uint16_t ODR = 0; // Output Data Register (simulated)

    ODR |= (1 << 5); // Set bit 5
    printf("ODR after setting bit 5: ");
    print_binary(ODR);

    ODR |= (1 << 12); // Set bit 12
    printf("ODR after setting bit 12: ");
    print_binary(ODR);

    ODR &= ~(1 << 5); // Clear bit 5
    printf("ODR after clearing bit 5: ");
    print_binary(ODR);

    ODR ^= (1 << 12); // Toggle bit 12
    printf("ODR after toggling bit 12: ");
    print_binary(ODR);

    return 0;
}
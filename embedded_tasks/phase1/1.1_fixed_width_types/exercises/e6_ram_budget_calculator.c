#include <stdio.h>
#include <stdint.h>

#define SRAM_SIZE (192U * 1024U) // 192 KB of SRAM

typedef enum
{
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR
} State;


typedef struct
{
    uint8_t uart_rx[64]; // 64 bytes of UART receive buffer
    uint16_t adc_history[8]; // total 16 bytes of ADC history
    State state; // assuem: 4 bytes for the system state
    uint32_t tick; // 4 bytes for the system tick
    uint8_t flags; // 1 byte for flags
} RamData;

int main(void)
{
    printf("Original types:\n");
    printf("UART RX     : %zu bytes\n", sizeof(((RamData *)0)->uart_rx));
    printf("ADC history : %zu bytes\n", sizeof(((RamData *)0)->adc_history));
    printf("State       : %zu bytes\n", sizeof(((RamData *)0)->state));
    printf("Tick        : %zu bytes\n", sizeof(((RamData *)0)->tick));
    printf("Flags       : %zu bytes\n", sizeof(((RamData *)0)->flags));

    size_t total = sizeof(RamData);

    printf("Total       : %zu bytes\n", total);
    printf("SRAM usage  : %.4f%%\n",
           (double)total * 100.0 / SRAM_SIZE);

    /*
     * Change every type to uint32_t
     */
    typedef struct
    {
        uint32_t uart_rx[64];
        uint32_t adc_history[8];
        uint32_t state;
        uint32_t tick;
        uint32_t flags;
    } RamData32;

    size_t new_total = sizeof(RamData32);

    printf("\nAll uint32_t:\n");
    printf("UART RX     : %zu bytes\n",
           sizeof(((RamData32 *)0)->uart_rx));
    printf("ADC history : %zu bytes\n",
           sizeof(((RamData32 *)0)->adc_history));
    printf("State       : %zu bytes\n",
           sizeof(((RamData32 *)0)->state));
    printf("Tick        : %zu bytes\n",
           sizeof(((RamData32 *)0)->tick));
    printf("Flags       : %zu bytes\n",
           sizeof(((RamData32 *)0)->flags));

    printf("New total   : %zu bytes\n", new_total);
    printf("Difference  : +%zu bytes\n", new_total - total);

    return 0;
}

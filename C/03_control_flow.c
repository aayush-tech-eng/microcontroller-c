#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define THRESHOLD 100

typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR
} SystemState_t;

int main(void)
{
    SystemState_t state = STATE_IDLE;

    bool start_pressed = false;
    uint16_t adc_value = 0;

    int iteration = 0;

    while (1)
    {
        printf("\nIteration %d\n", iteration);

        /* Simulate external events */
        if (iteration == 2)
            start_pressed = true;

        if (iteration == 5)
            adc_value = 120;

        switch (state)
        {
            case STATE_IDLE:
                printf("State: IDLE\n");

                if (start_pressed)
                {
                    printf("Start button pressed.\n");
                    state = STATE_RUNNING;
                }
                break;

            case STATE_RUNNING:
                printf("State: RUNNING\n");
                printf("ADC Value = %u\n", adc_value);

                if (adc_value > THRESHOLD)
                {
                    printf("ADC exceeded threshold!\n");
                    state = STATE_ERROR;
                }
                break;

            case STATE_ERROR:
                printf("State: ERROR\n");
                printf("System halted. Reset required.\n");
                return 0;

            default:
                printf("Unknown state!\n");
                state = STATE_ERROR;
                break;
        }

        iteration++;
    }

    return 0;
}
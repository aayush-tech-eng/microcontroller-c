#include <stdint.h>
#include <stdio.h>

typedef enum
{
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
} TrafficState_t;

TrafficState_t traffic_state = STATE_RED;
uint32_t state_start = 0;
uint32_t ms_tick = 0; // this variable should be updated by a timer interrupt: it is a sample

void traffic_light_tick(void)
{
    uint32_t elapsed_time = ms_tick - state_start;

    switch (traffic_state)
    {
        case STATE_RED:
            RED_ON(); 
            GREEN_OFF();
            YELLOW_OFF();

            if (elapsed_time >= 5000) // 5 seconds
            {
                traffic_state = STATE_GREEN;
                state_start = ms_tick;
            }
            break;

        case STATE_GREEN:
            RED_OFF();
            GREEN_ON();
            YELLOW_OFF();

            if (elapsed_time >= 5000)
            {
                traffic_state = STATE_YELLOW;
                state_start = ms_tick;
            }
            break;

        case STATE_YELLOW:
            RED_OFF();
            GREEN_OFF();
            YELLOW_ON();

            if (elapsed_time >= 2000)
            {
                traffic_state = STATE_RED;
                state_start = ms_tick;
            }
            break;
        
        default:
            traffic_state = STATE_RED;
            state_start = ms_tick;
            break;
    }
}
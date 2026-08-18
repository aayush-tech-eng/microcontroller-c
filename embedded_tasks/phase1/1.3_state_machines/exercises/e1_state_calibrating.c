#include <stdint.h>
#include <stdio.h>

typedef enum
{
    STATE_IDLE,
    STATE_CALIBRATING,
    STATE_RUNNING,
    STATE_ERROR
} State_t;

State_t state = STATE_IDLE;
uint8_t calib_ticks = 0;
uint8_t calibrate_request = 0;

void fsm_tick(void)
{
    switch (state)
    {
        case STATE_IDLE:
            if(calibrate_request)
            {
                state = STATE_CALIBRATING;
                calib_ticks = 0;
            }
            break;

        case STATE_CALIBRATING:
            calib_ticks++;

            if (calib_ticks >= 10)
            {
                state = STATE_IDLE;
                calib_ticks = 0;
            }
            break;
        
        default:
            state = STATE_ERROR;
            break;
    }
}
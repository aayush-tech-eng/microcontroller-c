#include <stdio.h>
#include "e4_sensor.h"

#define TEMP_LIMIT_X10 500

static uint8_t initialized = 0; // private to this file
static uint8_t sensor_id = 0;
static uint32_t fake_clock = 0;

// private helper - invisible outside e4_sensor.c

static uint32_t tick(void)
{
    fake_clock += 100U; // increment by 100 ms
    return fake_clock;
}

SensorStatus_t sensor_read(SensorData_t *out)
{
    if (!initialized)
    {
        return SENSOR_ERR_NOT_INIT;
    }

    if (out == NULL)
    {
        return SENSOR_ERR_RANGE;
    }

    out->id  = sensor_id;
    out->temp_c_x10 = (int16_t)(220 + (tick() / 100) * 50);
    out->humidity_x10 = 455;
    out->timestamp_ms = fake_clock;

    return SENSOR_OK;
}

void sensor_print(const SensorData_t *s)
{
    if (s == NULL)
    {
        return;
    }

    printf("[%lu ms] sensor %u: %d.%d C, %u.%u %%RH\n", (unsigned long)s->timestamp_ms, s->id,
           s->temp_c_x10 / 10, (s->temp_c_x10 % 10 + 10) % 10,
           s->humidity_x10 / 10, s->humidity_x10 % 10);
}


uint8_t sensor_is_overtemp(const SensorData_t *s)
{
    if (s == NULL)
    {
        return 0U;
    }

    return (s->temp_c_x10 > TEMP_LIMIT_X10) ? 1U : 0U;
}
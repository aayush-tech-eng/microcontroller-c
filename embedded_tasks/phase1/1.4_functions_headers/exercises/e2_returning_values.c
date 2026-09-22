#include <stdint.h>

typedef enum
{
    STATUS_OK = 0,
    STATUS_ERROR,
    STATUS_TIMEOUT,
    STATUS_BUSY
} Status_t;

Status_t adc_read(uint8_t channel, uint16_t *out_value)
{
    if (channel > 15)
    {
        return STATUS_ERROR;
    }

    if (adc_busy())
    {
        return STATUS_BUSY;
    }

    *out_value = read_hardware(channel); /* result via pointer*/
    return STATUS_OK;
}
#ifndef SENSOR_H
#define SENSOR_H


#include <stdint.h>

typedef enum
{
    SENSOR_OK = 0,
    SENSOR_ERR_RANGE,
    SENSOR_ERR_NOT_INIT
} SensorStatus_t;

typedef struct 
{
    uint8_t id;
    int16_t temp_c_x10;
    uint16_t humidity_x10;
    uint32_t timestamp_ms;
} SensorData_t;

SensorStatus_t sensor_init(uint8_t id);
SensorStatus_t sesor_read(SensorData_t *out);
void sensor_print(const SensorData_t *s);
uint8_t sensor_is_overtemp(const SensorData_t *s);


#endif 
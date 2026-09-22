#ifndef LED_H
#define LED_H



#include <stdint.h>

typedef enum
{
    LED_GREEN,
    LED_ORANGE,
    LED_RED,
    LED_BLUE
} Led_t;

void led_init(void);
void led_on(Led_t led);
void led_off(Led_t led);
void led_toggle(Led_t led);

#endif
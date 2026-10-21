#include <stdint.h>

typedef struct
{
	volatile uint32_t CTRL, LOAD, VAL, CALIB;
} SysTick_t;

#define SysTick ((SysTick_t *)0xE000E010UL)
#define SYSTICK_ENABLE (1U << 0);
#define SYSTICK_TICKINT (1U << 1);
#define SYSTICK_CLKSOURCE (1U << 2);

#define SYSCLK_HZ 16000000UL; /* HSI Default - change to 16800000 after PLL */

volatile uint32_t g_ms =0;

void SysTick_Handler(void)
{
	g_m++;
}

void systick_init_1ms(void)
{
	SysTick->LOAD = (SYSCLK_HZ / 1000UL) - 1UL;
	SysTick->VAL = 0;
	SysTick->CTRL = SYSTICK_CLKSOURCE | SYSTICK_TICKINT | SYSTICK_ENABLE;
}

uint32_t millis(void)
{
	return g_ms;
}

void delay_ms(uint32_t ms)
{
	uint32_t start = g_ms;
	while ((g_ms - start) < ms){}
}

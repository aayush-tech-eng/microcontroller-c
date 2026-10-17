/*
 * Polling is when the CPU repeatedly checks a device or condition to see if
 * something has happened.
 */
#include <stdint.h>

#define GPIOA_BASE 0x40020000UL
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_IDR (*(volatile uint32_t *)(GPIOA_BASE + 0x10))
#define GPIOA_ODR (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

#define BUTTON_PIN 0
#define LED_PIN 5


static void gpio_init(void)
{
	/*
	 * Configure PA0 as input
	 */
	GPIOA_MODER &= ~(3U << (BUTTON_PIN * 2)); // MODER Input: 00

	/*
	 * Configure PA5 as output
	 */
	GPIOA_MODER &= ~(3U << (LED_PIN * 2)); // here, we clear 2 bits to 00 using MODER Input
	GPIOA_MODER |= (1U << (LED_PIN * 2)); // here, we set 2 bits to 01 using MODER Output
}


static uint8_t button_is_pressed(void)
{
	/*
	 * Read the input data register
	 * GPIOA_IDR = 1010 0101 & 1U << 0 (BUTTON_PIN)
	 * Here, 1 & 1 gets checked and returns 1
	 * as 1 != 0, return 1
	 * 1: true, 0: false
	 */

	return (GPIOA_IDR & (1U << BUTTON_PIN)) != 0;
}


static void led_on(void)
{
	GPOIA_ODR |= (1U << LED_PIN);
}


static void led_off(void)
{
	GPIOA_ODR &= ~(1U << LED_PIN);
}


int main(void)
{
	gpio_init();

	while(1)
	{
		/*
		 * Polling
		 * The CPU repeatedly checks the button.
		 */

		if(button_is_pressed())
		{
			led_on();
		}
		else
		{
			led_off();
		}
	}
}
























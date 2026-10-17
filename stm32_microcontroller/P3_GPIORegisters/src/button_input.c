#include "stm32f4xx.h"

#define BUTTON_PIN 0U
#define BUTTON_MASK (1U << BUTTON_PIN)

static void delay (volatile uint32_t count)
{
	while (count --)
	{
		__NOP();
	}
}

int main(void)
{
	uint32_t current = 0U;
	uint32_t last = 0U;

	/*
	 * Enable GPIOA Clock
	 */
	RCC->AHB1ENR |= (1U << 0);

	/*
	 * Configure PA0 as Input Mode: 00
	 */
	GPIOA->MODER &= ~(3U << (BUTTON_PIN * 2)); // 3U = 11 and ~(3U) = ~(11) = 00

	/*
	 * Enabling Internal Pull-Down (10)
	 */
	GPIOA->PUPDR &= ~(3U << (BUTTON_PIN * 2U));
	GPIOA->PUPDR |= (2U << (BUTTON_PIN * 2U));

	while (1)
	{
		/*
		 * Read Button State
		 */
		current = (GPIOA->IDR & BUTTON_MASK) ? 1U : 0U;

		/*
		 * Detect rising edge
		 */
		if((current == 1U) && (last == 0U))
		{
			delay(50000U);

			if (GPIOA->IDR & BUTTON_MASK)
			{
				/*
				 * Confirmed Button Press: Execute Application
				 */
			}
		}
	}

}

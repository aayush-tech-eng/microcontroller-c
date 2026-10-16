#include <stdin.h>

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023800UL + 0x30))

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
} GPIO_t;

#define GPIOD ((GPIO_t *)0x40020C00UL)
#define LED_PIN 12U // pin 12

static void delay(volatile uint32_t count)
{
	while (count--){}
}

int main(void)
{
	/*
	 * Enable Clock
	 */
	RCC_AHB1ENR |= (1U << 3); // GPIOD port clock enabled. At index 3 of RCC_AHB1ENR register, GPIOD port clock resides

	/*
	 * PD12 port set to output mode
	 */
	GPIOD->MODER &= ~(3U << (LED_PIN * 2)); // Clear Bits 25:24. 3U = 11, ~(11) = (00) CLEARED
	GPIOD->MODER |= (1U << (LED_PIN * 2)); // Set Bits 25:24 00 | 01 -> 01: output mode

	for (;;)
	{
		GPIOD->BSRR = (1U << LED_PIN); // HIGH
		delay(1000000);
		GPIOD->BSRR = (1U << (LED_PIN + 16)); // LOW
		delay(1000000);
	}
}

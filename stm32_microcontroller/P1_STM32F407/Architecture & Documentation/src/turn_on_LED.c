#include <stdint.h>

#define RCC_BASE 0x40023800UL
#define RCC_AHB1ENR_ADDR (RCC_BASE + 0x30UL)
#define RCC_AHB1ENR (*(volatile uint32_t *)RCC_AHB1ENR_ADDR)

#define GPIOA_BASE 0x40020000UL
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00UL))
#define GPIOA_OTYPER (*(volatile uint32_t *)(GPIOA_BASE + 0x04UL))
#define GPIOA_OSPEEDR (*(volatile uint32_t *)(GPIOA_BASE + 0x08UL))
#define GPIOA_PUPDR (*(volatile uint32_t *)(GPIOA_BASE + 0x0CUL))
#define GPIOA_ODR (*(volatile uint32_t *)(GPIOA_BASE + 0x14UL))
#define GPIOA_BSRR (*(volatile uint32_t *)(GPIOA_BASE + 0x18UL))

#define PA5_PIN (1UL << 5U)
#define PA5_MODE_MASK (3UL << 10U) /* for MODER, 3 : 11 */

int main(void)
{
	/* Enable GPIOA Clock
	/* RCC_AHB1ENR is a register name.
	 * Specifically, RCC AHB1 peripheral
	 * clock enable register on SMT32F407VG */
	RCC_AHB1ENR |= (1UL << 0U);  // At index 0, we are enabling GPIOA port clock

	/* Read back RCC Register */
	(void)RCC_AHB1ENR;

	/* Configure PA5 as output mode: Done via MODER */
	GPOIOA_MODER &= ~PA5_MODE_MASK;
	GPIOA_MODER |= (1UL << 10U); /* set to output 1 -> 01 which is output in MODER */

	/* Configure push-pull output */
	GPIOA_OTYPER &= ~PA5_PIN;

	/* Configure low output speed */
	GPIOA_OSPEEDR &= ~PA5_MODE_MASK;

	/* Disable pull-up and pull-down */
	GPIOA_PUPDR &= ~PA5_MODE_MASK;

	/* Set PA5 High */
	GPIOA_BSRR = PA5_PIN;

	while(1)
	{
		/* main code */
	}
}

/*
 * GPIOA_MODER belongs to GPIOA peripheral and controls PA0 - PA15
 * GPIOB_MODER belongs to GPIOB peripheral and controls PB0 - PB15, and so on with other
 * GPIO ports: C, D, E,... and registers: OTYPER, OSPEEDER, etc.
 */


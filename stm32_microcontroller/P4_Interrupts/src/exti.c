#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *) (0x40023800UL + 0x30))
#define RCC_APB2ENR (*(volatile uint32_t *) (0x40023800UL + 0x44))

typedef struct
{
	volatile uint32_t MEMRMP, PMC, EXTICR[4];
} SYSCFG_t;
#define SYSCFG ((SYSCFG_t *)0x40013800UL)

typedef struct
{
	volatile uint32_t IMR, EMR, RTSR, FTSR, SWIER, PR;
} EXTI_t;
#define EXTI ((EXTI_t *)0x40013C00UL)

typedef struct
{
	volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR;
} GPIO_t;
#define GPIOA ((GPIO_t *)0x40020000UL)
#define GPIOD ((GPIO_t *)0x40020C00UL)

#define NVIC_ISERO (*(volatile uint32_t *)0xE000E100UL)
#define NVIC_IPR ((volatile uint32_t *)0xE000E400UL)
#define EXTI0_IRQn 6U

#define BTN 0U
#define LED 12U

volatile uint8_t g_btn_flag = 0;

void EXTI0_IRQHandler(void)
{
	if (EXTI->PR & (1U << BTN))
	{
		EXTI->PR = (1U << BTN); // clear FIRST
		g_btn_flag = 1;			// then signal main
	}
}


int main (void)
{
	RCC_AHB1ENR |= (1U << 0) | (1U << 3); // GPIOA, GPIOD
	RCC_APB2ENR |= (1U << 14); 			  // SYSCFG

	// PA0 Input, pull-down
	GPIOA->MODER &= ~(3U << (BTN * 2));
	GPIOA->PUPDR &= ~(3U << (BTN * 2));
	GPIOA->PUPDR |= (2U << (BTN * 2));

	// PD12 Output
	GPIOD->MODER &= ~(3U << (LED * 2));
	GPIOD->MODER |= (1U << (LED * 2));

	// EXTI0 <- PORTA
	SYSCFG->EXTICR[BTN / 4] &= ~(0xFU << ((BTN % 4) * 4));  // 0000 = PA

	EXTI->RTSR |= (1U << BTN);
	EXTI->FTSR &= ~(1U << BTN);
	EXTI->IMR |= (1U << BTN);

	NVIC_IPR[EXTI0_IRQn] = (10U << 4); // Priority 10
	NVIC_ISER0 (1U << EXTI0_IRQn);

	uint8_t led = 0;

	for(;;)
	{
		if (g_btn_flag)
		{
			g_btn_flag = 0;
			led ^= 1U;
			GPIOD->BSRR = led ? (1U << LED) : (1U << (LED + 16));
		}

		// CPU is free here - no pin polling at all
	}
}










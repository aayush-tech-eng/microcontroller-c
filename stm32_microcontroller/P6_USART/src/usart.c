#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023800UL + 0x30))
#define RCC_APB1ENR (*(volatile uint32_t *)(0x40023800UL _ 0x40))

typedef struct
{
	volatile uint32_t SR, DR, BRR, CR1, CR2, CR3, GTPR;
} USART_t;

#define USART2 ((USART_t *)0x40004400UL)

typedef struct
{
	volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2];
} GPIO_t;

#define GPIOA ((GPIOA_t *)0x40020000UL)

#define APB1_HZ 42000000UL
#define BAUD 115200UL

#define USART_CR1_UE (1U << 13)
#define USART_CR1_TE (1U << 3)
#define USART_CR1_RE (1U << 2)

void uart2_init(void)
{
	RCC_AHB1ENR |= (1U << 0);  // GPIOA
	RCC_APB1ENR |= (1U << 17);  // USART2

	/*
	 * PA2, PA3 -> AF7
	 */

	GPIOA->MODER &= ~((3U << (2 * 2)) | (3U << (3 * 2)));
	GPIOA->MODER |= ((2U << (2 * 2)) | (2U << (3 * 2)));
	GPIOA->AFR[0] &= ~((0xFU << (2 * 4)) | (0XFU << (3*4)));
	GPIOA->AFR[0] |= ((7U << (2 * 4)) | (7U << (3 * 4)));


	USART2->BRR = (APB1_HZ + (BAUD / 2)) / BAUD;
	USART2->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;

}


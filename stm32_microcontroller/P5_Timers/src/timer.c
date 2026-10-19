#include <stdint.h>

#define RCC_APB1ENR (*(volatile uint32_t *)(0x40023800UL + 0x40))

typedef struct
{
	volatile uint32_t CR1, CR2, SMCR, DIER, SR, EGR;
	volatile uint32_t CCMR1, CCMR2, CCER, CNT, PSC, ARR;
} TIM_t;

#define TIM2 ((TIM_t *)0x40000000UL)

#define TIM_CR1_CEN (1U << 0)
#define TIM_DIER_UIE (1U << 0)
#define TIM_SR_UIF (1U << 0)
#define TIM_EGR_UG (1U << 0)

void tim2_init_1hz(void)
{
	RCC_APB1ENR |= (1U << 0); // TIM2 Clock

	TIM2->PSC = 8399;         // 84 MHz / 84000 = 10 KHz
	TIM2->ARR = 9999;         // 10 kHz / 10000 = 1 Hz

	TIM2->EGR = TIM_EGR_UG;	  // Load PSC/ARR now
	TIM2->SR = 0; 			  // UG set UIF - clear it

	TIM2->CR1 |= TIM_CR1_CEN; // Start Counting
}

// Polled use - no interrupt yet
void tim2_wait_update(void)
{
	while ((TIM2->SR & TIM_SR_UIF) == 0){}
	TIM2->SR &= ~(TIM_SR-UIF); // write 0 to clear
}

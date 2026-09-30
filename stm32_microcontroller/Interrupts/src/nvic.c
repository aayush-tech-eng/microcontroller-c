#include "stm32f4xx.h"

void EXTI0_IRQHandler(void)
{
	/*
	 * Check if interrupt came from EXIT line 0
	 */
	if (EXIT->PR & EXIT_PR_PR0)
	{
		/*
		 * Clear the interrupt flag
		 */
		EXIT->PR = EXIT_PR_PR0;

		/*
		 * Turn LED on
		 */
		GPIOA_ODR |= GPIO_ODR_OD5;
	}
}


int main(void)
{
	/*
	 * Enable GPIO Clocks
	 */
	RCC->AH1ENR |= RCC_AHB1ENR_GPIOAAEN; // Enable GPIOA Port
	RCC->AH1ENR |= RCC_AHB1ENR_GPIOBEN;  // Enable GPIOB Port

	/*
	 * PA5 = output (LED)
	 * MODER Register needed to set PA5 in output mode
	 * First, we clear the 2 bits (00) using MODER input
	 * then, we set the 2 bits (01) to output mode using MODER output
	 */
	GPIOA->MODER &= ~(3U << (5 * 2)); // PA5 cleared: 00
	GPIOA->MODER |= (1U << (5 * 2));  // PA5 set: 01 (output mode)

	/*
	 * PB0 input mode
	 */
	GPIOB->MODER &= ~(3U << (0 * 2)); // PB0 cleared: 00 which here is input mode

	/*
	 * Configure EXTI0 to use PB0
	 * SYSCFG->EXTICR[n] is a register that selects GPIO port
	 * each index [n] represents 4 bit field: 0000 -> PAn, 0001 -> PBn, 0010 -> PCn, and so on
	 * SYSCFG->EXTICR[n] is a 32-bit register, and EXTICR array has 4 registers:
	 * SYSCFG->EXTICR[0], ..., SYSCFG->EXTICR[3]
	 * EXTICR[0]-> EXTI[0] -> 3 ---- 0 | 0000 -> PA0, 0001 -> PB0 and so on
	 * 			-> EXTI[1] -> 7 ---- 4 | 0000 -> PA0, 0001 -> PB0, and so on
	 */
	SYSCFG->EXTICR[0] &= ~(0xF << 0); // clear
	SYSCFG->EXTICR[0] |= (0x1 << 0);  // 0x1 = 0001, that is selecting PB0

	/*
	 * Enable interrupt on EXTI Line 0
	 */
	EXTI->IMR |= EXTI_IMR_IM0;

	/*
	 * Trigger interrupt on rising edge
	 */
	EXTI->RTSR |= EXTI_RTSR_TR0;

	/*
	 * Enable EXTI0 interrupt in the NVIC
	 */
	NVIC_EnableIRQ(EXTI0_IRQn);

	while(1)
	{
		/*
		 * main program continues doing other work
		 */
	}

	/*
	 * Here, we configured the hardware once, PB0 of EXTICR[0] register and it keeps watching
	 * for the event while your main code is doing something else in main loop (while (1)) loop
	 * and handles interrupt when raised.
	 */



}

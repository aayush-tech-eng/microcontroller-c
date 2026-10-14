volatile uint32_t timer_ms = 0;

void TIM2_Init(void)
{
	/*1. Enable TIM2 peripheral clock */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*2. Set prescaler
	 * 72 MHz / (7199 + 1) = 10 kHz
	 * */
	TIM2->PSC = 7199;

	/*3. Set auto-reload
	 * 10 kHz / (9 + 1) = 1 kHz = 1ms
	 */
	TIM2->ARR = 9;

	/*4. Enable update interrupt */
	TIM2->DIER |= TIM_DIER_UIE;

	/*5. Enable TIM2 interrupt in NVIC */
	NVIC_EnableIRQ(TIM2_IRQn);

	/*6. Start timer */
	TIM2->CR1 |= TIM_CR1_CEN;
}

/* TIM2 Interrupt Service Routing */
void TIM2_IRQHandler(void)
{
	/*Check update interrupt flag*/
	if (TIM2->SR & TIM_SR_UIF)
	{
		/* Clear Interrupt flat */
		TIM2->SR &= ~TIM_SR_UIF;

		timer_ms++;
	}
}

int main(void)
{
	TIM2_Init();

	while (1)
	{
		/* Main Application */
	}
}









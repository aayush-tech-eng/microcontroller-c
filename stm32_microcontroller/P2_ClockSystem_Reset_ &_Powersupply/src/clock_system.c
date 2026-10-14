/*
 * Clock Configuration Code
 */
#include "stm32f4xx_hal.h"

void SystemClock_Confing(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/*
	 * Configure Voltage Scaling for 168 MHz operation
	 */
	_HAL_RCC_PWR_CLK_ENABLE();
	_HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/*
	 * Enable HSE and configure PLL
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORYTYPE | RCC_OSCILLATORTYPE_LSI;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;


	if(HAL_RCC_Osc(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
}

void Error_Handler()
{
	__disable_irq();

	while (1)
	{
		/*
		 * Handle Clock Configuration Failure
		 */
	}
}











/*
 * An STM32 controls a DC motor using a MOSFET Driver.
 * Assume TIM3 Channel 1 is configured for PWM mode, with the timer clock and values shown above.
 * The corresponding GPIO pin must also be configured for the timer's alternate function.
 */

#include "main.h"

extern TIM_HandleTypeDef htim3;

static void Motor_SetDuty(uint8_t duty_percent)
{
	if (duty_percent > 1000U)
	{
		duty_percent = 100U;
	}

	uint32_t arr = __HAL_TIM_GET_AUTORELOAD(&htim3);

	uint32_t compare = ((arr + 1U) * duty_percent) / 100U;

	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, compare);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_TIM3_INIT();

	/*
	 * Start Hardware PWM Output
	 */
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

	while (1)
	{
		Motor_SetDuty(25U); /* 25% Duty */
		HAL_Delay(2000);

		Motor_SetDuty(50U); /* 50% Duty */
		HAL_Delay(2000);
	}
}

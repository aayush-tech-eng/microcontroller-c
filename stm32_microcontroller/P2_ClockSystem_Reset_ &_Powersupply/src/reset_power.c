#include "stm32f4xx.h"

/*
 * Identify the Reset Source
 */
void Check_Reset_Source(void)
{
	if(__HAL_RCC_GET_FLAG(RCC_FLAG_PORRST))
	{
		/*
		 * Power-on / power reset
		 */
	}

	if(__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST))
	{
		/*
		 * NRST PIN Reset
		 */
	}

	if(__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST))
	{
		/*
		 * Independent watchdog reset
		 */
	}

	if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDRST))
	{
		/*
		 * Window watchdog reset
		 */
	}

	if(__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST))
	{
		/*
		 * Software Reset
		 */
	}

	/* Clear reset flags after checking them */
	__HAL_RCC_CLEAR_RESET_FLAGS();
}

/*
 * Trigger a software reset
 */
void Software_Reset(void)
{
	NVIC_SystemReset();
}

/*
 * Enter Sleep Mode
 * CPU Stops: peripherals can continue running
 */
void Enter_Sleep_Mode(void)
{
	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	HAL_ResumeTick();
}

/*
 * Enter Stop Mode
 * Main regulator and high-speed clocks stop
 */
void Enter_Stop_Mode(void)
{
	HAL_SuspendTick();
	HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFI);

	/* Reconfigure system clock after waking */
	SystemClock_COnfig();
	HAL_ResumeTick();
}

/*
 * Enter Standby mode
 * Wake-up normally causes a reset/restart
 */
void Enter_Standby_Mode(void)
{
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	HAL_PWR_EnterSTANDBYMode();
	/* Execution normally does not return */
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	Check_Reset_Source();

	while (1)
	{
		/* Application Code */
	}
}















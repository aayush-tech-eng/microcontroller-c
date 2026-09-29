#include <stdint.h>
#include <stdbool.h>

/*
 * GPIOA Memory Map
 */
#define GPIOA_BASE (0x40020000UL)
#define GPIOA_OTYPER (*(volatile uint32_t *) (GPIOA_BASE + 0x04UL))
#define GPIOA_IDR (*(volatile uint32_t *)(GPIOA_BASE + 0x10UL))
#define GPIOA_ODR (*(volatile uint32_t *)(GPIOA_BASE + 0x14UL))

/*
 * GPIO Pin Definitions
 */
#define GIPO_PIN_A_O (0U)
#define GPIO_PIN_A_1 (1U)
#define GPIO_PIN_A_2 (2U)

#define GPIO_PIN_MASK(pin) (1UL << (pin))

/*
 * PA1 Configuration
 */
/*
 * OTYPER:
 * 0 = Push-pull
 * 1 = Open-drain
 */
static void GPIOA_PA1_SetPushPull(void)
{
	GPIOA_OTYPER &= ~GPIO_PIN_MASK(GPIO_PIN_A_1);
}

/*
 * PA1 Output Control
 */
static void GPIOA_PA1_SetHigh(void)
{
	GPIOA_ODR |= GPIO_PIN_MASK(GPIO_PIN_A_1);
}

static void GPIOA_PA1_SetLow(void)
{
	GPIOA_ODR &= ~GPIO_PIN_MASK(GPIO_PIN_A_1);
}

static void GPIOA_PA1_Toggle(void)
{
	GPIOA_ODR ^= GPIO_PIN_MASK(GPIO_PIN_A_1);
}

/*
 * PA1 Input Reading
 */
static bool GPIOA_PA1_Read(void)
{
	return (GPIOA_IDR & GPIO_PIN_MASK(GPIO_PIN_A_1)) != 0U;
}


/*
 * main function
 */
int main(void)
{
	/* Configure PA1 as push-pull */
	GPIOA_PA1_SetPushPull();

	/* Set PA1 High */
	GPIOA_PA1_SetHigh();

	/* Set PA1 Low */
	GPIOA_PA1_SetLow();

	/* Read PA1 */
	if (GPIOA_PA1_Read())
	{
		/* PA1 is High */
	}
	else
	{
		/* PA1 is Low */
	}

	/* Toggle PA1 */
	GPIOA_PA1_Toggle();

	while (1)
	{
		/* Application Code */
	}

	return 0;
}

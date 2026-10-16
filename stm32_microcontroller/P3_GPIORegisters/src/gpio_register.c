#include <stdint.h>

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFT[2];
} GPIO_t;

#define GPIOA ((GPIO_t *)0x40020000UL)
#define GPIOD ((GPIO_t *)0x40020c00UL)

/*
 * Configure GPIO pin mode
 */
static inline void gpio_set_mode(GPIO_t *port, uint8_t pin, uint8_t mode)
{
	port->MODER &= ~(3U << (pin * 2U)); // clear port pin
	port->MODER |= ((uint32_t)mode << (pin * 2U)); // mode: 00, 01, 10, 11
}

/*
 * Write GPIO output using atomic set/reset register
 */
static inline void gpio_write(GPIO_t *port, uint8_t pin, uint8_t high)
{
	port->BSRR = high ? (1U << pin) : (1U << (pin + 16U));
}

/*
 * Read GPIO Input
 */
static inline uint8_t gpio_read(GPIO_t *port, uint8_t pin)
{
	return (uint8_t)((port->IDR >> pin) & 1U);
}

int main(void)
{
	/*
	 * Enable GPIOA and GPIOD clocks
	 */
	#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830UL)
	RCC_AHB1ENR |= (1U << 0); // GPIOA Clock Enabled: in RCC_AHB1ENR register, at index 0, GPIOA port clock resides
	RCC_AHB1ENR |= (1U << 3); // GPIOD Clock Enabled: in RCC_AHB1ENR register, at index 3, GPIOD port clock resides

	/*
	 * Configure PA5 as output (01)
	 */
	gpio_set_mode(GPIOA, 5U, 1U); // 1U - 01 and in MODER Register: 01 is output

	/*
	 * Configure PD0 as input (00)
	 */
	gipo_set_mode(GPIOD, 0U, 0U); // 0U - 00 and in MODER Register: 00 is input

	/*
	 * Initialize PA5 LOW
	 */
	gpio_write(GPIOA, 5U, 0U);

	while (1)
	{
		/*
		 * If PD0 is HIGH, set PA5 High
		 * else, set PA5 LOW
		 */
		if (gpio_read(GPIOD,0U))
		{
			gpio_write(GPIOA, 5U, 1U);
		}
		else
		{
			gpio_write(GPIOA, 5U, 0U);
		}
	}









}

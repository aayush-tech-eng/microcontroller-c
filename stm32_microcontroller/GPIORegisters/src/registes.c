#include <stdint.h>
#define GPIOA_BASE (0x40020000UL)
#define GPIOA_ODR (*(volatile uint32_t *) (GPIOA_BASE + 0x14UL))
#define PA1 (1U)
#define PA5 (5U)
#define PA7 (7U)

int main(void)
{
	/* Set PA1, PA5, PA7 HIGH */
	GPIOA_ODR |= (1UL << PA1);
	GPIOA_ODR |= (1UL << PA5);
	GPIOA_ODR |= (1UL << PA7);

	while(1)
	{
	}

	return 0;
}

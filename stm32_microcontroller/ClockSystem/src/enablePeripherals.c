#define RCC_BASE 0x4002380UL


typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	uint32_t RESERVED0[8];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	uint32_t RESERVED1;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
} RCC_t;


#define RCC ((RCC_t *)RCC_BASE)

void clock_enable_gpiod(void)
{
	RCC->AHB1ENR |= (1U << 3); // AHB1ENR is 32-bit registers, each bit representing peripheral's clock
	(void)RCC->AHB1ENR;
}

#include <stdint.h>

typedef struct
{
	volatile uint32_t ISER[8];
	uint32_t RESERVED0[24];
	volatile uint32_t ICER[8];
	uint32_t RESERVED1[24];
	volatile uint32_t ISPR[8];
	uint32_t RESERVED2[24];
	volatile uint32_t ICPR[8];
	uint32_t RESERVED3[24];
	volatile uint32_t IABR[8];
	uint32_t RESERVED4[24];
	volatile uint8_t IPR[240];
} NVIC_t;

#define NVIC ((NVIC_t *)0xE000E100UL)
#define EXTI0_IRQn 6U
#define TIM2_IRQn 28U

static inline void nvic_enable(uint8_t irqn)
{
	NVIC->ISER[irqn >> 5] = (1U << (irqn & 0x1FU));
}

static inline void nvic_disable(uint8_t irqn)
{
	NVIC->ICER[irqn >> 5] = (1U << (irqn & 0x1FU));
	__asm volatile ("dsb"); // ensure it takes effect before continuing
}

static inline void nvic_set_priority(uint8_t irqn, uint8_t prio)
{
	NVIC->IPR[irqn] = (uint8_t)(prio << 4);
}

// usage
void setup(void)
{
	nvic_set_priority(TIM2_IRQn, 2); // urgent
	nvic_set_priority(EXTI0_IRQn, 10); // relaxed
	nvic_enable(TIM2_IRQn);
	nvic_enable(EXTI0_IRQn);
}



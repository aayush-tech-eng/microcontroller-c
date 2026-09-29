uint32_t g_init = 0xAA;
uint32_t g_zero;
const uint32_t g_const = 5;

int main(void)
{
	uint32_t local = 1;

	volatile uint32_t a_data = (uint32_t)&g_init;
	volatile uint32_t a_bss = (uint32_t)&g_zero;
	volatile uint32_t a_const = (uint32_t)&g_const;
	volatile uint32_t a_stack = (uint32_t)&local;

	(void)a_data; (void)a_bss; (void)a_const; (void)a_stack;

	for(;;);
}

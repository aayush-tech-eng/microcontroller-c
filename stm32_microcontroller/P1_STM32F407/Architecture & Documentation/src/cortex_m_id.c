#include <stdint.h>

/* ARM Core Register: identifies the CPU
 * Same address on all Cortex-M
 *
 * Below:
 * 0xE000ED00 is the memory address
 * (volatile uint32_t *)0xE000ED00- treat that address
 * as a pointer to a volatile uint32_t
 * now, *(volatile uint32_t *)0xE000EDO0- dereference the pointer,
 * meaning access the 32-bit value stored at that address
 */
#define SCB_CPUID (*(volatile uint32_t *)0xE000ED00) // access the value stored at 0xE000ED00

/* ST Registers: Chip-Specific Info Stored in System Memory  */
#define FLASH_SIZE_KB (*(volatile uint16_t *)0x1FFF7A22)

/* Keep the address as a pointer
 * 0x1FFF7A10- the starting memory address
 * (volatile uint32_t *)0x1FFF7A10- convert it into a pointer to a
 * volatile 32-bit integer
 * Now, later to hold this address 0x1FFF7A10
 * uint32_t *ptr = UID_BASE; // ptr = 0x1FFF7A10
 * uint32_t id_value = *ptr; // dereference(*) ptr
 */
#define UID_BASE ((volatile uint32_t *)0x1FFF7A10)
void read_uid(volatile uint32_t *uid_add, uint32_t *uid);


int main(void)
{
	uint32_t cpuid = SCB_CUPID;       // expect 0x410FC241
	uint32_t partno = (cpuid >> 4) & 0xFFF; // 0xC24 = Cortex-M4
	uint16_t flash_kb = FLASH_SIZE_KB; // expect 1024 (the "G")

	uint32_t uid[3];
	read_uid(UID_BASE, uid);

	(void)partno; (void)flash_kb; (void)uid; // silence warnings

	while(1)
	{

	}

}


void read_uid(volatile uint32_t *uid_add, uint32_t *uid)
{
	uid[0] = uid_add[0];
	uid[1] = uid_add[1];
	uid[2] = uid_add[2];
}




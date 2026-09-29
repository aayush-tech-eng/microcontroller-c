/*
 * chip_info.h
 *
 *  Created on: Sep 23, 2026
 *  Author: aayush_shahi
 */

#ifndef INC_CHIP_INFO_H_
#define INC_CHIP_INFO_H_

#include <stdint.h>

typedef struct
{
	uint32_t cpuid;
	uint32_t core_partno;
	uint16_t flash_kb;
	uint32_t uid[3];
} ChipInfo_t;

void chip_info_read(ChipInfo_t *info);

#endif /* INC_CHIP_INFO_H_ */

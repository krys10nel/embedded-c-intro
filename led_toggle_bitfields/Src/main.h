/*
 * main.h
 *
 *  Created on: Feb 20, 2024
 *      Author: krystene
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct {
	uint32_t GPIOA_EN		:1;
	uint32_t GPIOB_EN		:1;
	uint32_t GPIOC_EN		:1;
	uint32_t GPIOD_EN		:1;
	uint32_t GPIOE_EN		:1;
	uint32_t GPIOF_EN		:1;
	uint32_t GPIOG_EN		:1;
	uint32_t GPIOH_EN		:1;
	uint32_t GPIOI_EN		:1;
	uint32_t GPIOJ_EN		:1;
	uint32_t GPIOK_EN		:1;
	uint32_t RESERVED1		:1;
	uint32_t CRC_EN			:1;
	uint32_t RESERVED2		:2;
	uint32_t RESERVED3		:3;
	uint32_t BKPSRAM_EN		:1;
	uint32_t RESERVED4		:1;
	uint32_t CCMDATARAM_EN	:1;
	uint32_t DMA1_EN		:1;
	uint32_t DMA2_EN		:1;
	uint32_t DMA2D_EN		:1;
	uint32_t RESERVED5		:1;
	uint32_t ETHMAC_EN		:1;
	uint32_t ETHMACTX_EN	:1;
	uint32_t ETHMACRX_EN	:1;
	uint32_t ETHMACPTP_EN	:1;
	uint32_t OTGHS_EN		:1;
	uint32_t OTGHSULPI_EN	:1;
	// lasT reserved space dont need to be defined
}RCC_AHB1ENR_t;

typedef struct {
	uint32_t PIN0			:2;
	uint32_t PIN1			:2;
	uint32_t PIN2			:2;
	uint32_t PIN3			:2;
	uint32_t PIN4			:2;
	uint32_t PIN5			:2;
	uint32_t PIN6			:2;
	uint32_t PIN7			:2;
	uint32_t PIN8			:2;
	uint32_t PIN9			:2;
	uint32_t PIN10			:2;
	uint32_t PIN11			:2;
	uint32_t PIN12			:2;
	uint32_t PIN13			:2;
	uint32_t PIN14			:2;
	uint32_t PIN15			:2;
}GPIOx_MODER_t;

typedef struct {
	uint32_t PIN0			:1;
	uint32_t PIN1			:1;
	uint32_t PIN2			:1;
	uint32_t PIN3			:1;
	uint32_t PIN4			:1;
	uint32_t PIN5			:1;
	uint32_t PIN6			:1;
	uint32_t PIN7			:1;
	uint32_t PIN8			:1;
	uint32_t PIN9			:1;
	uint32_t PIN10			:1;
	uint32_t PIN11			:1;
	uint32_t PIN12			:1;
	uint32_t PIN13			:1;
	uint32_t PIN14			:1;
	uint32_t PIN15			:1;
	uint32_t RESERVED		:16;
}GPIOx_ODR_t;

#endif /* MAIN_H_ */

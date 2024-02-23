/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	// Red LED GPIOD14
	// Orange LED GPIOD13
	// Green LED GPIOD12
	// Blue LED GPIOD15 on AHB1

	// AHB1 and GPIOD Mode and Output register address + offset
	RCC_AHB1ENR_t volatile *const pClkCtrlReg 	= (RCC_AHB1ENR_t*) (0x40023800 + 0x30);	// RCC_AHB1ENR
	GPIOx_MODER_t volatile *const pPortDModeReg = (GPIOx_MODER_t*) (0x40020C00 + 0x00);	// GPIOx_MODER
	GPIOx_ODR_t volatile *const pPortDOutReg 	= (GPIOx_ODR_t*) (0x40020C00 + 0x14);	// GPIOx_ODR

	// Enabling clock on Port D (SET 3rd bit position to 1 in RCC_AHB1ENR)
	pClkCtrlReg->GPIOD_EN = 1;

	// Clearing port D12-15 for rewrite
	pPortDModeReg->PIN14 = 1;
	pPortDModeReg->PIN13 = 1;
	pPortDModeReg->PIN12 = 1;
	pPortDModeReg->PIN15 = 1;

	/* Loop Delay */
	while(1) {
		// Setting port D15 output to 1 (SET 15th bit position to 1 in GPIOx_ODR)
		pPortDOutReg->PIN15 = 1;

		for(uint32_t i = 0; i < 300000; i++); // traps processor in a loop that executes 300k times

		// Turn off LED / CLEAR
		pPortDOutReg->PIN15 = 0;
		pPortDOutReg->PIN14 = 1;

		for(uint32_t i = 0; i < 300000; i++);

		pPortDOutReg->PIN14 = 0;
		pPortDOutReg->PIN13 = 1;

		for(uint32_t i = 0; i < 300000; i++);

		pPortDOutReg->PIN13 = 0;
		pPortDOutReg->PIN12 = 1;

		for(uint32_t i = 0; i < 300000; i++);

		pPortDOutReg->PIN12 = 0;
	}
}
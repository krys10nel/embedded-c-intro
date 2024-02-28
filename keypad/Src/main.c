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
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void readColumnState(volatile uint32_t *const pPinEInReg);
void delay(void);

int main(void)
{
	printf("Hello World\n");
	/*
	 * Free I/Os listed in User Manual
	 * PE7-15 and PB11-15 are free
	 * PE7, 9, 11, 13 -> input (COLUMNS), PE15, PB11. 13. 15 -> output(ROWS)
	 *
	 * Wiring on 4x4 keypad: R1 R2 R3 R4 C1 C2 C3 C4
	 */

	uint32_t volatile *const pClkCtrlReg 	= (uint32_t*) (0x40023800 + 0x30); 	// RCC_AHB!ENR

	uint32_t volatile *const pPinEModeReg 	= (uint32_t*) (0x40021000 + 0x00); 	// GPIOx_MODER
	uint32_t volatile *const pPinEInReg 	= (uint32_t*) (0x40021000 + 0x10);	// GPIOx_IDR
	uint32_t volatile *const pPinEOutReg 	= (uint32_t*) (0x40021000 + 0x14);	// GPIOx_ODR
	uint32_t volatile *const pPinEPullUp	= (uint32_t*) (0x40021000 + 0x0C);	// GPIOx_PUPDR

	uint32_t volatile *const pPinBModeReg	= (uint32_t*) (0x40020400 + 0x00);	// GPIOx_MODER
	uint32_t volatile *const pPinBOutReg	= (uint32_t*) (0x40020400 + 0x14); 	// GPIOx_ODR

	/*
	 * Initialization
	 */

	// Enable clock register for GPIOB and E
	*pClkCtrlReg |= 1 << 1;
	*pClkCtrlReg |= 1 << 4;

	// Clearing/setting mode for PE7, 9, 11, 13 to input (00) - COLUMNS
	*pPinEModeReg &= ~(3 << 14);	// Pin 7 -- C4
	*pPinEModeReg &= ~(3 << 18);	// Pin 9 -- C3
	*pPinEModeReg &= ~(3 << 22);	// Pin 11 -- C2
	*pPinEModeReg &= ~(3 << 26);	// Pin 13 -- C1

	// Clearing and setting mode for PE15, PB11, 13, 15 to output (01) - ROWS
	*pPinEModeReg &= ~(3 << 30);	// Pin 15 -- R4
	*pPinEModeReg |= 1 << 30;

	*pPinBModeReg &= ~(3 << 22);	// Pin 11 -- R3
	*pPinBModeReg |= 1 << 22;
	*pPinBModeReg &= ~(3 << 26);	// Pin 13 -- R2
	*pPinBModeReg |= 1 << 26;
	*pPinBModeReg &= ~(3 << 30);	// Pin 15 -- R1
	*pPinBModeReg |= 1 << 30;

	// Setting pull-up registers for COLUMNS
	*pPinEPullUp |= 1 << 14;		// Pin 7
	*pPinEPullUp |= 1 << 18;		// Pin 9
	*pPinEPullUp |= 1 << 22;		// Pin 11
	*pPinEPullUp |= 1 << 26;		// Pin 13

	while(1) {
		// Make all ROWS high
		*pPinBOutReg |= 1 << 15; // R1
		*pPinBOutReg |= 1 << 13; // R2
		*pPinBOutReg |= 1 << 11; // R3
		*pPinEOutReg |= 1 << 15; // R4

		// Make ROW1 LOW and read button press for COLUMN 1
		*pPinBOutReg &= ~(1 << 15);

		if((*pPinEInReg & (1 << 13)) == 0) {
			delay();
			printf("1\n");
		}

		if((*pPinEInReg & (1 << 11)) == 0) {
			delay();
			printf("2\n");
		}

		if((*pPinEInReg & (1 << 9)) == 0) {
			delay();
			printf("3\n");
		}

		if((*pPinEInReg & (1 << 7)) == 0) {
			delay();
			printf("A\n");
		}

		// Make all ROWS high
		*pPinBOutReg |= 1 << 15; // R1
		*pPinBOutReg |= 1 << 13; // R2
		*pPinBOutReg |= 1 << 11; // R3
		*pPinEOutReg |= 1 << 15; // R4

		// Make ROW2 LOW and read button press for COLUMN 2
		*pPinBOutReg &= ~(1 << 13);

		if((*pPinEInReg & (1 << 13)) == 0) {
			delay();
			printf("4\n");
		}

		if((*pPinEInReg & (1 << 11)) == 0) {
			delay();
			printf("5\n");
		}

		if((*pPinEInReg & (1 << 9)) == 0) {
			delay();
			printf("6\n");
		}

		if((*pPinEInReg & (1 << 7)) == 0) {
			delay();
			printf("B\n");
		}

		// Make all ROWS high
		*pPinBOutReg |= 1 << 15; // R1
		*pPinBOutReg |= 1 << 13; // R2
		*pPinBOutReg |= 1 << 11; // R3
		*pPinEOutReg |= 1 << 15; // R4

		// Make ROW3 LOW and read button press for COLUMN 3
		*pPinBOutReg &= ~(1 << 11);

		if((*pPinEInReg & (1 << 13)) == 0) {
			delay();
			printf("7\n");
		}

		if((*pPinEInReg & (1 << 11)) == 0) {
			delay();
			printf("8\n");
		}

		if((*pPinEInReg & (1 << 9)) == 0) {
			delay();
			printf("9\n");
		}

		if((*pPinEInReg & (1 << 7)) == 0) {
			delay();
			printf("C\n");
		}

		// Make all ROWS high
		*pPinBOutReg |= 1 << 15; // R1
		*pPinBOutReg |= 1 << 13; // R2
		*pPinBOutReg |= 1 << 11; // R3
		*pPinEOutReg |= 1 << 15; // R4

		// Make ROW4 LOW and read button press for COLUMN 4
		*pPinEOutReg &= ~(1 << 15);

		if((*pPinEInReg & (1 << 13)) == 0) {
			delay();
			printf("*\n");
		}

		if((*pPinEInReg & (1 << 11)) == 0) {
			delay();
			printf("0\n");
		}

		if((*pPinEInReg & (1 << 9)) == 0) {
			delay();
			printf("#\n");
		}

		if((*pPinEInReg & (1 << 7)) == 0) {
			delay();
			printf("D\n");
		}
	}
}

void readColumnState(volatile uint32_t *const pPinEInReg) {
	for(uint8_t column = 1; column <= 4; column++) {
		if(column == 1) {
			if((*pPinEInReg & (1 << 7)) == 0) {
				delay();
				printf("1");
			}

			if((*pPinEInReg & (1 << 9)) == 0) {
				delay();
				printf("4");
			}

			if((*pPinEInReg & (1 << 11)) == 0) {
				delay();
				printf("7");
			}

			if((*pPinEInReg & (1 << 13)) == 0) {
				delay();
				printf("*");
			}
		}

		if(column == 2) {
			if((*pPinEInReg & (1 << 7)) == 0) {
				delay();
				printf("2");
			}

			if((*pPinEInReg & (1 << 9)) == 0) {
				delay();
				printf("5");
			}

			if((*pPinEInReg & (1 << 11)) == 0) {
				delay();
				printf("8");
			}

			if((*pPinEInReg & (1 << 13)) == 0) {
				delay();
				printf("0");
			}
		}

		if(column == 3) {
			if((*pPinEInReg & (1 << 7)) == 0) {
				delay();
				printf("3");
			}

			if((*pPinEInReg & (1 << 9)) == 0) {
				delay();
				printf("6");
			}

			if((*pPinEInReg & (1 << 11)) == 0) {
				delay();
				printf("9");
			}

			if((*pPinEInReg & (1 << 13)) == 0) {
				delay();
				printf("#");
			}
		}

		if(column == 4) {
			if((*pPinEInReg & (1 << 7)) == 0) {
				delay();
				printf("A");
			}

			if((*pPinEInReg & (1 << 9)) == 0) {
				delay();
				printf("B");
			}

			if((*pPinEInReg & (1 << 11)) == 0) {
				delay();
				printf("C");
			}

			if((*pPinEInReg & (1 << 13)) == 0) {
				delay();
				printf("D");
			}
		}
	}
}

void delay(void) {
	for(uint32_t i = 0; i <= 300000; i++);	//delay
}

/*
 * @brief  LPC11xx A/D conversion driver (except LPC1125)
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#ifndef __ADC_11XX_ASM_H_
#define __ADC_11XX_ASM_H_

#if !defined(CHIP_LPC1125)

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup ADC_11XX CHIP:  LPC11xx A/D conversion driver
 * @ingroup CHIP_11XX_Drivers
 * This ADC driver is for LPC11xx variants except for LPC1125.
 * @{
 */

#define ADC_MAX_SAMPLE_RATE 400000

/**
 * @brief 10 or 12-bit ADC register block structure
 */

#define LPC_ADC_BASE              0x4001C000

#define ADC_OFFSET_CR		0x000		/*!< A/D Control Register. The AD0CR register must be written to select the operating mode before A/D conversion can occur. */
#define ADC_OFFSET_GDR	0x004		/*!< A/D Global Data Register. Contains the result of the most recent A/D conversion. */
#define ADC_OFFSET_INTEN	0x00C		/*!< A/D Interrupt Enable Register. This register contains enable bits that allow the DONE flag of each A/D channel to be included or excluded from contributing to the generation of an A/D interrupt. */
//#define OFFSET_DR[8]			/*!< A/D Channel Data Register. This register contains the result of the most recent conversion completed on channel n. */
#define ADC_OFFSET_DR		0x010		/*!< A/D Channel Data Register. This register contains the result of the most recent conversion completed on channel n. */
#define ADC_OFFSET_STAT	0x030		/*!< A/D Status Register. This register contains DONE and OVERRUN flags for all of the A/D channels, as well as the A/D interrupt flag. */

/**
 * @brief ADC register support bitfields and mask
 */
 #define ADC_DR_RESULT(n)        ((((n) >> 6) & 0x3FF))	/*!< Mask for getting the 10 bits ADC data read value */
 #define ADC_CR_BITACC(n)        ((((n) & 0x7) << 17))	/*!< Number of ADC accuracy bits */

#define ADC_DR_DONE(n)          (((n) >> 31))			/*!< Mask for reading the ADC done status */
#define ADC_DR_OVERRUN(n)       ((((n) >> 30) & (1UL)))	/*!< Mask for reading the ADC overrun status */
#define ADC_CR_CH_SEL(n)        ((1UL << (n)))			/*!< Selects which of the AD0.0:7 pins is (are) to be sampled and converted */
#define ADC_CR_CLKDIV(n)        ((((n) & 0xFF) << 8))	/*!< The APB clock (PCLK) is divided by (this value plus one) to produce the clock for the A/D */
#define ADC_CR_BURST            ((1UL << 16))			/*!< Repeated conversions A/D enable bit */
#define ADC_CR_PDN              ((1UL << 21))			/*!< ADC convert is operational */
#define ADC_CR_START_MASK       ((7UL << 24))			/*!< ADC start mask bits */
#define ADC_CR_START_MODE_SEL(SEL)  ((SEL << 24))		/*!< Select Start Mode */
#define ADC_CR_START_NOW        ((1UL << 24))			/*!< Start conversion now */
#define ADC_CR_START_CTOUT15    ((2UL << 24))			/*!< Start conversion when the edge selected by bit 27 occurs on CTOUT_15 */
#define ADC_CR_START_CTOUT8     ((3UL << 24))			/*!< Start conversion when the edge selected by bit 27 occurs on CTOUT_8 */
#define ADC_CR_START_ADCTRIG0   ((4UL << 24))			/*!< Start conversion when the edge selected by bit 27 occurs on ADCTRIG0 */
#define ADC_CR_START_ADCTRIG1   ((5UL << 24))			/*!< Start conversion when the edge selected by bit 27 occurs on ADCTRIG1 */
#define ADC_CR_START_MCOA2      ((6UL << 24))			/*!< Start conversion when the edge selected by bit 27 occurs on Motocon PWM output MCOA2 */
#define ADC_CR_EDGE             ((1UL << 27))			/*!< Start conversion on a falling edge on the selected CAP/MAT signal */
#define ADC_SAMPLE_RATE_CONFIG_MASK         (ADC_CR_CLKDIV(0xFF) | ADC_CR_BITACC(0x07))

/**
 * @brief	ADC status register used for IP drivers
 */
#define ADC_DR_DONE_STAT 		0	/*!< ADC data register staus */
#define ADC_DR_OVERRUN_STAT 	1	/*!< ADC data overrun staus */
#define ADC_DR_ADINT_STAT	 	2	/*!< ADC interrupt status */

/** The channels on one ADC peripheral*/
#define ADC_CH0   0	/**< ADC channel 0 */
#define ADC_CH1	1	/**< ADC channel 1 */
#define ADC_CH2	2	/**< ADC channel 2 */
#define ADC_CH3	3	/**< ADC channel 3 */
#define ADC_CH4	4	/**< ADC channel 4 */
#define ADC_CH5	5	/**< ADC channel 5 */
#define ADC_CH6	6	/**< ADC channel 6 */
#define ADC_CH7	7	/**< ADC channel 7 */

/** The number of bits of accuracy of the result in the LS bits of ADDR*/
#define ADC_10BITS	0		/**< ADC 10 bits */
#define ADC_9BITS		1		/**< ADC 9 bits  */
#define ADC_8BITS		2		/**< ADC 8 bits  */
#define ADC_7BITS		3		/**< ADC 7 bits  */
#define ADC_6BITS		4		/**< ADC 6 bits  */
#define ADC_5BITS		5		/**< ADC 5 bits  */
#define ADC_4BITS		6		/**< ADC 4 bits  */
#define ADC_3BITS		7		/**< ADC 3 bits  */

/** Edge configuration, which controls rising or falling edge on the selected signal for the start of a conversion */
#define ADC_TRIGGERMODE_RISING		0		/**< Trigger event: rising edge */
#define ADC_TRIGGERMODE_FALLING		1		/**< Trigger event: falling edge */

/** Start mode, which controls the start of an A/D conversion when the BURST bit is 0. */
#define ADC_NO_START 			0
#define ADC_START_NOW			1	/*!< Start conversion now */
#define ADC_START_ON_CTOUT15	2	/*!< Start conversion when the edge selected by bit 27 occurs on CTOUT_15 */
#define ADC_START_ON_CTOUT8		3	/*!< Start conversion when the edge selected by bit 27 occurs on CTOUT_8 */
#define ADC_START_ON_ADCTRIG0	4	/*!< Start conversion when the edge selected by bit 27 occurs on ADCTRIG0 */
#define ADC_START_ON_ADCTRIG1	5	/*!< Start conversion when the edge selected by bit 27 occurs on ADCTRIG1 */
#define ADC_START_ON_MCOA2		6	/*!< Start conversion when the edge selected by bit 27 occurs on Motocon PWM output MCOA2 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* !defined(CHIP_LPC1125) */

#endif /* __ADC_11XX_ASM_H_ */

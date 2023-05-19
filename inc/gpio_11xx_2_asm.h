/*
 * @brief LPC11xx GPIO driver for CHIP_LPC11CXX, CHIP_LPC110X, CHIP_LPC11XXLV,
 * and CHIP_LPC1125 families only.
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
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

#ifndef __GPIO_11XX_2_ASM_H_
#define __GPIO_11XX_2_ASM_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup GPIO_11XX_2 CHIP: LPC11xx GPIO driver for CHIP_LPC11CXX, CHIP_LPC110X, and CHIP_LPC11XXLV families
 * @ingroup CHIP_11XX_Drivers
 * For device familes identified with CHIP definitions CHIP_LPC11CXX,
 * CHIP_LPC110X, and CHIP_LPC11XXLV only.
 * @{
 */

#define LPC_GPIO_PORT0_BASE       0x50000000
#define LPC_GPIO_PORT1_BASE       0x50010000
#define LPC_GPIO_PORT2_BASE       0x50020000
#define LPC_GPIO_PORT3_BASE       0x50030000

#define GPIO_GPIO_OFFSET_DATA	0x0000					/*!< Offset: 0x0000 to 0x3FFC Data address masking register (R/W) */
#define GPIO_OFFSET_DIR	0x8000					/*!< Offset: 0x8000 Data direction register (R/W) */
#define GPIO_OFFSET_IS		0x8004					/*!< Offset: 0x8004 Interrupt sense register (R/W) */
#define GPIO_OFFSET_IBE	0x8008					/*!< Offset: 0x8008 Interrupt both edges register (R/W) */
#define GPIO_OFFSET_IEV	0x800C					/*!< Offset: 0x800C Interrupt event register  (R/W) */
#define GPIO_OFFSET_IE		0x8010					/*!< Offset: 0x8010 Interrupt mask register (R/W) */
#define GPIO_OFFSET_RIS	0x8014					/*!< Offset: 0x8014 Raw interrupt status register (R/ ) */
#define GPIO_OFFSET_MIS	0x8018					/*!< Offset: 0x8018 Masked interrupt status register (R/ ) */
#define GPIO_OFFSET_IC		0x801C					/*!< Offset: 0x801C Interrupt clear register (W) */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_11XX_2_ASM_H_ */

/*
 * @brief IOCON registers and control functions
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

#ifndef __IOCON_11XX_ASM_H_
#define __IOCON_11XX_ASM_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup IOCON_11XX CHIP: LPC11xx IO Control driver
 * @ingroup CHIP_11XX_Drivers
 * @{
 */

/**
 * @brief IO Configuration Unit register block structure
 */

/**
 * @brief LPC11XX I/O Configuration register offset
 */
#define IOCON_PIO0_0 (0x00C >> 2)
#define IOCON_PIO0_1 (0x010 >> 2)
#define IOCON_PIO0_2 (0x01C >> 2)
#define IOCON_PIO0_3 (0x02C >> 2)
#define IOCON_PIO0_4 (0x030 >> 2)
#define IOCON_PIO0_5 (0x034 >> 2)
#define IOCON_PIO0_6 (0x04C >> 2)
#define IOCON_PIO0_7 (0x050 >> 2)
#define IOCON_PIO0_8 (0x060 >> 2)
#define IOCON_PIO0_9 (0x064 >> 2)
#define IOCON_PIO0_10 (0x070 >> 2)
#define IOCON_PIO0_11 (0x074 >> 2)

#define IOCON_PIO1_0 (0x078 >> 2)
#define IOCON_PIO1_1 (0x07C >> 2)
#define IOCON_PIO1_2 (0x080 >> 2)
#define IOCON_PIO1_3 (0x090 >> 2)
#define IOCON_PIO1_4 (0x094 >> 2)
#define IOCON_PIO1_5 (0x0A0 >> 2)
#define IOCON_PIO1_6 (0x0A4 >> 2)
#define IOCON_PIO1_7 (0x0A8 >> 2)
#define IOCON_PIO1_8 (0x014 >> 2)
#define IOCON_PIO1_9 (0x038 >> 2)
#define IOCON_PIO1_10 (0x06C >> 2)
#define IOCON_PIO1_11 (0x098 >> 2)

#define IOCON_PIO2_0 (0x008 >> 2)
#define IOCON_PIO2_1 (0x028 >> 2)
#define IOCON_PIO2_2 (0x05C >> 2)
#define IOCON_PIO2_3 (0x08C >> 2)
#define IOCON_PIO2_4 (0x040 >> 2)
#define IOCON_PIO2_5 (0x044 >> 2)
#define IOCON_PIO2_6 (0x000 >> 2)
#define IOCON_PIO2_7 (0x020 >> 2)
#define IOCON_PIO2_8 (0x024 >> 2)
#define IOCON_PIO2_9 (0x054 >> 2)
#define IOCON_PIO2_10 (0x058 >> 2)
#if !defined(CHIP_LPC1125)
#define IOCON_PIO2_11 (0x070 >> 2)
#endif

#define IOCON_PIO3_0 (0x084 >> 2)
#if !defined(CHIP_LPC1125)
#define IOCON_PIO3_1 (0x088 >> 2)
#endif
#define IOCON_PIO3_2 (0x09C >> 2)
#define IOCON_PIO3_3 (0x0AC >> 2)
#define IOCON_PIO3_4 (0x03C >> 2)
#define IOCON_PIO3_5 (0x048 >> 2)

/**
 * @brief LPC11XX Pin location select
 */
#define IOCON_SCKLOC_PIO0_10 (0xB0)
#if !defined(CHIP_LPC1125)
#define IOCON_SCKLOC_PIO2_11 (0xB0 | 1)
#endif    
#define IOCON_SCKLOC_PIO0_6 (0xB0 | 2)
#define IOCON_DSRLOC_PIO2_1 (0xB4)
#if !defined(CHIP_LPC1125)
#define IOCON_DSRLOC_PIO3_1 (0xB4 | 1)
#endif    
#define IOCON_DCDLOC_PIO2_2 (0xB8)
#define IOCON_DCDLOC_PIO3_2 (0xB8 | 1)
#define IOCON_RILOC_PIO2_3 (0xBC)
#define IOCON_RILOC_PIO3_3 (0xBC | 1)

#define LPC_IOCON_BASE            0x40044000

#define IOCON_OFFSET_PIO2_6	0x000                 /*!< Offset: 0x000 I/O configuration for pin PIO2_6 (R/W) */
#define IOCON_OFFSET_PIO2_0	0x008                 /*!< Offset: 0x008 I/O configuration for pin PIO2_0/DTR/SSEL1 (R/W) */
#define IOCON_OFFSET_RESET_PIO0_0	0x00C           /*!< Offset: 0x00C I/O configuration for pin RESET/PIO0_0  (R/W) */
#define IOCON_OFFSET_PIO0_1	0x010                 /*!< Offset: 0x010 I/O configuration for pin PIO0_1/CLKOUT/CT32B0_MAT2 (R/W) */
#define IOCON_OFFSET_PIO1_8	0x014                 /*!< Offset: 0x014 I/O configuration for pin PIO1_8/CT16B1_CAP0 (R/W) */
#define IOCON_OFFSET_SSEL1_LOC	0x018              /*!< Offset: 0x018 IOCON SSEL1 location register (IOCON_SSEL1_LOC, address 0x4004 4018) */
#define IOCON_OFFSET_PIO0_2	0x01C                 /*!< Offset: 0x01C I/O configuration for pin PIO0_2/SSEL0/CT16B0_CAP0 (R/W) */

#define IOCON_OFFSET_PIO2_7	0x020                 /*!< Offset: 0x020 I/O configuration for pin PIO2_7 (R/W) */
#define IOCON_OFFSET_PIO2_8	0x024                 /*!< Offset: 0x024 I/O configuration for pin PIO2_8 (R/W) */
#define IOCON_OFFSET_PIO2_1	0x028                 /*!< Offset: 0x028 I/O configuration for pin PIO2_1/nDSR/SCK1 (R/W) */
#define IOCON_OFFSET_PIO0_3	0x02C                 /*!< Offset: 0x02C I/O configuration for pin PIO0_3 (R/W) */
#define IOCON_OFFSET_PIO0_4	0x030                 /*!< Offset: 0x030 I/O configuration for pin PIO0_4/SCL (R/W) */
#define IOCON_OFFSET_PIO0_5	0x034                 /*!< Offset: 0x034 I/O configuration for pin PIO0_5/SDA (R/W) */
#define IOCON_OFFSET_PIO1_9	0x038                 /*!< Offset: 0x038 I/O configuration for pin PIO1_9/CT16B1_MAT0 (R/W) */
#define IOCON_OFFSET_PIO3_4	0x03C                 /*!< Offset: 0x03C I/O configuration for pin PIO3_4 (R/W) */

#define IOCON_OFFSET_PIO2_4	0x040                 /*!< Offset: 0x040 I/O configuration for pin PIO2_4 (R/W) */
#define IOCON_OFFSET_PIO2_5	0x044                 /*!< Offset: 0x044 I/O configuration for pin PIO2_5 (R/W) */
#define IOCON_OFFSET_PIO3_5	0x048                 /*!< Offset: 0x048 I/O configuration for pin PIO3_5 (R/W) */
#define IOCON_OFFSET_PIO0_6	0x04C                 /*!< Offset: 0x04C I/O configuration for pin PIO0_6/SCK0 (R/W) */
#define IOCON_OFFSET_PIO0_7	0x050                 /*!< Offset: 0x050 I/O configuration for pin PIO0_7/nCTS (R/W) */
#define IOCON_OFFSET_PIO2_9	0x054                 /*!< Offset: 0x054 I/O configuration for pin PIO2_9 (R/W) */
#define IOCON_OFFSET_PIO2_10	0x058                /*!< Offset: 0x058 I/O configuration for pin PIO2_10 (R/W) */
#define IOCON_OFFSET_PIO2_2	0x05C                 /*!< Offset: 0x05C I/O configuration for pin PIO2_2/DCD/MISO1 (R/W) */

#define IOCON_OFFSET_PIO0_8	0x060                /*!< Offset: 0x060 I/O configuration for pin PIO0_8/MISO0/CT16B0_MAT0 (R/W) */
#define IOCON_OFFSET_PIO0_9	0x064                 /*!< Offset: 0x064 I/O configuration for pin PIO0_9/MOSI0/CT16B0_MAT1 (R/W) */
#define IOCON_OFFSET_SWCLK_PIO0_10 0x068          /*!< Offset: 0x068 I/O configuration for pin SWCLK/PIO0_10/SCK0/CT16B0_MAT2 (R/W) */
#define IOCON_OFFSET_PIO1_10	0x06C                /*!< Offset: 0x06C I/O configuration for pin PIO1_10/AD6/CT16B1_MAT1 (R/W) */
#define IOCON_OFFSET_PIO2_11	0x070                /*!< Offset: 0x070 I/O configuration for pin PIO2_11/SCK0 (R/W) */
#define IOCON_OFFSET_R_PIO0_11	0x074              /*!< Offset: 0x074 I/O configuration for pin TDI/PIO0_11/AD0/CT32B0_MAT3 (R/W) */
#define IOCON_OFFSET_R_PIO1_0	0x078               /*!< Offset: 0x078 I/O configuration for pin TMS/PIO1_0/AD1/CT32B1_CAP0 (R/W) */
#define IOCON_OFFSET_R_PIO1_1	0x07C               /*!< Offset: 0x07C I/O configuration for pin TDO/PIO1_1/AD2/CT32B1_MAT0 (R/W) */

#define IOCON_OFFSET_R_PIO1_2	0x080               /*!< Offset: 0x080 I/O configuration for pin nTRST/PIO1_2/AD3/CT32B1_MAT1 (R/W) */
#define IOCON_OFFSET_PIO3_0	0x084                 /*!< Offset: 0x084 I/O configuration for pin PIO3_0/nDTR (R/W) */
#define IOCON_OFFSET_PIO3_1	0x088                 /*!< Offset: 0x088 I/O configuration for pin PIO3_1/nDSR (R/W) */
#define IOCON_OFFSET_PIO2_3	0x08C                 /*!< Offset: 0x08C I/O configuration for pin PIO2_3/RI/MOSI1 (R/W) */
#define IOCON_OFFSET_SWDIO_PIO1_3	0x090           /*!< Offset: 0x090 I/O configuration for pin SWDIO/PIO1_3/AD4/CT32B1_MAT2 (R/W) */
#define IOCON_OFFSET_PIO1_4	0x094                 /*!< Offset: 0x094 I/O configuration for pin PIO1_4/AD5/CT32B1_MAT3 (R/W) */
#define IOCON_OFFSET_PIO1_11	0x098                /*!< Offset: 0x098 I/O configuration for pin PIO1_11/AD7 (R/W) */
#define IOCON_OFFSET_PIO3_2	0x09C                 /*!< Offset: 0x09C I/O configuration for pin PIO3_2/nDCD (R/W) */

#define IOCON_OFFSET_PIO1_5	0x0A0                 /*!< Offset: 0x0A0 I/O configuration for pin PIO1_5/nRTS/CT32B0_CAP0 (R/W) */
#define IOCON_OFFSET_PIO1_6	0x0A4                 /*!< Offset: 0x0A4 I/O configuration for pin PIO1_6/RXD/CT32B0_MAT0 (R/W) */
#define IOCON_OFFSET_PIO1_7	0x0A8                 /*!< Offset: 0x0A8 I/O configuration for pin PIO1_7/TXD/CT32B0_MAT1 (R/W) */
#define IOCON_OFFSET_PIO3_3	0x0AC                 /*!< Offset: 0x0AC I/O configuration for pin PIO3_3/nRI (R/W) */
#define IOCON_OFFSET_SCK_LOC	0x0B0               /*!< Offset: 0x0B0 SCK pin location select Register (R/W) */
#define IOCON_OFFSET_DSR_LOC	0x0B4                /*!< Offset: 0x0B4 DSR pin location select Register (R/W) */
#define IOCON_OFFSET_DCD_LOC	0x0B8                /*!< Offset: 0x0B8 DCD pin location select Register (R/W) */
#define IOCON_OFFSET_RI_LOC	0x0BC                 /*!< Offset: 0x0BC RI pin location Register (R/W) */
#define IOCON_OFFSET_CT16B0_CAP0_LOC 0x0C0        /*!< Offset: 0x0C0 IOCON CT16B0_CAP0 location register (IOCON_CT16B0_CAP0_LOC, address 0x4004 40C0) */
#define IOCON_OFFSET_SCK1_LOC	0x0C4               /*!< Offset: 0x0C4 IOCON SCK1 location register (IOCON_SCK1_LOC, address 0x4004 40C4) */
#define IOCON_OFFSET_MISO1_LOC	0x0C8              /*!< Offset: 0x0C8 IOCON MISO1 location register (IOCON_MISO1_LOC, address 0x4004 40C8) */
#define IOCON_OFFSET_MOSI1_LOC	0x0CC              /*!< Offset: 0x0CC IOCON MOSI1 location register (IOCON_MOSI1_LOC, address 0x4004 40CC) */
#define IOCON_OFFSET_CT32B0_CAP0_LOC	0x0D0        /*!< Offset: 0x0D0 IOCON CT32B0_CAP0 location register (IOCON_CT32B0_CAP0_LOC, address 0x4004 40D0) */
#define IOCON_OFFSET_RXD_LOC	0x0D4                /*!< Offset: 0x0D4 IOCON RXD location register (IOCON_RXD_LOC, address 0x4004 40D4) */

/**
 * IOCON function and mode selection definitions
 * See the User Manual for specific modes and functions supported by the
 * various LPC11xx devices. Functionality can vary per device.
 */
#define IOCON_FUNC0             0x0				/*!< Selects pin function 0 */
#define IOCON_FUNC1             0x1				/*!< Selects pin function 1 */
#define IOCON_FUNC2             0x2				/*!< Selects pin function 2 */
#define IOCON_FUNC3             0x3				/*!< Selects pin function 3 */
#define IOCON_FUNC4             0x4				/*!< Selects pin function 4 */
#define IOCON_FUNC5             0x5				/*!< Selects pin function 5 */
#define IOCON_FUNC6             0x6				/*!< Selects pin function 6 */
#define IOCON_FUNC7             0x7				/*!< Selects pin function 7 */
#define IOCON_MODE_INACT        (0x0 << 3)		/*!< No addition pin function */
#define IOCON_MODE_PULLDOWN     (0x1 << 3)		/*!< Selects pull-down function */
#define IOCON_MODE_PULLUP       (0x2 << 3)		/*!< Selects pull-up function */
#define IOCON_MODE_REPEATER     (0x3 << 3)		/*!< Selects pin repeater function */
#define IOCON_HYS_EN            (0x1 << 5)		/*!< Enables hysteresis */
#define IOCON_INV_EN            (0x1 << 6)		/*!< Enables invert function on input */
#define IOCON_ADMODE_EN         (0x0 << 7)		/*!< Enables analog input function (analog pins only) */
#define IOCON_DIGMODE_EN        (0x1 << 7)		/*!< Enables digital function (analog pins only) */
#define IOCON_SFI2C_EN          (0x0 << 8)		/*!< I2C standard mode/fast-mode */
#define IOCON_STDI2C_EN         (0x1 << 8)		/*!< I2C standard I/O functionality */
#define IOCON_FASTI2C_EN        (0x2 << 8)		/*!< I2C Fast-mode Plus */
#define IOCON_FILT_DIS          (0x1 << 8)		/*!< Disables noise pulses filtering (10nS glitch filter) */
#define IOCON_OPENDRAIN_EN      (0x1 << 10)		/*!< Enables open-drain function */

/**
 * IOCON function and mode selection definitions (old)
 * For backwards compatibility.
 */
#define MD_PLN					(0x0 << 3)		/*!< Disable pull-down and pull-up resistor at resistor at pad */
#define MD_PDN					(0x1 << 3)		/*!< Enable pull-down resistor at pad */
#define MD_PUP					(0x2 << 3)		/*!< Enable pull-up resistor at pad */
#define MD_BUK					(0x3 << 3)		/*!< Enable pull-down and pull-up resistor at resistor at pad (repeater mode) */
#define MD_HYS					(0x1 << 5)		/*!< Enable hysteresis */
#define MD_INV					(0x1 << 6)		/*!< Invert enable */
#define MD_ADMODE				(0x0 << 7)		/*!< Select analog mode */
#define MD_DIGMODE				(0x1 << 7)		/*!< Select digitial mode */
#define MD_DISFIL				(0x0 << 8)		/*!< Disable 10nS input glitch filter */
#define MD_ENFIL				(0x1 << 8)		/*!< Enable 10nS input glitch filter */
#define MD_SFI2C				(0x0 << 8)		/*!< I2C standard mode/fast-mode */
#define MD_STDI2C				(0x1 << 8)		/*!< I2C standard I/O functionality */
#define MD_FASTI2C				(0x2 << 8)		/*!< I2C Fast-mode Plus */
#define MD_OPENDRAIN			(0x1 << 10)		/*!< Open drain mode bit */
#define FUNC0 0x0
#define FUNC1 0x1
#define FUNC2 0x2
#define FUNC3 0x3
#define FUNC4 0x4
#define FUNC5 0x5
#define FUNC6 0x6
#define FUNC7 0x7

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __IOCON_11XX_ASM_H_ */

/*
 * @brief LPC11XX System Control registers and control functions
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

#ifndef __SYSCTL_11XX_ASM_H_
#define __SYSCTL_11XX_ASM_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup SYSCTL_11XX CHIP: LPC11xx System Control block driver
 * @ingroup CHIP_11XX_Drivers
 * @{
 */
#define LPC_SYSCTL_BASE           0x40048000

/**
 * @brief LPC11XX System Control block structure
 */
#define SYSCTL_OFFSET_SYSMEMREMAP 0x0000		/*!< System Memory remap register */
#define SYSCTL_OFFSET_PRESETCTRL 0x0004		/*!< Peripheral reset Control register */
#define SYSCTL_OFFSET_SYSPLLCTRL 0x0008		/*!< System PLL control register */
#define SYSCTL_OFFSET_SYSPLLSTAT 0x000c		/*!< System PLL status register */
#define SYSCTL_OFFSET_USBPLLCTRL 0x0010		/*!< USB PLL control register, LPC11UXX only*/
#define SYSCTL_OFFSET_USBPLLSTAT 0x0014		/*!< USB PLL status register, LPC11UXX only */
//#define SYSCTL_OFFSET_RESERVED1[2] 0x0018, 0x1c
#define SYSCTL_OFFSET_SYSOSCCTRL 0x0020		/*!< System Oscillator control register */
#define SYSCTL_OFFSET_WDTOSCCTRL 0x0024		/*!< Watchdog Oscillator control register */
#define SYSCTL_OFFSET_IRCCTRL 0x0028			/*!< IRC control register, not on LPC11UXX and LPC11EXX */
#define SYSCTL_OFFSET_LFOSCCTRL 0x002c		/*!< LF oscillator control, LPC11AXX only */
#define SYSCTL_OFFSET_SYSRSTSTAT 0x0030		/*!< System Reset Status register           */
//#define SYSCTL_OFFSET_RESERVED2[3] 0x00
#define SYSCTL_OFFSET_SYSPLLCLKSEL 0x040	/*!< System PLL clock source select register */
#define SYSCTL_OFFSET_SYSPLLCLKUEN 0x044	/*!< System PLL clock source update enable register*/
#define SYSCTL_OFFSET_USBPLLCLKSEL 0x00	/*!< USB PLL clock source select register, LPC11UXX only */
#define SYSCTL_OFFSET_USBPLLCLKUEN 0x00	/*!< USB PLL clock source update enable register, LPC11UXX only */
//#define SYSCTL_OFFSET_RESERVED3[8] 0x00
#define SYSCTL_OFFSET_MAINCLKSEL 0x070	/*!< Main clock source select register		*/
#define SYSCTL_OFFSET_MAINCLKUEN 0x074	/*!< Main clock source update enable register	*/
#define SYSCTL_OFFSET_SYSAHBCLKDIV 0x078	/*!< System Clock divider register */
//#define SYSCTL_OFFSET_RESERVED4 0x00
#define SYSCTL_OFFSET_SYSAHBCLKCTRL 0x080	/*!< System clock control register */
//#define SYSCTL_OFFSET_RESERVED5[4] 0x00
#define SYSCTL_OFFSET_SSP0CLKDIV 0x094	/*!< SSP0 clock divider register   */
#define SYSCTL_OFFSET_USARTCLKDIV 0x098	/*!< UART clock divider register   */
#define SYSCTL_OFFSET_SSP1CLKDIV 0x09C	/*!< SSP1 clock divider register, not on CHIP_LPC110X, CHIP_LPC11XXLV */
//#define SYSCTL_OFFSET_RESERVED6[8] 0x00
#define SYSCTL_OFFSET_USBCLKSEL 0x00	/*!< USB clock source select register, LPC11UXX only */
#define SYSCTL_OFFSET_USBCLKUEN 0x00	/*!< USB clock source update enable register, LPC11UXX only */
#define SYSCTL_OFFSET_USBCLKDIV 0x00	/*!< USB clock source divider register, LPC11UXX only */
//#define SYSCTL_OFFSET_RESERVED7 0x00
#define SYSCTL_OFFSET_WDTCLKSEL 0x0D0	/*!< WDT clock source select register, some parts only */
#define SYSCTL_OFFSET_WDTCLKUEN 0x0D4	/*!< WDT clock source update enable register, some parts only */
#define SYSCTL_OFFSET_WDTCLKDIV 0x0D8	/*!< WDT clock divider register, some parts only */
//#define SYSCTL_OFFSET_RESERVED8 0x00
#define SYSCTL_OFFSET_CLKOUTSEL 0x0E0	/*!< Clock out source select register, not on LPC1102/04 */
#define SYSCTL_OFFSET_CLKOUTUEN 0x0E4	/*!< Clock out source update enable register, not on LPC1102/04 */
#define SYSCTL_OFFSET_CLKOUTDIV 0x0E8	/*!< Clock out divider register, not on LPC1102/04 */
//#define SYSCTL_OFFSET_RESERVED9[5] 0x00
#define SYSCTL_OFFSET_PIOPORCAP0 0x100/*!< POR captured PIO status registers, index 1 on LPC1102/04 */
#define SYSCTL_OFFSET_PIOPORCAP1 0x104/*!< POR captured PIO status registers, index 1 on LPC1102/04 */
//#define SYSCTL_OFFSET_RESERVED10[18] 0x00
#define SYSCTL_OFFSET_BODCTRL 0x150		/*!< Brown Out Detect register */
#define SYSCTL_OFFSET_SYSTCKCAL 0x154	/*!< System tick counter calibration register */
//#define SYSCTL_OFFSET_RESERVED11[6] 0x00
#define SYSCTL_OFFSET_IRQLATENCY 0x00	/*!< IRQ delay register, on LPC11UXX and LPC11EXX only */
#define SYSCTL_OFFSET_NMISRC 0x174		/*!< NMI source control register,some parts only */
//#define SYSCTL_OFFSET_PINTSEL[8] 0x00	/*!< GPIO pin interrupt select register 0-7, not on CHIP_LPC110X, CHIP_LPC11XXLV, CHIP_LPC11CXX */
#define SYSCTL_OFFSET_USBCLKCTRL 0x00	/*!< USB clock control register, LPC11UXX only */
#define SYSCTL_OFFSET_USBCLKST 0x00	/*!< USB clock status register, LPC11UXX only */
//#define SYSCTL_OFFSET_RESERVED12[24] 0x00
#define SYSCTL_OFFSET_STARTAPRP0 0x200	/*!< Start loigc 0 interrupt wake up enable register 0, on CHIP_LPC110X, CHIP_LPC11XXLV, CHIP_LPC11CXX */
#define SYSCTL_OFFSET_STARTERP0 0x204	/*!< Start loigc signal enable register 0, not on LPC11AXX */
#define SYSCTL_OFFSET_STARTRSRP0CLR 0x208	/*!< Start loigc reset register 0, on CHIP_LPC110X, CHIP_LPC11XXLV, CHIP_LPC11CXX */
#define SYSCTL_OFFSET_STARTSRP0 0x20c		/*!< Start loigc status register 0, on CHIP_LPC110X, CHIP_LPC11XXLV, CHIP_LPC11CXX */
//#define SYSCTL_OFFSET_RESERVED13 0x00
#define SYSCTL_OFFSET_STARTERP1 0x214	/*!< Start logic 1 interrupt wake up enable register 1, on LPC11UXX and LPC11EXX only */
//#define SYSCTL_OFFSET_RESERVED14[6] 0x00
#define SYSCTL_OFFSET_PDSLEEPCFG 0x230	/*!< Power down states in deep sleep mode register, not on LPC11AXX */
#define SYSCTL_OFFSET_PDWAKECFG 0x234	/*!< Power down states in wake up from deep sleep register, not on LPC11AXX */
#define SYSCTL_OFFSET_PDRUNCFG 0x238	/*!< Power configuration register*/
//#define SYSCTL_OFFSET_RESERVED15[110] 0x00
#define SYSCTL_OFFSET_DEVICEID 0x3F4	/*!< Device ID register */

/**
 * System memory remap modes used to remap interrupt vectors
 */
#define REMAP_BOOT_LOADER_MODE 0	/*!< Interrupt vectors are re-mapped to Boot ROM */
#define REMAP_USER_RAM_MODE 1	/*!< Interrupt vectors are re-mapped to Static RAM */
#define REMAP_USER_FLASH_MODE 2	/*!< Interrupt vectors are not re-mapped and reside in Flash */

/**
 * Peripheral reset identifiers, not available on all devices
 */
#define RESET_SSP0 		0			/*!< SSP0 reset control */
#define RESET_I2C0 		1			/*!< I2C0 reset control */
#define RESET_SSP1 		2			/*!< SSP1 reset control */
#define RESET_CAN0 		3			/*!< CAN0 reset control */
#define RESET_UART0 		4	/*!< UART0 reset control */
#define RESET_TIMER0_16 	5/*!< 16-bit Timer 0 reset control */
#define RESET_TIMER1_16 	6/*!< 16-bit Timer 1 reset control */
#define RESET_TIMER0_32 	7/*!< 32-bit Timer 0 reset control */
#define RESET_TIMER1_32 	8/*!< 32-bit Timer 1 reset control */
#define RESET_ACMP 		9		/*!< Analog comparator reset control */
#define RESET_DAC0 		10		/*!< DAC reset control */
#define RESET_ADC0		11		/*!< ADC reset control */

/**
 * System reset status
 */
#define SYSCTL_RST_POR    (1 << 0)	/*!< POR reset status */
#define SYSCTL_RST_EXTRST (1 << 1)	/*!< External reset status */
#define SYSCTL_RST_WDT    (1 << 2)	/*!< Watchdog reset status */
#define SYSCTL_RST_BOD    (1 << 3)	/*!< Brown-out detect reset status */
#define SYSCTL_RST_SYSRST (1 << 4)	/*!< software system reset status */

/**
 * Non-Maskable Interrupt Enable/Disable value
 */
#define SYSCTL_NMISRC_ENABLE   ((uint32_t) 1 << 31)	/*!< Enable the Non-Maskable Interrupt (NMI) source */


/**
 * Brown-out detector reset level
 */
#define SYSCTL_BODRSTLVL_RESERVED1 0	/*!< Only possible value for LPC11A/02/XXLV */
#define SYSCTL_BODRSTLVL_2_06V 	1/*!< Brown-out reset at 2.06v */
#define SYSCTL_BODRSTLVL_2_35V 	2/*!< Brown-out reset at 2.35v */
#define SYSCTL_BODRSTLVL_2_63V 	3/*!< Brown-out reset at 2.63v */

/**
 * Brown-out detector interrupt level
 */
#define SYSCTL_BODINTVAL_RESERVED1 0


#if !defined(LPC11AXX)
/**
 * Deep sleep setup values
 */
#define SYSCTL_DEEPSLP_BOD_PD    (1 << 3)	/*!< BOD power-down control in Deep-sleep mode, powered down */
#define SYSCTL_DEEPSLP_WDTOSC_PD (1 << 6)	/*!< Watchdog oscillator power control in Deep-sleep, powered down */


/**
 * Deep sleep to wakeup setup values
 */
#define SYSCTL_SLPWAKE_IRCOUT_PD (1 << 0)	/*!< IRC oscillator output wake-up configuration */
#define SYSCTL_SLPWAKE_IRC_PD    (1 << 1)	/*!< IRC oscillator power-down wake-up configuration */
#define SYSCTL_SLPWAKE_FLASH_PD  (1 << 2)	/*!< Flash wake-up configuration */
#define SYSCTL_SLPWAKE_BOD_PD    (1 << 3)	/*!< BOD wake-up configuration */
#define SYSCTL_SLPWAKE_ADC_PD    (1 << 4)	/*!< ADC wake-up configuration */
#define SYSCTL_SLPWAKE_SYSOSC_PD (1 << 5)	/*!< System oscillator wake-up configuration */
#define SYSCTL_SLPWAKE_WDTOSC_PD (1 << 6)	/*!< Watchdog oscillator wake-up configuration */
#define SYSCTL_SLPWAKE_SYSPLL_PD (1 << 7)	/*!< System PLL wake-up configuration */

#endif

/**
 * Power down configuration values
 */
#define SYSCTL_POWERDOWN_IRCOUT_PD (1 << 0)	/*!< IRC oscillator output power down */
#define SYSCTL_POWERDOWN_IRC_PD    (1 << 1)	/*!< IRC oscillator power-down */
#define SYSCTL_POWERDOWN_FLASH_PD  (1 << 2)	/*!< Flash power down */
#define SYSCTL_POWERDOWN_BOD_PD    (1 << 3)	/*!< BOD power down */
#define SYSCTL_POWERDOWN_ADC_PD    (1 << 4)	/*!< ADC power down */
#define SYSCTL_POWERDOWN_SYSOSC_PD (1 << 5)	/*!< System oscillator power down */
#define SYSCTL_POWERDOWN_WDTOSC_PD (1 << 6)	/*!< Watchdog oscillator power down */
#define SYSCTL_POWERDOWN_SYSPLL_PD (1 << 7)	/*!< System PLL power down */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /*!< __SYSCTL_11XX_ASM_H_ */

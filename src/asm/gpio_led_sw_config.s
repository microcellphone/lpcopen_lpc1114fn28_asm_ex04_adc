/*
Here are some common GCC directives for ARM Cortex-M0 assembly:

.align: Specifies the byte alignment of the following instruction or data item.
.ascii: Specifies a string of characters to be included in the output file.
.asciz: Specifies a zero-terminated string of characters to be included in the output file.
.byte: Specifies one or more bytes of data to be included in the output file.
.data: Marks the start of a data section.
.global: Marks a symbol as visible outside of the current file.
.section: Specifies the section of memory where the following instructions or data items should be placed.
.space: Reserves a block of memory with a specified size.
.thumb: Instructs the assembler to generate Thumb code.
.thumb_func: Marks a function as using the Thumb instruction set.
.word: Specifies one or more words of data to be included in the output file.

Note that this is not an exhaustive list, and different versions of GCC may support additional or different directives.
*/

#include "iocon_11xx_asm.h"
#include "gpio_11xx_2_asm.h"

#define LED1_PORT LPC_GPIO_PORT0_BASE
#define LED1_BIT  7
#define LED2_PORT LPC_GPIO_PORT1_BASE
#define LED2_BIT  0
#define LED3_PORT LPC_GPIO_PORT1_BASE
#define LED3_BIT  4
#define LED4_PORT LPC_GPIO_PORT1_BASE
#define LED4_BIT  5

#define SW1_PORT	LPC_GPIO_PORT1_BASE
#define SW1_BIT 8
#define SW2_PORT	LPC_GPIO_PORT1_BASE
#define SW2_BIT 9
#define SW3_PORT LPC_GPIO_PORT0_BASE
#define SW3_BIT  1
#define SW4_PORT LPC_GPIO_PORT0_BASE
#define SW4_BIT  3

    .syntax unified

    .text
    .global  gpio_config_request
	.thumb
	.thumb_func
    .type	gpio_config_request, %function
gpio_config_request:
	push	{lr}

// 	LPC_IOCON->PIO0_7   = 0x00000000;  //LED1 GPIO, disable pu/pd mos
	ldr		r3, =LPC_IOCON_BASE
	ldr		r1, =IOCON_OFFSET_PIO0_7
	movs	r0, #IOCON_FUNC0
	str		r0, [r3, r1]
//	LPC_IOCON->R_PIO1_0 = 0x00000000;  //LED2 GPIO, disable pu/pd mos
	ldr		r1, =IOCON_OFFSET_R_PIO1_0
	str		r0, [r3, r1]
//	LPC_IOCON->PIO1_4   = 0x00000000;  //LED3 GPIO, disable pu/pd mos
	ldr		r1, =IOCON_OFFSET_PIO1_4
	str		r0, [r3, r1]
//	LPC_IOCON->PIO1_5   = 0x00000000;  //LED4 GPIO, disable pu/pd mos
	ldr		r1, =IOCON_OFFSET_PIO1_5
	str		r0, [r3, r1]

// 	LPC_IOCON->PIO1_8   = 0x00000010;  //SW1 GPIO, pullup
	ldr		r1, =IOCON_OFFSET_PIO1_8
	movs	r0, #(IOCON_FUNC0 | IOCON_MODE_PULLUP | IOCON_DIGMODE_EN)
	str		r0, [r3, r1]
// 	LPC_IOCON->PIO1_9   = 0x00000010;  //SW2 GPIO, pullup
	ldr		r1, =IOCON_OFFSET_PIO1_9
	str		r0, [r3, r1]
// 	LPC_IOCON->PIO0_1   = 0x00000010;  //SW3 GPIO, pullup
	ldr		r1, =IOCON_OFFSET_PIO0_1
	str		r0, [r3, r1]
// 	LPC_IOCON->PIO0_3   = 0x00000010;  //SW4 GPIO, pullup
	ldr		r1, =IOCON_OFFSET_PIO0_3
	str		r0, [r3, r1]

// 	LPC_GPIO0->DIR |= (1 << 7);   // LED1 : PIO0_7 output
	ldr		r3, =LED1_PORT
	ldr		r1, =GPIO_OFFSET_DIR
	ldr		r0, [r3, r1]		// r0 = LPC_GPIO0->DIR
	ldr 	r2, =1 << LED1_BIT		// r2 = (1 << 7)
	orrs	r0, r0, r2
	str		r0, [r3, r1]
// 	LPC_GPIO1->DIR |= (1 << 0);   // LED2 : R_PIO1_0 output
	ldr		r3, =LED2_PORT
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << LED2_BIT
	orrs	r0, r0, r2
	str		r0, [r3, r1]
// 	LPC_GPIO1->DIR |= (1 << 4);   // LED3 : PIO1_4 output
	ldr		r3, =LED3_PORT
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << LED3_BIT
	orrs	r0, r0, r2
	str		r0, [r3, r1]
// 	LPC_GPIO1->DIR |= (1 << 5);   // LED4 : PIO1_5 output
	ldr		r3, =LED4_PORT
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << LED4_BIT
	orrs	r0, r0, r2
	str		r0, [r3, r1]

// 	LPC_GPIO1->DIR &= ~(1 << 8);  // SW1  : PIO1_8 input
	ldr		r3, =SW1_PORT
	ldr		r1, =GPIO_OFFSET_DIR
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW1_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]
// 	LPC_GPIO1->DIR &= ~(1 << 9);  // SW2  : PIO1_9 input
	ldr		r3, =SW2_PORT
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW2_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]
// 	LPC_GPIO0->DIR &= ~(1 << 1);  // SW3  : PIO0_1 input
	ldr		r3, =SW3_PORT
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW3_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]
// 	LPC_GPIO0->DIR &= ~(1 << 3);  // SW4  : PIO0_3 input
	ldr		r3, =SW4_PORT
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW4_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]

// 	LPC_GPIO[0].DATA[(1 << 7)] |= (1 << 7); 	// PIO0_7 -> High
	ldr	r2, =LED1_PORT
	movs	r3, #(1<<LED1_BIT)
	lsls	r3, r3, #2
	ldr	r3, [r2, r3]
	ldr	r2, =LED1_PORT
	movs	r1, #(1<<LED1_BIT)
	orrs	r1, r3
	movs	r3, #(1<<LED1_BIT)
	lsls	r3, r3, #2
	str	r1, [r2, r3]
// 	LPC_GPIO[1].DATA[(1 << 0)] |= (1 << 0);   // PIO1_0 -> High
	ldr	r3, =LED2_PORT
	ldr	r2, [r3, #4]
	ldr	r3, =LED2_PORT
	movs	r1, #(1<<LED2_BIT)
	orrs	r2, r1
	str	r2, [r3, #4]
// 	LPC_GPIO[1].DATA[(1 << 4)] |= (1 << 4);	// PIO1_4 -> High
	ldr	r3, =LED3_PORT
	ldr	r2, [r3, #64]
	ldr	r3, =LED3_PORT
	movs	r1, #(1<<LED3_BIT)
	orrs	r2, r1
	str	r2, [r3, #64]
// 	LPC_GPIO[1].DATA[(1 << 5)] |= (1 << 5);	// PIO1_5 -> High
	ldr	r2, =LED4_PORT
	movs	r3, #128
	ldr	r3, [r2, r3]
	ldr	r1, =LED4_PORT
	movs	r2, #(1<<LED4_BIT)
	orrs	r3, r2
	movs	r2, #128
	str	r3, [r1, r2]

//    LPC_GPIO[1].IS  &= ~(1 << 8);
	ldr		r3, =SW1_PORT
	ldr		r1, =GPIO_OFFSET_IS
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW1_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]
//     LPC_GPIO[1].IBE &= ~(1 << 8);
	ldr		r1, =GPIO_OFFSET_IBE
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW1_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]
//     LPC_GPIO[1].IEV &= ~(1 << 8);
	ldr		r1, =GPIO_OFFSET_IEV
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW1_BIT
	mvns	r2, r2
	ands	r0, r0, r2
	str		r0, [r3, r1]
//  LPC_GPIO[1].IE  |=  (1 << 8);
	ldr		r1, =GPIO_OFFSET_IE
	ldr		r0, [r3, r1]
	ldr 	r2, =1 << SW1_BIT
	orrs	r0, r0, r2
	str		r0, [r3, r1]

RETURN:
	nop
	pop	{pc}

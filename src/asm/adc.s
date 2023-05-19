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

#include "adc_11xx_asm.h"
#include "iocon_11xx_asm.h"
#include "sysctl_11xx_asm.h"

    .syntax unified

    .text
    .global  ADC_Config_Request
	.thumb
	.thumb_func
    .type	ADC_Config_Request, %function
ADC_Config_Request:
	ldr		r3, =LPC_IOCON_BASE
	ldr		r1, =IOCON_OFFSET_R_PIO0_11
	movs	r0, #(IOCON_FUNC2 | IOCON_MODE_INACT | IOCON_ADMODE_EN)
	str		r0, [r3, r1]

    // ADC_PD='0'
	ldr		r1, =LPC_SYSCTL_BASE
	ldr		r2, =SYSCTL_OFFSET_PDRUNCFG
	ldr 	r3, [r1, r2]
	ldr		r4, =~SYSCTL_POWERDOWN_ADC_PD
	ands 	r3, r3, r4
	str		r3, [r1, r2]
    // ADC='1'
	ldr		r2, =SYSCTL_OFFSET_SYSAHBCLKCTRL
	ldr 	r3, [r1, r2]
	ldr		r4, =(1 << 13)
	orrs 	r3, r3, r4
	str		r3, [r1, r2]

//    LPC_ADC->CR |= (1 << 0);
	ldr		r1, =LPC_ADC_BASE
	ldr		r2, =ADC_OFFSET_CR
	ldr 	r3, [r1, r2]
	ldr		r4, =ADC_CR_CH_SEL(ADC_CH0)
	orrs 	r3, r3, r4
	str		r3, [r1, r2]
//     LPC_ADC->CR |= (10 << 8);
	ldr 	r3, [r1, r2]
	ldr		r4, =ADC_CR_CLKDIV(10)
	orrs 	r3, r3, r4
	str		r3, [r1, r2]
//     LPC_ADC->CR |= (1 << 16);
	ldr 	r3, [r1, r2]
	ldr		r4, =ADC_CR_BURST
	orrs 	r3, r3, r4
	str		r3, [r1, r2]

	bx lr
	.size	ADC_Config_Request, .-ADC_Config_Request

    .text
    .global  ADC_Get_Data
	.thumb
	.thumb_func
    .type	ADC_Get_Data, %function
ADC_Get_Data:
    push {lr}
    movs r1, #0
    ldr r2, =LPC_ADC_BASE
    ldr r3, =ADC_OFFSET_DR
 	lsls r5, r0, #2
	adds r5, r5, r3
wait_conversion:
    ldr r4, [r2, r5]
    ldr r3, =(1<<31)
    tst r4, r3
    beq wait_conversion
    lsrs r0, r4, #6
    ldr r3, =0x3ff
    ands r0, r0, r3
    pop {pc}
    .size	ADC_Get_Data, .-ADC_Get_Data

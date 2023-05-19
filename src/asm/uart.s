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

#include "uart_11xx_asm.h"
#include "iocon_11xx_asm.h"
#include "sysctl_11xx_asm.h"

    .syntax unified

    .text
    .global  USART_Config_Request
	.thumb
	.thumb_func
    .type	USART_Config_Request, %function
USART_Config_Request:
	push	{r7, lr}
	sub	sp, sp, #16
	add	r7, sp, #0
	str	r0, [r7, #4]		//baudrate
	ldr	r2, =LPC_IOCON_BASE
	movs	r3, #IOCON_OFFSET_PIO1_6
	ldr	r3, [r2, r3]
	ldr	r1, =LPC_IOCON_BASE
	movs	r2, #IOCON_FUNC1
	orrs	r3, r2
	movs	r2, #IOCON_OFFSET_PIO1_6
	str	r3, [r1, r2]
	ldr	r2, =LPC_IOCON_BASE
	movs	r3, #IOCON_OFFSET_PIO1_7
	ldr	r3, [r2, r3]
	ldr	r1, =LPC_IOCON_BASE
	movs	r2, #IOCON_FUNC1
	orrs	r3, r2
	movs	r2, #IOCON_OFFSET_PIO1_7
	str	r3, [r1, r2]
	ldr	r2, =LPC_SYSCTL_BASE
	movs	r3, #SYSCTL_OFFSET_SYSAHBCLKCTRL
	ldr	r3, [r2, r3]
	ldr	r1, =LPC_SYSCTL_BASE
	movs	r2, #SYSCTL_OFFSET_SYSAHBCLKCTRL
	lsls	r2, r2, #5
	orrs	r3, r2
	movs	r2, #SYSCTL_OFFSET_SYSAHBCLKCTRL
	str	r3, [r1, r2]
	ldr	r2, =LPC_SYSCTL_BASE
	movs	r3, #SYSCTL_OFFSET_USARTCLKDIV
	movs	r1, #1
	str	r1, [r2, r3]
	ldr	r3, =LPC_SYSCTL_BASE
	ldr	r2, [r3, #SYSCTL_OFFSET_SYSAHBCLKDIV]
	ldr	r3, =SystemCoreClock
	ldr	r3, [r3]
	muls	r3, r2
	movs	r0, r3
	ldr	r2, =LPC_SYSCTL_BASE
	movs	r3, #SYSCTL_OFFSET_USARTCLKDIV
	ldr	r3, [r2, r3]
	ldr	r2, [r7, #4]	//baudrate
	muls	r3, r2
	lsls	r3, r3, #4
	movs	r1, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	str	r3, [r7, #12]
	ldr	r3, =LPC_USART_BASE
	ldr	r2, [r3, #USART_OFFSET_LCR]
	ldr	r3, =LPC_USART_BASE
	movs	r1, #128
	orrs	r2, r1
	str	r2, [r3, #USART_OFFSET_LCR]
	ldr	r3, =LPC_USART_BASE
	ldr	r2, [r7, #12]
	lsrs	r2, r2, #8
	str	r2, [r3, #USART_OFFSET_DLM]
	ldr	r3, =LPC_USART_BASE
	ldr	r2, [r7, #12]
	movs	r1, #255
	ands	r2, r1
	str	r2, [r3]
	ldr	r3, =LPC_USART_BASE
	ldr	r2, [r3, #USART_OFFSET_LCR]
	ldr	r3, =LPC_USART_BASE
	movs	r1, #(1<<7)
	bics	r2, r1
	str	r2, [r3, #USART_OFFSET_LCR]
	ldr	r3, =LPC_USART_BASE
	movs	r2, #UART_LCR_WLEN8
	str	r2, [r3, #USART_OFFSET_LCR]
	ldr	r3, =LPC_USART_BASE
	movs	r2, #(UART_FCR_TX_RS|UART_FCR_RX_RS|UART_FCR_FIFO_EN)	// 7
	str	r2, [r3, #USART_OFFSET_FCR]
	nop
	mov	sp, r7
	add	sp, sp, #16
	@ sp needed
	pop	{r7, pc}


    .text
    .global  USART_putc
	.thumb
	.thumb_func
    .type	USART_putc, %function
USART_putc:
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r2, r0
	adds	r3, r7, #7
	strb	r2, [r3]
	nop
.L5:
	ldr	r3, =LPC_USART_BASE
	ldr	r3, [r3, #USART_OFFSET_LSR]
	movs	r2, #UART_LSR_THRE
	ands	r3, r2
	beq	.L5
	ldr	r3, =LPC_USART_BASE
	adds	r2, r7, #7
	ldrb	r2, [r2]
	str	r2, [r3, #USART_OFFSET_THR]
	nop
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	1073774592

     .text
    .global  USART_puts
	.thumb_func
    .type	USART_puts, %function
USART_puts:
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	str	r0, [r7, #4]
	b	check
send:
	ldr	r3, [r7, #4]
	ldrb	r3, [r3]
	movs	r0, r3
	bl	USART_putc
	ldr	r3, [r7, #4]
	adds	r3, r3, #1
	str	r3, [r7, #4]
check:
	ldr	r3, [r7, #4]
	ldrb	r3, [r3]
	cmp	r3, #0
	bne	send
	nop
	nop
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
	.size	USART_puts, .-USART_puts

     .text
    .global  USART_getc
	.thumb_func
    .type	USART_getc, %function
USART_getc:
    movs r0, #0
wait_for_data:
    ldr r1, =LPC_USART_BASE
    ldrb r2, [r1, #USART_OFFSET_LSR]
    movs r3, #UART_LSR_RDR
    tst r2, r3
    bne read_data
    b wait_for_data
read_data:
    ldr r0, =LPC_USART_BASE
    ldrb r0, [r0, #USART_OFFSET_RBR]
    bx lr
	.size	USART_getc, .-USART_getc

/*
===============================================================================
 Name        : lpcopen_lpc1114fn28_asm_ex04_adc.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "my_delay.h"

// TODO: insert other definitions and declarations here
#define VDD 3126

extern void gpio_config_request(void);
extern void ADC_Config_Request(void);
extern uint32_t ADC_Get_Data(uint32_t port);
extern void USART_Config_Request(uint32_t baudrate);
extern void USART_putc(char data);
extern void USART_puts(char *str);
extern void USART_putc_decimal(uint32_t data);

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here
    uint32_t adc_value, converted_value;

	SysTick_Config(SystemCoreClock/1000 - 1); /* Generate interrupt each 1 ms   */
    USART_Config_Request(115200);
    ADC_Config_Request();
    USART_puts("lpcopen_lpc1114fn28_asm_ex04_adc\r\n");

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        USART_puts("  Measurement Value = ");
        adc_value = ADC_Get_Data(0);
        USART_putc_decimal(adc_value);
        converted_value = adc_value * VDD / 0x3ff;
        USART_puts("  The converted voltage value = ");
        USART_putc_decimal(converted_value);
        USART_puts("[mV]    \r");
        Delay(500);
		i++ ;
    	// "Dummy" NOP to allow source level single
    	// stepping of tight while() loop
    	__asm volatile ("nop");
    }
    return 0 ;
}

void USART_putc_decimal(uint32_t data)
{
    char converted_str[16];
    int16_t count=0;
    int16_t str_cnt;

    do {
    	converted_str[count++] = data % 10 + '0';
    } while (( data /= 10 ) != 0);
    count--;
    for( str_cnt=count; str_cnt>=0; str_cnt-- ) {
       USART_putc(converted_str[str_cnt]);
    }
}

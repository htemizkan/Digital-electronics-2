/* DEFINES */
 
#include <util/delay.h>
#include <stdlib.h>         
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "uart.h"
#include "gpio.h"
#include "segment.h"

//static uint8_t dist = 0;
//static uint8_t counter = 0;
//static uint8_t echo 
//static uint8_t trig 

#define TRIG   PD1
#define ECHO   PD0

int main(void)
{
    //uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU)); // 8N1

    
    TIM_config_prescaler(TIM0, TIM_PRESC_8);
    TIM_config_interrupt(TIM0, TIM_OVERFLOW_ENABLE);  
    GPIO_config_output(&DDRD,TRIG);
    GPIO_config_input_nopull(&PORTD,ECHO);

    sei();
  
    


    for (;;) {
        GPIO_toggle(&PORTD,TRIG);
        
        _delay_us(10);

        
        
    }

    return (0);
}


ISR(TIMER0_OVF_vect)
{
 //counter = counter;

 


}
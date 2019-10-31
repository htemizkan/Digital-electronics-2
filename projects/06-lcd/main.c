/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-10-16
 * Last update: 2019-10-24
 * Platform:    ATmega328P, 16 MHz, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description:
 *    Decimal counter with data display on LCD display.
 * 
 * Note:
 *    Modified version of Peter Fleury's LCD library with R/W pin 
 *    connected to GND. Newline symbol "\n" is not implemented, use
 *    lcd_gotoxy() function instead.
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
 *  Brief:  Main program. Shows decimal values ​​on LCD display.
 *  Input:  None
 *  Return: None
 */
  uint8_t value = 255;
    char lcd_string [3];
    char lcd_string1 [5];
    char lcd_string2 [9];

int main(void)
{
    /* LCD display
     * TODO: Initialize display and test different types of cursor */
    lcd_init(LCD_DISP_ON_CURSOR_BLINK); 
    TIM_config_prescaler(TIM1, TIM_PRESC_256);
    TIM_config_interrupt(TIM1, TIM_OVERFLOW_ENABLE);
   
    

    //Display string without auto linefeed
    lcd_gotoxy (0,0);
    lcd_puts("Counter: ");
    //itoa(value,lcd_string,10);  
   // lcd_puts(lcd_string);

    lcd_gotoxy (0,1);
   // itoa(value,lcd_string1,16);   
    lcd_puts("0x");
    lcd_puts(lcd_string1);
    lcd_gotoxy (6,1);
    lcd_puts(" 0b");   
   //itoa(value,lcd_string2,2);
   // lcd_puts(lcd_string2);

   


    /* Timer1
     * TODO: Configure Timer1 clock source and enable overflow 
     *       interrupt */

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    for (;;) {
    }

    return (0);
}

/**
 *  Brief: Timer1 overflow interrupt routine. Increment counter value.
 */
ISR(TIMER1_OVF_vect)
{
    // TODO: Increment counter value form 0 to 99

    static uint8_t x=0;
    x++;

    //lcd_puts("Counter: ");
    lcd_gotoxy (9,0);
    itoa(x,lcd_string,10);  
    lcd_puts(lcd_string);
    lcd_gotoxy (2,1);
    itoa(x,lcd_string1,16);  
    //lcd_puts("0x");
    lcd_puts(lcd_string1);
    //lcd_puts(" 0b");
    //lcd_gotoxy (1,0);
    lcd_gotoxy (9,1);
    itoa(x,lcd_string2,2);
    lcd_puts(lcd_string2);
     	

}

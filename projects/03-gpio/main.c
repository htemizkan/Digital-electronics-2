/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-09-27
 * Last update: 2019-09-26
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Blink a LED with delay function.
 * TODO: Verify functionality of LED blinker.
 * NOTE: Macro _BV converts a bit number into a byte value (see AVR Libc
 * Reference Manual).
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define BLINK_DELAY 250
#define LED_RED PB0
#define BTTN PD2

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
  * Brief:  Main program. Blink a LED with delay function.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pin */
    GPIO_config_output(&DDRB,LED_RED);
    GPIO_config_output(&DDRB,LED_GREEN);      /* DDRB = DDRB or (0010 0000) */
    //GPIO_config_output(&DDRD,BTTN);
    //GPIO_GPIOtoggle(&DDRD,BTTN);
    
    GPIO_config_input_pullup(&PORTD, BTTN);
    GPIO_write(&DDRB,LED_RED,0);
    GPIO_write(&DDRB,LED_GREEN,1);

   
    
    for (;;)
    {      
      if (bit_is_clear(PIND , BTTN))
      {
        /* Invert LED and delay */
        GPIO_toggle(&DDRB,LED_RED);
          

        GPIO_toggle(&DDRB,LED_GREEN);   /* PORTB = PORTB xor (0010 0000) */
        //PORTB ^= _BV(LED_RED);
        
        _delay_ms(BLINK_DELAY);     /* Wait for several milisecs */
        
       
      }


    }

    return (0);
}

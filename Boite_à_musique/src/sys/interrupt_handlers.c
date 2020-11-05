#include <stdio.h>
#include "interrupt_handlers.h"
#include "sys/systick.h"
#include "sys/devices.h" 
#include "sing_song.h"

volatile uint32_t next;
volatile uint32_t flag_play_note;
volatile uint32_t counter;           
volatile uint32_t play_pause;
volatile uint32_t i;
volatile uint32_t j;
volatile uint32_t LED_flag;         /*contine flagul pentru schimbarea culorii Tri-LED-ului*/

void __attribute__((interrupt)) SysTick_Handler()
{
    if(flag_play_note == 1)                     /* If this variable is 1 we allow Systick to run */
        {
            if(counter != 0)                    /* Counter contains the delay we need */
                counter = counter - 1; 
            else
                flag_play_note = 0;             /* After the delay is finished 
                                                the Systick will be stoped automatically*/
        }
    
}

void __attribute__((interrupt)) EXTI9_5_Handler() /* Shield User Button for next song functionality */
{
    EXTI.PR |= 1 << 8; /* this is for stoping the interuption */
    
    LED_flag = 2;   /* Sets the state on loading next state */
    next = 1;       /* Allows the changing of the song */

}


void __attribute__((interrupt)) EXTI15_10_Handler()/* STM32 User Button for the play/pause function*/
{
    EXTI.PR |= 1 << 13; /* this is for stoping the interuption */
                        
    
    LED_flag = 1;       /* Sets the LED mode to Pause */                   
                        
    play_pause++;       /* Increments the global variable that tracks the play/pause sequence */
    
    if(play_pause == 2) /* Is we are in the pause state, we need to reset to play */
        play_pause = 0; /* So we place 0 again in the variable */
    
    
}

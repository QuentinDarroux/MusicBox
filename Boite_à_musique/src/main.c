#include <stdio.h>
#include "sys/devices.h"
#include "sys/systick.h"
#include "sys/serial_io.h"  

#include "sys/functions_init.h"
#include "sys/song_definitions.h"
#include "sys/sing_song.h"
#include "sys/potentiometer.h"
#include "sys/button.h"
#include "sys/interrupt_handlers.h"
#include "sys/initial_LED.h"


volatile uint32_t flag_play_note;   /* This flag allows Systick to start the specific delay */
volatile uint32_t counter;          /* Containes the current value of the delay*/
volatile uint32_t play_pause;       /* Keeps track of the play-pause sequence induced by the user throug the button */
volatile uint32_t next;             /* Tells us if the user pressed the button in order to go to the next song */
volatile uint32_t LED_flag;         /* Contains the state of the board: 0 - Green = Play; 1 - REd = PAuse; 2 - Blue = State*/
volatile uint32_t LED_offset;       /* Allow the four LEDs model to repeat after it reached the maximum amount of steps */

volatile uint32_t i;    /* Keeps track of the song number starting from 0 */
volatile uint32_t j;    /* Keeps track of the musical note number in a song starting from 0 */

volatile uint32_t step_4_LEDs;        /* VAriable that increments with j and allows us to play the light on music and restart any model at any time */
volatile uint32_t current_switch_value; /* Containes the read value with the help of a function */
volatile uint32_t old_switch_value;     /* Containes the old value of the swich allowing to see if there was any change. Helps when changing 4 LEDs */

Note *song_list[NUMBER_SONGS]={berceuse, au_clair_de_la_lune, harry_potter_theme, Bond, th_century_fox}; /* Containes the names of our songs */


int main() {
    
    SysTick_init(1000);                          /* Starts systick and setup at 1 second*/
    init_TIM2();                                 /* Initialize the timer by placing starting values inside the registers */
    init_buzzer_GPIOB();                         /* Setup the port on Alternative Function Mode */
    configuration_potentiometre_PB0();           /* Setup of the port of the potentiometer */
    setup_ADC();                                 /* Place the right values in the registers of the ADC1*/
    
    button_init();                               /* Initialize the button PB8 - On the shield board */
    button_irq_init();                           /* Setup the interrupt for the first button on PB8 */
    
    button_init_2();                             /* Initialize the button PC13 - On the STM32 board */    
    button_irq_init2();                          /* Setup the interrupt for the first button on PB8 */
    
    initialize_LEDs();                           /* Prepare the LEDs by placing the right values in the registers */
   
   /* Place the right values in the variables that we are going to use later in our program */
    
   LED_offset = 0; 
   i = 0;
   j = 0;
   play_pause = 0;
   next = 0;
   step_4_LEDs = 0;
   current_switch_value = 0;
   old_switch_value = 10;

    while(1)  /* Infinite while to play the music untill the musix box is stopped*/
        {

            if(i == NUMBER_SONGS) /* Here we check if the maximum number of song was reached and if so, we restart the playlist */
                {
                    i = 0;
                }
                  
            while(song_list[i][j].freq != 0 && song_list[i][j].duree != 0)  /* This loop plays the song and it will play untill it reaches the end */
                {                                                           /* Each song is finishing by {0,0} */
                    LED_flag = 0;               /* Set the state on play */
                    board_current_state();      /* Update the tri LED so it will show the current state */
                    
                    current_switch_value = read_value_switch(); /* Store the value of the switch in the current_switch_value variable*/
                    
                    if(current_switch_value != old_switch_value) /* If we notice a variation in the switches we prepare for the chosen 4 LEDs model*/
                        {
                            step_4_LEDs = 0;
                            old_switch_value = current_switch_value;
                            LED_offset = 0;
                        }
                    
                    four_LED_band(); /* We update the 4 LEDs model accordingly */
                    
                    
                    sing_note(song_list[i][j].freq, song_list[i][j].duree); /* Here we call the function to play the note based on note freq and                duration*/
                    pause_entre_note(); /*Between 2 notes we have a break. If we have the same note more times it will be played as separate notes */
                    
                    board_current_state();  /* We update the state of the board as the user may be pressed a button */
                    
                    while(play_pause == 1)  /* If he pressed pause we enter the loop and remain here untill the user presses the play button */
                        {
                            if(next == 1) /* If the next button is pressed we prioritize next and play the song that follows */
                                {
                                    play_pause = 0; 
                                }
                        }
                    
                    if(next == 1) /* If next button was pressed we go to the next song by breaking the loop of the current song */
                        {
                            break; 
                        }
                        
                    j++;            /* Increase the note */
                    step_4_LEDs++;  /* Increase the 4 LEDs model on music */
                    
                }
            
            LED_flag = 2;
            board_current_state();     /* Changes the state of the board to next song */
            four_LED_band();           /* This stops the 4 LEDs during break between songs */
            
            pause_entre_songs();       /* This is a 3 seconds break between each song */
          
            
            /* Prepare the variables for the next song */
            
            next = 0;                   
            i++;
            j = 0;  
            step_4_LEDs = 0;
            
            current_switch_value = 0;
            old_switch_value = 10;     /* This value can be other, but different from 0, the one of current_switch_value */
            
        }
    
    
    return 0;

    
}   























    
    

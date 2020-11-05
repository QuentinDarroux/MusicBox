#include "stdio.h"
#include "sing_song.h"
#include "sys/clock.h"
#include "devices.h"
#include "potentiometer.h"


volatile uint32_t flag_play_note;
volatile uint32_t counter;            
volatile uint32_t play_pause;


void sing_note(uint32_t frequency, uint32_t duree) /* This function playes a note with the frequency and duration as parameters */
{
    
    TIM2.ARR = (get_APB1TIMCLK() / (TIM2.PSC + 1)) / (frequency - 1); /* Modify the frequency of a specific note based on prescaler and timer clk */
    
    TIM2.EGR |= 1;  /* Update the frequency of the note */

    counter = duree;    /* Place the duration of the note in the counter that will be decreased by the Systick*/
    
    TIM2.CR1 |= 1;  /* Enable the timer to send the signal */   

    flag_play_note = 1; /* Allowing the Systick to start decreasing the counter */   
    
    while(counter != 0) /* While we hear the note - so we can hear the volume changing */
        {
            modify_volume_potentiometer(); /* Modify the volume with the potentiometer */
        }
    
}

void pause_entre_note() /* Function that produces a pause between notes */
{
    
    TIM2.ARR = (get_APB1TIMCLK() / (TIM2.PSC + 1)) / (40000 - 1); /* Produce a high frequency that we cannot hear as a "pause" */
    
    TIM2.EGR |= 1; /* Update the ARR register */
    
    counter = 100; /*We have a 0.1 seconds pause between each note so we will not loose the tempo and still distinguish same notes*/
    
    flag_play_note = 1;  /* Allowing the Systick to start decreasing the counter */  
    
    while(counter != 0); /* Don't pass untill the delay is not finished */
}

void pause_entre_songs()
{
    
    TIM2.ARR = (get_APB1TIMCLK() / (TIM2.PSC + 1)) / (40000 - 1); /* Produce a high frequency that we cannot hear as a "pause" */
    
    TIM2.EGR |= 1; /* Update the ARR register */
    
    counter = 3000; /*We have a 3 seconds pause between each song */
    
    flag_play_note = 1;  /* Allowing the Systick to start decreasing the counter */  
    
    
    while(counter != 0); /* Don't pass untill the delay is not finished */
    
}







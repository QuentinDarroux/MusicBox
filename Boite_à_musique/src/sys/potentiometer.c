#include <stdio.h>
#include "sys/devices.h"

uint32_t reading_potentiometer() 
{
    
    ADC1.SR = 0;
    ADC1.CR2 |= (1 << 30);  /* Start conversion */
    
    while((ADC1.SR & 0x22) == 0); /* Looking for eoc and overrun */
        
    return ADC1.DR; /* Return the current value of the potentiometer */
    
}

void modify_volume_potentiometer() /* This function modifies the actual volume of the music box */
{
    uint32_t volume = reading_potentiometer(); /* Storing the value of the potentiometer in a variable */
    
    /* For this part we used USART2 in order to see at which values, the sound quality remains high. Also we saw that
     after a certain value the sound is mute. We used this observation to have volume 0 if wanted */
    
    if(volume > 4090)   
        {
            volume = 5;
        }
    else if(volume < 450)
        {
            volume = 450;
        }
        
    volume = volume / 20;
    
    /*
        Another version of working volume modifier:
        
        uint32_t min = 500;
        volume = ((min - 2) * volume / 4096) + 2;
    
     */
    
    TIM2.CCR2 = TIM2.ARR / volume; /* Modify the value of the CCR2 and thus the volume of the board */

}

void setup_ADC() /* This function prepares ADC1 for usage. We need it to convert the values of the potentiometer */
{
    enable_ADC1();
    
    ADC1.CR2 |= 1; /* Enabling ADC */ 
    ADC1.SR = 0;   /* Initializing SR with 0 */ 
    ADC_common.CCR = (ADC_common.CCR & ~(0b11 << 16)) | (0b01 << 16); /* We divide the clock by 4 to reduce the speed */
    ADC1.SMPR2 = ADC1.SMPR2 | (0b111 << 24);         /* 480 cycles */ 
    
    ADC1.SQR3 = (ADC1.SQR3 & ~(0b1111)) | (0b1000);  /* Setup the channel for PB0 - Potentiometer */
    ADC1.SQR1 = ADC1.SQR1 & ~(0b1111 << 20);         /* 16 conversions in the regular channel */
    
}

void configuration_potentiometre_PB0() /* Setting the potentiometer PB0 */
{
    enable_GPIOB();
    
    GPIOB.MODER = GPIOB.MODER | (0b11);     /* Analog mode */
    
    /*GPIOB.OTYPER = GPIOB.OTYPER & ~(0b1); */
    
}

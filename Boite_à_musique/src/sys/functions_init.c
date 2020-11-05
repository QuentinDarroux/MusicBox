#include "stdio.h"
#include "devices.h"
#include "functions_init.h"


void init_buzzer_GPIOB() /* This function will setup the buzer PB9 on alternative mode */
{
	enable_GPIOB();
	GPIOB.MODER |= (2<<18); /* Alternate fonction mode */
	GPIOB.AFRH |= (1<<4); /* Alternate mode sur AF1 */
}


void init_TIM2()   /* This function initiates the timer TIM2 - 32 bits*/
{
	
    enable_TIM2(); /* Here we turn on the Timer */
    
    /*PWM signal on mode 1*/
    TIM2.CCMR1 = (TIM2.CCMR1 & ~(0b111 << 12)) | (0b110 << 12);    
    TIM2.CCMR1 = (TIM2.CCMR1 & ~(0b1 << 11)) | (0b1 << 11); 
    
    TIM2.CCER |= (1<<4);    
    TIM2.CNT = 0;           /* Initialize the counter to zero */
	TIM2.PSC = 80;          /* Set the prescaler to 80 */
	
	TIM2.CR1 |= (1<<7);     /* Auto-Reload is buffered */
    
}

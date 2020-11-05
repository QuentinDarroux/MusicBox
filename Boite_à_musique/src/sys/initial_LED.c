#include <stdio.h>
#include "initial_LED.h"
#include "sys/devices.h"


volatile uint32_t step_4_LEDs; /* Variable which is modified in the main function that increments with j(the index of the note in a song). Allows the tracking of the notes so we can synchronise the LEDs with the notes*/
volatile uint32_t LED_flag; /* Variable that contains the state of the board. 0 = Play; 1 = Pause; 2 = Loading next song */
volatile uint32_t LED_offset; /* Variable which allows us to restart the cycle of LEDs models each time they finish */


void initialize_LEDs()
{
    
    enable_GPIOA();
    
    /* Tri-LED setup */
    
    GPIOA.MODER = (GPIOA.MODER & ~(0x3F << 16)) | (0x15 << 16);
    GPIOA.OTYPER = GPIOA.OTYPER & ~(0x7 << 8);
    
    /* Four-LEDs-Band */
    
    GPIOA.MODER = (GPIOA.MODER & ~(0xFF << 8)) | (0x55 << 8);
    GPIOA.OTYPER = GPIOA.OTYPER & ~(0xF << 4);
    
}


void board_current_state()
{
    
    if(LED_flag == 0)  /*Play song*/
        {
            
            GPIOA.ODR = GPIOA.ODR & ~(1 << 8); /* Red */
            GPIOA.ODR = GPIOA.ODR & ~(1 << 10); /* Blue */
            
            GPIOA.ODR = GPIOA.ODR | (0b1 << 9) ; /* Green */
            
        }
    else if(LED_flag == 1)  /*Pause song*/
        {
            
            GPIOA.ODR = GPIOA.ODR & ~(1 << 9); /* Green */
            GPIOA.ODR = GPIOA.ODR & ~(1 << 10); /* Blue */
            
            GPIOA.ODR = GPIOA.ODR | (0b1 << 8) ; /* Red */
            
        }
    else if(LED_flag == 2)  /*Change song*/
        {
            GPIOA.ODR = GPIOA.ODR & ~(1 << 9); /* Green */
            GPIOA.ODR = GPIOA.ODR & ~(1 << 8); /* Red */
            
            GPIOA.ODR = GPIOA.ODR | (0b1 << 10) ; /* Blue */
        }
    
    
}

void four_LED_band() /* Function wich modifies the play lights depnding on the user's choice*/
{
    
    if(LED_flag == 2 || read_value_switch() == 0) /* if next song / switch to 0*/
        {
            GPIOA.ODR = GPIOA.ODR & ~(0xF << 4); /* Turn off the 4 LEDs*/
        }
    else
        {
            if(read_value_switch() == 1)  /* LED Model Option 1 */
                {
                        if(step_4_LEDs == 0 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1010 << 4);
                            }

                        if(step_4_LEDs == 1 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0101 << 4);
                            }
                        
                        if(step_4_LEDs == 2 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0011 << 4);
                            }

                        if(step_4_LEDs == 3 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1100 << 4);
                            }
                            
                        if(step_4_LEDs == 4 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0110 << 4);
                            }

                        if(step_4_LEDs == 5 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1001 << 4);
                                LED_offset = LED_offset + 6;
                            }    
                }
                else if(read_value_switch() == 2)  /* LED Model Option 2 */
                {
                    
                        if(step_4_LEDs == 0 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0100 << 4);

                            }

                        if(step_4_LEDs == 1 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1100 << 4);
                            }
                        
                        if(step_4_LEDs == 2 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1101 << 4);
                            }

                        if(step_4_LEDs == 3 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1111 << 4);
                            }
                            
                        if(step_4_LEDs == 4 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4));
                            }
                            
                        if(step_4_LEDs == 5 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1111 << 4);
                            }
                        
                        if(step_4_LEDs == 6 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1101 << 4);
                            }
                        
                        if(step_4_LEDs == 7 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1100 << 4);
                            }
                        
                        if(step_4_LEDs == 8 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0100 << 4);
                            }
                        
                        if(step_4_LEDs == 9 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0000 << 4);
                                LED_offset = LED_offset + 10;
                            }
                }
                else if(read_value_switch() == 4)  /* LED Model Option 3 */
                {
                    
                        if(step_4_LEDs == 0 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0110 << 4);
                            }
                        
                        if(step_4_LEDs == 1 + LED_offset)
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1001 << 4);
                                LED_offset = LED_offset + 2;
                            }
                            
                        if(step_4_LEDs == 2 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1100 << 4);
                            }
                        
                        if(step_4_LEDs == 3 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0011 << 4);
                                LED_offset = LED_offset + 4;
                            }
                            
                }
                else if(read_value_switch() == 8)  /* LED Model Option 4 */
                {
                    
                        if(step_4_LEDs == 0 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1000 << 4);
                            }
                        
                        if(step_4_LEDs == 1 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0100 << 4);
                            }
                        
                        if(step_4_LEDs == 2 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0010 << 4);
                            }
                        
                        if(step_4_LEDs == 3 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0001 << 4);
                            }
                        
                        if(step_4_LEDs == 4 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0010 << 4);
                            }
                        
                        if(step_4_LEDs == 5 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b0100 << 4);
                            }
                        
                        if(step_4_LEDs == 6 + LED_offset) 
                            {
                                GPIOA.ODR = (GPIOA.ODR & ~(0xF << 4)) | (0b1000 << 4);
                                LED_offset = LED_offset + 7;
                            }
                            
                }
                else
                {
                    GPIOA.ODR = GPIOA.ODR & ~(0xF << 4); /* If the user chooses another model that was not programed the LEDs turn of such that he is noticed that the combination does not exist */ 
                    
                }
            
        }
    
}


uint32_t read_value_switch()
{
    return ((GPIOB.IDR & (0x78)) >> 3); /* We return the current value of the switches */ 
}

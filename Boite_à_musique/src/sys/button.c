#include <stdio.h>
#include "button.h"
#include "sys/devices.h"


void button_init() {    /*This sets up the button on PB8 - User Button Shield and also the Switches */

	GPIOB.MODER = GPIOB.MODER & ~(0xFF<<6 | 3<<16);    /* Input */
	GPIOB.PUPDR = GPIOB.PUPDR & ~(0xFF<<6 | 3<<16);    /* No pull */
}

void button_irq_init () {   /* This is for seting up the interrupt on the button PB8 - User Button Shield */
    
  /* set PB8 as EXTI8 input */
  SYSCFG.EXTICR3 = (SYSCFG.EXTICR3 & ~(0xf<<0)) | (0x1<<0);

  /* Setup interrupt for EXTI8, falling edge */
  EXTI.IMR  |= (1<<8);
  EXTI.RTSR &= ~(1<<8);
  EXTI.FTSR |= (1<<8);

  /* enable EXTI8 IRQ */
  NVIC.ISER[23/32]=(1<<(23%32)); 
}

void button_init_2() {  /* This sets up the button on PC13 - User Button STM32*/

	GPIOC.MODER = GPIOB.MODER & ~(0b11<<26);   /* Input */
	GPIOC.PUPDR = GPIOB.PUPDR & ~(0b11<<26);   /* No pull */
}

void button_irq_init2 () {   /* This is for seting up the interrupt on the button PC13 - User Button STM32 */
    
  /* set PC13 as EXTI15_10 input */
  SYSCFG.EXTICR4 = (SYSCFG.EXTICR4 & ~(0xf0<<0)) ^ (0x20);

  /* Setup interrupt for EXTI13, falling edge */
  EXTI.IMR  |= (1<<13);
  EXTI.RTSR &= ~(1<<13);
  EXTI.FTSR |= (1<<13); 
  
  /* enable EXTI13 IRQ */
  NVIC.ISER[40/32]=(1<<(40%32));
}

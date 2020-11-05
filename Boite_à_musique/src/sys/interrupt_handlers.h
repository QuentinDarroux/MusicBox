#include <stdio.h>

void __attribute__((interrupt)) SysTick_Handler();
void __attribute__((interrupt)) EXTI9_5_Handler();
void __attribute__((interrupt)) EXTI15_10_Handler();

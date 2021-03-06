#include "delay.h"						//we use software delay

#define DLY_MS		(62/2.5/0.67)			//62@no optimization

//delay a number of cycles
void delay(uint32_t dly) {
	while (dly--) NOP();
}

//delay a few us
void delay_us(uint32_t dly_us) {
	delay(dly_us);
	dly_us = dly_us >> 8;
	while (dly_us--) delay(0xff);			//delay(1);	//adjust dly_us for f_cpu
}

//delay a few ms
void delay_ms(uint32_t dly_ms) {
	while (dly_ms--) delay_us(DLY_MS * (F_CPU / 1000000ul));
}


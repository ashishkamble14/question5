/*
  Author     : Ashish Kamble
  File name  : main
  Created on :
  Programmer : Usbasp
  This program is to change the default clock frequency of ATmega16 chip to 8MHz using a code.
  This program also designed to generate a 2KHz square wave output on PIN 19 which is the OC1A pin ofATmega16
  The square wave is generated using a TIMER 1 with clock frequency as 8MHz.
*/

#include<avr/io.h>
#include<util/delay.h>
#include "pwm.c"

//The below is taken form fuse.h located in avr/io.h library
//To use this changes have been made in the makefile, the .hex file of lfuse ,hfuse have been linked with the elf file 
//Below by using the defined structure the low and high fuse bytes have been initiliased,so that the default clock frequency changes from
//1MHz to 8Mhz
FUSES = 
{
	.low = ((FUSE_SUT0>>0) & (FUSE_CKSEL1>>0) & (FUSE_CKSEL2>>0) & (FUSE_CKSEL3>>0)),

	.high = ((FUSE_JTAGEN>>0) & (FUSE_SPIEN>>0) & (FUSE_BOOTSZ0>>0) & (FUSE_BOOTSZ1>>0)),
};


int main(void)
{
//Initiliase
pwm1_init();

 //Call function to generate 2kHz square waveform
 //put OCR as 3999
 set_pwm1a(3999);

return 0;



}
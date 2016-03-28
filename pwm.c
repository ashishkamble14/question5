/*
Name       : Ashish Kamble
File name  : pwm
Type       : SOurce file
*/


//---------------------------------------------------pwm.c------------------------------------------------//


//Header files
#include<avr/io.h>
#include<stdlib.h>
#include<compat/deprecated.h>
#include<util/delay.h>
#include<avr/eeprom.h>
#include<pwm.h>






//Function Definitions

//Function initialises TIMER1
void pwm1_init(void)
{
  DDRD |= (PIND4>>1);
  TCCR1B = 0x00; //stop
  TCNT1H = 0x00; //setup
  TCNT1L = 0x00;
  OCR1AH = 0x00;
  OCR1AL = 0x00;
  OCR1BH = 0x00;
  OCR1BL = 0x00;
  ICR1H  = 0x11;                    //Set the ICR Count to 4500 as our maximum count will be 3999 to generate 2Khz waveform
  ICR1L  = 0x94;                    //Hex equivalent of 4500 is 1194
  TCCR1A = 0xA2;
  TCCR1B = 0x19; //start Timer
}



//Function to set up the OCR value
void set_pwm1a(int a)
{
  OCR1A=a;
}
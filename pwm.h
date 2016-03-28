/*
Author    : Ashish Kamble
File name : pwm
Type      : Header file
*/

//------------------------------------------pwm.h-----------------------------------//



//Header Files
#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

//PWM1A

#define PWM1A_DIR  	REGISTER_BIT(DDRD,4)
#define PWM1A 		REGISTER_BIT(PORTD,4)
//PWM1B

#define PWM1B_DIR  	REGISTER_BIT(DDRD,5)
#define PWM1B 		REGISTER_BIT(PORTD,5)

//Functions prototypes
void pwm1_init(void);
void set_pwm1a(int a);


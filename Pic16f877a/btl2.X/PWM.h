#include "Config.h"
#define TMR2PRESCALE 4
long freq;

/*this function calculate the maximum duty cycle value when we had defined Fosc and Timer 2 prescaler
for this example, MaxDuty = 1000 if we choose the frequency of pulse equal 1khz*/
int PWM_Max_Duty();
/*this function init the frequency of pulse*/
void PWM1_Init_Fre(long fre);
void PWM2_Init_Fre(long fre);
/*duty value is as percent,its value is between 0 and 100 percent*/
void PWM1_Duty(unsigned int duty);
void PWM2_Duty(unsigned int duty);
/* this function allow PWM module run immediately*/
void PWM1_Start();
void PWM2_Start();
/*this function stop PWM module.*/
void PWM1_Stop();
void PWM2_Stop();
void PWM_DC(unsigned int duty);

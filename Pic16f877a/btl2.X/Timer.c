#include <xc.h>
#include "Timer.h"
#include<pic16f877a.h>

void TMR0_Unit(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    
    ei();
    //configure our timer
    TMR0=251; 
    OPTION_REGbits.T0CS=0;//internal instruction cycle clock
    OPTION_REGbits.T0SE=0;//edge selection
    OPTION_REGbits.PSA=0;//prescalar assigned to timero
    //select prescalar as 1:256
    OPTION_REGbits.PS0=1;
    OPTION_REGbits.PS1=1;
    OPTION_REGbits.PS2=1;
}
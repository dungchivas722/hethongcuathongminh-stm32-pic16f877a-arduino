/*
 * File:   Adc.c
 * Author: dungc
 *
 * Created on June 20, 2022, 5:46 PM
 */
#include "Adc.h"
#include <xc.h>
#include "Config.h"
#include <pic16f877a.h>
void ADC_Initialize(void)
{

  ADCON0 = 0b01000001; //ADC ON and Fosc/16 is selected

  ADCON1 = 0b11000000; // Internal reference voltage is selected

}


unsigned int ADC_Read(unsigned char channel)
{

  ADCON0 &= 0x11000101; //Clearing the Channel Selection Bits

  ADCON0 |= channel<<3; //Setting the required Bits

  __delay_ms(2); //Acquisition time to charge hold capacitor

  GO_nDONE = 1; //Initializes A/D Conversion

  while(GO_nDONE); //Wait for A/D Conversion to complete

  return ((ADRESH<<8)+ADRESL); //Returns Result

}
char Joystick(void){
    char c;

    int joy_X = (ADC_Read(0)); //Read the X-Axis of joystick

    int joy_Y = (ADC_Read(1)); //Read the Y-Axis of Joystick
    int x=0,y=0;

    

    if (joy_X < 200) 

    { x = 1;} 

    else if (joy_X > 800) 

    { x = 2;} 

    else 

    { x = 3;} 

        

  

    if (joy_Y < 200) 

    { y = 4;} 

    else if (joy_Y > 800) 

    { y = 5;}

    else 

    {y = 6;} 
    
    int dem = x*10 + y;
    
    if ( dem == 35 && dem == 15 && dem == 25 ) c = 'l'; 
    else if ( dem == 16 ) c='t';
    else if ( dem == 61 ) c='p';
    else c='x';
    
    return c;
}
#include "Config.h"
#include "Lcd.h"
#include "Timer.h"
#include <stdio.h>
#include <xc.h>
#include "Uart.h"
#include "PWM.h"
#include "Adc.h"
unsigned int x;
unsigned int minute,second,hour;
char s[10];
int count = 0;
unsigned int duty = 0;
void main(void) {
    
    TRISD = 0x00;
    UART_Init(9600);
    TMR0_Unit();
    TRISC=0X00; //PORT C is used as output ports
    PORTC=0X00; //MAke all pins low
    TRISB1=1; //RB0 is used as input
    ADC_Initialize(); //Configure the ADC module
    Lcd_Init();
    int x=0,y=0;
    int dem =0;
    int len=0,xuong=0,trai=0,phai=0,dongcua=1,mocua=0;
    char vitri;
    int tinhnang=1,trangthai=0,trangthaim1=1,trangthaim2=1,trangthaim3=0,trangthaim4=0;
    while (1){
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Chon->");
    int joy_X = (ADC_Read(0)); //Read the X-Axis of joystick

    int joy_Y = (ADC_Read(1)); //Read the Y-Axis of Joystick
    
    
    {
    if ((joy_X < 200) && (joy_Y < 200) ) //Joy moved up

    { len++;trai=0;phai=0;xuong=0;
    if ( len >0)
    {
        tinhnang--;
        __delay_ms(1000);
    }
    
    } //Glow upper LED

     if((joy_X > 800) && (joy_Y < 200) )//Joy moved down

    { len++;trai=0;phai=0;xuong=0;
         if ( len >0)
    {
        tinhnang--;
               __delay_ms(1000);
    }
     } //Glow Lower LED
    if ((joy_X <= 800 && joy_X >= 200 ) && (joy_Y < 200) )
     { len++;trai=0;phai=0;xuong=0; 
        if ( len >0)
    {
        tinhnang--;
               __delay_ms(1000);
    }
    }

    if ((joy_X < 200) && (joy_Y > 800) ) //Joy moved up

    { xuong++;len=0;trai=0;phai=0;
    if ( xuong>0)
    {
        tinhnang++;
               __delay_ms(1000);
    }
    } //Glow upper LED

     if((joy_X > 800) && (joy_Y >800) )//Joy moved down

      { xuong++;len=0;trai=0;phai=0;
    if ( xuong>0)
    {
        tinhnang++;
               __delay_ms(1000);
    }
    } //Glow upper LED
    if ((joy_X <= 800 && joy_X >= 200 ) && (joy_Y >800) )
      { xuong++;len=0;trai=0;phai=0;
    if ( xuong>0)
    {
        tinhnang++;
               __delay_ms(1000);
    }
    } //Glow upper LED
    
      if ((joy_X < 200) && (joy_Y <= 800) && (joy_Y >= 200) )

    { phai++;xuong=0;len=0;trai=0;} 

     if((joy_X > 800) && (joy_Y <= 800) && (joy_Y >= 200) )//Joy moved down

     {__delay_ms(1000);
     tinhnang=1;
     trangthai=0;
     xuong=0;
     len=0;
     trai=0;
     dongcua=1;
     mocua=0;
     trangthaim1=1;
     trangthaim2=1;
     trangthaim3=0;
     trangthaim4=0;
     UART_Write('r');
         __delay_ms(100);
     }
    }
    if (tinhnang==0) tinhnang=8;
    if (tinhnang==9) tinhnang=1;
    if (tinhnang == 1) {
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("DngCua");
    }
    else if (tinhnang == 2){
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("Mo Cua");
    }
    else if (tinhnang == 3){
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("Mode 1");
    }
    else if (tinhnang == 4){
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("Mode 2");
    }
    else if (tinhnang == 5){
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("Mode 3");
    }
    else if (tinhnang == 6){
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("AllOff");
    }
    else if (tinhnang == 7) {
        {
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("All On");
    }
    }
    else if (tinhnang == 8) {
        {
        Lcd_Set_Cursor(2,7);
        Lcd_Write_String("chu xe");
    }
    }
    Lcd_Set_Cursor(2,13);
    Lcd_Write_String(":");
    if (trangthai==0) {
    Lcd_Set_Cursor(2,14);
    Lcd_Write_String("   ");
    }
    if (trangthai==1) {
    Lcd_Set_Cursor(2,14);
    Lcd_Write_String("OK ");
    }
    if (trangthai==2) {
    Lcd_Set_Cursor(2,14);
    Lcd_Write_String("ON ");
    
    }
    if (trangthai==3) {
    Lcd_Set_Cursor(2,14);
    Lcd_Write_String("OFF");
    }
    if ( tinhnang == 3 && trangthaim1 ==0) {
        trangthai = 3;
    }
    else if ( tinhnang == 3 && trangthaim1 ==1) {
        trangthai = 2;
    }
    else if ( tinhnang == 4 && trangthaim2==0) {
        trangthai = 3;
    }
    else if ( tinhnang == 4 && trangthaim2==1) {
        trangthai = 2;
    }
    else if ( tinhnang == 5 && trangthaim3==0) {
        trangthai = 3;
    }
    else if ( tinhnang == 5 && trangthaim3==1) {
        trangthai = 2;
    }
        else if ( tinhnang == 8 && trangthaim4==0) {
        trangthai = 3;
    }
    else if ( tinhnang == 8 && trangthaim4==1) {
        trangthai = 2;
    }
    else if ( tinhnang == 1 && trangthai == 1)
    {
        __delay_ms(1000);    
        trangthai = 0;
    }
    else if ( tinhnang == 2 && trangthai == 1)
    {
        __delay_ms(1000);    
        trangthai = 0;
    }
    else if ( tinhnang == 6 && trangthai == 1)
    {
        __delay_ms(1000);    
        trangthai = 0;
    }
        else if ( tinhnang == 7 && trangthai == 1)
    {
        __delay_ms(1000);    
        trangthai = 0;
    }
    else trangthai=0;
    if ( mocua > 0 && dongcua == 0 ) {
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(" Dang Mo ");
    }
    if ( mocua == 0 && dongcua > 0 ) {
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Dang Dong");
    }
    if (trangthaim1==0)
    {
    Lcd_Set_Cursor(1,11);
    Lcd_Write_String(" ");
    }
    else 
    {
    Lcd_Set_Cursor(1,11);
    Lcd_Write_String("1");
    }
        if (trangthaim2==0)
    {
    Lcd_Set_Cursor(1,13);
    Lcd_Write_String(" ");
    }
    else 
    {
    Lcd_Set_Cursor(1,13);
    Lcd_Write_String("2");
    }
            if (trangthaim3==0)
    {
    Lcd_Set_Cursor(1,15);
    Lcd_Write_String(" ");
    }
    else 
    {
    Lcd_Set_Cursor(1,15);
    Lcd_Write_String("3");
    }
                if (trangthaim4==0)
    {
    Lcd_Set_Cursor(1,16);
    Lcd_Write_String(" ");
    }
    else 
    {
    Lcd_Set_Cursor(1,16);
    Lcd_Write_String("x");
    }
    if (phai>0 && tinhnang==1) {
        trangthai=1;
        mocua=0;
        dongcua++;
        phai=0;
        UART_Write('d');
        __delay_ms(1000);
    }
    if (phai>0 && tinhnang==2) {
        __delay_ms(1000);
        trangthai=1;
        dongcua=0;
        mocua++;
        phai=0;
        UART_Write('m');
         __delay_ms(1000);
    }
    if (phai >0 && tinhnang == 3 && trangthaim1==0) {trangthaim1=1;phai=0;__delay_ms(1000); UART_Write('x');
         __delay_ms(100);}
    if (phai >0 && tinhnang == 3 && trangthaim1==1) {trangthaim1=0;phai=0;__delay_ms(1000);UART_Write('z');
         __delay_ms(100);}
        if (phai >0 && tinhnang == 4 && trangthaim2==0) {trangthaim2=1;phai=0;__delay_ms(1000);UART_Write('c');
         __delay_ms(100);}
    if (phai >0 && tinhnang == 4 && trangthaim2==1) {trangthaim2=0;phai=0;__delay_ms(1000);UART_Write('v');
         __delay_ms(100);}
        if (phai >0 && tinhnang == 5 && trangthaim3==0) {trangthaim3=1;phai=0;__delay_ms(1000);UART_Write('b');
         __delay_ms(100);}
    if (phai >0 && tinhnang == 5 && trangthaim3==1) {trangthaim3=0;phai=0;__delay_ms(1000);UART_Write('n');
         __delay_ms(100);}
    if (phai>0 && tinhnang==6) {
        trangthaim1=0;
        trangthaim2=0;
        trangthaim3=0;
        trangthai=1;
        phai=0;
        UART_Write('a');
         __delay_ms(100);
    }
    if (phai>0 && tinhnang==7) {
        trangthaim1=1;
        trangthaim2=1;
        trangthaim3=1;
        trangthai=1;
        phai=0;
        UART_Write('s');
         __delay_ms(100);
    }
        if (phai >0 && tinhnang == 8 && trangthaim4==0) {trangthaim4=1;phai=0;__delay_ms(1000); 
        for (int i=1;i<5;i++)
        {UART_Write('p');
         __delay_ms(100);}}
    if (phai >0 && tinhnang == 8 && trangthaim4==1) {trangthaim4=0;phai=0;__delay_ms(1000); }
    
}
}
void __interrupt() ISR(void){
    if(INTCONbits.TMR0IF) //check flags
    {
      INTCONbits.TMR0IF=0; // clear flags
      count++;
      if (count==76) {
//             UART_Write('c');
          count=0;
      }
    }
}



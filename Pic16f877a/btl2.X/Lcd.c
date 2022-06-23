#include <xc.h>
#include "Lcd.h"
#include "Config.h"
#include <stdio.h>
#include <stdint.h>

void Lcd_Port(char a)
{
    RD1 = 0;
	if(a & 1)
		D4 = 1;
	else
		D4 = 0;

	if(a & 2)
		D5 = 1;
	else
		D5 = 0;

	if(a & 4)
		D6 = 1;
	else
		D6 = 0;

	if(a & 8)
		D7 = 1;
	else
		D7 = 0;
}
void Lcd_Cmd(char a)
{
	RS = 0;             // => RS = 0
	Lcd_Port(a);
	EN  = 1;             // => E = 1
        __delay_ms(4);
        EN  = 0;             // => E = 0
}

void Lcd_Clear()
{
	Lcd_Cmd(0);
	Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
}

void Lcd_Init()
{
  Lcd_Port(0x00);
   __delay_ms(20);
  Lcd_Cmd(0x03);
	__delay_ms(5);
  Lcd_Cmd(0x03);
	__delay_ms(11);
  Lcd_Cmd(0x03);
  /////////////////////////////////////////////////////
  Lcd_Cmd(0x02);
  Lcd_Cmd(0x02);
  Lcd_Cmd(0x08);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x0C);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x06);
}

void Lcd_Write_Char(char a)
{
   char temp,y;
   temp = a&0x0F;
   y = a&0xF0;
   RS = 1;             // => RS = 1
   Lcd_Port(y>>4);             //Data transfer
   EN = 1;
   __delay_us(40);
   EN = 0;
   Lcd_Port(temp);
   EN = 1;
   __delay_us(40);
   EN = 0;
}

void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	   Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right()
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x0C);
}

void Lcd_Shift_Left()
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x08);
}

void Lcd_Time(unsigned int minute,unsigned int second,unsigned int hour,char *s){
    while(1){
        sprintf(s,"%u",(hour/10));
        Lcd_Set_Cursor(2,5);
        Lcd_Write_String(s);
        sprintf(s,"%u",(hour%10));
        Lcd_Set_Cursor(2,6);
        Lcd_Write_String(s);
        Lcd_Write_String(":");
        sprintf(s,"%u",(minute/10));
        Lcd_Set_Cursor(2,8);
        Lcd_Write_String(s);
        sprintf(s,"%u",(minute%10));
        Lcd_Set_Cursor(2,9);
        Lcd_Write_String(s);
        Lcd_Write_String(":");
        sprintf(s,"%u",(second/10));
        Lcd_Set_Cursor(2,11);
        Lcd_Write_String(s);
        sprintf(s,"%u",(second%10));
        Lcd_Set_Cursor(2,12);
        Lcd_Write_String(s);
            second++;
            if(second==61)
            { 
            minute++;
            second=00;
            }
            if(minute==61)
            {
                hour++;
                minute=0;
            }
            if(hour==13)
            {
                hour=0;
            }
    }
}
//void Lcd_Time_Count(unsigned int minute,unsigned int second,unsigned int hour){
//            second++;
//            if(second==61)
//            { 
//            minute++;
//            second=00;
//            }
//            if(minute==61)
//            {
//                hour++;
//                minute=0;
//            }
//            if(hour==13)
//            {
//                hour=0;
//            }
//}
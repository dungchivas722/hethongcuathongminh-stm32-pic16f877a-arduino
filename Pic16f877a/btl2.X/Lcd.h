#include <xc.h>
#include <stdint.h>


#define RS RD0
#define EN RD2
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7


void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();
void Lcd_Clear();
void Lcd_Time(unsigned int minute,unsigned int second,unsigned int hour,char *s);
//void Lcd_Time_Count(unsigned int minute,unsigned int second,unsigned int hour);


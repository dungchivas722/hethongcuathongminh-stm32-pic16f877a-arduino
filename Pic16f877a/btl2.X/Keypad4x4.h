#include <xc.h>
#include "Config.h"
#define RowA		RB0
#define RowB		RB1
#define RowC		RB2
#define RowD		RB3
#define C1			RB4
#define C2			RB5
#define C3			RB6
#define C4			RB7
#define Keypad_PORT	 PORTB
#define Keypad_PORT_Dir	TRISB
void InitKeypad(void);
char READ_SWITCHES(void);
char GetKey(void);
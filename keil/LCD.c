#include <REGX51.H>


//Function Declarations

void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void datacmd(char);
void returnhome(void);

// Pin Description

/*
P2 is data bus
P1.0 is RS
P2.1 is E

*/

//Define Pins

sbit RS = P1^0;
sbit E = P1^1;

//Main Program

void main(void)
{
	cct_init();		//Make all port zero
	lcdinit();		//Init LCD
	
	writecmd(0x85);
	writedata('S');
	writedata('a');
	writedata('u');
	writedata('m');
	writedata('i');
	writedata('l');
	
	writecmd(0xc4);
	writedata('I');
	writedata('L');
	writedata('o');
	writedata('v');
	writedata('e');
	writedata('Y');
	writedata('o');
	writedata('u');
	
//	returnhome();		//Return to 0 position
	
//	while(1)
//	{
//  }

	break;
}

void cct_init(void)
{
	P0 = 0x00; 	//not used
	P1 = 0x00; 	//not used
	P2 = 0x00;	//used as data port
	P3 = 0x00;	//used for generating E and RS
}

void delay(int a)
{
	int i;
	for(i=0;i<a;i++);	//null statement
}

void writecmd(int x)
{
  RS=0;
	P2=x;
	E=1;
	delay(150);
	E=0;
	delay(150);
}

void writedata(char t)
{
  RS=1;
	P2=t;
	E=1;
	delay(150);
	E=0;
	delay(150);
}

void lcdinit(void)
{
	delay(15000);
	writecmd(0x30);	//Line 1
	delay(4500);
	writecmd(0x30);	//Line 1
	delay(300);
	writecmd(0x30);
	delay(600);
	
	writecmd(0x38);  //function set
	writecmd(0x0c);  //display on,  cursor off, blink off
	writecmd(0x01);  //clear display
	writecmd(0x06);  //entry mode set increment
}

void returnhome(void)
{
	writecmd(0x02);
	delay(500);
}
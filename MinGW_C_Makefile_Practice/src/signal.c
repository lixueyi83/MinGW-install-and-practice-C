#include <stdio.h>
#include <signal.h>
#include <conio.h>
#include <unistd.h>
#include "common.h"

/*
* SIGINT:
* Interrupt: The programhas been interrupted interactively, by the user pressing "Ctrl+C" or by some similar event
*/

void signal_handler(int s)
{
	if(SIGINT == s)
	{
		TRACE("*** Signal 'SIGINT' generated...\n");
	}
}
void keypress_trigger(void)
{
	if('g' == getch())  /*The program will stop to wait for the input character from keyboard.*/
	{
		TRACE("the input character is 'g'. ");
	}
	else
	{
		TRACE("the input character is not 'g'. ");
	}
}

void signal_trigger(void)
{
	static int counter = 0;
	
	puts( "Press Ctrl+C to interrupt me.");
	signal(SIGINT, signal_handler);	/*reinstall the signal_handler to capture the "Ctrl+C" key press that triggers the signal (SIGINT interrupt).*/
	
	if(++counter >= 5)	/*If user didn't type Ctrl+C in the last 5 seconds, then simulate a Ctrl+C key press.*/
	{
		raise(SIGINT);	/*Simulate a Ctrl+C in case the user didn't type it.*/
		counter = 0;
	}
}

void putsgets(void) 
{ 
	char name[10]; 
	printf("enter your name:"); 
	gets(name); 
	printf("your name is:"); 
	puts(name); 
	getch(); 
} 

void task_signal(void)
{
	debug_info();
	//loop1(putsgets);
	//loop1(signal_trigger);
}




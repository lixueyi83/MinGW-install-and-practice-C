#include <stdio.h>
#include <signal.h>
#include <conio.h>
#include <unistd.h>
#include "common.h"


/*Finite State Machine state numbers*/
#define MAX_STATES 	(5)

extern void dummy(), sm1(), sm2(), sm3();

/*
* delcare and initialize the array that holds the StateMachine function pointers
* typedef int (*SM[MAX_STATES])();
* SM StateMachine = {sm1, sm2, sm3};
*/
void (*state_handler[MAX_STATES])() = {sm1, NULL, sm2, NULL, sm3};

/*
* Compared to above declarations, statemachine id is added to latch the state machine handler.
* this form is frequently used, because sm_id is directly linked to the state machine handler.
*/
typedef struct
{
	char id;
	void (*pfun)(char group_id, char msg_id, char * p_msg, char len);
}SM_LIST;

/*Define a global variable that hold the value of current state of the state machine.*/
static int sm_id ATTR_UNUSED = 0x00;   /*This variable combined with the function pointer array can control the SM flows,
								but it shall be double confirmed for the state_machine_id's assignment.*/


/**************************StateMachine Handlers*********************************/
void dummy(void)
{
	DEBUG("%s \n", __func__);
}
void sm1(void)
{
	DEBUG("%s \n", __func__);
}

void sm2(void)
{
	DEBUG("%s \n", __func__);
}

void sm3(void)
{
	DEBUG("%s \n", __func__);
}

void goto_loop(void)
{
loop:
	puts("This is a goto loop.");
	delay_1s();
	goto loop;
}

void switch_sm(void)
{

	if((NULL != state_handler[sm_id]) && (sm_id < MAX_STATES))
	{
		state_handler[sm_id]();
	}
	
	switch(sm_id)
	{
		case 0:
			sm_id = 1;
			break;
			
		case 1:
			sm_id = 2;
			break;
			
		case 2:
			sm_id = 3;
			break;
			
		case 3:
			sm_id = 4;
			break;
			
		case 4:
			sm_id = 5;
			break;
			
		default:
			TRACE("unexpected state machine!");
			sm_id = 0;
			break;
	}
}

void poll_sm(void)
{
	for(int i = 0; i < MAX_STATES; i++)
	{
		if(NULL != state_handler[i])
		{
			state_handler[i]();	/*Same as invoking (*SM[i])();*/
		}
		else
		{
			TRACE("The corresponding handler is not exist.");
			/*The corresponding state machine is not implemented.*/
		}
	}
}
void task_StaMach(void)
{
	debug_info();
	//switch_sm();
}
#include <stdio.h>
#include "common.h"

#define TASK_TABLE_LIST	 \
{\
	{TASK_ARRAY, 		NULL},\
	{TASK_CAST, 		NULL},\
	{TASK_DEBUG, 		NULL},\
	{TASK_JUMP,		NULL},\
	{TASK_MATH, 		NULL},\
	{TASK_POINTER, 	NULL},\
	{TASK_SIGNAL, 	NULL},\
	{TASK_SIZEOF, 		NULL},\
	{TASK_STACK, 		NULL},\
	{TASK_STAMACH, 	NULL},\
	{TASK_TIME, 		task_time},\
	{TASK_TYPEDEF,	NULL},\
}

TASK_TABLE task_table[TASK_NUMBER] = TASK_TABLE_LIST;

void os_schedule(void)
{
	for(int i = 0; i < TASK_NUMBER; i++)
	{
		if(NULL != task_table[i].task_ptr)
		{
			task_table[i].task_ptr();
			delay_1s();
		}
	};
}

/**-------------------------------------------- 
* return value:
* arguments: 
*----------------------------------------------*/
int  main(int argc, const char *argv[])
{
	while(1)
	{
		//os_schedule();	
		task_time();
		delay_1s();
	}
	return 0;
}


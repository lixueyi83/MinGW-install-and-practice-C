#include <stdio.h>
#include "common.h"

void int_to_unsigned_int(void)
{
	unsigned int x = 200u;
	
	if(-1 < x)
	{
		TRACE("-1 < x: -1 is still int type.\n");
	}
	else
	{
		TRACE("-1 > x: -1 was implicitly cast into unsigned int type\n");
	}
}

void task_cast(void)
{
	debug_info();
	//int_to_unsigned_int();
}
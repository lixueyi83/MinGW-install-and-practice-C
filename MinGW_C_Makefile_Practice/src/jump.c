#include <stdio.h>
#include <setjmp.h>
#include "common.h"


jmp_buf buf;


/*-------------------------------------------------------------------
longjmp differs from a goto in that: 

1. A goto can't jump out of the current function in C (that's why this is a "longjmp"¡ª you can 
jump a long way away, even to a function in a different file). 

2. You can only longjmp back to somewhere you have already been, where you did a setjmp, 
and that still has a live activation record. In this respect, setjmp is more like a "come from" 
statement than a "go to". Longjmp takes an additional integer argument that is passed back, 
and lets you figure out whether you got here from longjmp or from carrying on from the 
previous statement.
---------------------------------------------------------------------*/


/*
*Here the example below only shows the longjmp jumps inside a function/file, actually it is frequently used among files
*/
void long_jump(void)
{
	switch(setjmp(buf))
	{ 
		case 0:
			DEBUG("***0:  longjmp to function %s of line %d.\n", __func__, __LINE__); 
			longjmp(buf, 1);
			break;
			
		case 1:
			DEBUG("***1:  longjmp to function %s of line %d.\n", __func__, __LINE__); 
			longjmp(buf, 2);
			break;

		case 2:
			DEBUG("***2:  longjmp to function %s of line %d.\n", __func__, __LINE__); 
			longjmp(buf, 3);
			break;
		case 3:
			DEBUG("***3:  longjmp to function %s of line %d.\n", __func__, __LINE__); 
			longjmp(buf, 4);
			break;
			
		default:
			DEBUG("***risk:  longjmp to function %s of line %d.\n", __func__, __LINE__); 
			break;
	}
}

void goto_within_function(void)
{
	DEBUG("*** enter %s\n", __func__);
	goto step3;
	
step1:
	TRACE("*** goto step1");
	goto exit;

step2:
	TRACE("*** goto step2");
	goto step1;

step3:
	TRACE("*** goto step3");
	goto step2;

exit:
	DEBUG("*** exit goto %s\n", __func__);
}


void task_jump(void)
{
	debug_info();
	//long_jump();
	//goto_within_function();
}



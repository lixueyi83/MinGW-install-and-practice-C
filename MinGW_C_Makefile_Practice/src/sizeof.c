#include <stdio.h>
#include "common.h"


#define MAX	(1)


void sizeof_argument(void)
{
	int* q = NULL;
	int x = 200;
	int s1, s2;
	
	q = &x;
	s1 = MAX * sizeof * q;		/* equals: s1 = MAX * sizeof(*q) = 1*4 = 4  */
	s2 = sizeof (int) * s1;	/* equals: size2 = sizeof(int) * s1 = 4*4=16, 0x10.  */
	
	debug_2_var(s1, s2);	
}

void task_sizeof(void)
{
	debug_info();
	//sizeof_argument();
}
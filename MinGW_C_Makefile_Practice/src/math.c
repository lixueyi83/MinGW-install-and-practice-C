#include <stdio.h>
#include "common.h"

#define NUM 100

int add(int a, int b)
{
	return (a+b);
}

int minus(int a, int b)
{
	return ((a>b)?(a-b):(b-a));
}

void calculator(void)
{
	unsigned int a[101];
	unsigned int i, j;
	a[0] = 1;
	
	for(i = 1; i <= NUM; i++)
		a[i] = 0;

	printf("\nInitial value:\n");
	
	for(i = 0; i <= NUM; i++)
	{
		if(i%10 == 0) 
			printf("\n");
		printf(" %d ", a[i]);
	}
	
	for(i = 1; i < NUM; i++)
	{
		for(j = i; j <= NUM; j++)
		{
			a[j] += a[j-i];
			//printf("%d %d\n ", j, j-i);
		}
	}
	
	printf("\n\nCalculated value:\n");
	
	for(i = 0; i <= NUM; i++)
	{
		if(i%10 == 0) 
			printf("\n");
		printf(" %-10d ", a[i]);
	}
}
void task_math(void)
{
	debug_info();
}
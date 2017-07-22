#include <stdio.h>
#include <stdlib.h>
#include "common.h"


int s[10] = {0,1,2,3,4,5,6,7,8,9};
char *str[] =  {"YafengVisteon", "MentorGraphics"};
int *m = NULL;
 
void stack_test(char x, char y, char z, int a, int b, int c)
{
	int t = 8;
	int *h = &t;
	int *s = &t;

	debug_var((int)&x);
	debug_var((int)&y);
	debug_var((int)&z);
	debug_var((int)&a);
	debug_var((int)&b);
	debug_var((int)&c);
	debug_var((int)&t);
	debug_var((int)&h);
	debug_var((int)&s);
}

void test(void)
{
	int i,j;
	int *p = NULL;

	i = 0xFF;
	j = 0xAA;
	p = malloc(sizeof(int));
	*p = i;
	debug_2_var(i, j);
}

void task_stack(void)
{
	debug_info(); 
	//test();
	//stack_test(0xfa,0xfa,0xfa,0xfa,0xfa,0xfa);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
 

void print_stairecase(void)
{
	int n;
	printf("please enter an number: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
			printf("-");
		
		for(int j = 0; j <= i; j++)
			printf("#");
			
			
		for(int j = 0; j <= i; j++)
			printf("#");
			
		for(int j = 0; j < n-i-1; j++)
			printf("-");
		
		printf("\n");
	}
}

void print_input_str(void)
{
	char str[20];
	//gets(str); /*can accept tab/enter/space keys*/
	scanf("%s", str); /*stop after tab/enter/space keys*/
	printf("%s", &str);
}

void my_macro(void)
{
	#ifdef MY_MACRO /*this macro is defined in compiler options*/
	printf("\n'MY_MACRO Defined'\n");
	#endif 
}

/*Interpret char as unsigned char using -funsigned-char option*/
void unsigned_to_signed(void)
{
	char c = -10;  
	
	printf("\n*** Hello, C Programming Language! ***\n");
	printf("c = %d\n", c);
}

/*this function shall be called in main by main_function_parameters(argc, argv); or 
	main_function_parameters(argc, &argv[0]); */
void main_function_parameters(int count, char *p[])
{
	while(count--)
	{
		printf("%s\n", *p++);
	}
}

void big_little_endian_union(void)
{
	union temp
	{
		int a;
		char b;
	}temp;
	
	temp.a = 0x11223344;
	
	if(temp.b == 0x11)
	{
		printf("big endian.\n");
	}
	else if(temp.b == 0x44)
	{
		printf("little endian.\n");
	}
	else
	{
		printf("endianess cannot decide.\n");
	}
}

void big_little_endian_union_char(void)
{
	union
	{
		char a[4];
		int b;
	}temp;
	
	temp.a[0] = 0x11;
	temp.a[1] = 0x22;
	temp.a[2] = 0x33;
	temp.a[3] = 0x44;

	printf("temp.b = 0x%x\n", temp.b);
	
	if(temp.b == 0x11223344)
	{
		printf("big endian.\n");
	}
	else if(temp.b == 0x44332211)
	{
		printf("little endian.\n");
	}
	else
	{
		printf("endianess cannot decide.\n");
	}
}

void big_little_endian_address(void)
{
	char a;
	unsigned int data;
	data = 0x11223344;
	a = data;
	
	printf("a = 0x%x\n", a);
		
	if(a == 0x11)
	{
		printf("big endian.\n");
	}
	else if(a == 0x44)
	{
		printf("little endian.\n");
	}
	else
	{
		printf("endianess cannot decide.\n");
	}
}

void big_little_endian_address_p(void)
{
	int data = 0x11223344;
	char i, * p;
	p = (char *)&data;
	
	for(i = 0; i < 4; i++)
		printf("%x", *(p+i));
	printf("\n");
		
	if(*p == 0x11)
	{
		printf("big endian.\n");
	}
	else if(*p == 0x44)
	{
		printf("little endian.\n");
	}
	else
	{
		printf("endianess cannot decide.\n");
	}
}

void task_endian(void)
{	
	big_little_endian_address_p();
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int u16;
typedef void (funcptr)(void);

unsigned int x, y, z;

#define var *((int*)(0x40da2c)) 

void test(void)
{
	var = 0x8976;
	printf("%x, %x, %x\n", (u16)&x, (u16)&y, (u16)&z);
	printf("%x, %x, %x\n", (u16)&var, (u16)var, (u16)&test);
}

int current_time(void)
{
  time_t now;
  time(&now);
 
  printf("%s", ctime(&now));
 
  return EXIT_SUCCESS;
}

void debug_info(void)
{
	printf("\n\n*** Hello, C Programming Language! ***\n");
	printf("----------------------------------------\n");
	printf("File Name: %s\n", __FILE__);
	printf("Function Name: %s\nLine Number: %d\n",__func__, __LINE__);
	
	current_time();
	
	printf("----------------------------------------\n");
}

int main(void)
{	
	funcptr p;
	void (*fptr)(void);
	
	(*(funcptr *)0x4013e0)();
	
	#if 1
	fptr = test;
	fptr();

	debug_info();
	*p = test;
	p();
	#endif
	return 0;
}


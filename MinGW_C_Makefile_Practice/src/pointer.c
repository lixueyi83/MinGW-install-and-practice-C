/*
How Array and Pointer ParametersAre Changed by the Compiler:
The "array name is rewritten as a pointer argument"rule isn't recursive. 
An array of arrays is rewritten as a "pointer to arrays" not as a "pointer to pointer". 

Argument(实参):  						Matches Formal Parameter(匹配的形式参数): 
array of array  char c[8][10];  		char (*c)[10];  pointer to array 
array of pointer  char *c[15];  		char **c;  pointer to pointer 
pointer to array  char (*c)[64];  		char (*c)[64];  doesn't change
pointer to pointer  char **c;  			char **c;  doesn't change

The reason you see char **argv is that argv is an array of pointers(i.e., char 
*argv[]). This decays into a pointer to the element, namely a pointer to a pointer. If the 
argv parameter were actually declared as an array of arrays (say, char argv[10][15])it would 
decay to char (* argv)[15] (i.e., a pointer to an array of characters) not char **argv.
*/

#include <stdio.h>
#include "common.h"

/**********************************************************************************
*	This file shows two ways of using pointer to function:
*	1st: define a type of pointer to function, use that type to define a var
*	2nd: get the entry address of function and then cast that address to 
*		pointer to function type
***********************************************************************************/

char* const *(*next)();	/*next is a pointer to a function returning a pointer to a read-only pointer-to-char*/
char *(*c[10])(int **p);	/*c is an array[0..9] of pointer to a function returning a pointer-to-char*/

/**---------------------------------------------------------------------- 
* When a pointer is delcared, the address of the pointer fixed, but the pointer's value may vary;
* int *p:  &p is the address that stores the pointer, p is pointer's value that stores the address of the variable it points to;
* If the content that a pointer points to is declared as const, as grape1 and grape2 below, then the content is read-only, 
* which means any contents that the pointer points to is read-only, supposing that pointer's value varies.
* If a pointer is declared as const, then the pointer's value is read-only, as grape3 below;
* If both the pointer and the content it points to are declared as const, then they are both read-only.
*-----------------------------------------------------------------------*/
void pointer_const(void)
{
	int var1 = 0x11;
	const int var2 = 0xFF;	/* int const t = 0xFF; variable t is read-only. */
	
	const int * grape1 = &var1;	/*the content that pointer grape points to is read-only, but the pointer may vary, meaning *grape1 varies*/
	int const * grape2 = &var1;	/*the content that pointer grape points to is read-only, but the pointer may vary, meaning *grape2 varies.*/
	int * const grape3 = &var1;	/*pointer grape is read-only, but the content it points to may vary, meaning *grape3 varies.*/

	//DEBUG3(&grape1, grape1, *grape1);
	grape1 = &var2;
	grape2 = &var2;
	*grape3 = var2;
	//*grape1 = var2;	/* error: assignment of read-only location '*grape1', the content is read-only. */
	//*grape2 = var2;	/* error: assignment of read-only location '*grape2', the content is read-only. */
	//grape3 = &var2;	/* error: assignment of read-only variable 'grape3'  */

	//DEBUG3(&grape1, &grape2, &grape3);
	debug_3_var(*grape1, *grape2, *grape3);
	//DEBUG3(&grape1, grape1, *grape1);
	
	const int * const grape_jam1 = &var1;	/*The pointer and the content it points to are both read-only*/
	int const * const grape_jam2 = &var1;	/*The pointer and the content it points to are both read-only*/

	//grape_jam1 = &var2;	/*  error: assignment of read-only variable 'grape_jam1' */
	//grape_jam2 = &var2;	/*  error: assignment of read-only variable 'grape_jam2' */
	//*grape_jam1 = var2;	/*  error: assignment of read-only variable 'grape_jam1' */
	//*grape_jam2 = var2;	/*  error: assignment of read-only variable 'grape_jam2' */
	
	//DEBUG2(&grape_jam1, &grape_jam2);
	debug_2_var(*grape_jam1, *grape_jam2);
}

/**-------------------------------------------- 
* return value: void 
* arguments: int 
*---------------------------------------------*/
void swap(int *x, int *y)
{
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}

/**-------------------------------------------- 
* return value: void 
* arguments: void 
*---------------------------------------------*/
void void_func_void(void)
{
	DEBUG("typedef void (*funcptr1)(void), %s\n", __func__);
}

/**-------------------------------------------- 
* return value: void 
* arguments: int 
*---------------------------------------------*/
void void_func_int(int *x, int *y)
{
	DEBUG("typedef void (*funcptr2)(int *x, int *y), %s\n", __func__);
	debug_2_var(*x,*y);
}

/**-------------------------------------------- 
* return value: int 
* arguments: int 
*----------------------------------------------*/
int int_func_int(int *x, int *y)
{
	DEBUG("typedef int (*funcptr3)(int *x, int *y), %s\n", __func__);
	debug_3_var(*x,*y,*x+*y);
	return (*x+*y);
}

/**-------------------------------------------- 
* return value:
* arguments: 
*----------------------------------------------*/
void function_ptr_study(void)
{
	int a ATTR_UNUSED, b ATTR_UNUSED;
	a=0x66;
	b=0x88;
	
	debug_info();
	
#ifdef INDIRECT_FUNCTION_PTR
	funcptr1 p1;
	funcptr2 p2;
	funcptr3 p3;
	
	p1 = void_func_void;
	p2 = void_func_int;
	p3 = int_func_int;
	
	debug_3_var((int)p1,(int)p2,(int)p3);
	
	p1();
	p2(&a,&b);
	p3(&a,&b);
	p2 = swap;
	p2(&a,&b);
#else
	debug_3_var((int)void_func_void,(int)void_func_int,(int)int_func_int);
	(*(funcptr1)void_func_void)();
	//(*(funcptr1)0x401698)();  /*This is confirmed working. Here suppose the address of void_func_void is 0x401698.*/
	(*(funcptr2)void_func_int)(&a,&b);
	(*(funcptr3)int_func_int)(&a,&b);
	(*(funcptr2)swap)(&a,&b);
#endif

	debug_2_var(a,b);	
}


/*
	&var   = 4235264(0x40A000)
	&p     = 2686736(0x28FF10)
	 p     = 4235264(0x40A000)
	&p[0]  = 4235264(0x40A000)
	&n     = 2686740(0x28FF14)
	 var   = 43981(0xABCD)
	 n     = 65535(0xFFFF)
*/
int var = 0xABCD;

void set_value(int *p, int n)
{
	debug_var(&var);
	debug_var(&p);
	debug_var(p);
	debug_var(&p[0]);
	debug_var(&n);
	debug_var(var);
	debug_var(n);
	
	*p = n;
}

/**-------------------------------------------- 
* return value:
* arguments: 
*----------------------------------------------*/
void task_pointer(void)
{
	debug_info();
	//pointer_const();
	//set_value(&var, 0xFFFF);
}

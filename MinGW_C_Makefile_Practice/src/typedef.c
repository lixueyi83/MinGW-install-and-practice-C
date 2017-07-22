#include <stdio.h>
#include "common.h"


/*typedef and #define when dealing with array.*/
#define array_macro int[10]
typedef int array_type[10];
array_type x;		/*x is an array containing 10 int type variables*/
//array_macro y;		/* This is not correct, array_macro is not a data type*/

typedef struct
{
	char s[9];
	int next;
}this;

void task_typedef(void)
{
	//this s;
	debug_info();
	//debug_2_var(sizeof(array_type), sizeof(array_macro));
	//debug_3_var(sizeof(s), sizeof(s.s),sizeof(s.next));	/* DEBUG3: sizeof(s) = 0x10, sizeof(s.s) = 0x9, sizeof(s.next) = 0x4, sizeof(struct type var) must be the multiple of the widest data type in the struct.*/
}
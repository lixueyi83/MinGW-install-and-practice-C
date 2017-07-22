#ifndef _COMMON_H_
#define _COMMON_H_

#ifndef NULL
#define NULL 	((void *)0)
#endif

#define ATTR_UNUSED		__attribute__ ((unused)) /*This attribute suppresses the warining -Wunused-but-set-variable*/
#define COMMON_EXTERN	extern

/************************* Standard I/O Macros *************************/
#define TRACE			puts				/*'\n' will be automatically added in the end of the string.*/
#define DEBUG			printf			/* equals: #define DEBUG printf */
/*Both Dec and Hex Format */
#ifdef DETAIL_DEBUG_INFO
#define debug_var(exp)			{printf("Debug: "); printf(#exp" = %d(0x%X),  Line:%d, Func:%s, File:%s\n", exp, exp, __LINE__, __func__, __FILE__);}
#define debug_2_var(exp1,exp2)		{printf("Debug: "); printf(#exp1" = %d(0x%X), "#exp2" = %d(0x%X),  Line:%d, Func:%s, File:%s\n", exp1, exp1, exp2, exp2, __LINE__, __func__, __FILE__);}
#define debug_3_var(exp1,exp2,exp3)	(printf("Debug: "), printf(#exp1" = %d(0x%X), "#exp2" = %d(0x%X), "#exp3" = %d(0x%X),  Line:%d, Func:%s, File:%s\n", exp1, exp1, exp2, exp2, exp3, exp3, __LINE__, __func__, __FILE__))
#else
#define debug_var(exp)			{printf(#exp" = %d(0x%X)\n", exp, exp);}
#define debug_2_var(exp1,exp2)		{printf(#exp1" = %d(0x%X), "#exp2" = %d(0x%X)\n", exp1, exp1, exp2, exp2);}
#define debug_3_var(exp1,exp2,exp3)	(printf(#exp1" = %d(0x%X), "#exp2" = %d(0x%X), "#exp3" = %d(0x%X)\n", exp1, exp1, exp2, exp2, exp3, exp3))	
#endif
//#define debug_str(exp) 			{printf("Debug: "); printf(#exp" = %s, Line:%d, Func:%s, File:%s\n", exp, __LINE__, __func__, __FILE__);}
#define debug_str(exp) 				{printf("Debug: "); printf(#exp" = %s\n", exp);}
#define debug_char(exp) 				{printf("Debug: "); printf(#exp" = %c\n", exp);}
/************************* debugging info*************************/
#define debug_info()	\
do{								\
	printf("-------- Function:%s  File:%s --------\n",__func__, __FILE__);	\
}while(0)

#define main_parameter_parse(argc, argv)	\
do{											\
	static int i = 0;			\
	DEBUG("NumberOfParameters: %d\n", argc);\
	TRACE("TheInputString: ");				\
	for(i=0; argv[i] != '\0'; i++)		\
	{									\
		DEBUG("%s\n", argv[i]);			\
	}									\
}while(0)


/************************* delay declarations*************************/
extern unsigned sleep( unsigned period );		/*defined in "unistd.h" file.*/
extern int usleep( unsigned period );		/*defined in "unistd.h" file.*/

#define delay_1s()		sleep(1)		/*sleep(n): sleep n seconds.*/
#define delay_500ms()	usleep(500000)  /*The usleep() function was obsolete and its continued use is not recommended. 
									There will be warnings if this function is invoked hereafter.*/		
#define loop1(func)		{while(1) func();}
#define loop2(func1, func2)	{while(1) {func1(); func2();}}

/************************* function pointers*************************/
typedef void (*funcptr1)(void); 
typedef void (*funcptr2)(int *x, int *y);
typedef int (*funcptr3)(int *x, int *y);

typedef struct
{
	unsigned char task_id;
	void (*task_ptr)(void);
}TASK_TABLE;

typedef enum
{
	TASK_ARRAY,
	TASK_CAST,
	TASK_DEBUG,
	TASK_JUMP,
	TASK_MATH,
	TASK_POINTER,
	TASK_SIGNAL,
	TASK_SIZEOF,
	TASK_STACK,
	TASK_STAMACH,
	TASK_TIME,
	TASK_TYPEDEF,
	TASK_NUMBER
}TASK_ID;

/************* Extern Functions ****************/
COMMON_EXTERN void task_array(void);
COMMON_EXTERN void task_cast(void);
COMMON_EXTERN void task_debug(void);
COMMON_EXTERN void task_jump(void);
COMMON_EXTERN void task_math(void);
COMMON_EXTERN void task_pointer(void);
COMMON_EXTERN void task_signal(void);
COMMON_EXTERN void task_sizeof(void);
COMMON_EXTERN void task_stack(void);
COMMON_EXTERN void task_StaMach(void);
COMMON_EXTERN void task_time(void);
COMMON_EXTERN void task_typedef(void);

#endif  /*End of this file*/

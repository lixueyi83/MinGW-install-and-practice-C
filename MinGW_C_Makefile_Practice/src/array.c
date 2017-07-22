#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//#define POINTER_ARRAY_FORMAT

#ifdef POINTER_ARRAY_FORMAT
const char *summary[8]=				/*the array holds 8 elements, each element hold a pointer pointing to an string.*/
#else
const char summary[][200]=			/*two-D array*/
#endif
{
	"Rich experience in embedded software design, programming, integration and debugging",
	"Good knowledge of audio infotainment product development and audio multimedia software architecture",
	"Familiar with automotive network software development (Volcano), including physical, network and diagnostic layers",
	"Proficient in vehicle communication specifications like CAN/LIN, SPI, IIC, SCI and Vector CANoe, CANalyzer tools",
	"Good knowledge of Makefile and batch file programming, familiar with GNU make",
	"Excellent written and verbal communication skills, maintain good relationship between internal and external customers",
	"High sense of dedication, cooperation and responsibility, willing to work under high pressure",
	"Quick learning ability and flexibility, ready to take on new responsibilities and challenges",
};

char ga[] = "abcdefghijklm"; 

void apricot_pointer(void)
{
	int apricot[2][3][5];
	typedef int (*P1)[2][3][5];
	typedef int (*P2)[3][5];
	typedef int (*P3)[5];
	
	P1 p = (P1)apricot;
	P2 r = (P2)apricot[0];
	P3 t = (P3)apricot[0][0];

	/* &apricot = 2686572(0x28FE6C), &apricot[0] = 2686572(0x28FE6C), &apricot[0][0] = 2686572(0x28FE6C)*/
	debug_3_var(&apricot, &apricot[0], &apricot[0][0]);	
	/* &apricot+1 = 2686692(0x28FEE4), &apricot[0]+1 = 2686632(0x28FEA8), &apricot[0][0]+1 = 2686592(0x28FE80)*/
	debug_3_var(&apricot+1, &apricot[0]+1, &apricot[0][0]+1);	
	
	debug_3_var(p, r, t);	/* p = 2686572(0x28FE6C), r = 2686572(0x28FE6C), t = 2686572(0x28FE6C)*/
	debug_3_var(p+1, r+1, t+1);	/*p+1 = 2686632(0x28FEA8), r+1 = 2686592(0x28FE80), t+1 = 2686576(0x28FE70)*/
}

void print_summary(const char (*p)[200], char *a/*char a[]*/)
{
	for(int i = 0; i < sizeof(char)*8; i++)
	{
		#ifdef POINTER_ARRAY_FORMAT
		debug_str(summary[i]);
		#else
		debug_str(&p[i]);
		#endif
	}
	
	debug_str(a);
}

void print_item(void)
{
	int *t;
	char *s;
	typedef int (*P1)[200];
	
	#ifdef POINTER_ARRAY_FORMAT
	debug_str(summary[0]+1);
	debug_char(summary[0]+1);
	#else
	debug_str(&summary[0]+1);
	debug_char(summary[0][2]);
	
	P1 p = (P1)summary;
	t = (int *)summary;
	s = (char *)summary;
	
	debug_3_var(p, t, s);
	debug_3_var(p+1, t+1, s+1);
	
	debug_str(p);
	debug_str(p+1);

	debug_str(t);
	debug_str(t+1);

	debug_str(s);
	debug_str(s+1);
	#endif 
}

void my_array_func(char ca[10]) 
{ 
	printf(" addr of array param = %#x \n",&ca); 
	printf(" addr (ca[0]) = %#x \n",&(ca[0])); 
	printf(" addr (ca[1]) = %#x \n",&(ca[1])); 
	printf(" ++ca = %#x \n\n", ++ca); 
} 
void my_pointer_func( char *pa ) 
{ 
	printf(" addr of ptr param = %#x \n",&pa); 
	printf(" addr (pa[0]) = %#x \n",&(pa[0])); 
	printf(" addr (pa[1]) = %#x \n",&(pa[1])); 
	printf(" ++pa = %#x \n", ++pa); 
} 
void Expert_Arrary(void) 
{ 
	printf(" addr of global array = %#x \n",&ga); 
	printf(" addr (ga[0]) = %#x \n",&(ga[0])); 
	printf(" addr (ga[1]) = %#x \n\n",&(ga[1])); 
	my_array_func( ga ); 
	my_pointer_func( ga ); 
}

void task_array(void)
{
	debug_info();
	//print_item();
	//print_summary(summary, ga);
	//apricot_pointer();
	//Expert_Arrary();
}

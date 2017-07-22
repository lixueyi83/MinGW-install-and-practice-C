#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "common.h"
#include "signal.h"

struct timeval tv, tv_begin, tv_end;
unsigned int start_time;

/**-------------------------------------------- 
* return value:
* arguments: 
*----------------------------------------------*/
int current_time(void)
{
	time_t now;
	time(&now);
	DEBUG("%s", ctime(&now));
	return EXIT_SUCCESS;
}

unsigned int sec(void)
{
	gettimeofday(&tv, NULL);
	return (tv.tv_sec % 60);
}
unsigned int msec(void)
{
	gettimeofday(&tv, NULL);
	return (tv.tv_usec/1000);
}
unsigned int usec(void)
{
	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}
void busy_wait(void)
{
   unsigned int  tnow;
   unsigned int  elapsed;

    do
    {
        tnow = msec();
        elapsed = (unsigned int)(tnow - start_time);
    } while (elapsed < 2000);

    start_time += 2000;
}
void task_time(void)
{
	gettimeofday(&tv_begin, NULL);
	debug_info();
	//loop1(current_time);
	delay_1s();
	gettimeofday(&tv_end, NULL);

	debug_var(tv_begin.tv_sec);
	debug_var(tv_begin.tv_usec);
	//busy_wait();
}

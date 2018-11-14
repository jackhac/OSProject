#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

#include "semaphore.h"

/* the semaphore */

void wait(semaphore *S)
{
	S->value--;
	if (S->value < 0)
	{
		//ADD PROCESS TO s->list
		//block();
	}
}

void signal(semaphore *S)
{
	S->value++;
	if (S->value <= 0)
	{
		//remove a process P from S->list;
		//wakeup(P);
	}
}
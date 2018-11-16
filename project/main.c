#include <stdlib.h> /* required for rand() */
#include <stdio.h>
#include <pthread.h>

#include "buffer.h"
#include "threads.h"

void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */

void initializeData();
void sleep(int a);

int main(int argc, char *argv[]) 
{
	int i;
	
	pthread_t tid;       //Thread ID
	//pthread_attr_t attr; //Set of thread attributes
	
	// 1. Get command line arguments  argv[1],argv[2],argv[3]
	int mainSleepTime = atoi(argv[1]); 
    int numProd = atoi(argv[2]); 
    int numCons = atoi(argv[3]); 
	
	// 2. Initialize buffer 
	initializeData();
	
	//3. Create producer thread(s) 
	for(i = 0; i < numProd; i++) 
	{
      pthread_create(&tid,NULL,producer,NULL);
    }
	
	// 4. Create consumer thread(s) 
	for(i = 0; i < numCons; i++) 
	{
      pthread_create(&tid,NULL,consumer,NULL);
    }
	
	// 5. Sleep 
	sleep(mainSleepTime);
	
	// 6. Exit 
	printf("Exit the program\n");
   	exit(0);
}
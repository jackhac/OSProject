#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "buffer.h"
#include "threads.h"

void *producer(void *param);
void *consumer(void *param);

void initializeData();
void sleep(int a);

int main(int argc, char *argv[]) 
{
	//initialize variables
	int sleepTime; 
    int producerNum; 
    int consumerNum;
	pthread_t thread_id;
	int i;
	
	if (argc!=4)
	{
		fprintf(stderr, "usage: project int1 int2 int3\n");
		return 1; 
	}
	
	//get command line arguments  argv[1],argv[2],argv[3]
	sleepTime = atoi(argv[1]); 
    producerNum = atoi(argv[2]); 
    consumerNum = atoi(argv[3]); 
	
	//initialize buffer 
	initializeData();
	
	//create producer threads
	for(i = 0; i < producerNum; i++) 
	{
      pthread_create(&thread_id,NULL,producer,NULL);
    }
	
	//create consumer threads 
	for(i = 0; i < consumerNum; i++) 
	{
      pthread_create(&thread_id,NULL,consumer,NULL);
    }
	
	//sleep 
	sleep(sleepTime);
	
	//exit 
	printf("Exit the program\n");
   	exit(0);
}
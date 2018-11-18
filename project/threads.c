#include <stdlib.h> 
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#include "buffer.h"
#include "threads.h"

int insert_item(buffer_item item);
int remove_item(buffer_item *item);
void sleep(int a);

//mutux lock
pthread_mutex_t mutex;

//semaphores
sem_t full, empty;

//producer thread
void *producer(void *param) 
{
   buffer_item item;

   while(true) 
   {
      //sleep for a random period of time
      //set it for between 1-6
      sleep(rand() % 6);

      //generate random num
      item = rand();

      //wait(empty)
      sem_wait(&empty);
      //lock mutex
      pthread_mutex_lock(&mutex);
	  //insert item into buffer or throw error
      if(insert_item(item)) 
	  {
         fprintf(stderr, "Producer report error condition\n");
      }
      else 
	  {
         printf("producer produced %d\n", item);
      }
      //unlock mutex
      pthread_mutex_unlock(&mutex);
      //signal(full)
      sem_post(&full);
   }
}

//consumer thread
void *consumer(void *param) 
{
   buffer_item item;

   while(true) 
   {
      //sleep for a random period of time
      //set it for between 1-6
      sleep(rand() % 6);

      //wait(full)
      sem_wait(&full);
      //mutex lock
      pthread_mutex_lock(&mutex);
      if(remove_item(&item)) 
	  {
         fprintf(stderr, "Consumer report error condition\n");
      }
      else 
	  {
         printf("consumer consumed %d\n", item);
      }
      //unlock mutex
      pthread_mutex_unlock(&mutex);
      //signal empty
      sem_post(&empty);
   }
}

//initialze sephmores and mutex
void initializeData() 
{
   //create the mutex lock
   pthread_mutex_init(&mutex, NULL);

   //create the full semaphore and initialize to 0
   sem_init(&full, 0, 0);

   //create the empty semaphore and initialize to BUFFER_SIZE
   sem_init(&empty, 0, BUFFER_SIZE);
}
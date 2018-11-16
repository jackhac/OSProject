#include <stdlib.h> /* required for rand() */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "buffer.h"
#include "threads.h"

int insert_item(buffer_item item);
int remove_item(buffer_item *item);

void sleep(int a);

/* The mutex lock */
pthread_mutex_t mutex;

/* the semaphores */
sem_t full, empty;

/* Producer Thread */
void *producer(void *param) 
{
   buffer_item item;

   while(true) 
   {
      /* sleep for a random period of time */
      int rNum = rand() % 6;
      sleep(rNum);

      /* generate a random number */
      item = rand();

      /* acquire the empty lock */
      sem_wait(&empty);
      /* acquire the mutex lock */
      pthread_mutex_lock(&mutex);

      if(insert_item(item)) {
         fprintf(stderr, " Producer report error condition\n");
      }
      else {
         printf("producer produced %d\n", item);
      }
      /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal full */
      sem_post(&full);
   }
}

/* Consumer Thread */
void *consumer(void *param) 
{
   buffer_item item;

   while(true) 
   {
      /* sleep for a random period of time */
      int rNum = rand() % 6;
      sleep(rNum);

      /* aquire the full lock */
      sem_wait(&full);
      /* aquire the mutex lock */
      pthread_mutex_lock(&mutex);
      if(remove_item(&item)) {
         fprintf(stderr, "Consumer report error condition\n");
      }
      else {
         printf("consumer consumed %d\n", item);
      }
      /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal empty */
      sem_post(&empty);
   }
}


void initializeData() 
{

   /* Create the mutex lock */
   pthread_mutex_init(&mutex, NULL);

   /* Create the full semaphore and initialize to 0 */
   sem_init(&full, 0, 0);

   /* Create the empty semaphore and initialize to BUFFER_SIZE */
   sem_init(&empty, 0, BUFFER_SIZE);

   /* Get the default attributes */
  // pthread_attr_init(&attr);

   /* init buffer */
  // counter = 0;
}
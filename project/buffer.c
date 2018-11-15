#include <semaphore.h>
#include <pthread.h> 

#include "buffer.h"

/* the buffer */
buffer_item buffer[BUFFER_SIZE];

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

int in = 0;
int out =0;

int insert_item(buffer_item item) 
{
	/* insert item into buffer
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	
	buffer_item next_produced;
	
	do
	{
		/*produce an item in next_produced */
		
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		
		/*add next_produced to the buffer */
		while (((in + 1) % BUFFER_SIZE) == out)
		{
			
		}
		buffer[in] = next_produced;
		in = (in + 1) % BUFFER_SIZE;
		
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
		
	}while (0==0);
	
	return 0;
}
int remove_item(buffer_item *item) 
{
	/* remove an object from buffer
	placing it in item
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	
	buffer_item next_consumed;
	
	do
	{
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		
		/*remove an item from the buffer to next_consumed */
		
		while (in == out)
		{
			
		}
		next_consumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		
		/*consume the item in next_consumed */
	}while (0==0);
	
	return 0;
}

int initialize_buffer()
{
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	pthread_mutex_init(&mutex, NULL);
}
#include "buffer.h"
#include "semaphore.h"
#include <pthread.h> 

/* the buffer */
buffer_item buffer[BUFFER_SIZE];

int n;
semaphore empty;
semaphore full;

//replace with mutex lock
semaphore mutex;

int insert_item(buffer_item item) 
{
	/* insert item into buffer
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	
	do
	{
		/*produce an item in next_produced */
		
		wait(empty);
		wait(mutex);
		
		/*add next_produced to the buffer */
		
		signal(mutex);
		signal(empty);
		
	}while (0==0);
	
	return 0;
}
int remove_item(buffer_item *item) 
{
	/* remove an object from buffer
	placing it in item
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	
	do
	{
		wait(full);
		wait(mutex);
		
		/*remove an item from the buffer to next_consumed */
		
		signal(mutex);
		signal(empty);
		
		/*consume the item in next_consumed */
	}while (0==0);
	
	return 0;
}

int initialize(buffer_item *item)
{
	return 0;
}
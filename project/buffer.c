#include "buffer.h"

/* the buffer */
buffer_item buffer[BUFFER_SIZE];

int counter=0;

/* Add an item to the buffer */
int insert_item(buffer_item item) 
{
   /* When the buffer is not full add the item
      and increment the counter*/
   if(counter < BUFFER_SIZE) 
   {
      buffer[counter] = item;
      counter++;
      return 0;
   }
   else 
   { 
	  /* Error the buffer is full */
      return -1;
   }
}

/* Remove an item from the buffer */
int remove_item(buffer_item *item) 
{
   /* When the buffer is not empty remove the item
      and decrement the counter */
   if(counter > 0) 
   {
      *item = buffer[(counter-1)];
      counter--;
      return 0;
   }
   else 
   { 
	  /* Error buffer empty */
      return -1;
   }
}
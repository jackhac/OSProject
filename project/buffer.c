#include "buffer.h"

//the buffer
buffer_item buffer[BUFFER_SIZE];

int counter=0;

//insert item into buffer
int insert_item(buffer_item item) 
{
   //when buffer isnt full then add item to counter and increment counter
	//if not return error
   if(counter < BUFFER_SIZE) 
   {
      buffer[counter] = item;
      counter++;
      return 0;
   }
   else 
   { 
      return -1;
   }
}

//remove item from buffer
int remove_item(buffer_item *item) 
{
   //when buffer isnt empty then delete item from buffer and decrement counter
	//if not return error
   if(counter > 0) 
   {
      *item = buffer[(counter-1)];
      counter--;
      return 0;
   }
   else 
   { 
      return -1;
   }
}
#include <stdlib.h> /* required for rand() */
#include <stdio.h>
#include "buffer.h"

int insert_item(buffer_item item);
int remove_item(buffer_item *item);

void *producer(void *param) 
{
   buffer_item item;
   while (0==0) 
   {
      /* sleep for a random period of time */
      //sleep(rand());
      /* generate a random number */
      item = rand();
      if (insert_item(item))
         fprintf(stderr, "report error condition");
      else
         printf("producer produced %d\n",item);
   }
}
void *consumer(void *param) 
{
   buffer_item item;
   while (0==0) 
   {
      /* sleep for a random period of time */
      //sleep(rand());
      if (remove_item(&item))
         fprintf(stderr, "report error condition");
      else
         printf("consumer consumed %d\n",item);
   }
}
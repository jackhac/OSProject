/* semaphore.h */
typedef struct
{
	int value;
	struct process *list;
}semaphore;

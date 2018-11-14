#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

#include "buffer.h"

int main(int argc, char *argv[]) 
{
	//initialize variables
	int args[3];
	
	if (argc!=4)
	{
		fprintf(stderr, "Ex: usage: project int1 int2 int3\n");
		return 1; 
	}
	//1. Get command line arguments  argv[1],argv[2],argv[3]
	args[0]=atoi(argv[1]);
	args[1]=atoi(argv[2]);
	args[2]=atoi(argv[3]);
	
	//2. Initialize buffer 
	
	
	
	//3. Create producer thread(s) 
	
	
	
	//4. Create consumer thread(s) 
	
	
	
	//5. Sleep 
	sleep(args[2]);
	
	
	//6. Exit 
	return 0;
	
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_SLEEP 50

// TODO: program description here

int main(int argc, char *argv[])
{
	// Declare variables
	int sleep_time, op1, op2, child_num;
	
	// Validate arg amount
	if(argc != 4) 
	{
		printf("\nERROR: Incorrect number of arguments.\nUsage: %s [sleep-time] [integer-operand-1] [integer-operand-2]\n\n", argv[0]);
		exit(1);		
	}
	
	// Cast args as integers (will evaluate to zero if no valid conversion can be performed)
	sleep_time = atoi(argv[1]);
	op1 = atoi(argv[2]);
	op2 = atoi(argv[3]);

	// Validate arg content
	if(sleep_time < 0 || sleep_time > MAX_SLEEP) 
	{
		printf("\nUsage: %s [sleep-time] [integer-operand-1] [integer-operand-2]\n[sleep-time] must be a positve integer less than or equal to %d\n\n", argv[0], MAX_SLEEP);
		exit(1);		
	}

	// Initialize Random Number Generator (using time as seed)
	srand((int) time(NULL));
	
	// Randomizing sleep time
	sleep_time = rand() % sleep_time;
	
	// Print out the parent info
	printf("\nI am the parent process, the maximum sleep time is %d and the two numbers are %d and %d\n", MAX_SLEEP, op1, op2);
    
	// Sleep for randomized sleep_time
	sleep(sleep_time);

	/* TODO: execute 4 x child processes (project2-child.c) passing child_num, sleep_time, op1 & op2 */
	for (child_num = 0; child_num < 4; child_num++) {
		// fork() to create new process and exec to run project2-child.c, passing child_argv as arguments to child process
		// child_argv[] = {"project2-child", i, sleep_time, op1, op2}
		if(fork() == 0) {
			static char *child_argv[] = {"project2-child", op1, op2, child_num, sleep_time, (char *) 0};	
			printf("Forked child %ld", (long)getpid());
			execvp("project2-child", child_argv);
		}
	}

//end main
}

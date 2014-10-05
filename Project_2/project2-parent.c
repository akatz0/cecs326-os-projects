#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_SLEEP 50

// TODO: program description here

int main(int argc, char *argv[])
{
	// Declare variables
	int sleep_time, op1, op2;
	static char *child_argv[] = {"lab1", "5", (char *) 0};
	
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
	for (int i = 0; i < 4; i++) {
		// fork() to create new process and exec to run project2-child.c, passing child_argv as arguments to child process
		// child_argv[] = {"project2-child", i, sleep_time, op1, op2}
	}


	/*
	CODE BELOW IS FROM PROJECT_1
	//generate binary process tree
	while(current_level < max_level)
	{	
		//If child, gather parent id, iterate, then continue
		if((lchildpid = fork()) == 0 || (rchildpid = fork()) == 0) {
			parentpid = getppid();
			current_level++;
			continue;
		}
		
		//check for forking errors
		if(lchildpid == -1 || rchildpid == -1) 
		{
			perror("\n The fork failed\n");
			exit(1);
		}
		
		//If current fork has two children, print complete generation to console and exit while loop
		if(lchildpid && rchildpid){
			printf("%d\t%ld\t%ld\t%ld\t%ld\n", current_level, (long)getpid(), (long)getppid(), (long)lchildpid, (long)rchildpid);
			break;
		}	
	}
	//wait for children to end to ensure valid getppid() calls
	waitpid(lchildpid, &status_ptr, 0);
   	waitpid(rchildpid, &status_ptr, 0);
	exit(0);
	*/

//end main
}

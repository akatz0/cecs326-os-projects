#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// TODO: Add description of project2-child.c main() here

int main(int argc, char *argv[])
{
	// Declare variables
	int child_num, sleep_time, op1, op2;
	
	// Validate arg amount
	if(argc != 5) 
	{
		printf("\nERROR: Incorrect number of arguments\nUsage: %s [child-num] [sleep-time] [integer-operand-1] [integer-operand-2]\n\n", argv[0]);
		exit(1);		
	}
	
	// Cast args to integer	
	child_num = atoi(argv[1]);
	sleep_time = atoi(argv[2]);
	op1 = atoi(argv[3]);
	op2 = atoi(argv[4]);

	// Child sleeps for random sleep_time
	sleep(sleep_time);

	/* TODO: handle arithmatic operation based on child_num (switch statement) */
	
//end main
}

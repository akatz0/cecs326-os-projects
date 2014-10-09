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
	op1 = atoi(argv[1]);
	op2 = atoi(argv[2]);
	child_num = atoi(argv[3]);
	sleep_time = atoi(argv[4]);

	// Initialize Random Number Generator (using time as seed)
	// srand((int) time(NULL));
	
	// Randomizing sleep time
	sleep_time = rand() % sleep_time;

	// Child sleeps for random sleep_time
	sleep(sleep_time);

	/* TODO: handle arithmatic operation based on child_num (switch statement) */
	switch(child_num) {
		case 0:
			printf("I am child number %i with PID %ld, the sum is %i", child_num, (long)getpid(), op1 + op2);
		case 1:
			printf("I am child number %i with PID %ld, the difference is %i", child_num, (long)getpid(), op1 - op2);
		case 2:
			printf("I am child number %i with PID %ld, the quotient is %i with a remainder of %i", child_num, (long)getpid(), op1 / op2, op1 % op2);
		case 3:
			printf("I am child number %i with PID %ld, the product is %i", child_num, (long)getpid(), op1 * op2);
	}
	
//end main
}

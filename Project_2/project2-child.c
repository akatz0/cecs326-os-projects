#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* 
* PROGRAM: Project2-child.c
* 
* Sleeps for a random time (maximum sleep time being command line argument 1), 
* then prints a statement based on the child number (argv[4]) which includes
* the child number, it's PID, and an arithmatic operation based on child number.
*
* child number 0: operand 1 (argv[2]) + operand 2 (argv[3]) = sum
* child number 1: operand 1 (argv[2]) - operand 2 (argv[3]) = difference
* child number 2: operand 1 (argv[2]) * operand 2 (argv[3]) = product
* child number 3: operand 1 (argv[2]) / operand 2 (argv[3]) = quotient 
*		& operand 1 (argv[2]) % operand 2 (argv[3]) = remainder
*
*
*/
int main(int argc, char *argv[])
{
	// Declare variables
	int child_num, sleep_time, op1, op2;

	// Validate arg amount
	if(argc != 5) 
	{
		printf("\nERROR: Incorrect number of arguments\nUsage: %s [sleep-time] [integer-operand-1] [integer-operand-2] [child-num]\n\n", argv[0]);
		exit(1);		
	}
	
	// Cast args to integer	
	sleep_time = atoi(argv[1]);
	op1 = atoi(argv[2]);
	op2 = atoi(argv[3]);
	child_num = atoi(argv[4]);
	
	// Initialize Random Number Generator (using pid as seed)
	srand(getpid());
	
	// Randomizing sleep time
	sleep_time = rand() % sleep_time;

	// Child sleeps for random sleep_time
	sleep(sleep_time);

	/* Print out the child number, PID and it's associated arithmatic operation */
	switch(child_num) {
		case 0:
			printf("I am child number %i with PID %ld, the sum is %i\n", child_num, (long)getpid(), op1 + op2);
			break;
		case 1:
			printf("I am child number %i with PID %ld, the difference is %i\n", child_num, (long)getpid(), op1 - op2);
			break;
		case 2:
			// Handle divide by zero error
			if(op2 != 0) {
				printf("I am child number %i with PID %ld, the quotient is %i with a remainder of %i\n", child_num, (long)getpid(), op1 / op2, op1 % op2);
			} else {
				printf("ERROR: Cannot divide by 0\n");
			}
			break;
		case 3:
			printf("I am child number %i with PID %ld, the product is %i\n", child_num, (long)getpid(), op1 * op2);
			break;
	}	
//end main
}

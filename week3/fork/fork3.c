/*
Example: C program to differentiate a parent process from a child process after a fork
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void forkexample()
{
	int x = 313; // Variable
	int child_status;

	if (fork() == 0)
		printf("Child has x = %d\n", ++x); // Child Increments x
	else{
		//wait(&child_status);
		printf("Parent has x = %d\n", --x); // Parent Decrements x
		}
}
int main()
{
	forkexample();
	return 0;
}
/* answers

child has: 314
parent has: 313

child has: 314
parent has:312


*/


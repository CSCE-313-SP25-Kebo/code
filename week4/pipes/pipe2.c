/*
Example: fork() and pipe()
The parent process writes to the child process.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int pipefds[2]; // Array of file descriptor
	pid_t pid; // Process ID

	char buf[30]; // Some text

	//create pipe
	if(pipe(pipefds)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	memset(buf,0,30);

	pid = fork(); // Create one child process - system call
	/*
	What are the return values of the fork() function

	0: in the context of the child
	pid>0: in the context of the parent and pid is the process ID of the child
	pid<0: failure
	*/
 
    // If PID is strictly positive - the value is the process ID of the child process
	if(pid>0){
		printf("PARENT: write in pipe.\n");
		printf("PARENT: write in pipe, to %d\n", pid);
		 //parent close the read end
		close(pipefds[0]);
		//parent write in the pipe write end
		write(pipefds[1],"CSCE3150",9);
		//after finishing writing, parent close the write end
		close(pipefds[1]); // Solution
		//parent wait for child
		wait(NULL); // Wait for the child process to read the string.
	}
	else{
		// Close the write end on the child - Close the unused end of the pipe
		close(pipefds[1]); 
		//child read from the pipe read end until the pipe is empty!
		// Read 1 byte at a time from the pipe
		while(read(pipefds[0],buf,1)==1){
			printf("CHILD read from pipe --%s\n",buf);
		}
		//after finishing reading, child close the read end
		close(pipefds[0]);
		printf("CHILD: EXITING!\n");
		exit(EXIT_SUCCESS);

	}
	return 0;
}

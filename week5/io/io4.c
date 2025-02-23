// C program to illustrate
// I/O system Calls
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main (void)
{
	int fd[2];
	char buf1[12] = "hello world";
	char buf2[12];

	// assume foobar.txt is already created
	fd[0] = open("foobar.txt", O_RDWR);	// fp is at the zero position
	fd[1] = open("foobar.txt", O_RDWR); // fp is at the zero position
	
	write(fd[0], buf1, strlen(buf1));		
	write(1, buf2, read(fd[1], buf2, 12)); // Print the final file content to the STDOUT

	close(fd[0]);
	close(fd[1]);

	return 0;
}

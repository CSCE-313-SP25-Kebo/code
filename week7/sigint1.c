/*
Example: Signal handler for CTRL-C using the signal()* function
*/

#include "apue.h"

// Handler  to perform an operation if CTRL-C*/
void sighandler(int signum)
{
    printf("\nSignal caught for a CTRL C!\n");
}

int main()
{
    // Option 1: Handle the signal
    // Define what to do when a signal is received - sighandler is the disposition when CTRL-C is received.
    signal(SIGINT, sighandler); // VERSION 1
    //signal(SIGCONT, sighandler); // VERSION 1
    //signal(SIGUSR1, sighandler); // VERSION 1

    // Option 2: ignore the signal
    //signal(SIGINT, SIG_IGN); // If a SIGINT is captured ignore it

    // Option 3: Use the default behavior
    
    //pid_t process_id = getpid(); // The process ID of the running process
    //printf("The process ID is %d\n", process_id);
    //signal(SIGINT, SIG_DFL); // Terminate :(
    
    // Simulation of work
    for (int i = 0; i < 500; i++)
    {
        printf("Sleeping...\n");
        sleep(5);
        printf("Awake\n");
    }
}
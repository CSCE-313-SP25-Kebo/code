/**
 * C program to illustrate the read system Call
 **/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd, sz;
    char *c = (char *)calloc(100, sizeof(char)); // compared to malloc ???

    fd = open("foo.txt", O_RDONLY);
    if (fd < 0)
    {
        //perror("r1");
        exit(1);
    }

    sz = read(fd, c, 10); // The read function returns the number of bytes read!
    printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
}

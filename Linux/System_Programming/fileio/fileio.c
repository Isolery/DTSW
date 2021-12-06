#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define MAX_READ 20
char buffer[MAX_READ+1];
ssize_t numRead;

int main(void)
{
    while( (numRead = read(STDIN_FILENO, buffer, MAX_READ)) > 0)
    {
        buffer[numRead] = '\0';
        printf("The input data was: %s\n", buffer);
    }

    return 0;
}


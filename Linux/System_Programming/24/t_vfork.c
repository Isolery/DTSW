#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int istack = 222;

    switch(vfork())
    {
        case -1:
            perror("vfork");

        case 0:
            sleep(3);
            write(STDOUT_FILENO, "child executing\n", 16);
            istack *= 3;
            _exit(EXIT_SUCCESS);

        default:
            write(STDOUT_FILENO, "parent executing\n", 17);
            printf("istack: %d\n", istack);
            exit(EXIT_SUCCESS);
    }
}
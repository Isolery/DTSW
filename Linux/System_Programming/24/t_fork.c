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

static int sdata = 111;

int main(int argc, char *argv[])
{
    int idata = 222;
    pid_t child_pid;

    switch(child_pid = fork())
    {
        case -1:  // error
            perror("fork error");
            break;
        case 0:   // 子进程
            idata *= 2;
            sdata *= 2;
            break;
        default:  // 父进程
            sleep(3);
            break;
    }

    printf("pid = %d, %s, idata = %d, sdata = %d\n", getpid(), (child_pid == 0) ? "child" : "parent", idata, sdata);

    exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i = 0;

    printf("alarm before\n");
    alarm(9);
    printf("alarm after\n");

    while(i < 20)
    {
        i++;
        sleep(1);
        printf("process things, i=%d\n", i);
    }

    return 0;
}
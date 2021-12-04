#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(void)
{
    printf("raise before\n");
    raise(9);   // == _exit() exit()
    printf("raise after\n");

    return 0;
}
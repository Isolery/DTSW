#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "curr_time.h"

int main(void)
{
    printf("currTime: %s\n", currTime("%F"));

    return 0;
}
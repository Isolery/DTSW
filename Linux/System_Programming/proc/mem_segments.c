#define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];
int primes[] = {2, 3, 5, 7};

static int square(int x)
{
    int result;

    result = x * x;
    return result;
}

static void doCalc(int val)
{
    printf("The square of %d is %d\n", val, square(val));

    if(val < 1000){
        int t;

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int main(int argc, char *argv[])
{
    static int key = 9973;           /* Initialized data segment */
    static char mbuf[10240000];      /* Uninitialized data segment */
    char *p;                         /* Allocated in frame for main() */

    p = malloc(1024);                /* Points to memory in heap segment */

    doCalc(key);

    exit(EXIT_SUCCESS);
}

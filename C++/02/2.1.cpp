#include <stdio.h>

int main(int argc, char *argv[])
{
    register int i = 1000;

    while(i--);

    printf("&i = %p\n", &i);

    return 0;
}

#include <stdio.h>

int main()
{
    int var = 0;

    int size = sizeof(var++);

    printf("var = %d, size = %d\n", var, size);

    return 0;
}
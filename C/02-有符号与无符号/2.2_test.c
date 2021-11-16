#include <stdio.h>

int main()
{
    unsigned int i = 5;
    int j = -10;

    if ((i + j) > 0)
        printf("i + j = %u\n", i + j);
    else
        printf("i + j < 0\n");

    return 0;
}

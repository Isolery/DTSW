#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;

    ++i || ++j && ++k;

    printf("i = %d, j = %d, k = %d\n ", i, j, k);

    return 0;
}
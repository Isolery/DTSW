#include <stdio.h>

int main(void)
{
    const int c = 0;
    int *p = (int*)&c;

    printf("c = %d\n", c);

    *p = 5;

    printf("c = %d\n", c);
    printf("*p = %d\n", *p);

    return 0;
}

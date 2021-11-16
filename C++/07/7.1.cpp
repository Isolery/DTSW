#include <stdio.h>

int mul(int x = 5);

int main(void)
{
    printf("%d\n", mul());
    printf("%d\n", mul(-1));
    printf("%d\n", mul(2));

    return 0;
}

int mul(int x)
{
    return x * x;
}
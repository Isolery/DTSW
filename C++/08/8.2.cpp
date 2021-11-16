#include <stdio.h>
#include <string.h>

int func(int a, int b, int c = 0)
{
    return a * b * c;
}

int func(int a, int b)
{
    return a + b;
}

int main(void)
{
    int c = func(1, 2);

    return 0;
}

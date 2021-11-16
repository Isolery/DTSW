#include <stdio.h>
#include <string.h>

int func(int x)
{
    return x;
}

int func(int x, int y)
{
    return x + y;
}

int func(const char *s)
{
    return strlen(s);
}

typedef int(*pFunc)(int);

int main(void)
{
    int c = 0;

    pFunc p = func;

    c = p(1);

    printf("c = %d\n", c);

    return 0;
}
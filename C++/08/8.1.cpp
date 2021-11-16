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

int main(void)
{
    printf("%d\n", func(3));
    printf("%d\n", func(4, 5));
    printf("%d\n", func("Gaoman"));

    return 0;
}
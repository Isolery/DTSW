#include <stdio.h>

f(i)
{
    printf("i = %d\n", i);
}

g()
{
    return 1;
}

int main(int argc, char *argv[])
{
    f(10);

    printf("g() = %d\n", g(1, 2));

    return 0;
}
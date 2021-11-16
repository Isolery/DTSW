#include <stdio.h>

int main(void)
{
    int a = 1;
    int& b = a;

    printf("a = %d, b = %d\n", a, b);
    printf("&a = %p, &b = %p\n", &a, &b);

    return 0;
}
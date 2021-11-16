#include <stdio.h>

int main()
{
    int a[5] = {0};
    int* p = NULL;

    printf("a = 0x%X\n", (unsigned int)(a));
    printf("a + 1 = 0x%X\n", (unsigned int)(a + 1));

    printf("p = 0x%X\n", (unsigned int)(p));
    printf("p + 1 = 0x%X\n", (unsigned int)(p + 1));

    return 0;
}
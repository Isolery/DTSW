#include <stdio.h>

int main()
{
    printf("%d\n", 3 << 2);
    printf("%d\n", 3 >> 1);
    printf("%d\n", -1 >> 1);
    printf("%d\n", 0x01 << 2 + 3);
    printf("%d\n", 3 << -1);

    return 0;
}
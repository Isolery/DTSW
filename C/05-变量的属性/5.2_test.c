#include <stdio.h>

extern int g_i;
extern int getI();

int main()
{
    printf("%d\n", g_i);
    printf("%d\n", getI());

    return 0;
}

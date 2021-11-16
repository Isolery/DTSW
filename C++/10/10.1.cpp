#include <stdio.h>

int main(void)
{
    int *p = new int;

    *p = 5;

    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    delete p;

    p = new int[10];

    for(int i=0; i<10; i++)
    {
        p[i] = i;
        printf("p[%d] = %d\n", i, p[i]);
    }

    delete[] p;

    return 0;
}
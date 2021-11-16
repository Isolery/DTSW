#include <stdio.h>

struct Ts
{

};

int main()
{
    struct Ts t1;
    struct Ts t2;

    printf("sizeof(struct Ts) = %d\n", sizeof(struct Ts));
    printf("sizeof(t1) = %d, &t1 = %p\n", sizeof(t1), &t1);
    printf("sizeof(t2) = %d, &t2 = %p\n", sizeof(t2), &t2);

    return 0;
}

#include <stdio.h>

struct A
{
//default public
    int i;

    int getI()
    {
        return i;
    }
};

class B
{
// default private
    int i;

    int getI()
    {
        return i;
    }
};

int main(void)
{
    A a;
    B b;

    a.i = 1; 
    printf("a.i = %d\n", a.getI());

    b.i = 2;
    printf("b.i = %d\n", b.getI());

    return 0;
}
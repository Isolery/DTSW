#include <stdio.h>

class Test
{
public:
    Test()
    {
        printf("Test()\n");
    }
    Test(int v)
    {
        printf("Test(int v), v = %d\n", v);
    }
    Test(int a, int b)
    {
        printf("Test(int a, int b), a = %d, b = %d\n", a, b);
    }
};

int main()
{
    Test t;          // 调用 Test()
    Test t1(1);      // 调用 Test(int v)
    Test t2 = 1;     // 调用 Test(int v)
    Test t3(1, 2);   // 调用 Test(int a, b)

    Test t4 = Test(3, 4);
    //t4.Test(3, 4);

    int i(100);

    printf("i = %d\n", i);

    return 0;
}
#include <stdio.h>

void func()
{
    printf("func()\n");
}

int func(int i)
{
    printf("func(int i) = %d\n", i);

    return i;
}

class Test
{
private:
    int mi;
public:
    Test()
    {
        printf("Test()\n");
    }
    Test(int i)
    {
        mi = i;
        printf("Test(int i), mi = %d\n", mi);
    }
    Test(const Test& t)
    {
        mi = t.mi;
        printf("Test(const Test&), mi = %d\n", mi);
    }

    static void func()
    {
        printf("static void func()\n");
    }

    void func(int i)
    {
        printf("void func, i = %d\n", i);
    }
};

int main(void)
{
    printf("constructor overload...\n");
    Test t1;
    Test t2(1);
    Test t3(t2);
    printf("\n");

    printf("global function overload...\n");
    func();
    func(1);
    printf("\n");

    printf("member function overload...\n");

    Test::func();
    t1.func();
    t1.func(2);
    printf("\n");

    return 0;
}
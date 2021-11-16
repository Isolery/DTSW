#include <stdio.h>

class Test
{
private:
    int mi;
public:
    Test(int v)
    {
        mi = v;
        printf("Test(): %d\n", mi);
    }
    ~Test()
    {
        printf("~Test(): %d\n", mi);
    }
};

int main(void)
{
    Test t(1);

    Test* pt = new Test(2);

    delete pt;

    return 0;
}
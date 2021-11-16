#include <stdio.h>

class Test
{
private:
    const int ci;
public:
    Test() : ci(100)
    {
        printf("Test::Test()\n");
    }
    int getCI()
    {
        return ci;
    }
    int setCI(int v)
    {
        int *p = const_cast<int*>(&ci);
    
        *p = v;
    }
};

int main()
{
    Test t;

    printf("t.ci = %d\n", t.getCI());

    t.setCI(10);

    printf("t.ci = %d\n", t.getCI());

    return 0;
}
#include <stdio.h>

class Test
{
private:
    const int ci;
public:
    Test() : ci(0)
    {
       
    }
    int getCI()
    {
        return ci;
    }
};

int main()
{
    Test t;

    printf("t.ci = %d\n", t.getCI());

    return 0;
}
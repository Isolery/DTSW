#include <stdio.h>

class Test
{
private:
    static int sCount;
public:
    Test()
    {
        sCount++;
    }
    ~Test()
    {
        --sCount;
    }
    int getCount()
    {
        return sCount;
    }
};

int Test::sCount = 0;

int main()
{
    printf("cont = %d\n", Test::sCount);
    
    return 0;
}

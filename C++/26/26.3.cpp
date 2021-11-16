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
    static int getCount()
    {
        return sCount;
    }
};

int Test::sCount = 0;

int main()
{
    printf("count = %d\n", Test::getCount());
    
    Test t1;
    Test t2;
    
    printf("count = %d\n", t1.getCount());
    printf("count = %d\n", t2.getCount());
    
    Test* pt = new Test();
    
    printf("count = %d\n", pt->getCount());
    
    delete pt;

    printf("count = %d\n", Test::getCount());
    
    return 0;
}

#include <stdio.h>

class Test
{
private:
    static int sCount = 0;
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

Test gTest;

int main()
{
    Test t1;
    Test t2;
    
    printf("count = %d\n", gTest.getCount());
    printf("count = %d\n", t1.getCount());
    printf("count = %d\n", t2.getCount());
    
    Test* pt = new Test();
    
    printf("count = %d\n", pt->getCount());
    
    delete pt;
    
    printf("count = %d\n", gTest.getCount());
    
    return 0;
}

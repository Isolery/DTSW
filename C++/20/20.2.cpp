#include <stdio.h>

class Value
{
private:
    int mi;
public:
    Value() {}
    Value(int i)
    {
        printf("i = %d\n", i);
        mi = i;
    }
    int getI()
    {
        return mi;
    }
};

class Test
{
private:
    Value m2;
    Value m3;
    Value m1;
public:
    Test() 
    {
        printf("Test::Test()\n");
    }
};


int main()
{
    Test t;
    
    return 0;
}

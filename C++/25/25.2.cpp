#include <stdio.h>

class Test
{
private:
    const static int sCount = 1;
public:
    int getCount()
    {
        return sCount;
    }
};

//const int Test::sCount = 0;

int main()
{
    Test t;
    
    printf("sCount = %d\n", t.getCount());
    
    return 0;
}

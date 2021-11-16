#include <stdio.h>

class Test
{
private:
    int mi;
public:
    int mj;
    Test(int i);
    int getMi() const;
};

Test::Test(int i)
{
    mi = i;
}

int Test::getMi() const
{
    //mi = 0;  // error: assignment of data-member ‘Test::mi’ in read-only structure
    return mi;
}

int main()
{
    const Test t(1);

    printf("t.getMi() = %d\n", t.getMi());
    
    return 0;
}

#include <stdio.h>

class Test
{
private:
    int mi;
public:
    int mj;
    Test(int i);
    int getMi(Test *const mthis);
    int getMi_const(const Test *const mthis);
    int getMi(const Test *const mthis) const;
};

Test::Test(int i)
{
    mi = i;
}

int Test::getMi(Test *const mthis)
{
    mthis->mi = 0;

    //mthis = NULL;    // error: assignment of read-only parameter ‘mthis’

    return mi;
}

int Test::getMi_const(const Test *const mthis)
{
    //mthis->mi = 0;   // 

    //mthis = NULL;    // error: assignment of read-only parameter ‘mthis’

    return mi;
}

int Test::getMi(const Test *const mthis) const
{
    return mi;
}

int main(void)
{
    Test t1(1);
    const Test t2(2);
    const Test t3(3);

    printf("t1.getMi(&t) = %d\n", t1.getMi(&t1));
    printf("t2.getMi(&t) = %d\n", t2.getMi_const(&t2));
    printf("t3.getMi(&t) = %d\n", t3.getMi(&t3));
    
    return 0;
}

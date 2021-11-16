#include <stdio.h>

class Test
{
    int mi;
    int mj;
    bool mStatus;
public:
    Test(int i, int j) : mStatus(false)
    {
        mi = i;

        return;

        mj = j;

        mStatus = true;
    }
    int getI()
    {
        return mi;
    }
    int getJ()
    {
        return mj;
    }
    int status()
    {
        return mStatus;
    }
};

int main(void)
{
    Test t(1, 2);

    if(t.status())
    {
        printf("t1.mi = %d\n", t.getI());
        printf("t2.mi = %d\n", t.getJ());
    }

    return 0;
}


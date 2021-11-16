#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test(int i)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }

    Test& operator ++ ()
    {
        ++mValue;

        return *this;
    }

    Test operator ++ (int)
    {
        Test ret(mValue);

        mValue++;

        return ret;
    }
};

int main(void)
{
    Test t0(0);

    Test t1 = ++t0;

    cout << t1.value() << endl;
    cout << t0.value() << endl;

    Test t2 = t0++;

    cout << t2.value() << endl;
    cout << t0.value() << endl;

    return 0;
}

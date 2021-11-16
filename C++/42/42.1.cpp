#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test()
    {
        mValue = 0;
    }
    Test(int i)
    {
        mValue = i;
    }

    operator int ()
    {
        return mValue;
    }

    int value()
    {
        return mValue;
    }
};

int main(void)
{
    Test t(100);

    int i = t;

    cout << t.value() << endl;
    cout << i << endl;

    return 0;
}
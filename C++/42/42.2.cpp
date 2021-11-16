#include <iostream>
#include <string>

using namespace std;

class Test;

class Value
{
public:
    Value()
    {

    }
    explicit Value(Test& t)
    {

    }
};

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

    operator Value ()
    {
        Value ret;

        cout << "operator Value()" << endl;

        return ret;
    }

    int value()
    {
        return mValue;
    }
};

int main(void)
{
    Test t(100);

    Value v = t;

    return 0;
}
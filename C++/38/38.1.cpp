#include <iostream>

using namespace std;

class Test
{
    int mValue;
public:
    Test(int v)
    {
        mValue = v;
    }
    int value() const
    {
        return mValue;
    }
};

bool operator && (const Test& l, const Test& r)
{
    return (l.value() && r.value());
}

bool operator || (const Test& l, const Test& r)
{
    return (l.value() || r.value());
}

Test fun(Test t)
{
    cout << "Test fun(Test t) : t.value() = " << t.value() << endl;

    return t;
}

int main(void)
{
    Test t0(0);
    Test t1(1);

    if( fun(t0) && fun(t1) )
    {
        cout << "Result is true" << endl;
    }
    else
    {
        cout << "Result is false" << endl;
    }

    if( fun(t1) || fun(t0) )
    {
        cout << "Result is true" << endl;
    }
    else
    {
        cout << "Result is false" << endl;
    }

    return 0;
}
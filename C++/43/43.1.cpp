#include <iostream>
#include <string>

using namespace std;

class Parent
{
    int mValue;
public:
    Parent()
    {
        cout << "Parent()" << endl;

        mValue = 100;
    }
    void method()
    {
        cout << "mValue = " << mValue << endl;
    }
    ~Parent()
    {
        cout << "~Parent()" << endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }
    void hello()
    {
        cout << "I'm Child class!" << endl;
    }
    ~Child()
    {
        cout << "~Child()" << endl;
    }
};

int main(void)
{
    Child c;
    Parent p1 = c;
    Parent p2;

    c.hello();
    c.method();

    p2 = c;
    //p2.hello();    // error

    return 0;
}

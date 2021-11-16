#include <iostream>
#include <string>

using namespace std;

class Parent
{
//private:
protected:
    int mv;
public:
    Parent()
    {
        mv = 100;
    }

    int value()
    {
        return mv;
    }
};

class Child : public Parent
{
public:
    int addValue(int v)
    {
        mv = mv + v;
    }
};

int main(void)
{
    Parent p;

    //p.mv = 1;    // 

    cout << "p.mv = " << p.value() << endl;

    Child c;

    //c.mv = 1;    // 
    cout << "c.mv = " << c.value() << endl;

    return 0;
}
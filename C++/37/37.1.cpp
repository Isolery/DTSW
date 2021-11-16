#include <iostream>
#include <string>

using namespace std;

class Test
{
    int i;
public:
    Test(int i)
    {
        cout << "Test(int i)" << endl;
        this->i = i;
    }
    int value()
    {
        return i;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

class Pointer
{
    Test* mp;
public:
    Pointer(Test *p = NULL)
    {
        mp = p;
    }
    Pointer(const Pointer& obj)
    {
        mp = obj.mp;
        const_cast<Pointer&>(obj).mp = NULL;
    }

    Test* operator -> ()
    {
        return mp;
    }
    Test& operator * ()
    {
        return *mp;
    }

    Pointer& operator = (const Pointer& obj)
    {
        if(this != &obj)
        {
            mp = obj.mp;
            const_cast<Pointer&>(obj).mp = NULL;
        }

        return *this;
    }

    bool isNULL()
    {
        return (mp == NULL);
    }
    Test* value()
    {
        return mp;
    }

    ~Pointer()
    {
        delete mp;
    }
};

int main(void)
{
    Pointer p1 = new Test(0);

    cout << p1->value() << endl;
    cout << p1.value() << endl; 

    Pointer p2 = p1;

    cout << p1.value() << endl; 
    cout << p2.value() << endl; 
    
    return 0;
}

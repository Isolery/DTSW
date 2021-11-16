#include <iostream>

using namespace std;

class Test
{
    int *m_pointer;
public:
    Test()
    {
        m_pointer = NULL;
    }
    Test(int i)
    {
        m_pointer = new int(i);
    }
    Test(const Test& obj)
    {
        m_pointer = new int(*obj.m_pointer);
    }

    Test& operator = (const Test& obj)
    {
        if(this != &obj)
        {
            delete m_pointer;
            m_pointer = new int(*obj.m_pointer);
        }

        return *this;
    }

    void print()
    {
        cout << "m_pointer: " << hex << m_pointer << endl;
    }

    ~Test()
    {
        delete m_pointer;
    }
};

int main(void)
{
    Test t1(1);
    Test t2 = t1;

    Test t3;

    t3 = t1;

    t1.print();
    t2.print();
    t3.print();

    return 0;
}
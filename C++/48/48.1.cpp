#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;
    
    void add(int i)
    {
        mi += i;
    }
    
    void add(int a, int b)
    {
        mi += (a + b);
    }
};

class Child : public Parent
{
public:
    int mi;
    int mv;
    
    void add(int x, int y, int z)
    {
        mi += (x + y + z);
    }
};

int main()
{
    Parent p;
    Child c;
    
    p = c;
    
    Parent p1(c);
    
    Parent& rp = c;
    Parent* pp = &c;
    
    c.mi = 10;
    rp.mi = 100;
    rp.add(5);             // 没有发生同名覆盖?
    rp.add(10, 10);        // 没有发生同名覆盖?

    cout << "c.mi = " << c.mi << endl;
    cout << "rp.mi = " << rp.mi << endl;
    
    /* 为什么编译不过? */
    //rp.mv = 1000;
    //rp.add(1, 10, 100);
    //pp->mv = 1000;
    //pp->add(1, 10, 100);
    
    return 0;
}
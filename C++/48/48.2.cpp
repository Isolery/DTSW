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
    
    void print()
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    int mv;
    
    void add(int x, int y, int z)
    {
        mv += (x + y + z);
    }
    
    void print()
    {
        cout << "I'm Child." << endl;
    }
};

int main()
{
    Parent p;
    Child c;

    p.print();
    c.print();
    
    return 0;
}
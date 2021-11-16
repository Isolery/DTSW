#include <iostream>
#include <string>

using namespace std;

class Parent 
{
public:
    // Parent()
    // {
    //     cout << "Parent()" << endl;
    // }
    Parent(int a = 1)
    {
        cout << "a = " << a << endl;
    }
    // Parent(string s)
    // {
    //     cout << "Parent(string s) " << s << endl;
    // }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }
    Child(string s) 
    {
        cout << "Child(string s) " << s << endl;
    }
};

int main(void)
{
    Child c;
    Child cc("cc");

    return 0;
}
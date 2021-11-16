#include <iostream>
#include <string>

using namespace std;

class Object
{
public:
    Object()
    {
        cout << "Object()" << endl;
    }
    Object(string s)
    {
        cout << "Object(string s) " << s << endl;
    }
};

class Parent : public Object
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }
    Parent(string s) : Object(s)
    {
        cout << "Parent(string s) " << s << endl;
    }
};

class Child : public Parent
{
    Object mO1;
    Object mO2;
public:
    Child() : mO1("Default 1"), mO2("Default 2")
    {
        cout << "Child()" << endl;
    }
    Child(string s) : Parent(s), mO1(s + "1"), mO2(s + "2")
    {
        cout << "Child(string s) " << s << endl;
    }
};

int main(void)
{
    Child c;

    cout << endl;

    Child cc("cc");

    return 0;
}
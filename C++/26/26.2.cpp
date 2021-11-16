#include <stdio.h>

class Demo
{
private:
    int i;
public:
    int getI();
    static void StaticFunc(const char* s);
    static void StaticSetI(Demo& d, int v);
};

int Demo::getI()
{
    return i;
}

void Demo::StaticFunc(const char* s)
{
    printf("StaticFunc: %s\n", s);
}

void Demo::StaticSetI(Demo& d, int v)
{
    //i = v;  error: invalid use of member ‘Demo::i’ in static member function
    d.i = v;
    Demo::StaticFunc("Hello");
}

int main()
{
    Demo::StaticFunc("main Begin...");    // 通过类名直接调用

    Demo d;

    Demo::StaticSetI(d, 10);

    printf("d.i = %d\n", d.getI());

    d.StaticFunc("main End...");   // 通过对象名直接调用

    return 0;
}
#include <stdio.h>
#include <math.h>

const char endl = '\n';

class Console
{
public:
    Console& operator << (int i)
    {
        printf("%d", i);

        return *this;
    }

    Console& operator << (char c)
    {
        printf("%c", c);

        return *this;
    }

    Console& operator << (double d)
    {
        printf("%f", d);

        return *this;
    }

    Console& operator << (const char *s)
    {
        printf("%s", s);

        return *this;
    }
};

Console cout;

int main(void)
{
    cout << 10 << endl;

    cout << 'a' << endl;

    double a = 3;
    double b = 4;
    double c = sqrt(a * a + b * b);

    cout << c << endl;

    cout << "Hello World!" << endl;

    return 0;
}

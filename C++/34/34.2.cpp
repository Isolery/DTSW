#include <iostream>
#include <string>

using namespace std;

class Test
{
    int a[5];
public:
    int& operator [](int i)
    {
        return a[i];
    }
    int& operator [](const string& s)
    {
        if(s == "0")
        {
            return a[0];
        }
        else if(s == "1")
        {
            return a[1];
        }
        else if(s == "2")
        {
            return a[2];
        }
        else if(s == "3")
        {
            return a[3];
        }
        else if(s == "4")
        {
            return a[4];
        }
    }
};

int main(void)
{
    Test t;

    for(int i = 0; i < 5; i++)
    {
        t[i] = i;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << t[i] << endl;
    }

    cout << endl;

    cout << t["0"] << endl;
    cout << t["1"] << endl;
    cout << t["2"] << endl;
    cout << t["3"] << endl;
    cout << t["4"] << endl;

    return 0;
}


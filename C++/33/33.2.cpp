#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define TO_NUMBER(s, n) (istringstream(s) >> n)
#define TO_STRING(n)    (((ostringstream&)(ostringstream() << n)).str())

bool to_number(const string& str, int& n)
{
    istringstream iss(str);

    return iss >> n;
}

string to_string(double num)
{
    ostringstream oss;
    oss << num;

    return oss.str();
}

int main(void)
{
    double n = 0;

    // cout << to_number("123", n) << endl;
    // cout << n << endl;

    if(TO_NUMBER("123.456", n))
    {
        cout << n << endl;
    }

    //cout << to_string(654.321) << endl;

    string s = TO_STRING(123);
    cout << s << endl;

    return 0; 
}
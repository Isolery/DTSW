#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 1;
    
    //int& b = 1;    //error
    int& b = a;
    const int& c = 1;

    int *p = (int*)&c;

    //c = 5;    //error

    *p = 5;
    
    return 0;
}
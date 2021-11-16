#include <stdio.h>

int main()
{   
    char c = 0;
    short s = 0;
    int i = 0;
    double d = 0;
    char* p = "str";
        
    printf( "%d\n", sizeof(c ? c : s) );
    printf( "%d\n", sizeof(i ? i : d) );
    // printf( "%d\n", sizeof(d ? d : p) );    // error

    return 0;
}

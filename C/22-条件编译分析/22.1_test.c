#include <stdio.h>

int main()
{
    const char* s;

    #ifdef C
        s = "This is first printf...\n";
    #else
        s = "This is second printf...\n";
    #endif

    printf("%s", s);

    return 0;
}
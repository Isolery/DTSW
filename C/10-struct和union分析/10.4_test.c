#include <stdio.h>

int system_mode()
{
    union SM
    {
        int i;
        char c;
    };

    union SM sm;

    sm.i = 1;

    return sm.c;
}

int main()
{
    printf("System mode: %d\n", system_mode());

    return 0;
}
#include <stdio.h>

int main()
{
    printf("%s : %d\n", __FILE__, __LINE__);

    #line 1 "gaoman.c"

    printf("%s : %d\n", __FILE__, __LINE__);

    return 0;
}
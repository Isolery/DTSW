#include <stdio.h>
#include <assert.h>

int strlen(const char* s)
{
    return assert(s), (*s ? strlen(s + 1) + 1 : 0);
}

int main()
{
    printf("len = %d\n", strlen("Gaoman"));
    printf("len = %d\n", strlen(NULL));

    return 0;
}
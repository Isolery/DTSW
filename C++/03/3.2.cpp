#include <stdio.h>

int main()
{
    const volatile int c = 0;
    int* p = (int*)&c;
    
    *p = 5;
    
    printf("c = %d\n", c);
    printf("*p = %d\n", *p);
    printf("&c = %p\n", &c);
    printf("p = %p\n", p);
    
    return 0;
}

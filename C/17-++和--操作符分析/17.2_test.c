#include <stdio.h>

int main()
{   
    int i = 0;
    // int j = ++i+++i+++i;    // error
    int j = ++i + ++i + ++i;
    
    int a = 1;
    int b = 4;
    int c = a+++b;
    
    int* p = &a;
    
    b = b / *p;

    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
      
    return 0;
}

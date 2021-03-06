#include <stdio.h>

int main()
{
    const int x = 1;
    const int& rx = x;
    
    int& nrx = const_cast<int&>(rx);
    
    nrx = 5;
    
    printf("x = %d\n", x);
    printf("rx = %d\n", rx);
    printf("nrx = %d\n", nrx);
    printf("&x = %p\n", &x);
    printf("&rx = %p\n", &rx);
    printf("&nrx = %p\n", &nrx);
    
    volatile const int y = 2;
    int* p = const_cast<int*>(&y);
    
    *p = 6;
    
    printf("y = %d\n", y);
    printf("p = %p\n", p);
    
    const int z = y;
    
    p = const_cast<int*>(&z);
    
    *p = 7;
    
    printf("z = %d\n", z);
    printf("p = %p\n", p);
    
    char c = 'c';
    char& rc = c;
    const int& trc = c;
    
    rc = 'a';
    
    printf("c = %c\n", c);
    printf("rc = %c\n", rc);
    printf("trc = %c\n", trc);
    printf("&c = %p\n", &c);
    printf("&rc = %p\n", &rc);
    printf("&trc = %p\n", &trc);
    
    return 0;
}
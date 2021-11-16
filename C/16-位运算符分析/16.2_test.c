#include <stdio.h>

#define SWAP1(a, b)    \
{                     \
    int temp = a;     \
    a = b;            \
    b = temp;         \
}  

#define SWAP2(a, b)    \
{                      \
    a = a + b;         \
    b = a - b;         \
    a = a - b;         \
}  

#define SWAP3(a, b)    \
{                      \
    a = a ^ b;         \
    b = a ^ b;         \
    a = a ^ b;         \
} 

int main()
{
    int a = 1;
    int b = 2;

    SWAP3(a, b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
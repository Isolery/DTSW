#include <stdio.h>

#pragma pack(4)

struct Test1
{
    char  c1;
    short s;
    char  c2;
    int   i; 
};

struct Test2
{
    char  c1;
    char  c2;
    short s;
    int   i;
};

struct S1
{
    short a;
    long b;
};

struct S2
{
    char c;
    struct S1 d;
    double e;
};

#pragma pack()

int main()
{
    printf("%d\n", sizeof(struct Test1));    // 12
    printf("%d\n", sizeof(struct Test2));    // 8
    printf("%d\n", sizeof(struct S1));       // 8
    printf("%d\n", sizeof(struct S2));       // 20

    return 0;
}
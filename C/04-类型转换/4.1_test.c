#include <stdio.h>

struct Ts
{
    int i;
    int j;
};

struct Ts ts;

int main()
{
    short s = 0x1122;

    char c = (char)s;    // 0x22

    int i = (int)s;    // 0x00001122

    int j = (int)3.1415;    // 3

    unsigned int p = (unsigned int)&ts;

    //long l = (long)ts;    // error

    //ts = (long)ts;    // error

    printf("s = %x\n", s);
    printf("c = %x\n", c);
    printf("i = %x\n", i);
    printf("j = %x\n", j);
    printf("p = %x\n", p);
    printf("&ts = %p\n", &ts);

    return 0;
}

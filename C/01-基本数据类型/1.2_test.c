#include <stdio.h>

typedef int INT32;
typedef unsigned char BYTE;
typedef struct _tag_ts
{
    BYTE b1;
    BYTE b2;
    short s;
    INT32 i;
} TS;

int main()
{
    INT32 i32;
    BYTE b;
    TS ts;

    printf("%d, %d\n", sizeof(INT32), sizeof(i32));
    printf("%d, %d\n", sizeof(BYTE), sizeof(b));
    printf("%d, %d\n", sizeof(TS), sizeof(ts));

    return 0;
}

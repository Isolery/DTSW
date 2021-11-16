#include <stdio.h>

typedef int Int32;

struct _tag_point
{
    int x;
    int y;
};

typedef struct _tag_point Point;

typedef struct
{
    int length;
    int arry[];
}SoftArray;

typedef struct _tag_list_node ListNode;
struct _tag_list_node
{
    ListNode* next;
};

int main()
{
    Int32 i = -100;
    //unsigned Int32 ii = 0;  // error
    Point p;
    SoftArray* sa = NULL;
    ListNode* node = NULL;

    return 0;
}
#include <stdio.h>

namespace First
{
    int i = 0;
}

namespace Second
{
    int i = 1;

    namespace Internal
    {
        int i = 2;

        struct P
        {
            int x;
            int y;
        };
    }
}

int main(void)
{
    using namespace First;

    printf("First::i = %d\n", i);
    printf("Second::i = %d\n", Second::i);
    printf("Second::Internal::i = %d\n", Second::Internal::i);

    using Second::Internal::P;

    P p = {2, 3};

    printf("p.x = %d\n", p.x);
    printf("p.y = %d\n", p.y);

    return 0;
}
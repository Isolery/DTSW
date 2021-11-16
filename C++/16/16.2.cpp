#include <stdio.h>
#include "Operator.h"

int main(void)
{
    Operator op;
    double r = 0;

    op.setOperator('/');
    op.setParameter(9, 3);

    if(op.result(r))
    {
        printf("r = %lf\n", r);
    }
    else
    {
        printf("Calculte error!\n");
    }

    return 0;
}
#include <stdio.h>

int main(void)
{
    int *pi = new int(1);
    double *pf = new double(2.5f);
    char *pc = new char('a');

    printf("pi = %d\n", *pi);
    printf("pf = %f\n", *pf);
    printf("pc = %c\n", *pc);

    delete pi;
    delete pf;
    delete pc;

    return 0;
}
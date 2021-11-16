//TwoPhaseCons   NewInstance  construct
#include <stdio.h>

class TwoPhaseCons
{
private:
    int mi;

    TwoPhaseCons() : mi(0)
    {

    }
    bool construct()
    {
        int *p = new int(1);

        if(p == NULL) return false;
        
        return true;
    }
public:
    static TwoPhaseCons *NewInstance();
};

TwoPhaseCons * TwoPhaseCons::NewInstance()
{
    TwoPhaseCons *ret = new TwoPhaseCons();

    if(!(ret && ret->construct()))
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}

int main(void)
{
    TwoPhaseCons *obj = TwoPhaseCons::NewInstance();

    printf("obj = %p\n", obj);

    delete obj;

    return 0;
}
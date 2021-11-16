#include <stdio.h>

class Test {
    int mi;
public:
    Test(int i) {
        mi = i;
        printf("Test(int i)\n");
    }
    Test() {
        Test(0);
    }
    ~Test(){
        printf("~Test(): %d\n", mi);
    }
    void print() {
        printf("mi = %d\n", mi);
    }
};


int main()
{
    Test t;
    
    t.print();

    return 0;
}

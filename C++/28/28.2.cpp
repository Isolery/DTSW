#include <stdio.h>

class ClassC
{
    const char* Name;
public:
    ClassC(const char* Name)
    {
        this->Name = Name;
    }

    friend class ClassB;
};

class ClassB
{
    const char* Name;
public:
    ClassB(const char* Name)
    {
        this->Name = Name;
    }
    
    void getClassCName(ClassC& c)
    {
        printf("c.name = %s\n", c.Name);
    }

    friend class ClassA;
};

class ClassA
{
    const char* Name;
public:
    ClassA(const char* Name)
    {
        this->Name = Name;
    }
    
    void getClassBName(ClassB& b)
    {
        printf("b.name = %s\n", b.Name);
    }

    // void getClassCName(ClassC& c)
    // {
    //     printf("c.name = %s\n", c.Name);
    // }
};

int main(void)
{
    ClassA A("A");
    ClassB B("B");
    ClassC C("C");

    A.getClassBName(B);
    B.getClassCName(C);

    //A.getClassCName(C);   // error: ‘const char* ClassC::Name’ is private

    return 0;
}
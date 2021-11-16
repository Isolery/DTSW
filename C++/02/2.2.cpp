#include <stdio.h>

typedef struct
{
    const char* name;
    int age;
}Student1;

struct Student2
{
    const char* name;
    int age;
};

int main(int argc, char *argv[])
{
    Student1 stu1 = {"zhangsan", 20};
    Student2 stu2 = {"lisi", 22};

    printf("Student1's name = %s, age is %d\n", stu1.name, stu1.age);
    printf("Student2's name = %s, age is %d\n", stu2.name, stu2.age);

    return 0;
}

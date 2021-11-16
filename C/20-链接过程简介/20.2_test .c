#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void* pdlib = dlopen("./dlib.so", RTLD_LAZY);

    char* (*pname)();
    int (*padd)(int, int);

    if( pdlib != NULL )
    {
        pname = dlsym(pdlib, "name");
        padd = dlsym(pdlib, "add");
 
        if( (pname != NULL) && (padd != NULL) )
        {
            printf("Name: %s\n", pname());
            printf("Result: %d\n", padd(2, 3));
        }

        dlclose(pdlib);
    }
    else
    {
        printf("Cannot open lib ...\n");
    }

    return 0;
}


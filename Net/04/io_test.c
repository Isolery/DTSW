#include <stdio.h>
#include <unistd.h>

int main()
{
    int iofd = 0;
    char s[] = "D.T.Software\n";
    int len = 0;

    write(1, s, sizeof(s));

    len = read(0, s, 5);

    s[len] = '\0';

    printf("%s\n", s);

    return 0;
}

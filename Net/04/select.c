#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int iofd = 0;
    int fd = 0;
    char s[] = "D.T.Software\n";
    int len = 0;
    fd_set reads = {0};
    fd_set temps = {0};
    struct timeval timeout = {0};

    fd = open("test.txt", O_RDWR);
    if(fd < 0){
        printf("open error\n");
    }

    FD_ZERO(&reads);
    FD_SET(iofd, &reads);
    FD_SET(fd, &reads);

    while(1)
    {
        int r = -1;

        temps = reads;

        timeout.tv_sec = 0;
        timeout.tv_usec = 50000;

        r = select(1, &temps, NULL, NULL, &timeout);

        if(r > 0){
            printf("reading...\n");
            len = read(iofd, s, sizeof(s)-1);
            s[len] = '\0';
            printf("Input: %s\n", s);
        }else if(r == 0){
            static int count = 0;

            usleep(10000);

            count++;

            if(count > 100){
                printf("do something else\n");
                count = 0;
            }
        }else{break;}
    }

    return 0;
}
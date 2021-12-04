#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd, flag;
    char template[] = "/tmp/testXXXXXX";

    setbuf(stdout, NULL);

    // 在创建子进程之前打开文件，子进程继承父进程的fd
    if((fd = mkstemp(template)) == -1){
        perror("mkstemp error");
    }

    printf("file offset before fork: %lld\n", (long long)lseek(fd, 0, SEEK_CUR));

    if((flag == fcntl(fd, F_GETFL)) == -1){
        perror("fcntl error");
    }

    printf("O_APPEND flag before fork: %s\n", (flag & O_APPEND) ? "on" : "off");

    switch(fork())
    {
        case -1:
            perror("fork error");
            break;
        case 0:
            if(lseek(fd, 1000, SEEK_CUR) == -1){
                perror("lseek error");
            }

            if(fcntl(fd, F_GETFL) == -1){
                perror("fcntl get error");
            }

            flag |= O_APPEND;
            if(fcntl(fd, F_SETFL, flag) == -1){
                perror("fcntl set error");
            }

            _exit(EXIT_SUCCESS);

        default:
            if(wait(NULL) == -1){
                printf("wait error");
            }

            printf("child has existed\n");

            printf("file offset after fork: %lld\n", (long long)lseek(fd, 0, SEEK_CUR));

            if((flag = fcntl(fd, F_GETFL)) == -1){
                perror("fcntl error");
            }

            printf("O_APPEND flag after fork: %s\n", (flag & O_APPEND) ? "on" : "off");
    }
}
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int fd[2];
    int ret;
    char writebuf[] = "hello linux";
    char readbuf[128] = {0};
    char process_inter = 0;
    pid_t pid;

    ret = pipe(fd);
    if(ret < 0){
        printf("create pipe failed\n");
        return -1;
    }

    printf("create pipe success, fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);

    pid = fork();
    if(pid == 0){
        int i = 0;
        read(fd[0], &process_inter, 1);
        while(process_inter == 0);
        for(i=0; i<5; i++)
        {
            printf("this is child process i=%d\n", i);
            usleep(100);
        }
    }
    if(pid > 0){
        int i = 0;
        for(i=0; i<5; i++)
        {
            printf("this is parent process i=%d\n", i);
            usleep(100);
        }
        process_inter = 1;
        sleep(5);
        write(fd[1], &process_inter, 1);
    }

    while(1);
    return 0;
}
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

    write(fd[1], writebuf, sizeof(writebuf));

    read(fd[0], readbuf, 128);
    printf("readbuf: %s\n", readbuf);

    memset(readbuf, 0, 128);

    read(fd[0], readbuf, 128);
    printf("second read after\n");

    close(fd[0]);
    close(fd[1]);

    return 0;
}

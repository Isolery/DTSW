#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main(void)
{
    int ret;
    char process_inter = 0;
    int fd;

    fd = open("/tmp/myfifo", O_WRONLY);
    if(fd < 0){
        printf("open myfifo failed\n");
        return -1;
    }

    printf("open myfifo success\n");

    for(int i=0; i<5; i++)
    {
        printf("this is first process i=%d\n", i);
        usleep(100);
    }
    process_inter = 1;
    sleep(5);

    write(fd, &process_inter, 1);

    while(1);

    return 0;
}

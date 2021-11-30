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

    fd = open("/tmp/myfifo", O_RDONLY);
    if(fd < 0){
        printf("open myfifo failed\n");
        return -1;
    }

    printf("open myfifo success\n");

    read(fd, &process_inter, 1);
    while(process_inter == 0);

    for(int i=0; i<5; i++)
    {
        printf("this is second process\n");
        usleep(100);
    }

    while(1);

    return 0;
}

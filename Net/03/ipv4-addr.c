#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

int main()
{
    unsigned int addr = inet_addr("1.2.3.4");
    struct in_addr addr1 = {0x09080706};
    struct in_addr addr2 = {0x05040302};

    char *s1 = strcpy(malloc(32), inet_ntoa(addr1));    // inet_ntoa返回的是同一个内存地址, 因此多次调用前要将数据拷贝出来以防止覆盖
    char *s2 = strcpy(malloc(32), inet_ntoa(addr2));

    printf("addr = %x\n", addr);

    printf("addr1 = %x\n", addr);
    printf("addr1 = %x\n", addr1.s_addr);
    printf("addr2 = %x\n", addr2.s_addr);

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    if(inet_aton("D.T.Software", &addr1)){      // inet_aton函数不仅可以转换ip地址，还可以判断输入的ip地址是否合法
        printf("addr1 = %x\n", addr1.s_addr);
    }else{
        printf("invaild ipaddr\n");
    }

    free(s1);
    free(s2);

    return 0;
}
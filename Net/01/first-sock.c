#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int sock = 0;
    struct sockaddr_in addr = {0};
    char *tosend = "GET /index.html HTTP/1.1\nHOST: www.dt4sw.com\nUser-Agent: TEST\nConnection: close\n\n";
    int len = 0;
    char buf[128] = {0};
    int r = 0;

    sock = socket(PF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        printf("socket error\n");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("47.99.217.175");
    addr.sin_port = htons(80);

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1 ){
        printf("connect error\n");
    }else{
        printf("connect success\n");
    }

    len = send(sock, tosend, strlen(tosend), 0);

    printf("send bytes = %d\n", len);

    do
    {
        int i = 0;

        r = recv(sock, buf, sizeof(buf), 0);
        if(r > 0){
            len += r;
        }

        for(i=0; i<r; i++)
        {
            printf("%c", buf[i]);
        }
    }while(r > 0);

    printf("recv bytes: %d\n", len);

    close(sock);

    return 0;
}
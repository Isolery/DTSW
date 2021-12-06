#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sock = 0;
    struct sockaddr_in caddr = {0};
    char input[32] = {0};
    char buf[128] = {0};

    sock = socket(PF_INET, SOCK_STREAM, 0);

    if(sock  == -1){
        printf("socket error\n");
        return -1;
    }

    caddr.sin_family = AF_INET;
    caddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    caddr.sin_port = htons(8888);

    if(connect(sock, (struct sockaddr*)&caddr, sizeof(caddr)) == -1){
        printf("connect error\n");
        return -1;
    }

    printf("connect success\n");

    while(1)
    {
        printf("Input: ");

        scanf("%s", input);

        int len = send(sock, input, strlen(input)+1, 0);

        int r = recv(sock, buf, sizeof(buf), 0);
        if(r > 0){
            printf("Receive: %s\n", buf);
        }else{
            break;
        }
    }

    close(sock);

    return 0;
}
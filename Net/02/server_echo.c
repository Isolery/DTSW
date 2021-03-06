#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int server = 0;
    int client = 0;
    struct sockaddr_in saddr = {0};
    struct sockaddr_in caddr = {0};
    char buf[32] = {0};

    int r = 0;

    server = socket(PF_INET, SOCK_STREAM, 0);

    if(server == -1){
        printf("server socket error\n");
        return -1;
    }

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(8888);

    if(bind(server, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
        printf("server bind error\n");
        return -1;
    }

    if(listen(server, 1) == -1){
        printf("server listen error\n");
        return -1;
    }

    printf("server start success\n");

    socklen_t asize = sizeof(caddr);

    while(1)
    {
        client = accept(server, (struct sockaddr *)&caddr, &asize);

        if(client == -1){
            printf("client accept error\n");
            return -1;
        }

        printf("client: %d\n", client);

        do
        {
            r = recv(client, buf, sizeof(buf), 0);

            if(r > 0){
                printf("Receive: %s\n", buf);

                if(strcmp(buf, "quit") != 0){
                    int len = send(client, buf, r, 0);
                }else{
                    break;
                }
            }
        }while(r > 0);

        close(client);
    }

    close(server);

    return 0;
}
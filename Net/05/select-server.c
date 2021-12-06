#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>

int server_handler(int server)
{
    struct sockaddr_in addr = {0};
    socklen_t asize = sizeof(addr);

    return accept(server, (struct sockaddr *)&addr, &asize);
}

int client_handler(int client)
{
    char buf[32] = {0};
    int ret = read(client, buf, sizeof(buf)-1);

    if(ret > 0){
        buf[ret] = '\0';
        printf("Receive: %s\n", buf);

        if(strcmp(buf, "quit") != 0){
            ret = write(client, buf, ret);
        }else{
            ret = -1;
        }
    }

    return ret;
}

int main()
{
    int server = 0;
    int client = 0;
    struct sockaddr_in saddr = {0};
    char buf[32] = {0};
    int max = 0;
    int num = 0;
    struct timeval timeout = {0};

    fd_set reads = {0};
    fd_set temps = {0};

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

    socklen_t asize = sizeof(saddr);

    FD_ZERO(&reads);
    FD_SET(server, &reads);

    max = server;

    while(1)
    {
        temps = reads;

        timeout.tv_sec = 0;
        timeout.tv_usec = 10000;

        num = select(max+1, &temps, 0, 0, &timeout);   // num表示有事件发生时的文件描述符数量

        if(num > 0){
            for(int i=0; i<=max; i++)
            {
                if(FD_ISSET(i, &temps)){
                    if(i == server){
                        int client = server_handler(server);

                        if(client > -1){
                            FD_SET(client, &reads);

                            max = (client > max) ? client : max;

                            printf("accept client: %d\n", client);
                        }
                    }else{
                        int r = client_handler(i);

                        if(r == -1){
                            FD_CLR(i, &reads);

                            close(i);
                        }
                    }
                }
            }
        }
    }

    close(server);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "msg_parser.h"

typedef struct msg_parser
{
    Message cache;    // 缓存已解析的消息头
    int header;       // 标识消息头是否解析成功
    int need;         // 标识还需要多少字节才能完成解析
    Message* msg;     // 解析中的协议消息(半成品)
} MsgParser;

MParser* MParser_New()
{
    MParser *ret = calloc(1, sizeof(MsgParser));

    MParser_Reset(ret);

    return ret;
}

Message* MParser_ReadMem(MParser* parser, unsigned char* mem, unsigned int length)
{
    Message* ret = NULL;
    MsgParser* p = (MsgParser *)parser;
    
    if (p && mem && length) {
        if (p->header == 0) {    // 解析头部
            if (p->need <= length) {
                memcpy(&p->cache, mem, p->need);

                p->cache.type   = ntohs(p->cache.type);
                p->cache.cmd    = ntohs(p->cache.cmd);
                p->cache.index  = ntohs(p->cache.index);
                p->cache.total  = ntohs(p->cache.total);
                p->cache.length = ntohl(p->cache.length);
                
                mem += p->need;
                length -= p->need;

                p->header = 1;  // 头部解析完成
                p->need = p->cache.length;

                ret = MParser_ReadMem(p, mem, length);
            }
        } else {
            if (p->msg == NULL) {
                p->msg = malloc(sizeof(p->cache) + p->need);

                if (p->msg != NULL)
                    *p->msg = p->cache;
            } 
            
            if (p->msg != NULL) {
                unsigned int len = (p->need < length) ? p->need : length;
                unsigned int offset = p->msg->length - p->need;

                memcpy(p->msg->payload, mem, len);

                p->need -= len;
            }

            if (p->need == 0) {    // 没有可读字节
                ret = p->msg;

                p->msg = NULL;

                MParser_Reset(p);
            }
        }
    }

    return ret;
}

Message* MParser_ReadFd(MParser* parser, int fd)
{

}

void MParser_Reset(MParser* parser)
{
    MsgParser* p = (MsgParser *)parser;

    if (p != NULL) {
        p->header = 0;
        p->need = sizeof(p->cache);

        if (p->msg)
            free(p->msg);

        p->msg = NULL;
    }
}

void MParser_Del(MParser* parser)
{
    MsgParser* p = (MsgParser *)parser;

    if (p != NULL) {
        if (p->msg)
            free(p->msg);
        free(p);
    }
}

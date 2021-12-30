#ifndef MSG_PARSE_H
#define MSG_PARSE_H

#include "message.h"

typedef void MParser;

MParser* MParser_New();
Message* MParser_ReadMem(MParser* parser, unsigned char* mem, unsigned int length);
Message* MParser_ReadFd(MParser* parser, int fd);
void MParser_Reset(MParser* parser);
void MParser_Del(MParser* parser);

#endif

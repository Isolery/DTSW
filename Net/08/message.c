#include "message.h"
#include <malloc.h>
#include <string.h>

Message* Message_New(unsigned short type, unsigned short cmd, unsigned short index, 
                     unsigned short total, unsigned int length, const char* payload)
{
    Message* ret = malloc(sizeof(Message) + length);

    if(ret != NULL){
        ret->type = type;
        ret->cmd = cmd;
        ret->index = index;
        ret->total = total;
        ret->length = length;

        if(payload != NULL){
            memcpy(ret+1, payload, length);
        }
    }

    return ret;
}
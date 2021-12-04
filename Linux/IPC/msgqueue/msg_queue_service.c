#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include "sys/shm.h"

struct mymesg{
	long int mtype;
	char mtext[512];
};

#define SHARED_BUFFER_SIZE 16200*4

typedef struct
{
    int pid;                             // 0表示可写 ，非0表示不可写
    unsigned char rgb_data[SHARED_BUFFER_SIZE];    
} shared_user_st;

shared_user_st *shared_user = NULL;

key_t shm = 0;
key_t msg = 0;

int shmid;
int msg_id = 0;

struct amsgbuf{
	long int type;
	char text[128];
};

struct amsgbuf arecvmsg;
struct amsgbuf asendmsg;

int main()
{
	shm = ftok("/tmp/myshm",'a');

    if(shm < 0){
        printf("creat key failure\n");
        return -1;
    }

    printf("creat key sucess\n");

    shmid = shmget((key_t)shm, sizeof(shared_user_st), IPC_CREAT | 0777);
    if(shmid < 0){
        printf("creat share memory failure\n");
        return -1;
    }

    printf("creat share memory sucess shmid=%d\n",shmid);

    shared_user = (shared_user_st *)shmat(shmid,NULL,0);
    if(shared_user == NULL){
	   printf("parent process:shmat function failure\n");
	   return -3;
    }

    msg = ftok("/tmp/mymsg",'a');
    msg_id = msgget(msg, 0666 | IPC_CREAT);

	if(msg_id == -1){
		printf("open msg error \n");
		return 0;
	}

    printf("create msg success, msg_id=%d\n", msg_id);

	while(1)
	{
		static int i = 0;
		shared_user->rgb_data[0] = i++;
		
		do
		{
			memset(&asendmsg, 0, sizeof(asendmsg));
			asendmsg.type = 100; 
			memcpy(asendmsg.text, "start", 5);

			if(msgsnd(msg_id, (void *)&asendmsg, 128, 0) < 0){
				printf("send msg error \n");
				continue;
			}

			printf("service msgsnd success\n");

			memset(&arecvmsg, 0, sizeof(arecvmsg));
			arecvmsg.type = 200; 

			if(msgrcv(msg_id, (void *)&arecvmsg, 128, arecvmsg.type, 0) < 0){
				printf("receive msg error \n");
				break;
			}

			if((strncmp(arecvmsg.text, "OK", 2) == 0)){
				printf("service msgrecv ok\n");
				break;
			}else{
				continue;
			}
		}while(1);
	}

	return 0;
}

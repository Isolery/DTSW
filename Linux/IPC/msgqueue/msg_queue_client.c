#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct msgbuf{
	long int type;
	char text[128];
};

int main()
{
	int id = 0;
	struct msgbuf recvmsg;
	struct msgbuf sendmsg;

	key_t key_msg = ftok("/tmp/mymsg",'a');
	id = msgget(key_msg, 0666 | IPC_CREAT);

	if(id == -1){
		printf("open msg error \n");
		return 0;
	}

	while(1)
	{
		do
		{
			memset(&recvmsg, 0, sizeof(recvmsg));
			recvmsg.type = 100; 

			if(msgrcv(id, (void *)&recvmsg, 128, recvmsg.type, 0) < 0){
				printf("receive msg error \n");
				break;
			}
		}while(!(strncmp(recvmsg.text, "start", 5) == 0));

		memset(&sendmsg, 0, sizeof(sendmsg));
		sendmsg.type = 200;
		memcpy(sendmsg.text, "ok", 2);

		if(msgsnd(id, (void *)&sendmsg, 128, 0) < 0){
			printf("send msg error \n");
			return 0;
		}
	}

	if(msgctl(id, IPC_RMID, NULL) < 0){
		printf("del msg error \n");
		return 0;
	}

	return 0;
}
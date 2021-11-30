#include "sys/types.h"
#include "sys/shm.h"
#include "signal.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

#define SHARED_BUFFER_SIZE 16200*4

typedef struct
{
    int pid;                              // 0表示可写 ，非0表示不可写
    char rgb_data[SHARED_BUFFER_SIZE];    
} shared_user_st;

shared_user_st *shared_user;

int shmid;

struct mybuf
{
	int pid;
	char buf[124];
};

void myfun(int signum)
{
	return ;
}

static void atexit_handler(void)
{
	shmdt(shared_user);
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m"); 

	printf("atexit_handler\n");
}

void handler(int signum)
{
	exit(0);
}

int main()
{
	int key;
	
	int pid;

	key = ftok("/tmp/shm_signal",'a');
	if(key < 0){
		printf("creat key failure\n");
		return -1;
	}

	printf("creat key sucess\n");

	shmid = shmget((key_t)key, sizeof(shared_user_st), IPC_CREAT | 0777);
	if(shmid < 0){
		printf("creat share memory failure\n");
		perror("shmget error");
		return -1;
	}

	printf("creat share memory sucess shmid=%d\n",shmid);

	atexit(atexit_handler);

	signal(SIGINT, handler);
	signal(SIGUSR2, myfun);

	shared_user = (shared_user_st *)shmat(shmid, NULL, 0);
	if(shared_user == NULL){
		printf("parent process:shmat function failure\n");
		return -3;
	}

	//get client pid
	shared_user->pid = getpid();  //write server pid to share memory

	pause();   //wait client read server pid;
	
	pid = shared_user->pid;

	printf("client pid = %d\n", pid);

	//write

	while(1)
	{
		//write share memory
		printf("parent process start write share memory:\n");
		fgets(shared_user->rgb_data, 128, stdin);
		kill(pid, SIGUSR1);   // client process read data 
		pause();              // wait client process read
	}

	shmdt(shared_user);
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m");

	return 0;
}

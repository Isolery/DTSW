#define _GNU_SOURCE
#include <signal.h>
#include "signal_functions.h"
#include "tlpi_hdr.h"

static int sigCnt[NSIG];      
static volatile sig_atomic_t gotSigint = 0;

static void handler(int sig)
{
    if (sig == SIGINT)
        gotSigint = 1;
    else
        sigCnt[sig]++;
}

int main(int argc, char *argv[])
{
    int n, numSecs;
    sigset_t pendingMask, blockingMask, emptyMask;

    printf("%s: PID is %ld\n", argv[0], (long) getpid());

    // 为所有的信号添加处理函数
    for (n = 1; n < NSIG; n++)
    {
        (void) signal(n, handler);
    }

    if (argc > 1) {
        numSecs = getInt(argv[1], GN_GT_0, NULL);

        // 将blockingMask全部置位，即阻塞所有信号
        sigfillset(&blockingMask);
        if (sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1)
            errExit("sigprocmask");

        printf("%s: sleeping for %d seconds\n", argv[0], numSecs);
        sleep(numSecs);

        // 检测哪些信号被置位了，存放在pendingMask中
        if (sigpending(&pendingMask) == -1)
            errExit("sigpending");

        printf("%s: pending signals are: \n", argv[0]);
        printSigset(stdout, "\t\t", &pendingMask);  

        // 解除所有信号的阻塞
        sigemptyset(&emptyMask);
        if (sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1)
            errExit("sigprocmask");
    }

    while (!gotSigint)
        continue;

    for (n = 1; n < NSIG; n++)
        if (sigCnt[n] != 0)
            printf("%s: signal %d caught %d time%s\n", argv[0], n, sigCnt[n], (sigCnt[n] == 1) ? "" : "s");

    exit(EXIT_SUCCESS);
}
/*
 * @Author: Human0722
 * @Date: 2020-12-04 20:29:25
 * @LastEditTime: 2020-12-04 21:53:49
 * @FilePath: /c_demo/SIGNAL/02_handlesignal_d/handlesignal.c
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sighandler(int sig) {
    switch(sig) {
        case SIGUSR1:
            printf("hello, SIGUSR1\n");
            break;
        case SIGUSR2:
            printf("hello, SIGUSR2\n");
            break;
        case SIGINT:
            printf("You can not kill me\n");
            break;
        case SIGTSTP:
            printf("You can not stop me\n");
            break;
        case SIGQUIT:
            printf("You can not quit ever\n");
            break;
        case SIGSEGV:
            printf("ooops, sth error\n");
            break;
        case SIGKILL:
            printf("handle signal SIGKILL\n");
            break;
        case SIGSTOP:
            printf("handle signal SIGSTOP\n");
            break;
        default:
            printf("hello, who are you %d?", sig);
    }
}

int main(void) {
    printf("I'm [ %d ]\n", getpid());

    if(SIG_ERR == signal(SIGUSR1, sighandler)) {
        perror("signal SIGUSR1");
    }
    if(SIG_ERR == signal(SIGUSR2, sighandler)) {
        perror("signal SIGUSR2");
    }
    if(SIG_ERR == signal(SIGINT, sighandler)) {
        perror("signal SIGINT");
    }
    if(SIG_ERR == signal(SIGTSTP, sighandler)) {
        perror("signal SIGTSTP");
    }
    if(SIG_ERR == signal(SIGQUIT, sighandler)) {
        perror("signal SIGQUIT");
    }
    if(SIG_ERR == signal(SIGSEGV, sighandler)) {
        perror("signal SIGSEGV");
    }
    /* try to catch SIGKILL and SIGSTOP */
    if(SIG_ERR == signal(SIGKILL, sighandler)) {
        perror("signal SIGKILL");
    }
    if(SIG_ERR == signal(SIGSTOP, sighandler)) {
        perror("signal SIGSTOP");
    }
    /* }}} try to catch SIGKILL and SIGSTOP */

    while(1) {
        write(STDOUT_FILENO, ".", 1);
        sleep(5);
    }
    return 0;
}


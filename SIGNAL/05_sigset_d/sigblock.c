/*
 * @Author: Human0722
 * @Date: 2020-12-07 13:29:59
 * @LastEditTime: 2020-12-07 13:56:01
 * @FilePath: /c_demo/SIGNAL/05_sigset_d/sigblock.c
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void printsigset(const sigset_t *set) 
{
    int i;
    for(i = 1; i <= 64; i++) {
        if(i == 33) putchar(' ');
        if(sigismember(set, i) == 1) {
            putchar('1');
        }else {
            putchar('0');
        }
    }
    puts("");
}

void handler(int sig) 
{
    if(sig == SIGINT) printf("hello, SIGINT\n");
    if(sig == SIGQUIT) printf("hello, SIGQUIT\n");
}

int main(void) 
{
    /* output pid */
    printf("I'm %d\n", getpid());

    /* block some signal */
    sigset_t st, oldset;
    sigemptyset(&st);
    sigaddset(&st, SIGINT);
    sigaddset(&st, SIGQUIT);
    sigprocmask(SIG_BLOCK, &st, &oldset);
    printf("new set: ");
    printsigset(&st);
    printf("old set: ");
    printsigset(&oldset);
    /* register signal handler function */
    if(SIG_ERR == signal(SIGINT, handler)) {
        perror("signal SIGINT");
        exit(1);
    }

    if(SIG_ERR == signal(SIGQUIT, handler)) {
        perror("signal SIGQUIT");
        exit(1);
    }

    puts("");

    int n = 0;

    while(1) {
        sigpending(&st);
        printsigset(&st);
        puts("");
        sleep(1);

        if(n == 10) {
            sigset_t tmp;
            sigemptyset(&tmp);
            sigaddset(&tmp, SIGINT);
            sigprocmask(SIG_UNBLOCK, &tmp, NULL);
        }
         ++n;
    }
    return 0;
}


/*
 * @Author: your name
 * @Date: 2020-12-07 17:06:47
 * @LastEditTime: 2020-12-07 21:38:06
 * @FilePath: /c_demo/SIGNAL/06_sigaction_d/sigaction.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

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
    if(sig == SIGTSTP) printf("hello, SIGTSTP\n");
    if(sig == SIGINT) printf("hello, SIGINT\n");
    sleep(5);
    sigset_t st;
    sigpending(&st);
    printsigset(&st);
}

int main(void) 
{
    /* output pid */
    printf("I'm %d\n", getpid());

    /* Variable statemeng */
    struct sigaction act, oldact;
    
    /* setting  singal handle function*/
    act.sa_handler = handler;

    /* add SIGINT to sa_mask */
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);
    act.sa_flags = 0;

    sigaction(SIGTSTP, &act, &oldact);
    sigaction(SIGINT, &act, &oldact);

    while(1) {
        write(STDOUT_FILENO, ".", 1);
        pause();
    }
    return 0;
}

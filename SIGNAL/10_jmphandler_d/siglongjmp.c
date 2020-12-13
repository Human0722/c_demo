/*
 * @Author: Human0722
 * @Date: 2020-12-13 22:46:57
 * @LastEditTime: 2020-12-13 23:33:04
 * @FilePath: /c_demo/SIGNAL/10_jmphandler_d/siglongjmp.c
 */

#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>

jmp_buf jmpbuf;

void printBlock()
{
    sigset_t block;
    sigprocmask(SIG_BLOCK, NULL, &block);
    printf("block:");
    if (sigismember(&block, SIGQUIT)) printf("SIGQUIT, ");
    if (sigismember(&block, SIGALRM)) printf("SIGALRM\t");
    puts("");
}

void handler(int sig)
{
    if (sig == SIGQUIT) printf("SIGQUIT, ");
    if (sig == SIGALRM) printf("SIGALRM, ");
    printBlock();
    longjmp(jmpbuf, 1);
    puts("----------------------------------");

}

int main(void)
{
    printf("I'm %d\n", getpid());
    signal(SIGQUIT, handler);
    signal(SIGALRM, handler);
    printf("before signal, ");
    printBlock();

    if (sigsetjmp(jmpbuf, 1) != 0) {
        printf("jump to here!");
        printBlock();
        puts("================================");
    }
    while(1) {
        pause();
    }
    return 0;
}

/*
 * @Author: Human0722  
 * @Date: 2020-12-07 10:00:39
 * @LastEditTime: 2020-12-07 12:42:08
 * @FilePath: /c_demo/SIGNAL/05_sigset_d/printfsig.c
 */
#include <stdio.h>
#include <signal.h>

void printsigset(const sigset_t *set) 
{
    int i;
    for(i = 1; i <= 64; i++) {
        if(i == 33) putchar(' ');
        if(sigismember(set ,i) == 1)
            putchar('1');
        else
            putchar('0'); 
    }
    puts("");
}

int main(void) {
    /* output sigset_t content */
    sigset_t set;
    printsigset(&set);

    /* verify sigset_t is 64 bit length */
    unsigned int test[2] =  {0xf0f0f0f0, 0xf0f0f0f0};
    printsigset((sigset_t *)test);

    /* fill sigset_t with 1 */
    sigfillset(&set);
    printf("Already fill sigset_t with 1\n");
    printsigset(&set);

    /* empty sigset_t with 0 */
    sigemptyset(&set);
    printf("Already fill sigset_t with 0\n"); 
    printsigset(&set);

    /* set sig bit 1 */
    printf("Already fill some sigset_t with 1\n");
    sigaddset(&set, SIGCHLD);
    sigaddset(&set, SIGKILL);
    printsigset(&set);

    /* search some key */
    if(sigismember(&set, SIGKILL)) {
        printf("SIGKILL exists!\n");
    }
    
    /* delete some key */
    printf("Delete key: SIGKILL\n");
    sigdelset(&set, SIGKILL);
    printsigset(&set);

    return 0;
}

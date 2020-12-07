/*
 * @Author: Human0722
 * @Date: 2020-12-05 22:54:10
 * @LastEditTime: 2020-12-05 22:57:30
 * @FilePath: /c_demo/SIGNAL/04_alarm_f/persecond.c
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    if(sig == SIGALRM) {
        printf("Boom~\n");
    }
}

int main(void) {
    /* register signal handle function */
    if(SIG_ERR == signal(SIGALRM, handler)) {
        perror("signal");
    }
    int remain = 5;

    while(1) {
        remain = alarm(5);
        sleep(5);        
    }
    return 0;
}

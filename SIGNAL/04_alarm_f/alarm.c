/*
 * @Author: Human0722
 * @Date: 2020-12-05 22:42:59
 * @LastEditTime: 2020-12-05 22:51:29
 * @FilePath: /c_demo/SIGNAL/04_alarm_f/alarm.c
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
   if(SIG_ERR == signal(SIGALRM, handler)) {
       perror("signal SIGALRM");
   } 

    unsigned int remain = 0;
    remain = alarm(5);
    printf("the previous alarm remain %d seconds\n", remain);
    sleep(3);
    remain = alarm(3);
    printf("the previous alarm remain %d seconds\n", remain);
    

    while(1) {
        write(STDOUT_FILENO, ".", 1);
        pause();
    }


   return 0;
}

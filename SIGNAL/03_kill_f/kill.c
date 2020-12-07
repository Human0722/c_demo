/*
 * @Author: Human0722
 * @Date: 2020-12-05 20:30:30
 * @LastEditTime: 2020-12-05 21:00:12
 * @FilePath: /c_demo/SIGNAL/03_kill_f/kill.c
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    if(sig == SIGUSR1) {
        printf("hello, my child\n");
    }
    else if(sig == SIGCHLD) {
        wait(NULL);
    }
}

void child() {
    int n = 10;
    while(n--) {
        if(kill(getppid(), SIGUSR1) == -1) {
            perror("kill");
        }
        sleep(1);
    }
    exit(0);
}

int main(void) {
    if(SIG_ERR == signal(SIGUSR1, handler)) {
        perror("signal SIGUSR1\n");
    }
    if(SIG_ERR == signal(SIGCHLD, handler)) {
        perror("signal SIGCLD\n");
    }

    pid_t pid = fork();

    if(pid == 0) child();
    else if(pid == -1) {
        perror("fork");
        exit(1);
    }

    while(1) {
        write(STDOUT_FILENO, ".", 1);
        sleep(5);
    }
    
    return 0;
}
/*
 * @Author: Human0722
 * @Date: 2020-12-01 21:40:18
 * @LastEditTime: 2020-12-01 23:47:36
 * @FilePath: /c_demo/PROCESS/04_defunct_d/mywait.c
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    printf("Before fork~\n");

    pid_t pid, n = 5;

    while(n--) {
        pid = fork();
        if(pid == 0) break;     // prevent child process loop
        else if (pid < 0) {
            perror("fork");
            return 1;
        }
    }

    /* child just output one line */
    if(pid == 0) {
        printf("hello, I'm child %d; my father is %d\n", getpid(), getppid());
        return 0;
    }

    /* parent keep printing ... */
    while(1) {
        sleep(3);
        pid = wait(NULL);   // Ignore signal
        if(pid == -1) {
            perror("wait");
            printf("I'm father %d; I have wiped out all zombies\n", getpid());
            exit(1);
        }
        printf("hello, I'm father %d\n", getpid());
    }

    return 0;
}

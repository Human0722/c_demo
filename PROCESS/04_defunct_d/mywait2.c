/*
 * @Author: your name
 * @Date: 2020-12-03 13:52:41
 * @LastEditTime: 2020-12-03 14:00:54
 * @FilePath: /c_demo/PROCESS/04_defunct_d/mywait2.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void) {
    pid_t pid;
    int n = 5;
    printf("Before fork\n");
    
    while(n) {
        pid = fork();
        if(pid == 0) break;
        else if(pid < 0) {
            perror("fork");
            exit(1);
        }
        n--;
    }

    if(pid == 0) {
        printf("I'm child %d, my father is %d\n", getpid(), getppid());
        exit(1);
    }

    while(1) {
        sleep(3);
        pid = wait(NULL);
        if(pid == -1) {
            /* no child process, means wait task finish */
            printf("I'm father %d, I have clear all zombie\n", getpid());
            
            exit(1);
        }
        printf("I'm father %d, child process %d exit!\n", getpid(), pid);
        
    }
   return 0; 
}

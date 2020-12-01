/*
 * @Author: Human0722
 * @Date: 2020-12-01 21:18:46
 * @LastEditTime: 2020-12-01 21:23:48
 * @FilePath: /c_demo/PROCESS/03_exec_f/forkAndExec.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    char *argv[] = {"ls", "-l", NULL};
    pid_t pid = fork();
 
    if(pid > 0) {
        /* parent process */
        printf("This message comes from parent process!\n");
    }else if(pid == 0) {
        /* child process */
        printf("This message comes from child precess!\n");
        if(execvp("ls", argv) == -1) {
            perror("evecvp");
            exit(1);
        }
    }else {
        perror("fork");
        exit(1);
    }
    return 0;
}

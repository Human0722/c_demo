/*
 * @Author: Human-722
 * @Date: 2020-11-29 16:44:29
 * @FilePath: /c_demo/PROCESS/02_fork_f/fork.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    pid_t pid;
    char *buf = "I'm father process!\n";
    write(STDOUT_FILENO, buf, strlen(buf));
    printf("Before fork~\n");

    pid = fork(); 

    if(!pid)
    {
        printf("I'm child process, pid is %d, my father's pid is %d\n", getpid(), getppid());   
        sleep(3);
    }
    else if(pid > 0)
    {
        printf("I'm father process, pid is %d, my child's pid is %d\n", getpid(), pid);
        /* try to not sleep, get different result */
        sleep(3);
    }
    else
    {
        perror("fork");
        exit(1);
    }
    
    return 0;
}

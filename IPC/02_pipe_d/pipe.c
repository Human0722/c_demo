/*
 * @Author: Human0722
 * @Date: 2020-12-16 20:50:26
 * @LastEditTime: 2020-12-16 21:35:27
 * @FilePath: /c_demo/IPC/02_pipe_d/pipe.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

void child(int fd[])
{
    int n, i;
    char buf[64];
    close(fd[1]);

    while(1) {
        n = read(fd[0], buf, 64);
        for(i = 0; i < n; ++i) putchar(toupper(buf[i]));
        /*  quit condition */
        if(*buf == 'q') {    //if word start with q
            close(fd[0]);
            exit(1);
        }
        if(n == 0) {
            printf("no data now! Retry after 2 second!\n");
            sleep(2);
        }
    }
    exit(1); 
}

int main(int argc, char *argv[]) 
{
    int fd[2];
    int n;
    char buf[64];
    
    if(pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if(pid == 0) {
        child(fd);
    }

    close(fd[0]);

    while(1) {
        n = read(STDIN_FILENO, buf, 64);
        write(fd[1], buf, n);
        if (*buf == 'q') {
            close(fd[1]);
            exit(1);
        }
    }
    return 0;
}


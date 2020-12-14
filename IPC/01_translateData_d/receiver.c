/*
 * @Author: Human0722
 * @Date: 2020-12-14 15:50:18
 * @LastEditTime: 2020-12-14 22:52:34
 * @FilePath: /c_demo/IPC/01_translateData_d/receiver.c
 */
#include "header.h"

void handler(int sig)
{
    char buf[64];
    int i;
    int fd = open("tmp", O_RDONLY);
    if (fd < 0) {
        perror("open tmp");
        return;
    }

    int n = 0;
    if ((n = read(fd, buf, 64)) < 0) {
        perror("read tmp");
        close(fd);
        return ;
    }
    close(fd);
    unlink("tmp");

    printf("hit handler\n");
    /* output content of buf */
    buf[n] = '\0';
    printf("%s", buf);
    //if(*buf == 'q') exit(0);
}

int main(void)
{
    printf("I'm receiver %d\n", getpid());
    
    /* register signal handle function */
    struct sigaction act;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if(sigaction(SIGUSR1, &act, NULL) < 0) {
        perror("sigaction");
        exit(1);
    }

    while(1) pause();
}

/*
 * @Author: Human0722 
 * @Date: 2020-12-16 22:39:33
 * @LastEditTime: 2020-12-16 23:34:55
 * @FilePath: /c_demo/IPC/03_named_pipe_d/sender.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int n;
    char buf[64];

    int fd = open("/root/hello", O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    printf("Receiver is online!\n");

    while(1)
    {
        n = read(STDIN_FILENO, buf, 64);
        write(fd, buf, n);
        if(*buf == 'q') {
            close(fd);
            exit(1);    
        }
    }

    return 0;
}

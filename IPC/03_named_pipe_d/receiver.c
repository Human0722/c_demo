/*
 * @Author: Human0722   
 * @Date: 2020-12-16 22:39:38
 * @LastEditTime: 2020-12-16 23:38:29
 * @FilePath: /c_demo/IPC/03_named_pipe_d/receiver.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
    int n, i;
    char buf[64];
    int fd = open("/root/hello", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    printf("Sender is online!\n");

    while(1) {
        n =  read(fd, buf, 64); 
        for(i = 0; i < n; ++i) putchar(toupper(buf[i])); 
        if(*buf == 'q') {
            close(fd);
            exit(1);    
        }
    }
    return 0;
}

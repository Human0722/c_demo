/*
 * @Author: Human0722
 * @Date: 2020-12-01 16:06:13
 * @LastEditTime: 2020-12-01 16:29:00
 * @FilePath: /c_demo/PROCESS/02_fork_f/fork_mem.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int fd = open("mem_test.txt", O_WRONLY | O_CREAT, 0664);
    if(fd == -1) {
        perror("open");
        exit(1);
    }
    printf("I'm father!\n");
    printf("Before fork~\n");

    pid_t pid = fork();

    if(pid > 0) {
        /* parent process */
        sleep(3);
        printf("I'm father, I'm writing mem_test.txt...\n");
        write(fd, "hello", 5);
        close(fd);

    }else if(pid == 0) {
        /* Child process */
        printf("I'm child, I'm writing mem_test.txt...\n");
        write(fd, "world", 5);  // will it write content to file directly? 
        sleep(5);
        write(fd, "lalala", 6);
        close(fd);
    }else {
        perror("fork");
        exit(1);
    }
    return 0;
}

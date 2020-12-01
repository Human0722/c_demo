/*
 * @Author: Human0722
 * @Date: 2020-12-01 16:35:11
 * @LastEditTime: 2020-12-01 16:59:22
 * @FilePath: /c_demo/PROCESS/03_exec_f/execvp.c
 */

#include <stdio.h>
#include <unistd.h>


int main(void) {
    char *argv[] = {"ls", "-l", NULL};
    if(execvp("ls", argv) == -1) {
        perror("exec");
        return 1;
    }
    printf("hello\n");
    return 0;
}

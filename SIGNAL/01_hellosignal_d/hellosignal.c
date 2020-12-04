/*
 * @Author: your name
 * @Date: 2020-12-03 15:31:48
 * @LastEditTime: 2020-12-03 15:33:54
 * @FilePath: /c_demo/SIGNAL/01_hellosignal_d/hellosignal.c
 */
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("I'm main process, pid: [ %d ].\n", getpid());

    while(1) {
        sleep(10);
        write(STDOUT_FILENO, ".", 1);
    }

    return 0;
}
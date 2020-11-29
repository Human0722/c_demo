/*
 * @Author: your name
 * @Date: 2020-11-29 16:23:22
 * @FilePath: /c_demo/PROCESS/01_getpid_f/getpid.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("Pid: %d\n", pid);
    printf("Ppid: %d\n", ppid);
    sleep(3);
    return 0;
}

/*
 * @Author: Human0722
 * @Date: 2020-12-18 23:02:12
 * @LastEditTime: 2020-12-18 23:18:11
 * @FilePath: /c_demo/IPC/04_shm_d/a.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(void)
{
    /* shm id is 0x8888 */
    int id = shmget(0x8888, 4096, IPC_CREAT | IPC_EXCL | 0664);
    if(id < 0) {
        perror("shmget");
        exit(1);
    }
    printf("id = %d.\n", id);

    char *buf = shmat(id, NULL, 0);
    if (buf == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    strcpy(buf, "hello,share memory!\n");

    if(shmdt(buf) < 0) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}

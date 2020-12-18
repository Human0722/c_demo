/*
 * @Author: Human0722
 * @Date: 2020-12-18 23:02:16
 * @LastEditTime: 2020-12-18 23:19:39
 * @FilePath: /c_demo/IPC/04_shm_d/b.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(void)
{
    /* get id, param2 and param3 be 0 */
    int id = shmget(0x8888, 0, 0);
    if (id < 0) {
        perror("shmget");
        exit(1);
    }
    printf("id = %d.\n", id);

    char *buf = shmat(id, NULL, 0);
    if (buf == (char*)-1) {
        perror("shmat");
        exit(1);
    }
    printf("%s", buf);

    if (shmdt(buf) < 0) {
        perror("shmdt");
        exit(1);
    }
    
    /* delete kernal object */
    if(shmctl(id, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(1);
    }
    return 0;
}
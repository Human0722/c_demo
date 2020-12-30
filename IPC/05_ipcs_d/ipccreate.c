/*
 * @Author: Human0722
 * @Date: 2020-12-19 21:15:19
 * @LastEditTime: 2020-12-19 21:26:20
 * @FilePath: /c_demo/IPC/05_ipcs_d/ipccreate.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("%s <ipc type> <key>");
        return -1;
    }

    /* define variable */
    key_t key = strtoll(argv[2], NULL, 16);
    char type = argv[1][0];
    char buf[64];
    int id;

    if (type == '0') {
        id = shmget(key, 4096, IPC_CREAT | IPC_EXCL | 0644);
        strcpy(buf, "share memory");
    }
    else if (type == '1') {
        id = msgget(key, IPC_CREAT | IPC_EXCL | 0644);
        strcpy(buf, "message queue");
    }
    else if (type == '2') {
        id = semget(key, 5, IPC_CREAT | IPC_EXCL | 0644);
        strcpy(buf, "semaphore");
    }
    else {
        printf("type must be 0, 1, or 2!\n");
        return -1;
    }
    
    printf("create %s at 0x%x, id = %d\n", buf, key ,id);
    
    return 0;
}

/*
 * @Author: Human0722
 * @Date: 2020-12-19 21:26:41
 * @LastEditTime: 2020-12-19 22:12:10
 * @FilePath: /c_demo/IPC/05_ipcs_d/ipcget.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>


int main(int argc, char *argv[]) 
{
    if (argc < 3) {
        printf("%s <ipc type> <key>\n", argv[0]);
        return -1;
    }

    key_t key = strtoll(argv[2], NULL, 16);
    char type = argv[1][0];
    char buf[64];
    int id;

    if (type == '0') {
        id = shmget(key, 0, 0);
        strcpy(buf, "share memory");
    }
    else if (type == '1') {
        id = msgget(key, 0);
        strcpy(buf, "message queue");
    }
    else if (type == '2') {
        id = semget(key, 0, 0);
        strcpy(buf, "semaphore");
    }
    else {
        printf("type must be 0, 1 or 2.\n");
        return -1;
    }

    if (id < 0) {
        perror("get error");
        return -1;
    }
    
    printf("get %s at 0x%x, id = %d\n", buf, key, id);
     
    return 0;
}
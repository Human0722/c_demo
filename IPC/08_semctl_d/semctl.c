/*
 * @Author: Human0722
 * @Date: 2020-12-30 15:45:40
 * @LastEditTime: 2020-12-30 20:20:15
 * @FilePath: /c_demo/IPC/08_semctl_d/semctl.c
 */
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define R0 0
#define R1 1 
#define R2 2

void printSem(int id) {
    unsigned short vals[3] = { 0 };
    semctl(id, 3, GETALL, vals);
    printf("R0 = %d, R1 = %d, R2 = %d\n\n", vals[0], vals[1], vals[2]);
}

int main() {
    int id = semget(0x8888, 3, IPC_CREAT | IPC_EXCL | 0664);
    
    // 打印信号量的值
    puts("信号量的初始值(默认值)");
    printSem(id);

    // 1.设置第2个信号量值
    puts("1. 设置第二个信号量(R2)的值为20");
    semctl(id, 2, SETVAL, 20);
    printSem(id);

    // 2. 同时设置3个信号量的值
    puts("2. 同时设置三个信号量的值为 12, 5 9");
    unsigned short vals[3] = {12, 5, 9};
    semctl(id, 0, SETALL, vals);
    printSem(id);

    // 3. 请求 2 个 R0 资源
    puts("3. 请求两个 R0 资源");
    struct sembuf op1 = {0, -2, 0};
    semop(id, &op1, 1);
    printSem(id);

    //4. 请求3个R1 和 5个R2
    puts("4. 请求3个R1和5个R2");
    struct sembuf ops1[2] = {
        {1, -3, 0},
        {2, -5, 0}
    };
    semop(id, ops1, 2);
    printSem(id);

    // 5. 释放两个R1
    puts("5. 释放两个R1");
    struct sembuf op2 = {1, 2, 0};
    semop(id, &op2, 1);
    printSem(id);

    //6. 释放1个R0,1个R1,3个R2
    puts("6. 释放1个R0,一个R1,三个R2");
    struct sembuf ops2[3] = {
        {0, 1, 0},
        {1, 1, 0},
        {2, 3, 0}
    };
    semop(id, ops2, 3);
    printSem(id);

    // 7.删除IPC内核对象
    puts("7. 删除IPC内核对象");
    semctl(id, 0, IPC_RMID);

    return 0;
}

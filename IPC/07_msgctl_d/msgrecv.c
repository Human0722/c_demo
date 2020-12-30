/*
 * @Author: Human0722
 * @Date: 2020-12-30 14:37:39
 * @LastEditTime: 2020-12-30 14:50:55
 * @FilePath: /c_demo/IPC/07_msgctl_d/msgrecv.c
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define ASSERT(prompt, res) if ((res) < 0) {perror(#prompt);exit(-1);}

typedef struct {
    char name[20];
    int age;
}Person;

typedef struct {
    long type;
    Person person;
}Msg;

void printMsg(Msg *msg) {
    printf("{ type = %ld, name = %s, age = %d }\n",
        msg->type, msg->person.name, msg->person.age);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <type> \n", argv[0]);
        return -1;
    }

    // 要获取的消息类型
    long type = atol(argv[1]);

    // 获取 ipc 内核对象id
    int id = msgget(0x8888, 0);

    // 如果错误就退出
    ASSERT(msgget, id);

    Msg msg;
    int res;

    while(1) {
        // 以阻塞的方式接受类型为 type 的消息
        res = msgrcv(id, &msg, sizeof(Person), type, IPC_NOWAIT);
        if (res < 0) {
            // 如果消息接受完毕就退出，否则报错并退出
            if (errno == ENOMSG) {
                printf("No message!\n");
                break;
            }
            else {
                ASSERT(msgrcv, res);
            }
        }
        // 打印消息内容
        printMsg(&msg);
    }
    return 0;
}
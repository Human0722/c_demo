/*
 * @Author: Human0722
 * @Date: 2020-12-30 10:28:43
 * @LastEditTime: 2020-12-30 10:50:10
 * @FilePath: /c_demo/IPC/06_shmctl_d/shmctl.c
 */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT(res) if((res) < 0){perror(__FUNCTION__);exit(-1);}

// print ipc_perm
void printPerm(struct ipc_perm *perm) {
    printf("euid of owner = %d\n", perm->uid);
    printf("egid of owner = %d\n", perm->gid);
    printf("euid of creator = %d\n", perm->cuid);
    printf("egid of creator = %d\n", perm->cgid);
    printf("mode = 0%x\n", perm->mode);
}

// print ipc info
void printShmid(struct shmid_ds *shmid) {
    printPerm(&shmid->shm_perm);
    printf("segment size = %d\n", shmid->shm_segsz);
    printf("last attach time = %s", ctime(&shmid->shm_atime));
    printf("last detach time = %s", ctime(&shmid->shm_dtime));
    printf("last change time = %s", ctime(&shmid->shm_ctime));
    printf("pid of creator = %d\n", shmid->shm_cpid);
    printf("pid of last shmat/shmdt = %d\n", shmid->shm_lpid);
    printf("NO. of creent attaches = %ld\n", shmid->shm_nattch);
}

// create ipc
void create() {
    int id = shmget(0x8888, 123, IPC_CREAT | IPC_EXCL | 0664);
    printf("create %d\n", id);
    ASSERT(id);
}

// IPC_STAT command
void show() {
    int id = shmget(0x8888, 0, 0);
    ASSERT(id);
    struct shmid_ds shmid;
    ASSERT(shmctl(id, IPC_STAT, &shmid));
    printShmid(&shmid);
}

// IPC_SET  command
void set() {
    int id = shmget(0x8888, 123, IPC_STAT | 0664);
    ASSERT(id);
    struct shmid_ds shmid;
    ASSERT(shmctl(id, IPC_STAT, &shmid));
    shmid.shm_perm.mode = 0600;
    ASSERT(shmctl(id, IPC_SET, &shmid));
    printf("set %d\n", id);
}

// IPC_RMID command
void rm() {
    int id = shmget(0x8888, 123, IPC_CREAT | 0664);
    ASSERT(id);
    ASSERT(shmctl(id, IPC_RMID, NULL));
    printf("remove %d\n", id);
}

// install and uninstall
void at_dt() {
    int id = shmget(0x8888, 123, IPC_CREAT | 0664);
    char *buf = shmat(id, NULL, 0);
    if (buf == (char *)-1) ASSERT(-1);
    printf("shmat %p\n", buf);
    sleep(5);   // wait for 5s
    ASSERT(shmdt(buf));
    printf("shmdt %p\n", buf);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <option -c -v -s -d -a>\n", argv[0]);
        return -1;
    }

    printf("I'm %d\n", getpid());

    if(!strcmp(argv[1], "-c")) {
        create();
    }
    else if (!strcmp(argv[1], "-v")) {
        show();
    }
    else if(!strcmp(argv[1], "-s")) {
        set();
    }
    else if(!strcmp(argv[1], "-d")) {
        rm();
    }
    else if(!strcmp(argv[1], "-a")) {
        at_dt();
    }

    return 0;
}









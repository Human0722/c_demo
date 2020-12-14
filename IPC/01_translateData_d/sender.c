/*
 * @Author: Human0722 
 * @Date: 2020-12-14 15:39:42
 * @LastEditTime: 2020-12-14 23:03:54
 * @FilePath: /c_demo/IPC/01_translateData_d/sender.c
 */
#include "header.h"


int main(int argc, char *argv[])
{
    /* get recevier */
    if (argc < 2) {
        perror("missing pid.");
        exit(1);
    }

    pid_t pid = atoi(argv[1]);
    char buf[64] = { 0 };
    int n = 0;

    while(1) {
        /* read date from stdin */
        if ((n = read(STDIN_FILENO, buf, 64)) > 0) {
            int fd = open("tmp", O_WRONLY | O_CREAT | O_EXCL, 0664);
            if (fd < 0) {
                perror("open tmp file.\n");
                continue;
            }
            write(fd, buf, n);
            close(fd);

            /* send signal to receiver */
            if (kill(pid, SIGUSR1) < 0) {
                perror("kill");
            }
            /* quit key char */
            if (*buf == 'q') return 0;
        }
    }
    return 0;
}

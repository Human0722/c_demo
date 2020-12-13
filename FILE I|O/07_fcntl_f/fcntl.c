/*
 * @Author: Human0722
 * @Date: 2020-11-26 13:45:23
 * @FilePath: /c_demo/07_fcntl_f/fcntl.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    int flag;

    if(argc < 2)
    {
        perror("Missing param!");
        exit(1);
    }

    fd = atoi(argv[1]);

    flag = fcntl(fd, F_GETFL);

    if(flag & O_RDONLY)
    {
        printf("O_RDONLY\n");
    }
    
    if(flag & O_WRONLY)
    {
        printf("O_WRONLY\n");
    }

    if(flag & O_RDWR)
    {
        printf("O_RDWR");
    }

    if(flag & O_APPEND)
    {
        printf("O_APPEND\n");
    }

    return 0;
}
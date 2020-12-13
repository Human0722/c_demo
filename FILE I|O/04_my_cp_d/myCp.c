/*
 * @Author: Human0722
 * @Date: 2020-11-24 10:40:35
 * @FilePath: /c_demo/04_my_cp_d/myCp.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFSIZE 4098

int main(int argc, char *argv[])
{
    /* param check */
    if(argc != 3) 
    {
        perror("*  Missing param *");
        exit(1);
    }

    int len = 0;
    int buf[BUFFSIZE] = {0};

    /* open source file */ 
    int srcfd = open(argv[1], O_RDONLY);
    if(srcfd == -1)
    {
        perror("open source file");
        exit(1);
    }

    /* open dest file */
    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    while((len = read(srcfd, buf, BUFFSIZE)) > 0)
    {
        if((write(dstfd, buf, len)) != len)
        {
            perror("wirte error");
            exit(1);
        }
    }
    /* handle read error */
    if(len < 0)
    {
        perror("src read error");
        exit(1);
    }

    /* close files */
    close(srcfd);
    close(dstfd); 
    return 0;
}

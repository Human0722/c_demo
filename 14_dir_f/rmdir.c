/*
 * @Author: Human0722
 * @Date: 2020-11-28 22:17:44
 * @FilePath: /c_demo/14_dir_f/rmdir.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(rmdir(argv[1]) == -1)
    {
        perror("rmdir");
        exit(1);
    }
    printf("Success rmdir: %s\n", argv[1]);
    return 0;
}

/*
 * @Author: Human0722
 * @Date: 2020-11-28 22:13:35
 * @FilePath: /c_demo/14_dir_f/mkdir.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(mkdir(argv[1], 775) == -1)
    {
        perror("mkdir");
        exit(1);
    }
    printf("Success mkdir: %s\n", argv[1]);
    return 0;
}
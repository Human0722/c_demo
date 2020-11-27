/*
 * @Author: Human0722
 * @Date: 2020-11-27 16:47:05
 * @FilePath: /c_demo/10_chmod_f/mychmod.c
 */
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int mode = strtol(argv[1], NULL, 8);
    chmod(argv[2], mode);    
    return 0;
}

/*
 * @Author: Human0722
 * @Date: 2020-11-28 20:22:04
 * @FilePath: /c_demo/13_links_f/symlink.c
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(symlink(argv[1], argv[2]) == -1)
    {
        perror("symlink");
    }
    return 0;
}

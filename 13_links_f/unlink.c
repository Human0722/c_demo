/*
 * @Author: Human0722
 * @Date: 2020-11-28 21:37:55
 * @FilePath: /c_demo/13_links_f/unlink.c
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(unlink(argv[1]) == -1)
    {
        perror("unlink");
    }
    return 0;
}
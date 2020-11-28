/*
 * @Author: Human0722
 * @Date: 2020-11-28 19:59:02
 * @FilePath: /c_demo/13_links_f/link.c
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(link(argv[1], argv[2]) == -1)
    {
        perror("link");
    }
    return 0;
}

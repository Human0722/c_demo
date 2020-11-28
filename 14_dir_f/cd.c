/*
 * @Author: Human0722
 * @Date: 2020-11-28 22:01:13
 * @FilePath: /c_demo/14_dir_f/cd.c
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(chdir(argv[1]) == -1)
    {
        perror("chdir");
    }
    printf("Location: %s\n", getcwd(NULL, 0));
    return 0;
}

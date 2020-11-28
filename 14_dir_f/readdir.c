/*
 * @Author: Human0722
 * @Date: 2020-11-28 22:21:18
 * @FilePath: /c_demo/14_dir_f/readdir.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;

    if((dir = opendir(argv[1])) == NULL)
    {
        perror("opendir");
        exit(1);
    }
    while((entry = readdir(dir)) != NULL)
    {
        printf("%ld\t0x%02x\t%ld\t%s\n", entry->d_ino, entry->d_type, entry->d_off, entry->d_name);
    }

    return 0;
}

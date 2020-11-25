/*
 * @Author: Human0722
 * @Date: 2020-11-25 21:34:30
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char buf[10] = {0};
    int len;

    while(1)
    {
        len = read(STDIN_FILENO, buf, 10);
        write(STDOUT_FILENO, buf, len);
    }
    
    return 0;
}

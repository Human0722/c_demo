/*
 * @Author: Human0722
 * @Date: 2020-11-25 21:02:31
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define SIZE 64

int main(void)
{
    char buf[SIZE] = {0};
    int length = 0;

    int fd = open("test", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    lseek(fd, 6, SEEK_SET);
    length = read(fd, buf, SIZE);
    if(length > 0)
        buf[length] = '\0';
    printf("Result of lseek is: %s", buf);
    return 0;
}

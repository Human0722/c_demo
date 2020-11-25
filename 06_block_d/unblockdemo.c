/*
 * @Author: Human0722
 * @Date: 2020-11-25 22:25:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

char MSG_TRY[] = "try again!\n";

int main(void)
{
    char buf[10];
    int len;
    int fd;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);

    while(1)
    {
        len = read(fd, buf, 10);
        if(len < 0)
        {
            if(errno == EAGAIN) 
            {
                write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
                sleep(1);   //让出CPU
            }
            else
            {
                perror("read");
                exit(1);
            }
            
        }
        else
        {
            break;
        }
        
    }
    write(STDOUT_FILENO, buf, len);
    return 0;
}

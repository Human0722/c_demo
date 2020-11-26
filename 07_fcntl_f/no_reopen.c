/*
 * @Author: Human0722
 * @Date: 2020-11-26 14:48:47
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

char MSG_TRY[] = "TRY AGAIN\n";

int main(void)
{
    int len = 0;
    char buf[10] = {0};

    /* Already open terminal file, get the flags */
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    if(flags & O_RDONLY)
    {
        printf("STDIN is O_RDONLY\n");
    }

    flags |= O_NONBLOCK;

    if(fcntl(STDIN_FILENO, F_SETFL, flags) == -1)
    {
        perror("set fcntl");
        exit(1);
    }

    while(1)
    {
        len = read(STDIN_FILENO, buf, 10);
        if(len < 0)
        {
            /* maybe error or wait */
            if(errno == EWOULDBLOCK)
            {
                write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
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
        sleep(1);
        
    }

    write(STDOUT_FILENO, buf, len);
    return 0;

}

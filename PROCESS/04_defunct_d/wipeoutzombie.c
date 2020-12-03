/*
 * @Author: Human0722
 * @Date: 2020-12-03 14:03:58
 * @LastEditTime: 2020-12-03 15:00:48
 * @FilePath: /c_demo/PROCESS/04_defunct_d/wipeoutzombie.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("Before fork \n");

    pid_t pid, n = 5;
    while(n--) {
        pid = fork();
        if(pid == 0) {
            /* child process jump here*/
            break;
        }else if(pid < 0) {
            perror("fork");
            exit(1);
        }
    }
    /* child process sleep for 4*n+1 second */
    if(pid == 0) {
        sleep(4*n + 1);
        printf("hello, I'm child [ %d ]; my father is [ %d ]\n", getpid(), getppid());

        if(4*n+1 == 5) *((int *)0) = 0;
        /* child process over here */ 
        return 4*n + 1;
    }

    int status = 0;
    while(1) {
        pid = waitpid(-1, &status, WUNTRACED | WCONTINUED);

        if(pid == -1) {
            perror("wait");
            sleep(10);
            printf("I'm father [ %d ]; I have wipe out all zombies\n\n", getpid());
            return 1;
        }
        else if(pid == 0) {
            /* only ocurr WNOHANG on */
            printf("Hello, I'm father; I'm waitting child\n\n");
        }
        else {

            if(WIFEXITED(status)) {
                printf("child [ %d ] <exited> with code [ %d ]\n\n", pid, WEXITSTATUS(status));
            }

            else if(WIFSIGNALED(status)) {
                printf("child [ %d ] <terminated> banormally, signal [ %d ]\n\n", pid, WTERMSIG(status));
#ifdef WCOREDUMP
                if(WCOREDUMP(status)) {
                    printf("<core file generated> in child [ %d ]\n\n", pid);
                }
#endif
            }

            else if(WIFSTOPPED(status)) {
                printf("child [ %d ] <stopped>, signal [ %d ]\n\n", pid, WSTOPSIG(status));
            }

            else if (WIFCONTINUED(status)) {
                printf("child [ %d ] <continued>\n\n", pid);
            }
        }
    }
    return 0;
}

/*
 * @Author: Human0722
 * @Date: 2020-12-05 19:06:27
 * @FilePath: /c_demo/SIGNAL/02_handlesignal_d/reenterable.c
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    getpwnam("root");
}

int main(void) {

    if(SIG_ERR == signal(SIGINT, handler)) {
        perror("signal");
        exit(1);
    }
    printf("I'm %d\n", getpid());
    struct passwd *pwd = getpwnam("tooler");
    sleep(10);
    printf("tooler's uid = %d\n", pwd->pw_uid);
    return 0;
}

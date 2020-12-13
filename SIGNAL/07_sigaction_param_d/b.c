/*
 * @Author: Human0722
 * @Date: 2020-12-11 17:01:18
 * @LastEditTime: 2020-12-11 17:02:05
 * @FilePath: /c_demo/SIGNAL/07_sigaction_param_d/b.c
 */
// b.c
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) printf("usage: %s <pid>\n", argv[0]);
  pid_t pid = atoi(argv[1]);

  union sigval val;
  while(1) {
    scanf("%d", &val.sival_int);
    if (sigqueue(pid, SIGQUIT, val) < 0) { // 发送带附加值的信号
      perror("sigqueue");
    }   
  }
}

/*
 * @Author: Human0722
 * @Date: 2020-11-28 19:38:42
 * @FilePath: /c_demo/12_truncate_f/truncate.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    off_t len = 5;
    truncate("test.txt", len);
    return 0;
}



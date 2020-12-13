/*
 * @Author: Human0722
 * @Date: 2020-12-13 21:12:35
 * @LastEditTime: 2020-12-13 21:14:07
 * @FilePath: /c_demo/SIGNAL/09_longjmp_d/goto.c
 */


#include <stdio.h>

int main(void)
{
    hello:
    printf("hello, goto app.\n");
    sleep(2);
    goto hello;
    return 0;
}
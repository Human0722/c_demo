/*
 * @Author: Human0722
 * @Date: 2020-12-13 21:05:37
 * @LastEditTime: 2020-12-13 21:12:07
 * @FilePath: /c_demo/SIGNAL/09_longjmp_d/jmp.c
 */

#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>

jmp_buf hello;

void func2()
{
    longjmp(hello,1);
}

void func1()
{
    setjmp(hello);
    printf("Here is func1\n");
    sleep(2);
    func2();
}

int main(void)
{
    func1();
    return 0;
}

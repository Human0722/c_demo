/*
 * @Author: Human0722 
 * @Date: 2020-12-13 21:36:31
 * @LastEditTime: 2020-12-13 21:59:33
 * @FilePath: /c_demo/SIGNAL/09_longjmp_d/antherjmp.c
 */
#include <stdio.h>
#include <setjmp.h>

jmp_buf jmpbuf;

void doSth()
{
    int n = 0;
    scanf("%d", &n);
    if(n == 100) {
        longjmp(jmpbuf, 100);
    }

    if(n == 200) {
        longjmp(jmpbuf, 200);
    }

}

int main(void)
{
    int res = 0;
    if((res = setjmp(jmpbuf)) != 0) {
        printf("hello, res = %d\n", res);
    }

    while(1)
    {
        doSth();
    }
    return 0;
}

/*
 * @Author: Human0722
 * @Date: 2020-11-28 19:27:39
 * @FilePath: /c_demo/11_utime_f/utime.c
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <utime.h>


int main(void)
{
   struct stat st;
   stat("test.txt", &st);
   printf("最近修改时间: %s\n", ctime(&st.st_mtime));
   printf("最近访问时间: %s\n", ctime(&st.st_atime));

   struct utimbuf utb = {st.st_atime - 24 * 3600, st.st_mtime -24*3600};

   utime("test,txt", &utb);
   stat("test.txt", &st);
   printf("执行 utime 之后的时间:\n");
   printf("最近修改时间: %s\n", ctime(&st.st_mtime));
   printf("最近访问时间: %s\n", ctime(&st.st_atime));

   return 0; 
}
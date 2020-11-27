/*
 * @Author: Human0722
 * @Date: 2020-11-27 14:25:18
 * @FilePath: /c_demo/08_stat_f/statdemo.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void)
{
    struct stat st;
    int r = stat("test.txt", &st);

    /* Handle error */
    if(r)
    {
        perror("stat");
        exit(1);
    }

    printf("st_dev = %lld\n", st.st_dev);
    printf("st_ino = %ld\n", st.st_ino);
    printf("st_mode = %d\n", st.st_mode);
    printf("st_nlink = %d\n", st.st_nlink);
    printf("st_uid = %d\n", st.st_uid);
    printf("st_gid = %d\n", st.st_gid);
    printf("st_size = %ld\n", st.st_size);
    
    printf("st_atime = %ld\n", st.st_atime);
    printf("st_mtime = %ld\n", st.st_mtime);
    printf("st_ctime = %ld\n", st.st_ctime);

    return 0;

    
}

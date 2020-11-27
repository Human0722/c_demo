/*
 * @Author: Human0722
 * @Date: 2020-11-27 15:45:48
 * @LastEditTime: 2020-11-27 16:06:25
 * @FilePath: /c_demo/09_time_f/timeDemo.c
 */
#include <stdio.h>
#include <time.h>

/* get time_t and transform  it to GMT time and Local time. */
int main(void)
{
    char *wday[] = {"SUN", "MON", "TUE", "WED", "THUR", "FRI", "SAT"};
    /* get time_t time */
    time_t t;
    t = time(NULL);
    printf("time_t time: %ld\n", t);

    /*  transform it to GMT time */
    struct tm *tt;
    tt = gmtime(&t);
    printf("GMT:  \n");
    printf("%d-%d-%d ", 1900 + tt->tm_year, tt->tm_mon, tt->tm_mday);
    printf("%s %d:%d:%d\n", wday[tt->tm_wday], tt->tm_hour, tt->tm_min, tt->tm_sec);

    /* transform it to Local time */
    tt = localtime(&t);
    printf("Local: \n");
    printf("%d-%d-%d ", 1900 + tt->tm_year, tt->tm_mon, tt->tm_mday);
    printf("%s %d:%d:%d\n", wday[tt->tm_wday], tt->tm_hour, tt->tm_min, tt->tm_sec);

    /* transform it back to origin */
    t= mktime(tt);
    printf("time_t time: %ld\n", t);

    return 0;
}

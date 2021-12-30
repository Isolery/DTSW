#include <locale.h>
#include <time.h>
#include <sys/time.h>
#include "tlpi_hdr.h"

#define SECONDS_IN_TROPICAL_YEAR (365.24219 * 24 * 60 * 60)

int main(int argc, char *argv[])
{
    time_t t;
    struct tm *gmp, *locp;
    struct tm gm, loc;
    struct timeval tv;

    t = time(NULL);    // 获取从1970.1.1到现在的秒数
    printf("Seconds since the Epoch (1 Jan 1970): %ld", (long)t);
    printf("(about %6.3f years)\n", t / SECONDS_IN_TROPICAL_YEAR);

    if(gettimeofday(&tv, NULL) == -1){    // 获取秒数(与time返回值一样)和微妙
        errExit("gettimeofday");
    }
    printf("gettimeofday() returned %ld secs, %ld microsecs\n", (long)tv.tv_sec, (long)tv.tv_usec);

    gmp = gmtime(&t);         // 分解时间为GMT时间
    if(gmp == NULL){
        errExit("gmtime");
    }

    gm = *gmp;

    printf("Broken down by gmtime():\n");
    printf("year=%d mon=%d mday=%d hour=%d min=%d sec=%d ", gm.tm_year, gm.tm_mon, gm.tm_mday, gm.tm_hour, gm.tm_min, gm.tm_sec);
    printf("wday=%d yday=%d isdst=%d\n", gm.tm_wday, gm.tm_yday, gm.tm_isdst);

    locp = localtime(&t);   // 分解时间为本地时间(GMT+8)
    if(locp == NULL){
        errExit("localtime");
    }

    loc = *locp;

    printf("Broken down by localtime():\n");
    printf("year=%d mon=%d mday=%d hour=%d min=%d sec=%d", loc.tm_year, loc.tm_mon, loc.tm_mday, loc.tm_hour, loc.tm_min, loc.tm_sec);
    printf("wday=%d yday=%d isdst=%d\n", loc.tm_wday, loc.tm_yday, loc.tm_isdst);

    printf("asctime() formats the gmtime() value as:    %s", asctime(&gm));     // 将分解时间转换成打印格式: Mon Dec 20 00:58:10 2021
    printf("asctime() formats the localtime() value as: %s", asctime(&loc));    // asctime不受本地时区的影响, 转化后为UTC时间
    printf("ctime() formats the time() value as:        %s", ctime(&t));        // ctime受本地时区的影响, 转化后为本地时间

    printf("mktime() of gmtime() value:    %ld secs\n", (long)mktime(&gm));     // 
    printf("mktime() of localtime() value: %ld secs\n", (long)mktime(&loc));    // 

    exit(EXIT_SUCCESS);
}
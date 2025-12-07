#include <stdio.h>
#include <time.h>

int main() {
    time_t raw;
    struct tm *ti;

    time(&raw);
    ti = localtime(&raw);

    printf("Current time: %02d:%02d:%02d\n",
           ti->tm_hour,
           ti->tm_min,
           ti->tm_sec);

    printf("Date: %02d-%02d-%04d\n",
           ti->tm_mday,
           ti->tm_mon + 1,
           ti->tm_year + 1900);

    return 0;
}

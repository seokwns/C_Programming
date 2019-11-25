#include <stdio.h>
#include <time.h>
#define DAYSEC (24 * 60 * 60)

int main(void) {
    struct tm *now, *set;
    time_t now_t, set_t;
    const char *weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",  "Friday", "Saturday" };

    time(&now_t);
    now = localtime(&now_t);
    printf("today's date : %d / %d / %d\n", now -> tm_year + 1900, now -> tm_mon + 1,now -> tm_mday);
    printf("day : %s\n", weekday[now -> tm_wday]);

    int n;
    printf("n : ");
    scanf("%d", &n);
    printf("after (n = %d) day : %s\n", n, weekday[(now -> tm_wday + n) % 7]);

    int mm, dd, yyyy;
    printf("Input date(mm/dd/yyyy) : ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    time(&set_t);
    set = localtime(&set_t);

    set -> tm_year = yyyy - 1900;
    set -> tm_mon = mm - 1;
    set -> tm_mday = dd;
    
    set_t = mktime(set);

    double abs = (now_t > set_t? now_t - set_t : set_t - now_t);
    double diff = (double)(abs / DAYSEC);
    printf("difference : %.f\n", diff);

    return 0;
}

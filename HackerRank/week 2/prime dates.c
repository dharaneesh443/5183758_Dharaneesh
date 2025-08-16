#include <stdio.h>
#include <stdlib.h>

int isLeap(int y) {
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int getMonthDays(int m, int y) {
    int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) return 29;
    return arr[m-1];
}
void parseDate(const char *s, int *d, int *m, int *y) {
    sscanf(s, "%2d-%2d-%4d", d, m, y);
}

int sameDate(int d1, int m1, int y1, int d2, int m2, int y2) {
    return (d1 == d2) && (m1 == m2) && (y1 == y2);
}


void nextDay(int *d, int *m, int *y) {
    (*d)++;
    int days = getMonthDays(*m, *y);
    if (*d > days) {
        *d = 1;
        (*m)++;
        if (*m > 12) {
            *m = 1;
            (*y)++;
        }
    }
}


int isLucky(int d, int m, int y) {
    char buff[16];
    sprintf(buff, "%02d%02d%04d", d, m, y);
    long long val = atoll(buff);
    return (val % 4 == 0) || (val % 7 == 0);
}

int main() {
    char u, v;
    scanf("%s %s", u, v);

    int d1, m1, y1, d2, m2, y2;
    parseDate(u, &d1, &m1, &y1);
    parseDate(v, &d2, &m2, &y2);

    int count = 0;
    int curd = d1, curm = m1, cury = y1;

    while (1) {
        if (isLucky(curd, curm, cury))
            count++;
        if (sameDate(curd, curm, cury, d2, m2, y2))
            break;
        nextDay(&curd, &curm, &cury);
    }
    printf("%d\n", count);
    return 0;
}

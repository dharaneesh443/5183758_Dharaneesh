#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findZigZagSequence(int a[], int n) {
    qsort(a, n, sizeof(int), cmpfunc);

    int mid = (n + 1) / 2 - 1;
    int temp = a[mid];
    a[mid] = a[n-1];
    a[n-1] = temp;

    int st = mid + 1;
    int ed = n - 2;
    while(st <= ed) {
        temp = a[st];
        a[st] = a[ed];
        a[ed] = temp;
        st++;
        ed--;
    }

    // Print the result
    for(int i = 0; i < n; i++) {
        if(i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        findZigZagSequence(a, n);
    }
    return 0;
}

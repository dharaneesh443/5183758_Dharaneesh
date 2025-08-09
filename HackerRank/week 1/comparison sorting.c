#include <stdio.h>

int main() {
    int n, num;
    int freq[100] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num >= 0 && num < 100) {
            freq[num]++;
        }
    }

    for (int i = 0; i < 100; i++) {
        printf("%d", freq[i]);
        if (i < 99) printf(" ");
    }
    printf("\n");

    return 0;
}
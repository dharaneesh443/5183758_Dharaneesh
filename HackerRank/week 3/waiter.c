#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define MAXQ 100

void generatePrimes(int *primes, int q) {
    int isPrime[130000] = {0};
    int count = 0;
    for (int i = 2; count < q; i++) {
        if (!isPrime[i]) {
            primes[count++] = i;
            for (int j = i+i; j < 130000; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int A1[MAXN], A2[MAXN], B[MAXN], answers[MAXN], ans_idx = 0;
    int primes[MAXQ];
    generatePrimes(primes, q);

    for(int i=0; i<n; i++)
        scanf("%d", &A1[i]);
    int lenA1 = n, lenA2, lenB;

    for(int i=0; i<lenA1/2; i++) {
        int tmp = A1[i];
        A1[i] = A1[lenA1-1-i];
        A1[lenA1-1-i] = tmp;
    }

    for(int i=0; i<q; i++) {
        lenA2 = 0;
        lenB = 0;
        while (lenA1 > 0) {
            int cur = A1[--lenA1];
            if (cur % primes[i] == 0)
                B[lenB++] = cur;
            else
                A2[lenA2++] = cur;
        }
       
        for (int j=lenB-1; j>=0; j--)
            answers[ans_idx++] = B[j];
        int *tmpA = A1; A1 = A2; A2 = tmpA;
        lenA1 = lenA2;
    }

    for (int i=lenA1-1; i>=0; i--)
        answers[ans_idx++] = A1[i];

    for (int i=0; i<ans_idx; i++)
        printf("%d\n", answers[i]);

    return 0;
}

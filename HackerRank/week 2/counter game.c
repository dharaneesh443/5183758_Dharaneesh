#include <stdio.h>

const char* counterGame(unsigned long long n) {
    int moves = 0;

    while (n > 1) {
        // If n is a power of 2
        if ((n & (n - 1)) == 0) {
            n /= 2;
        } else {
            unsigned long long p = 1ULL << 63;
            while (p > n) p >>= 1;
            while (p > n) p >>= 1;
            n -= p;
        }
        moves++;
    }

    return (moves % 2 == 0) ? "Richard" : "Louise";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}

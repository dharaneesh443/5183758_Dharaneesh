#include <stdio.h>
#include <string.h>

long long digitSum(const char *s) {
    long long sum = 0;
    for (int i = 0; s[i]; i++)
        sum += s[i] - '0';
    return sum;
}
int superDigitHelper(long long n) {
    if (n < 10)
        return n;
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigitHelper(sum);
}

int superDigit(char *n, int k) {
    long long sum = digitSum(n);
    sum *= k;
    return superDigitHelper(sum);
}

int main() {
    char n[100001];
    int k;
    scanf("%s %d", n, &k);
    printf("%d\n", superDigit(n, k));
    return 0;
}

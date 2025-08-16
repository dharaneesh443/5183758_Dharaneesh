#include <stdio.h>

int towerBreakers(int n, int m) {
    if (m == 1 || n % 2 == 0)
        return 2;
    else
        return 1;
}

int main() {
    int t, n, m;
    scanf("%d", &t); 
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", towerBreakers(n, m));
    }
    return 0;
}

#include <stdio.h>


int buildUnique(int *ranked, int n, int *unique) {
    int size = 0;
    unique[size++] = ranked[0];
    for (int i = 1; i < n; i++) {
        if (ranked[i] != unique[size-1])
            unique[size++] = ranked[i];
    }
    return size;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int ranked[n], unique[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &ranked[i]);
    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &player[i]);
    
    int uniqueSize = buildUnique(ranked, n, unique);
    int i = uniqueSize - 1;  
    for (int j = 0; j < m; j++) {
        while (i >= 0 && player[j] >= unique[i])
            i--;
        printf("%d\n", i + 2); 
    }
    return 0;
}

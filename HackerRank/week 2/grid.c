#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortRow(char *row, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (row[j] > row[j+1]) {
                char tmp = row[j];
                row[j] = row[j+1];
                row[j+1] = tmp;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char grid[n][n+1]; 

        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
            sortRow(grid[i], n); 
        }

        int is_valid = 1;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n-1; row++) {
                if (grid[row][col] > grid[row+1][col]) {
                    is_valid = 0;
                    break;
                }
            }
            if (!is_valid) break;
        }

        if (is_valid)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

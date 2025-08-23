#include <stdio.h>
#include <string.h>

#define MAX 200

int r, c, n;
char grid[MAX][MAX+1];
char grid3[MAX][MAX+1], grid5[MAX][MAX+1];

void fillBombs(char out[MAX][MAX+1]) {
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            out[i][j] = 'O';
    for (int i=0; i<r; i++)
        out[i][c] = 0;
}

void detonate(char in[MAX][MAX+1], char out[MAX][MAX+1]) {
    int i, j;
    for (i=0; i<r; i++)
        strcpy(out[i], ""); // Clear for writing
    fillBombs(out);
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
            if (in[i][j] == 'O') {
                out[i][j] = '.';
                if (i > 0) out[i-1][j] = '.';
                if (j > 0) out[i][j-1] = '.';
                if (i < r-1) out[i+1][j] = '.';
                if (j < c-1) out[i][j+1] = '.';
            }
}

int main() {
    scanf("%d %d %d", &r, &c, &n);
    for (int i=0; i<r; i++)
        scanf("%s", grid[i]);

    if (n == 1) {
        for (int i=0; i<r; i++)
            printf("%s\n", grid[i]);
        return 0;
    }

    if (n % 2 == 0) {
        fillBombs(grid);
        for (int i=0; i<r; i++)
            printf("%s\n", grid[i]);
        return 0;
    }

    detonate(grid, grid3);
    detonate(grid3, grid5);

    if ((n-3)%4 == 0) {
        for (int i=0; i<r; i++)
            printf("%s\n", grid3[i]);
    } else {
        for (int i=0; i<r; i++)
            printf("%s\n", grid5[i]);
    }
    return 0;
}

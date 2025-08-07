#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100
#define MAX_UNIQUE 1000

typedef struct {
    char str[MAX_STR_LEN];
    int count;
} StringCount;

int main() {
    int n, q;
    scanf("%d", &n);

    char temp[MAX_STR_LEN];
    StringCount freq[MAX_UNIQUE];
    int freq_size = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%s", temp);
        int found = 0;
        for(int j = 0; j < freq_size; ++j) {
            if (strcmp(freq[j].str, temp) == 0) {
                freq[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(freq[freq_size].str, temp);
            freq[freq_size].count = 1;
            freq_size++;
        }
    }

    // Read and answer queries
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        scanf("%s", temp);
        int answer = 0;
        for(int j = 0; j < freq_size; ++j) {
            if (strcmp(freq[j].str, temp) == 0) {
                answer = freq[j].count;
                break;
            }
        }
        printf("%d\n", answer);
    }

    return 0;
}
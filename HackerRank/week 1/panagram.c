#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* pangrams(char s[]) {
    int alpha[26] = {0};
    int i, idx;
    size_t len = strlen(s);

    for (i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            idx = tolower(s[i]) - 'a';
            alpha[idx] = 1;
        }
    }
    for (i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            return "not pangram";
        }
    }
    return "pangram";
}

int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n')
        s[len-1] = '\0';

    printf("%s\n", pangrams(s));
    return 0;
}
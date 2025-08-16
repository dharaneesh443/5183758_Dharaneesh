#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char* s, int k) {
    int n = strlen(s);
    k = k % 26; 
    for (int i = 0; i < n; i++) {
        if (isupper(s[i])) {
            s[i] = 'A' + (s[i] - 'A' + k) % 26;
        } else if (islower(s[i])) {
            s[i] = 'a' + (s[i] - 'a' + k) % 26;
        }
       
    }
    printf("%s\n", s);
}

int main() {
    int n, k;
    char s[200]; 

    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);

    caesarCipher(s, k);

    return 0;
}

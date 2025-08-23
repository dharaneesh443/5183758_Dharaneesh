#include <stdio.h>
#include <string.h>

const char* isValid(const char* s) {
    int freq[26] = {0};
    int i, minFreq = 1e6, maxFreq = 0;
    int len = strlen(s);

 
    for (i = 0; i < len; i++)
        freq[s[i] - 'a']++;

    
    for (i = 0; i < 26; i++) {
        if (freq[i]) {
            if (freq[i] < minFreq) minFreq = freq[i];
            if (freq[i] > maxFreq) maxFreq = freq[i];
        }
    }

    if (minFreq == maxFreq) return "YES";

    int minCount = 0, maxCount = 0, others = 0;
    for (i = 0; i < 26; i++) {
        if (freq[i]) {
            if (freq[i] == minFreq) minCount++;
            else if (freq[i] == maxFreq) maxCount++;
            else others++;
        }
    }

    
    if ((others == 0 && maxCount == 1 && maxFreq - minFreq == 1) ||
        (others == 0 && minCount == 1 && minFreq == 1))
        return "YES";

    return "NO";
}

int main() {
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}

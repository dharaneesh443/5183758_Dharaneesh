#include <stdio.h>
#include <string.h>

char* strings_xor(char* s, char* t) {
char* result = malloc(strlen(s) + 1);
for (int i = 0; i < strlen(s); i++) {
result[i] = (s[i] == t[i]) ? '0' : '1';
}
result[strlen(s)] = '\0';
return result;
}

int main() {
char s[100], t[100];
scanf("%s\n%s", s, t);
char* result = strings_xor(s, t);
printf("%s\n", result);
free(result);
return 0;
}

#include <stdio.h>
#include <string.h>

#define MAXLEN 1001

int isBalanced(const char *s) {
    char stack[MAXLEN];
    int top = -1;
    for (int i = 0; s[i]; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else {
            if (top < 0)
                return 0;
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{'))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    int n;
    char s[MAXLEN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%s\n", isBalanced(s) ? "YES" : "NO");
    }
    return 0;
}

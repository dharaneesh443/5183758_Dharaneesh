#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000000
#define MAXOPS 100000

typedef struct {
    int type; 
    char str[MAXLEN];
} OpStack;

char S[MAXLEN + 1];  
OpStack ops[MAXOPS];  
int s_len = 0;       
int o_top = -1;       

int main() {
    int Q;
    scanf("%d", &Q);
    S[0] = '\0';

    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
           
            char w[MAXLEN];
            scanf("%s", w);
            int wl = strlen(w);
           
            ops[++o_top].type = 1;
            strcpy(ops[o_top].str, w);
            
            strcpy(S + s_len, w);
            s_len += wl;
            S[s_len] = '\0';
        } else if (type == 2) {
          
            int k;
            scanf("%d", &k);
         
            ops[++o_top].type = 2;
            strncpy(ops[o_top].str, S + s_len - k, k);
            ops[o_top].str[k] = '\0';
            
            s_len -= k;
            S[s_len] = '\0';
        } else if (type == 3) {
            
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } else if (type == 4) {
          
            if (o_top < 0) continue;
            if (ops[o_top].type == 1) {
                
                int wl = strlen(ops[o_top].str);
                s_len -= wl;
                S[s_len] = '\0';
            } else if (ops[o_top].type == 2) {
                int wl = strlen(ops[o_top].str);
                strcpy(S + s_len, ops[o_top].str);
                s_len += wl;
                S[s_len] = '\0';
            }
            o_top--;
        }
    }
    return 0;
}

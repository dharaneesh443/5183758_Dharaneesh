#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} DynArray;

void append(DynArray *arr, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (arr->head == NULL) {
        arr->head = newNode;
    } else {
        Node *cur = arr->head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }
    arr->size++;
}


int get(DynArray *arr, int idx) {
    Node *cur = arr->head;
    while (idx--) {
        cur = cur->next;
    }
    return cur->value;
}


void freeDynArray(DynArray *arr) {
    Node *cur = arr->head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);


    DynArray *arr = malloc(n * sizeof(DynArray));
    for (int i = 0; i < n; i++) {
        arr[i].head = NULL;
        arr[i].size = 0;
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        int idx = (x ^ lastAnswer) % n;
        if (t == 1) {
            append(&arr[idx], y);
        } else if (t == 2) {
            int val = get(&arr[idx], y % arr[idx].size);
            lastAnswer = val;
            printf("%d\n", lastAnswer);
        }
    }
 for (int i = 0; i < n; i++) {
        freeDynArray(&arr[i]);
    }
    free(arr);

    return 0;
}

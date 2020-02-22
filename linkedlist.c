// 6210450075 Thanyatorn Krikran

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node *newNode(int newValue) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->value = newValue;
    newNode->next = NULL;

    return newNode;
}

void Add(struct Node **first, struct Node *newNode) {
    struct Node *now;
    if (*first == NULL || (*first)->value >= newNode->value) {
        newNode->next = *first;
        *first = newNode;
    } else {
        now = *first;
        while (now->next != NULL &&
               now->next->value < newNode->value) {
            now = now->next;
        }
        newNode->next = now->next;
        now->next = newNode;
    }
}

void print(struct Node *first) {
    for(;first; first = first->next){
        printf("%d", first->value);
        printf("\n");
    }
   
}

int main() {
    struct Node *first = NULL;
    struct Node *node = NULL;
    int n;
    while (scanf("%d", &n),n != -1) {
        node = newNode(n);
        Add(&first, node);
        
    }
    
    print(first);

    return 0;
}
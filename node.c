#include <stdlib.h>

typedef union Data{
    int i;
    float f;
    char c;
    char s[256];
};

typedef struct Node{
    union Data data;
    struct Node *next;
};

struct Node *newNode(){
    struct Node *new = malloc(sizeof(struct Node));
    new->next = NULL;
    return new;
}

int getNodeI(struct Node *node){
    return node->data.i;
}

float getNodeF(struct Node *node){
    return node->data.f;
}

char getNodeC(struct Node *node){
    return node->data.c;
}

char *getNodeS(struct Node *node){
    return &node->data.s;
}


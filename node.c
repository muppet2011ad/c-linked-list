#include <stdlib.h>

typedef union Data{
    int i;
    float f;
    char c;
    char *s;
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

void setNodeI(struct Node *node, int i){
    node->data.i = i;
}

void setNodeF(struct Node *node, float f){
    node->data.f = f;
}

void setNodeC(struct Node *node, char c){
    node->data.c = c;
}

void setNodeS(struct Node *node, char *s){
    node->data.s = s;
}
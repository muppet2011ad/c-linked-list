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
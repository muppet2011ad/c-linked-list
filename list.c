#include <stdio.h>
#include <stdlib.h>
#include "node.c"

struct Node *newList();
struct Node *newListFromNode(struct Node *head);
struct Node *getNode(struct Node *head, int n);
void addToListEnd(struct Node *new, struct Node *head);
struct Node *addToList(struct Node *new, struct Node *head, int n);
struct Node *removeFromList(struct Node *head, int n);
int getListLen(struct Node *head);
void deleteList(struct Node *head);

int main(){
    printf("Hello World\n");
    struct Node *list1 = newList();
    setNodeI(list1,1337);
    addToListEnd(newNodeI(255), list1);
    printf("%d\n",getListLen(list1));
    printf("%d\n",getNodeI(getNode(list1,1)));
    addToList(newNodeI(2019),list1,1);
    printf("%d\n",getNodeI(getNode(list1,1)));
    removeFromList(list1,1);
    printf("%d\n",getNodeI(getNode(list1,1)));
    deleteList(list1);
    printf("%d\n",sizeof(struct Node));
    return 0;
}

struct Node *newList(){
    struct Node *head = malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}

struct Node *newListFromNode(struct Node *head){
    head->next = NULL;
    return head;
}

struct Node *getNode(struct Node *head, int n){
    struct Node *sel = head;
    for (int i = 0; i < n; i++){
        if (sel->next == NULL){
            return NULL;
        }
        sel = sel->next;
    }
    return sel;
}

void addToListEnd(struct Node *new, struct Node *head){
    struct Node *sel = head;
    while (sel->next != NULL){
        sel = sel->next;
    }
    sel->next = new;
}

struct Node *addToList(struct Node *new, struct Node *head, int n){
    if (n != 0){
        struct Node *btarget = getNode(head, n-1);
        struct Node *atarget = btarget->next;
        btarget->next = new;
        new->next = atarget;
        return head;
    }
    else{
        new->next = head;
        return new;
    }

}

struct Node *removeFromList(struct Node *head, int n){
    if (n != 0){
        struct Node *btarget = getNode(head, n-1);
        struct Node *target = btarget->next;
        struct Node *atarget = target->next;
        btarget->next = atarget;
        free(target);
        return head;
    }
    else{
        struct Node *next = head->next;
        free(head);
        return next;
    }

}

int getListLen(struct Node *head){
    int length = 1;
    struct Node *sel = head;
    while (sel->next != NULL){
        length++;
        sel = sel->next;
    }
    return length;
}

void deleteList(struct Node *head){
    struct Node *sel = head;
    while (sel->next != NULL){
        struct Node *next = sel->next;
        free(sel);
        sel = next;
    }
    free(sel);
}
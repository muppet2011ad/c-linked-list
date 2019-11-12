#include <stdio.h>
#include <stdlib.h>
#include "node.c"

int main(){

}

struct Node *newList(){
    struct Node *head = malloc(sizeof(struct Node));
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

void addToList(struct Node *new, struct Node *head, int n){
    struct Node *btarget = getNode(head, n-1);
    struct Node *atarget = btarget->next;
    btarget->next = new;
    new->next = atarget;
}

void removeFromList(struct Node *head, int n){
    struct Node *btarget = getNode(head, n-1);
    struct Node *target = btarget->next;
    struct Node *atarget = target->next;
    btarget->next = atarget;
    free(target);
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
}
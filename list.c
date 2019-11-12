#include <stdio.h>
#include <stdlib.h>
#include "node.c"

int main(){

}

struct Node *newList(){
    static struct Node head;
    head.next = NULL;
    return &head;
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
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* criaLista(int val) {
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new -> val = val;
    new -> next = NULL;
    return new;
}

void addLista(int val,struct ListNode* root) {
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new -> val = val;
    new -> next = NULL;
    root -> next = new;
    }

void unifyList(struct ListNode* root,struct ListNode* tounify) {
    if (root -> next == NULL) {
    root -> next = tounify;
    return;
    } else
    unifyList(root -> next,tounify);
}

void mergeKlists(struct ListNode* root){
    int temp;
    if (root->next == NULL)
    return;
    if (root-> val > root -> next -> val ) {
    temp = root -> next -> val;
    root -> next -> val = root -> val;
    root -> val = temp;
    } else mergeKlists(root->next);
}

void printLista(struct ListNode* root){
    if (root -> next == NULL)
    return;
    printf("%d  ",root -> val);
    printLista(root -> next);
    return;
}

int main() {
struct ListNode* new = criaLista(3);
addLista(2,new);
addLista(9,new->next);
addLista(7,new->next->next);
mergeKlists(new);
printLista(new);
free(new -> next -> next -> next);
free(new -> next -> next);
free(new -> next);
free(new);
}
// EXP 11 - DOUBLY LINKED LIST (Forward + Backward)
// Compile: cc exp11.c    Run: ./a.out
#include <stdio.h>
#include <stdlib.h>

struct node { int info; struct node *llink, *rlink; };
typedef struct node *NODE;
NODE first = NULL;

void insert() {
    NODE temp; int item;
    printf("Enter value: "); scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item; temp->llink = NULL; temp->rlink = NULL;
    if (first == NULL) { first = temp; return; }
    first->llink = temp;    // old first's left = new node
    temp->rlink  = first;   // new node's right = old first
    first = temp;           // new node is now first
    printf("%d inserted\n", item);
}

void del() {
    NODE cur;
    if (first == NULL) { printf("Empty\n"); return; }
    cur = first;
    first = first->rlink;
    if (first != NULL) first->llink = NULL;
    printf("%d deleted\n", cur->info);
    free(cur);
}

void display_forward() {
    NODE cur = first;
    if (first == NULL) { printf("Empty\n"); return; }
    printf("Forward:  ");
    while (cur != NULL) { printf("%d\t", cur->info); cur = cur->rlink; }
    printf("\n");
}

void display_backward() {
    NODE cur = first;
    if (first == NULL) { printf("Empty\n"); return; }
    while (cur->rlink != NULL) cur = cur->rlink;   // go to last node
    printf("Backward: ");
    while (cur != NULL) { printf("%d\t", cur->info); cur = cur->llink; }
    printf("\n");
}

void main() {
    int option;
    do {
        printf("1.Insert 2.Delete 3.Forward 4.Backward 5.Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: insert();           break;
            case 2: del();              break;
            case 3: display_forward();  break;
            case 4: display_backward(); break;
            case 5: exit(0);
        }
    } while (option != 5);
}

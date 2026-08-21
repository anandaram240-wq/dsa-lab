// EXP 10 - ORDERED LINKED LIST (always sorted!)
// Compile: cc exp10.c    Run: ./a.out
#include <stdio.h>
#include <stdlib.h>

struct node { int info; struct node *link; };
typedef struct node *NODE;
NODE first = NULL;

void insert() {
    NODE temp, cur, prev; int item;
    printf("Enter value: "); scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item; temp->link = NULL;

    if (first == NULL) { first = temp; return; }         // empty list
    if (item < first->info) {                            // insert at front
        temp->link = first; first = temp; return;
    }
    cur = first; prev = cur;
    while (cur != NULL && item > cur->info) { prev = cur; cur = cur->link; }
    prev->link = temp; temp->link = cur;                 // insert in middle/end
    printf("%d inserted\n", item);
}

void display() {
    NODE cur = first;
    if (first == NULL) { printf("Empty\n"); return; }
    while (cur != NULL) { printf("%d\t", cur->info); cur = cur->link; }
    printf("\n");
}

void main() {
    int option;
    do {
        printf("1.Insert 2.Display 3.Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: insert();  break;
            case 2: display(); break;
        }
    } while (option != 3);
}
// Try: Insert 55, 11, 22 -> Display shows 11  22  55 (sorted!)

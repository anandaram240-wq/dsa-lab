// EXP 7 - CIRCULAR LINKED LIST
// Compile: cc exp7.c    Run: ./a.out
#include <stdio.h>
#include <stdlib.h>

struct node { int info; struct node *link; };
typedef struct node *NODE;
NODE first = NULL;

void insert() {
    NODE temp, cur; int item;
    printf("Enter value: "); scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = temp;             // points to itself
    if (first == NULL) { first = temp; return; }
    cur = first;
    while (cur->link != first) cur = cur->link;  // go to last
    cur->link = temp;
    temp->link = first;            // new node -> first (circular!)
    printf("%d inserted\n", item);
}

void del() {
    NODE cur;
    if (first == NULL) { printf("Empty\n"); return; }
    if (first->link == first) {    // only 1 node
        printf("%d deleted\n", first->info);
        free(first); first = NULL; return;
    }
    cur = first;
    while (cur->link != first) cur = cur->link;  // go to last
    cur->link = first->link;
    printf("%d deleted\n", first->info);
    free(first);
    first = cur->link;
}

void display() {
    NODE cur;
    if (first == NULL) { printf("Empty\n"); return; }
    cur = first;
    while (cur->link != first) { printf("%d\t", cur->info); cur = cur->link; }
    printf("%d\n", cur->info);     // print last node
}

void main() {
    int option;
    do {
        printf("1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: insert();  break;
            case 2: del();     break;
            case 3: display(); break;
            case 4: exit(0);
        }
    } while (option != 4);
}

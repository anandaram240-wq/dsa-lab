// EXP 8 - SINGLY LINKED LIST
// Compile: cc exp8.c    Run: ./a.out
#include <stdio.h>
#include <stdlib.h>

struct node { int info; struct node *link; };
typedef struct node *NODE;
NODE first = NULL;

void insert() {
    NODE temp; int item;
    printf("Enter value: "); scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = first;   // new node points to old first
    first = temp;         // new node IS now first
    printf("%d inserted\n", item);
}

void del() {
    NODE cur, prev; int key;
    printf("Enter value to delete: "); scanf("%d", &key);
    if (first == NULL) { printf("Empty\n"); return; }
    if (key == first->info) {
        cur = first; first = first->link;
        printf("%d deleted\n", cur->info); free(cur); return;
    }
    cur = first; prev = NULL;
    while (cur != NULL && cur->info != key) { prev = cur; cur = cur->link; }
    if (cur == NULL) { printf("Not found\n"); return; }
    prev->link = cur->link;
    printf("%d deleted\n", cur->info); free(cur);
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

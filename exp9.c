// EXP 9 - SINGLY LL + MAX / MIN / SUM
// Compile: cc exp9.c    Run: ./a.out
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
    temp->link = first;
    first = temp;
    printf("%d inserted\n", item);
}

void display() {
    NODE cur = first;
    if (first == NULL) { printf("Empty\n"); return; }
    while (cur != NULL) { printf("%d\t", cur->info); cur = cur->link; }
    printf("\n");
}

void findMax() {
    int max; NODE ptr = first;
    if (first == NULL) { printf("Empty\n"); return; }
    max = first->info;
    while (ptr != NULL) { if (ptr->info > max) max = ptr->info; ptr = ptr->link; }
    printf("Maximum = %d\n", max);
}

void findMin() {
    int min; NODE ptr = first;
    if (first == NULL) { printf("Empty\n"); return; }
    min = first->info;
    while (ptr != NULL) { if (ptr->info < min) min = ptr->info; ptr = ptr->link; }
    printf("Minimum = %d\n", min);
}

void findSum() {
    int sum = 0; NODE ptr = first;
    while (ptr != NULL) { sum += ptr->info; ptr = ptr->link; }
    printf("Sum = %d\n", sum);
}

void main() {
    int option;
    do {
        printf("1.Insert 2.Display 3.Max 4.Min 5.Sum 6.Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: insert();  break;
            case 2: display(); break;
            case 3: findMax(); break;
            case 4: findMin(); break;
            case 5: findSum(); break;
            case 6: exit(0);
        }
    } while (option != 6);
}

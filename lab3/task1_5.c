#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void append(Node **head, int new_data);
void directPrint(Node *head);
void reversePrint(Node *head);
void freeList(Node *head);


int main() {
    Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    directPrint(head);
    reversePrint(head);

    freeList(head);

    return EXIT_SUCCESS;
}

void append(Node** head, int new_data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        new_node->prev = NULL;
        return;
    }

    Node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
    new_node->prev = last;
}

void directPrint(Node *head) {
    Node *pointer = head;
    printf("Printout in direct order: ");
    while (pointer != NULL) {
        printf("%d ", pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
}

void reversePrint(Node *head) {
    if (head == NULL) return;

    Node *pointer = head;
    while (pointer->next != NULL) {
        pointer = pointer->next;
    }

    printf("Printout in reverse order: ");
    while (pointer != NULL) {
        printf("%d ", pointer->data);
        pointer = pointer->prev;
    }
    printf("\n");
}

void freeList(Node *head) {
    Node *pointer;
    while (pointer != NULL) {
        pointer = head;
        head = head->next;
        free(pointer);
    }
}
//Create a Doubly linked list using integer data type

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()

{
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head = first;

    first->data = 10;
    first->next = second;
    first->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = first;

    third->data = 30;
    third->next = NULL;
    third->prev = second;

    printf("Traversing in forward direction:\n");
    struct Node *current = head;
    printf("NULL ->");
    
    while (current != NULL) {
        printf(" Data: %d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");

    printf("Traversing in reverse:\n");
    current = third;
    printf("NULL <-");
    while (current != NULL) {
        printf(" Data: %d <-", current->data);
        current = current->prev;
    }
    printf("NULL\n");

    free(head);
    free(first);
    free(second);
    free(third);
    
    return 0;
}
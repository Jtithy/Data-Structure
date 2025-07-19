//Create a Doubly linked list using string data type

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data[100];
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

    head->next = first;

    strcpy(first->data, "Node 1");
    first->next = second;
    first->prev = NULL;

    strcpy(second->data, "Node 2");
    second->next = third;
    second->prev = first;

    strcpy(third->data, "Node 3");
    third->next = NULL;
    third->prev = second;

    struct Node *current = first;
    printf("Traversing in forward direction:\n");
    printf("NULL -> ");
    while (current != NULL) {
        printf("Data: %s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    current = third;
    printf("Traversing in reverse:\n");
    printf("NULL <- ");
    while (current != NULL) {
        printf("Data: %s <- ", current->data);
        current = current->prev;
    }
    printf("NULL\n");

    free(head);
    free(first);
    free(second);
    free(third);

    return 0;
}

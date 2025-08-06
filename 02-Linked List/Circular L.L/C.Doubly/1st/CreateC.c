//Create a Circular Doubly linked list using integer data type

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
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    head->prev = third;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = head;
    third->prev = second;

    struct Node *current = head;
    while (current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next;
    }
    printf("NULL\n");
    current = third;
    while (current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->prev;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);
    
    return 0;
}
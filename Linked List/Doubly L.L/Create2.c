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
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->data, "Node 1");
    head->next = second;
    head->prev = NULL;

    strcpy(second->data, "Node 2");
    second->next = third;
    second->prev = head;

    strcpy(third->data, "Node 3");
    third->next = NULL;
    third->prev = second;

    struct Node *current = head;
    while (current != NULL) {
        printf("Data: %s\n", current->data);
        current = current->next;
    }
    printf("NULL\n");
    current = third;
    while (current != NULL) {
        printf("Data: %s\n", current->data);
        current = current->prev;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);

    return 0;
}

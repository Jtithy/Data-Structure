//Create a Doubly linked list using string & integer data type

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int age;
    char name[100];
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

    strcpy(first->name, "Node 1");
    first->age = 21;
    first->next = second;
    first->prev = NULL;

    strcpy(second->name, "Node 2");
    second->age = 22;
    second->next = third;
    second->prev = first;

    strcpy(third->name, "Node 3");
    third->age = 23;
    third->next = NULL;
    third->prev = second;

    printf("Traversing in forward direction:\n");
    struct Node *current = head;

    printf("NULL -> ");
    while (current != NULL) {
        printf("Data: %s, Age: %d -> ", current->name, current->age);
        current = current->next;
    }
    printf("NULL\n");

    printf("Traversing in backward direction:\n");
    current = third;
    
    printf("NULL <- ");
    while (current != NULL) {
        printf("Data: %s, Age: %d <- ", current->name, current->age);
        current = current->prev;
    }
    printf("NULL\n");

    free(head);
    free(first);
    free(second);
    free(third);

    return 0;
}

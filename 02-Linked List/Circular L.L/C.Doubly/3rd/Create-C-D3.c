//Create a Circular Doubly linked list using string & integerdata type

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
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->name, "Node 1");
    head->age = 21;
    head->next = second;
    head->prev = third;

    strcpy(second->name, "Node 2");
    second->age = 22;
    second->next = third;
    second->prev = head;

    strcpy(third->name, "Node 3");
    third->age = 23;
    third->next = head;
    third->prev = second;

    struct Node *current = head;
    while (current != NULL) {
        printf("Data: %s, Age: %d\n", current->name, current->age);
        current = current->next;
    }
    printf("NULL\n");
    current = third;
    while (current != NULL) {
        printf("Data: %s, Age: %d\n", current->name, current->age);
        current = current->prev;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);

    return 0;
}
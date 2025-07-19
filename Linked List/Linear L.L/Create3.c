//Create a singly linked list using string & integer data type

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int age; 
    char name[100];
    struct Node *next;
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

    strcpy(first->name, "Levi Ackerman");
    first->age = 25;
    first->next = second;

    strcpy(second->name, "Gojo Satoru");
    second->age = 28;
    second->next = third;

    strcpy(third->name, "Megumi Fushiguro");
    third->age = 21;
    third->next = NULL;

    struct Node *current = head;
    if(current == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("Linked List: ");
        while(current != NULL) {
            printf("%s (%d)-> ", current->name, current->age);
            current = current->next;
        }
        printf("NULL\n");
    }
    
    free(head);
    free(second);
    free(third);

    return 0;
}

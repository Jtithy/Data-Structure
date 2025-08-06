//Insert elements at head in a linear linked list

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
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->name, "Levi Ackerman");
    head->age = 25;
    head->next = second;

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

    // Insert a new node at the head
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, "Eren Yeager");
    newNode->age = 20;
    newNode->next = head;
    head = newNode;

    // Print the updated linked list
    current = head;
    if(current != NULL) {
        printf("Updated Linked List: ");
        while(current != NULL) {
            printf("%s (%d)-> ", current->name, current->age);
            current = current->next;
        }
        printf("NULL\n");
    } else {
        printf("The linked list is now empty.\n");
    }

    // Free allocated memory
    
    free(head);
    free(second);
    free(third);

    return 0;
}
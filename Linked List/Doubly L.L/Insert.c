//Insert elements at a specific position in a doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int age;
    char name[100];
    struct Node *next;
    struct Node *prev;
};

int main() {
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    first = head;

    strcpy(first->name, "Levi Ackerman");
    first->age = 25;
    first->next = second;
    first->prev = NULL;

    strcpy(second->name, "Gojo Satoru");
    second->age = 28;
    second->next = third;
    second->prev = first;

    strcpy(third->name, "Megumi Fushiguro");
    third->age = 21;
    third->next = NULL;
    third->prev = second;

    printf("Original Doubly Linked List: \n");
    struct Node *current = head;

    printf("Forward: \n");
    while(current != NULL) {
        printf("%s (%d)-> ", current->name, current->age);
        current = current->next;
    }
    printf("NULL\n");

    current = third;
    printf("Backward: \n");
    while(current != NULL) {
        printf("%s (%d)<- ", current->name, current->age);
        current = current->prev;
    }
    printf("NULL\n");

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, "Eren Yeager");
    newNode->age = 20;
    newNode->next = NULL;

    int position;
    printf("Enter the position to insert the new node (1 for head): ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position! Position must be 1 or greater.\n");
        free(newNode);
    } else if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node *prev = head;
        int i = 1;
        while (prev != NULL && i < position - 1) {
            prev = prev->next;
            i++;
        }
        if (prev == NULL) {
            printf("Position out of bounds.\n");
            free(newNode);
        } else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    // Updated doubly linked list
    printf("Updated Doubly Linked List: \n");
    current = head;

    printf("Forward: \n");
    while(current != NULL) {
        printf("%s (%d)-> ", current->name, current->age);
        current = current->next;
    }
    printf("NULL\n");

    current = third;
    
    printf("Backward: \n");
    while(current != NULL) {
        printf("%s (%d)<- ", current->name, current->age);
        current = current->prev;
    }
    printf("NULL\n");

    // Free the whole list safely
    current = head;
    struct Node *temp;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(first);
    free(second);
    free(third);
    free(newNode);

    return 0;
}

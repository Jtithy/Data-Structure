//Insert elements at a specific position in a linear linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int age;
    char name[100];
    struct Node *next;
};

int main() {
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
    printf("Original Linked List: ");
    while(current != NULL) {
        printf("%s (%d)-> ", current->name, current->age);
        current = current->next;
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

    current = head;
    printf("Updated Linked List: ");
    while(current != NULL) {
        printf("%s (%d)-> ", current->name, current->age);
        current = current->next;
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

    return 0;
}

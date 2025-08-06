//Search element at a specific position and delete it in a singly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    char data2[100];
    struct Node *next;
};

int main() {
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
    strcpy(first->data2, "First");
    first->next = second;

    second->data = 20;
    strcpy(second->data2, "Second");
    second->next = third;

    third->data = 30;
    strcpy(third->data2, "Third");
    third->next = NULL;

    struct Node *current = head;
    if(current == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("Linked List: ");
        while(current != NULL) {
            printf("%d (%s) -> ", current->data, current->data2);
            current = current->next;
        }
        printf("NULL\n");
    }

    int position;
    printf("Enter the position to search for (1-based index): ");
    scanf("%d", &position);
    if(position < 1) {
        printf("Invalid position. Please enter a positive integer.\n");
        return 1;
    }
    
    current = head;
    int count = 1;

    while(current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if(current != NULL) {
        printf("Element at position %d: %d (%s)\n", position, current->data, current->data2);
    } else {
        printf("Position %d does not exist in the linked list.\n", position);
    }

    // Delete the element at the specified position

    if(position == 1 && head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Head element deleted.\n");
    } else {
        current = head;
        struct Node *prev = NULL;
        count = 1;

        while(current != NULL && count < position) {
            prev = current;
            current = current->next;
            count++;
        }

        if(current != NULL) {
            prev->next = current->next;
            free(current);
            printf("Element at position %d deleted.\n", position);
        } else {
            printf("Position %d does not exist in the linked list.\n", position);
        }
    }

    // Print the updated linked list

    current = head;
    if(current != NULL) {
        printf("Updated Linked List: ");
        while(current != NULL) {
            printf("%d (%s) -> ", current->data, current->data2);
            current = current->next;
        }
        printf("NULL\n");
    } else {
        printf("The linked list is now empty.\n");
    }

    // Free allocated memory
    free(head);
    free(first);
    free(second);
    free(third);

    return 0;
}

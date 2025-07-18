//Search element at a specific position and delete it in a doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    char data2[100];
    struct Node *next;
    struct Node *prev; 
};

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    strcpy(head->data2, "First");
    head->next = second;
    head->prev = NULL; 

    second->data = 20;
    strcpy(second->data2, "Second");
    second->next = third;
    second->prev = head;

    third->data = 30;
    strcpy(third->data2, "Third");
    third->next = NULL;
    third->prev = second;

    printf("Doubly Linked List (Forward): \n");
    struct Node *current = head;
    if(current != NULL)
    {
        while(current != NULL) {
            printf("%d (%s) -> ", current->data, current->data2);
            current = current->next;
        }
        printf("NULL\n");
    }

    printf("Doubly Linked List (Backward): \n");
    current = third;
    if(current != NULL)
    {
        while(current != NULL) {
            printf("%d (%s) <- ", current->data, current->data2);
            current = current->prev;
        }
        printf("NULL\n");
    }

    // Search for an element at a specific position
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

    // Deleting the node at the specified position
    if(current != NULL) {
        if(current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next; // Update head if deleting the first node
        }
        
        if(current->next != NULL) {
            current->next->prev = current->prev;
        }

        free(current);
        printf("Node at position %d deleted successfully.\n", position);
    } else {
        printf("No node found at position %d to delete.\n", position);
    }

    // Display the list after deletion
    printf("Doubly Linked List after deletion: \n");
    current = head;
    printf("Doubly Linked List (Forward): \n");
    while(current != NULL) {
        printf("%d (%s) -> ", current->data, current->data2);
        current = current->next;
    }
    printf("NULL\n");

    current = third;
    printf("Doubly Linked List (Backward): \n");
    while(current != NULL) {
        printf("%d (%s) <- ", current->data, current->data2);
        current = current->prev;
    }
    printf("NULL\n");

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}

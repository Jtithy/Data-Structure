//Search element at a specific position in a linear linked list

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
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    strcpy(head->data2, "First");
    head->next = second;

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

    free(head);
    free(second);
    free(third);

    return 0;
}

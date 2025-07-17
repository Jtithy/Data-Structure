//Search element at head in a linear linked list 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    char data2[100];
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

    // Search for an element at the head
    if (head != NULL) {
        printf("Head Element: %d, %s\n", head->data, head->data2);
    } else {
        printf("The linked list is empty.\n");
    }

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}

//Create a singly linked list using string data type

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[100];
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

    strcpy(head->data, "First Node");
    head->next = second;

    strcpy(second->data, "Second Node");
    second->next = third;

    strcpy(third->data, "Third Node");
    third->next = NULL;

    struct Node *current = head;
    if(current == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("Linked List: ");
        while(current != NULL) {
            printf("%s -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
    
    free(head);
    free(second);
    free(third);
    
    return 0;
}

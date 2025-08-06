//Create a linear linked list using a function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node* next;
};

struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* createLinkedList() {
    struct node* head = NULL;
    struct node* tail = NULL;
    char choice;

    do {
        char data;
        printf("Enter a character: ");
        scanf(" %c", &data);

        struct node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

void printLinkedList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* linkedList = createLinkedList();
    printf("The created linked list is: ");
    printLinkedList(linkedList);

    // Free the allocated memory
    struct node* current = linkedList;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
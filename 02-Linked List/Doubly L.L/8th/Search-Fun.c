//Create a doubly linked list for searching for any specific element at any position using function

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display() {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insertAtEnd(5);
    insertAtEnd(10);
    insertAtEnd(15);
    insertAtEnd(20);
    insertAtEnd(25);
    insertAtEnd(30);

    display();
    printf("\n");

    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    int position = search(value);
    if (position != -1) printf("Found at position %d\n", position);
    else printf("Not found\n");

    return 0;
}

//Create a doubly linked list and display it in both forward and backward directions using functions.

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

void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void displayForward() {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayBackward() {
    Node* temp = head;
    if (!temp) return;
    while (temp->next) temp = temp->next;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {
    insertAtEnd(10);
    insertAtEnd(15);
    insertAtEnd(20);
    insertAtEnd(25);
    insertAtBeginning(5);

    displayForward();
    printf("\n");
    displayBackward();
}

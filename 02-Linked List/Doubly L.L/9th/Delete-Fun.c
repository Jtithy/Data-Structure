//Create a doubly linked list for deleting any specific element at any position using function

#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* prev;
struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (head == NULL) {
newNode->prev = NULL;
head = newNode;
return;
}
struct Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}

void deleteAtPosition(int position) {
if (head == NULL) return;
struct Node* temp = head;
int i = 1;
if (position == 1) {
head = temp->next;
if (head != NULL) head->prev = NULL;
free(temp);
return;
}
while (temp != NULL && i < position) {
temp = temp->next;
i++;
}
if (temp == NULL) {
printf("Position %d not found.\n", position);
return;
}
if (temp->next != NULL)
temp->next->prev = temp->prev;
if (temp->prev != NULL)
temp->prev->next = temp->next;
free(temp);
}

void display() {
struct Node* temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
insertEnd(100);
insertEnd(200);
insertEnd(300);
insertEnd(400);
insertEnd(500);
insertEnd(600);
insertEnd(700);
printf("Original List: ");
display();
int pos;
printf("Enter position to delete: ");
scanf("%d", &pos);
deleteAtPosition(pos);
printf("After Deleting Position %d: ", pos);
display();
return 0;
}
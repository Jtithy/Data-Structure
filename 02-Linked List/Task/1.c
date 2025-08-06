//Dynamic User Input Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    struct Node* prev;
    struct Node* next;
};

int main()
{
  struct Node* head = NULL;
  struct Node* tail = NULL;
  struct Node* newNode;
  int n, i;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter name for node %d: ", i + 1);
    scanf("%s", newNode->name);
    newNode->prev = tail;
    newNode->next = NULL;

    if (tail != NULL) {
      tail->next = newNode;
    } else {
      head = newNode;
    }
    tail = newNode;
  }
    printf("Doubly Linked List Forward: \n");
    struct Node* current = head;
    printf("NULL ->");
    while (current != NULL) {
        printf("%s ->", current->name);
        current = current->next;
    }
    printf("NULL\n");

    printf("Doubly Linked List Backward: \n");
    current = tail;
    printf("NULL ->");
    while (current != NULL) {
        printf("%s ->", current->name);
        current = current->prev;
    }
    printf("NULL\n");
    return 0;
}
//Create a program for Queue insertion and deletion using array.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, item;

    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(rear == SIZE - 1) {
                printf("Queue Overflow\n");
            } else {
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                if(front == -1) front = 0;
                rear++;
                queue[rear] = item;
            }
        } else if(choice == 2) {
            if(front == -1 || front > rear) {
                printf("Queue Underflow\n");
            } else {
                printf("Dequeued item: %d\n", queue[front]);
                front++;
            }
        } else if(choice == 3) {
            if(front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                for(int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
        } else if(choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

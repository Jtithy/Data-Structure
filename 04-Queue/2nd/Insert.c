//Write Program For Queue Insertion

#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void insert() {
    int x;
    printf("Enter value: ");
    scanf("%d", &x);
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

void view() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("1.Insert 2.View 3.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) insert();
        else if (ch == 2) view();
        else if (ch == 3) break;
        else printf("Invalid\n");
    }
    return 0;
}

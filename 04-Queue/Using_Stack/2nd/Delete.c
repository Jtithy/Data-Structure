// Create a queue using stack with enqueue and view operations

#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
int pop1() { return stack1[top1--]; }
void push2(int x) { stack2[++top2] = x; }
int pop2() { return stack2[top2--]; }

void enqueue() {
    int x;
    printf("Enter value: ");
    scanf("%d", &x);
    push1(x);
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (top2 == -1) {
        while (top1 != -1)
            push2(pop1());
    }
    printf("Deleted: %d\n", pop2());
}

void view() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    int temp1 = top1, temp2 = top2;
    for (int i = temp2; i >= 0; i--)
        printf("%d ", stack2[i]);
    for (int i = 0; i <= temp1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.View 4.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) view();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}

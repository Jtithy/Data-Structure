// Write a program for creating a Queue using Stack.

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

void view() {
    if (top1 == -1) {
        printf("Queue is empty\n");
        return;
    }
    top2 = -1;
    for (int i = 0; i <= top1; i++)
        push2(stack1[i]);
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("1.Enqueue 2.View 3.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) enqueue();
        else if (ch == 2) view();
        else if (ch == 3) break;
        else printf("Invalid\n");
    }
    return 0;
}

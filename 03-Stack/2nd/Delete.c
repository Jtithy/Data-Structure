//Create a stack and implement push and pop operations with delete functionality.

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int choice, val;
    while (1) {
        printf("1.Push\n2.Pop\n3.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            val = pop();
            if (val != -1) printf("Deleted: %d\n", val);
            else printf("Stack Empty\n");
        } else if (choice == 3) {
            break;
        }
    }
    return 0;
}

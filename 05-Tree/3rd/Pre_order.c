// In-order Traversal of a Binary Tree in C

#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to build the tree
struct Node* buildTree() {
    int data;
    printf("Enter node data (or -1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* root = createNode(data);

    printf("Enter left child of %d:\n", data);
    root->left = buildTree();

    printf("Enter right child of %d:\n", data);
    root->right = buildTree();

    return root;
}

// Function for Pre-order traversal (Root, Left, Right)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    printf("--- Tree Creation ---\n");
    root = buildTree();

    printf("\n--- Pre-order Traversal ---\n");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}
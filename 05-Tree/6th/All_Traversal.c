#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode (struct Node* root, int data){
    if(root == NULL) return createNode(data);
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preOrder(struct Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node* root = NULL;
    int n;
    int value;

    printf("Enter number of data: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Pre-Order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

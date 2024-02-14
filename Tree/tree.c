#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node* createNode(int data) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node* insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value > root->data) {
        root->right = insert(root->right, value);
    }

    else if (value < root->data) {
        root->left = insert(root->left, value);
    }

    return root;
}

void inOrder(Node *root) 
{
    if (root != NULL) {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node *root) 
{
    if (root != NULL) {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) 
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}

void deleteTree(Node *root)
{
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() 
{
    Node *root;

    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 5); 
    root = insert(root, 24);  
    inOrder(root);
    deleteTree(root);
    return 0;
}

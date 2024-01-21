#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;
    n->right = NULL;
    n->left = NULL;

    return n;
}

Node* insert(Node *root, int value) 
{
    if (root == NULL) {
        return createNode(value);
    }
    
    else if (value > root->data) {
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
    Node *root = createNode(20);
    
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 23);
    root = insert(root, 5);

    inOrder(root);
    deleteTree(root);
    return 0;
}

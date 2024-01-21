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

int main() 
{
    return 0;
}

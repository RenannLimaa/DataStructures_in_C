#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node* createNode(int value) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data  = value;
    n->right = NULL;
    n->left  = NULL;

    return n;
}

void insertAtLeft(Node **node, int el)
{
    if ((*node)->left == NULL) {
        Node *newNode = createNode(el);
        (*node)->left = newNode;
    }

    else {
        if (el < (*node)->left->data)
            insertAtLeft((*node)->left, el);
        else 
            insertAtRight((*node)->left, el);
    }
}


void insert(Node **root, int el) 
{
    Node *newNode = createNode(el);

    if (*root == NULL) 
        *root = newNode;

    else {
        if (el > (*root)->data) 
            (*root)->right = newNode;
        else 
            (*root)->left  = newNode;
    }
}

int main() 
{
    return 0;
}

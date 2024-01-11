#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *rChild;
    struct Node *lChild;
} Node 

Node* createNode(int value) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->rChild = NULL;
    n->lChild = NULL;

    return n;
}

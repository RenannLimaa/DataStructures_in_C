#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;

    return n;
}

void push(Node **top, int value) 
{
    Node *newNode = createNode(value);
    if (*top == NULL) {
        *top = newNode;
        return;
    }

    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top) 
{
    int el;

    if ((*top)->next == NULL) {
        *top = NULL;
        free(*top);
    }

    else {
        Node *tmp = *top;
        *top = (*top)->next;
        
        el = tmp->data;
        tmp->next = NULL;
        free(tmp);
    }
    
    return el;
}

void printStack(Node **top) 
{
    if (*top == NULL) {
        printf("printStack: empty list!)\n");
        return;
    }

    Node *tmp = *top;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

void deleteStack(Node **top) 
{
    if (*top == NULL) {
        printf("deleteStack: empty stack!\n");
        return;
    }

    Node *tmp;
    while ((*top)->next != NULL) {
        tmp = *top;
        *top = (*top)->next;

        free(tmp);
    }
}

int main() 
{
    Node *top = createNode(0);

    push(&top, 2);
    push(&top, 1);

    printStack(&top);
    
    printf("Element removed: %d\n", pop(&top));
    printStack(&top);
    deleteStack(&top);
    return 0;
}

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

void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode(value);
    newNode->data = value;
    newNode->next = *head; 

    if (*head == NULL) {
       *head = newNode; 
    }
    
    else {
        Node *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = newNode; 
    }
}

void removeFromEnd(Node **head)
{
    if ((*head)->next == NULL) {
        *head = NULL;
        free(*head);
    }

    else {
        Node *current = *head;
        Node *prev;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        free(current);
        prev->next = *head;
    }
}


int main() 
{
    Node *head = createNode(1);
    removeFromEnd(&head);
    return 0;
}

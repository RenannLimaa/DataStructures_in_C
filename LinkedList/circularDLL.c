#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int value) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;
    n->next = n;
    n->prev = NULL;

    return n;
}

void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *tmp = *head;
    while (tmp->next != *head) {
        tmp = tmp->next;
    }

    tmp->next = newNode;

    newNode->next = *head;
    newNode->prev = tmp;
}

void insertAtBeginning(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *tmp = *head;
    while (tmp->next != *head) {
        tmp = tmp->next;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;

    tmp->next = *head;
}
void deleteList(Node **head)
{
    if (*head == NULL) {
        printf("deleteList: empty list!\n");
        return;
    }

    Node *tmp, *current = *head;
    do {
        tmp = current;
        current = current->next;
        free(tmp);
    } while (current != *head);
}

void printList(Node **head) 
{
    if (*head == NULL) {
        printf("printList: empty list!\n");
        return;
    }

    Node *tmp = *head;
    do {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    } while (tmp != *head);
}
int main() 
{
    Node *head;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);
    printList(&head);
    deleteList(&head);
}

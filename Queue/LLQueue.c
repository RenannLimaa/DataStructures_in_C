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

void enqueue(Node **head, int value) 
{
    Node *newNode = createNode(value);

    if (*head == NULL) {
        printf("enqueue: queue is empty!\n");
        return;
    }

    Node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    
    tmp->next = newNode;
}
    
void dequeue(Node **head) 
{
    if ((*head)->next == NULL) {
        *head = NULL;
        free(*head);
        return;
    }

    Node *tmp = *head;
    *head = (*head)->next;

    tmp->next = NULL;
    free(tmp);
}

int peek(Node **head) 
{
    if (head == NULL) {
        printf("peek: queue empty!\n");
        return -1;    
    }

    return (*head)->data;
}

int getSize(Node **head) 
{
    if (*head == NULL) {
        printf("getSize: queue empty)");
        return 0;
    }

    Node *tmp = *head;
    int count = 0;
    while (tmp != NULL) {
        count++;
    }

    return count;
}

void printQueue(Node **head) 
{
    if (*head == NULL) {
        printf("printQueue: queue empty!\n");
        return;
    }

    Node *tmp = *head;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

void deleteQueue(Node **head) 
{
    if (*head == NULL) {
        printf("deleteQueue: queue is empty!\n");
        return;
    }

    Node *tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;

        free(tmp);
    }
}

int main() 
{
    Node *head = createNode(0);

    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    dequeue(&head);
    
    printQueue(&head);
    deleteQueue(&head);
}

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
    n->next = n;
    
    return n;
}

void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode(value); 

    if (*head == NULL) {
       *head = newNode; 
       newNode->next = *head;
    }
    
    else {
        Node *tmp = *head;
        while (tmp->next != *head) {
            tmp = tmp->next;
        }

        tmp->next = newNode; 
        newNode->next = *head;
    }
}

void insertAtBeginning(Node **head, int value)
{
    Node *newNode = createNode(value); 

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return; 
    }

    Node *tmp = *head;
    while (tmp->next != *head) {
        tmp = tmp->next;
    }
    newNode->next = *head;
    tmp->next = newNode;
    *head = newNode;
}
void removeFromEnd(Node **head)
{
    if ((*head)->next == *head) {
        *head = NULL;
        free(*head);
    }

    else {
        Node *current = *head;
        Node *prev;
        while (current->next != *head) {
            prev = current;
            current = current->next;
        }

        free(current);
        prev->next = *head;
    }
}

void printList(Node **head)
{
    Node *tmp = *head;
    if (*head == NULL) {
        printf("printList: Empty list!\n");
        return;
    }
   
    do {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    } while (tmp != *head);
  
}

void deleteList(Node **head) 
{
    if (*head == NULL) {
        printf("deleteList: Empty list!\n");
        return;
    }
   
    Node *tmp;
    Node *current = *head;
    do {
        tmp = current;
        current = current->next;
        free(tmp);
    } while (current != *head); 

    *head = NULL; 
}

int main() 
{
    Node *head;
    insertAtBeginning(&head, 20); 
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 12);
    insertAtBeginning(&head, 14);
    
    printList(&head);
    deleteList(&head);
    return 0;
}

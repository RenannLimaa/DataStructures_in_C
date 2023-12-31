#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

Node* createNode(int value) 
{
	Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
	n->prev = NULL;
    n->data = value;
	return n;
}

void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode(value);
    newNode->data = value;
    newNode->next = NULL;
        
    if (*head == NULL) {
        *head = newNode;
        newNode->prev = NULL;
    } 
    
    else {
        Node *tmp = *head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = newNode;
        newNode->prev = tmp;
    }
}

void insertAtBeginning(Node **head, int value) 
{
    Node *newNode = createNode(value);
    newNode->data = value;    
    newNode->prev = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;       
     }

    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
     }
}

void removeFromEnd(Node **head)
{
    Node *tmp = *head;
    if (tmp->next == NULL) {
        free(tmp);
        *head = NULL;
    }

    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
    
        Node *secondLast;
        secondLast = tmp->prev;
        secondLast->next = NULL;
    
        tmp->prev = NULL;
        free(tmp);
    }
}

void removeFromBeginning(Node **head)
{
    if ((*head)->next == NULL) {
        *head = NULL;
        free(*head);
    }
        
    else {
        Node *tmp = *head;

        *head = (*head)->next;
        (*head)->prev = NULL;
       
        tmp->next = NULL;
        free(tmp);
    }
}

void deleteList(Node **head) {
    Node *tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void printList(Node **head)
{
    if (*head == NULL)
        printf("Empty list!\n");
    
    Node *tmp = *head;
    while(tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }

}


void printReverseList(Node **head)
{
    if (*head == NULL)
        printf("Empty list!");
    
    Node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->prev;
    }

}

int main() 
{
	Node *head = createNode(10);

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    
    printList(&head); 
    deleteList(&head);
	return 0;
}

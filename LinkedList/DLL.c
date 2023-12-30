#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

Node* createNode() 
{
	Node *n = (Node *)malloc(sizeof(Node));
   // n->data = value;
    n->next = NULL;
	n->prev = NULL;

	return n;
}

void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode();
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

int main() 
{
	Node *head;

    insertAtEnd(&head, 10);

    printList(&head);
    
    deleteList(&head);
	return 0;
}

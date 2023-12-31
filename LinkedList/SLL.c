/*Study more about pointers: arrow operator, deferencing, etc.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int value) 
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->next = NULL;
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
	}

	else {
		Node *tmp = *head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		tmp->next = newNode;
	}
}

void insertAtBeginning(Node **head, int value)
{
	Node *newNode = createNode(value);

	if (*head == NULL) {
		*head = newNode;
		(*head)->data = value;
	}
	
	else {
		newNode->next 	= *head;
		newNode->data 	= value;
		*head	= newNode;	
	}
}

void removeFromEnd(Node **head) 
{

	Node *prev = NULL;
	Node *current = *head;

	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (prev == NULL) {
		free(current);
		*head = NULL;
	}

	else {
		prev->next = NULL;
		free(current);		
	}
}


void removeFromBeginning(Node **head) 
{
	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
	}

	else {
		Node *tmp = *head;
		*head = (*head)->next;

		tmp->next = NULL;
		free(tmp);
	}
}

void printList(Node **head)
{
	if (*head == NULL)
		printf("Empty list!\n");

	Node *tmp = *head;
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void deleteList(Node **head)
{
	Node *tmp;
	while (*head != NULL) {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

int main() 
{
    Node *head = createNode(8);
	
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 12);	
    insertAtBeginning(&head, 6);

	printList(&head);	
	deleteList(&head);
	return 0;
}

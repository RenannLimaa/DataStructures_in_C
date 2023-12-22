/*Study more about pointers: arrow operator, deferencing, etc.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

//1. create node
//2. check if list is empty.
//3. traverse the list to get the last node
//4. assign the next member of the last node to the new node.
void insertAtEnd(Node **head, int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	
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

//1. create node
//2. if list is empty, assign to the next member the value of new node
//3. assign to the next member of the new node the value of head
//4. assign to the head node the value of new node
void insertAtBeginning(Node **head, int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

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

void removeFromEnd(Node **head) //bugs when there is just one element in the list
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
	Node *head;
	
//	insertAtEnd(&head, 10);
//	insertAtEnd(&head, 12)	
//	insertAtEnd(&head, 14);
	insertAtBeginning(&head, 24);
//	insertAtEnd(&head, 24);
	printList(&head);
	
	deleteList(&head);
	return 0;
}

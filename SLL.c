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



void removeFromEnd(Node **head) //bugs when there is just one element in the list
{
	Node *prev = NULL;
	Node *last = *head;

	while (last->next != NULL) {
		prev = last;
		last = last->next;
	}

	prev->next = NULL;
	free(last);		
}

void printList(Node **head)
{
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
	
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 12);
	insertAtEnd(&head, 14);
	insertAtEnd(&head, 24);
	printList(&head);
	
	printf("\n");
	removeFromEnd(&head);
	printList(&head);
	deleteList(&head);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int 	data;
	struct 	Node *next;
}; typedef struct Node Node;

int isEmpty(Node **list) 
{
	return((*list)->next == NULL);
}

Node* createNode() 
{	
	Node *n 	= (Node *)malloc(sizeof(Node));
	n->next 	= NULL;

	return n;
}

void insert(Node* *list, int value)
{
	if (isEmpty(list)) {
		(*list)->data = value;
	}

	Node *tmp = *list;
	while (tmp != NULL) tmp = tmp->next;

	Node *n 	= createNode();
	tmp->next 	= n;
}

void delete(Node **list) 
{
	if (isEmpty(list)) {
		free(list);	
	}

	Node *current 	= *list;
	Node *tmp;
	while (current != NULL) {
		tmp 	= *list;
		current = current->next;
	}

	tmp->next = NULL;
	free(current);		
}

void display(Node **list)
{
	Node *tmp = *list;
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int main(void) 
{	
	Node *head = createNode();
	
	insert(&head, 10);	
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 11);

	display(&head);
	return 0;
}

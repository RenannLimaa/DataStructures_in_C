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
	n->next = NULL;
	n->next = NULL;

	return n;
}
int main() 
{
	Node *head = createNode();
	return 0;
}

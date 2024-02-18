#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node* createNode(int data) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node* insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value > root->data) {
        root->right = insert(root->right, value);
    }

    else if (value < root->data) {
        root->left = insert(root->left, value);
    }

    return root;
}

Node* removeNode(Node *root, int el) 
{
    if (root == NULL) {
        printf("removeNode: value not found or empty tree!\n");
        return NULL;
    }

    else {
        if (root->data == el) {
            if (root->right == NULL && root->left == NULL) {
                free(root);
                return NULL;
            }

            else if (root->right == NULL || root->left == NULL) {
                Node *tmp;
                if (root->right != NULL) 
                    tmp = root->right;
                else
                    tmp = root->left;

                free(root);
                return tmp;
            }
            else if (root->right != NULL && root->left != NULL) {
               Node *maxLeft = root->left; 
               Node *parent = root; 
               while (maxLeft->right != NULL) {
                   parent = maxLeft;
                   maxLeft = maxLeft->right;
               }
                
               root->data = maxLeft->data;
               parent->right = NULL;
               free(maxLeft);
               return root;
            }
        }

        else if (el > root->data) 
            root->right = removeNode(root->right, el);
        else
            root->left = removeNode(root->left, el);
    }

    return root;
}

void inOrder(Node *root) 
{
    if (root != NULL) {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node *root) 
{
    if (root != NULL) {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) 
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}

void deleteTree(Node *root)
{
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() 
{
    Node *root = NULL;

    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 2);
//    root = insert(root, 3);
 //   root = insert(root, 5); 
//    root = insert(root, 24);  
    preOrder(root);
    printf("\n");

    root = removeNode(root, 20);
    preOrder(root);
    deleteTree(root);
    return 0;
}

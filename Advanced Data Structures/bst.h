#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	struct node *left, *right, *parent;
}node;
typedef struct bst
{
	node *root;
}bst;
void init(bst *b1);
void insert(bst *b1, int val);
node* search(bst *b, int k);
void inorder(node *b1);
void inordertraversal(bst *b1);
void preorder(node *b1);
void preordertraversal(bst *b1);
void postorder(node *b1);
void postordertraversal(bst *b1);
int max(node *b1);
int min(node *b1);
int maxelement(bst *b1);
int minelement(bst *b1);
int succ(node *b1);
int successor(bst *b1, int k);
int pred(node *b1);
int predecessor(bst *b1, int k);
void transplant(bst *b, node *u, node *v);
void treedelete(bst *b, node *z);
void deletenode(bst *b, int k);

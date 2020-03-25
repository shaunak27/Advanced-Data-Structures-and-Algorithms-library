#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
/* Initialize the binary search tree */

void init(bst *b1)
{
	b1->root = NULL;
}

/* Insert function to insert an integer value into the tree */
void insert(bst *b1, int val)
{
	node *b, *y;
	b = b1->root;
	while(b != NULL)
	{	
		y = b;
		if(val < b->key)
		{	
			b = b->left;
		}
		else
		{
			b = b->right;
		}
	}
	if(b1->root == NULL)	
	{
		b1->root = (node*)malloc(sizeof(node));
		(b1->root)->key = val;
		(b1->root)->left = NULL;
		(b1->root)->right = NULL;
		(b1->root)->parent = NULL;
		
	}
	else if(val < y->key)
	{
		y->left = (node*)malloc(sizeof(node));
		(y->left)->key = val;
		(y->left)->left = NULL;
		(y->left)->right = NULL;
		(y->left)->parent = y;
	}
	else
	{
		y->right = (node*)malloc(sizeof(node));
		(y->right)->key = val;
		(y->right)->left = NULL;
		(y->right)->right = NULL;
		(y->right)->parent = y;
	}
}
/* Search function returns the node if found and NULL, otherwise */
node* search(bst *b, int k)
{
	node *b1 = b->root;
	while(b1 != NULL)
	{
		if(k > b1->key)
		{
			b1 = b1->right;
		}
		else if(k < b1->key)
		{
			b1 = b1->left;
		}
		else if(k == b1->key)
		{
			return b1;
		}
	}
	return NULL;
}

/* Function to print Inorder Traversal of the tree */

void inorder(node *b1)
{
	if(b1 != NULL)
	{
		
		inorder((b1)->left);
		printf("%d ",(b1)->key);
		inorder((b1)->right);
	}
}
void inordertraversal(bst *b1)
{
	inorder(b1->root);
	if(b1->root != NULL)
	{
		printf("\n");
	}
}

/* Function to print Preorder Traversal of the tree */

void preorder(node *b1)
{
	if(b1 != NULL)
	{
		printf("%d ",(b1)->key);
		preorder((b1)->left);
		preorder((b1)->right);
	}
}
void preordertraversal(bst *b1)
{
	preorder(b1->root);
	if(b1->root != NULL)
	{
		printf("\n");
	}
}

/* Function to printf Postorder Traversal of the tree */

void postorder(node *b1)
{
	if(b1 != NULL)
	{
		
		postorder((b1)->left);
		postorder((b1)->right);
		printf("%d ",(b1)->key);
	}
}
void postordertraversal(bst *b1)
{
	postorder(b1->root);
	if(b1->root != NULL)
	{
		printf("\n");
	}
}

/* Function to maximum element */

int max(node *b1)
{
	node *b = b1;
	while(b->right!=NULL)
	{
		b = b->right;
	}
	return b->key;
}	

/* Function to find minimum element */

int min(node *b1)
{
	node *b = b1;
	while(b->left!=NULL)
	{
		b = b->left;
	}
	return b->key;
}

int maxelement(bst *b1)
{
	return max(b1->root);
}
int minelement(bst *b1)
{
	return min(b1->root);
}

/* Function to find Successor of input node  */

int succ(node *b1)
{
	if(b1->right != NULL)
	{
		return min(b1->right);
	}
	node *y = (b1->parent);
	node *x = b1;
	while(y != NULL && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y->key;
}
int successor(bst *b1, int k)
{
	node *y = search(b1, k);
	return succ(y);
}

/* Function to find Predecessor of input node   */

int pred(node *b1)
{
	if(b1->left != NULL)
	{
		return max(b1->left);
	}
	node *y = (b1->parent);
	node *x = b1;
	while(y != NULL && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return y->key;
}
int predecessor(bst *b1, int k)
{
	node *y = search(b1, k);
	return pred(y);
}

/* Function to transplant a branch to another node. Useful for deleting a node with two children */

void transplant(bst *b, node *u, node *v)
{
	if(u->parent == NULL)
	{
		b->root = v;
	}
	else if(u == (u->parent)->left)
	{
		(u->parent)->left = v;
	}
	else
	{
		(u->parent)->right = v;
	}
	if(v != NULL)
	{
		v->parent = u->parent;
	}
}

/* Delete Function to remove a particular node  */

void treedelete(bst *b, node *z)
{
	if(z->left == NULL)
	{
		transplant(b, z, z->right);
	}
	else if(z->right == NULL)
	{
		transplant(b, z, z->left);
	}
	else
	{
		int k = min(z->right);
		node *y = search(b, k);
		if(y->parent != z)
		{
			transplant(b, y, y->right);
			y->right = z->right;
			(y->right)->parent = y;
		}
		transplant(b, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}
void deletenode(bst *b, int k)
{
	node *y = search(b, k);
	if(y != NULL)
	{
		treedelete(b, y);
	}
}

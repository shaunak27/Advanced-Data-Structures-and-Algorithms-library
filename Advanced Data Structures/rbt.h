#include <stdio.h>
#include <stdlib.h>
struct rbtNode
{          
	int key;
	char color;
	struct rbtNode *left, *right,*parent;
}; 
struct rbtNode* root;
void leftRotate(struct rbtNode *x);
void rightRotate(struct rbtNode *y);
int search(int val);
void color_insert(struct rbtNode *z);
void insert(int val);
void inorderTree(struct rbtNode* root);
void postorderTree(struct rbtNode* root);
void traversal(struct rbtNode* root);
struct rbtNode* min(struct rbtNode *x);
struct rbtNode* successor(struct rbtNode *x);
void color_delete(struct rbtNode *x);
struct rbtNode* rdelete(int var);


#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MIN 2
struct btreeNode {
	int val[MAX + 1], count;
    struct btreeNode *link[MAX + 1];
};
struct btreeNode *root;
struct btreeNode * createNode(int val, struct btreeNode *child);
void addValToNode(int val, int pos, struct btreeNode *node, struct btreeNode *child);
void splitNode (int val, int *pval, int pos, struct btreeNode *node, struct btreeNode *child, struct btreeNode **newNode);
int setValueInNode(int val, int *pval, struct btreeNode *node, struct btreeNode **child);
void insertion(int val);
void copySuccessor(struct btreeNode *myNode, int pos);
void removeVal(struct btreeNode *myNode, int pos);
void doRightShift(struct btreeNode *myNode, int pos);
void doLeftShift(struct btreeNode *myNode, int pos) ;
void mergeNodes(struct btreeNode *myNode, int pos);
void adjustNode(struct btreeNode *myNode, int pos);
int delValFromNode(int val, struct btreeNode *myNode);
void deletion(int val, struct btreeNode *myNode);
void searching(int val, int *pos, struct btreeNode *myNode) ;
void traversal(struct btreeNode *myNode) ;


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct inode
{
	int data;
	struct inode* next;
}inode;
typedef struct queue
{
	inode * front, *rear;
}queue;
void qinit(queue*);
void enq(queue*, int);
int deq(queue*);
int isempty(queue*);
int isfull(queue*);
 

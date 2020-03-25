#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "qlist.h"
void qinit(queue *q)
{
	q->front = q->rear = NULL;
}
void enq(queue *q, int i)
{
	inode* temp = (inode*)malloc(sizeof(inode));
	if(!temp)
	{
		exit(1);
	}
	temp->data = i;
	if(!q->front)
	{
		temp->next = NULL;
		q->front = temp;
		q->rear = q->front;
		return;
	}
	q->rear->next = temp;
	temp->next = NULL;
	q->rear = temp;
}
int deq(queue *q)
{
	inode* temp = q->front;
	int rt = q->front->data;
	q->front = temp->next;
	free(temp);
	return rt;
}
int isempty(queue *q)
{
	return q->front == NULL;
}
int isfull(queue *q)
{
	return 0;
}
	
	
		

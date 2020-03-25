#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
void init(queue *q)
{
	q->front = q->rear = q->count = 0;
}
void enq(queue *q, char *str)
{
	q->arr[q->rear] = (char*)malloc(sizeof(str)+ 1);
	strcpy(q->arr[q->rear],str);
	q->rear = (q->rear + 1) % N;
	q->count++;
}
char* deq(queue *q)
{
	char *temp;
	temp = q->arr[q->front];
	q->front = (q->front + 1) % N;
	q->count--;
	return temp;
}
int isempty(queue *q)
{
	return q->count == 0;
}
int isfull(queue *q)
{
	return q->count == N;
}

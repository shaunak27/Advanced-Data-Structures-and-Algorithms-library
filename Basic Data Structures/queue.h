#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1600
typedef struct queue 
{
	char *arr[N];
	int front, rear, count;
}queue;
void init(queue*);
void enq(queue*, char*);
char* deq(queue*);
int isempty(queue*);
int isfull(queue*);


#include<stdio.h>
#include<stdlib.h>
#include "list.h"
typedef struct priority_queue
{
	list l1;
}priority_queue;
void pqinit(priority_queue *pq);
void pqenq(priority_queue *pq, int data);
int pqdeq(priority_queue *pq);
int pqfull(priority_queue *pq);
int pqempty(priority_queue *pq);
void pp(priority_queue *pq);

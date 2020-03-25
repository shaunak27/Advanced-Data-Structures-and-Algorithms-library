#include<stdio.h>
#include<stdlib.h>
#include "minpq.h"
void pqinit(priority_queue *pq)
{
	init(&(pq->l1));
}
void pqenq(priority_queue *pq, int data)
{
	insertsorted(&(pq->l1),data);
	sort(&(pq->l1));
}
int pqdeq(priority_queue *pq)
{
	return remitem(&(pq->l1));
}
int pqfull(priority_queue *pq)
{
	return 0;
}
int pqempty(priority_queue *pq)
{
	return isempty(pq->l1);
}
void pp(priority_queue *pq)
{
	printlistLR(pq->l1);
}

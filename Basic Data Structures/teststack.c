#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
int main()
{
	stack s;
	init(&s);
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	push(&s,6);
	push(&s,7);
	if(!isfull(&s))
	{
		push(&s,8);
	}
	while(!isempty(&s))
	{
		printf("%d\n",pop(&s));
	}
}

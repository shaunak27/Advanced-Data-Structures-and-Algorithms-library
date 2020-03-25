#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
int main()
{
	queue s;
	init(&s);
	enq(&s,"a");
	enq(&s,"b");
	enq(&s,"c");
	enq(&s,"d");
	enq(&s,"e");
	enq(&s,"f");
	while(!isempty(&s))
	{
		printf("%s\n",deq(&s));
	}
}

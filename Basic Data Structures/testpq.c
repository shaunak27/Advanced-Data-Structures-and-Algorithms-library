#include<stdio.h>
#include "minpq.h"
int main()
{
	priority_queue p;
	pqinit(&p);
	pqenq(&p,3);
	pqenq(&p,3);
	pqenq(&p,3);
	pqenq(&p,3);
	pqenq(&p,2);
	pqenq(&p,2);
	pqenq(&p,1);
	pqenq(&p,1);
	printf("%d\n",pqdeq(&p));
	printf("%d\n",pqdeq(&p));
	printf("%d\n",pqdeq(&p));
	printf("%d\n",pqdeq(&p));
	printf("%d\n",pqdeq(&p));
	printf("%d\n",pqdeq(&p));
	
	
}
	

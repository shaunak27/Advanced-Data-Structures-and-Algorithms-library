#include<stdio.h>
#include "list.h"
#include<stdlib.h>
int main()
{
	list l;
	init(&l);
	insertright(&l,12);
	insertright(&l,32);
	insertright(&l,25);
	insertright(&l,17);
	insertright(&l,66);
	insertright(&l,91);
	printlistLR(l);
	printf("%d\n",length(l));
	sort(&l);
	printlistLR(l);
	reverse(&l);
	printlistLR(l);
	
}
	

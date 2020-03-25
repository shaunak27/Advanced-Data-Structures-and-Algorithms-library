#include<stdio.h>
#include<stdlib.h>
#include "numlib.h"
int main()
{
	int N;
	printf("Enter Number\n");
	scanf("%d", &N);
	sieve_of_eratosthenes(N);
}

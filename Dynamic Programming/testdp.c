#include<stdio.h>
#include<stdlib.h>
#include "DP.h"
int main()
{
	char X[1000], Y[1000],A[1000],B[1000];
	int N, W,keyarr[1000],i,t;
	printf("Longest Increasing Subsequence of Numbers\n");
	printf("Enter size and all the elements\n");
	scanf("%d",&t);
	for(i = 0; i < t;i++)
	{
		scanf("%d",&keyarr[i]);
	}
	printf("Length of LIS is : %d\n",LIS(t, keyarr));
	printf("Longest Common Subsequence\n");
	printf("Enter Strings\n");
    scanf("%s",X);
    scanf("%s",Y);
	LCSS(X, Y);
	printf("Longest Common Subsequence\n");
	printf("Enter Strings\n");
    scanf("%s",A);
    scanf("%s",B);
	LCSW(A, B);
	printf("Knapsack Problem\n");
	printf("Enter Number of Items and Total Weight\n");
	scanf("%d%d", &N, &W);
	printf("Max Value: %d\n",knapsack(N,W));
}

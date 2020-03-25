#include<stdio.h>
#include<stdlib.h>

/* Prime Number upto N are printed onto the screen */

void sieve_of_eratosthenes(int N)
{
        int i, p;
        int *A = (int*)malloc((N + 1) * sizeof(int));
       	for(i = 0; i < N + 1; i++)
		{
			A[i] = 1;
		}
        for (p = 2; p*p <= N; p++)
        {
                if (A[p] == 1)
                {
                        for (i = p * 2; i <= N; i += p)
                        {
                                A[i] = 0;
                        }
                }
        }

        for (i = 2; i <= N; i++)
        {
                if (A[i])
                {
                        printf("%d\n", i);
                }
        }

}


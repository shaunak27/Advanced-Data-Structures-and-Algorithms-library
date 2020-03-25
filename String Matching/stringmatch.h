#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define d 256 
void getnumarray(char* pat, int M, int* lps); 

/*  Knuth Morris Pratt String Match Algorithm
	Input: Two Strings
	Output: Index of common string
*/

void KMPSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt);
    int ind[M]; 
    getnumarray(pat, M, ind); 
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) 
    { 
        	if (pat[j] == txt[i]) 
        	{ 
            	j++; 
            	i++; 
    		} 
		if (j == M) 
		{ 
    		printf("Found pattern at index %d\n", i - j); 
        	j = ind[j - 1]; 
    	}  
    	else if (i < N && pat[j] != txt[i]) 
    	{ 
    		if (j != 0)
    		{ 
        		j = ind[j - 1];
        	} 
        	else
        	{
            	i = i + 1;
        	} 
    	} 
    } 
} 
void getnumarray(char* pat, int M, int* ind) 
{ 
    int len = 0; 
    ind[0] = 0;
    int i = 1; 
    while (i < M) 
    { 
        if (pat[i] == pat[len]) 
        { 
            len++; 
            ind[i] = len; 
            i++; 
        } 
        else 
        {
            if (len != 0) 
            { 
                len = ind[len - 1]; 
            } 
            else
            { 
                ind[i] = 0; 
                i++; 
            } 
        } 
    } 
}  

/*  Rabin Karp String Match Algorithm
	Input: Two Strings
	Output: Index of common string
*/

void rabinkarp(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; 
    int t = 0; 
    int h = 1; 
    for (i = 0; i < M-1; i++) 
    {
        h = (h*d)%q; 
	}  
    for (i = 0; i < M; i++) 
    { 
        p = (d*p + pat[i])%q; 
        t = (d*t + txt[i])%q; 
    } 
    for (i = 0; i <= N - M; i++) 
    { 
        if ( p == t ) 
        { 
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
            if (j == M) 
            {
                printf("Pattern found at index %d \n", i); 
            }
        } 
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 

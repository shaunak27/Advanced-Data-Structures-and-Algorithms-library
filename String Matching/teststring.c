#include<stdio.h> 
#include<string.h> 
#include "stringmatch.h"
int main() 
{ 
    char txt[] = "AAAAAAAAAAB"; 
    char pat[] = "AAAB";
    printf("Original Strings\n%s\n%s\n",txt,pat);
    int q = 101;
    printf("Knuth-Morris-Pratt\n");
    KMPSearch(pat, txt); 
    printf("Rabin-Karp\n");
    rabinkarp(pat, txt, q);
    return 0; 
} 

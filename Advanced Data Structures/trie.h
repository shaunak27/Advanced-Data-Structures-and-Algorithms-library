#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define getsize(a) sizeof(a)/sizeof(a[0]) 
#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
typedef struct node 
{ 
    struct node *children[ALPHABET_SIZE]; 
    int endofword; 
}node; 
struct node *getnode(void);
void insert(node *root, const char *key);
int search(node *root, const char *key);
void printfunc(int i, const char *str);


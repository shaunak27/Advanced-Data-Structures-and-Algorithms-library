#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trie.h"

/* allocates and returns a new node */

struct node *getnode(void) 
{ 
    node *n = NULL; 
  
    n = (node *)malloc(sizeof(node)); 
  
    if (n) 
    { 
        int i; 
        n->endofword = 0; 
        for (i = 0; i < ALPHABET_SIZE; i++) 
            n->children[i] = NULL; 
    } 
  
    return n; 
} 

/* inserts a node according to the input character array  */

void insert(node *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    node *temp = root; 
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
        if (!temp->children[index]) 
            temp->children[index] = getnode(); 
  
        temp = temp->children[index]; 
    } 
    temp->endofword = 1; 
} 

/* search returns 1 if found and 0 otherwise */

int search(node *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    node *temp = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
  
        if (!temp->children[index]) 
            return 0; 
  
        temp = temp->children[index]; 
    } 
  
    return (temp != NULL && (temp->endofword == 1)); 
} 

/* prints the existence of element in btree  */

void printfunc(int i, const char *str)
{
	if(i == 0)
	{
		printf("%s:  NOT PRESENT IN TRIE\n", str);
	}
	else
	{
		printf("%s:  IS PRESENT IN TRIE\n", str);
	}
}	


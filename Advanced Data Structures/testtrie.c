#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trie.h"
int main() 
{ 
    char keys[][20] = {"shaunak", "coep", "computer"};    
    node *root = getnode(); 
    int i; 
    for (i = 0; i < getsize(keys); i++) 
        insert(root, keys[i]); 
    printfunc(search(root, "shaunak"), "shaunak");
    printfunc(search(root, "coep"),"coep");
    printfunc(search(root, "mech"), "mech");
    
    return 0; 
} 

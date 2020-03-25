#include<stdio.h>
#include<stdlib.h>
#include "AVL.h"
int main( int argc, char **argv ) {
	avl_tree_t *tree = NULL;
	int val, ch;
	tree = avl_create();
	while (1) {
                printf("1. Insertion\t2. Deletion\n");
                printf("3. Traversal\t");
                printf("4. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                case 1:
                scanf("%d",&val);
                avl_insert(tree, val);
                break;
				case 2:
				scanf("%d",&val);
                avl_delete(tree, val);
                break;	
                case 3:
				avl_traverse_dfs( tree );
				break;
				case 4:
				exit(0);
				default:
				printf("Invalid input\n");
	            }
	          }
	          
}


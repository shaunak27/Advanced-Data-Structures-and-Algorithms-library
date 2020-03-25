#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "AVL.h"

/* Create a new AVL tree. */

avl_tree_t *avl_create() {
	avl_tree_t *tree = NULL;

	if( ( tree = malloc( sizeof( avl_tree_t ) ) ) == NULL ) {
		return NULL;
	}

	tree->root = NULL;

	return tree;
}

/* Initialize a new node. */

avl_node_t *avl_create_node() {
	avl_node_t *node = NULL;
	
	if( ( node = malloc( sizeof( avl_node_t ) ) ) == NULL ) {
		return NULL;
	}

	node->left = NULL;
	node->right = NULL;
	node->value = 0;

	return node;	
}

/* Find the height of an AVL node recursively */

int avl_node_height( avl_node_t *node ) {
	int height_left = 0;
	int height_right = 0;

	if( node->left ) height_left = avl_node_height( node->left );
	if( node->right ) height_right = avl_node_height( node->right );

	return height_right > height_left ? ++height_right : ++height_left;
}

/* Find the balance of an AVL node */

int avl_balance_factor( avl_node_t *node ) {
	int bf = 0;

	if( node->left  ) bf += avl_node_height( node->left );
	if( node->right ) bf -= avl_node_height( node->right );

	return bf ;
}

/* Left Left Rotate */

avl_node_t *avl_rotate_leftleft( avl_node_t *node ) {
 	avl_node_t *a = node;
	avl_node_t *b = a->left;
	
	a->left = b->right;
	b->right = a;

	return( b );
}

/* Left Right Rotate */

avl_node_t *avl_rotate_leftright( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->left;
	avl_node_t *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;

	return( c );
}

/* Right Left Rotate */

avl_node_t *avl_rotate_rightleft( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->right;
	avl_node_t *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;

	return( c );
}

/* Right Right Rotate */

avl_node_t *avl_rotate_rightright( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->right;
	
	a->right = b->left;
	b->left = a; 

	return( b );
}

/* Balance a given node */

avl_node_t *avl_balance_node( avl_node_t *node ) {
	avl_node_t *newroot = NULL;

	
	if( node->left )
		node->left  = avl_balance_node( node->left  );
	if( node->right ) 
		node->right = avl_balance_node( node->right );

	int bf = avl_balance_factor( node );

	if( bf >= 2 ) {
		/* Left Heavy */	

		if( avl_balance_factor( node->left ) <= -1 ) 
			newroot = avl_rotate_leftright( node );
		else 
			newroot = avl_rotate_leftleft( node );

	} else if( bf <= -2 ) {
		/* Right Heavy */

		if( avl_balance_factor( node->right ) >= 1 )
			newroot = avl_rotate_rightleft( node );
		else 
			newroot = avl_rotate_rightright( node );

	} else {
		

		newroot = node;
	}

	return( newroot );	
}

/* Balance a given tree */

void avl_balance( avl_tree_t *tree ) {

	avl_node_t *newroot = NULL;

	newroot = avl_balance_node( tree->root );

	if( newroot != tree->root )  {
		tree->root = newroot; 
	}
}

/* Insert a new node. */

void avl_insert( avl_tree_t *tree, int value ) {
	avl_node_t *node = NULL;
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;

	if( tree->root == NULL ) {
		node = avl_create_node();
		node->value = value;

		tree->root = node;

	} else {
		next = tree->root;

		while( next != NULL ) {
			last = next;

			if( value < next->value ) {
				next = next->left;

			} else if( value > next->value ) {
				next = next->right;

			
			} else if( value == next->value ) {
					
			}
		}

		node = avl_create_node();
		node->value = value;

		if( value < last->value ) last->left = node;
		if( value > last->value ) last->right = node;
		
	}

	avl_balance( tree );
}

/* Find the node containing a given value */

avl_node_t *avl_find( avl_tree_t *tree, int value ) {
	avl_node_t *current = tree->root;

	while( current && current->value != value ) {
		if( value > current->value )
			current = current->right;
		else
			current = current->left;
	}

	return current;
}

/* Do a depth first traverse of a node. */

void avl_traverse_node_dfs( avl_node_t *node, int depth ) {
	int i = 0;

	if( node->left ) avl_traverse_node_dfs( node->left, depth + 2 );

	//for( i = 0; i < depth; i++ ) putchar( ' ' );
	//printf( "%d: %d\n", node->value, avl_balance_factor( node ) );
	printf("%d ",node->value);

	if( node->right ) avl_traverse_node_dfs( node->right, depth + 2 );
}

/* Do a depth first traverse of a tree. */

void avl_traverse_dfs( avl_tree_t *tree )
{
	if(tree->root!=NULL)
	{
		avl_traverse_node_dfs( tree->root, 0 );
		printf("\n");
	}
}
avl_node_t *min_node(avl_node_t *n)
{
	avl_node_t *m = n;
	if(n == NULL)
	{	
		return n;
	}
	while(m->left != NULL)
	{	
		m = m->left;
	}
	return m;
}
void delete_node(avl_node_t *n, int key)
{
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;
	avl_node_t *parent = NULL;
	if(n == NULL)
	{
		return;
	}
	else 
	{
	next = n;
	while(next != NULL)
	{
		last = next;
		if(key < next->value)
	 	{
			next = next->left;
	 	}
	 	else if(key > next->value)
	 	{
			next = next->right;
			
	 	}	
	 	else if(key == next->value ) 
	 	{
			break;	
	 	}
	 	parent = last;
	}
	if(last != NULL)
	{
		if( (last->left == NULL) || (last->right == NULL) ) 
        { 
            avl_node_t *temp = last->left ? last->left : last->right; 
            // No child case 
            if (temp == NULL) 
            { 
                temp = last;  
                if((parent->left) == last)
                {
                	parent->left = NULL;
                }
                else
                {
                	parent->right = NULL;
                }
            } 
            else // One child case 
             {*last = *temp;} // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        }
        else
        {
        	avl_node_t* temp = min_node(last->right);  
            // Copy the inorder successor's data to this node 
            last->value = temp->value; 
            // Delete the inorder successor 
            delete_node(last->right, temp->value); 
        }  
	}	
}
}
void avl_delete(avl_tree_t *tree, int key)
{
	if(tree->root == NULL)
	{
		return;
	}
	delete_node(tree->root, key);
	avl_balance(tree);
}		


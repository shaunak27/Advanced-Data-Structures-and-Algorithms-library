#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct avl_node_s {
	struct avl_node_s *left;
	struct avl_node_s *right;
	int value;
};

typedef struct avl_node_s avl_node_t;

struct avl_tree_s {
	struct avl_node_s *root;
};

typedef struct avl_tree_s avl_tree_t;
avl_tree_t *avl_create();
avl_node_t *avl_create_node();
int avl_node_height( avl_node_t *node );
int avl_balance_factor( avl_node_t *node );
avl_node_t *avl_rotate_leftleft( avl_node_t *node ) ;
avl_node_t *avl_rotate_leftright( avl_node_t *node );
avl_node_t *avl_rotate_rightleft( avl_node_t *node ) ;
avl_node_t *avl_rotate_rightright( avl_node_t *node );
avl_node_t *avl_balance_node( avl_node_t *node );
void avl_balance( avl_tree_t *tree );
void avl_insert( avl_tree_t *tree, int value );
avl_node_t *avl_find( avl_tree_t *tree, int value );
void avl_traverse_node_dfs( avl_node_t *node, int depth );
void avl_traverse_dfs( avl_tree_t *tree );
avl_node_t *min_node(avl_node_t *n);
void delete_node(avl_node_t *n, int key);
void avl_delete(avl_tree_t *tree, int key);


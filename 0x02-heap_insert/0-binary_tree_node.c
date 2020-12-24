#include <stdlib.h>
#include "binary_trees.h"

/**
  * bianry_tree_node - create node
  * @parent: parent
  * @value: value
  *
  * Return: new node or null
  */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}


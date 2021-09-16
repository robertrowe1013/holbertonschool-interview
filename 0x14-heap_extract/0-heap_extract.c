#include "binary_trees.h"

/**
  * heap_extract - extract the root node of a max binary heap
  * @root: double pointer to root node of heap
  *
  * Return: value stored in node, 0 on fail
  */

int heap_extract(heap_t **root)
{
	int value;

	if (root == NULL || *root == NULL)
	{
		return (0);
	}
	value = (*root)->n;
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		*root = NULL;
	}

	return (value);
}



void heapify(heap_t *node)
{
	int tmp;
	heap_t *max = node;

	if (node->left != NULL && node->left->n > max->n)
	{
		max = node->left;
	}

	if (node->right != NULL && node->right->n > max->n)
	{
		max = node->right;
	}

	if (max != node)
	{
		tmp = node->n;
		node->n = max->n;
		max->n = tmp;
		heapify(max);
	}
}

#include "binary_trees.h"

/**
  * sorted_array_to_avl - sort array to avl
  *
  * @array: array to sort
  * @size: size of array
  *
  * Return: pointer to root or null
  */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	int mid;

	if (array == NULL)
		return (NULL);

	tree = malloc(sizeof(avl_t));
	if (tree == NULL)
		return (NULL);
	mid = (size - 1) / 2;
	tree->n = array[mid];
	tree->parent = NULL;
	tree->left = branch(array, 0, mid - 1, tree);
	tree->right = branch(array, mid + 1, size - 1, tree);

	return (tree);
}

/**
  * branch - create tree branches
  *
  * @array: sorted array
  * @start: beginning
  * @end: end
  * @tree: tree
  *
  * Return: tree
  */
avl_t *branch(int *array, int start, int end, avl_t *tree)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	mid = (start + end) / 2;
	printf("start: %d, end: %d, mid: %d, array mid: %d\n", start, end, mid, array[mid]);
	node->n = array[mid];
	node->parent = tree;
	node->left = branch(array, start, mid - 1, node);
	node->right = branch(array, mid + 1, end, node);

	return (node);
}

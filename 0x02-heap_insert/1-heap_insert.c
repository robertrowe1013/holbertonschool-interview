#include <stdlib.h>
#include "binary_trees.h"
static size_t _height(const heap_t *tree);

/**
  * heap_insert - inserts node
  * @root: root
  * @value: value
  *
  * Return: new node
  */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *location;
	int level, height;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}

	height = (int)_height(*root);
	for (level = 0; level <= height; level++)
	{
		location = locator(*root, level);
		if (location->right == NULL)
		{
			break;
		}
	}
	new_node = binary_tree_node(location, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (location->left == NULL)
	{
		location->left = new_node;
	}
	else
	{
		location->right = new_node;
	}
	new_node = heapify(new_node);

	return (new_node);
}

/**
  * _height - get height of tree
  * @tree: tree to measure
  *
  * Return: height of tree
  */
static size_t _height(const heap_t *tree)
{
	size_t height_l, height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
  * locator - locate parent for new node
  * @root: pointer to root of heap
  * @level: height of tree
  *
  * Return: pointer to location to insert or NULL
  */
heap_t *locator(heap_t *root, int level)
{
	heap_t *location = NULL;

	if (root == NULL)
	{
		return (NULL);
	}
	if (level == 0 || (level == 1 && root->right == NULL))
	{
		return (root);
	}
	location = locator(root->left, level - 1);
	if (location->right != NULL)
	{
		location = locator(root->right, level - 1);
	}
	return (location);
}

/**
  * heapify - add node to tree
  * @node: pointer to node
  *
  * Return: location fo swap
  */
heap_t *heapify(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}

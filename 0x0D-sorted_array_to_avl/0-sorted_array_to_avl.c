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
	unsigned int i;
	avl_t *newNode;

	if (array == NULL)
		return (NULL);

	newNode = malloc(sizeof(avl_t));
	if (newNode == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		newNode->n = array[i];
	}

	return (newNode);
}

#include "search_algos.h"

/**
  * advanced_binary - binary search
  * @array: array
  * @size: size
  * @value: value
  *
  * Return: first index of value or -1
  */

int advanced_binary(int *array, size_t size, int value)
{
	unsigned int i;

	if (array == NULL || value < array[0])
		return (-1);
	if (array[(int)size - 1] < value)
		return (-1);
	if (array[0] == value)
	{
		printf("Searching in array: %d", array[0]);
		for (i = 1; i < size; i++)
		{
			printf(", %d", array[i]);
		}
		printf("\n");
	}
	return (0);
}

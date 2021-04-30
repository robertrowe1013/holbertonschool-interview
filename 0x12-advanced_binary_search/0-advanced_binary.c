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
	int index;
	int start = 0;
	int end = size - 1;

	if (array == NULL || value < array[0])
		return (-1);

	index = research(array, start, end, value);

	return (index);
}

/**
  * research - recursive binary search
  * @array: array
  * @start: indext to start
  * @end: index to end
  * @value: value
  *
  * Return: first index or -1
  */
int research(int *array, int start, int end, int value)
{
	int mid, i, index;

	if (end >= start)
	{
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i < end)
			{
				printf(", ");
			}
		}
		printf("\n");
		mid = start + (end - start) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			index = research(array, start, mid, value);
		else
			index = research(array, mid + 1, end, value);
		return (index);
	}
	return (-1);
}

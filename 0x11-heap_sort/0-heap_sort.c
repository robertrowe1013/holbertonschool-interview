#include <stdio.h>
#include "sort.h"

/**
  * heap_sort - heap sort, sift-down
  * @array: array to sort
  * @size: size of array
  */

void heap_sort(int *array, size_t size)
{
	int swap;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	if (size == 2)
	{
		if (array[0] >= array[1])
		{
			swap = array[0];
			array[0] = array[1];
			array[1] = swap;
			print_array(array, size);
		}
		return;
	}
}

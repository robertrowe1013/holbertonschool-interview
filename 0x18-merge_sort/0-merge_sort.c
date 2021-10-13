#include "sort.h"

/**
  * merge_sort - sort an array using merge sort ascending
  * @array: array to be sorted
  * @size: size of array
  */
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(sizeof(int) * size);

	sorter(array, size, tmp);
	free(tmp);
}

/**
  * sorter - actually does the sorting
  * @arr: array to be sorted
  * @size: size of array
  * @tmp: temp array
  */
void sorter(int *arr, size_t size, int *tmp)
{
	size_t left_s = size / 2;
	size_t right_s = size - left_s;
	size_t i = 0, j = 0, k = 0;
	int *right = arr + left_s;

	if (size <= 1)
	{
		return;
	}
	sorter(arr, left_s, tmp);
	sorter(right, right_s, tmp);
	for (i = 0; i < left_s; i++)
	{
		tmp[i] = arr[i];
	}
	i = 0;
	printf("Merging...\n[left]: ");
	print_array(arr, left_s);
	printf("[right]: ");
	print_array(right, right_s);
	while (i < left_s || j < right_s)
	{
		while (j < right_s && (i >= left_s || right[j] < tmp[i]))
		{
			arr[k] = right[j];
			k++;
			j++;
		}
		while (i < left_s && (j >= right_s || tmp[i] <= right[j]))
		{
			arr[k] = tmp[i];
			k++;
			i++;
		}
	}
	printf("[Done]: ");
	print_array(arr, size);
}

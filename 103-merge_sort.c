#include "sort.h"
#include <stdio.h>

/**
 * merge_sort - sorts an array of integers in ascending order.
 *		using the Merge sort algorithm.
 * @array: array to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	top_down_merge_sort(array, size);
}

/**
 * top_down_merge_sort - recursive function to perform merge sort.
 * @array: array to sort
 * @size: size of the array
 */

void top_down_merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid, i;

	if (size < 2)
		return;

	mid = size / 2;

	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));

	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	top_down_merge_sort(left, mid);
	top_down_merge_sort(right, size - mid);

	merge_arrays(array, left, mid, right, size - mid);

	free(left);
	free(right);
}

/**
 * merge_arrays - merges two arrays in ascending order.
 * @array: original array.
 * @left: left subarray
 * @left_size: size of the left subarray
 * @right: right subarray
 * @right_size: size of the right subarray
 */

void merge_arrays(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

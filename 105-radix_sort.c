#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort2 - performs counting sort on an array.
 * @array: array to sort
 * @size: size of the array
 * @exp: current digit exponent
 */

void counting_sort2(int *array, size_t size, int exp)
{
	int *output, *count;
	int i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	count = calloc(10, sizeof(int));
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *		using the Radix sort algorithm.
 * @array: array to sort
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (!array || size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort2(array, size, exp);
}


/**
 * get_max - returns the maximum element in an array.
 * @array: array to find the maximum element from.
 * @size: size of the array
 *
 * Return: maximum element in the array.
 */

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

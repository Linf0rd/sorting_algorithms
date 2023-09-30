#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order.
 *			using the Counting sort algorithm.
 * @array: array to sort
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	unsigned int i, max_val = 0;
	int *count, *output;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max_val)
			max_val = array[i];
	}

	count = malloc(sizeof(int) * (max_val + 1));
	if (!count)
		return;

	for (i = 0; i <= max_val; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= max_val; i++)
		count[i] += count[i - 1];

	print_array(count, max_val + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}

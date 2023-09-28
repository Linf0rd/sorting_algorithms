#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using,
 *			the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min_idx = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_idx])
				min_idx = y;
		}

		if (min_idx != x)
		{
			temp = array[x];
			array[x] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}

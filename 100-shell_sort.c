#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using,
 *		the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, x, y;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= gap && array[y - gap] > temp; y -= gap)
				array[y] = array[y - gap];
			array[y] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

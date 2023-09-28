#include "sort.h"

/**
 * partition - Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Number of elements in the array.
 *
 * Return: Index of the pivot element.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int x, y;

	pivot = array[high];
	x = low - 1;

	for (y = low; y < high; y++)
	{
		if (array[y] < pivot)
		{
			x++;
			if (x != y)
			{
				temp = array[x];
				array[x] = array[y];
				array[y] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[x + 1])
	{
		temp = array[x + 1];
		array[x + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (x + 1);
}

/**
 * quicksort - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Number of elements in the array.
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using,
 *		the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

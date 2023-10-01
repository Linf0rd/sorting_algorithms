#include "sort.h"
#include <stdio.h>

/**
 * heap_sort - sorts an array of integers in ascending order
 *		using the Heap sort algorithm.
 * @array: array to sort
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	build_heap(array, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * build_heap - builds a max heap from an array.
 * @array: array to build heap from.
 * @size: size of the array
 */

void build_heap(int *array, size_t size)
{
	size_t i;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);
}

/**
 * heapify - maintains the heap property of a subtree.
 * @array: array representing the heap
 * @size: size of the heap
 * @root: root index of the subtree
 * @total_size: total size of the array
 */

void heapify(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * swap - swaps two integers.
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

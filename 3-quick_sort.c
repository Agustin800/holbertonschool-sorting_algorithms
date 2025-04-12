#include <stdlib.h>
#include "sort.h"

/**
 * partition - Partitions the array around a pivot element.
 * @array: The array of integers.
 * @start: The starting index of the partition.
 * @end: The ending index of the partition.
 * @size: The size of the entire array (for printing).
 *
 * Return: The final pivot index.
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int low = start - 1;
	int high = end;
	int temp;

	while (1)
	{
		while (array[++low] < pivot)
			;
		while (array[--high] > pivot && high > low)
			;
		if (low >= high)
			break;
		temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	temp = array[low];
	array[low] = array[end];
	array[end] = temp;
	print_array(array, size);
	return (low);
}

/**
 * quick_sort_helper - Recursively sorts the array using QuickSort algorithm.
 * @array: The array of integers.
 * @start: The starting index of the sort.
 * @end: The ending index of the sort.
 * @size: The size of the entire array (for printing).
 */
void quick_sort_helper(int *array, int start, int end, size_t size)
{
	if (start < end)
	{
		int p = partition(array, start, end, size);

		quick_sort_helper(array, start, p - 1, size);
		quick_sort_helper(array, p + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using QuickSort.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

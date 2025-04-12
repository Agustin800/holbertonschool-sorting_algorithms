#include <stdlib.h>
#include "sort.h"
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - partitions array using the Lomuto scheme
 * @array: array to be sorted
 * @low: lowest index of section to sort
 * @high: highest index of section to sort
 * @size: size of the whole array
 *
 * Return: new partition point
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_helper - recursive implementation of quick sort
 * @array: array to be sorted
 * @low: lowest index of section to sort
 * @high: highest index of section to sort
 * @size: size of the whole array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quick sort algorithm
 * @array: array to be sorted
 * @length: length of the array
 */
void quick_sort(int *array, size_t length)
{
	if (!array || length < 2)
		return;
	quick_sort_helper(array, 0, length - 1, length);
}

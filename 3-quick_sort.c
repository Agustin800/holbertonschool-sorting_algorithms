#include <stdlib.h>
#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order using the
 *	quick sort algorithm.
 * @array: the array to be sorted.
 * @length: the length of @array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t length)
{
	int pivot = 0, j = 0, i = 0, temp = 0;

	if (length < 2)
		return;
	pivot = array[length - 1];
	j = 0;
	for (i = 0; i < (int)length - 1; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			j++;
		}
	}
	temp = array[length - 1];
	array[length - 1] = array[j];
	array[j] = temp;
	quick_sort(array, j); /* sorts left vector */
	quick_sort(array + j + 1, length - j - 1); /* sorts right vector */
}

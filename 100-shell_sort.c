#include "sort.h"
#include <stdlib.h>
/**
 * shell_sort - sorts an array of integers in ascending order using the
 *		Shell sort algorithm and the Knuth sequence.
 * @array: the array to be sorted.
 * @size: the size of @array.
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	/*knugth sequence:  n+1=(n*3)+1 */
	size_t gap = 0, i = 0, j = 0;
	int temp = 0;

	if (array == NULL || size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

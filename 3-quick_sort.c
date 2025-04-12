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
 * quick_sort - sorts an array of integers in ascending order using the
 *	quick sort algorithm.
 * @array: the array to be sorted.
 * @length: the length of @array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t length)
{
	size_t i, j, l_stack[1024], r_stack[1024], top = 0;
	int pivot, *start;
	size_t left, right;

	if (length < 2 || !array)
		return;
	l_stack[0] = 0;
	r_stack[0] = length;
	top = 1;
	while (top > 0)
	{
		right = r_stack[--top];
		left = l_stack[top];
		if (right - left < 2)
			continue;
		start = array + left;
		pivot = start[right - left - 1];
		j = 0;
		for (i = 0; i < right - left - 1; i++)
		{
			if (start[i] <= pivot)
			{
				if (i != j)
					swap(&start[i], &start[j]);
				j++;
			}
		}
		swap(&start[right - left - 1], &start[j]);
		print_array(array, length);
		if (j > 0)
		{
			l_stack[top] = left;
			r_stack[top++] = left + j;
		}
		if (right - left - j - 1 > 0)
		{
			l_stack[top] = left + j + 1;
			r_stack[top++] = right;
		}
	}
}

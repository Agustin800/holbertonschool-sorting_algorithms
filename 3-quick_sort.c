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
	size_t left, right, pivot;

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
		pivot = array[right - 1];
		for (i = left, j = left; j < right - 1; j++)
		{
			if (array[j] <= (int)pivot)
			{
				if (i != j)
				{
					swap(&array[i], &array[j]);
					print_array(array, length);
				}
				i++;
			}
		}
		if (i != right - 1)
		{
			swap(&array[i], &array[right - 1]);
			print_array(array, length);
		}
		if (i > left)
		{
			l_stack[top] = left;
			r_stack[top++] = i;
		}
		l_stack[top] = i + 1;
		r_stack[top++] = right;
	}
}

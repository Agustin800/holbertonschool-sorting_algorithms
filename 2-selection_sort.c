#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array of integers to sort
 * @size: The size of the array
 * Description: Prints the array after each swap
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	/*Aca compruebo que array no sea nulo*/
	/*Y que size tenga min 2 elementos sino no hay nada que ordenar*/
	if (!array || size < 2)
		return;

	/*Recorremos el array elemento por elemento*/
	for (i = 0; i < size - 1; i++)
	{
		/*Suponemos que el minimo esta en la posicion actual*/
		min_idx = i;

		/*Buscamos si hay un elemento más chico en el resto del arra*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/*Si encontramos un nuevo mínimo, lo intercambiamo*/
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			/*Imprimimos el array después del swap*/
			print_array(array, size);
		}
	}
}

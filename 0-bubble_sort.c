#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array of integers to be sorted
 * @size: The number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	/*Aca compruebo que array no sea nulo*/
	/*Y que size tenga min 2 elementos sino no hay nada que ordenar*/
	if (array == NULL || size < 2)
		return;

	/*Este for controla el numero de pasadas que se hacen al array*/
	for (i = 0; i < size - 1; i++)
	{
		/*Esto marca cuando hay un intercambio de elementos*/
		swapped = 0;

		/*Este for recorre el array comparando elementos adyacentes*/
		for (j = 0; j < size - i - 1; j++)
		{
			/*Esto comprueba si los elementos estan ordenados*/
			if (array[j] > array[j + 1])
			{
				/*Esta parte intercambia elementos*/
				/*Usando temp para guardar uno de ellos*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*Con esto mostramos el array tras el swap*/
				print_array(array, size);
				/*Como hubo un cambio lo indicamos en el swap*/
				swapped = 1;
			}
		}
		/*Esto comprueba si el arreglo ya esta ordenado*/
		if (swapped == 0)
			break;
	}
}

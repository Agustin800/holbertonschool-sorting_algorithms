#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 * Description: Prints the list after each swap of two elements.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	/*Aca empezamos desde el segundo nodo*/
	current = (*list)->next;

	while (current)
	{
		temp = current;
		current = current->next;

		/*Mientras que temp sea menor a su nodo anterior se intercambia*/
		while (temp->prev && temp->n < temp->prev->n)
		{
			/*Intercambio de nodos*/
			swap_nodes(list, temp->prev, temp);
			/*Se imprime la lista despues del swap*/
			print_list(*list);
		}
	}
}

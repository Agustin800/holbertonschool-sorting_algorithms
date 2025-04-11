#include "sort.h"

#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: First node
 * @b: Second node (must be right after 'a')
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	/*Si a tiene un nodo antes lo conectamos a b*/
	if (a->prev)
		a->prev->next = b;

	/*Si era el primero, b se volvera el nuevo head*/
	else
		*list = b;

	/*Si b tiene un nodo despues, lo conectamos con a*/
	if (b->next)
		b->next->prev = a;

	/*Conectamos a y b*/
	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

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

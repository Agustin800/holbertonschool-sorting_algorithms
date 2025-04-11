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

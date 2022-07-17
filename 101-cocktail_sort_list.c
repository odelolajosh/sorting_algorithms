#include "sort.h"

/**
 * swap - swap two nodes in a doubly linked list
 * @list: given list
 * @A: first node
 * @B: second node
 */
void swap(listint_t **list, listint_t *A, listint_t *B)
{
	if (A == B)
		return;

	A->next = B->next;
	B->prev = A->prev;

	if (A->prev)
		A->prev->next = B;
	else
		*list = B;

	if (B->next)
		B->next->prev = A;

	A->prev = B;
	B->next = A;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: given list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;
	int swapped = 0;

	do {
		current = *list;
		/* do forward bubble */
		while (current && current->next)
		{
			next = current->next;
			if (current->n > next->n)
			{
				/* do swap */
				swap(list, current, next);
				swapped = 1;
				continue;
			}
			current = current->next;
		}
		
		/* will a swap still be necessary? */
		if (!swapped)
			break;
		swapped = 0;

		/* do backward swap */
		while (current && current->prev)
		{
			prev = current->prev;
			if (prev->n > current->n)
			{
				/* do swap */
				swap(list, prev, current);
				swapped = 1;
				continue;
			}
			current = current->prev;
		}
	} while (swapped);
}

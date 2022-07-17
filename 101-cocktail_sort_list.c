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
 *
 * [*] Performance update
 * since in the forward bubble, the last index will be the max
 * of the list, to improve performance, we set a upper boundary
 * so the algorithm never reach there again. Same for the backward
 * bubble.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;
	listint_t *lower, *upper;
	int swapped = 0;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		current = *list;
		/* do forward bubble */
		while (current && current->next && current->next != upper)
		{
			next = current->next;
			if (current->n > next->n)
			{
				swap(list, current, next);
				swapped = 1;
				continue;
			}
			current = current->next;
		}
		upper = current;
		/* will a swap still be necessary? */
		if (!swapped)
			break;
		swapped = 0;
		/* do backward bubble */
		while (current && current->prev && current->prev != lower)
		{
			prev = current->prev;
			if (prev->n > current->n)
			{
				swap(list, prev, current);
				swapped = 1;
				continue;
			}
			current = current->prev;
		}
		lower = current;
	} while (swapped);
}

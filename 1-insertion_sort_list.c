#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next = currect->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			/* Detach current */
			if (currect->next)
				currect->next->prev = insert;
			insert->next = current->next;

			/* Move current before insert */
			currect->prev = insert->prev;
			current->next = insert;

			if (insert->prev)
				insert->prev->next = current;
			else
				*list = current;

			insert->prev = current;

			print_list(*list);

			insert = current->prev;
		}
		current = next;
	}
}
